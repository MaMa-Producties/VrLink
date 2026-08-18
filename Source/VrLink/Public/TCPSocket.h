// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TCPSocket.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNetworkDelegate, TArray<uint8>, Data);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSocketDelegate, FString, Message);
UCLASS()
class VRLINK_API ATCPSocket : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATCPSocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


private:
	UPROPERTY(EditAnywhere, Category = "VR Link")
		FString IPAddress;

	UPROPERTY(EditAnywhere, Category = "VR Link")
		int32 Port;

	/**
	 * Stop the server when this actor leaves play (end of PIE / level change). Leaving it
	 * running turns the port into a zombie: it accepts connections but nothing answers, and
	 * the next play session binds a duplicate listener next to it.
	 */
	UPROPERTY(EditAnywhere, Category = "VR Link")
		bool DisconnectOnExit;

	UPROPERTY(EditAnywhere, Category = "VR Link")
		bool PrintMessages;

	UPROPERTY(EditAnywhere, Category = "VR Link")
	bool ConnectOnStart;

public:
	// Called every frame
	virtual void Tick(const float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Socket")
		void StartServer();

	UFUNCTION(BlueprintCallable, Category = "Socket")
		void StopServer();

	UFUNCTION(BlueprintCallable, Category = "Socket")
		void SendMessage(const FString Message);
	UFUNCTION(Category = "Socket")
		void ReceiveMessage(TArray<uint8> Data);

	UFUNCTION(BlueprintCallable, Category = "Socket")
		bool IsSocketConnected();

	UPROPERTY(BlueprintAssignable, Category = "Socket")
		FSocketDelegate OnMessageReceived;

};
