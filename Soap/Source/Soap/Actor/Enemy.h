// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class SOAP_API AEnemy : public ABasePawn
{
	GENERATED_BODY()

public:

	AEnemy();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool Dead;

};
