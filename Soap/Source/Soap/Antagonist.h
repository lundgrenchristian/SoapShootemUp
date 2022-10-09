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

	UPROPERTY(EditAnywhere)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;

	//GUNS
	UPROPERTY(EditAnywhere)
	class UGunComponent* GunComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* GunMesh;


protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaSeconds) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;


	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	
};


