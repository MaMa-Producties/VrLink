// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Containers/Ticker.h"
// For FVrLinkCarriedSession, which is held by value below. One-directional: the
// component header knows nothing about this one.
#include "VrLinkComponent.h"
#include "VrLinkSubsystem.generated.h"

class UVrLinkComponent;

/**
 * The one-stop Blueprint interface to the Neural Recorder tablet.
 *
 * A GameInstance subsystem: it exists for the whole game's lifetime, needs no
 * setup, and every node is reachable from any Blueprint via
 * `Get VrLinkSubsystem`. There is no connection object to store: the subsystem
 * IS the connection.
 *
 * Minimal integration, four calls:
 *
 *   1. `Initialize Vr Link` once (e.g. GameInstance Init or level BeginPlay).
 *      Spawns the network link if the level does not already contain one.
 *   2. `Start Session` when the ride starts. The tablet runs the participant's
 *      baseline automatically at session start; give it ~30 s of calm before
 *      the first stimulus.
 *   3. `Set Location` / `Start Scenario` from your triggers on EVERY change.
 *      These labels are what the analysis segments by; without them a
 *      recording cannot be attributed to a design.
 *   4. `End Session` when the ride ends.
 *
 * One session per participant, not one per point of interest: the recording
 * runs continuously and your location changes segment it. Gaze recording
 * follows the session automatically.
 *
 * A level that already contains a VR Link component (the Steps-table workflow)
 * is left untouched: the subsystem finds and drives that one instead of
 * spawning its own.
 */
/**
 * The calibration poles, as a closed set.
 *
 * A free string here was a real hazard: the recorder keys its calibration window
 * on the exact phase name, so a spelling it does not know ("calm", "negative")
 * lands outside its predicate and the window closes early -- producing a baseline
 * range that is quietly half of what it claims, with no error and no gap in the
 * file. An enum makes that unspellable from Blueprint.
 */
UENUM(BlueprintType)
enum class EVrLinkCalibrationPhase : uint8
{
	/** One undivided calibration stretch, when the experience does not split it. */
	Baseline UMETA(DisplayName = "Baseline"),

	/** The lower pole: the participant at rest. */
	Relaxed UMETA(DisplayName = "Relaxed (lower pole)"),

	/** The upper pole: the participant deliberately unsettled. */
	Stressed UMETA(DisplayName = "Stressed (upper pole)")
};

UCLASS(DisplayName = "VR Link")
class VRLINK_API UVrLinkSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/**
	 * Makes the link exist and listen for the tablet. Safe to call more than
	 * once. `ProjectName` is the study/project shown on the tablet (e.g.
	 * "Spaklerweg"); `Posture` is the participant's body position, an EEG-noise
	 * covariate ("Cycling" for the bike).
	 *
	 * Call it once, from the Game Instance. It is remembered, and the link is
	 * rebuilt by itself in every level the participant is taken to -- the
	 * subsystem outlives a level change but the actors in a level do not, so
	 * without that the first Open Level would silently leave nothing to talk
	 * to. The session keeps running across the change; only the actors are new.
	 */
	UFUNCTION(BlueprintCallable, Category = "VR Link")
	void InitializeVrLink(const FString& ProjectName, const FString& Posture = TEXT("Cycling"));

	/** Starts the recording session (the tablet mints the ids and confirms). */
	UFUNCTION(BlueprintCallable, Category = "VR Link")
	void StartSession();

	/** Ends the session. Reason: complete | interrupted | emergency-stop. */
	UFUNCTION(BlueprintCallable, Category = "VR Link")
	void EndSession(const FString& Reason = TEXT("complete"));

	/**
	 * The participant arrived at a location (e.g. "Spaklerweg"). Call on every
	 * location change; consecutive duplicate names are collapsed to one event.
	 */
	UFUNCTION(BlueprintCallable, Category = "VR Link")
	void SetLocation(const FString& Name);

	/**
	 * The design variant now on display (e.g. "Green facade"). Call on every change.
	 *
	 * Calling it again with another name starts that one, which is what ends this one:
	 * only one design is on display at a time. EndScenario is for the other case, a
	 * design stopping with nothing to replace it.
	 *
	 * Shown in Blueprint as Start Scenario, to pair with End Scenario. The C++ name is
	 * deliberately left alone: nodes bind to that, and renaming it would turn every
	 * existing call into a red error node in a graph nobody here can open.
	 */
	UFUNCTION(BlueprintCallable, Category = "VR Link", meta = (DisplayName = "Start Scenario"))
	void SetScenario(const FString& Name);

	/**
	 * Ends the scenario now showing. Call it every time a design stops being shown,
	 * whether another follows it or the ride is over.
	 *
	 * Everything from here until the next Start Scenario or Set Location is thrown
	 * away by analysis. That stretch is the participant between designs: a transition,
	 * a corridor, a fade to black. It has no point of interest in it, and counted as
	 * data it would be credited to the design that just ended.
	 */
	UFUNCTION(BlueprintCallable, Category = "VR Link", meta = (DisplayName = "End Scenario"))
	void EndScenario();

	/** Flags a moment of interest on the recording timeline. */
	UFUNCTION(BlueprintCallable, Category = "VR Link")
	void SendMark(const FString& Label);

	/** Whether a recording session is running right now. */
	UFUNCTION(BlueprintPure, Category = "VR Link")
	bool IsSessionActive() const;

	/** The agreed session id, empty outside a session. */
	UFUNCTION(BlueprintPure, Category = "VR Link")
	FString GetSessionId() const;

	/**
	 * For experiences that drive the calibration themselves instead of letting the
	 * tablet time it: marks the start and end of a calibration phase.
	 *
	 * Call it around each pole. A calibration that is a relaxed half followed by a
	 * stressed half needs all four calls, and the recorder keeps them as one window
	 * because both are calibration; without the second pole the range has no upper
	 * end and every value measured against it is wrong in the same direction.
	 */
	UFUNCTION(BlueprintCallable, Category = "VR Link|Calibration", meta = (DisplayName = "Start Baseline"))
	void StartBaseline(EVrLinkCalibrationPhase Phase);

	/**
	 * Closes the calibration phase opened by Start Baseline. Pass the SAME phase.
	 *
	 * A phase left open runs to the end of the session, so the calibration swallows the
	 * ride and there is nothing left to compare it against.
	 */
	UFUNCTION(BlueprintCallable, Category = "VR Link|Calibration", meta = (DisplayName = "End Baseline"))
	void EndBaseline(EVrLinkCalibrationPhase Phase);

	/** What both of the above call. Not exposed: a caller that can pass the wrong
	  * boolean can open a phase twice and never close it. */
	void SendBaselinePhase(EVrLinkCalibrationPhase Phase, bool bStart);

