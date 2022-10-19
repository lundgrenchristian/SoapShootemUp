// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Enemy0.h"
#include "SoapGameMode.generated.h"


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
class SOAP_API ASoapGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
		ASoapGameMode();

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



	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;



	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	

	
};


