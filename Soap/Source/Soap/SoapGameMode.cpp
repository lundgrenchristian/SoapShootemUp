// Copyright Epic Games, Inc. All Rights Reserved.


#include "SoapGameMode.h"
#include "Antagonist.h"
#include "Enemy0.h"
#include "Soap.h"

ASoapGameMode::ASoapGameMode()
{
	DefaultPawnClass = AAntagonist::StaticClass();
	

}

void ASoapGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASoapGameMode::SpawnGroupOfEnemies, 0.0f, true, 5.0f);
}



void ASoapGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	UE_LOG(LogSoap, Log, TEXT("Game is running %s %s"), *MapName, *Options);

}

void ASoapGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void ASoapGameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);

	Player = NewPlayer;
}

void ASoapGameMode::SpawnGroupOfEnemies() const
{
	GetWorld()->SpawnActor<AEnemy0>(EnemyBP, FVector(100.0f, 100.0f, 200.0f), FRotator(0.0f, 0.0f, 0.0f));
}


