// Fill out your copyright notice in the Description page of Project Settings.


#include "GunComponent.h"
#include "Antagonist.h"


// Sets default values for this component's properties
UGunComponent::UGunComponent(): FireCounter(0.0f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	Antagonist = Cast<AAntagonist>(GetOwner());

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

	
	FireCounter += DeltaTime;

	if (EquippedGun->FireRate <= FireCounter)
	{
		EquippedGun->Shoot();
		FireCounter = 0.0f;
	}



}

void UGunComponent::Use()
{
	
	Antagonist->GunMesh->SetStaticMesh(EquippedGun->Mesh);
	
	EquippedGun->World = World;
	EquippedGun->Use();
	EquippedGun->Antagonist = Antagonist;

}

