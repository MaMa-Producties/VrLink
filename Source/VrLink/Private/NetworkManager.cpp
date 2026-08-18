// Fill out your copyright notice in the Description page of Project Settings.


#include "NetworkManager.h"
#include "Common/TcpSocketBuilder.h"
#include "HAL/PlatformProcess.h"
// Included explicitly rather than relied on transitively. In this project the
// unity/PCH build happens to pull these in, so the plugin compiled here and
// failed the moment it was packaged for another team -- GEngine, Async and
// AsyncTask all came up undeclared. A plugin meant to be dropped into someone
// else's project cannot depend on that project's build settings.
#include "Engine/Engine.h"
#include "Async/Async.h"
#include "Async/TaskGraphInterfaces.h"


NetworkManager::NetworkManager()
{
	MaxBufferSize = MAX_BUFFER_SIZE;
	ListenSocket = nullptr;
	ClientSocket = nullptr;
	IsConnected = false;
	IsListening = false;
}

NetworkManager::~NetworkManager()
{
	StopServer();
}

void NetworkManager::StartServer(const FString IPAddress, const int32 Port)
{
	// Already running (e.g. a second PIE session): keep the existing listener instead of
	// binding a duplicate socket to the same port and leaking the old one.
	if (IsListening)
	{
		return;
	}

	FIPv4Address Address;
	if (!FIPv4Address::Parse(IPAddress, Address))
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("IP adress was not valid"));
		//throw std::logic_error("IP address was not valid");
	}

	//Create Socket
	const FIPv4Endpoint Endpoint(Address, Port);

	ListenSocket = FTcpSocketBuilder(TEXT("Socket"))
		.AsReusable()
		.BoundToEndpoint(Endpoint)
		.WithReceiveBufferSize(MaxBufferSize);

	ListenSocket->SetReceiveBufferSize(MaxBufferSize, MaxBufferSize);
	ListenSocket->SetSendBufferSize(MaxBufferSize, MaxBufferSize);

	ListenSocket->Listen(10);

	// Flag before launching so an immediate StopServer() can never miss the loop.
	IsListening = true;
	LoopTask = Async(EAsyncExecution::Thread, [this]() { Loop(); });
}

void NetworkManager::StopServer()
{
	IsConnected = false;
	IsListening = false;

	// Let the loop thread observe IsListening == false and exit before the sockets it
	// polls are destroyed underneath it. Must not be called from the loop thread itself.
	if (LoopTask.IsValid())
	{
		LoopTask.Wait();
		LoopTask = TFuture<void>();
	}

	if (ListenSocket)
	{
		ListenSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ListenSocket);
		ListenSocket = nullptr;
	}
	if (ClientSocket)
	{
		ClientSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket);
		ClientSocket = nullptr;
	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("server stopped"));
}

void NetworkManager::Loop()
{
	while (IsListening)
	{
		HandleConnection();
		if (IsConnected)
			HandleData();

		// Yield between polls so this thread doesn't spin a full core.
		FPlatformProcess::Sleep(0.001f);
	}
}

void NetworkManager::HandleConnection()
{
	if (ListenSocket) {
		bool isClientPendingConnection;
		ListenSocket->HasPendingConnection(isClientPendingConnection);
		if (isClientPendingConnection)
		{
			if (ClientSocket)
			{
				ClientSocket->Close();
				ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket);
			}

			//Remote address
			const TSharedRef<FInternetAddr> RemoteAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
			ClientSocket = ListenSocket->Accept(*RemoteAddress, TEXT("tcp-client"));
			if (ClientSocket != nullptr)
			{
				IsConnected = true;
				// vrlink is client-initiated: do NOT send anything here. Unreal waits
				// for Unity's `hello` and then replies `welcome` (see UVrLinkComponent).
				// A stray non-JSON greeting would break the peer's line parser.
			}
		}
	}
}

void NetworkManager::HandleData()
{
	if (ClientSocket == nullptr)
	{
		return;
	}

	uint32 DataPending = 0;
	if (!ClientSocket->HasPendingData(DataPending))
	{
		return;
	}

	int32 BytesRead = 0;
	uint8 Buffer[MAX_BUFFER_SIZE];
	const bool bRecvOk = ClientSocket->Recv(Buffer, MaxBufferSize, BytesRead);

	// A socket that reports readable but yields nothing is a peer that has gone away,
	// not data. Previously the result was ignored and nothing ever cleared IsConnected,
	// so a disconnected tablet left this loop re-reading the dead socket every
	// millisecond and flooding the game thread with empty packets forever.
	if (!bRecvOk || BytesRead <= 0)
	{
		HandleDisconnect();
		return;
	}

	// Build the payload here rather than copying the whole 1 KB buffer into the lambda.
	TArray<uint8> Payload(Buffer, BytesRead);
	AsyncTask(ENamedThreads::GameThread, [this, Payload = MoveTemp(Payload)]()
		{
			OnDataReceived.Broadcast(Payload);
		});
}

void NetworkManager::HandleDisconnect()
{
	IsConnected = false;

	if (ClientSocket)
	{
		ClientSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket);
		ClientSocket = nullptr;
	}

	// The listen socket stays open, so the tablet can simply reconnect.
	UE_LOG(LogTemp, Warning, TEXT("vrlink: client disconnected, waiting for a new connection."));
}

void NetworkManager::SendMessage(const FString Message)
{
	// Key 8810 rather than -1: -1 appends a NEW 15-second line for every message sent,
	// so a busy session buried the screen under a growing wall of text. A fixed key
	// overwrites the same slot, showing the latest frame instead of all of them.
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(8810, 5.f, IsSocketConnected() ? FColor::Blue : FColor::Red,
			FString(TEXT("[vrlink out] ")) + Message);
	}

	// Route through the single framed-send helper so the newline and the correct
	// UTF-8 byte length are always applied (was: Send(Data, Message.Len()) — no
	// newline and the UTF-16 char count instead of the UTF-8 byte count).
	SendLine(Message);
}

void NetworkManager::SendLine(const FString& Line)
{
	// One vrlink frame == one line terminated by '\n'.
	FString Framed = Line;
	if (!Framed.EndsWith(TEXT("\n")))
	{
		Framed.AppendChar(TEXT('\n'));
	}

	// Encode as UTF-8 and send the exact BYTE count (Length()), not the character count.
	FTCHARToUTF8 Utf8(*Framed);
	Send(reinterpret_cast<const uint8*>(Utf8.Get()), Utf8.Length());
}

bool NetworkManager::IsSocketConnected()
{
	return IsConnected;
}

bool NetworkManager::Send(const uint8* Data, const int Count)
{
	if (ClientSocket)
	{
		int32 BytesSent = 0;
		return ClientSocket->Send(Data, Count, BytesSent);
	}
	return false;
}


