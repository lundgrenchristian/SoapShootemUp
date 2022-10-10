// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGun.h"

UBaseGun::UBaseGun(): FireCounter(0.0f)
{
	
}

void UBaseGun::Use()
{
}

void UBaseGun::Tick(float DeltaTime)
{
	FireCounter += DeltaTime;

	if(FireRate <= FireCounter)
	{
		Shoot();
		FireCounter = 0.0f;
	}


}

void UBaseGun::Shoot()
{
}

