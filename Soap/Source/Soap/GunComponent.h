// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseGun.h"
#include "GunComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOAP_API UGunComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGunComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UBaseGun> EquippedGunTemplate;

	UPROPERTY()
		class AAntagonist* Antagonist;

	UPROPERTY()
	class UBaseGun* EquippedGun;

	UPROPERTY()
	class UWorld* World;

	UPROPERTY()
	float FireCounter;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION()
	void Use();
		
};
