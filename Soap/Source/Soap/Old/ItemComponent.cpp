// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemComponent.h"

#include "Antagonist.h"
#include "../Soap.h"


// Sets default values for this component's properties
UItemComponent::UItemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;




	

}


// Called when the game starts
void UItemComponent::BeginPlay()
{
	Super::BeginPlay();

	OwningActor = GetOwner();

	

	//Use default gun equipped 
	EquippedItem = StartItem.GetDefaultObject();

	//Use the default item
	Use();

}


// Called every frame
void UItemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(EquippedItem)
	{
		EquippedItem->Tick(DeltaTime);
	}
}

void UItemComponent::Use()
{
	EquippedItem->Initialize(this, GetOwner());
	EquippedItem->Use();


}

