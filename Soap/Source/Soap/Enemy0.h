// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Enemy0.generated.h"

/**
 * 
 */
UCLASS()
class SOAP_API AEnemy0 : public ABaseCharacter
{
	GENERATED_BODY()

public:
		AEnemy0();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void Move();


};
