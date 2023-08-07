// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Old/Enemy0.h"
#include "Components/BoxComponent.h"
#include "GameFramework/GameStateBase.h"
#include "SoapGameState.generated.h"

USTRUCT()
struct FFormation
{
	GENERATED_BODY()

		UPROPERTY()
		TArray<FVector> Locations;
};


USTRUCT()
struct FWaterCollider
{
	GENERATED_BODY()


};


/**
 * 
 */
UCLASS()
class SOAP_API ASoapGameState : public AGameStateBase
{
	GENERATED_BODY()

	

public:

	ASoapGameState();


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

protected:

	



private:

	float PlayingArea_m;

	
};
