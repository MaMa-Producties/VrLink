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
#include "Misc/ScopeLock.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"


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
	{
		FScopeLock Lock(&ClientLock);
		CloseSocket(ClientSocket);
		ClientSocket = nullptr;
	}
	CloseSocket(PendingSocket);
	PendingSocket = nullptr;
	PendingBytes.Reset();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("server stopped"));
}

void NetworkManager::Loop()
{
	while (IsListening)
	{
		HandleConnection();
		HandlePending();
		if (IsConnected)
			HandleData();

		// Yield between polls so this thread doesn't spin a full core.
		FPlatformProcess::Sleep(0.001f);
	}
}

void NetworkManager::HandleConnection()
{
	if (!ListenSocket)
	{
		return;
	}

	bool bPending = false;
	ListenSocket->HasPendingConnection(bPending);
	if (!bPending)
	{
		return;
	}

	const TSharedRef<FInternetAddr> RemoteAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	FSocket* Newcomer = ListenSocket->Accept(*RemoteAddress, TEXT("tcp-client"));
	if (Newcomer == nullptr)
	{
		return;
	}

	// vrlink is client-initiated: nothing is sent to a tablet that is let in. Unreal
	// waits for its `hello` and replies `welcome` (see UVrLinkComponent).
	FScopeLock Lock(&ClientLock);

	// Nobody holds the PC, or the one holding it went quiet after pinging: this tablet
	// gets it straight away.
	if (ClientSocket == nullptr || IsClientStale())
	{
		AdoptClient(Newcomer);
		return;
	}

	// Another tablet holds the PC. This used to close it and take the newcomer, so two
	// tablets taking turns on one PC knocked each other off: the one in the questionnaire
	// reconnected and threw out the one recording a ride, which then did the same back.
	// Now the newcomer waits for its `hello`, and only gets in if it is the recording
	// tablet coming back (HandlePending). One newcomer is heard at a time.
	if (PendingSocket != nullptr)
	{
		RejectAndClose(Newcomer, TEXT("busy"));
		return;
	}
	PendingSocket = Newcomer;
	PendingSince = FPlatformTime::Seconds();
	PendingBytes.Reset();
}

void NetworkManager::HandlePending()
{
	if (PendingSocket == nullptr)
	{
		return;
	}

	// The tablet holding the PC may have left while this one waited: then it simply gets in.
	{
		FScopeLock Lock(&ClientLock);
		if (ClientSocket == nullptr || IsClientStale())
		{
			FSocket* Newcomer = PendingSocket;
			PendingSocket = nullptr;
			TArray<uint8> Early = MoveTemp(PendingBytes);
			AdoptClient(Newcomer);
			if (Early.Num() > 0)
			{
				AsyncTask(ENamedThreads::GameThread, [this, Early = MoveTemp(Early)]() { OnDataReceived.Broadcast(Early); });
			}
			return;
		}
	}

	uint32 Waiting = 0;
	if (PendingSocket->HasPendingData(Waiting))
	{
		uint8 Buffer[MAX_BUFFER_SIZE];
		int32 Read = 0;
		if (!PendingSocket->Recv(Buffer, MaxBufferSize, Read) || Read <= 0)
		{
			CloseSocket(PendingSocket);
			PendingSocket = nullptr;
			PendingBytes.Reset();
			return;
		}
		PendingBytes.Append(Buffer, Read);
	}

	const int32 LineEnd = PendingBytes.IndexOfByKey(static_cast<uint8>('\n'));
	if (LineEnd == INDEX_NONE)
	{
		if (FPlatformTime::Seconds() - PendingSince > HelloWaitSeconds || PendingBytes.Num() > 16 * 1024)
		{
			RejectAndClose(PendingSocket, TEXT("busy"));
			PendingSocket = nullptr;
			PendingBytes.Reset();
		}
		return;
	}

	// The first line is the `hello`. Read only what decides admission: which session,
	// if any, this tablet says it is resuming.
	FString ResumeId;
	{
		const FUTF8ToTCHAR Text(reinterpret_cast<const ANSICHAR*>(PendingBytes.GetData()), LineEnd);
		const FString Line(Text.Length(), Text.Get());
		TSharedPtr<FJsonObject> Hello;
		if (FJsonSerializer::Deserialize(TJsonReaderFactory<TCHAR>::Create(Line), Hello) && Hello.IsValid())
		{
			const TSharedPtr<FJsonObject>* Resume = nullptr;
			if (Hello->TryGetObjectField(TEXT("resume"), Resume) && Resume && Resume->IsValid())
			{
				(*Resume)->TryGetStringField(TEXT("sessionId"), ResumeId);
			}
		}
	}

	bool bOwnsTheRide = false;
	{
		FScopeLock Lock(&SessionLock);
		bOwnsTheRide = bSessionRunning && !RunningSessionId.IsEmpty() && ResumeId == RunningSessionId;
	}

	if (!bOwnsTheRide)
	{
		RejectAndClose(PendingSocket, TEXT("busy"));
		PendingSocket = nullptr;
		PendingBytes.Reset();
		UE_LOG(LogTemp, Log, TEXT("vrlink: turned away a second tablet, this PC is busy."));
		return;
	}

	// The recording tablet came back (Wi-Fi blip): its old connection only looks open.
	// It takes the PC back, and its `hello` goes on to the component as normal.
	FSocket* Returning = PendingSocket;
	PendingSocket = nullptr;
	TArray<uint8> Hello = MoveTemp(PendingBytes);
	{
		FScopeLock Lock(&ClientLock);
		AdoptClient(Returning);
	}
	UE_LOG(LogTemp, Log, TEXT("vrlink: the recording tablet reconnected and took its PC back."));
	AsyncTask(ENamedThreads::GameThread, [this, Hello = MoveTemp(Hello)]() { OnDataReceived.Broadcast(Hello); });
}

