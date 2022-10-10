// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun0.h"

#include "Antagonist.h"
#include "Soap.h"
#include "Bullet0.h"

UGun0::UGun0()
{
	
}

void UGun0::Use()
{
	Super::Use();



}

void UGun0::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void UGun0::Shoot()
{
	
	
	Super::Shoot();
	World->SpawnActor<ABullet0>(Bullet, Antagonist->GetActorLocation() , Antagonist->GetActorRotation());

	UE_LOG(LogSoap, Warning, TEXT("%s"), *Antagonist->GetActorLocation().ToString());

}
