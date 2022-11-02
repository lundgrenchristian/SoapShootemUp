// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBullet.h"
#include "Bullet0.generated.h"

/**
 * 
 */
UCLASS()
class SOAP_API ABullet0 : public ABaseBullet
{
	GENERATED_BODY()

private:
		ABullet0();

protected:

	virtual void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BubbleExpandTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BubbleBulletSize;

	UPROPERTY()
		float BubbleExpandCounter;

};
