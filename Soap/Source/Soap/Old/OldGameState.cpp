// Fill out your copyright notice in the Description page of Project Settings.


#include "OldGameState.h"
#include "../Soap.h"



AOldGameState::AOldGameState()
{


}

void AOldGameState::BeginPlay()
{
	Super::BeginPlay();




	InitializeFormationArray(FormationsArray);
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AOldGameState::SpawnGroupOfEnemies, 4.0f, true, 1.0f);

}





void AOldGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}





void AOldGameState::SpawnGroupOfEnemies() const
{
	//GetWorld()->SpawnActor<AEnemy0>(EnemyBP, FVector(100.0f, 100.0f, 200.0f), FRotator(0.0f, 0.0f, 0.0f));

	FFormation RandomFormation = FormationsArray[FMath::RandRange(0, FormationsArray.Num() - 1)];


	for (int i = 0; i < RandomFormation.Locations.Num(); i++)
	{
		GetWorld()->SpawnActor<AEnemy0>(EnemyBP, RandomFormation.Locations[i], FRotator(0.0f, 0.0f, 0.0f));
	}

}

void  AOldGameState::InitializeFormationArray(TArray<FFormation> Formations)
{
	const float SpawnDistanceFromPlayer = 600.0f;


	FFormation Formation1;
	const int EnemiesInFormation = 5;
	const float Distance = 1200.0f;

	for (int i = 0; i < EnemiesInFormation; i++)
	{
		FVector Location = FVector(SpawnDistanceFromPlayer, (static_cast<float>(i) / static_cast<float>(EnemiesInFormation)) * Distance + (-Distance / 2) + ((Distance / EnemiesInFormation) / 2), 100.f);
		Formation1.Locations.Add(Location);

		UE_LOG(LogSoap, Log, TEXT("%s"), *Location.ToString());
	}


	FormationsArray.Add(Formation1);

}

float  AOldGameState::GetPlayingArea()
{
	return PlayingArea_m;
}
