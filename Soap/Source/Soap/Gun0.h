// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseGun.h"
#include "Gun0.generated.h"

/**
 * 
 */
UCLASS()
class SOAP_API UGun0 : public UBaseGun
{
	GENERATED_BODY()

		UGun0();


	virtual void Use()override;


	virtual void Tick(float DeltaTime) override;

	
	
	virtual void Shoot() override;

	
	
};
