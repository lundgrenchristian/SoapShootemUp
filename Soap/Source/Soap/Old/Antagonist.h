// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Antagonist.generated.h"

/**
 * 
 */
UCLASS()
class SOAP_API AAntagonist : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AAntagonist();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void TouchPressed(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION()
	void TouchReleased(ETouchIndex::Type FingerIndex, FVector Location);

	UFUNCTION()
	void TouchMoved(ETouchIndex::Type FingerIndex, FVector Location);

public:
	UPROPERTY(EditDefaultsOnly)
	class UItemComponent* ItemComponent;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* GunMesh;

	UPROPERTY(EditDefaultsOnly)
	class USceneComponent* Muzzle;


private:


	bool bMoving;

	FVector MoveLocation;

	UPROPERTY()
		class ASoapGameState* GameState;

	UPROPERTY(EditDefaultsOnly)
		float MovementForce;


};


