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
#include "Misc/Timespan.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "Policies/CondensedJsonPrintPolicy.h"
#include "Dom/JsonObject.h"
#include "SocketSubsystem.h"
#include "IPAddress.h"


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
		.WithReceiveBufferSize(SocketBufferBytes)
		.WithSendBufferSize(SocketBufferBytes);

	if (ListenSocket == nullptr || !ListenSocket->Listen(10))
	{
		// Port taken (a second copy of the experience running?) or no network.
		UE_LOG(LogTemp, Error, TEXT("vrlink: could not listen on port %d; no tablet can connect."), Port);
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Red,
				FString::Printf(TEXT("VR Link: could not listen on port %d. Is the experience running twice?"), Port));
		CloseSocket(ListenSocket);
		ListenSocket = nullptr;
		return;
	}

	int32 Actual = 0;
	ListenSocket->SetReceiveBufferSize(SocketBufferBytes, Actual);
	ListenSocket->SetSendBufferSize(SocketBufferBytes, Actual);

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
		ClientAddress.Reset();
		ClientPartial.Reset();
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

FString NetworkManager::PeerAddress(const FInternetAddr& Address)
{
	return Address.ToString(/*bAppendPort=*/false);
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
	const FString From = PeerAddress(*RemoteAddress);

	// vrlink is client-initiated: nothing is sent to a tablet that is let in. Unreal
	// waits for its `hello` and replies `welcome` (see UVrLinkComponent).
	FScopeLock Lock(&ClientLock);

	// Nobody holds the PC, or the one holding it went quiet after pinging: this tablet
	// gets it straight away.
	if (ClientSocket == nullptr || IsClientStale())
	{
		AdoptClient(Newcomer, From);
		return;
	}

	// The same tablet again. A device cannot be its own rival: this is it reconnecting
	// while its old connection still looks open here (a Wi-Fi blip, an app restart), or
	// dialling twice at once. The newest connection is the one it will use, so it wins.
	// Two tablets never share an address on the study network.
	if (!From.IsEmpty() && From == ClientAddress)
	{
		UE_LOG(LogTemp, Log, TEXT("vrlink: %s connected again; the new connection replaces the old one."), *From);
		AdoptClient(Newcomer, From);
		return;
	}

	// Another tablet holds the PC. This used to close it and take the newcomer, so two
	// tablets taking turns on one PC knocked each other off: the one in the questionnaire
	// reconnected and threw out the one recording a ride, which then did the same back.
	// Now the newcomer waits for its `hello`, and only gets in if it is the recording
	// tablet coming back (HandlePending). One newcomer is heard at a time; a second one
	// arriving meanwhile is only unlucky, not refused, so it is asked to try again.
	if (PendingSocket != nullptr)
	{
		if (!From.IsEmpty() && From == PendingAddress)
		{
			// The waiting newcomer dialled again: its newest connection is the one it uses.
			CloseSocket(PendingSocket);
			PendingSocket = Newcomer;
			PendingSince = FPlatformTime::Seconds();
			PendingBytes.Reset();
			return;
		}
		RejectAndClose(Newcomer, ReasonTryAgain);
		return;
	}
	PendingSocket = Newcomer;
	PendingSince = FPlatformTime::Seconds();
	PendingBytes.Reset();
	PendingAddress = From;
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
			AdoptClient(Newcomer, PendingAddress, MoveTemp(PendingBytes));
			PendingBytes.Reset();
			return;
		}
	}

	if (!ReadAvailable(PendingSocket, PendingBytes))
	{
		// Gave up before saying hello.
		CloseSocket(PendingSocket);
		PendingSocket = nullptr;
		PendingBytes.Reset();
		return;
	}

	// Admission is decided on the `hello`, and only on it. A tablet can send a ping or a
	// headband report in the moment before its hello goes out; judging on the first line
	// turned a recording tablet away as "busy", which it reads as its ride being over.
	// Other lines are kept, and reach the component if this tablet is let in.
	bool bHaveHello = false;
	FString ResumeId;
	{
		int32 Start = 0;
		for (int32 i = 0; i < PendingBytes.Num() && !bHaveHello; ++i)
		{
			if (PendingBytes[i] != '\n')
			{
				continue;
			}
			const FUTF8ToTCHAR Text(reinterpret_cast<const ANSICHAR*>(PendingBytes.GetData() + Start), i - Start);
			const FString Line(Text.Length(), Text.Get());
			Start = i + 1;
			TSharedPtr<FJsonObject> Msg;
			FString Type;
			if (!FJsonSerializer::Deserialize(TJsonReaderFactory<TCHAR>::Create(Line), Msg) || !Msg.IsValid()
				|| !Msg->TryGetStringField(TEXT("type"), Type) || Type != TEXT("hello"))
			{
				continue;
			}
			bHaveHello = true;
			const TSharedPtr<FJsonObject>* Resume = nullptr;
			if (Msg->TryGetObjectField(TEXT("resume"), Resume) && Resume && Resume->IsValid())
			{
				(*Resume)->TryGetStringField(TEXT("sessionId"), ResumeId);
			}
		}
	}

	if (!bHaveHello)
	{
		if (FPlatformTime::Seconds() - PendingSince > HelloWaitSeconds || PendingBytes.Num() > 16 * 1024)
		{
			// A slow hello is no reason to tell a tablet its ride is over.
			RejectAndClose(PendingSocket, ReasonTryAgain);
			PendingSocket = nullptr;
			PendingBytes.Reset();
		}
		return;
	}

	bool bOwnsTheRide = false;
	{
		FScopeLock Lock(&SessionLock);
		bOwnsTheRide = bSessionRunning && !RunningSessionId.IsEmpty() && ResumeId == RunningSessionId;
	}

	if (!bOwnsTheRide)
	{
		RejectAndClose(PendingSocket, ReasonBusy);
		PendingSocket = nullptr;
		PendingBytes.Reset();
		UE_LOG(LogTemp, Log, TEXT("vrlink: turned away a second tablet, this PC is busy."));
		return;
	}

	// The recording tablet came back from a new address (a Wi-Fi blip that changed its
	// lease): its old connection only looks open. It takes the PC back, and its `hello`
	// goes on to the component as normal.
	FSocket* Returning = PendingSocket;
	PendingSocket = nullptr;
	{
		FScopeLock Lock(&ClientLock);
		AdoptClient(Returning, PendingAddress, MoveTemp(PendingBytes));
	}
	PendingBytes.Reset();
	UE_LOG(LogTemp, Log, TEXT("vrlink: the recording tablet reconnected and took its PC back."));
}

