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

	bool Send(const uint8* Data, const int Count);
	void StopServer();

	bool IsSocketConnected();

	/** True while the listen socket is bound and the accept/receive loop is running. */
	bool IsServerListening() const { return IsListening; }

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
	 * A connection that has sent `ping` before and then nothing for this long is treated
	 * as gone, so a tablet that died without closing its socket cannot hold the PC forever.
	 * Only applies to tablets that ping; one that never pings is never timed out.
	 */
	static constexpr double StaleAfterSeconds = 20.0;

	/** How long a newcomer has to say `hello` before it is turned away. */
	static constexpr double HelloWaitSeconds = 3.0;
	
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

	/** Make `Socket` the tablet's connection, closing any previous one. Caller holds ClientLock. */
	void AdoptClient(FSocket* Socket);

	/** Close the current client and tell the game thread. Caller holds ClientLock. */
	void CloseClientLocked();

	/** Send `{"type":"reject","reason":...}` and close, letting the line reach the peer first. */
	static void RejectAndClose(FSocket* Socket, const TCHAR* Reason);

	static void CloseSocket(FSocket* Socket);

	FSocket* ListenSocket;
	FSocket* ClientSocket;

	/** Guards ClientSocket: the loop thread replaces it while the game thread sends on it. */
	FCriticalSection ClientLock;

	/** A newcomer that arrived while a tablet was connected, waiting for its `hello`. */
	FSocket* PendingSocket = nullptr;
	double PendingSince = 0.0;
	TArray<uint8> PendingBytes;

	double LastClientDataSeconds = 0.0;
	bool bClientPings = false;

	FCriticalSection SessionLock;
	bool bSessionRunning = false;
	FString RunningSessionId;

	/** The accept/receive loop task; StopServer() waits on it before destroying the sockets. */
	TFuture<void> LoopTask;

	int32 MaxBufferSize;

	std::atomic<bool> IsConnected;
	std::atomic<bool> IsListening;
};
