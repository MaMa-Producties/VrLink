// Fill out your copyright notice in the Description page of Project Settings.


#include "GazeRecorder.h"
#include "GameFramework/Pawn.h"
#include "VrLinkComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerController.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformProcess.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

DEFINE_LOG_CATEGORY_STATIC(LogGaze, Log, All);

namespace
{
	/**
	 * The column list, verbatim from the data contract (vrlink v1.1 §6d, DATA_FORMAT.md).
	 *
	 * Do not reorder or rename: the analysis tool reads this header. Adding a column
	 * means updating both of those documents in the same change.
	 */
	const TCHAR* const GazeCsvHeader =
		TEXT("SessionId,Time,WallUtc,Source,Valid,GazeX,GazeY,HitObject,")
		TEXT("HeadX,HeadY,HeadZ,DirX,DirY,DirZ,HitX,HitY,HitZ,Scene\n");

	/** `head` today. Eye tracking writes `eye` into the same file when it lands. */
	const TCHAR* const GazeSourceHead = TEXT("head");

	/** RFC-4180 quoting, matching the recorder's own Csv() so both sides quote alike. */
	FString Csv(const FString& Value)
	{
		if (!Value.Contains(TEXT(",")) && !Value.Contains(TEXT("\"")) &&
			!Value.Contains(TEXT("\n")) && !Value.Contains(TEXT("\r")))
		{
			return Value;
		}
		return TEXT("\"") + Value.Replace(TEXT("\""), TEXT("\"\"")) + TEXT("\"");
	}

	/** Makes a string safe to use as a file or folder name, matching the recorder's Sanitize(). */
	FString Sanitize(const FString& Value)
	{
		FString Out;
		Out.Reserve(Value.Len());
		for (const TCHAR Char : Value)
		{
			const bool bSafe = FChar::IsAlnum(Char) || Char == TEXT('_') || Char == TEXT('-');
			Out.AppendChar(bSafe ? Char : TEXT('_'));
		}
		return Out.IsEmpty() ? TEXT("study") : Out;
	}

	/** Prints to the log and to the viewport, keyed so lines update instead of stacking. */
	void Announce(const FColor& Colour, const FString& Message)
	{
		UE_LOG(LogGaze, Log, TEXT("%s"), *Message);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(8804, 8.f, Colour, FString(TEXT("[Gaze] ")) + Message);
		}
	}
}

UGazeRecorder::UGazeRecorder()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	// Sample after the HMD's late update, so the head pose in a row is the pose that
	// frame was actually rendered from rather than the previous one.
	PrimaryComponentTick.TickGroup = TG_PostUpdateWork;
}

void UGazeRecorder::BeginPlay()
{
	Super::BeginPlay();

	// Auto-discover the link if it was not wired up in the editor, so dropping this
	// component into a level is genuinely all the setup there is.
	if (!VrLink)
	{
		for (TActorIterator<AActor> It(GetWorld()); It; ++It)
		{
			if (UVrLinkComponent* Found = It->FindComponentByClass<UVrLinkComponent>())
			{
				VrLink = Found;
				break;
			}
		}
	}

	// Say so either way. A gaze recorder that silently records nothing because it never
	// found the link is the failure that only shows up when the data is being analysed.
	Announce(VrLink ? FColor::Green : FColor::Red,
		VrLink
			? FString::Printf(TEXT("Ready: %.0f Hz, writing when the tablet starts recording."), SampleRateHz)
			: TEXT("NO VR Link found in the level. No gaze will be recorded."));
}

void UGazeRecorder::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Stopping play mid-session must still leave a complete, readable file.
	CloseFile();

	Super::EndPlay(EndPlayReason);
}

void UGazeRecorder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Follow the session rather than being told about it: this covers both start paths
	// (tablet-initiated and VR-initiated) and every end path, including the link dropping,
	// with no ordering assumptions about who fires what first.
	//
	// The id is part of the condition because a VR-initiated start runs for a few frames
	// with the clock going but no agreed id yet; those frames land in settle-in, never in
	// a scenario, so dropping them costs nothing and saves writing a file named `_gaze.csv`.
	const bool bShouldRecord =
		VrLink != nullptr && VrLink->IsSessionActive() && !VrLink->GetSessionId().IsEmpty();

	// A different id while still recording means the operator started a new session without
	// ending the old one. Close the old file first, so one file is always one session.
	if (bRecording && (!bShouldRecord || VrLink->GetSessionId() != RecordingSessionId))
	{
		CloseFile();
	}

	// FailedSessionId stops a failed open (unwritable folder, locked file) from retrying
	// every frame for the rest of the run and burying the log in the same error.
	if (bShouldRecord && !bRecording && VrLink->GetSessionId() != FailedSessionId)
	{
		OpenFile();
	}

	if (!bRecording)
	{
		return;
	}

	// Flush on wall-clock time, before the rate gate can return early, so the interval
	// means one second of real time whatever the frame rate is doing.
	TimeSinceLastFlush += DeltaTime;
	if (TimeSinceLastFlush >= FlushIntervalSeconds)
	{
		Flush();
		TimeSinceLastFlush = 0.f;
	}

	// Cap the rate. The cap is a ceiling, not a guarantee: a slow frame simply produces
	// fewer rows, and each row carries its own Time, so analysis is unaffected.
	if (SampleRateHz > 0.f)
	{
		TimeSinceLastSample += DeltaTime;
		if (TimeSinceLastSample < 1.f / SampleRateHz)
		{
			return;
		}
		TimeSinceLastSample = 0.f;
	}

	CaptureSample();
}

