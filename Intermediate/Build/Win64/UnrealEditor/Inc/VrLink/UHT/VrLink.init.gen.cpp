// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVrLink_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
	VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_ExperienceFinished__DelegateSignature(ETypeConstructPhase);
	VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_ExperienceStepEnded__DelegateSignature(ETypeConstructPhase);
	VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_ExperienceStepStarted__DelegateSignature(ETypeConstructPhase);
	VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_NetworkDelegate__DelegateSignature(ETypeConstructPhase);
	VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_RecordingStarted__DelegateSignature(ETypeConstructPhase);
	VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_SocketDelegate__DelegateSignature(ETypeConstructPhase);
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VrLink;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase)
	{
		if (!Z_Registration_Info_UPackage__Script_VrLink.OuterSingleton)
		{
		static FTypeConstructFunc* SingletonFuncArray[] = {
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_VrLink_ExperienceFinished__DelegateSignature,
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_VrLink_ExperienceStepEnded__DelegateSignature,
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_VrLink_ExperienceStepStarted__DelegateSignature,
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_VrLink_NetworkDelegate__DelegateSignature,
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_VrLink_RecordingStarted__DelegateSignature,
			(FTypeConstructFunc*)Z_Construct_UDelegateFunction_VrLink_SocketDelegate__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/VrLink",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0xC7A677B3,
			0xFF66AC43,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VrLink.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_VrLink.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VrLink(Z_Construct_UPackage__Script_VrLink, TEXT("/Script/VrLink"), Z_Registration_Info_UPackage__Script_VrLink, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xC7A677B3, 0xFF66AC43));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
