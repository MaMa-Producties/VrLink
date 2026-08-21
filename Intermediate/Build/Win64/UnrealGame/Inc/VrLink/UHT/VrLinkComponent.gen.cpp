// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VrLinkComponent.h"
#include "InputCoreTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeVrLinkComponent() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UActorComponent(ETypeConstructPhase);
INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase);
VRLINK_API UEnum* Z_Construct_UEnum_VrLink_EExperienceStartMode(ETypeConstructPhase);
VRLINK_API UEnum* Z_Construct_UEnum_VrLink_EStepAdvanceMode(ETypeConstructPhase);
VRLINK_API UEnum* Z_Construct_UEnum_VrLink_EStepKind(ETypeConstructPhase);
VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_ExperienceFinished__DelegateSignature(ETypeConstructPhase);
VRLINK_API UScriptStruct* Z_Construct_UScriptStruct_FExperienceStep(ETypeConstructPhase);
VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_ExperienceStepEnded__DelegateSignature(ETypeConstructPhase);
VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_ExperienceStepStarted__DelegateSignature(ETypeConstructPhase);
VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_RecordingStarted__DelegateSignature(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_UVrLinkComponent(ETypeConstructPhase);
VRLINK_API UScriptStruct* Z_Construct_UScriptStruct_FVrLinkStudyConfig(ETypeConstructPhase);
VRLINK_API UScriptStruct* Z_Construct_UScriptStruct_FVrLinkVariable(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_ATCPSocket(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_UVrLinkComponent(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Enum EStepKind *****************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_VrLink_EStepKind_Statics
template<> VRLINK_NON_ATTRIBUTED_API UEnum* StaticEnum<EStepKind>()
{
	return Z_Construct_UEnum_VrLink_EStepKind(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Baseline.Comment", "/** The rest window every other reading is normalised against. Sends baseline start and end. */" },
		{ "Baseline.DisplayName", "Baseline" },
		{ "Baseline.Name", "EStepKind::Baseline" },
		{ "Baseline.ToolTip", "The rest window every other reading is normalised against. Sends baseline start and end." },
		{ "BlueprintType", "true" },
		{ "Comment", "/** What a step represents, which determines the events it sends to the recorder. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "Scenario.Comment", "/** A design variant shown at a location. Sends the location and scenario. */" },
		{ "Scenario.DisplayName", "Scenario" },
		{ "Scenario.Name", "EStepKind::Scenario" },
		{ "Scenario.ToolTip", "A design variant shown at a location. Sends the location and scenario." },
		{ "SettleIn.Comment", "/** Sends no events. Use it to hold time while the participant gets set up. */" },
		{ "SettleIn.DisplayName", "Settle In" },
		{ "SettleIn.Name", "EStepKind::SettleIn" },
		{ "SettleIn.ToolTip", "Sends no events. Use it to hold time while the participant gets set up." },
		{ "ToolTip", "What a step represents, which determines the events it sends to the recorder." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStepKind::SettleIn", (int64)EStepKind::SettleIn },
		{ "EStepKind::Baseline", (int64)EStepKind::Baseline },
		{ "EStepKind::Scenario", (int64)EStepKind::Scenario },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
	nullptr,
	"EStepKind",
	"EStepKind",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EStepKind;
UEnum* Z_Construct_UEnum_VrLink_EStepKind(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EStepKind.OuterSingleton)
		{
			ZRIE_EStepKind.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VrLink_EStepKind, (UObject*)Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase::Outer), TEXT("EStepKind"));
		}
		return ZRIE_EStepKind.OuterSingleton;
	}
	if (!ZRIE_EStepKind.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EStepKind.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EStepKind.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EStepKind *******************************************************************

// ********** Begin Enum EStepAdvanceMode **********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_VrLink_EStepAdvanceMode_Statics
template<> VRLINK_NON_ATTRIBUTED_API UEnum* StaticEnum<EStepAdvanceMode>()
{
	return Z_Construct_UEnum_VrLink_EStepAdvanceMode(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** What advances the timeline to the next step. */" },
		{ "Duration.Comment", "/** Each step advances once its DurationSeconds elapses. Requires no level content. */" },
		{ "Duration.DisplayName", "Duration" },
		{ "Duration.Name", "EStepAdvanceMode::Duration" },
		{ "Duration.ToolTip", "Each step advances once its DurationSeconds elapses. Requires no level content." },
		{ "Manual.Comment", "/** A key or controller button advances the timeline. Useful for stepping through a run. */" },
		{ "Manual.DisplayName", "Manual" },
		{ "Manual.Name", "EStepAdvanceMode::Manual" },
		{ "Manual.ToolTip", "A key or controller button advances the timeline. Useful for stepping through a run." },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "What advances the timeline to the next step." },
		{ "TriggerVolume.Comment", "/** A trigger volume in the level advances the timeline by calling GoToNextStep. */" },
		{ "TriggerVolume.DisplayName", "Trigger Volume" },
		{ "TriggerVolume.Name", "EStepAdvanceMode::TriggerVolume" },
		{ "TriggerVolume.ToolTip", "A trigger volume in the level advances the timeline by calling GoToNextStep." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EStepAdvanceMode::Duration", (int64)EStepAdvanceMode::Duration },
		{ "EStepAdvanceMode::TriggerVolume", (int64)EStepAdvanceMode::TriggerVolume },
		{ "EStepAdvanceMode::Manual", (int64)EStepAdvanceMode::Manual },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
	nullptr,
	"EStepAdvanceMode",
	"EStepAdvanceMode",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EStepAdvanceMode;
UEnum* Z_Construct_UEnum_VrLink_EStepAdvanceMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EStepAdvanceMode.OuterSingleton)
		{
			ZRIE_EStepAdvanceMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VrLink_EStepAdvanceMode, (UObject*)Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase::Outer), TEXT("EStepAdvanceMode"));
		}
		return ZRIE_EStepAdvanceMode.OuterSingleton;
	}
	if (!ZRIE_EStepAdvanceMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EStepAdvanceMode.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EStepAdvanceMode.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EStepAdvanceMode ************************************************************

// ********** Begin Enum EExperienceStartMode ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UEnum_VrLink_EExperienceStartMode_Statics
template<> VRLINK_NON_ATTRIBUTED_API UEnum* StaticEnum<EExperienceStartMode>()
{
	return Z_Construct_UEnum_VrLink_EExperienceStartMode(ETypeConstructPhase::Outer);
}
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** What starts the experience running. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "OnBeginPlay.Comment", "/** Starts automatically the moment the level begins play. */" },
		{ "OnBeginPlay.DisplayName", "On Begin Play" },
		{ "OnBeginPlay.Name", "EExperienceStartMode::OnBeginPlay" },
		{ "OnBeginPlay.ToolTip", "Starts automatically the moment the level begins play." },
		{ "OnTabletStart.Comment", "/** Starts automatically when the tablet operator presses Start Recording (on the tablet's session.start). */" },
		{ "OnTabletStart.DisplayName", "When Tablet Starts Recording" },
		{ "OnTabletStart.Name", "EExperienceStartMode::OnTabletStart" },
		{ "OnTabletStart.ToolTip", "Starts automatically when the tablet operator presses Start Recording (on the tablet's session.start)." },
		{ "OnTrigger.Comment", "/** Waits to be started: by a Start Trigger volume you assign, or a Blueprint call to Start Experience. */" },
		{ "OnTrigger.DisplayName", "On Trigger" },
		{ "OnTrigger.Name", "EExperienceStartMode::OnTrigger" },
		{ "OnTrigger.ToolTip", "Waits to be started: by a Start Trigger volume you assign, or a Blueprint call to Start Experience." },
		{ "ToolTip", "What starts the experience running." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EExperienceStartMode::OnBeginPlay", (int64)EExperienceStartMode::OnBeginPlay },
		{ "EExperienceStartMode::OnTrigger", (int64)EExperienceStartMode::OnTrigger },
		{ "EExperienceStartMode::OnTabletStart", (int64)EExperienceStartMode::OnTabletStart },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct UHT_STATICS 
const UECodeGen_Private::FEnumParams UHT_STATICS::EnumParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
	nullptr,
	"EExperienceStartMode",
	"EExperienceStartMode",
	UHT_STATICS::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(UHT_STATICS::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	(uint8)UEnum::EUnderlyingType::uint8,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FEnumRegistrationInfo ZRIE_EExperienceStartMode;
UEnum* Z_Construct_UEnum_VrLink_EExperienceStartMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!ZRIE_EExperienceStartMode.OuterSingleton)
		{
			ZRIE_EExperienceStartMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VrLink_EExperienceStartMode, (UObject*)Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase::Outer), TEXT("EExperienceStartMode"));
		}
		return ZRIE_EExperienceStartMode.OuterSingleton;
	}
	if (!ZRIE_EExperienceStartMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(ZRIE_EExperienceStartMode.InnerSingleton, UHT_STATICS::EnumParams);
	}
	return ZRIE_EExperienceStartMode.InnerSingleton;
}
#undef UHT_STATICS
// ********** End Enum EExperienceStartMode ********************************************************

// ********** Begin ScriptStruct FExperienceStep ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FExperienceStep_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FExperienceStep>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FExperienceStep); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * One step of the experience. The Location and Scenario set here are the single\n * source of truth: they are written into the recorded data AND they generate the\n * scene and variable lists sent to the tablet in the handshake, so the two can\n * never disagree.\n */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "One step of the experience. The Location and Scenario set here are the single\nsource of truth: they are written into the recorded data AND they generate the\nscene and variable lists sent to the tablet in the handshake, so the two can\nnever disagree." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StepKind_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** What this step represents. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "What this step represents." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** Where the participant is, e.g. \"Spaklerweg\". Reuse the same value across scenarios in one location. */" },
		{ "EditCondition", "StepKind == EStepKind::Scenario" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Where the participant is, e.g. \"Spaklerweg\". Reuse the same value across scenarios in one location." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scenario_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** The design variant shown here, e.g. \"Green facade\". */" },
		{ "EditCondition", "StepKind == EStepKind::Scenario" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "The design variant shown here, e.g. \"Green facade\"." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DurationSeconds_MetaData[] = {
		{ "Category", "Experience" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** How long the step runs. Only used when AdvanceMode is Duration. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "How long the step runs. Only used when AdvanceMode is Duration." },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FadeOutSeconds_MetaData[] = {
		{ "Category", "Experience" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** Delay between this step ending and the next starting, to allow a fade. Only used when AdvanceMode is Duration. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Delay between this step ending and the next starting, to allow a fade. Only used when AdvanceMode is Duration." },
		{ "UIMin", "0.0" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FExperienceStep constinit property declarations *******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_StepKind_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StepKind;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Scenario;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DurationSeconds;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FadeOutSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FExperienceStep constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FExperienceStep>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FExperienceStep Property Definitions ******************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_StepKind_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_StepKind = { "StepKind", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(FExperienceStep, StepKind), Z_Construct_UEnum_VrLink_EStepKind, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StepKind_MetaData), NewProp_StepKind_MetaData) }; // b55257629059912365b5b47ffefa22ba254d4a5e
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FExperienceStep, Location), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Scenario = { "Scenario", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FExperienceStep, Scenario), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scenario_MetaData), NewProp_Scenario_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DurationSeconds = { "DurationSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FExperienceStep, DurationSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DurationSeconds_MetaData), NewProp_DurationSeconds_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FadeOutSeconds = { "FadeOutSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FExperienceStep, FadeOutSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FadeOutSeconds_MetaData), NewProp_FadeOutSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepKind_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepKind,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Scenario,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DurationSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FadeOutSeconds,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FExperienceStep Property Definitions ********************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
	nullptr,
	&NewStructOps,
	"ExperienceStep",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FExperienceStep>(),
	alignof(FExperienceStep),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FExperienceStep;
UScriptStruct* Z_Construct_UScriptStruct_FExperienceStep(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FExperienceStep.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FExperienceStep.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FExperienceStep, (UObject*)Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase::Outer), TEXT("ExperienceStep"));
		}
		return Z_Registration_Info_UScriptStruct_FExperienceStep.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FExperienceStep.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FExperienceStep.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FExperienceStep.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FExperienceStep *****************************************************

