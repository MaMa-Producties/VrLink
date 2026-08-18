// Fill out your copyright notice in the Description page of Project Settings.


#include "VrLinkComponent.h"
#include "TCPSocket.h"
#include "NetworkManager.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Serialization/JsonSerializer.h"
#include "Policies/CondensedJsonPrintPolicy.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogExperience, Log, All);

namespace
{
	/**
	 * How Location and Scenario map onto vrlink state events.
	 *
	 * vrlink treats a state change named "Scene" as a scene change and any other
	 * name as a variable change, so Location is sent as "Scene" and Scenario as a
	 * variable named "Scenario". These two constants are the entire mapping.
	 */
	const TCHAR* const LocationStateName = TEXT("Scene");
	const TCHAR* const ScenarioStateName = TEXT("Scenario");

	/**
	 * The phase sent with baseline start and end, deliberately not configurable.
	 *
	 * The recorder only treats a phase as a rest window when it is "baseline" or
	 * "relaxed" (SessionRecorder.cs:115-116). The other phases vrlink documents,
	 * "focus" and "stressed", would be accepted, sent, and then silently not
	 * recorded, leaving the session with no baseline and no error raised anywhere.
	 */
	const TCHAR* const BaselinePhaseName = TEXT("baseline");

	/** Prints to the log and to the viewport, keyed so lines update instead of stacking. */
	void Announce(int32 Key, const FColor& Colour, const FString& Message)
	{
		UE_LOG(LogExperience, Log, TEXT("%s"), *Message);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Key, 8.f, Colour, FString(TEXT("[Experience] ")) + Message);
		}
	}

	constexpr int32 KeyStatus = 8801;
	constexpr int32 KeyStep = 8802;
	constexpr int32 KeyWaiting = 8803;
}

UVrLinkComponent::UVrLinkComponent()
{
	// Only ticks in Manual mode, to poll the advance key. Enabled in BeginPlay.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	// Default to the Lichtverhaal/Spaklerweg example from the vrlink v1.1 spec (§3).
	StudyConfig.Experience = TEXT("Spaklerweg");
	StudyConfig.Posture = TEXT("Cycling");

	// Empty pairing code = accept any tablet. Set one only when several stations
	// share a room, otherwise a mismatch rejects the tablet on every retry.
	StudyConfig.PairingCode = FString();
}

void UVrLinkComponent::BeginPlay()
{
	Super::BeginPlay();

	// Auto-discover the transport actor in the level if it was not wired up in the editor.
	if (!Socket)
	{
		for (TActorIterator<ATCPSocket> It(GetWorld()); It; ++It)
		{
			Socket = *It;
			break;
		}
	}

	if (Socket)
	{
		Socket->OnMessageReceived.AddDynamic(this, &UVrLinkComponent::HandleLine);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[vrlink] No ATCPSocket found; inbound messages will not be handled."));
	}

	SetComponentTickEnabled(AdvanceMode == EStepAdvanceMode::Manual);

	// Always announce ourselves. Silence at startup is indistinguishable from the
	// component not being in the level at all, which wastes time diagnosing.
	Announce(KeyStatus, Socket ? FColor::Green : FColor::Orange,
		FString::Printf(TEXT("Ready on %s: %d step(s), advance=%s, start=%s, socket=%s, pairing=%s"),
			*GetNameSafe(GetOwner()),
			Steps.Num(),
			*UEnum::GetDisplayValueAsText(AdvanceMode).ToString(),
			*UEnum::GetDisplayValueAsText(StartMode).ToString(),
			Socket ? TEXT("found") : TEXT("MISSING"),
			StudyConfig.PairingCode.IsEmpty() ? TEXT("any tablet") : *StudyConfig.PairingCode));

	switch (StartMode)
	{
	case EExperienceStartMode::OnBeginPlay:
		StartExperience();
		break;

	case EExperienceStartMode::OnTrigger:
		if (StartTrigger)
		{
			// No Blueprint needed: start the first time the participant walks into the assigned volume.
			StartTrigger->OnActorBeginOverlap.AddDynamic(this, &UVrLinkComponent::OnStartTriggerOverlap);
			Announce(KeyWaiting, FColor::Yellow,
				FString::Printf(TEXT("Waiting: starts when the participant enters %s."), *GetNameSafe(StartTrigger)));
		}
		else
		{
			Announce(KeyWaiting, FColor::Yellow,
				TEXT("Waiting: call Start Experience (from a trigger or Blueprint) to begin."));
		}
		break;

	case EExperienceStartMode::OnTabletStart:
		Announce(KeyWaiting, FColor::Yellow,
			TEXT("Waiting: starts when the tablet operator presses Start Recording."));
		break;
	}
}

void UVrLinkComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (AdvanceMode != EStepAdvanceMode::Manual || !IsRunning())
	{
		return;
	}

	if (const APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		if (ManualAdvanceKey.IsValid() && PC->WasInputKeyJustPressed(ManualAdvanceKey))
		{
			GoToNextStep();
		}
	}
}

// ---------------------------------------------------------------- experience

TArray<FString> UVrLinkComponent::BuildSceneList() const
{
	TArray<FString> Scenes;
	for (const FExperienceStep& Step : Steps)
	{
		if (Step.StepKind == EStepKind::Scenario && !Step.Location.IsEmpty())
		{
			Scenes.AddUnique(Step.Location);
		}
	}
	return Scenes;
}

TArray<FVrLinkVariable> UVrLinkComponent::BuildVariableList() const
{
	FVrLinkVariable ScenarioVar;
	ScenarioVar.Name = ScenarioStateName;

	for (const FExperienceStep& Step : Steps)
	{
		if (Step.StepKind == EStepKind::Scenario && !Step.Scenario.IsEmpty())
		{
			ScenarioVar.Options.AddUnique(Step.Scenario);
		}
	}

	TArray<FVrLinkVariable> Variables;
	if (ScenarioVar.Options.Num() > 0)
	{
		Variables.Add(ScenarioVar);
	}
	return Variables;
}

void UVrLinkComponent::OnStartTriggerOverlap(AActor* /*OverlappedActor*/, AActor* OtherActor)
{
	// Only the participant (a pawn) starts it, not stray world actors. Fire once, then unbind so
	// re-entering the volume can never restart a running experience.
	if (!OtherActor || !OtherActor->IsA<APawn>())
	{
		return;
	}
	if (StartTrigger)
	{
		StartTrigger->OnActorBeginOverlap.RemoveDynamic(this, &UVrLinkComponent::OnStartTriggerOverlap);
	}
	StartExperience();
}

void UVrLinkComponent::StartExperience()
{
	if (IsRunning())
	{
		UE_LOG(LogExperience, Warning, TEXT("StartExperience ignored: already running at step %d."), CurrentStep);
		return;
	}

	if (Steps.Num() == 0)
	{
		Announce(KeyStatus, FColor::Red, TEXT("Cannot start: the Steps table is empty."));
		return;
	}

	// A baseline is mandatory: every reading is normalised against a rest window, so a run
	// without one is uninterpretable. Refuse to start rather than record un-baselined data.
	const bool bHasBaseline = Steps.ContainsByPredicate(
		[](const FExperienceStep& S) { return S.StepKind == EStepKind::Baseline; });
	if (!bHasBaseline)
	{
		Announce(KeyStatus, FColor::Red,
			TEXT("Cannot start: no Baseline step in the Steps table. A baseline is required for every run."));
		return;
	}

	LastLocationSent.Reset();
	EnterStep(0);
}

void UVrLinkComponent::StopExperience()
{
	ClearTimers();

	if (IsRunning())
	{
		EndCurrentStep();
	}

	CurrentStep = INDEX_NONE;
}

void UVrLinkComponent::GoToNextStep()
{
	if (!IsRunning())
	{
		UE_LOG(LogExperience, Warning, TEXT("GoToNextStep ignored: the experience is not running."));
		return;
	}

	// An explicit advance cuts the step short, so the fade delay does not apply.
	ClearTimers();
	EndCurrentStep();
	StartNextStep();
}

