// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BFL.generated.h"

/**
 * 
 */
UCLASS()
class SOAP_API UBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	UFUNCTION(BlueprintCallable, Category = "Analytics")
	static FVector ScreenToWorldLocation(FVector2D ScreenLocation, APlayerController* PlayerController);
	 
};