// ********** Begin ScriptStruct FVrLinkVariable ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FVrLinkVariable_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FVrLinkVariable>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FVrLinkVariable); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * One study variable (condition) the VR side drives, e.g. \"Scenario\" with options\n * \"Green facade\"/\"Grey facade\". Built automatically from the Steps table and sent\n * in the `welcome` handshake so the tablet locks its recorder config to what the\n * experience actually contains. Not authored by hand.\n */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "One study variable (condition) the VR side drives, e.g. \"Scenario\" with options\n\"Green facade\"/\"Grey facade\". Built automatically from the Steps table and sent\nin the `welcome` handshake so the tablet locks its recorder config to what the\nexperience actually contains. Not authored by hand." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "VrLink" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Options_MetaData[] = {
		{ "Category", "VrLink" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FVrLinkVariable constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Options_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Options;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FVrLinkVariable constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVrLinkVariable>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FVrLinkVariable Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FVrLinkVariable, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Options_Inner = { "Options", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Options = { "Options", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(FVrLinkVariable, Options), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Options_MetaData), NewProp_Options_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Options_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Options,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FVrLinkVariable Property Definitions ********************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
	nullptr,
	&NewStructOps,
	"VrLinkVariable",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FVrLinkVariable>(),
	alignof(FVrLinkVariable),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FVrLinkVariable;
UScriptStruct* Z_Construct_UScriptStruct_FVrLinkVariable(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FVrLinkVariable.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FVrLinkVariable.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVrLinkVariable, (UObject*)Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase::Outer), TEXT("VrLinkVariable"));
		}
		return Z_Registration_Info_UScriptStruct_FVrLinkVariable.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FVrLinkVariable.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FVrLinkVariable.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FVrLinkVariable.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FVrLinkVariable *****************************************************

