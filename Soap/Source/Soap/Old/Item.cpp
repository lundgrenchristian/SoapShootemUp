// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

UItem::UItem(): Equippable(false)
{
	
}



void UItem::Initialize(UItemComponent* Component, AActor* Owning)
{
	OwningActor = Owning;
	ItemComponent = Component;
}

void UItem::Use()
{
}

void UItem::Tick(float DeltaTime)
{

}