bool NetworkManager::IsClientStale() const
{
	return ClientSocket != nullptr && bClientPings
		&& FPlatformTime::Seconds() - LastClientDataSeconds > StaleAfterSeconds;
}

void NetworkManager::AdoptClient(FSocket* Socket)
{
	if (ClientSocket != nullptr)
	{
		CloseClientLocked();
	}
	ClientSocket = Socket;
	IsConnected = true;
	LastClientDataSeconds = FPlatformTime::Seconds();
	bClientPings = false;
}

void NetworkManager::CloseClientLocked()
{
	IsConnected = false;
	CloseSocket(ClientSocket);
	ClientSocket = nullptr;
	AsyncTask(ENamedThreads::GameThread, [this]() { OnClientDisconnected.Broadcast(); });
}

void NetworkManager::RejectAndClose(FSocket* Socket, const TCHAR* Reason)
{
	if (Socket == nullptr)
	{
		return;
	}
	const FString Line = FString::Printf(TEXT("{\"type\":\"reject\",\"reason\":\"%s\"}\n"), Reason);
	const FTCHARToUTF8 Utf8(*Line);
	int32 Sent = 0;
	Socket->Send(reinterpret_cast<const uint8*>(Utf8.Get()), Utf8.Length(), Sent);

	// Drain what the peer already sent and close the sending side first. Closing a socket
	// with unread bytes resets it, and a reset can arrive before the reject is read, which
	// would leave the tablet retrying instead of stepping aside.
	uint32 Waiting = 0;
	uint8 Sink[MAX_BUFFER_SIZE];
	int32 Read = 0;
	while (Socket->HasPendingData(Waiting) && Socket->Recv(Sink, MAX_BUFFER_SIZE, Read) && Read > 0) {}
	Socket->Shutdown(ESocketShutdownMode::Write);
	CloseSocket(Socket);
}

void NetworkManager::CloseSocket(FSocket* Socket)
{
	if (Socket)
	{
		Socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	}
}

void NetworkManager::SetActiveSession(bool bActive, const FString& SessionId)
{
	FScopeLock Lock(&SessionLock);
	bSessionRunning = bActive;
	RunningSessionId = bActive ? SessionId : FString();
}

void NetworkManager::DropClient()
{
	FScopeLock Lock(&ClientLock);
	if (ClientSocket != nullptr)
	{
		CloseClientLocked();
	}
}

void NetworkManager::HandleData()
{
	FScopeLock Lock(&ClientLock);
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

	LastClientDataSeconds = FPlatformTime::Seconds();
	if (!bClientPings)
	{
		// A tablet that pings can be timed out when it stops; see StaleAfterSeconds.
		const FUTF8ToTCHAR Seen(reinterpret_cast<const ANSICHAR*>(Buffer), BytesRead);
		bClientPings = FString(Seen.Length(), Seen.Get()).Contains(TEXT("\"ping\""));
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
	// Called from HandleData, which holds ClientLock.
	if (ClientSocket)
	{
		CloseClientLocked();
	}
	IsConnected = false;

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
	FScopeLock Lock(&ClientLock);
	if (ClientSocket)
	{
		int32 BytesSent = 0;
		return ClientSocket->Send(Data, Count, BytesSent);
	}
	return false;
}


