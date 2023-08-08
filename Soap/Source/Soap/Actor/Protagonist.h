// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Protagonist.generated.h"

/**
 * 
 */
UCLASS()
class SOAP_API AProtagonist : public ABasePawn
{
	GENERATED_BODY()

public:
	AProtagonist();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:

	UFUNCTION()
		void TouchPressed(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION()
		void TouchReleased(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION()
		void TouchMoved(ETouchIndex::Type FingerIndex, FVector Location);

private:

	UPROPERTY(EditDefaultsOnly)
		float MovementForce;

	UPROPERTY()
	APlayerController* PlayerController;

};
