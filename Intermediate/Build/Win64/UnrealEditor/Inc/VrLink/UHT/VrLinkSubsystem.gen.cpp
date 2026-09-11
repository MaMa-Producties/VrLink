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
VRLINK_API UEnum* Z_Construct_UEnum_VrLink_EVrLinkCalibrationPhase(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_UVrLinkSubsystem(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_UVrLinkSubsystem(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EVrLinkCalibrationPhase ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_VrLink_EVrLinkCalibrationPhase_Statics
template<> VRLINK_NON_ATTRIBUTED_API UEnum* StaticEnum<EVrLinkCalibrationPhase>()
{
	return Z_Construct_UEnum_VrLink_EVrLinkCalibrationPhase(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Baseline.Comment", "/** One undivided calibration stretch, when the experience does not split it. */" },
		{ "Baseline.DisplayName", "Baseline" },
		{ "Baseline.Name", "EVrLinkCalibrationPhase::Baseline" },
		{ "Baseline.ToolTip", "One undivided calibration stretch, when the experience does not split it." },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * The calibration poles, as a closed set.\n *\n * A free string here was a real hazard: the recorder keys its calibration window\n * on the exact phase name, so a spelling it does not know (\"calm\", \"negative\")\n * lands outside its predicate and the window closes early -- producing a baseline\n * range that is quietly half of what it claims, with no error and no gap in the\n * file. An enum makes that unspellable from Blueprint.\n */" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "Relaxed.Comment", "/** The lower pole: the participant at rest. */" },
		{ "Relaxed.DisplayName", "Relaxed (lower pole)" },
		{ "Relaxed.Name", "EVrLinkCalibrationPhase::Relaxed" },
		{ "Relaxed.ToolTip", "The lower pole: the participant at rest." },
		{ "Stressed.Comment", "/** The upper pole: the participant deliberately unsettled. */" },
		{ "Stressed.DisplayName", "Stressed (upper pole)" },
		{ "Stressed.Name", "EVrLinkCalibrationPhase::Stressed" },
		{ "Stressed.ToolTip", "The upper pole: the participant deliberately unsettled." },
		{ "ToolTip", "The calibration poles, as a closed set.\n\nA free string here was a real hazard: the recorder keys its calibration window\non the exact phase name, so a spelling it does not know (\"calm\", \"negative\")\nlands outside its predicate and the window closes early -- producing a baseline\nrange that is quietly half of what it claims, with no error and no gap in the\nfile. An enum makes that unspellable from Blueprint." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EVrLinkCalibrationPhase::Baseline", (int64)EVrLinkCalibrationPhase::Baseline },
		{ "EVrLinkCalibrationPhase::Relaxed", (int64)EVrLinkCalibrationPhase::Relaxed },
		{ "EVrLinkCalibrationPhase::Stressed", (int64)EVrLinkCalibrationPhase::Stressed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
	nullptr,
	"EVrLinkCalibrationPhase",
	"EVrLinkCalibrationPhase",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EVrLinkCalibrationPhase;
UEnum* Z_Construct_UEnum_VrLink_EVrLinkCalibrationPhase(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EVrLinkCalibrationPhase.OuterSingleton)
		{
			ZRIE_EVrLinkCalibrationPhase.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VrLink_EVrLinkCalibrationPhase, (UObject*)Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase::Outer), TEXT("EVrLinkCalibrationPhase"));
		}
		return ZRIE_EVrLinkCalibrationPhase.OuterSingleton;
	}
	if (!ZRIE_EVrLinkCalibrationPhase.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EVrLinkCalibrationPhase.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EVrLinkCalibrationPhase.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EVrLinkCalibrationPhase *****************************************************

// ********** Begin Class UVrLinkSubsystem Function EndBaseline ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_EndBaseline_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventEndBaseline_Parms
	{
		EVrLinkCalibrationPhase Phase;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link|Calibration" },
		{ "Comment", "/**\n\x09 * Closes the calibration phase opened by Start Baseline. Pass the SAME phase.\n\x09 *\n\x09 * A phase left open runs to the end of the session, so the calibration swallows the\n\x09 * ride and there is nothing left to compare it against.\n\x09 */" },
		{ "DisplayName", "End Baseline" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "Closes the calibration phase opened by Start Baseline. Pass the SAME phase.\n\nA phase left open runs to the end of the session, so the calibration swallows the\nride and there is nothing left to compare it against." },
	};
#endif // WITH_METADATA

// ********** Begin Function EndBaseline constinit property declarations ***************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Phase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Phase;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function EndBaseline constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function EndBaseline Property Definitions **************************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Phase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Phase = { "Phase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventEndBaseline_Parms, Phase), Z_Construct_UEnum_VrLink_EVrLinkCalibrationPhase, METADATA_PARAMS(0, nullptr) }; // 2f494e01b803020224bd3600d867cc2297169dfd
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Phase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Phase,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function EndBaseline Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "EndBaseline", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventEndBaseline_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventEndBaseline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_EndBaseline(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execEndBaseline)
{
	P_GET_ENUM(EVrLinkCalibrationPhase,Z_Param_Phase);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndBaseline(EVrLinkCalibrationPhase(Z_Param_Phase));
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function EndBaseline **************************************

// ********** Begin Class UVrLinkSubsystem Function EndScenario ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_EndScenario_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/**\n\x09 * Ends the scenario now showing. Call it every time a design stops being shown,\n\x09 * whether another follows it or the ride is over.\n\x09 *\n\x09 * Everything from here until the next Start Scenario or Set Location is thrown\n\x09 * away by analysis. That stretch is the participant between designs: a transition,\n\x09 * a corridor, a fade to black. It has no point of interest in it, and counted as\n\x09 * data it would be credited to the design that just ended.\n\x09 */" },
		{ "DisplayName", "End Scenario" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "Ends the scenario now showing. Call it every time a design stops being shown,\nwhether another follows it or the ride is over.\n\nEverything from here until the next Start Scenario or Set Location is thrown\naway by analysis. That stretch is the participant between designs: a transition,\na corridor, a fade to black. It has no point of interest in it, and counted as\ndata it would be credited to the design that just ended." },
	};
#endif // WITH_METADATA

// ********** Begin Function EndScenario constinit property declarations ***************************
// ********** End Function EndScenario constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "EndScenario", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_EndScenario(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execEndScenario)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndScenario();
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function EndScenario **************************************

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
		{ "Comment", "/**\n\x09 * Makes the link exist and listen for the tablet. Safe to call more than\n\x09 * once. `ProjectName` is the study/project shown on the tablet (e.g.\n\x09 * \"Spaklerweg\"); `Posture` is the participant's body position, an EEG-noise\n\x09 * covariate (\"Cycling\" for the bike).\n\x09 *\n\x09 * Call it once, from the Game Instance. It is remembered, and the link is\n\x09 * rebuilt by itself in every level the participant is taken to -- the\n\x09 * subsystem outlives a level change but the actors in a level do not, so\n\x09 * without that the first Open Level would silently leave nothing to talk\n\x09 * to. The session keeps running across the change; only the actors are new.\n\x09 */" },
		{ "CPP_Default_Posture", "Cycling" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "Makes the link exist and listen for the tablet. Safe to call more than\nonce. `ProjectName` is the study/project shown on the tablet (e.g.\n\"Spaklerweg\"); `Posture` is the participant's body position, an EEG-noise\ncovariate (\"Cycling\" for the bike).\n\nCall it once, from the Game Instance. It is remembered, and the link is\nrebuilt by itself in every level the participant is taken to -- the\nsubsystem outlives a level change but the actors in a level do not, so\nwithout that the first Open Level would silently leave nothing to talk\nto. The session keeps running across the change; only the actors are new." },
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

// ********** Begin Class UVrLinkSubsystem Function SetPedalling ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_SetPedalling_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventSetPedalling_Parms
	{
		bool bTurning;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/**\n\x09 * The bike's pedals started or stopped turning. Call on every change, or every\n\x09 * tick straight from the sensor: repeats of the same value are dropped here.\n\x09 *\n\x09 * Recorded as two marks, `pedal:start` and `pedal:stop`, which is the whole\n\x09 * span of movement rather than a reading of how fast. A cadence value at even\n\x09 * ten a second is five thousand rows in a session, and the recorder has been\n\x09 * here before: the headband's blink flag was written as rows until somebody\n\x09 * counted them and found nothing could use them.\n\x09 *\n\x09 * Call it once after Start Session as well, whatever the pedals are doing. The\n\x09 * analysis cannot tell a recording that never reported from a participant who\n\x09 * never moved, and it refuses to guess, so an opening call is what makes the\n\x09 * whole session readable rather than the part after the first change.\n\x09 *\n\x09 * What it is for: the calibration is the one stretch that is supposed to be\n\x09 * the participant at rest, and nothing in the file could say whether it was.\n\x09 */" },
		{ "DisplayName", "Set Pedalling" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "The bike's pedals started or stopped turning. Call on every change, or every\ntick straight from the sensor: repeats of the same value are dropped here.\n\nRecorded as two marks, `pedal:start` and `pedal:stop`, which is the whole\nspan of movement rather than a reading of how fast. A cadence value at even\nten a second is five thousand rows in a session, and the recorder has been\nhere before: the headband's blink flag was written as rows until somebody\ncounted them and found nothing could use them.\n\nCall it once after Start Session as well, whatever the pedals are doing. The\nanalysis cannot tell a recording that never reported from a participant who\nnever moved, and it refuses to guess, so an opening call is what makes the\nwhole session readable rather than the part after the first change.\n\nWhat it is for: the calibration is the one stretch that is supposed to be\nthe participant at rest, and nothing in the file could say whether it was." },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPedalling constinit property declarations **************************
	static void NewProp_bTurning_SetBit(void* Obj)
	{
		((VrLinkSubsystem_eventSetPedalling_Parms*)Obj)->bTurning = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTurning;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPedalling constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPedalling Property Definitions *************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bTurning = { "bTurning", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(VrLinkSubsystem_eventSetPedalling_Parms), &UHT_STATICS::NewProp_bTurning_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bTurning,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetPedalling Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "SetPedalling", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventSetPedalling_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventSetPedalling_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_SetPedalling(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execSetPedalling)
{
	P_GET_UBOOL(Z_Param_bTurning);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPedalling(Z_Param_bTurning);
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function SetPedalling *************************************

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
		{ "Comment", "/**\n\x09 * The design variant now on display (e.g. \"Green facade\"). Call on every change.\n\x09 *\n\x09 * Calling it again with another name starts that one, which is what ends this one:\n\x09 * only one design is on display at a time. EndScenario is for the other case, a\n\x09 * design stopping with nothing to replace it.\n\x09 *\n\x09 * Shown in Blueprint as Start Scenario, to pair with End Scenario. The C++ name is\n\x09 * deliberately left alone: nodes bind to that, and renaming it would turn every\n\x09 * existing call into a red error node in a graph nobody here can open.\n\x09 */" },
		{ "DisplayName", "Start Scenario" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "The design variant now on display (e.g. \"Green facade\"). Call on every change.\n\nCalling it again with another name starts that one, which is what ends this one:\nonly one design is on display at a time. EndScenario is for the other case, a\ndesign stopping with nothing to replace it.\n\nShown in Blueprint as Start Scenario, to pair with End Scenario. The C++ name is\ndeliberately left alone: nodes bind to that, and renaming it would turn every\nexisting call into a red error node in a graph nobody here can open." },
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

// ********** Begin Class UVrLinkSubsystem Function StartBaseline **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkSubsystem_StartBaseline_Statics
struct UHT_STATICS
{
	struct VrLinkSubsystem_eventStartBaseline_Parms
	{
		EVrLinkCalibrationPhase Phase;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VR Link|Calibration" },
		{ "Comment", "/**\n\x09 * For experiences that drive the calibration themselves instead of letting the\n\x09 * tablet time it: marks the start and end of a calibration phase.\n\x09 *\n\x09 * Call it around each pole. A calibration that is a relaxed half followed by a\n\x09 * stressed half needs all four calls, and the recorder keeps them as one window\n\x09 * because both are calibration; without the second pole the range has no upper\n\x09 * end and every value measured against it is wrong in the same direction.\n\x09 */" },
		{ "DisplayName", "Start Baseline" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
		{ "ToolTip", "For experiences that drive the calibration themselves instead of letting the\ntablet time it: marks the start and end of a calibration phase.\n\nCall it around each pole. A calibration that is a relaxed half followed by a\nstressed half needs all four calls, and the recorder keeps them as one window\nbecause both are calibration; without the second pole the range has no upper\nend and every value measured against it is wrong in the same direction." },
	};
#endif // WITH_METADATA

// ********** Begin Function StartBaseline constinit property declarations *************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Phase_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Phase;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartBaseline constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartBaseline Property Definitions ************************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Phase_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_Phase = { "Phase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkSubsystem_eventStartBaseline_Parms, Phase), Z_Construct_UEnum_VrLink_EVrLinkCalibrationPhase, METADATA_PARAMS(0, nullptr) }; // 2f494e01b803020224bd3600d867cc2297169dfd
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Phase_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Phase,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function StartBaseline Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkSubsystem, nullptr, "StartBaseline", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkSubsystem_eventStartBaseline_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkSubsystem_eventStartBaseline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkSubsystem_StartBaseline(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkSubsystem::execStartBaseline)
{
	P_GET_ENUM(EVrLinkCalibrationPhase,Z_Param_Phase);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartBaseline(EVrLinkCalibrationPhase(Z_Param_Phase));
	P_NATIVE_END;
}
// ********** End Class UVrLinkSubsystem Function StartBaseline ************************************

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
		{ "DisplayName", "VR Link" },
		{ "IncludePath", "VrLinkSubsystem.h" },
		{ "ModuleRelativePath", "Public/VrLinkSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UVrLinkSubsystem constinit property declarations *************************
// ********** End Class UVrLinkSubsystem constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("EndBaseline"), .Pointer = &UVrLinkSubsystem::execEndBaseline },
		{ .NameUTF8 = UTF8TEXT("EndScenario"), .Pointer = &UVrLinkSubsystem::execEndScenario },
		{ .NameUTF8 = UTF8TEXT("EndSession"), .Pointer = &UVrLinkSubsystem::execEndSession },
		{ .NameUTF8 = UTF8TEXT("GetSessionId"), .Pointer = &UVrLinkSubsystem::execGetSessionId },
		{ .NameUTF8 = UTF8TEXT("InitializeVrLink"), .Pointer = &UVrLinkSubsystem::execInitializeVrLink },
		{ .NameUTF8 = UTF8TEXT("IsSessionActive"), .Pointer = &UVrLinkSubsystem::execIsSessionActive },
		{ .NameUTF8 = UTF8TEXT("SendMark"), .Pointer = &UVrLinkSubsystem::execSendMark },
		{ .NameUTF8 = UTF8TEXT("SetLocation"), .Pointer = &UVrLinkSubsystem::execSetLocation },
		{ .NameUTF8 = UTF8TEXT("SetPedalling"), .Pointer = &UVrLinkSubsystem::execSetPedalling },
		{ .NameUTF8 = UTF8TEXT("SetScenario"), .Pointer = &UVrLinkSubsystem::execSetScenario },
		{ .NameUTF8 = UTF8TEXT("StartBaseline"), .Pointer = &UVrLinkSubsystem::execStartBaseline },
		{ .NameUTF8 = UTF8TEXT("StartSession"), .Pointer = &UVrLinkSubsystem::execStartSession },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UVrLinkSubsystem_EndBaseline, "EndBaseline" }, // 7635acf21b7dbb3c8cd6600093fa05be7d9557ab
		{ &Z_Construct_UFunction_UVrLinkSubsystem_EndScenario, "EndScenario" }, // 8fcf4fe8a90941627b68213b80e6cdcfdf271a8b
		{ &Z_Construct_UFunction_UVrLinkSubsystem_EndSession, "EndSession" }, // 6ff681d5058c287f1aa2f6223862e4e390581a74
		{ &Z_Construct_UFunction_UVrLinkSubsystem_GetSessionId, "GetSessionId" }, // 59047d22e52152fdb9f4ebbd8fbf290d9159ba43
		{ &Z_Construct_UFunction_UVrLinkSubsystem_InitializeVrLink, "InitializeVrLink" }, // 4e2f529394a68500b8fd18e80fbc569221d1ed6a
		{ &Z_Construct_UFunction_UVrLinkSubsystem_IsSessionActive, "IsSessionActive" }, // b1605c9e97dd2f3315119f8194a49ed456a9250d
		{ &Z_Construct_UFunction_UVrLinkSubsystem_SendMark, "SendMark" }, // 499a2f3fcc57b928561dfee92935d95d6c0012dd
		{ &Z_Construct_UFunction_UVrLinkSubsystem_SetLocation, "SetLocation" }, // 2754007a02b372719df09291a6d6285d27751e1f
		{ &Z_Construct_UFunction_UVrLinkSubsystem_SetPedalling, "SetPedalling" }, // 8b1ebf5b4c3ab5767496aed35e30cbb1497772fd
		{ &Z_Construct_UFunction_UVrLinkSubsystem_SetScenario, "SetScenario" }, // 0229bf2039d245dbc7009e0a83f0ccb3d07595b0
		{ &Z_Construct_UFunction_UVrLinkSubsystem_StartBaseline, "StartBaseline" }, // 1f575bb047f250c46b044ce0d5659bb4a6b9540c
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
#define UHT_STATICS Z_CompiledInDeferFile_FID_vb58_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h__Script_VrLink_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_VrLink_EVrLinkCalibrationPhase, TEXT("EVrLinkCalibrationPhase"), &ZRIE_EVrLinkCalibrationPhase, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 793333249U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UVrLinkSubsystem, TEXT("UVrLinkSubsystem"), &Z_Registration_Info_UClass_UVrLinkSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVrLinkSubsystem), 2213396022U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_vb58_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h__Script_VrLink_b469d22c0e58a44bf2b9fc99d3da6486d88c7c70{
	TEXT("/Script/VrLink"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