bool NetworkManager::IsClientStale() const
{
	return ClientSocket != nullptr && bClientPings
		&& FPlatformTime::Seconds() - LastClientDataSeconds > StaleAfterSeconds;
}

void NetworkManager::AdoptClient(FSocket* Socket, const FString& Address, TArray<uint8> Early)
{
	if (ClientSocket != nullptr)
	{
		CloseClientLocked();
	}
	ClientSocket = Socket;
	ClientAddress = Address;
	ClientPartial.Reset();
	IsConnected = true;
	LastClientDataSeconds = FPlatformTime::Seconds();
	bClientPings = false;

	int32 Actual = 0;
	Socket->SetSendBufferSize(SocketBufferBytes, Actual);
	Socket->SetReceiveBufferSize(SocketBufferBytes, Actual);

	if (Early.Num() > 0)
	{
		ClientPartial = MoveTemp(Early);
		DeliverLines(ClientPartial);
	}
}

void NetworkManager::CloseClientLocked()
{
	IsConnected = false;
	CloseSocket(ClientSocket);
	ClientSocket = nullptr;
	ClientAddress.Reset();
	ClientPartial.Reset();
	AsyncTask(ENamedThreads::GameThread, [this]() { OnClientDisconnected.Broadcast(); });
}

bool NetworkManager::ReadAvailable(FSocket* Socket, TArray<uint8>& Into)
{
	uint8 Buffer[MAX_BUFFER_SIZE];
	for (int32 Reads = 0; Reads < 64; ++Reads)
	{
		uint32 Waiting = 0;
		if (!Socket->HasPendingData(Waiting))
		{
			// Nothing waiting: either nothing yet, or the peer is gone. A closed or failed
			// socket still selects as readable; reading it then returns failure.
			if (!Socket->Wait(ESocketWaitConditions::WaitForRead, FTimespan::Zero()))
			{
				return true;
			}
			int32 Read = 0;
			if (!Socket->Recv(Buffer, MAX_BUFFER_SIZE, Read))
			{
				return false;
			}
			if (Read <= 0)
			{
				return true;   // would block: a spurious wake-up, not a close
			}
			Into.Append(Buffer, Read);
			continue;
		}

		int32 Read = 0;
		if (!Socket->Recv(Buffer, MAX_BUFFER_SIZE, Read))
		{
			return false;
		}
		if (Read <= 0)
		{
			return true;
		}
		Into.Append(Buffer, Read);
	}
	return true;
}

void NetworkManager::DeliverLines(TArray<uint8>& Buffer)
{
	int32 Last = INDEX_NONE;
	for (int32 i = Buffer.Num() - 1; i >= 0; --i)
	{
		if (Buffer[i] == '\n' || Buffer[i] == '\0')
		{
			Last = i;
			break;
		}
	}
	if (Last == INDEX_NONE)
	{
		return;
	}

	TArray<uint8> Lines(Buffer.GetData(), Last + 1);
	Buffer.RemoveAt(0, Last + 1);

	if (!bClientPings)
	{
		// A tablet that pings can be timed out when it stops; see StaleAfterSeconds.
		const FUTF8ToTCHAR Seen(reinterpret_cast<const ANSICHAR*>(Lines.GetData()), Lines.Num());
		bClientPings = FString(Seen.Length(), Seen.Get()).Contains(TEXT("\"ping\""));
	}

	AsyncTask(ENamedThreads::GameThread, [this, Lines = MoveTemp(Lines)]()
		{
			OnDataReceived.Broadcast(Lines);
		});
}