// ********** Begin ScriptStruct FVrLinkStudyConfig ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FVrLinkStudyConfig_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FVrLinkStudyConfig>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FVrLinkStudyConfig); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * The study definition handed to the recorder in the `welcome` message (vrlink v1.1 \xc3\x82\xc2\xa7""3).\n *\n * Note there is no scene or variable list here: those are derived from the Steps\n * table on the component, so the names in the handshake and the names in the\n * recorded events are guaranteed to be the same.\n */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "The study definition handed to the recorder in the `welcome` message (vrlink v1.1 \xc3\x82\xc2\xa7""3).\n\nNote there is no scene or variable list here: those are derived from the Steps\ntable on the component, so the names in the handshake and the names in the\nrecorded events are guaranteed to be the same." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Experience_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/**\n\x09 * The project / study name: the urban-development project, e.g. \"Spaklerweg\". One field, shown in\n\x09 * the editor as \"Project Name\". Sent to the tablet in `welcome` as the linked experience. Kept named\n\x09 * `Experience` in code so nothing downstream (wire key, Unity, session.csv) has to be renamed.\n\x09 */" },
		{ "DisplayName", "Project Name" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "The project / study name: the urban-development project, e.g. \"Spaklerweg\". One field, shown in\nthe editor as \"Project Name\". Sent to the tablet in `welcome` as the linked experience. Kept named\n`Experience` in code so nothing downstream (wire key, Unity, session.csv) has to be renamed." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Posture_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** Participant posture, e.g. \"Cycling\" (Sitting/Standing/Walking/Cycling/Lying down). */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Participant posture, e.g. \"Cycling\" (Sitting/Standing/Walking/Cycling/Lying down)." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PairingCode_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/**\n\x09 * Optional pairing code for this station. When set, only a tablet whose hello carries the same\n\x09 * code is accepted (others get a pairing-code-mismatch reject), so several stations can run in\n\x09 * one room without cross-connecting. **Leave empty to accept any tablet**, which is what you\n\x09 * want unless you are actually running multiple stations.\n\x09 */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Optional pairing code for this station. When set, only a tablet whose hello carries the same\ncode is accepted (others get a pairing-code-mismatch reject), so several stations can run in\none room without cross-connecting. **Leave empty to accept any tablet**, which is what you\nwant unless you are actually running multiple stations." },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FVrLinkStudyConfig constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Experience;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Posture;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PairingCode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FVrLinkStudyConfig constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVrLinkStudyConfig>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FVrLinkStudyConfig Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Experience = { "Experience", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FVrLinkStudyConfig, Experience), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Experience_MetaData), NewProp_Experience_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Posture = { "Posture", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FVrLinkStudyConfig, Posture), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Posture_MetaData), NewProp_Posture_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_PairingCode = { "PairingCode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FVrLinkStudyConfig, PairingCode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PairingCode_MetaData), NewProp_PairingCode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Experience,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Posture,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PairingCode,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FVrLinkStudyConfig Property Definitions *****************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
	nullptr,
	&NewStructOps,
	"VrLinkStudyConfig",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FVrLinkStudyConfig>(),
	alignof(FVrLinkStudyConfig),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FVrLinkStudyConfig;
UScriptStruct* Z_Construct_UScriptStruct_FVrLinkStudyConfig(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FVrLinkStudyConfig.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FVrLinkStudyConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVrLinkStudyConfig, (UObject*)Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase::Outer), TEXT("VrLinkStudyConfig"));
		}
		return Z_Registration_Info_UScriptStruct_FVrLinkStudyConfig.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FVrLinkStudyConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FVrLinkStudyConfig.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FVrLinkStudyConfig.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FVrLinkStudyConfig **************************************************

