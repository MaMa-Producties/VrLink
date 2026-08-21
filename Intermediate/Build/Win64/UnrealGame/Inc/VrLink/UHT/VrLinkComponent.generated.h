// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VrLinkComponent.h"

#ifdef VRLINK_VrLinkComponent_generated_h
#error "VrLinkComponent.generated.h already included, missing '#pragma once' in VrLinkComponent.h"
#endif
#define VRLINK_VrLinkComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
enum class EStepKind : uint8;

// ********** Begin ScriptStruct FExperienceStep ***************************************************
struct Z_Construct_UScriptStruct_FExperienceStep_Statics;
VRLINK_API UScriptStruct* Z_Construct_UScriptStruct_FExperienceStep(ETypeConstructPhase);

#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_64_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FExperienceStep_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FExperienceStep(ETypeConstructPhase::Inner); }


struct FExperienceStep;
// ********** End ScriptStruct FExperienceStep *****************************************************

// ********** Begin ScriptStruct FVrLinkVariable ***************************************************
struct Z_Construct_UScriptStruct_FVrLinkVariable_Statics;
VRLINK_API UScriptStruct* Z_Construct_UScriptStruct_FVrLinkVariable(ETypeConstructPhase);

#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_98_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FVrLinkVariable_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FVrLinkVariable(ETypeConstructPhase::Inner); }


struct FVrLinkVariable;
// ********** End ScriptStruct FVrLinkVariable *****************************************************

// ********** Begin ScriptStruct FVrLinkStudyConfig ************************************************
struct Z_Construct_UScriptStruct_FVrLinkStudyConfig_Statics;
VRLINK_API UScriptStruct* Z_Construct_UScriptStruct_FVrLinkStudyConfig(ETypeConstructPhase);

#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_117_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FVrLinkStudyConfig_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FVrLinkStudyConfig(ETypeConstructPhase::Inner); }


struct FVrLinkStudyConfig;
// ********** End ScriptStruct FVrLinkStudyConfig **************************************************

// ********** Begin Class UVrLinkComponent *********************************************************
#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_179_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleLine); \
	DECLARE_FUNCTION(execOnStartTriggerOverlap); \
	DECLARE_FUNCTION(execGetCurrentScene); \
	DECLARE_FUNCTION(execGetSessionElapsedSeconds); \
	DECLARE_FUNCTION(execIsSessionActive); \
	DECLARE_FUNCTION(execGetSessionFolder); \
	DECLARE_FUNCTION(execGetSessionId); \
	DECLARE_FUNCTION(execSendError); \
	DECLARE_FUNCTION(execSendMark); \
	DECLARE_FUNCTION(execSendBaseline); \
	DECLARE_FUNCTION(execSendState); \
	DECLARE_FUNCTION(execEndSession); \
	DECLARE_FUNCTION(execStartSession); \
	DECLARE_FUNCTION(execIsRunning); \
	DECLARE_FUNCTION(execGetCurrentStepIndex); \
	DECLARE_FUNCTION(execGoToNextStep); \
	DECLARE_FUNCTION(execStopExperience); \
	DECLARE_FUNCTION(execStartExperience);


struct Z_Construct_UClass_UVrLinkComponent_Statics;
VRLINK_API UClass* Z_Construct_UClass_UVrLinkComponent(ETypeConstructPhase);

#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_179_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UVrLinkComponent_Statics; \
	friend VRLINK_API UClass* ::Z_Construct_UClass_UVrLinkComponent(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UVrLinkComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VrLink"), Z_Construct_UClass_UVrLinkComponent) \
	DECLARE_SERIALIZER(UVrLinkComponent)


#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_179_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UVrLinkComponent(UVrLinkComponent&&) = delete; \
	UVrLinkComponent(const UVrLinkComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVrLinkComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVrLinkComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVrLinkComponent) \
	NO_API virtual ~UVrLinkComponent();


#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_176_PROLOG
#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_179_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_179_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_179_INCLASS_NO_PURE_DECLS \
	FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h_179_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UVrLinkComponent;

// ********** End Class UVrLinkComponent ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkComponent_h

// ********** Begin Enum EStepKind *****************************************************************
#define FOREACH_ENUM_ESTEPKIND(op) \
	op(EStepKind::SettleIn) \
	op(EStepKind::Baseline) \
	op(EStepKind::Scenario) 

enum class EStepKind : uint8;
template<> struct TIsUEnumClass<EStepKind> { enum { Value = true }; };
template<> UE_NODEBUG VRLINK_NON_ATTRIBUTED_API UEnum* StaticEnum<EStepKind>();
// ********** End Enum EStepKind *******************************************************************

// ********** Begin Enum EStepAdvanceMode **********************************************************
#define FOREACH_ENUM_ESTEPADVANCEMODE(op) \
	op(EStepAdvanceMode::Duration) \
	op(EStepAdvanceMode::TriggerVolume) \
	op(EStepAdvanceMode::Manual) 

enum class EStepAdvanceMode : uint8;
template<> struct TIsUEnumClass<EStepAdvanceMode> { enum { Value = true }; };
template<> UE_NODEBUG VRLINK_NON_ATTRIBUTED_API UEnum* StaticEnum<EStepAdvanceMode>();
// ********** End Enum EStepAdvanceMode ************************************************************

// ********** Begin Enum EExperienceStartMode ******************************************************
#define FOREACH_ENUM_EEXPERIENCESTARTMODE(op) \
	op(EExperienceStartMode::OnBeginPlay) \
	op(EExperienceStartMode::OnTrigger) \
	op(EExperienceStartMode::OnTabletStart) 

enum class EExperienceStartMode : uint8;
template<> struct TIsUEnumClass<EExperienceStartMode> { enum { Value = true }; };
template<> UE_NODEBUG VRLINK_NON_ATTRIBUTED_API UEnum* StaticEnum<EExperienceStartMode>();
// ********** End Enum EExperienceStartMode ********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
