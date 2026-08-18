// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "GazeRecorder.generated.h"

class UVrLinkComponent;

/**
 * Records where the participant looks, into `{SessionId}_gaze.csv`.
 *
 * The only file the VR side writes. Everything else (EEG, events, session
 * metadata) is written by the tablet; gaze lives here because it needs the scene
 * geometry the tablet cannot see.
 *
 * Setup: add this component to an actor in the level (the VR pawn is the natural
 * home, but anywhere works, it reads the player camera). Nothing else. It finds
 * the VR Link component itself and follows the recording session:
 *
 *  - recording starts on the tablet  -> the file is opened
 *  - each frame                      -> one row (capped at Sample Rate Hz)
 *  - recording ends                  -> the file is flushed and closed
 *
 * The file goes in `Documents/MuseEEG/{sessionFolder}/`, where `sessionFolder` is
 * the study-day folder name the tablet sends in the handshake. Copy the tablet's
 * folder of the same name over this one and all four files of a session sit
 * together, sharing the `{SessionId}_` prefix the analysis tool groups by.
 *
 * What the analysis actually uses: `HitObject` (which object was looked at, and
 * for how long) and `HitX/HitY/HitZ` (the 3D heat map). `GazeX/GazeY` are a
 * viewport projection that only carries information once eye tracking lands, see
 * the note on those properties.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent, DisplayName = "Gaze Recorder"))
class VRLINK_API UGazeRecorder : public UActorComponent
{
	GENERATED_BODY()

public:
	UGazeRecorder();

	/**
	 * The VR Link component whose session this follows. Leave empty and it is found
	 * in the level on BeginPlay, which is what you want unless a level somehow has
	 * more than one.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaze")
	UVrLinkComponent* VrLink = nullptr;

	/**
	 * Rows per second. 60 matches the contract (`~60 Hz`). The real rate is capped by
	 * the frame rate, so a frame drop thins the samples rather than stretching them:
	 * every row carries its own `Time`, so analysis is unaffected. 0 = one row per
	 * rendered frame, whatever that turns out to be.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaze", meta = (ClampMin = "0.0", UIMin = "0.0", UIMax = "120.0"))
	float SampleRateHz = 60.f;

	/** How far the gaze ray reaches, in cm. Beyond this the row records a miss (empty Hit Object). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaze", meta = (ClampMin = "1.0", UIMin = "100.0"))
	float MaxTraceDistance = 20000.f;

	/** Collision channel the gaze ray tests against. Visibility is right for scenery. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaze")
	TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;

	/**
	 * Prefer an actor's first Tag over its object name for `HitObject`.
	 *
	 * This is the difference between an analysis column full of `StaticMeshActor_12`
	 * and one full of `Green facade`. Tag the things you actually want measured
	 * ("Trees", "Bike lane", "Facade"); untagged actors still record under their
	 * object name.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaze")
	bool bUseActorTagAsHitObject = true;

	/**
	 * Where the study-day folders live. Empty = `Documents/MuseEEG`, which mirrors the
	 * tablet, so the two machines' files merge by copying one folder onto the other.
	 * Set it only to write somewhere else on this PC.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaze")
	FString OutputRootOverride;

	/**
	 * How often buffered rows are appended to disk. A crash loses at most this much
	 * gaze; the rest of the file is still valid CSV.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gaze", meta = (ClampMin = "0.1", UIMin = "0.1"))
	float FlushIntervalSeconds = 1.f;

	/** Full path of the file being written, or the last one written. Empty before the first session. */
	UFUNCTION(BlueprintPure, Category = "Gaze")
	FString GetGazeFilePath() const { return GazeFilePath; }

	/** Whether rows are being recorded right now. */
	UFUNCTION(BlueprintPure, Category = "Gaze")
	bool IsRecording() const { return bRecording; }

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	/** Opens the file for the session VrLink is running, writes the header. */
	void OpenFile();

	/** Appends what is buffered and stops recording. Safe to call when not recording. */
	void CloseFile();

	/** Traces the head ray and appends one row to the buffer. */
	void CaptureSample();

	/** Appends the buffer to disk and empties it. No-op when the buffer is empty. */
	void Flush();

	/** `Documents/MuseEEG/{sessionFolder}` (or the override), with the folder created. */
	FString ResolveSessionDirectory() const;

	/** Tag if there is one and tags are preferred, otherwise the object name. */
	FString ResolveHitObjectName(const AActor* HitActor) const;

	bool bRecording = false;
	FString GazeFilePath;
	FString RecordingSessionId;

	/** Session whose file could not be opened, so the failure is reported once, not every frame. */
	FString FailedSessionId;

	FString RowBuffer;
	int32 RowCount = 0;
	float TimeSinceLastSample = 0.f;
	float TimeSinceLastFlush = 0.f;
};