void UGazeRecorder::OpenFile()
{
	const FString SessionId = VrLink->GetSessionId();

	const FString Directory = ResolveSessionDirectory();
	if (Directory.IsEmpty())
	{
		FailedSessionId = SessionId;
		Announce(FColor::Red, TEXT("Could not create the output folder. No gaze for this session."));
		return;
	}

	RecordingSessionId = SessionId;
	GazeFilePath = FPaths::Combine(Directory, Sanitize(RecordingSessionId) + TEXT("_gaze.csv"));

	// Truncating write, so a re-run of the same session id never appends to a stale file.
	if (!FFileHelper::SaveStringToFile(FString(GazeCsvHeader), *GazeFilePath,
			FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
	{
		FailedSessionId = SessionId;
		Announce(FColor::Red, FString::Printf(TEXT("Could not write %s. No gaze for this session."), *GazeFilePath));
		GazeFilePath.Reset();
		return;
	}

	RowBuffer.Reset();
	RowCount = 0;
	TimeSinceLastSample = 0.f;
	TimeSinceLastFlush = 0.f;
	bRecording = true;

	// So `session.saved` can name the file, and the operator sees on the tablet that
	// the PC wrote its half of the session.
	VrLink->SetGazeFilePath(GazeFilePath);

	Announce(FColor::Green, FString::Printf(TEXT("Recording -> %s"), *GazeFilePath));
}

void UGazeRecorder::CloseFile()
{
	if (!bRecording)
	{
		return;
	}

	Flush();
	bRecording = false;

	Announce(FColor::Green, FString::Printf(TEXT("Saved %d rows -> %s"), RowCount, *GazeFilePath));
}

void UGazeRecorder::CaptureSample()
{
	const APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	const APlayerCameraManager* Camera = PC ? PC->PlayerCameraManager : nullptr;
	UWorld* World = GetWorld();
	if (!Camera || !World)
	{
		return;
	}

	// The head pose is the camera pose: in VR the camera is driven by the HMD, so this is
	// where the participant's head is and which way it faces.
	const FVector Head = Camera->GetCameraLocation();
	const FVector Direction = Camera->GetCameraRotation().Vector();
	const FVector RayEnd = Head + Direction * MaxTraceDistance;

	FCollisionQueryParams Params(FName(TEXT("GazeTrace")), /*bTraceComplex=*/false);
	Params.AddIgnoredActor(GetOwner());
	if (const APawn* Pawn = PC->GetPawn())
	{
		Params.AddIgnoredActor(Pawn);
	}

	FHitResult Hit;
	const bool bHit = World->LineTraceSingleByChannel(Hit, Head, RayEnd, TraceChannel, Params);

	// A miss is still a real sample (they are looking at the sky, or past everything).
	// It records the far end of the ray with an empty HitObject rather than being dropped.
	const FVector HitPoint = bHit ? Hit.ImpactPoint : RayEnd;
	const FString HitObject = bHit ? ResolveHitObjectName(Hit.GetActor()) : FString();

	// Viewport coordinates of the hit point. For head gaze the ray IS the view axis, so
	// this is the centre of the view on every row and carries no information; it is kept
	// because the column is part of the contract and becomes meaningful the moment eye
	// tracking starts writing Source=eye. The analysis signal is HitObject and Hit*.
	FString GazeX, GazeY;
	FVector2D Screen = FVector2D::ZeroVector;
	int32 ViewX = 0, ViewY = 0;
	PC->GetViewportSize(ViewX, ViewY);
	if (ViewX > 0 && ViewY > 0 &&
		UGameplayStatics::ProjectWorldToScreen(PC, HitPoint, Screen, /*bPlayerViewportRelative=*/false))
	{
		GazeX = FString::Printf(TEXT("%.4f"), Screen.X / ViewX);
		GazeY = FString::Printf(TEXT("%.4f"), Screen.Y / ViewY);
	}
	// Left blank when the point is behind the camera or the viewport is not up yet.
	// Blank reads as missing in every CSV reader; a 0 would read as the top-left corner.

	// The same clock the tablet stamps its EEG and events with, plus the wall time as the
	// fallback for reconciling the two machines.
	const double Time = VrLink->GetSessionElapsedSeconds();
	const FString WallUtc = FDateTime::UtcNow().ToIso8601();

	RowBuffer += FString::Printf(
		TEXT("%s,%.3f,%s,%s,1,%s,%s,%s,%.1f,%.1f,%.1f,%.4f,%.4f,%.4f,%.1f,%.1f,%.1f,%s\n"),
		*Csv(RecordingSessionId), Time, *WallUtc, GazeSourceHead,
		*GazeX, *GazeY, *Csv(HitObject),
		Head.X, Head.Y, Head.Z,
		Direction.X, Direction.Y, Direction.Z,
		HitPoint.X, HitPoint.Y, HitPoint.Z,
		*Csv(VrLink->GetCurrentScene()));

	++RowCount;
}

void UGazeRecorder::Flush()
{
	if (RowBuffer.IsEmpty() || GazeFilePath.IsEmpty())
	{
		return;
	}

	if (FFileHelper::SaveStringToFile(RowBuffer, *GazeFilePath,
			FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM,
			&IFileManager::Get(), FILEWRITE_Append))
	{
		RowBuffer.Reset();
	}
	else
	{
		// Keep the buffer and try again next flush: a momentarily locked file (a virus
		// scanner, the folder open in Explorer) should cost nothing.
		UE_LOG(LogGaze, Warning, TEXT("Could not append to %s; retrying next flush."), *GazeFilePath);

		// Unless it never comes back. Losing old gaze beats growing the buffer until the
		// session runs the machine out of memory.
		constexpr int32 MaxBufferedChars = 4 * 1024 * 1024;
		if (RowBuffer.Len() > MaxBufferedChars)
		{
			UE_LOG(LogGaze, Error, TEXT("Dropping %d buffered characters of gaze: %s stayed unwritable."),
				RowBuffer.Len(), *GazeFilePath);
			RowBuffer.Reset();
		}
	}
}

FString UGazeRecorder::ResolveSessionDirectory() const
{
	// Default to the tablet's own layout, Documents/MuseEEG, so collecting a session is
	// copying one folder onto the other and letting the {SessionId}_ prefix do the rest.
	FString Root = OutputRootOverride;
	if (Root.IsEmpty())
	{
		Root = FPaths::Combine(FString(FPlatformProcess::UserDir()), TEXT("MuseEEG"));
	}

	// The tablet names the study-day folder and sends it in the handshake, so both
	// machines write into the same name without agreeing on a clock or a timezone.
	FString Folder = VrLink ? VrLink->GetSessionFolder() : FString();
	if (Folder.IsEmpty())
	{
		// Only reached if the tablet sent no folder (an older build). Same shape, derived
		// from this side's own config, so the file still lands somewhere findable.
		const FString Experience = (VrLink && !VrLink->StudyConfig.Experience.IsEmpty())
			? VrLink->StudyConfig.Experience
			: TEXT("study");
		Folder = FString::Printf(TEXT("%s_%s"), *Sanitize(Experience), *FDateTime::UtcNow().ToString(TEXT("%Y-%m-%d")));

		UE_LOG(LogGaze, Warning,
			TEXT("The tablet sent no sessionFolder; falling back to '%s'. Check it matches the tablet's folder."), *Folder);
	}

	const FString Directory = FPaths::Combine(Root, Sanitize(Folder));
	IFileManager& Files = IFileManager::Get();
	if (!Files.DirectoryExists(*Directory) && !Files.MakeDirectory(*Directory, /*Tree=*/true))
	{
		return FString();
	}
	return Directory;
}

FString UGazeRecorder::ResolveHitObjectName(const AActor* HitActor) const
{
	if (!HitActor)
	{
		return FString();
	}

	// A tag is what the designer chose to call this thing ("Green facade"); the object
	// name is whatever Unreal generated ("StaticMeshActor_12"). Prefer the tag, because
	// this column is read by a person deciding whether a design worked.
	if (bUseActorTagAsHitObject && HitActor->Tags.Num() > 0)
	{
		return HitActor->Tags[0].ToString();
	}

	// Deliberately not GetActorLabel(): that is editor-only, so a packaged run would
	// record different names than a PIE run and the two could not be compared.
	return HitActor->GetName();
}
