// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy0.h"
#include "GameFramework/GameStateBase.h"
#include "SoapGameState.generated.h"

USTRUCT()
struct FFormation
{
	GENERATED_BODY()

		UPROPERTY()
		TArray<FVector> Locations;
};

/**
 * 
 */
UCLASS()
class SOAP_API ASoapGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
		UPROPERTY(BlueprintReadOnly)
		APlayerController* Player;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AEnemy0> EnemyBP;


	UPROPERTY()
		FTimerHandle SpawnTimerHandle;

	UFUNCTION()
		void SpawnGroupOfEnemies() const;

	UPROPERTY()
		TArray<FFormation> FormationsArray;

	UFUNCTION()
		void InitializeFormationArray(TArray<FFormation> Formations);

	UFUNCTION()
		float GetPlayingArea();

	UPROPERTY()
		TArray<AActor*> EnemyArray;
	

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:

	float PlayingArea_m;

	
};
