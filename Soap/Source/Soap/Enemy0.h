// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "ItemActor.h"
#include "Components/TimelineComponent.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<AItemActor>> DroppableItems;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float DropRatePercentage;



	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UItemComponent* ItemComponent;*/


	UFUNCTION()
		void Move();


	virtual void Death() override;
};
