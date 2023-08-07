// Copyright Epic Games, Inc. All Rights Reserved.


#include "SoapGameMode.h"
#include "../Old/Antagonist.h"
#include "../Old/Enemy0.h"
#include "../Soap.h"

ASoapGameMode::ASoapGameMode()
{
	DefaultPawnClass = AAntagonist::StaticClass();
	

}




void ASoapGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	UE_LOG(LogSoap, Log, TEXT("Game is running %s %s"), *MapName, *Options);

}


void ASoapGameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);
}

