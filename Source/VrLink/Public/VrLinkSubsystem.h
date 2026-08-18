// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
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
 *   3. `Set Location` / `Set Scenario` from your triggers on EVERY change.
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
UCLASS(DisplayName = "VR Link")
class VRLINK_API UVrLinkSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/**
	 * Makes the link exist and listen for the tablet. Safe to call more than
	 * once. `ProjectName` is the study/project shown on the tablet (e.g.
	 * "Spaklerweg"); `Posture` is the participant's body position, an EEG-noise
	 * covariate ("Cycling" for the bike).
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

	/** The design variant now on display (e.g. "Green facade"). Call on every change. */
	UFUNCTION(BlueprintCallable, Category = "VR Link")
	void SetScenario(const FString& Name);

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
	 * Advanced, only for experiences that drive the calibration phases
	 * themselves instead of letting the tablet time them: marks the start/end
	 * of a baseline phase. Phase: baseline | relaxed | stressed.
	 */
	UFUNCTION(BlueprintCallable, Category = "VR Link|Advanced")
	void SendBaselinePhase(const FString& Phase, bool bStart);

private:
	/** The link being driven: the level's own if one exists, else the spawned one. */
	UVrLinkComponent* FindLink() const;

	/** FindLink, with one keyed on-screen warning when there is nothing to drive. */
	UVrLinkComponent* RequireLink(const TCHAR* ForCall) const;

	/** The actor this subsystem spawned to host the link (null when the level provided one). */
	TWeakObjectPtr<AActor> SpawnedHost;

	/** Collapses duplicate consecutive SetLocation calls client-side. */
	FString LastLocation;
};