// ********** Begin Delegate FExperienceStepStarted ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_VrLink_ExperienceStepStarted__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_VrLink_eventExperienceStepStarted_Parms
	{
		FString Location;
		FString Scenario;
		EStepKind StepKind;
		int32 StepIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scenario_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FExperienceStepStarted constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Scenario;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StepKind_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StepKind;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StepIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FExperienceStepStarted constinit property declarations ******************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FExperienceStepStarted Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventExperienceStepStarted_Parms, Location), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Scenario = { "Scenario", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventExperienceStepStarted_Parms, Scenario), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scenario_MetaData), NewProp_Scenario_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_StepKind_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_StepKind = { "StepKind", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventExperienceStepStarted_Parms, StepKind), Z_Construct_UEnum_VrLink_EStepKind, METADATA_PARAMS(0, nullptr) }; // b55257629059912365b5b47ffefa22ba254d4a5e
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_StepIndex = { "StepIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventExperienceStepStarted_Parms, StepIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Scenario,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepKind_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepKind,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FExperienceStepStarted Property Definitions *****************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink, nullptr, "ExperienceStepStarted__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_VrLink_eventExperienceStepStarted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_VrLink_eventExperienceStepStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_VrLink_ExperienceStepStarted__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FExperienceStepStarted **************************************************

// ********** Begin Delegate FExperienceStepEnded **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_VrLink_ExperienceStepEnded__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_VrLink_eventExperienceStepEnded_Parms
	{
		FString Location;
		FString Scenario;
		EStepKind StepKind;
		int32 StepIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scenario_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FExperienceStepEnded constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Scenario;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StepKind_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StepKind;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StepIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FExperienceStepEnded constinit property declarations ********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FExperienceStepEnded Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventExperienceStepEnded_Parms, Location), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Scenario = { "Scenario", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventExperienceStepEnded_Parms, Scenario), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scenario_MetaData), NewProp_Scenario_MetaData) };
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_StepKind_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_StepKind = { "StepKind", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventExperienceStepEnded_Parms, StepKind), Z_Construct_UEnum_VrLink_EStepKind, METADATA_PARAMS(0, nullptr) }; // b55257629059912365b5b47ffefa22ba254d4a5e
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_StepIndex = { "StepIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventExperienceStepEnded_Parms, StepIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Scenario,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepKind_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepKind,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepIndex,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FExperienceStepEnded Property Definitions *******************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink, nullptr, "ExperienceStepEnded__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_VrLink_eventExperienceStepEnded_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_VrLink_eventExperienceStepEnded_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_VrLink_ExperienceStepEnded__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FExperienceStepEnded ****************************************************

// ********** Begin Delegate FExperienceFinished ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_VrLink_ExperienceFinished__DelegateSignature_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FExperienceFinished constinit property declarations *******************
// ********** End Delegate FExperienceFinished constinit property declarations *********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink, nullptr, "ExperienceFinished__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UDelegateFunction_VrLink_ExperienceFinished__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FExperienceFinished *****************************************************

// ********** Begin Delegate FRecordingStarted *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_VrLink_RecordingStarted__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_VrLink_eventRecordingStarted_Parms
	{
		FString SessionId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FRecordingStarted constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SessionId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FRecordingStarted constinit property declarations ***********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FRecordingStarted Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventRecordingStarted_Parms, SessionId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SessionId_MetaData), NewProp_SessionId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SessionId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FRecordingStarted Property Definitions **********************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink, nullptr, "RecordingStarted__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_VrLink_eventRecordingStarted_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_VrLink_eventRecordingStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_VrLink_RecordingStarted__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FRecordingStarted *******************************************************

// ********** Begin Class UVrLinkComponent Function EndSession *************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_EndSession_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventEndSession_Parms
	{
		FString Reason;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** Ends the current session (spec \xc3\x82\xc2\xa7""4 stop). `Reason` is complete|interrupted|emergency-stop. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Ends the current session (spec \xc3\x82\xc2\xa7""4 stop). `Reason` is complete|interrupted|emergency-stop." },
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
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventEndSession_Parms, Reason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Reason_MetaData), NewProp_Reason_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function EndSession Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "EndSession", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventEndSession_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventEndSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_EndSession(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execEndSession)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Reason);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EndSession(Z_Param_Reason);
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function EndSession ***************************************

// ********** Begin Class UVrLinkComponent Function GetCurrentScene ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_GetCurrentScene_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventGetCurrentScene_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** The scene (Location) last sent to the recorder. Empty before the first scenario step. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "The scene (Location) last sent to the recorder. Empty before the first scenario step." },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentScene constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentScene constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentScene Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventGetCurrentScene_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentScene Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "GetCurrentScene", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventGetCurrentScene_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventGetCurrentScene_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_GetCurrentScene(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execGetCurrentScene)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetCurrentScene();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function GetCurrentScene **********************************

// ********** Begin Class UVrLinkComponent Function GetCurrentStepIndex ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_GetCurrentStepIndex_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventGetCurrentStepIndex_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** Index of the running step, or -1 when the experience is not running. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Index of the running step, or -1 when the experience is not running." },
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentStepIndex constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentStepIndex constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentStepIndex Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventGetCurrentStepIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetCurrentStepIndex Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "GetCurrentStepIndex", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventGetCurrentStepIndex_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventGetCurrentStepIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_GetCurrentStepIndex(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execGetCurrentStepIndex)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetCurrentStepIndex();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function GetCurrentStepIndex ******************************

// ********** Begin Class UVrLinkComponent Function GetSessionElapsedSeconds ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_GetSessionElapsedSeconds_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventGetSessionElapsedSeconds_Parms
	{
		double ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** Seconds since session start: the clock every event and every gaze row is stamped with. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Seconds since session start: the clock every event and every gaze row is stamped with." },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSessionElapsedSeconds constinit property declarations **************
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSessionElapsedSeconds constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSessionElapsedSeconds Property Definitions *************************
const UECodeGen_Private::FDoublePropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventGetSessionElapsedSeconds_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSessionElapsedSeconds Property Definitions ***************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "GetSessionElapsedSeconds", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventGetSessionElapsedSeconds_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventGetSessionElapsedSeconds_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_GetSessionElapsedSeconds(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execGetSessionElapsedSeconds)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(double*)Z_Param__Result=P_THIS->GetSessionElapsedSeconds();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function GetSessionElapsedSeconds *************************

// ********** Begin Class UVrLinkComponent Function GetSessionFolder *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_GetSessionFolder_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventGetSessionFolder_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** The study-day folder name the tablet minted, e.g. \"Spaklerweg_2026-07-10\". Empty outside a session. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "The study-day folder name the tablet minted, e.g. \"Spaklerweg_2026-07-10\". Empty outside a session." },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSessionFolder constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSessionFolder constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSessionFolder Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventGetSessionFolder_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSessionFolder Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "GetSessionFolder", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventGetSessionFolder_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventGetSessionFolder_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_GetSessionFolder(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execGetSessionFolder)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetSessionFolder();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function GetSessionFolder *********************************

// ********** Begin Class UVrLinkComponent Function GetSessionId ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_GetSessionId_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventGetSessionId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** The agreed session id, `{museId}-{utcMs}-{rand4}`. Empty until the tablet answers. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "The agreed session id, `{museId}-{utcMs}-{rand4}`. Empty until the tablet answers." },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSessionId constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSessionId constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSessionId Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventGetSessionId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetSessionId Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "GetSessionId", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventGetSessionId_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventGetSessionId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_GetSessionId(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execGetSessionId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetSessionId();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function GetSessionId *************************************

// ********** Begin Class UVrLinkComponent Function GoToNextStep ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_GoToNextStep_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/**\n\x09 * Ends the current step and starts the next.\n\x09 *\n\x09 * The single entry point every advance mode goes through: the duration timer, a\n\x09 * trigger volume, the manual key, or a Level Sequence event track.\n\x09 */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Ends the current step and starts the next.\n\nThe single entry point every advance mode goes through: the duration timer, a\ntrigger volume, the manual key, or a Level Sequence event track." },
	};
#endif // WITH_METADATA

