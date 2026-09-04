// Fill out your copyright notice in the Description page of Project Settings.

#include "VrLinkSubsystem.h"

#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GazeRecorder.h"
#include "TCPSocket.h"
#include "VrLinkComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogVrLinkSubsystem, Log, All);

namespace
{
	constexpr int32 KeyWarn = 8806;

	void Warn(const FString& Message)
	{
		UE_LOG(LogVrLinkSubsystem, Warning, TEXT("%s"), *Message);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(KeyWarn, 8.f, FColor::Orange, TEXT("[VR Link] ") + Message);
		}
	}
}

void UVrLinkSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Every level the participant is taken to gets its link rebuilt. The subsystem
	// lives on the Game Instance and survives a level change; the actors it spawns
	// do not, so without this the first Open Level would leave InitializeVrLink
	// looking like it had never been called -- which is exactly what it looked like.
	WorldReadyHandle = FWorldDelegates::OnPostWorldInitialization.AddWeakLambda(
		this,
		[this](UWorld* World, const UWorld::InitializationValues)
		{
			// Only once somebody has asked for a link, and only for a world this
			// game instance is actually running. Editor preview and asset-thumbnail
			// worlds raise this delegate too, and spawning a socket server into one
			// of those would fight the real session for the port.
			if (!bConfigured || World == nullptr)
			{
				return;
			}
			const bool bPlayable =
				World->WorldType == EWorldType::Game || World->WorldType == EWorldType::PIE;
			if (!bPlayable || World->GetGameInstance() != GetGameInstance())
			{
				return;
			}

			SpawnedHost.Reset();
			BuildLink(World);
		});

	// Caught while the OUTGOING world is still standing, which is the only moment the
	// component holding the session can still be asked for it. By the time the next
	// world is initialised it has already gone.
	WorldTearDownHandle = FWorldDelegates::OnWorldBeginTearDown.AddWeakLambda(
		this,
		[this](UWorld* World)
		{
			if (!bConfigured || World == nullptr || GetGameInstance() == nullptr)
			{
				return;
			}
			if (World->GetGameInstance() != GetGameInstance())
			{
				return;
			}
			if (const UVrLinkComponent* Link = FindLink())
			{
				CarriedSession = Link->CaptureSession();
			}
		});
}

void UVrLinkSubsystem::Deinitialize()
{
	FWorldDelegates::OnPostWorldInitialization.Remove(WorldReadyHandle);
	FWorldDelegates::OnWorldBeginTearDown.Remove(WorldTearDownHandle);
	Super::Deinitialize();
}

void UVrLinkSubsystem::InitializeVrLink(const FString& ProjectName, const FString& Posture)
{
	// Remembered before anything else, so a call from Game Instance Init -- which
	// happens before any world exists -- still configures the link. The first level
	// to open then builds it. That is the natural place to call this from, and it
	// used to be the one place it did not work.
	ConfiguredProject = ProjectName;
	ConfiguredPosture = Posture;
	bConfigured = true;

	UWorld* World = GetGameInstance() ? GetGameInstance()->GetWorld() : nullptr;
	if (!World)
	{
		UE_LOG(LogVrLinkSubsystem, Log,
			TEXT("InitializeVrLink: no world yet, remembered '%s' and building at the first level."),
			*ProjectName);
		return;
	}

	BuildLink(World);
}

