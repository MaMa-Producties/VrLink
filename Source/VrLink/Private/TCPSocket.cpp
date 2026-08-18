// Fill out your copyright notice in the Description page of Project Settings.

#include "TCPSocket.h"
#include "Networking.h"
#include "NetworkManager.h"
// GEngine, for the on-screen debug messages below. Transitively available
// inside this project; not when the plugin is packaged for another one.
#include "Engine/Engine.h"

//Copyright Some guy
// Lifecycle events only: -1 appends a new line, which is fine for things that
// happen a handful of times per session.
#define PRINT(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green,text)

// Anything that can fire per packet MUST use this instead. A fixed key overwrites
// its own slot, so traffic updates one line rather than burying the viewport under
// a new 5-second line per message.
#define PRINT_KEYED(key, text) if (GEngine) GEngine->AddOnScreenDebugMessage(key, 5, FColor::Green,text)

namespace
{
	constexpr int32 KeySent = 8821;
	constexpr int32 KeyRecvCount = 8822;
	constexpr int32 KeyRecvMessage = 8823;
}

// Sets default values
ATCPSocket::ATCPSocket()
{
	PrimaryActorTick.bCanEverTick = false;

	IPAddress = "0.0.0.0";
	Port = 3030;
	DisconnectOnExit = true;
	PrintMessages = true;
	ConnectOnStart = true;
	PRINT("Construct socket");
}

// Called when the game starts or when spawned
void ATCPSocket::BeginPlay()
{
	PRINT("Begin play socket");

	Super::BeginPlay();
	NetworkManager::GetInstance().OnDataReceived.AddDynamic(this, &ATCPSocket::ReceiveMessage);

	if (ConnectOnStart)
		StartServer();
}

void ATCPSocket::StartServer()
{
	// Guard on listening, not connected: a stale "connected" flag from an earlier session
	// must not prevent a fresh session from bringing the server up.
	if (!NetworkManager::GetInstance().IsServerListening()) {
		NetworkManager::GetInstance().StartServer(IPAddress, Port);
		if (PrintMessages) {
			PRINT("Start server");
		}
	}
}

void ATCPSocket::StopServer()
{
	if (PrintMessages) {
		PRINT("Server stopped");
	}

	NetworkManager::GetInstance().StopServer();
}


// Called every frame
void ATCPSocket::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// EndPlay, not BeginDestroy: BeginDestroy is a GC-time callback that runs long after the
// world is gone (or not at all until editor shutdown), so the server outlived the session.
void ATCPSocket::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	NetworkManager::GetInstance().OnDataReceived.RemoveDynamic(this, &ATCPSocket::ReceiveMessage);
	if (DisconnectOnExit)
		StopServer();

	Super::EndPlay(EndPlayReason);
}

void ATCPSocket::SendMessage(const FString Message)
{
	NetworkManager::GetInstance().SendMessage(Message);

	if (PrintMessages) {
		PRINT_KEYED(KeySent, "Sent: " + Message);
	}
}

void ATCPSocket::ReceiveMessage(TArray<uint8> Data)
{
	// Was an ungated PRINT on every packet, so a chatty or retrying peer buried the
	// viewport regardless of the PrintMessages setting. Now gated and keyed.
	if (PrintMessages) {
		PRINT_KEYED(KeyRecvCount, FString::Printf(TEXT("Received %d bytes"), Data.Num()));
	}
	FString Message = FString();
	for (int i = 0; i < Data.Num(); i++)
	{
		if (Data[i] == '\n' || Data[i] == '\0')
		{
			if (OnMessageReceived.IsBound())
				OnMessageReceived.Broadcast(Message);

			if (PrintMessages) {
				PRINT_KEYED(KeyRecvMessage, Message);
			}

			Message = "";
		}
		else
		{
			Message.AppendChar(Data[i]);
		}
	}
}


bool ATCPSocket::IsSocketConnected()
{
	return NetworkManager::GetInstance().IsSocketConnected();
}


