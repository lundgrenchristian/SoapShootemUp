// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "Antagonist.h"
#include "Soap.h"
#include "Bullet0.h"
#include "ItemComponent.h"

UGun::UGun(): FireCounter(0.0f)
{
	
}

void UGun::Use()
{
	Super::Use();

	const AAntagonist* Antagonist = Cast<AAntagonist>(OwningActor);

	if (Equippable)
	{
		Antagonist->GunMesh->SetStaticMesh(Mesh);
	}


}

void UGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FireCounter += DeltaTime;

	if (FireRate <= FireCounter)
	{
		Shoot();
		FireCounter = 0.0f;
	}



}

void UGun::Shoot()
{

	const AAntagonist* Antagonist =  Cast<AAntagonist>(OwningActor);

	const FVector Location = Antagonist->Muzzle->GetComponentLocation();
	const FRotator Rotation = Antagonist->Muzzle->GetComponentRotation();

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Instigator = Cast<APawn>(OwningActor);

	//Super::Shoot();
	OwningActor->GetWorld()->SpawnActor<ABullet0>(Bullet, Location , Rotation, SpawnParameters);

	

}
