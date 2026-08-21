// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VrLinkSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeVrLinkSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_UVrLinkSubsystem(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_UVrLinkSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UVrLinkSubsystem Function EndSession *************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_EndSession_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventEndSession_Parms
	{
		FString Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/** Ends the session. Reason: complete | interrupted | emergency-stop. */" },
		{ "CPP_Default_Reason", "complete" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "Ends the session. Reason: complete | interrupted | emergency-stop." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Reason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function EndSession constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EndSession constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EndSession Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventEndSession_Parms, Reason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Reason_MetaData), NewProp_Reason_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function EndSession Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "EndSession", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventEndSession_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventEndSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_EndSession(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execEndSession)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Reason);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndSession(Z_Param_Reason);
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function EndSession ***************************************

// ********** Begin Class UVrLinkSubsystem Function GetSessionId ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_GetSessionId_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventGetSessionId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/** The agreed session id, empty outside a session. */" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "The agreed session id, empty outside a session." },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSessionId constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSessionId constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSessionId Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventGetSessionId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSessionId Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "GetSessionId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventGetSessionId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventGetSessionId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_GetSessionId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execGetSessionId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetSessionId();
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function GetSessionId *************************************

// ********** Begin Class UVrLinkSubsystem Function InitializeVrLink *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_InitializeVrLink_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventInitializeVrLink_Parms
	{
		FString ProjectName;
		FString Posture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/**\n\x09 * Makes the link exist and listen for the tablet. Safe to call more than\n\x09 * once. `ProjectName` is the study/project shown on the tablet (e.g.\n\x09 * \"Spaklerweg\"); `Posture` is the participant's body position, an EEG-noise\n\x09 * covariate (\"Cycling\" for the bike).\n\x09 */" },
		{ "CPP_Default_Posture", "Cycling" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "Makes the link exist and listen for the tablet. Safe to call more than\nonce. `ProjectName` is the study/project shown on the tablet (e.g.\n\"Spaklerweg\"); `Posture` is the participant's body position, an EEG-noise\ncovariate (\"Cycling\" for the bike)." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Posture_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function InitializeVrLink constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProjectName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Posture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InitializeVrLink constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InitializeVrLink Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ProjectName = { "ProjectName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventInitializeVrLink_Parms, ProjectName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectName_MetaData), NewProp_ProjectName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Posture = { "Posture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventInitializeVrLink_Parms, Posture), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Posture_MetaData), NewProp_Posture_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProjectName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Posture,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InitializeVrLink Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "InitializeVrLink", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventInitializeVrLink_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventInitializeVrLink_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_InitializeVrLink(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execInitializeVrLink)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ProjectName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Posture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeVrLink(Z_Param_ProjectName,Z_Param_Posture);
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function InitializeVrLink *********************************

// ********** Begin Class UVrLinkSubsystem Function IsSessionActive ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_IsSessionActive_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventIsSessionActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/** Whether a recording session is running right now. */" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "Whether a recording session is running right now." },
	};
#endif // WITH_METADATA

// ********** Begin Function IsSessionActive constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VrLinkSubsystem_eventIsSessionActive_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSessionActive constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSessionActive Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(VrLinkSubsystem_eventIsSessionActive_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsSessionActive Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "IsSessionActive", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventIsSessionActive_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventIsSessionActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_IsSessionActive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execIsSessionActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSessionActive();
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function IsSessionActive **********************************

