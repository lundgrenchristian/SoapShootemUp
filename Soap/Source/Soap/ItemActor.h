// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

UCLASS()
class SOAP_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UItem> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* DisplayMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