void UVrLinkComponent::EnterStep(int32 StepIndex)
{
	if (!Steps.IsValidIndex(StepIndex))
	{
		return;
	}

	CurrentStep = StepIndex;
	const FExperienceStep& Step = Steps[StepIndex];

	switch (Step.StepKind)
	{
	case EStepKind::Baseline:
		SendBaseline(BaselinePhaseName, /*bStart=*/true);
		bBaselineIsOpen = true;
		break;

	case EStepKind::Scenario:
		// Only send the location when it changes, so consecutive scenarios in one
		// location produce a single location event rather than a redundant second.
		// SendState records it as the current scene, so no assignment is needed here.
		if (!Step.Location.IsEmpty() && Step.Location != LastLocationSent)
		{
			SendState(LocationStateName, Step.Location);
		}

		if (!Step.Scenario.IsEmpty())
		{
			SendState(ScenarioStateName, Step.Scenario);
		}
		break;

	case EStepKind::SettleIn:
	default:
		break;
	}

	Announce(KeyStep, FColor::Cyan,
		FString::Printf(TEXT("Step %d/%d STARTED  [%s]  %s / %s"),
			StepIndex + 1, Steps.Num(),
			*UEnum::GetDisplayValueAsText(Step.StepKind).ToString(),
			Step.Location.IsEmpty() ? TEXT("-") : *Step.Location,
			Step.Scenario.IsEmpty() ? TEXT("-") : *Step.Scenario));

	OnStepStarted.Broadcast(Step.Location, Step.Scenario, Step.StepKind, StepIndex);

	if (AdvanceMode != EStepAdvanceMode::Duration)
	{
		Announce(KeyWaiting, FColor::Yellow,
			AdvanceMode == EStepAdvanceMode::Manual
				? FString::Printf(TEXT("Waiting: press %s to advance."), *ManualAdvanceKey.GetDisplayName().ToString())
				: FString(TEXT("Waiting: participant must reach a trigger volume.")));
		return;
	}

	UWorld* World = GetWorld();
	if (World == nullptr)
	{
		return;
	}

	if (Step.DurationSeconds > KINDA_SMALL_NUMBER)
	{
		World->GetTimerManager().SetTimer(
			StepTimer, this, &UVrLinkComponent::EndStepThenWaitForFade, Step.DurationSeconds, false);
	}
	else
	{
		// A timer with a rate of 0 never fires, so advance next tick rather than
		// stalling the whole experience on one unfilled entry.
		World->GetTimerManager().SetTimerForNextTick(this, &UVrLinkComponent::EndStepThenWaitForFade);
	}
}

void UVrLinkComponent::EndStepThenWaitForFade()
{
	if (!IsRunning())
	{
		return;
	}

	const float FadeSeconds = Steps[CurrentStep].FadeOutSeconds;

	EndCurrentStep();

	UWorld* World = GetWorld();
	if (World == nullptr)
	{
		return;
	}

	if (FadeSeconds > KINDA_SMALL_NUMBER)
	{
		// Mark the fade/blackout window so analysis can exclude it. A fade is never a point of
		// interest, and the visual transition to black can itself provoke an EEG spike. The window
		// runs from this mark to the next scene/variable event, or to session.end at the last step.
		SendMark(TEXT("fade"));
		World->GetTimerManager().SetTimer(
			FadeTimer, this, &UVrLinkComponent::StartNextStep, FadeSeconds, false);
	}
	else
	{
		StartNextStep();
	}
}

void UVrLinkComponent::EndCurrentStep()
{
	if (!Steps.IsValidIndex(CurrentStep))
	{
		return;
	}

	const FExperienceStep& Step = Steps[CurrentStep];

	if (Step.StepKind == EStepKind::Baseline && bBaselineIsOpen)
	{
		SendBaseline(BaselinePhaseName, /*bStart=*/false);
		bBaselineIsOpen = false;
	}

	Announce(KeyStep, FColor::Silver,
		FString::Printf(TEXT("Step %d/%d ended    %s / %s"),
			CurrentStep + 1, Steps.Num(),
			Step.Location.IsEmpty() ? TEXT("-") : *Step.Location,
			Step.Scenario.IsEmpty() ? TEXT("-") : *Step.Scenario));

	OnStepEnded.Broadcast(Step.Location, Step.Scenario, Step.StepKind, CurrentStep);
}

