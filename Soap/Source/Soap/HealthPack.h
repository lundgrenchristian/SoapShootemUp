// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "HealthPack.generated.h"

/**
 * 
 */
UCLASS()
class SOAP_API UHealthPack : public UItem
{
	GENERATED_BODY()

		UHealthPack();

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AmountToHeal;

	virtual void Use() override;

	virtual void Tick(float DeltaTime) override;
};
