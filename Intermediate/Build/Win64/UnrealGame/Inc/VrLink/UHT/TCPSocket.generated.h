// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TCPSocket.h"

#ifdef VRLINK_TCPSocket_generated_h
#error "TCPSocket.generated.h already included, missing '#pragma once' in TCPSocket.h"
#endif
#define VRLINK_TCPSocket_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ATCPSocket ***************************************************************
#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsSocketConnected); \
	DECLARE_FUNCTION(execReceiveMessage); \
	DECLARE_FUNCTION(execSendMessage); \
	DECLARE_FUNCTION(execStopServer); \
	DECLARE_FUNCTION(execStartServer);


struct Z_Construct_UClass_ATCPSocket_Statics;
VRLINK_API UClass* Z_Construct_UClass_ATCPSocket(ETypeConstructPhase);

#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h_13_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ATCPSocket_Statics; \
	friend VRLINK_API UClass* ::Z_Construct_UClass_ATCPSocket(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ATCPSocket, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VrLink"), Z_Construct_UClass_ATCPSocket) \
	DECLARE_SERIALIZER(ATCPSocket)


#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ATCPSocket(ATCPSocket&&) = delete; \
	ATCPSocket(const ATCPSocket&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATCPSocket); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATCPSocket); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATCPSocket) \
	NO_API virtual ~ATCPSocket();


#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h_10_PROLOG
#define FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h_13_INCLASS_NO_PURE_DECLS \
	FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ATCPSocket;

// ********** End Class ATCPSocket *****************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