void UVrLinkComponent::StartNextStep()
{
	const int32 NextStep = CurrentStep + 1;

	if (Steps.IsValidIndex(NextStep))
	{
		EnterStep(NextStep);
		return;
	}

	CurrentStep = INDEX_NONE;
	Announce(KeyStep, FColor::Green, TEXT("Experience FINISHED."));

	// The last fadeout has ended. Tell Unity to stop recording and save the eeg/events files;
	// Unity then runs the questionnaire and writes the session file (vrlink handoff step 9-10).
	// No-op if the session was already ended from the tablet.
	EndSession(TEXT("complete"));

	OnExperienceFinished.Broadcast();
}

void UVrLinkComponent::ClearTimers()
{
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(StepTimer);
		World->GetTimerManager().ClearTimer(FadeTimer);
	}
}

void UVrLinkComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Never leave a baseline open: the recorder would treat the rest window as
	// running to the end of the session and normalise every reading against it.
	StopExperience();

	if (Socket)
	{
		Socket->OnMessageReceived.RemoveDynamic(this, &UVrLinkComponent::HandleLine);
	}

	if (StartTrigger)
	{
		StartTrigger->OnActorBeginOverlap.RemoveDynamic(this, &UVrLinkComponent::OnStartTriggerOverlap);
	}

	Super::EndPlay(EndPlayReason);
}

void UVrLinkComponent::HandleLine(FString Line)
{
	Line.TrimStartAndEndInline();
	if (Line.IsEmpty())
	{
		return;
	}

	// Parse the one JSON object on this line.
	TSharedPtr<FJsonObject> Msg;
	const TSharedRef<TJsonReader<TCHAR>> Reader = TJsonReaderFactory<TCHAR>::Create(Line);
	if (!FJsonSerializer::Deserialize(Reader, Msg) || !Msg.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("[vrlink] Ignoring unparseable line: %s"), *Line);
		return;
	}

	FString Type;
	Msg->TryGetStringField(TEXT("type"), Type);

	// Dispatch on message type. Unknown types are ignored for forward compatibility.
	if (Type == TEXT("hello"))
	{
		HandleHello(Msg);
	}
	else if (Type == TEXT("session.start"))
	{
		HandleSessionStart(Msg);
	}
	else if (Type == TEXT("session.started"))
	{
		HandleSessionStarted(Msg);
	}
	else if (Type == TEXT("session.end"))
	{
		HandleSessionEnd(Msg);
	}
	else if (Type == TEXT("session.saved"))
	{
		// Ack to our own session.end; nothing further to do on this side.
		UE_LOG(LogTemp, Log, TEXT("[vrlink] Peer saved its session file."));
	}
	else if (Type == TEXT("ping"))
	{
		// Keepalive: no-op (the OS-level connection staying up is the signal).
	}
	else if (Type == TEXT("error"))
	{
		FString ErrText;
		Msg->TryGetStringField(TEXT("message"), ErrText);
		UE_LOG(LogTemp, Error, TEXT("[vrlink] Peer error: %s"), *ErrText);
	}
	// `welcome`, `reject`, `state`, `baseline.*`, `mark`, `gaze` are Unreal -> Unity
	// (or handshake replies to Unity); inbound copies are ignored here.
}

