// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Enemy0.h"
#include "SoapGameMode.generated.h"

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


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;



	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;



	
};
