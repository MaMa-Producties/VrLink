// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Dom/JsonObject.h"
#include "InputCoreTypes.h"
#include "VrLinkComponent.generated.h"

class ATCPSocket;

/** What a step represents, which determines the events it sends to the recorder. */
UENUM(BlueprintType)
enum class EStepKind : uint8
{
	/** Sends no events. Use it to hold time while the participant gets set up. */
	SettleIn UMETA(DisplayName = "Settle In"),

	/** The rest window every other reading is normalised against. Sends baseline start and end. */
	Baseline UMETA(DisplayName = "Baseline"),

	/** A design variant shown at a location. Sends the location and scenario. */
	Scenario UMETA(DisplayName = "Scenario")
};

/** What advances the timeline to the next step. */
UENUM(BlueprintType)
enum class EStepAdvanceMode : uint8
{
	/** Each step advances once its DurationSeconds elapses. Requires no level content. */
	Duration UMETA(DisplayName = "Duration"),

	/** A trigger volume in the level advances the timeline by calling GoToNextStep. */
	TriggerVolume UMETA(DisplayName = "Trigger Volume"),

	/** A key or controller button advances the timeline. Useful for stepping through a run. */
	Manual UMETA(DisplayName = "Manual")
};

/** What starts the experience running. */
UENUM(BlueprintType)
enum class EExperienceStartMode : uint8
{
	/** Starts automatically the moment the level begins play. */
	OnBeginPlay UMETA(DisplayName = "On Begin Play"),

	/** Waits to be started: by a Start Trigger volume you assign, or a Blueprint call to Start Experience. */
	OnTrigger UMETA(DisplayName = "On Trigger"),

	/** Starts automatically when the tablet operator presses Start Recording (on the tablet's session.start). */
	OnTabletStart UMETA(DisplayName = "When Tablet Starts Recording")
};

/**
 * One step of the experience. The Location and Scenario set here are the single
 * source of truth: they are written into the recorded data AND they generate the
 * scene and variable lists sent to the tablet in the handshake, so the two can
 * never disagree.
 */
USTRUCT(BlueprintType)
struct FExperienceStep
{
	GENERATED_BODY()

	/** What this step represents. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience")
	EStepKind StepKind = EStepKind::Scenario;

	/** Where the participant is, e.g. "Spaklerweg". Reuse the same value across scenarios in one location. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience",
		meta = (EditCondition = "StepKind == EStepKind::Scenario", EditConditionHides))
	FString Location;

	/** The design variant shown here, e.g. "Green facade". */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience",
		meta = (EditCondition = "StepKind == EStepKind::Scenario", EditConditionHides))
	FString Scenario;

	/** How long the step runs. Only used when AdvanceMode is Duration. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float DurationSeconds = 30.f;

	/** Delay between this step ending and the next starting, to allow a fade. Only used when AdvanceMode is Duration. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float FadeOutSeconds = 0.f;
};

/**
 * One study variable (condition) the VR side drives, e.g. "Scenario" with options
 * "Green facade"/"Grey facade". Built automatically from the Steps table and sent
 * in the `welcome` handshake so the tablet locks its recorder config to what the
 * experience actually contains. Not authored by hand.
 */
USTRUCT(BlueprintType)
struct FVrLinkVariable
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "VrLink")
	FString Name;

	UPROPERTY(BlueprintReadOnly, Category = "VrLink")
	TArray<FString> Options;
};

/**
 * The study definition handed to the recorder in the `welcome` message (vrlink v1.1 Â§3).
 *
 * Note there is no scene or variable list here: those are derived from the Steps
 * table on the component, so the names in the handshake and the names in the
 * recorded events are guaranteed to be the same.
 */
USTRUCT(BlueprintType)
struct FVrLinkStudyConfig
{
	GENERATED_BODY()

