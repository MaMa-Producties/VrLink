// Fill out your copyright notice in the Description page of Project Settings.


#include "GazeRecorder.h"

#include "EyeTrackerFunctionLibrary.h"
#include "IEyeTracker.h"
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
		TEXT("SessionId,Time,WallUtc,Source,Valid,GazeX,GazeY,")
		TEXT("HeadX,HeadY,HeadZ,DirX,DirY,DirZ,HitX,HitY,HitZ,Scene,")
		TEXT("HeadQuatX,HeadQuatY,HeadQuatZ,HeadQuatW\n");

	/**
	 * The gaze file's layout, sent once as `gazeformat:2` so a reader knows which columns
	 * to expect. 2 added the head rotation, Valid=0 for rejected eye samples, and the
	 * `route:reset` mark.
	 */
	const TCHAR* const GazeFormatMark = TEXT("gazeformat:2");

	/**
	 * The one recorder writing this process's gaze. The plugin builds a recorder with every
	 * link, and the README used to say to add one to the pawn as well: with both, every
	 * sample was written twice into the same file, 41 to 46 per cent of the rows of the
	 * 5 October rides, in one-second blocks out of time order. The first recorder to open
	 * the session's file owns it; any other stays idle.
	 */
	TWeakObjectPtr<UGazeRecorder> GActiveRecorder;

	/**
	 * Where the head was on the previous row, carried across recorders: a level load builds
	 * a new one, and the jump it causes is exactly the reset worth marking.
	 */
	FVector GLastHead = FVector::ZeroVector;
	FString GLastHeadSession;

	/** A head that moves further than this between two rows was moved by the level. */
	constexpr double ResetJumpCm = 1000.0;

	/**
	 * What produced the ray for a row. The analysis reads this per row and widens or
	 * tightens the heat map to match, so a session that loses tracking partway through
	 * is still read correctly rather than being all one thing or the other.
	 */
	const TCHAR* const GazeSourceHead = TEXT("head");
	const TCHAR* const GazeSourceEye = TEXT("eye");

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

	/**
	 * Sanitize() for a relative folder path: each part is cleaned on its own and the
	 * slashes are kept, so the tablet's `Study/Sessions/2026-10-28` stays three folders
	 * instead of collapsing into one `Study_Sessions_2026-10-28` beside the tablet's.
	 * Empty, `.` and `..` parts are dropped, so the path can never climb out of the root.
	 */
	FString SanitizeFolderPath(const FString& Value)
	{
		TArray<FString> Parts;
		Value.Replace(TEXT("\\"), TEXT("/")).ParseIntoArray(Parts, TEXT("/"), /*InCullEmpty=*/true);

		FString Out;
		for (const FString& Part : Parts)
		{
			if (Part == TEXT(".") || Part == TEXT(".."))
			{
				continue;
			}
			Out = Out.IsEmpty() ? Sanitize(Part) : Out + TEXT("/") + Sanitize(Part);
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
	// Stopping play mid-session must still leave a complete, readable file. A level
	// change is not stopping: the rows written so far are flushed and the file is left
	// for the recorder built in the next level to carry on with, because closing it
	// here ended the gaze recording at the first location every time.
	if (EndPlayReason == EEndPlayReason::LevelTransition)
	{
		Flush();
		if (GActiveRecorder.Get() == this)
		{
			GActiveRecorder.Reset();
		}
		Super::EndPlay(EndPlayReason);
		return;
	}

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
	bool bShouldRecord =
		VrLink != nullptr && VrLink->IsSessionActive() && !VrLink->GetSessionId().IsEmpty();

	// Another recorder already writes this session: stay idle rather than write it twice.
	if (bShouldRecord && !bRecording && GActiveRecorder.IsValid() && GActiveRecorder.Get() != this
		&& GActiveRecorder->IsRecording())
	{
		if (!bAnnouncedIdle)
		{
			bAnnouncedIdle = true;
			Announce(FColor::Yellow, FString::Printf(
				TEXT("A second Gaze Recorder (on %s) stays idle: one is already recording. Remove the extra one."),
				*GetNameSafe(GetOwner())));
		}
		bShouldRecord = false;
	}

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

	// A tablet that reconnected mid-ride starts from a fresh welcome and has forgotten
	// whether an eye tracker is on: the mark is sent once per file, so it is sent again.
	if (VrLink->GetWelcomeCount() != MarkedWelcomeCount)
	{
		SendTrackerMark();
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

	// The tablet has paused the recording: it writes nothing meanwhile and its clock stands
	// still, so neither does this file. Rows written now would all carry the same Time.
	if (VrLink->IsSessionPaused())
	{
		// The rider may move on while paused; the jump between the last row before the
		// pause and the first after it is not a reset of the route.
		GLastHeadSession.Reset();
		return;
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

	// A session that began in an earlier level already has its file open and its header
	// written. Carry on appending to it: writing the header again would put a second
	// one in the middle of the CSV, and truncating would throw away every row recorded
	// before the participant moved.
	const FString Carried = VrLink->GetGazeFilePath();
	if (!Carried.IsEmpty() && Carried == GazeFilePath
		&& IFileManager::Get().FileExists(*GazeFilePath))
	{
		RowBuffer.Reset();
		bRecording = true;
		GActiveRecorder = this;
		MarkedWelcomeCount = VrLink->GetWelcomeCount();
		Announce(FColor::Green, FString::Printf(TEXT("Continuing -> %s"), *GazeFilePath));
		return;
	}

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
	GActiveRecorder = this;
	VrLink->SendMark(GazeFormatMark);

	// So `session.saved` can name the file, and the operator sees on the tablet that
	// the PC wrote its half of the session.
	VrLink->SetGazeFilePath(GazeFilePath);

	// Said once, at the top of the session, because neither Source nor Valid can say
	// it. A file of nothing but head rows is either a session with no eye-tracking
	// hardware at all or one where tracking never cleared threshold, and those mean
	// very different things to whoever reads the numbers: the first has no eye data
	// to be missing, the second has eye data that failed. Without this the only way
	// to tell them apart is to ask whoever ran the session.
	SendTrackerMark();

	Announce(FColor::Green, FString::Printf(TEXT("Recording -> %s"), *GazeFilePath));
}

void UGazeRecorder::SendTrackerMark()
{
	const bool bTracker = bPreferEyeTracking && UEyeTrackerFunctionLibrary::IsEyeTrackerConnected();
	VrLink->SendMark(bTracker ? TEXT("eyetracker:present") : TEXT("eyetracker:absent"));
	MarkedWelcomeCount = VrLink->GetWelcomeCount();
}

void UGazeRecorder::CloseFile()
{
	if (!bRecording)
	{
		return;
	}

	Flush();
	bRecording = false;
	if (GActiveRecorder.Get() == this)
	{
		GActiveRecorder.Reset();
	}

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
	// where the participant's head is and which way it faces. It is recorded on every row
	// whichever ray is traced, because where somebody stood is worth knowing either way --
	// the 3D view puts its camera there.
	const FVector Head = Camera->GetCameraLocation();
	const FVector HeadDirection = Camera->GetCameraRotation().Vector();

	// Eye gaze when the headset offers it and the tracker is confident, the head ray
	// otherwise. Deciding per row rather than per session: confidence collapses during a
	// blink, and those rows are worth keeping as head rows rather than losing.
	FVector Origin = Head;
	FVector Direction = HeadDirection;
	bool bEye = TryEyeGaze(Origin, Direction);
	const double Now = FPlatformTime::Seconds();

	// A blink the runtime does not flag. The VIVE reports no confidence, so a blink came
	// through as an eye ray flung across the view: 210 samples above 1000 deg/s on the
	// ride of 5 October, faster than an eye can move. A sample that far from the last
	// believed one, that quickly, is not believed; the row falls back to the head ray.
	if (bEye && LastEyeSeconds > 0.0)
	{
		const double Dt = Now - LastEyeSeconds;
		const double Degrees = FMath::RadiansToDegrees(
			FMath::Acos(FMath::Clamp(FVector::DotProduct(Direction, LastEyeDirection), -1.0, 1.0)));
		if (Dt > 0.0 && Degrees / Dt > MaxEyeDegreesPerSecond)
		{
			bEye = false;
			Origin = Head;
			Direction = HeadDirection;
		}
	}
	if (bEye)
	{
		LastEyeDirection = Direction;
		LastEyeSeconds = Now;
	}

	// Valid=0 marks an eye sample the tracker lost or that was not believed, while it was
	// otherwise tracking: a blink, a glance to the edge. The row still carries the head
	// ray. After a second without eyes the tracker counts as not tracking, and head rows
	// are ordinary valid head rows again, so a session whose tracker never locked on is
	// still a usable head-gaze session rather than one marked invalid end to end.
	const bool bEyeLost = !bEye && LastEyeSeconds > 0.0 && Now - LastEyeSeconds < EyeLostGraceSeconds;

	// The level moved the rider (a respawn, a route restart, the next design's level).
	// Marked so the analysis does not have to guess it from a jump in the positions.
	const FString SessionNow = VrLink ? VrLink->GetSessionId() : FString();
	if (GLastHeadSession == SessionNow && FVector::Dist(Head, GLastHead) > ResetJumpCm && VrLink)
	{
		VrLink->SendMark(TEXT("route:reset"));
	}
	GLastHead = Head;
	GLastHeadSession = SessionNow;

	if (bEye != bEyeGazeInUse || !bEyeGazeAnnounced)
	{
		bEyeGazeAnnounced = true;
		Announce(bEye ? FColor::Green : FColor::Yellow,
			bEye ? TEXT("Eye tracking active: rows record Source=eye.")
			     : TEXT("No eye tracking: rows record Source=head."));
	}
	bEyeGazeInUse = bEye;

	const FVector RayEnd = Origin + Direction * MaxTraceDistance;

	FCollisionQueryParams Params(FName(TEXT("GazeTrace")), /*bTraceComplex=*/false);
	Params.AddIgnoredActor(GetOwner());
	if (const APawn* Pawn = PC->GetPawn())
	{
		Params.AddIgnoredActor(Pawn);
	}

	FHitResult Hit;
	const bool bHit = World->LineTraceSingleByChannel(Hit, Origin, RayEnd, TraceChannel, Params);

	// A miss is still a real sample (they are looking at the sky, or past everything).
	// It is written with NO world position rather than being dropped, and rather than
	// recording the far end of the ray, which is what it used to do: that put a point
	// kilometres away in the three columns the heat map is built from, marked as not
	// real only by an empty name in the column beside it. Blank says nowhere, once.
	const FVector HitPoint = bHit ? Hit.ImpactPoint : RayEnd;
	const FString HitColumns = bHit
		? FString::Printf(TEXT("%.1f,%.1f,%.1f"), HitPoint.X, HitPoint.Y, HitPoint.Z)
		: FString(TEXT(",,"));

	// Viewport coordinates of the hit point. For head gaze the ray IS the view axis, so
	// this is the centre of the view on every row and carries no information; it is kept
	// because the column is part of the contract and becomes meaningful the moment eye
	// tracking starts writing Source=eye. The analysis signal is Hit*.
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

	// Which way the head faced on an eye row, so a head turn can be told from an eye
	// movement. Empty on head rows, where Dir already is the head direction.
	FString HeadQuatColumns = TEXT(",,,");
	if (bEye)
	{
		const FQuat Q = Camera->GetCameraRotation().Quaternion();
		HeadQuatColumns = FString::Printf(TEXT("%.5f,%.5f,%.5f,%.5f"), Q.X, Q.Y, Q.Z, Q.W);
	}

	// The same clock the tablet stamps its EEG and events with, plus the wall time as the
	// fallback for reconciling the two machines.
	const double Time = VrLink->GetSessionElapsedSeconds();
	const FString WallUtc = FDateTime::UtcNow().ToIso8601();

	RowBuffer += FString::Printf(
		TEXT("%s,%.3f,%s,%s,%d,%s,%s,%.1f,%.1f,%.1f,%.4f,%.4f,%.4f,%s,%s,%s\n"),
		*Csv(RecordingSessionId), Time, *WallUtc, bEye ? GazeSourceEye : GazeSourceHead,
		bEyeLost ? 0 : 1,
		*GazeX, *GazeY,
		Head.X, Head.Y, Head.Z,
		Direction.X, Direction.Y, Direction.Z,
		*HitColumns,
		*Csv(VrLink->GetCurrentScene()),
		*HeadQuatColumns);

	++RowCount;
}

bool UGazeRecorder::TryEyeGaze(FVector& OutOrigin, FVector& OutDirection) const
{
	if (!bPreferEyeTracking)
	{
		return false;
	}

	// Asked every frame rather than cached: a tracker can be plugged in, calibrated or lost
	// mid-session, and the call is a cheap flag read.
	if (!UEyeTrackerFunctionLibrary::IsEyeTrackerConnected())
	{
		return false;
	}

	FEyeTrackerGazeData Data;
	if (!UEyeTrackerFunctionLibrary::GetGazeData(Data))
	{
		return false;
	}

	// Confidence is not reported by every runtime; the ones that do not leave it at 0, which
	// would reject every sample. A zero is read as "not reported" and allowed through, so a
	// tracker that answers with a direction is trusted to have meant it.
	if (Data.ConfidenceValue > 0.f && Data.ConfidenceValue < MinEyeConfidence)
	{
		return false;
	}

	if (Data.GazeDirection.IsNearlyZero())
	{
		return false;
	}

	// World space already: the eye tracker module applies the HMD pose, so this ray can be
	// traced against the level exactly as the camera ray is.
	OutOrigin = Data.GazeOrigin;
	OutDirection = Data.GazeDirection.GetSafeNormal();
	return true;
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
		Folder = FString::Printf(TEXT("%s/Sessions/%s"), *Sanitize(Experience), *FDateTime::UtcNow().ToString(TEXT("%Y-%m-%d")));

		UE_LOG(LogGaze, Warning,
			TEXT("The tablet sent no sessionFolder; falling back to '%s'. Check it matches the tablet's folder."), *Folder);
	}

	const FString Directory = FPaths::Combine(Root, SanitizeFolderPath(Folder));
	IFileManager& Files = IFileManager::Get();
	if (!Files.DirectoryExists(*Directory) && !Files.MakeDirectory(*Directory, /*Tree=*/true))
	{
		return FString();
	}
	return Directory;
}