// ********** Begin Function GoToNextStep constinit property declarations **************************
// ********** End Function GoToNextStep constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "GoToNextStep", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UVrLinkComponent_GoToNextStep(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execGoToNextStep)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GoToNextStep();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function GoToNextStep *************************************

// ********** Begin Class UVrLinkComponent Function HandleLine *************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_HandleLine_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventHandleLine_Parms
	{
		FString Line;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/** Bound to ATCPSocket::OnMessageReceived; parses one JSON line and dispatches on `type`. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Bound to ATCPSocket::OnMessageReceived; parses one JSON line and dispatches on `type`." },
	};
#endif // WITH_METADATA

// ********** Begin Function HandleLine constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Line;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HandleLine constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HandleLine Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Line = { "Line", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventHandleLine_Parms, Line), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Line,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function HandleLine Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "HandleLine", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventHandleLine_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventHandleLine_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_HandleLine(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execHandleLine)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Line);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleLine(Z_Param_Line);
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function HandleLine ***************************************

// ********** Begin Class UVrLinkComponent Function IsRunning **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_IsRunning_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventIsRunning_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** Whether a step is currently running. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Whether a step is currently running." },
	};
#endif // WITH_METADATA

// ********** Begin Function IsRunning constinit property declarations *****************************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VrLinkComponent_eventIsRunning_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsRunning constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsRunning Property Definitions ****************************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(VrLinkComponent_eventIsRunning_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsRunning Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "IsRunning", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventIsRunning_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventIsRunning_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_IsRunning(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execIsRunning)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsRunning();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function IsRunning ****************************************

// ********** Begin Class UVrLinkComponent Function IsSessionActive ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_IsSessionActive_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventIsSessionActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** Whether a recording session is running right now. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Whether a recording session is running right now." },
	};
#endif // WITH_METADATA

// ********** Begin Function IsSessionActive constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VrLinkComponent_eventIsSessionActive_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSessionActive constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSessionActive Property Definitions **********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(VrLinkComponent_eventIsSessionActive_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsSessionActive Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "IsSessionActive", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventIsSessionActive_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventIsSessionActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_IsSessionActive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execIsSessionActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSessionActive();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function IsSessionActive **********************************

// ********** Begin Class UVrLinkComponent Function OnStartTriggerOverlap **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_OnStartTriggerOverlap_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventOnStartTriggerOverlap_Parms
	{
		AActor* OverlappedActor;
		AActor* OtherActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Comment", "/** Bound to StartTrigger's OnActorBeginOverlap when Start Mode is On Trigger; starts on first entry. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Bound to StartTrigger's OnActorBeginOverlap when Start Mode is On Trigger; starts on first entry." },
	};
#endif // WITH_METADATA

// ********** Begin Function OnStartTriggerOverlap constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnStartTriggerOverlap constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnStartTriggerOverlap Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OverlappedActor = { "OverlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventOnStartTriggerOverlap_Parms, OverlappedActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventOnStartTriggerOverlap_Parms, OtherActor), Z_Construct_UClass_AActor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OverlappedActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OtherActor,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OnStartTriggerOverlap Property Definitions ******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "OnStartTriggerOverlap", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventOnStartTriggerOverlap_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventOnStartTriggerOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_OnStartTriggerOverlap(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execOnStartTriggerOverlap)
{
	P_GET_OBJECT(AActor,Z_Param_OverlappedActor);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnStartTriggerOverlap(Z_Param_OverlappedActor,Z_Param_OtherActor);
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function OnStartTriggerOverlap ****************************

// ********** Begin Class UVrLinkComponent Function SendBaseline ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_SendBaseline_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventSendBaseline_Parms
	{
		FString Phase;
		bool bStart;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** Sends a `baseline.start` (bStart=true) or `baseline.end` event for the given phase. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Sends a `baseline.start` (bStart=true) or `baseline.end` event for the given phase." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Phase_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SendBaseline constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Phase;
	static void NewProp_bStart_SetBit(void* Obj)
	{
		((VrLinkComponent_eventSendBaseline_Parms*)Obj)->bStart = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStart;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SendBaseline constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SendBaseline Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Phase = { "Phase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventSendBaseline_Parms, Phase), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Phase_MetaData), NewProp_Phase_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bStart = { "bStart", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(VrLinkComponent_eventSendBaseline_Parms), &UHT_STATICS::NewProp_bStart_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Phase,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bStart,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SendBaseline Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "SendBaseline", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventSendBaseline_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventSendBaseline_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_SendBaseline(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execSendBaseline)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Phase);
	P_GET_UBOOL(Z_Param_bStart);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendBaseline(Z_Param_Phase,Z_Param_bStart);
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function SendBaseline *************************************

// ********** Begin Class UVrLinkComponent Function SendError **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_SendError_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventSendError_Parms
	{
		FString Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** Sends an `error` message to surface a failure to the operator. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Sends an `error` message to surface a failure to the operator." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SendError constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SendError constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SendError Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventSendError_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SendError Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "SendError", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventSendError_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventSendError_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_SendError(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execSendError)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendError(Z_Param_Message);
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function SendError ****************************************

// ********** Begin Class UVrLinkComponent Function SendMark ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_SendMark_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventSendMark_Parms
	{
		FString Label;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** Sends a `mark` (trigger/marker) event to Unity, which records it. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Sends a `mark` (trigger/marker) event to Unity, which records it." },
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
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventSendMark_Parms, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Label,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SendMark Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "SendMark", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventSendMark_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventSendMark_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_SendMark(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execSendMark)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Label);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendMark(Z_Param_Label);
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function SendMark *****************************************

// ********** Begin Class UVrLinkComponent Function SendState **************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_SendState_Statics
struct UHT_STATICS
{
	struct VrLinkComponent_eventSendState_Parms
	{
		FString Name;
		FString Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/**\n\x09 * Sends a `state` event (scene or variable change) to Unity, which records it:\n\x09 * a change with Name==\"Scene\" is a scene change, any other Name a variable change.\n\x09 */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Sends a `state` event (scene or variable change) to Unity, which records it:\na change with Name==\"Scene\" is a scene change, any other Name a variable change." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SendState constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SendState constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SendState Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventSendState_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(VrLinkComponent_eventSendState_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SendState Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "SendState", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::VrLinkComponent_eventSendState_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::VrLinkComponent_eventSendState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVrLinkComponent_SendState(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execSendState)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendState(Z_Param_Name,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function SendState ****************************************

// ********** Begin Class UVrLinkComponent Function StartExperience ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_StartExperience_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** Runs the experience from the first step. No-op if already running. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Runs the experience from the first step. No-op if already running." },
	};
#endif // WITH_METADATA

// ********** Begin Function StartExperience constinit property declarations ***********************
// ********** End Function StartExperience constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "StartExperience", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UVrLinkComponent_StartExperience(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execStartExperience)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartExperience();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function StartExperience **********************************

// ********** Begin Class UVrLinkComponent Function StartSession ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_StartSession_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/**\n\x09 * Starts a session from the VR side (spec \xc3\x82\xc2\xa7""4 case B). Sends `session.start`\n\x09 * with a null sessionId; Unity mints the id and returns it in `session.started`.\n\x09 */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Starts a session from the VR side (spec \xc3\x82\xc2\xa7""4 case B). Sends `session.start`\nwith a null sessionId; Unity mints the id and returns it in `session.started`." },
	};
#endif // WITH_METADATA

// ********** Begin Function StartSession constinit property declarations **************************
// ********** End Function StartSession constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "StartSession", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UVrLinkComponent_StartSession(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execStartSession)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartSession();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function StartSession *************************************

// ********** Begin Class UVrLinkComponent Function StopExperience *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UVrLinkComponent_StopExperience_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** Stops immediately, ending the current step so a baseline is never left open. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Stops immediately, ending the current step so a baseline is never left open." },
	};
