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

	InitializeFormationArray(FormationsArray);
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASoapGameMode::SpawnGroupOfEnemies, 4.0f, true, 1.0f);
	
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
	//GetWorld()->SpawnActor<AEnemy0>(EnemyBP, FVector(100.0f, 100.0f, 200.0f), FRotator(0.0f, 0.0f, 0.0f));

	FFormation RandomFormation = FormationsArray[FMath::RandRange(0, FormationsArray.Num() - 1)];


	for(int i = 0; i < RandomFormation.Locations.Num(); i++)
	{
		GetWorld()->SpawnActor<AEnemy0>(EnemyBP, RandomFormation.Locations[i], FRotator(0.0f, 0.0f, 0.0f));
	}
	
}

void ASoapGameMode::InitializeFormationArray(TArray<FFormation> Formations)
{
	const float SpawnDistanceFromPlayer = 600.0f;


	FFormation Formation1;
	const int EnemiesInFormation = 5;
	const float Distance = 1200.0f;

	for(int i = 0; i < EnemiesInFormation; i++)	
	{
		FVector Location = FVector(SpawnDistanceFromPlayer, (static_cast<float>(i) / static_cast<float>(EnemiesInFormation)) * Distance + (-Distance/2) +((Distance/EnemiesInFormation)/2), 100.f);
		Formation1.Locations.Add(Location);

		UE_LOG(LogSoap, Log, TEXT("%s"), *Location.ToString());
	}


	FormationsArray.Add(Formation1);

}



