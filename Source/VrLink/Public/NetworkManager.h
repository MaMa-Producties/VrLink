// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sockets.h"
#include "TCPSocket.h"
#include "Async/Future.h"
#include "HAL/CriticalSection.h"
#include "Delegates/Delegate.h"
#include <atomic>

#define  MAX_BUFFER_SIZE 1024


class VRLINK_API NetworkManager
{
public:
	static NetworkManager& GetInstance()
	{
		static NetworkManager Instance;
		return Instance;
	}
	NetworkManager(NetworkManager const&) = delete;
	void operator=(NetworkManager const&) = delete;

	void StartServer(const FString IPAddress, const int32 Port);
	void SendMessage(const FString Message);

	/**
	 * Sends a single vrlink frame: one line of UTF-8, terminated by '\n'.
	 * This is the single outbound path every sender must go through. It appends
	 * the newline framing (if missing) and sends the exact UTF-8 BYTE count,
	 * not the UTF-16 character count, so multibyte text is framed correctly.
	 */
	void SendLine(const FString& Line);

	/** Sends all of `Count` bytes, or none of the rest once the connection fails. */
	bool Send(const uint8* Data, const int Count);
	void StopServer();

	bool IsSocketConnected();

	/** True while the listen socket is bound and the accept/receive loop is running. */
	bool IsServerListening() const { return IsListening; }

	/**
	 * Complete lines from the tablet, '\n' included, never a part of one. Broadcast on the
	 * game thread. A line split over two reads is held back until its end arrives.
	 */
	FNetworkDelegate OnDataReceived;

	/**
	 * The tablet's connection has gone (closed, dropped, or replaced by the same tablet
	 * coming back). Broadcast on the game thread. The session is NOT over: a tablet that
	 * loses Wi-Fi mid-ride reconnects into the same session.
	 */
	FSimpleMulticastDelegate OnClientDisconnected;

	/**
	 * What session is running, so a second tablet can be told the PC is busy while the
	 * one recording it can always come back. Called from the game thread.
	 */
	void SetActiveSession(bool bActive, const FString& SessionId);

	/** Drop the connected tablet, e.g. from an operator key, if it is stuck. */
	void DropClient();

	/**
	 * Tell the connected tablet why it is refused, then close it, so the PC is free for
	 * the next one. Used for a pairing-code or protocol mismatch, which used to leave the
	 * refused tablet holding the PC.
	 */
	void RejectClient(const FString& Reason);

	/**
	 * A connection that has sent `ping` before and then nothing for this long is treated
	 * as gone, so a tablet that died without closing its socket cannot hold the PC forever.
	 * Only applies to tablets that ping; one that never pings is never timed out.
	 */
	static constexpr double StaleAfterSeconds = 20.0;

	/** How long a newcomer has to say `hello` before it is asked to try again. */
	static constexpr double HelloWaitSeconds = 3.0;

	/**
	 * The two reasons a newcomer can be turned away, and they ask for different things.
	 * `busy`: another tablet holds this PC, look elsewhere. `try-again`: nothing is wrong
	 * with this PC for you, the moment was bad (another newcomer was being heard, or your
	 * hello was slow); dial the same PC again shortly. A recording tablet reads `busy` as
	 * "my ride is over", so `busy` must never be sent for a reason that is only timing.
	 */
	static constexpr const TCHAR* ReasonBusy = TEXT("busy");
	static constexpr const TCHAR* ReasonTryAgain = TEXT("try-again");

private:
	NetworkManager();
	~NetworkManager();

	void Loop();
	void HandleConnection();
	void HandleData();

	/** Tears down a dead client connection so the loop stops polling it and can accept a new one. */
	void HandleDisconnect();

	/** Reads the newcomer waiting while another tablet holds the PC, and decides on its `hello`. */
	void HandlePending();

	/** Whether the held connection has gone quiet after pinging, see StaleAfterSeconds. */
	bool IsClientStale() const;

	/**
	 * Make `Socket` the tablet's connection, closing any previous one. `Early` is what it
	 * already sent; its complete lines go to the game thread, the rest is kept. Caller holds
	 * ClientLock.
	 */
	void AdoptClient(FSocket* Socket, const FString& Address, TArray<uint8> Early = TArray<uint8>());

	/** Close the current client and tell the game thread. Caller holds ClientLock. */
	void CloseClientLocked();

	/**
	 * Read what `Socket` has into `Into`. False when the peer has closed or the connection
	 * failed. A closed socket reads as readable with nothing waiting, which is why this
	 * cannot rest on HasPendingData alone: that says false both for "nothing yet" and for
	 * "gone", and the tablet leaving went unnoticed until the ping timeout.
	 */
	static bool ReadAvailable(FSocket* Socket, TArray<uint8>& Into);

	/** Hand the complete lines in `Buffer` to the game thread and keep the rest. */
	void DeliverLines(TArray<uint8>& Buffer);

	/** Send `{"type":"reject","reason":...}` and close, letting the line reach the peer first. */
	static void RejectAndClose(FSocket* Socket, const FString& Reason);

	/** Send every byte, waiting briefly while the socket's buffer is full. */
	static bool SendAll(FSocket* Socket, const uint8* Data, int32 Count);

	static void CloseSocket(FSocket* Socket);

	/** The peer's IP without the port, so a reconnect from the same tablet is recognised. */
	static FString PeerAddress(const FInternetAddr& Address);

	FSocket* ListenSocket;
	FSocket* ClientSocket;
	FString ClientAddress;

	/** What the tablet sent that does not end in a newline yet. */
	TArray<uint8> ClientPartial;

	/** Guards ClientSocket: the loop thread replaces it while the game thread sends on it. */
	FCriticalSection ClientLock;

	/** A newcomer that arrived while a tablet was connected, waiting for its `hello`. */
	FSocket* PendingSocket = nullptr;
	double PendingSince = 0.0;
	TArray<uint8> PendingBytes;
	FString PendingAddress;

	double LastClientDataSeconds = 0.0;
	bool bClientPings = false;

	FCriticalSection SessionLock;
	bool bSessionRunning = false;
	FString RunningSessionId;

	/** The accept/receive loop task; StopServer() waits on it before destroying the sockets. */
	TFuture<void> LoopTask;

	int32 MaxBufferSize;

	/**
	 * Socket buffers for the tablet's connection. The listen socket used to be built with
	 * 1 KB send and receive buffers, which an accepted socket inherits, so a `welcome`
	 * longer than that could only go out in pieces, and a piece the non-blocking send did
	 * not take was silently dropped.
	 */
	static constexpr int32 SocketBufferBytes = 64 * 1024;

	std::atomic<bool> IsConnected;
	std::atomic<bool> IsListening;
};