void UVrLinkComponent::HandleHello(const TSharedPtr<FJsonObject>& Msg)
{
	// Validate protocol and version; reject and close on mismatch (spec §3).
	FString Protocol;
	Msg->TryGetStringField(TEXT("protocol"), Protocol);

	int32 Version = 0;
	Msg->TryGetNumberField(TEXT("version"), Version);

	if (Protocol != TEXT("vrlink") || Version != 1)
	{
		SendReject(FString::Printf(TEXT("unsupported protocol/version (%s v%d)"), *Protocol, Version));
		return;
	}

	// Pairing: if this station has a code, only accept a tablet whose code matches (spec §3).
	// Empty code = automatic (accept any tablet).
	if (!StudyConfig.PairingCode.IsEmpty())
	{
		FString TabletCode;
		Msg->TryGetStringField(TEXT("pairingCode"), TabletCode);
		if (TabletCode != StudyConfig.PairingCode)
		{
			SendReject(TEXT("pairing-code-mismatch"), /*bStopServer=*/false);
			return;
		}
	}

	// Remember the museId so we can mint a session id later if we ever need to.
	Msg->TryGetStringField(TEXT("museId"), MuseId);

	// A fresh connection: reset the per-connection sequence counter.
	OutSeq = 0;

	// Reply `welcome` with the study definition Unity will lock onto.
	const TSharedRef<FJsonObject> Welcome = MakeShared<FJsonObject>();
	Welcome->SetStringField(TEXT("type"), TEXT("welcome"));
	Welcome->SetNumberField(TEXT("version"), 1);
	// One name only: sent as `experience` (Unity reads experience first). The old separate `project`
	// field was collapsed into this; the editor labels it "Project Name".
	Welcome->SetStringField(TEXT("experience"), StudyConfig.Experience);
	Welcome->SetBoolField(TEXT("baseline"), true); // baseline is mandatory; no opt-out
	Welcome->SetStringField(TEXT("posture"), StudyConfig.Posture);
	Welcome->SetStringField(TEXT("pairingCode"), StudyConfig.PairingCode); // echo so the tablet can confirm the pairing

	// Scenes and variables are DERIVED from the Steps table, never authored separately,
	// so the names the tablet is told are by construction the names the events carry.
	TArray<TSharedPtr<FJsonValue>> Variables;
	for (const FVrLinkVariable& Var : BuildVariableList())
	{
		const TSharedRef<FJsonObject> VarObj = MakeShared<FJsonObject>();
		VarObj->SetStringField(TEXT("name"), Var.Name);

		TArray<TSharedPtr<FJsonValue>> Options;
		for (const FString& Option : Var.Options)
		{
			Options.Add(MakeShared<FJsonValueString>(Option));
		}
		VarObj->SetArrayField(TEXT("options"), Options);
		Variables.Add(MakeShared<FJsonValueObject>(VarObj));
	}
	Welcome->SetArrayField(TEXT("variables"), Variables);

	TArray<TSharedPtr<FJsonValue>> Scenes;
	for (const FString& Scene : BuildSceneList())
	{
		Scenes.Add(MakeShared<FJsonValueString>(Scene));
	}
	Welcome->SetArrayField(TEXT("scenes"), Scenes);

	// Baseline length (seconds) from the Baseline step, so the tablet shows/drives the real duration
	// instead of falling back to its own default. Baseline is mandatory, so a Baseline step always exists.
	float BaselineSeconds = 0.f;
	for (const FExperienceStep& Step : Steps)
	{
		if (Step.StepKind == EStepKind::Baseline)
		{
			BaselineSeconds = Step.DurationSeconds;
			break;
		}
	}
	Welcome->SetNumberField(TEXT("baselineSeconds"), FMath::RoundToInt(BaselineSeconds));

	// The ordered phase/step names, so the tablet's live progress shows the real timeline. One entry per
	// step, in order; the tablet reads `phases` (array of strings) to build its segments.
	TArray<TSharedPtr<FJsonValue>> Phases;
	for (const FExperienceStep& Step : Steps)
	{
		FString PhaseName;
		switch (Step.StepKind)
		{
		case EStepKind::SettleIn: PhaseName = TEXT("Settle In"); break;
		case EStepKind::Baseline: PhaseName = TEXT("Baseline"); break;
		default:
			if (!Step.Location.IsEmpty() && !Step.Scenario.IsEmpty()) PhaseName = Step.Location + TEXT(" / ") + Step.Scenario;
			else if (!Step.Scenario.IsEmpty()) PhaseName = Step.Scenario;
			else if (!Step.Location.IsEmpty()) PhaseName = Step.Location;
			else PhaseName = TEXT("Scenario");
			break;
		}
		Phases.Add(MakeShared<FJsonValueString>(PhaseName));
	}
	Welcome->SetArrayField(TEXT("phases"), Phases);

	Welcome->SetNumberField(TEXT("tServer"), SessionElapsedSeconds());

	SendJson(Welcome);
	bHandshakeComplete = true;
}

