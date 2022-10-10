// Fill out your copyright notice in the Description page of Project Settings.


#include "GunComponent.h"
#include "Antagonist.h"


// Sets default values for this component's properties
UGunComponent::UGunComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	

}


// Called when the game starts
void UGunComponent::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	EquippedGun = EquippedGunTemplate.GetDefaultObject();

	//Use default gun equipped
	Use();

	
}


// Called every frame
void UGunComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(EquippedGun)
	Cast<UBaseGun>(EquippedGun)->Tick(DeltaTime);

}

void UGunComponent::Use()
{
	
	Cast<AAntagonist>(GetOwner())->GunMesh->SetStaticMesh(Cast<UBaseGun>(EquippedGun)->Mesh);

	Cast<UBaseGun>(EquippedGun)->World = World;
	Cast<UBaseGun>(EquippedGun)->Use();


}

