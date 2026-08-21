// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VrLinkSubsystem.h"

#ifdef VRLINK_VrLinkSubsystem_generated_h
#error "VrLinkSubsystem.generated.h already included, missing '#pragma once' in VrLinkSubsystem.h"
#endif
#define VRLINK_VrLinkSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UVrLinkSubsystem *********************************************************
#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSendBaselinePhase); \
	DECLARE_FUNCTION(execGetSessionId); \
	DECLARE_FUNCTION(execIsSessionActive); \
	DECLARE_FUNCTION(execSendMark); \
	DECLARE_FUNCTION(execSetScenario); \
	DECLARE_FUNCTION(execSetLocation); \
	DECLARE_FUNCTION(execEndSession); \
	DECLARE_FUNCTION(execStartSession); \
	DECLARE_FUNCTION(execInitializeVrLink);


struct Z_Construct_UClass_UVrLinkSubsystem_Statics;
VRLINK_API UClass* Z_Construct_UClass_UVrLinkSubsystem(ETypeConstructPhase);

#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h_42_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UVrLinkSubsystem_Statics; \
	friend VRLINK_API UClass* ::Z_Construct_UClass_UVrLinkSubsystem(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UVrLinkSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VrLink"), Z_Construct_UClass_UVrLinkSubsystem) \
	DECLARE_SERIALIZER(UVrLinkSubsystem)


#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h_42_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVrLinkSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UVrLinkSubsystem(UVrLinkSubsystem&&) = delete; \
	UVrLinkSubsystem(const UVrLinkSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVrLinkSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVrLinkSubsystem); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVrLinkSubsystem) \
	NO_API virtual ~UVrLinkSubsystem();


#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h_39_PROLOG
#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h_42_INCLASS_NO_PURE_DECLS \
	FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UVrLinkSubsystem;

// ********** End Class UVrLinkSubsystem ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_VrLinkSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
