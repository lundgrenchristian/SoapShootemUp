// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBullet.h"
#include "Item.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class SOAP_API UGun : public UItem
{
	GENERATED_BODY()

		UGun();

public:



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet")
		TSubclassOf<ABaseBullet> Bullet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire Rate")
		float FireRate;


	UPROPERTY()
		float FireCounter;

	virtual void Use()override;




	virtual void Tick(float DeltaTime) override;


	virtual void Shoot();
	
};