void UVrLinkComponent::HandleSessionStart(const TSharedPtr<FJsonObject>& Msg)
{
	// Unity-initiated start (spec §4 case A): adopt its sessionId and reply session.started.
	BeginSessionClock(NowIso());

	FString IncomingId;
	Msg->TryGetStringField(TEXT("sessionId"), IncomingId);
	if (IncomingId.IsEmpty())
	{
		// Responder mints the id when the initiator sent null.
		IncomingId = FString::Printf(TEXT("%s-%s"),
			MuseId.IsEmpty() ? TEXT("Muse") : *MuseId,
			*FDateTime::UtcNow().ToString(TEXT("%Y%m%dT%H%M%SZ")));
	}
	SessionId = IncomingId;

	// Unity mints the shared output folder name; adopt it for later use (empty if absent).
	Msg->TryGetStringField(TEXT("sessionFolder"), SessionFolder);

	FString IncomingMuse;
	if (Msg->TryGetStringField(TEXT("museId"), IncomingMuse) && !IncomingMuse.IsEmpty())
	{
		MuseId = IncomingMuse;
	}
	Msg->TryGetStringField(TEXT("participantId"), ParticipantId);

	const TSharedRef<FJsonObject> Started = MakeShared<FJsonObject>();
	Started->SetStringField(TEXT("type"), TEXT("session.started"));
	Started->SetStringField(TEXT("sessionId"), SessionId);
	Started->SetBoolField(TEXT("ok"), true);
	SendJson(Started);

	// Tell Blueprint the recording is now live, so environment movement/visuals can begin.
	OnRecordingStarted.Broadcast(SessionId);

	// If configured to follow the tablet, launch the experience now: the recording and our session
	// clock have just started, so the timeline and the EEG share one zero point by construction.
	if (StartMode == EExperienceStartMode::OnTabletStart && !IsRunning())
	{
		StartExperience();
	}

	UE_LOG(LogTemp, Log, TEXT("[vrlink] Session started (Unity-initiated): %s"), *SessionId);
}

void UVrLinkComponent::HandleSessionStarted(const TSharedPtr<FJsonObject>& Msg)
{
	// Ack to our own session.start (spec §4 case B): adopt the returned identifiers.
	Msg->TryGetStringField(TEXT("sessionId"), SessionId);

	// Unity mints the shared output folder name; adopt it for later use (empty if absent).
	Msg->TryGetStringField(TEXT("sessionFolder"), SessionFolder);

	FString IncomingMuse;
	if (Msg->TryGetStringField(TEXT("museId"), IncomingMuse) && !IncomingMuse.IsEmpty())
	{
		MuseId = IncomingMuse;
	}
	Msg->TryGetStringField(TEXT("participantId"), ParticipantId);

	UE_LOG(LogTemp, Log, TEXT("[vrlink] Session started (VR-initiated), adopted id: %s"), *SessionId);

	// Same Blueprint signal as the tablet-initiated path: the recording is now live.
	OnRecordingStarted.Broadcast(SessionId);
}

void UVrLinkComponent::HandleSessionEnd(const TSharedPtr<FJsonObject>& Msg)
{
	// Unity-initiated end (spec §4 stop): Unity owns the event log, so just reply session.saved.
	bSessionActive = false;

	const TSharedRef<FJsonObject> Saved = MakeShared<FJsonObject>();
	Saved->SetStringField(TEXT("type"), TEXT("session.saved"));
	Saved->SetStringField(TEXT("sessionId"), SessionId);
	Saved->SetBoolField(TEXT("ok"), true);
	// The gaze file if a gaze recorder is running, empty otherwise. The gaze recorder
	// notices the session ended on its next tick and closes the file then; this names
	// the path so the operator can see on the tablet that the PC wrote its half.
	Saved->SetStringField(TEXT("file"), GazeFilePath);
	SendJson(Saved);
}

void UVrLinkComponent::StartSession()
{
	if (!bHandshakeComplete)
	{
		UE_LOG(LogTemp, Warning, TEXT("[vrlink] StartSession before handshake; ignored."));
		return;
	}

	// VR-initiated (spec §4 case B): start our clock and send a null sessionId; Unity mints it.
	BeginSessionClock(NowIso());
	SessionId.Reset();

	const TSharedRef<FJsonObject> Start = MakeEvent(TEXT("session.start"), SessionElapsedSeconds(), NowIso());
	Start->SetField(TEXT("sessionId"), MakeShared<FJsonValueNull>());
	SendJson(Start);
}

