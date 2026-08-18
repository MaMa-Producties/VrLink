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

void UVrLinkSubsystem::InitializeVrLink(const FString& ProjectName, const FString& Posture)
{
	UWorld* World = GetGameInstance() ? GetGameInstance()->GetWorld() : nullptr;
	if (!World)
	{
		Warn(TEXT("InitializeVrLink: no world yet; call it from BeginPlay or later."));
		return;
	}

	// A level that already contains a VR Link (the Steps-table workflow) wins:
	// configure nothing, spawn nothing, drive that one.
	if (UVrLinkComponent* Existing = FindLink())
	{
		UE_LOG(LogVrLinkSubsystem, Log, TEXT("InitializeVrLink: using the level's own VR Link on %s."),
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
		Warn(TEXT("InitializeVrLink: could not spawn the link host actor."));
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
	Link->StudyConfig.Experience = ProjectName;
	Link->StudyConfig.Posture = Posture;
	Link->RegisterComponent();

	// Gaze rides along; it follows the session by itself.
	UGazeRecorder* Gaze = NewObject<UGazeRecorder>(Host, TEXT("GazeRecorder"));
	Gaze->VrLink = Link;
	Gaze->RegisterComponent();

	UE_LOG(LogVrLinkSubsystem, Log, TEXT("InitializeVrLink: spawned link + gaze for project '%s' (posture %s)."),
		*ProjectName, *Posture);
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

void UVrLinkSubsystem::SendBaselinePhase(const FString& Phase, bool bStart)
{
	if (UVrLinkComponent* Link = RequireLink(TEXT("SendBaselinePhase")))
	{
		Link->SendBaseline(Phase.IsEmpty() ? TEXT("baseline") : Phase, bStart);
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

UVrLinkComponent* UVrLinkSubsystem::RequireLink(const TCHAR* ForCall) const
{
	UVrLinkComponent* Link = FindLink();
	if (!Link)
	{
		Warn(FString::Printf(TEXT("%s: no VR Link in the level. Call Initialize Vr Link first."), ForCall));
	}
	return Link;
}
