// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GazeRecorder.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeGazeRecorder() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent(ETypeConstructPhase);
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_UGazeRecorder(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_UGazeRecorder(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_UVrLinkComponent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UGazeRecorder Function GetGazeFilePath ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UGazeRecorder_GetGazeFilePath_Statics
struct UHT_STATICS
{
	struct GazeRecorder_eventGetGazeFilePath_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Gaze" },
		{ "Comment", "/** Full path of the file being written, or the last one written. Empty before the first session. */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Full path of the file being written, or the last one written. Empty before the first session." },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGazeFilePath constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGazeFilePath constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGazeFilePath Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(GazeRecorder_eventGetGazeFilePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetGazeFilePath Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UGazeRecorder, nullptr, "GetGazeFilePath", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::GazeRecorder_eventGetGazeFilePath_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::GazeRecorder_eventGetGazeFilePath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGazeRecorder_GetGazeFilePath(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UGazeRecorder::execGetGazeFilePath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetGazeFilePath();
	P_NATIVE_END;
}
// ********** End Class UGazeRecorder Function GetGazeFilePath *************************************

// ********** Begin Class UGazeRecorder Function IsRecording ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UGazeRecorder_IsRecording_Statics
struct UHT_STATICS
{
	struct GazeRecorder_eventIsRecording_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Gaze" },
		{ "Comment", "/** Whether rows are being recorded right now. */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Whether rows are being recorded right now." },
	};
#endif // WITH_METADATA

// ********** Begin Function IsRecording constinit property declarations ***************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GazeRecorder_eventIsRecording_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsRecording constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsRecording Property Definitions **************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(GazeRecorder_eventIsRecording_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsRecording Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UGazeRecorder, nullptr, "IsRecording", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::GazeRecorder_eventIsRecording_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::GazeRecorder_eventIsRecording_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGazeRecorder_IsRecording(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UGazeRecorder::execIsRecording)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsRecording();
	P_NATIVE_END;
}
// ********** End Class UGazeRecorder Function IsRecording *****************************************

// ********** Begin Class UGazeRecorder Function IsUsingEyeTracking ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UGazeRecorder_IsUsingEyeTracking_Statics
struct UHT_STATICS
{
	struct GazeRecorder_eventIsUsingEyeTracking_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Gaze" },
		{ "Comment", "/** Whether eye gaze is being used right now, as opposed to falling back to the head ray. */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Whether eye gaze is being used right now, as opposed to falling back to the head ray." },
	};
#endif // WITH_METADATA

// ********** Begin Function IsUsingEyeTracking constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GazeRecorder_eventIsUsingEyeTracking_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsUsingEyeTracking constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsUsingEyeTracking Property Definitions *******************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(GazeRecorder_eventIsUsingEyeTracking_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsUsingEyeTracking Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UGazeRecorder, nullptr, "IsUsingEyeTracking", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::GazeRecorder_eventIsUsingEyeTracking_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::GazeRecorder_eventIsUsingEyeTracking_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGazeRecorder_IsUsingEyeTracking(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UGazeRecorder::execIsUsingEyeTracking)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsUsingEyeTracking();
	P_NATIVE_END;
}
// ********** End Class UGazeRecorder Function IsUsingEyeTracking **********************************

// ********** Begin Class UGazeRecorder ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UGazeRecorder_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "Comment", "/**\n * Records where the participant looks, into `{SessionId}_gaze.csv`.\n *\n * The only file the VR side writes. Everything else (EEG, events, session\n * metadata) is written by the tablet; gaze lives here because it needs the scene\n * geometry the tablet cannot see.\n *\n * Setup: add this component to an actor in the level (the VR pawn is the natural\n * home, but anywhere works, it reads the player camera). Nothing else. It finds\n * the VR Link component itself and follows the recording session:\n *\n *  - recording starts on the tablet  -> the file is opened\n *  - each frame                      -> one row (capped at Sample Rate Hz)\n *  - recording ends                  -> the file is flushed and closed\n *\n * The file goes in `Documents/MuseEEG/{sessionFolder}/`, where `sessionFolder` is\n * the study-day folder name the tablet sends in the handshake. Copy the tablet's\n * folder of the same name over this one and all four files of a session sit\n * together, sharing the `{SessionId}_` prefix the analysis tool groups by.\n *\n * What the analysis actually uses: `HitObject` (which object was looked at, and\n * for how long) and `HitX/HitY/HitZ` (the 3D heat map). `GazeX/GazeY` are a\n * viewport projection that only carries information once eye tracking lands, see\n * the note on those properties.\n */" },
		{ "DisplayName", "Gaze Recorder" },
		{ "IncludePath", "GazeRecorder.h" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Records where the participant looks, into `{SessionId}_gaze.csv`.\n\nThe only file the VR side writes. Everything else (EEG, events, session\nmetadata) is written by the tablet; gaze lives here because it needs the scene\ngeometry the tablet cannot see.\n\nSetup: add this component to an actor in the level (the VR pawn is the natural\nhome, but anywhere works, it reads the player camera). Nothing else. It finds\nthe VR Link component itself and follows the recording session:\n\n - recording starts on the tablet  -> the file is opened\n - each frame                      -> one row (capped at Sample Rate Hz)\n - recording ends                  -> the file is flushed and closed\n\nThe file goes in `Documents/MuseEEG/{sessionFolder}/`, where `sessionFolder` is\nthe study-day folder name the tablet sends in the handshake. Copy the tablet's\nfolder of the same name over this one and all four files of a session sit\ntogether, sharing the `{SessionId}_` prefix the analysis tool groups by.\n\nWhat the analysis actually uses: `HitObject` (which object was looked at, and\nfor how long) and `HitX/HitY/HitZ` (the 3D heat map). `GazeX/GazeY` are a\nviewport projection that only carries information once eye tracking lands, see\nthe note on those properties." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VrLink_MetaData[] = {
		{ "Category", "Gaze" },
		{ "Comment", "/**\n\x09 * The VR Link component whose session this follows. Leave empty and it is found\n\x09 * in the level on BeginPlay, which is what you want unless a level somehow has\n\x09 * more than one.\n\x09 */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "The VR Link component whose session this follows. Leave empty and it is found\nin the level on BeginPlay, which is what you want unless a level somehow has\nmore than one." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SampleRateHz_MetaData[] = {
		{ "Category", "Gaze" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/**\n\x09 * Rows per second. 60 matches the contract (`~60 Hz`). The real rate is capped by\n\x09 * the frame rate, so a frame drop thins the samples rather than stretching them:\n\x09 * every row carries its own `Time`, so analysis is unaffected. 0 = one row per\n\x09 * rendered frame, whatever that turns out to be.\n\x09 */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Rows per second. 60 matches the contract (`~60 Hz`). The real rate is capped by\nthe frame rate, so a frame drop thins the samples rather than stretching them:\nevery row carries its own `Time`, so analysis is unaffected. 0 = one row per\nrendered frame, whatever that turns out to be." },
		{ "UIMax", "120.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxTraceDistance_MetaData[] = {
		{ "Category", "Gaze" },
		{ "ClampMin", "1.0" },
		{ "Comment", "/** How far the gaze ray reaches, in cm. Beyond this the row records a miss (empty Hit Object). */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "How far the gaze ray reaches, in cm. Beyond this the row records a miss (empty Hit Object)." },
		{ "UIMin", "100.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TraceChannel_MetaData[] = {
		{ "Category", "Gaze" },
		{ "Comment", "/** Collision channel the gaze ray tests against. Visibility is right for scenery. */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Collision channel the gaze ray tests against. Visibility is right for scenery." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPreferEyeTracking_MetaData[] = {
		{ "Category", "Gaze" },
		{ "Comment", "/**\n\x09 * Use the eye tracker's gaze ray when the headset has one, and the head ray when it does not.\n\x09 *\n\x09 * Safe to leave on before any eye-tracking hardware arrives: with no tracker connected this\n\x09 * changes nothing at all, and every row still records `head`. The moment a headset that\n\x09 * supports it is plugged in, rows start recording `eye` instead, with no rebuild and no\n\x09 * change to the file format.\n\x09 *\n\x09 * Why it matters to the analysis: a head ray is not where somebody is looking. People turn\n\x09 * their eyes first and their head only partway, so the head ray marks a region of attention\n\x09 * roughly seven degrees wide, which across a street is more than a metre. Eye gaze is nearer\n\x09 * one degree. The heat map widens or tightens to match, per row, from the `Source` column --\n\x09 * so a recording that switches mid-session is still read correctly.\n\x09 *\n\x09 * Turn it off to force head gaze, for instance to keep one test day consistent with an\n\x09 * earlier one recorded before the hardware arrived.\n\x09 */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Use the eye tracker's gaze ray when the headset has one, and the head ray when it does not.\n\nSafe to leave on before any eye-tracking hardware arrives: with no tracker connected this\nchanges nothing at all, and every row still records `head`. The moment a headset that\nsupports it is plugged in, rows start recording `eye` instead, with no rebuild and no\nchange to the file format.\n\nWhy it matters to the analysis: a head ray is not where somebody is looking. People turn\ntheir eyes first and their head only partway, so the head ray marks a region of attention\nroughly seven degrees wide, which across a street is more than a metre. Eye gaze is nearer\none degree. The heat map widens or tightens to match, per row, from the `Source` column --\nso a recording that switches mid-session is still read correctly.\n\nTurn it off to force head gaze, for instance to keep one test day consistent with an\nearlier one recorded before the hardware arrived." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinEyeConfidence_MetaData[] = {
		{ "Category", "Gaze" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/**\n\x09 * Below this confidence the eye tracker's answer is not used and the row falls back to the\n\x09 * head ray, recording `head`.\n\x09 *\n\x09 * Confidence collapses during a blink and while the tracker is losing the eye behind\n\x09 * spectacles. Those rows are not dropped -- a blink is not a look away, and losing them\n\x09 * would leave holes in the dwell -- they simply revert to the less precise ray, which is\n\x09 * still true about where the participant was facing.\n\x09 */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Below this confidence the eye tracker's answer is not used and the row falls back to the\nhead ray, recording `head`.\n\nConfidence collapses during a blink and while the tracker is losing the eye behind\nspectacles. Those rows are not dropped -- a blink is not a look away, and losing them\nwould leave holes in the dwell -- they simply revert to the less precise ray, which is\nstill true about where the participant was facing." },
		{ "UIMax", "1.0" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseActorTagAsHitObject_MetaData[] = {
		{ "Category", "Gaze" },
		{ "Comment", "/**\n\x09 * Prefer an actor's first Tag over its object name for `HitObject`.\n\x09 *\n\x09 * This is the difference between an analysis column full of `StaticMeshActor_12`\n\x09 * and one full of `Green facade`. Tag the things you actually want measured\n\x09 * (\"Trees\", \"Bike lane\", \"Facade\"); untagged actors still record under their\n\x09 * object name.\n\x09 */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Prefer an actor's first Tag over its object name for `HitObject`.\n\nThis is the difference between an analysis column full of `StaticMeshActor_12`\nand one full of `Green facade`. Tag the things you actually want measured\n(\"Trees\", \"Bike lane\", \"Facade\"); untagged actors still record under their\nobject name." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutputRootOverride_MetaData[] = {
		{ "Category", "Gaze" },
		{ "Comment", "/**\n\x09 * Where the study-day folders live. Empty = `Documents/MuseEEG`, which mirrors the\n\x09 * tablet, so the two machines' files merge by copying one folder onto the other.\n\x09 * Set it only to write somewhere else on this PC.\n\x09 */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "Where the study-day folders live. Empty = `Documents/MuseEEG`, which mirrors the\ntablet, so the two machines' files merge by copying one folder onto the other.\nSet it only to write somewhere else on this PC." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlushIntervalSeconds_MetaData[] = {
		{ "Category", "Gaze" },
		{ "ClampMin", "0.1" },
		{ "Comment", "/**\n\x09 * How often buffered rows are appended to disk. A crash loses at most this much\n\x09 * gaze; the rest of the file is still valid CSV.\n\x09 */" },
		{ "ModuleRelativePath", "Public/GazeRecorder.h" },
		{ "ToolTip", "How often buffered rows are appended to disk. A crash loses at most this much\ngaze; the rest of the file is still valid CSV." },
		{ "UIMin", "0.1" },
	};
#endif // WITH_METADATA

// ********** Begin Class UGazeRecorder constinit property declarations ****************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VrLink;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SampleRateHz;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxTraceDistance;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static void NewProp_bPreferEyeTracking_SetBit(void* Obj)
	{
		((UGazeRecorder*)Obj)->bPreferEyeTracking = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreferEyeTracking;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinEyeConfidence;
	static void NewProp_bUseActorTagAsHitObject_SetBit(void* Obj)
	{
		((UGazeRecorder*)Obj)->bUseActorTagAsHitObject = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseActorTagAsHitObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutputRootOverride;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FlushIntervalSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGazeRecorder constinit property declarations ******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetGazeFilePath"), .Pointer = &UGazeRecorder::execGetGazeFilePath },
		{ .NameUTF8 = UTF8TEXT("IsRecording"), .Pointer = &UGazeRecorder::execIsRecording },
		{ .NameUTF8 = UTF8TEXT("IsUsingEyeTracking"), .Pointer = &UGazeRecorder::execIsUsingEyeTracking },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGazeRecorder_GetGazeFilePath, "GetGazeFilePath" }, // 8825628b80f5cc0ad8906712e1b024bd0079f870
		{ &Z_Construct_UFunction_UGazeRecorder_IsRecording, "IsRecording" }, // 83d402e4d771a5647be5aa93051fd3671677f0a0
		{ &Z_Construct_UFunction_UGazeRecorder_IsUsingEyeTracking, "IsUsingEyeTracking" }, // 3a58315bc89c56640c52023ca2cacad4f6ff2bfd
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGazeRecorder>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UGazeRecorder Property Definitions ***************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_VrLink = { "VrLink", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(UGazeRecorder, VrLink), Z_Construct_UClass_UVrLinkComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VrLink_MetaData), NewProp_VrLink_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SampleRateHz = { "SampleRateHz", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UGazeRecorder, SampleRateHz), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SampleRateHz_MetaData), NewProp_SampleRateHz_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaxTraceDistance = { "MaxTraceDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UGazeRecorder, MaxTraceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxTraceDistance_MetaData), NewProp_MaxTraceDistance_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, STRUCT_OFFSET(UGazeRecorder, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TraceChannel_MetaData), NewProp_TraceChannel_MetaData) }; // 3aff698625c18cc2ccaa87a587b2eac8c50cdec7
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPreferEyeTracking = { "bPreferEyeTracking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UGazeRecorder), &UHT_STATICS::NewProp_bPreferEyeTracking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPreferEyeTracking_MetaData), NewProp_bPreferEyeTracking_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinEyeConfidence = { "MinEyeConfidence", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UGazeRecorder, MinEyeConfidence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinEyeConfidence_MetaData), NewProp_MinEyeConfidence_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bUseActorTagAsHitObject = { "bUseActorTagAsHitObject", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(UGazeRecorder), &UHT_STATICS::NewProp_bUseActorTagAsHitObject_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseActorTagAsHitObject_MetaData), NewProp_bUseActorTagAsHitObject_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_OutputRootOverride = { "OutputRootOverride", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UGazeRecorder, OutputRootOverride), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutputRootOverride_MetaData), NewProp_OutputRootOverride_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FlushIntervalSeconds = { "FlushIntervalSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UGazeRecorder, FlushIntervalSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlushIntervalSeconds_MetaData), NewProp_FlushIntervalSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_VrLink,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SampleRateHz,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxTraceDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPreferEyeTracking,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinEyeConfidence,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bUseActorTagAsHitObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OutputRootOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FlushIntervalSeconds,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UGazeRecorder Property Definitions *****************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UActorComponent,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UGazeRecorder,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UGazeRecorder_StaticRegisterNativesUGazeRecorder()
{
	UClass* Class = UGazeRecorder::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UGazeRecorder;
UClass* Z_Construct_UClass_UGazeRecorder(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UGazeRecorder;
		if (!Z_Registration_Info_UClass_UGazeRecorder.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("GazeRecorder"),
				Z_Registration_Info_UClass_UGazeRecorder.InnerSingleton,
				UGazeRecorder_StaticRegisterNativesUGazeRecorder,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UGazeRecorder.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UGazeRecorder.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGazeRecorder.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UGazeRecorder.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGazeRecorder);
UGazeRecorder::~UGazeRecorder() {}
// ********** End Class UGazeRecorder **************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_vb58_HostProject_Plugins_VrLink_Source_VrLink_Public_GazeRecorder_h__Script_VrLink_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGazeRecorder, TEXT("UGazeRecorder"), &Z_Registration_Info_UClass_UGazeRecorder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGazeRecorder), 1123429576U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_vb58_HostProject_Plugins_VrLink_Source_VrLink_Public_GazeRecorder_h__Script_VrLink_3fdfd2f5e4eb069e65d707eb5764684f0b1a210e{
	TEXT("/Script/VrLink"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