	/**
	 * The project / study name: the urban-development project, e.g. "Spaklerweg". One field, shown in
	 * the editor as "Project Name". Sent to the tablet in `welcome` as the linked experience. Kept named
	 * `Experience` in code so nothing downstream (wire key, Unity, session.csv) has to be renamed.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VrLink", meta = (DisplayName = "Project Name"))
	FString Experience;

	// Baseline is mandatory: it is always sent as true in `welcome`, and StartExperience refuses
	// to run without a Baseline step. There is deliberately no opt-out.

	/** Participant posture, e.g. "Cycling" (Sitting/Standing/Walking/Cycling/Lying down). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VrLink")
	FString Posture;

	/**
	 * Optional pairing code for this station. When set, only a tablet whose hello carries the same
	 * code is accepted (others get a pairing-code-mismatch reject), so several stations can run in
	 * one room without cross-connecting. **Leave empty to accept any tablet**, which is what you
	 * want unless you are actually running multiple stations.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VrLink")
	FString PairingCode;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FExperienceStepStarted, const FString&, Location, const FString&, Scenario, EStepKind, StepKind, int32, StepIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FExperienceStepEnded, const FString&, Location, const FString&, Scenario, EStepKind, StepKind, int32, StepIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FExperienceFinished);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRecordingStarted, const FString&, SessionId);

/**
 * Runs the experience and speaks the vrlink v1.1 protocol to the Unity recorder.
 *
 * This is the only component you need. Put it on one actor in the level, fill in
 * the Steps table, and bind OnStepStarted / OnStepEnded to drive the visuals.
 *
 * Setup:
 *  1. Add this component to an actor in the level.
 *  2. Fill in Steps, one entry per phase the participant goes through.
 *  3. Pick an AdvanceMode: Duration, TriggerVolume, or Manual.
 *  4. Bind OnStepStarted and OnStepEnded in Blueprint.
 *
 * The Steps table is the single source of truth. The `welcome` handshake derives
 * its scene list from the distinct Locations and its variable list from the
 * distinct Scenarios, so what the tablet is told and what the events record are
 * always the same names.
 *
 * All three advance modes run the same Steps and emit the same events; only the
 * caller of GoToNextStep differs, so a run stepped through manually records
 * identically to one driven by trigger volumes.
 *
 * Transport is ATCPSocket / NetworkManager. Unity owns the event log and the
 * session clock: it receives the scene/variable/baseline events over vrlink and
 * records them. The one file this side writes is `{SessionId}_gaze.csv`, and only
 * if a UGazeRecorder is in the level; this component just publishes the session
 * state that recorder needs.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent, DisplayName = "VR Link"))
class VRLINK_API UVrLinkComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UVrLinkComponent();

	// ---------------------------------------------------------------- experience

	/** The steps, in order. Add an entry to add a location or scenario. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience", meta = (TitleProperty = "Scenario"))
	TArray<FExperienceStep> Steps;

	/** What advances the timeline to the next step. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience")
	EStepAdvanceMode AdvanceMode = EStepAdvanceMode::Duration;

	/** Key or controller button that advances the timeline. Only used when AdvanceMode is Manual. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience",
		meta = (EditCondition = "AdvanceMode == EStepAdvanceMode::Manual", EditConditionHides))
	FKey ManualAdvanceKey = EKeys::SpaceBar;

	/** What starts the experience: automatically on play, or waiting for a trigger. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience")
	EExperienceStartMode StartMode = EExperienceStartMode::OnBeginPlay;

	/**
	 * Optional, only used when Start Mode is On Trigger. Drop a Trigger Box (or any actor that fires
	 * overlap events) here and the experience starts the first time the participant enters it, with no
	 * Blueprint at all. Leave empty to start it yourself by calling Start Experience from Blueprint.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience",
		meta = (EditCondition = "StartMode == EExperienceStartMode::OnTrigger", EditConditionHides))
	AActor* StartTrigger = nullptr;

	/** Fired as a step begins, after its events are sent. Bind visuals here. */
	UPROPERTY(BlueprintAssignable, Category = "Experience")
	FExperienceStepStarted OnStepStarted;

	/** Fired as a step ends, before the fade delay. Bind fade-outs here. */
	UPROPERTY(BlueprintAssignable, Category = "Experience")
	FExperienceStepEnded OnStepEnded;

	/** Fired once after the final step ends. */
	UPROPERTY(BlueprintAssignable, Category = "Experience")
	FExperienceFinished OnExperienceFinished;

	/**
	 * Fired when the recording session starts: the tablet operator's Start Recording (its session.start),
	 * or a VR-initiated start. Bind this in Blueprint to begin environment movement or visuals the moment
	 * recording begins, independently of the Steps timeline.
	 */
	UPROPERTY(BlueprintAssignable, Category = "VrLink")
	FRecordingStarted OnRecordingStarted;

	/** Runs the experience from the first step. No-op if already running. */
	UFUNCTION(BlueprintCallable, Category = "Experience")
	void StartExperience();

	/** Stops immediately, ending the current step so a baseline is never left open. */
	UFUNCTION(BlueprintCallable, Category = "Experience")
	void StopExperience();

	/**
	 * Ends the current step and starts the next.
	 *
	 * The single entry point every advance mode goes through: the duration timer, a
	 * trigger volume, the manual key, or a Level Sequence event track.
	 */
	UFUNCTION(BlueprintCallable, Category = "Experience")
	void GoToNextStep();

	/** Index of the running step, or -1 when the experience is not running. */
	UFUNCTION(BlueprintPure, Category = "Experience")
	int32 GetCurrentStepIndex() const { return CurrentStep; }

	/** Whether a step is currently running. */
	UFUNCTION(BlueprintPure, Category = "Experience")
	bool IsRunning() const { return CurrentStep != INDEX_NONE; }

	// ------------------------------------------------------------------- vrlink

	/** The transport actor. If left null it is auto-discovered in the level on BeginPlay. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VrLink")
	ATCPSocket* Socket;

	/** The study definition handed to Unity in `welcome`. Scenes and variables come from Steps. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VrLink")
	FVrLinkStudyConfig StudyConfig;

	/**
	 * Starts a session from the VR side (spec Â§4 case B). Sends `session.start`
	 * with a null sessionId; Unity mints the id and returns it in `session.started`.
	 */
	UFUNCTION(BlueprintCallable, Category = "VrLink")
	void StartSession();

