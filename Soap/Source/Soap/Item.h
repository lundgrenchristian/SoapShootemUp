// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced) //DefaultToInstanced
class SOAP_API UItem : public UObject
{
	GENERATED_BODY()

public:

	UItem();

	
	//Initialize variables
	UPROPERTY()
		class AActor* OwningActor;

	UPROPERTY()
		class UItemComponent* ItemComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Equippable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Static Mesh")
		class UStaticMesh* Mesh;

	UFUNCTION()
	virtual void Initialize(class UItemComponent* Component, class AActor* Owning);

	UFUNCTION()
	virtual void Use();

	UFUNCTION()
	virtual void Tick(float DeltaTime);

	
	
};