#endif // WITH_METADATA

// ********** Begin Function StopExperience constinit property declarations ************************
// ********** End Function StopExperience constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UVrLinkComponent, nullptr, "StopExperience", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_UVrLinkComponent_StopExperience(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UVrLinkComponent::execStopExperience)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopExperience();
	P_NATIVE_END;
}
// ********** End Class UVrLinkComponent Function StopExperience ***********************************

// ********** Begin Class UVrLinkComponent *********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UVrLinkComponent_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "Comment", "/**\n * Runs the experience and speaks the vrlink v1.1 protocol to the Unity recorder.\n *\n * This is the only component you need. Put it on one actor in the level, fill in\n * the Steps table, and bind OnStepStarted / OnStepEnded to drive the visuals.\n *\n * Setup:\n *  1. Add this component to an actor in the level.\n *  2. Fill in Steps, one entry per phase the participant goes through.\n *  3. Pick an AdvanceMode: Duration, TriggerVolume, or Manual.\n *  4. Bind OnStepStarted and OnStepEnded in Blueprint.\n *\n * The Steps table is the single source of truth. The `welcome` handshake derives\n * its scene list from the distinct Locations and its variable list from the\n * distinct Scenarios, so what the tablet is told and what the events record are\n * always the same names.\n *\n * All three advance modes run the same Steps and emit the same events; only the\n * caller of GoToNextStep differs, so a run stepped through manually records\n * identically to one driven by trigger volumes.\n *\n * Transport is ATCPSocket / NetworkManager. Unity owns the event log and the\n * session clock: it receives the scene/variable/baseline events over vrlink and\n * records them. The one file this side writes is `{SessionId}_gaze.csv`, and only\n * if a UGazeRecorder is in the level; this component just publishes the session\n * state that recorder needs.\n */" },
		{ "DisplayName", "VR Link" },
		{ "IncludePath", "VrLinkComponent.h" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Runs the experience and speaks the vrlink v1.1 protocol to the Unity recorder.\n\nThis is the only component you need. Put it on one actor in the level, fill in\nthe Steps table, and bind OnStepStarted / OnStepEnded to drive the visuals.\n\nSetup:\n 1. Add this component to an actor in the level.\n 2. Fill in Steps, one entry per phase the participant goes through.\n 3. Pick an AdvanceMode: Duration, TriggerVolume, or Manual.\n 4. Bind OnStepStarted and OnStepEnded in Blueprint.\n\nThe Steps table is the single source of truth. The `welcome` handshake derives\nits scene list from the distinct Locations and its variable list from the\ndistinct Scenarios, so what the tablet is told and what the events record are\nalways the same names.\n\nAll three advance modes run the same Steps and emit the same events; only the\ncaller of GoToNextStep differs, so a run stepped through manually records\nidentically to one driven by trigger volumes.\n\nTransport is ATCPSocket / NetworkManager. Unity owns the event log and the\nsession clock: it receives the scene/variable/baseline events over vrlink and\nrecords them. The one file this side writes is `{SessionId}_gaze.csv`, and only\nif a UGazeRecorder is in the level; this component just publishes the session\nstate that recorder needs." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Steps_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** The steps, in order. Add an entry to add a location or scenario. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "TitleProperty", "Scenario" },
		{ "ToolTip", "The steps, in order. Add an entry to add a location or scenario." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdvanceMode_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** What advances the timeline to the next step. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "What advances the timeline to the next step." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ManualAdvanceKey_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** Key or controller button that advances the timeline. Only used when AdvanceMode is Manual. */" },
		{ "EditCondition", "AdvanceMode == EStepAdvanceMode::Manual" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Key or controller button that advances the timeline. Only used when AdvanceMode is Manual." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartMode_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** What starts the experience: automatically on play, or waiting for a trigger. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "What starts the experience: automatically on play, or waiting for a trigger." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StartTrigger_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/**\n\x09 * Optional, only used when Start Mode is On Trigger. Drop a Trigger Box (or any actor that fires\n\x09 * overlap events) here and the experience starts the first time the participant enters it, with no\n\x09 * Blueprint at all. Leave empty to start it yourself by calling Start Experience from Blueprint.\n\x09 */" },
		{ "EditCondition", "StartMode == EExperienceStartMode::OnTrigger" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Optional, only used when Start Mode is On Trigger. Drop a Trigger Box (or any actor that fires\noverlap events) here and the experience starts the first time the participant enters it, with no\nBlueprint at all. Leave empty to start it yourself by calling Start Experience from Blueprint." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStepStarted_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** Fired as a step begins, after its events are sent. Bind visuals here. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Fired as a step begins, after its events are sent. Bind visuals here." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnStepEnded_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** Fired as a step ends, before the fade delay. Bind fade-outs here. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Fired as a step ends, before the fade delay. Bind fade-outs here." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnExperienceFinished_MetaData[] = {
		{ "Category", "Experience" },
		{ "Comment", "/** Fired once after the final step ends. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Fired once after the final step ends." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnRecordingStarted_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/**\n\x09 * Fired when the recording session starts: the tablet operator's Start Recording (its session.start),\n\x09 * or a VR-initiated start. Bind this in Blueprint to begin environment movement or visuals the moment\n\x09 * recording begins, independently of the Steps timeline.\n\x09 */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "Fired when the recording session starts: the tablet operator's Start Recording (its session.start),\nor a VR-initiated start. Bind this in Blueprint to begin environment movement or visuals the moment\nrecording begins, independently of the Steps timeline." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Socket_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** The transport actor. If left null it is auto-discovered in the level on BeginPlay. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "The transport actor. If left null it is auto-discovered in the level on BeginPlay." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StudyConfig_MetaData[] = {
		{ "Category", "VrLink" },
		{ "Comment", "/** The study definition handed to Unity in `welcome`. Scenes and variables come from Steps. */" },
		{ "ModuleRelativePath", "Public/VrLinkComponent.h" },
		{ "ToolTip", "The study definition handed to Unity in `welcome`. Scenes and variables come from Steps." },
	};
#endif // WITH_METADATA

// ********** Begin Class UVrLinkComponent constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Steps_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Steps;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AdvanceMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AdvanceMode;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ManualAdvanceKey;
	static const UECodeGen_Private::FBytePropertyParams NewProp_StartMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_StartMode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StartTrigger;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStepStarted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnStepEnded;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnExperienceFinished;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRecordingStarted;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Socket;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StudyConfig;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UVrLinkComponent constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("EndSession"), .Pointer = &UVrLinkComponent::execEndSession },
		{ .NameUTF8 = UTF8TEXT("GetCurrentScene"), .Pointer = &UVrLinkComponent::execGetCurrentScene },
		{ .NameUTF8 = UTF8TEXT("GetCurrentStepIndex"), .Pointer = &UVrLinkComponent::execGetCurrentStepIndex },
		{ .NameUTF8 = UTF8TEXT("GetSessionElapsedSeconds"), .Pointer = &UVrLinkComponent::execGetSessionElapsedSeconds },
		{ .NameUTF8 = UTF8TEXT("GetSessionFolder"), .Pointer = &UVrLinkComponent::execGetSessionFolder },
		{ .NameUTF8 = UTF8TEXT("GetSessionId"), .Pointer = &UVrLinkComponent::execGetSessionId },
		{ .NameUTF8 = UTF8TEXT("GoToNextStep"), .Pointer = &UVrLinkComponent::execGoToNextStep },
		{ .NameUTF8 = UTF8TEXT("HandleLine"), .Pointer = &UVrLinkComponent::execHandleLine },
		{ .NameUTF8 = UTF8TEXT("IsRunning"), .Pointer = &UVrLinkComponent::execIsRunning },
		{ .NameUTF8 = UTF8TEXT("IsSessionActive"), .Pointer = &UVrLinkComponent::execIsSessionActive },
		{ .NameUTF8 = UTF8TEXT("OnStartTriggerOverlap"), .Pointer = &UVrLinkComponent::execOnStartTriggerOverlap },
		{ .NameUTF8 = UTF8TEXT("SendBaseline"), .Pointer = &UVrLinkComponent::execSendBaseline },
		{ .NameUTF8 = UTF8TEXT("SendError"), .Pointer = &UVrLinkComponent::execSendError },
		{ .NameUTF8 = UTF8TEXT("SendMark"), .Pointer = &UVrLinkComponent::execSendMark },
		{ .NameUTF8 = UTF8TEXT("SendState"), .Pointer = &UVrLinkComponent::execSendState },
		{ .NameUTF8 = UTF8TEXT("StartExperience"), .Pointer = &UVrLinkComponent::execStartExperience },
		{ .NameUTF8 = UTF8TEXT("StartSession"), .Pointer = &UVrLinkComponent::execStartSession },
		{ .NameUTF8 = UTF8TEXT("StopExperience"), .Pointer = &UVrLinkComponent::execStopExperience },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UVrLinkComponent_EndSession, "EndSession" }, // 772eda82e25909c7a683e8d18f1f6cd518872896
		{ &Z_Construct_UFunction_UVrLinkComponent_GetCurrentScene, "GetCurrentScene" }, // 8ce66cca549ae40f30f90fc87142384435a1eca3
		{ &Z_Construct_UFunction_UVrLinkComponent_GetCurrentStepIndex, "GetCurrentStepIndex" }, // 2fbf1d6a47f49597d21e4e70256d3ce93d5241df
		{ &Z_Construct_UFunction_UVrLinkComponent_GetSessionElapsedSeconds, "GetSessionElapsedSeconds" }, // bb53422c36bd4820a263f15bc43a3e610683ac4f
		{ &Z_Construct_UFunction_UVrLinkComponent_GetSessionFolder, "GetSessionFolder" }, // ddcaa66034769941452f313e274d367e31ec141a
		{ &Z_Construct_UFunction_UVrLinkComponent_GetSessionId, "GetSessionId" }, // 42f363c3661905a7b0fd9d676d48392759ca3aab
		{ &Z_Construct_UFunction_UVrLinkComponent_GoToNextStep, "GoToNextStep" }, // 6de83ce8a0dd4f5158a3d852aa7ae13ad8851902
		{ &Z_Construct_UFunction_UVrLinkComponent_HandleLine, "HandleLine" }, // f3cee7b055480e3be68d78d2b5f321167414dec1
		{ &Z_Construct_UFunction_UVrLinkComponent_IsRunning, "IsRunning" }, // 6eeeb9a91d0077d942449e9bd2963fc721ffe754
		{ &Z_Construct_UFunction_UVrLinkComponent_IsSessionActive, "IsSessionActive" }, // 6d56e894ed2a205ea601dcc1854c7aa032c2665f
		{ &Z_Construct_UFunction_UVrLinkComponent_OnStartTriggerOverlap, "OnStartTriggerOverlap" }, // 289a9b6914a4264c1f0920595e774a0c65938cb7
		{ &Z_Construct_UFunction_UVrLinkComponent_SendBaseline, "SendBaseline" }, // efb9ebdc47673966399a3a3ec5d33e2b1fd60979
		{ &Z_Construct_UFunction_UVrLinkComponent_SendError, "SendError" }, // 42fa9b6eebd3587033151fe2ed0749f86b72e42e
		{ &Z_Construct_UFunction_UVrLinkComponent_SendMark, "SendMark" }, // d0d604de41a06c5248bae186d87850a3ea58cbb4
		{ &Z_Construct_UFunction_UVrLinkComponent_SendState, "SendState" }, // 151db3ac037b4c80239767fd0ceb5a2473926986
		{ &Z_Construct_UFunction_UVrLinkComponent_StartExperience, "StartExperience" }, // e972a6652f9c06dd564da74b6044682be2c0f336
		{ &Z_Construct_UFunction_UVrLinkComponent_StartSession, "StartSession" }, // 2468926988b6f2fc7b2fa627b7b7aefc56fee026
		{ &Z_Construct_UFunction_UVrLinkComponent_StopExperience, "StopExperience" }, // addfdc4e8921cfa6cb78c391e22777f464c64190
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVrLinkComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UVrLinkComponent Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Steps_Inner = { "Steps", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FExperienceStep, METADATA_PARAMS(0, nullptr) }; // 8944b8b00035714b9febbbf8abb6c90d43dbd6ff
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Steps = { "Steps", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, Steps), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Steps_MetaData), NewProp_Steps_MetaData) }; // 8944b8b00035714b9febbbf8abb6c90d43dbd6ff
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_AdvanceMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_AdvanceMode = { "AdvanceMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, AdvanceMode), Z_Construct_UEnum_VrLink_EStepAdvanceMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdvanceMode_MetaData), NewProp_AdvanceMode_MetaData) }; // 4ad93f299ad4f2e64910ce6fd182faf2ea2e5a70
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ManualAdvanceKey = { "ManualAdvanceKey", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, ManualAdvanceKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ManualAdvanceKey_MetaData), NewProp_ManualAdvanceKey_MetaData) }; // 64b3e4afc222613fc56ee34bd705dda53a3378d0
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_StartMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams UHT_STATICS::NewProp_StartMode = { "StartMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, StartMode), Z_Construct_UEnum_VrLink_EExperienceStartMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartMode_MetaData), NewProp_StartMode_MetaData) }; // 414df07326e48e01773fc1fade91930863ec403f
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_StartTrigger = { "StartTrigger", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, StartTrigger), Z_Construct_UClass_AActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StartTrigger_MetaData), NewProp_StartTrigger_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnStepStarted = { "OnStepStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, OnStepStarted), Z_Construct_UDelegateFunction_VrLink_ExperienceStepStarted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStepStarted_MetaData), NewProp_OnStepStarted_MetaData) }; // ceba5095657f04fbaa042df55582a4e5732db61e
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnStepEnded = { "OnStepEnded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, OnStepEnded), Z_Construct_UDelegateFunction_VrLink_ExperienceStepEnded__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnStepEnded_MetaData), NewProp_OnStepEnded_MetaData) }; // 06fc959b921510bd1bf509d6a20db087a37122a0
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnExperienceFinished = { "OnExperienceFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, OnExperienceFinished), Z_Construct_UDelegateFunction_VrLink_ExperienceFinished__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnExperienceFinished_MetaData), NewProp_OnExperienceFinished_MetaData) }; // aabfea2b1cc3b34406cce1f6c76bd1c3416836ec
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnRecordingStarted = { "OnRecordingStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, OnRecordingStarted), Z_Construct_UDelegateFunction_VrLink_RecordingStarted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnRecordingStarted_MetaData), NewProp_OnRecordingStarted_MetaData) }; // 89f3ba303badde1a21bd9d5869d7131b713d7825
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Socket = { "Socket", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, Socket), Z_Construct_UClass_ATCPSocket, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Socket_MetaData), NewProp_Socket_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_StudyConfig = { "StudyConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(UVrLinkComponent, StudyConfig), Z_Construct_UScriptStruct_FVrLinkStudyConfig, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StudyConfig_MetaData), NewProp_StudyConfig_MetaData) }; // 986a447181f2d0d0b02c34e5372c1ad3afd27532
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Steps_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Steps,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AdvanceMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AdvanceMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ManualAdvanceKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StartTrigger,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnStepStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnStepEnded,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnExperienceFinished,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnRecordingStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Socket,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StudyConfig,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UVrLinkComponent Property Definitions **************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UActorComponent,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UVrLinkComponent,
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
static void UVrLinkComponent_StaticRegisterNativesUVrLinkComponent()
{
	UClass* Class = UVrLinkComponent::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UVrLinkComponent;
UClass* Z_Construct_UClass_UVrLinkComponent(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UVrLinkComponent;
		if (!Z_Registration_Info_UClass_UVrLinkComponent.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("VrLinkComponent"),
				Z_Registration_Info_UClass_UVrLinkComponent.InnerSingleton,
				UVrLinkComponent_StaticRegisterNativesUVrLinkComponent,
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
		return Z_Registration_Info_UClass_UVrLinkComponent.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UVrLinkComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVrLinkComponent.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UVrLinkComponent.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UVrLinkComponent);
UVrLinkComponent::~UVrLinkComponent() {}
// ********** End Class UVrLinkComponent ***********************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h__Script_VrLink_Statics
struct UHT_STATICS
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ Z_Construct_UEnum_VrLink_EStepKind, TEXT("EStepKind"), &ZRIE_EStepKind, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3042072418U) },
		{ Z_Construct_UEnum_VrLink_EStepAdvanceMode, TEXT("EStepAdvanceMode"), &ZRIE_EStepAdvanceMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1255751465U) },
		{ Z_Construct_UEnum_VrLink_EExperienceStartMode, TEXT("EExperienceStartMode"), &ZRIE_EExperienceStartMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1095626867U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FExperienceStep, Z_Construct_UScriptStruct_FExperienceStep_Statics::NewStructOps, TEXT("ExperienceStep"),&Z_Registration_Info_UScriptStruct_FExperienceStep, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FExperienceStep), 2302982320U) },
		{ Z_Construct_UScriptStruct_FVrLinkVariable, Z_Construct_UScriptStruct_FVrLinkVariable_Statics::NewStructOps, TEXT("VrLinkVariable"),&Z_Registration_Info_UScriptStruct_FVrLinkVariable, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVrLinkVariable), 1001822428U) },
		{ Z_Construct_UScriptStruct_FVrLinkStudyConfig, Z_Construct_UScriptStruct_FVrLinkStudyConfig_Statics::NewStructOps, TEXT("VrLinkStudyConfig"),&Z_Registration_Info_UScriptStruct_FVrLinkStudyConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVrLinkStudyConfig), 2557101169U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UVrLinkComponent, TEXT("UVrLinkComponent"), &Z_Registration_Info_UClass_UVrLinkComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVrLinkComponent), 2524897179U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h__Script_VrLink_eb28090028e0ea41405ee1adc827b25f0641d374{
	TEXT("/Script/VrLink"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	UHT_STATICS::EnumInfo, UE_ARRAY_COUNT(UHT_STATICS::EnumInfo),
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
