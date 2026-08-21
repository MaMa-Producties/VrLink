// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TCPSocket.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeTCPSocket() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_VrLink(ETypeConstructPhase);
VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_NetworkDelegate__DelegateSignature(ETypeConstructPhase);
VRLINK_API UFunction* Z_Construct_UDelegateFunction_VrLink_SocketDelegate__DelegateSignature(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_ATCPSocket(ETypeConstructPhase);
VRLINK_API UClass* Z_Construct_UClass_ATCPSocket(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Delegate FNetworkDelegate ******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_VrLink_NetworkDelegate__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_VrLink_eventNetworkDelegate_Parms
	{
		TArray<uint8> Data;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FNetworkDelegate constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Data_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Data;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FNetworkDelegate constinit property declarations ************************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FNetworkDelegate Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Data_Inner = { "Data", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventNetworkDelegate_Parms, Data), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Data_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Data,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FNetworkDelegate Property Definitions ***********************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink, nullptr, "NetworkDelegate__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_VrLink_eventNetworkDelegate_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_VrLink_eventNetworkDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_VrLink_NetworkDelegate__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FNetworkDelegate ********************************************************

// ********** Begin Delegate FSocketDelegate *******************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UDelegateFunction_VrLink_SocketDelegate__DelegateSignature_Statics
struct UHT_STATICS
{
	struct _Script_VrLink_eventSocketDelegate_Parms
	{
		FString Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FSocketDelegate constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FSocketDelegate constinit property declarations *************************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FSocketDelegate Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VrLink_eventSocketDelegate_Parms, Message), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Delegate FSocketDelegate Property Definitions ************************************
const UECodeGen_Private::FDelegateFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink, nullptr, "SocketDelegate__DelegateSignature", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::_Script_VrLink_eventSocketDelegate_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::_Script_VrLink_eventSocketDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_VrLink_SocketDelegate__DelegateSignature(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
// ********** End Delegate FSocketDelegate *********************************************************

// ********** Begin Class ATCPSocket Function IsSocketConnected ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ATCPSocket_IsSocketConnected_Statics
struct UHT_STATICS
{
	struct TCPSocket_eventIsSocketConnected_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsSocketConnected constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((TCPSocket_eventIsSocketConnected_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSocketConnected constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSocketConnected Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(TCPSocket_eventIsSocketConnected_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function IsSocketConnected Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ATCPSocket, nullptr, "IsSocketConnected", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TCPSocket_eventIsSocketConnected_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TCPSocket_eventIsSocketConnected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATCPSocket_IsSocketConnected(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ATCPSocket::execIsSocketConnected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSocketConnected();
	P_NATIVE_END;
}
// ********** End Class ATCPSocket Function IsSocketConnected **************************************

// ********** Begin Class ATCPSocket Function ReceiveMessage ***************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ATCPSocket_ReceiveMessage_Statics
struct UHT_STATICS
{
	struct TCPSocket_eventReceiveMessage_Parms
	{
		TArray<uint8> Data;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ReceiveMessage constinit property declarations ************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Data_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Data;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ReceiveMessage constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ReceiveMessage Property Definitions ***********************************
const UECodeGen_Private::FBytePropertyParams UHT_STATICS::NewProp_Data_Inner = { "Data", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(TCPSocket_eventReceiveMessage_Parms, Data), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Data_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Data,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ReceiveMessage Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ATCPSocket, nullptr, "ReceiveMessage", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TCPSocket_eventReceiveMessage_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TCPSocket_eventReceiveMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATCPSocket_ReceiveMessage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ATCPSocket::execReceiveMessage)
{
	P_GET_TARRAY(uint8,Z_Param_Data);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ReceiveMessage(Z_Param_Data);
	P_NATIVE_END;
}
// ********** End Class ATCPSocket Function ReceiveMessage *****************************************

// ********** Begin Class ATCPSocket Function SendMessage ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ATCPSocket_SendMessage_Statics
struct UHT_STATICS
{
	struct TCPSocket_eventSendMessage_Parms
	{
		FString Message;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SendMessage constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SendMessage constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SendMessage Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(TCPSocket_eventSendMessage_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SendMessage Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ATCPSocket, nullptr, "SendMessage", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::TCPSocket_eventSendMessage_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::TCPSocket_eventSendMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATCPSocket_SendMessage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ATCPSocket::execSendMessage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SendMessage(Z_Param_Message);
	P_NATIVE_END;
}
// ********** End Class ATCPSocket Function SendMessage ********************************************

// ********** Begin Class ATCPSocket Function StartServer ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ATCPSocket_StartServer_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartServer constinit property declarations ***************************
// ********** End Function StartServer constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ATCPSocket, nullptr, "StartServer", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ATCPSocket_StartServer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ATCPSocket::execStartServer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartServer();
	P_NATIVE_END;
}
// ********** End Class ATCPSocket Function StartServer ********************************************

// ********** Begin Class ATCPSocket Function StopServer *******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ATCPSocket_StopServer_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StopServer constinit property declarations ****************************
// ********** End Function StopServer constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ATCPSocket, nullptr, "StopServer", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ATCPSocket_StopServer(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ATCPSocket::execStopServer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StopServer();
	P_NATIVE_END;
}
// ********** End Class ATCPSocket Function StopServer *********************************************

// ********** Begin Class ATCPSocket ***************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ATCPSocket_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "TCPSocket.h" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IPAddress_MetaData[] = {
		{ "Category", "VR Link" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Port_MetaData[] = {
		{ "Category", "VR Link" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisconnectOnExit_MetaData[] = {
		{ "Category", "VR Link" },
		{ "Comment", "/**\n\x09 * Stop the server when this actor leaves play (end of PIE / level change). Leaving it\n\x09 * running turns the port into a zombie: it accepts connections but nothing answers, and\n\x09 * the next play session binds a duplicate listener next to it.\n\x09 */" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
		{ "ToolTip", "Stop the server when this actor leaves play (end of PIE / level change). Leaving it\nrunning turns the port into a zombie: it accepts connections but nothing answers, and\nthe next play session binds a duplicate listener next to it." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrintMessages_MetaData[] = {
		{ "Category", "VR Link" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConnectOnStart_MetaData[] = {
		{ "Category", "VR Link" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnMessageReceived_MetaData[] = {
		{ "Category", "Socket" },
		{ "ModuleRelativePath", "Public/TCPSocket.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ATCPSocket constinit property declarations *******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_IPAddress;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Port;
	static void NewProp_DisconnectOnExit_SetBit(void* Obj)
	{
		((ATCPSocket*)Obj)->DisconnectOnExit = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_DisconnectOnExit;
	static void NewProp_PrintMessages_SetBit(void* Obj)
	{
		((ATCPSocket*)Obj)->PrintMessages = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_PrintMessages;
	static void NewProp_ConnectOnStart_SetBit(void* Obj)
	{
		((ATCPSocket*)Obj)->ConnectOnStart = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ConnectOnStart;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMessageReceived;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ATCPSocket constinit property declarations *********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("IsSocketConnected"), .Pointer = &ATCPSocket::execIsSocketConnected },
		{ .NameUTF8 = UTF8TEXT("ReceiveMessage"), .Pointer = &ATCPSocket::execReceiveMessage },
		{ .NameUTF8 = UTF8TEXT("SendMessage"), .Pointer = &ATCPSocket::execSendMessage },
		{ .NameUTF8 = UTF8TEXT("StartServer"), .Pointer = &ATCPSocket::execStartServer },
		{ .NameUTF8 = UTF8TEXT("StopServer"), .Pointer = &ATCPSocket::execStopServer },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATCPSocket_IsSocketConnected, "IsSocketConnected" }, // cd35b6cd133f5c5f95a921fb73053c4d4f3da319
		{ &Z_Construct_UFunction_ATCPSocket_ReceiveMessage, "ReceiveMessage" }, // 53626644f856ba8e7b1c370054fa6c25bfe24ed0
		{ &Z_Construct_UFunction_ATCPSocket_SendMessage, "SendMessage" }, // 01a914698ab600f0a6751299a954a52657414c9f
		{ &Z_Construct_UFunction_ATCPSocket_StartServer, "StartServer" }, // 72ef7a979c94030d747780715495ffe3e681d3d1
		{ &Z_Construct_UFunction_ATCPSocket_StopServer, "StopServer" }, // dcb6b6e465d42f96dd4277808543b9b0350f96eb
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATCPSocket>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ATCPSocket Property Definitions ******************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_IPAddress = { "IPAddress", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ATCPSocket, IPAddress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IPAddress_MetaData), NewProp_IPAddress_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ATCPSocket, Port), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Port_MetaData), NewProp_Port_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_DisconnectOnExit = { "DisconnectOnExit", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ATCPSocket), &UHT_STATICS::NewProp_DisconnectOnExit_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisconnectOnExit_MetaData), NewProp_DisconnectOnExit_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_PrintMessages = { "PrintMessages", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ATCPSocket), &UHT_STATICS::NewProp_PrintMessages_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrintMessages_MetaData), NewProp_PrintMessages_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ConnectOnStart = { "ConnectOnStart", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ATCPSocket), &UHT_STATICS::NewProp_ConnectOnStart_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConnectOnStart_MetaData), NewProp_ConnectOnStart_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams UHT_STATICS::NewProp_OnMessageReceived = { "OnMessageReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, nullptr, nullptr, 1, STRUCT_OFFSET(ATCPSocket, OnMessageReceived), Z_Construct_UDelegateFunction_VrLink_SocketDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnMessageReceived_MetaData), NewProp_OnMessageReceived_MetaData) }; // ca9bfd632f8eb1068a3f8b90bbc8083b5fc0475e
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_IPAddress,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Port,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DisconnectOnExit,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PrintMessages,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ConnectOnStart,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OnMessageReceived,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ATCPSocket Property Definitions ********************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_VrLink,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ATCPSocket,
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
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void ATCPSocket_StaticRegisterNativesATCPSocket()
{
	UClass* Class = ATCPSocket::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ATCPSocket;
UClass* Z_Construct_UClass_ATCPSocket(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ATCPSocket;
		if (!Z_Registration_Info_UClass_ATCPSocket.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("TCPSocket"),
				Z_Registration_Info_UClass_ATCPSocket.InnerSingleton,
				ATCPSocket_StaticRegisterNativesATCPSocket,
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
		return Z_Registration_Info_UClass_ATCPSocket.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ATCPSocket.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATCPSocket.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ATCPSocket.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ATCPSocket);
ATCPSocket::~ATCPSocket() {}
// ********** End Class ATCPSocket *****************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h__Script_VrLink_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATCPSocket, TEXT("ATCPSocket"), &Z_Registration_Info_UClass_ATCPSocket, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATCPSocket), 4152829280U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_wlaar_Documents_GitHub_OlifantPad_VrLink_Packaged_HostProject_Plugins_VrLink_Source_VrLink_Public_TCPSocket_h__Script_VrLink_5afb3597d482b1f55b80dd48c27f6efe12f9210a{
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