void UVrLinkSubsystem::BuildLink(UWorld* World)
{
	if (!World)
	{
		return;
	}

	// A level that already contains a VR Link (the Steps-table workflow) wins:
	// configure nothing, spawn nothing, drive that one.
	if (UVrLinkComponent* Existing = FindLink())
	{
		UE_LOG(LogVrLinkSubsystem, Log, TEXT("VR Link: using the level's own on %s."),
			*GetNameSafe(Existing->GetOwner()));
		return;
	}

	// Transport first, so the link component's auto-discovery finds it. The socket
	// starts its own server on BeginPlay (ConnectOnStart defaults true).
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	World->SpawnActor<ATCPSocket>(ATCPSocket::StaticClass(), FTransform::Identity, Params);

	AActor* Host = World->SpawnActor<AActor>(AActor::StaticClass(), FTransform::Identity, Params);
	if (!Host)
	{
		Warn(TEXT("VR Link: could not spawn the link host actor."));
		return;
	}
#if WITH_EDITOR
	Host->SetActorLabel(TEXT("VrLinkRuntime"));
#endif
	SpawnedHost = Host;

	// The link itself. On Trigger start mode = wait to be told; the subsystem's
	// StartSession is the telling. The Steps table stays empty: the experience,
	// not a table, drives this integration.
	UVrLinkComponent* Link = NewObject<UVrLinkComponent>(Host, TEXT("VrLink"));
	Link->StartMode = EExperienceStartMode::OnTrigger;
	Link->StudyConfig.Experience = ConfiguredProject;
	Link->StudyConfig.Posture = ConfiguredPosture;

	// Adopted BEFORE the component begins play, not after. BeginPlay decides what to
	// announce, and a link that is told about the carried session only afterwards spends
	// that moment believing no recording exists: it prints "Waiting: call Start
	// Experience" on every level of a running session, sending whoever is integrating
	// to look for a node they must not call.
	Link->RestoreSession(CarriedSession);
	Link->RegisterComponent();

	// Gaze rides along; it follows the session by itself.
	UGazeRecorder* Gaze = NewObject<UGazeRecorder>(Host, TEXT("GazeRecorder"));
	Gaze->VrLink = Link;
	Gaze->RegisterComponent();

	UE_LOG(LogVrLinkSubsystem, Log, TEXT("VR Link: built link + gaze for project '%s' (posture %s)."),
		*ConfiguredProject, *ConfiguredPosture);
}

void UVrLinkSubsystem::StartSession()
{
	LastLocation.Reset();
	if (UVrLinkComponent* Link = RequireLink(TEXT("StartSession")))
	{
		Link->StartSession();
	}
}

void UVrLinkSubsystem::EndSession(const FString& Reason)
{
	// Nothing to carry once it is over. Without this the next participant's first
	// level would adopt the previous participant's session id.
	CarriedSession = FVrLinkCarriedSession();

	if (UVrLinkComponent* Link = RequireLink(TEXT("EndSession")))
	{
		Link->EndSession(Reason.IsEmpty() ? TEXT("complete") : Reason);
	}
}

void UVrLinkSubsystem::SetLocation(const FString& Name)
{
	if (Name.IsEmpty() || Name == LastLocation)
	{
		return;   // trigger volumes love to fire twice; one location change = one event
	}
	if (UVrLinkComponent* Link = RequireLink(TEXT("SetLocation")))
	{
		LastLocation = Name;
		Link->SendState(TEXT("Scene"), Name);
	}
}

void UVrLinkSubsystem::SetScenario(const FString& Name)
{
	if (Name.IsEmpty())
	{
		return;
	}
	if (UVrLinkComponent* Link = RequireLink(TEXT("SetScenario")))
	{
		Link->SendState(TEXT("Scenario"), Name);
	}
}

void UVrLinkSubsystem::EndScenario()
{
	if (UVrLinkComponent* Link = RequireLink(TEXT("EndScenario")))
	{
		// The `fade` mark, which is what analysis already excludes on: the window runs
		// from here to the next scene or variable event, so the next Start Scenario or
		// Set Location closes it. Everything in between counts for nothing, which is
		// exactly what a scenario having ended means.
		//
		// One mark and no second event, deliberately. A variable sent alongside it would
		// carry the same timestamp and close the window it had just opened.
		//
		// It matters for gaze as much as for EEG. Rays cast between two scenarios still
		// hit whatever the head is pointing at, and without this they are counted as
		// somebody looking at the design that just ended.
		Link->SendMark(TEXT("fade"));
	}
}