	/** Ends the current session (spec Â§4 stop). `Reason` is complete|interrupted|emergency-stop. */
	UFUNCTION(BlueprintCallable, Category = "VrLink")
	void EndSession(const FString& Reason);

	/**
	 * Sends a `state` event (scene or variable change) to Unity, which records it:
	 * a change with Name=="Scene" is a scene change, any other Name a variable change.
	 */
	UFUNCTION(BlueprintCallable, Category = "VrLink")
	void SendState(const FString& Name, const FString& Value);

	/** Sends a `baseline.start` (bStart=true) or `baseline.end` event for the given phase. */
	UFUNCTION(BlueprintCallable, Category = "VrLink")
	void SendBaseline(const FString& Phase, bool bStart);

	/** Sends a `mark` (trigger/marker) event to Unity, which records it. */
	UFUNCTION(BlueprintCallable, Category = "VrLink")
	void SendMark(const FString& Label);

	/** Sends an `error` message to surface a failure to the operator. */
	UFUNCTION(BlueprintCallable, Category = "VrLink")
	void SendError(const FString& Message);

	// ------------------------------------------------- session state (read-only)
	//
	// What the gaze recorder needs to write a file that pairs with the tablet's:
	// the agreed id, the folder the tablet chose, the shared clock, and the scene
	// each row belongs to. All of it is owned here, so there is one source of truth.

	/** The agreed session id, `{museId}-{utcMs}-{rand4}`. Empty until the tablet answers. */
	UFUNCTION(BlueprintPure, Category = "VrLink")
	FString GetSessionId() const { return SessionId; }

	/** The study-day folder name the tablet minted, e.g. "Spaklerweg_2026-07-10". Empty outside a session. */
	UFUNCTION(BlueprintPure, Category = "VrLink")
	FString GetSessionFolder() const { return SessionFolder; }

	/** Whether a recording session is running right now. */
	UFUNCTION(BlueprintPure, Category = "VrLink")
	bool IsSessionActive() const { return bSessionActive; }

	/** Seconds since session start: the clock every event and every gaze row is stamped with. */
	UFUNCTION(BlueprintPure, Category = "VrLink")
	double GetSessionElapsedSeconds() const { return SessionElapsedSeconds(); }

	/** The scene (Location) last sent to the recorder. Empty before the first scenario step. */
	UFUNCTION(BlueprintPure, Category = "VrLink")
	FString GetCurrentScene() const { return LastLocationSent; }

	/**
	 * Told by the gaze recorder when it opens its file, so `session.saved` can name
	 * the file the VR side wrote instead of reporting an empty string.
	 */
	void SetGazeFilePath(const FString& Path) { GazeFilePath = Path; }

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// --- experience ---

	/** Sends the step's events, broadcasts OnStepStarted, and arms the duration timer. */
	void EnterStep(int32 StepIndex);

	/** Duration timer handler: ends the step, then waits out the fade before advancing. */
	void EndStepThenWaitForFade();

	/** Broadcasts OnStepEnded and closes an open baseline. */
	void EndCurrentStep();

	/** Advances to the next step, or finishes if there are none left. */
	void StartNextStep();

	/** Clears both timers. Safe when neither is set. */
	void ClearTimers();

	/** The distinct Locations across Steps, in order of first appearance. */
	TArray<FString> BuildSceneList() const;

	/** The distinct Scenarios across Steps as a single "Scenario" variable. */
	TArray<FVrLinkVariable> BuildVariableList() const;

	int32 CurrentStep = INDEX_NONE;
	FString LastLocationSent;
	bool bBaselineIsOpen = false;
	FTimerHandle StepTimer;
	FTimerHandle FadeTimer;

	// --- vrlink ---

	/** Bound to StartTrigger's OnActorBeginOverlap when Start Mode is On Trigger; starts on first entry. */
	UFUNCTION()
	void OnStartTriggerOverlap(AActor* OverlappedActor, AActor* OtherActor);

	/** Bound to ATCPSocket::OnMessageReceived; parses one JSON line and dispatches on `type`. */
	UFUNCTION()
	void HandleLine(FString Line);

	void HandleHello(const TSharedPtr<FJsonObject>& Msg);
	void HandleSessionStart(const TSharedPtr<FJsonObject>& Msg);
	void HandleSessionStarted(const TSharedPtr<FJsonObject>& Msg);
	void HandleSessionEnd(const TSharedPtr<FJsonObject>& Msg);

	void SendReject(const FString& Reason, bool bStopServer = true);
	void SendJson(const TSharedRef<FJsonObject>& Obj);
	TSharedRef<FJsonObject> MakeEvent(const FString& Type, double T, const FString& WallUtc);

	void BeginSessionClock(const FString& WallUtc);
	double SessionElapsedSeconds() const;
	static FString NowIso();

	bool bHandshakeComplete = false;
	bool bSessionActive = false;
	int32 OutSeq = 0;

	FString SessionId;
	FString MuseId;
	FString ParticipantId;
	FString SessionFolder;
	FString GazeFilePath;

	double SessionStartSeconds = 0.0;
	FString SessionStartWallUtc;
};