void NetworkManager::RejectAndClose(FSocket* Socket, const FString& Reason)
{
	if (Socket == nullptr)
	{
		return;
	}

	// Written with the JSON writer, not a format string: the protocol-mismatch reason
	// carries text the peer sent, and a quote in it would break the line.
	const TSharedRef<FJsonObject> Reject = MakeShared<FJsonObject>();
	Reject->SetStringField(TEXT("type"), TEXT("reject"));
	Reject->SetStringField(TEXT("reason"), Reason);
	FString Line;
	const TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer =
		TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&Line);
	FJsonSerializer::Serialize(Reject, Writer);
	Line.AppendChar(TEXT('\n'));

	const FTCHARToUTF8 Utf8(*Line);
	SendAll(Socket, reinterpret_cast<const uint8*>(Utf8.Get()), Utf8.Length());

	// Drain what the peer already sent and close the sending side first. Closing a socket
	// with unread bytes resets it, and a reset can arrive before the reject is read, which
	// would leave the tablet retrying instead of stepping aside.
	TArray<uint8> Sink;
	ReadAvailable(Socket, Sink);
	Socket->Shutdown(ESocketShutdownMode::Write);
	CloseSocket(Socket);
}

bool NetworkManager::SendAll(FSocket* Socket, const uint8* Data, int32 Count)
{
	// The socket is non-blocking: a send can take part of the line, or none of it while
	// the buffer is full. The result used to be ignored, so the rest of the line was lost
	// and the next one was glued onto what had gone out.
	int32 Done = 0;
	const double GiveUpAt = FPlatformTime::Seconds() + 0.5;
	while (Done < Count)
	{
		int32 Sent = 0;
		const bool bOk = Socket->Send(Data + Done, Count - Done, Sent);
		if (bOk && Sent > 0)
		{
			Done += Sent;
			continue;
		}
		const ESocketErrors Error = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLastErrorCode();
		const bool bWouldBlock = (bOk && Sent == 0) || Error == SE_EWOULDBLOCK || Error == SE_TRY_AGAIN;
		if (!bWouldBlock || FPlatformTime::Seconds() > GiveUpAt)
		{
			return false;
		}
		Socket->Wait(ESocketWaitConditions::WaitForWrite, FTimespan::FromMilliseconds(20));
	}
	return true;
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

void NetworkManager::RejectClient(const FString& Reason)
{
	FScopeLock Lock(&ClientLock);
	if (ClientSocket == nullptr)
	{
		return;
	}
	FSocket* Refused = ClientSocket;
	ClientSocket = nullptr;
	ClientAddress.Reset();
	ClientPartial.Reset();
	IsConnected = false;
	RejectAndClose(Refused, Reason);
	AsyncTask(ENamedThreads::GameThread, [this]() { OnClientDisconnected.Broadcast(); });
}

void NetworkManager::HandleData()
{
	FScopeLock Lock(&ClientLock);
	if (ClientSocket == nullptr)
	{
		return;
	}

	const int32 Before = ClientPartial.Num();
	const bool bOpen = ReadAvailable(ClientSocket, ClientPartial);

	// What arrived is delivered before any close is acted on: a tablet that sends its
	// session.end and lets go at once has both land in the same read, and the end must
	// reach the component first. The lines are queued ahead of the disconnect.
	if (ClientPartial.Num() != Before)
	{
		LastClientDataSeconds = FPlatformTime::Seconds();
		DeliverLines(ClientPartial);
	}

	if (!bOpen)
	{
		// Closed by the tablet (it let go after its ride), or failed. This used to go
		// unnoticed: the check only read when bytes were waiting, and a closed socket has
		// none, so the PC stayed "busy" until the ping timeout and the handshake was never
		// reset.
		HandleDisconnect();
		return;
	}

	// A peer that never sends a newline cannot grow the buffer without bound.
	if (ClientPartial.Num() > 64 * 1024)
	{
		UE_LOG(LogTemp, Warning, TEXT("vrlink: dropped %d bytes from the tablet with no line end."), ClientPartial.Num());
		ClientPartial.Reset();
	}
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
		if (SendAll(ClientSocket, Data, Count))
		{
			return true;
		}
		// Part of a line may have gone out. Anything sent after it would be glued onto
		// the torn half, so the connection is closed and the tablet reconnects cleanly.
		UE_LOG(LogTemp, Warning, TEXT("vrlink: could not send to the tablet; closing the connection."));
		CloseClientLocked();
	}
	return false;
}