void UVrLinkComponent::EndSession(const FString& Reason)
{
	if (!bSessionActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("[vrlink] EndSession with no active session; ignored."));
		return;
	}

	const double EndT = SessionElapsedSeconds();
	const FString EndWall = NowIso();
	bSessionActive = false;

	// VR-initiated end (spec §4 stop): notify Unity (Unity owns the event log).
	const TSharedRef<FJsonObject> End = MakeEvent(TEXT("session.end"), EndT, EndWall);
	End->SetStringField(TEXT("sessionId"), SessionId);
	End->SetStringField(TEXT("reason"), Reason);
	SendJson(End);
}

void UVrLinkComponent::SendState(const FString& Name, const FString& Value)
{
	const double T = SessionElapsedSeconds();
	const FString Wall = NowIso();

	// Remember the scene here rather than at the call sites, so a scene set from
	// Blueprint stamps gaze rows exactly like one set by a step does.
	if (Name == LocationStateName)
	{
		LastLocationSent = Value;
	}

	// Send to Unity, which records it in its own event log (a scene change if
	// Name=="Scene", otherwise a variable/condition change).
	const TSharedRef<FJsonObject> Event = MakeEvent(TEXT("state"), T, Wall);
	Event->SetStringField(TEXT("name"), Name);
	Event->SetStringField(TEXT("value"), Value);
	SendJson(Event);
}

void UVrLinkComponent::SendBaseline(const FString& Phase, bool bStart)
{
	const TSharedRef<FJsonObject> Event = MakeEvent(bStart ? TEXT("baseline.start") : TEXT("baseline.end"), SessionElapsedSeconds(), NowIso());
	Event->SetStringField(TEXT("phase"), Phase);
	SendJson(Event);
}

void UVrLinkComponent::SendMark(const FString& Label)
{
	const double T = SessionElapsedSeconds();
	const FString Wall = NowIso();

	// Send to Unity, which records it in its own event log.
	const TSharedRef<FJsonObject> Event = MakeEvent(TEXT("mark"), T, Wall);
	Event->SetStringField(TEXT("label"), Label);
	SendJson(Event);
}

void UVrLinkComponent::SendError(const FString& Message)
{
	const TSharedRef<FJsonObject> Error = MakeShared<FJsonObject>();
	Error->SetStringField(TEXT("type"), TEXT("error"));
	Error->SetStringField(TEXT("message"), Message);
	SendJson(Error);
}

void UVrLinkComponent::SendReject(const FString& Reason, bool bStopServer)
{
	const TSharedRef<FJsonObject> Reject = MakeShared<FJsonObject>();
	Reject->SetStringField(TEXT("type"), TEXT("reject"));
	Reject->SetStringField(TEXT("reason"), Reason);
	SendJson(Reject);

	// On a bad protocol/version, drop the link entirely. But a pairing-code mismatch just means this
	// isn't our tablet — keep listening so this station's own tablet can still connect.
	if (bStopServer)
	{
		NetworkManager::GetInstance().StopServer();
	}
}

void UVrLinkComponent::SendJson(const TSharedRef<FJsonObject>& Obj)
{
	// Serialize as a single condensed line; SendLine adds the '\n' framing.
	FString Out;
	const TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer =
		TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&Out);
	FJsonSerializer::Serialize(Obj, Writer);

	NetworkManager::GetInstance().SendLine(Out);
}

TSharedRef<FJsonObject> UVrLinkComponent::MakeEvent(const FString& Type, double T, const FString& WallUtc)
{
	const TSharedRef<FJsonObject> Obj = MakeShared<FJsonObject>();
	Obj->SetStringField(TEXT("type"), Type);
	Obj->SetNumberField(TEXT("seq"), ++OutSeq);
	Obj->SetNumberField(TEXT("t"), T);
	Obj->SetStringField(TEXT("wallUtc"), WallUtc);
	return Obj;
}

void UVrLinkComponent::BeginSessionClock(const FString& WallUtc)
{
	SessionStartSeconds = FPlatformTime::Seconds();
	SessionStartWallUtc = WallUtc;
	bSessionActive = true;
}

double UVrLinkComponent::SessionElapsedSeconds() const
{
	return bSessionActive ? (FPlatformTime::Seconds() - SessionStartSeconds) : 0.0;
}

FString UVrLinkComponent::NowIso()
{
	return FDateTime::UtcNow().ToIso8601();
}