void UVrLinkSubsystem::SendMark(const FString& Label)
{
	if (UVrLinkComponent* Link = RequireLink(TEXT("SendMark")))
	{
		Link->SendMark(Label);
	}
}

bool UVrLinkSubsystem::IsSessionActive() const
{
	const UVrLinkComponent* Link = FindLink();
	return Link != nullptr && Link->IsSessionActive();
}

FString UVrLinkSubsystem::GetSessionId() const
{
	const UVrLinkComponent* Link = FindLink();
	return Link ? Link->GetSessionId() : FString();
}

void UVrLinkSubsystem::StartBaseline(EVrLinkCalibrationPhase Phase)
{
	SendBaselinePhase(Phase, /*bStart=*/true);
}

void UVrLinkSubsystem::EndBaseline(EVrLinkCalibrationPhase Phase)
{
	SendBaselinePhase(Phase, /*bStart=*/false);
}

void UVrLinkSubsystem::SendBaselinePhase(EVrLinkCalibrationPhase Phase, bool bStart)
{
	// The exact strings the recorder pins its calibration predicate to. Changing one
	// of these silently changes which rows the tablet treats as calibration, so they
	// are written out here rather than derived from the enum's own names.
	const TCHAR* Name = TEXT("baseline");
	switch (Phase)
	{
	case EVrLinkCalibrationPhase::Relaxed:  Name = TEXT("relaxed");  break;
	case EVrLinkCalibrationPhase::Stressed: Name = TEXT("stressed"); break;
	case EVrLinkCalibrationPhase::Baseline: break;
	}

	if (UVrLinkComponent* Link = RequireLink(TEXT("SendBaselinePhase")))
	{
		Link->SendBaseline(Name, bStart);
	}
}

UVrLinkComponent* UVrLinkSubsystem::FindLink() const
{
	UWorld* World = GetGameInstance() ? GetGameInstance()->GetWorld() : nullptr;
	if (!World)
	{
		return nullptr;
	}

	// The spawned host first (cheap), then any component in the level.
	if (AActor* Host = SpawnedHost.Get())
	{
		if (UVrLinkComponent* Link = Host->FindComponentByClass<UVrLinkComponent>())
		{
			return Link;
		}
	}
	for (TActorIterator<AActor> It(World); It; ++It)
	{
		if (UVrLinkComponent* Link = It->FindComponentByClass<UVrLinkComponent>())
		{
			return Link;
		}
	}
	return nullptr;
}

UVrLinkComponent* UVrLinkSubsystem::RequireLink(const TCHAR* ForCall)
{
	if (UVrLinkComponent* Link = FindLink())
	{
		return Link;
	}

	// Nothing here yet. If the caller has said which project this is, that is
	// everything needed to build one, so build it rather than refusing and
	// telling them to do what they already did.
	UWorld* World = GetGameInstance() ? GetGameInstance()->GetWorld() : nullptr;
	if (bConfigured && World != nullptr)
	{
		UE_LOG(LogVrLinkSubsystem, Log,
			TEXT("VR Link: %s arrived before the link existed in %s; building it now."),
			ForCall, *GetNameSafe(World));
		SpawnedHost.Reset();
		BuildLink(World);
		if (UVrLinkComponent* Built = FindLink())
		{
			return Built;
		}
	}

	// Now the message means what it says: either Initialize Vr Link was never
	// called, or there is no world to build into.
	// Each Printf takes a literal format: the checked-format macro will not accept
	// one chosen at run time, so the choice is made over whole messages instead.
	Warn(bConfigured
		? FString::Printf(TEXT("%s: no world to build the VR Link into yet. Call it once play has started."), ForCall)
		: FString::Printf(TEXT("%s: Initialize Vr Link has not been called. Call it from the Game Instance."), ForCall));
	return nullptr;
}