// ********** Begin Class UVrLinkSubsystem Function SendBaselinePhase ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_SendBaselinePhase_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventSendBaselinePhase_Parms
	{
		FString Phase;
		bool bStart;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link|Advanced" },
		{ "Comment", "/**\n\x09 * Advanced, only for experiences that drive the calibration phases\n\x09 * themselves instead of letting the tablet time them: marks the start/end\n\x09 * of a baseline phase. Phase: baseline | relaxed | stressed.\n\x09 */" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "Advanced, only for experiences that drive the calibration phases\nthemselves instead of letting the tablet time them: marks the start/end\nof a baseline phase. Phase: baseline | relaxed | stressed." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Phase_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SendBaselinePhase constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Phase;
	static void NewProp_bStart_SetBit(void* Obj)
	{
		((VrLinkSubsystem_eventSendBaselinePhase_Parms*)Obj)->bStart = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStart;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SendBaselinePhase constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SendBaselinePhase Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Phase = { "Phase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventSendBaselinePhase_Parms, Phase), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Phase_MetaData), NewProp_Phase_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bStart = { "bStart", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(VrLinkSubsystem_eventSendBaselinePhase_Parms), &UHT_STATICS::NewProp_bStart_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Phase,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bStart,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SendBaselinePhase Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "SendBaselinePhase", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventSendBaselinePhase_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventSendBaselinePhase_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_SendBaselinePhase(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execSendBaselinePhase)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Phase);
	P_GET_UBOOL(Z_Param_bStart);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendBaselinePhase(Z_Param_Phase,Z_Param_bStart);
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function SendBaselinePhase ********************************

// ********** Begin Class UVrLinkSubsystem Function SendMark ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_SendMark_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventSendMark_Parms
	{
		FString Label;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/** Flags a moment of interest on the recording timeline. */" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "Flags a moment of interest on the recording timeline." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SendMark constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SendMark constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SendMark Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventSendMark_Parms, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Label,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SendMark Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "SendMark", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventSendMark_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventSendMark_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_SendMark(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execSendMark)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Label);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendMark(Z_Param_Label);
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function SendMark *****************************************

// ********** Begin Class UVrLinkSubsystem Function SetLocation ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_SetLocation_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventSetLocation_Parms
	{
		FString Name;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/**\n\x09 * The participant arrived at a location (e.g. \"Spaklerweg\"). Call on every\n\x09 * location change; consecutive duplicate names are collapsed to one event.\n\x09 */" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "The participant arrived at a location (e.g. \"Spaklerweg\"). Call on every\nlocation change; consecutive duplicate names are collapsed to one event." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetLocation constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLocation constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLocation Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventSetLocation_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetLocation Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "SetLocation", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventSetLocation_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventSetLocation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_SetLocation(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execSetLocation)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLocation(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function SetLocation **************************************

// ********** Begin Class UVrLinkSubsystem Function SetScenario ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_SetScenario_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventSetScenario_Parms
	{
		FString Name;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/** The design variant now on display (e.g. \"Green facade\"). Call on every change. */" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "The design variant now on display (e.g. \"Green facade\"). Call on every change." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetScenario constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetScenario constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetScenario Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventSetScenario_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetScenario Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "SetScenario", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventSetScenario_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventSetScenario_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_SetScenario(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execSetScenario)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetScenario(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function SetScenario **************************************

// ********** Begin Class UVrLinkSubsystem Function StartSession ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_StartSession_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/** Starts the recording session (the tablet mints the ids and confirms). */" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "Starts the recording session (the tablet mints the ids and confirms)." },
	};
#endif // WITH_METADATA

// ********** Begin Function StartSession constinit property declarations **************************
// ********** End Function StartSession constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "StartSession", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_StartSession(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execStartSession)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartSession();
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function StartSession *************************************

// ********** Begin Class UVrLinkSubsystem *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UVrLinkSubsystem_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/**\n * The one-stop Blueprint interface to the Neural Recorder tablet.\n *\n * A GameInstance subsystem: it exists for the whole game's lifetime, needs no\n * setup, and every node is reachable from any Blueprint via\n * `Get VrLinkSubsystem`. There is no connection object to store: the subsystem\n * IS the connection.\n *\n * Minimal integration, four calls:\n *\n *   1. `Initialize Vr Link` once (e.g. GameInstance Init or level BeginPlay).\n *      Spawns the network link if the level does not already contain one.\n *   2. `Start Session` when the ride starts. The tablet runs the participant's\n *      baseline automatically at session start; give it ~30 s of calm before\n *      the first stimulus.\n *   3. `Set Location` / `Set Scenario` from your triggers on EVERY change.\n *      These labels are what the analysis segments by; without them a\n *      recording cannot be attributed to a design.\n *   4. `End Session` when the ride ends.\n *\n * One session per participant, not one per point of interest: the recording\n * runs continuously and your location changes segment it. Gaze recording\n * follows the session automatically.\n *\n * A level that already contains a VR Link component (the Steps-table workflow)\n * is left untouched: the subsystem finds and drives that one instead of\n * spawning its own.\n */" },
		{ "DisplayName", "VR Link" },
		{ "IncludePath", "VrLinkSubsystem.h" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "The one-stop Blueprint interface to the Neural Recorder tablet.\n\nA GameInstance subsystem: it exists for the whole game's lifetime, needs no\nsetup, and every node is reachable from any Blueprint via\n`Get VrLinkSubsystem`. There is no connection object to store: the subsystem\nIS the connection.\n\nMinimal integration, four calls:\n\n  1. `Initialize Vr Link` once (e.g. GameInstance Init or level BeginPlay).\n     Spawns the network link if the level does not already contain one.\n  2. `Start Session` when the ride starts. The tablet runs the participant's\n     baseline automatically at session start; give it ~30 s of calm before\n     the first stimulus.\n  3. `Set Location` / `Set Scenario` from your triggers on EVERY change.\n     These labels are what the analysis segments by; without them a\n     recording cannot be attributed to a design.\n  4. `End Session` when the ride ends.\n\nOne session per participant, not one per point of interest: the recording\nruns continuously and your location changes segment it. Gaze recording\nfollows the session automatically.\n\nA level that already contains a VR Link component (the Steps-table workflow)\nis left untouched: the subsystem finds and drives that one instead of\nspawning its own." },
	};
#endif // WITH_METADATA

// ********** Begin Class UVrLinkSubsystem constinit property declarations *************************
// ********** End Class UVrLinkSubsystem constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("EndSession"), .Pointer = &UVrLinkSubsystem::execEndSession },
		{ .NameUTF8 = UTF8TEXT("GetSessionId"), .Pointer = &UVrLinkSubsystem::execGetSessionId },
		{ .NameUTF8 = UTF8TEXT("InitializeVrLink"), .Pointer = &UVrLinkSubsystem::execInitializeVrLink },
		{ .NameUTF8 = UTF8TEXT("IsSessionActive"), .Pointer = &UVrLinkSubsystem::execIsSessionActive },
		{ .NameUTF8 = UTF8TEXT("SendBaselinePhase"), .Pointer = &UVrLinkSubsystem::execSendBaselinePhase },
		{ .NameUTF8 = UTF8TEXT("SendMark"), .Pointer = &UVrLinkSubsystem::execSendMark },
		{ .NameUTF8 = UTF8TEXT("SetLocation"), .Pointer = &UVrLinkSubsystem::execSetLocation },
		{ .NameUTF8 = UTF8TEXT("SetScenario"), .Pointer = &UVrLinkSubsystem::execSetScenario },
		{ .NameUTF8 = UTF8TEXT("StartSession"), .Pointer = &UVrLinkSubsystem::execStartSession },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UVrLinkSubsystem_EndSession, "EndSession" }, // 6ff681d5058c287f1aa2f6223862e4e390581a74
		{ &Z_Construct_UFunction_UVrLinkSubsystem_GetSessionId, "GetSessionId" }, // 59047d22e52152fdb9f4ebbd8fbf290d9159ba43
		{ &Z_Construct_UFunction_UVrLinkSubsystem_InitializeVrLink, "InitializeVrLink" }, // 3382eb85d7451d1d25e28170fce8f286e4e3fe43
		{ &Z_Construct_UFunction_UVrLinkSubsystem_IsSessionActive, "IsSessionActive" }, // b1605c9e97dd2f3315119f8194a49ed456a9250d
		{ &Z_Construct_UFunction_UVrLinkSubsystem_SendBaselinePhase, "SendBaselinePhase" }, // 71a049b9025af8fec5c3fe43dcea0af1c780ba64
		{ &Z_Construct_UFunction_UVrLinkSubsystem_SendMark, "SendMark" }, // 499a2f3fcc57b928561dfee92935d95d6c0012dd
		{ &Z_Construct_UFunction_UVrLinkSubsystem_SetLocation, "SetLocation" }, // 2754007a02b372719df09291a6d6285d27751e1f
		{ &Z_Construct_UFunction_UVrLinkSubsystem_SetScenario, "SetScenario" }, // 71613e5aa705046c76384c3bed183b57cb12b11c
		{ &Z_Construct_UFunction_UVrLinkSubsystem_StartSession, "StartSession" }, // 6b23f10d9c8e3f47329ec932c8c3131004e2a0b1
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVrLinkSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UGameInstanceSubsystem,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UVrLinkSubsystem,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UVrLinkSubsystem_StaticRegisterNativesUVrLinkSubsystem()
{
	UClass* Class = UVrLinkSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UVrLinkSubsystem;
UClass* Z_Construct_UClass_UVrLinkSubsystem(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UVrLinkSubsystem;
		if (!Z_Registration_Info_UClass_UVrLinkSubsystem.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("VrLinkSubsystem"),
				Z_Registration_Info_UClass_UVrLinkSubsystem.InnerSingleton,
				UVrLinkSubsystem_StaticRegisterNativesUVrLinkSubsystem,
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
		return Z_Registration_Info_UClass_UVrLinkSubsystem.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UVrLinkSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVrLinkSubsystem.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UVrLinkSubsystem.OuterSingleton;
}
#undef UHT_STATICS
UVrLinkSubsystem::UVrLinkSubsystem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UVrLinkSubsystem);
UVrLinkSubsystem::~UVrLinkSubsystem() {}
// ********** End Class UVrLinkSubsystem ***********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h__Script_VrLink_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UVrLinkSubsystem, TEXT("UVrLinkSubsystem"), &Z_Registration_Info_UClass_UVrLinkSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVrLinkSubsystem), 1512218334U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h__Script_VrLink_db0daf55c9ad5b09c553215566253b70c9e9bf17{
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
