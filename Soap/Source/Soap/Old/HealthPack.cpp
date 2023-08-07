// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPack.h"
#include "BaseCharacter.h"

UHealthPack::UHealthPack()
{
	
}


void UHealthPack::Use()
{
	Super::Use();

	Cast<ABaseCharacter>(OwningActor)->RestoreHealth(AmountToHeal);
}

void UHealthPack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
