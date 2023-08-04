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

	
	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;



	
};


