// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SoapGameState.generated.h"


/**
 * 
 */
UCLASS()
class SOAP_API ASoapGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	ASoapGameState();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	
};
