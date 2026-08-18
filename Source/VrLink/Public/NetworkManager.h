// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sockets.h"
#include "TCPSocket.h"
#include "Async/Future.h"
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
	
private:
	NetworkManager();
	~NetworkManager();

	void Loop();
	void HandleConnection();
	void HandleData();

	/** Tears down a dead client connection so the loop stops polling it and can accept a new one. */
	void HandleDisconnect();

	FSocket* ListenSocket;
	FSocket* ClientSocket;

	/** The accept/receive loop task; StopServer() waits on it before destroying the sockets. */
	TFuture<void> LoopTask;

	int32 MaxBufferSize;

	std::atomic<bool> IsConnected;
	std::atomic<bool> IsListening;
};
