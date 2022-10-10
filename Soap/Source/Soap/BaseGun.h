// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseBullet.h"
#include "BaseGun.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced) //DefaultToInstanced
class SOAP_API UBaseGun : public UObject
{
	GENERATED_BODY()

public:

	UBaseGun();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Static Mesh")
		class UStaticMesh* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Bullet")
		TSubclassOf<ABaseBullet> Bullet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fire Rate")
		float FireRate;

	UPROPERTY()
		class UWorld* World;

	//virtual class UWorld* GetWorld() const override
	//{
	//	return World;
	//}

	UPROPERTY()
		float FireCounter;

	UFUNCTION()
	virtual void Use();

	UFUNCTION()
	virtual void Tick(float DeltaTime);

	UFUNCTION()
	virtual void Shoot();
	
};