private:
	/** The link being driven: the level's own if one exists, else the spawned one. */
	UVrLinkComponent* FindLink() const;

	/**
	 * The link to drive, built now if the level has not got one yet.
	 *
	 * Not const, and not merely FindLink with a warning attached, because the
	 * delegate that builds the link fires at a moment the subsystem does not
	 * control: how early a world is initialised relative to the game instance
	 * differs between PIE, a packaged run and a level change, and when it lands
	 * on the wrong side every single call warns that Initialize was never called
	 * when it was. Building on demand removes the ordering from the question.
	 *
	 * Warns only when it still cannot produce one, which now means something.
	 */
	UVrLinkComponent* RequireLink(const TCHAR* ForCall);

	/**
	 * Builds the transport, link and gaze actors in `World`.
	 *
	 * Called once per level: the new-world delegate is bound in Initialize as a
	 * lambda rather than a member function, because its signature names a type
	 * nested inside UWorld and this header only forward-declares UWorld.
	 */
	void BuildLink(UWorld* World);

	/** The actor this subsystem spawned to host the link (null when the level provided one). */
	TWeakObjectPtr<AActor> SpawnedHost;

	/**
	 * What Initialize was called with, kept so a new level can be given the same link.
	 * Empty until the first call, which is how `bConfigured` stays honest about whether
	 * anyone has asked for a link at all.
	 */
	FString ConfiguredProject;
	FString ConfiguredPosture;
	bool bConfigured = false;

	/** Handles for the world delegates, released on Deinitialize. */
	FDelegateHandle WorldReadyHandle;
	FDelegateHandle WorldTearDownHandle;

	/**
	 * Builds the link the moment a playable world exists, then stops.
	 *
	 * The world delegate above fires at a moment that differs between PIE, a
	 * packaged run and a level change, and when it is missed nothing is built.
	 * That is not merely a warning: the socket SERVER lives on the spawned
	 * ATCPSocket and starts in its BeginPlay, so an unbuilt link means no port
	 * is ever opened and the tablet cannot connect however long it waits.
	 * Nothing on the VR side has to be called for that to happen, so there is
	 * no call to build it lazily from either.
	 */
	FTSTicker::FDelegateHandle BuildTickHandle;

	/** One line on screen saying whether the link is up and the tablet is on it. */
	void ReportStatus();
	FTSTicker::FDelegateHandle StatusTickHandle;

	/**
	 * A session in flight, held between one level being torn down and the next being
	 * built. The tablet keeps recording throughout; only our end of it is rebuilt.
	 */
	FVrLinkCarriedSession CarriedSession;

	/** Collapses duplicate consecutive SetLocation calls client-side. */
	FString LastLocation;
};
