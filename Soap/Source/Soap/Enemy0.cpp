// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy0.h"

AEnemy0::AEnemy0()
{
	AutoPossessAI = EAutoPossessAI::Spawned;
}

void AEnemy0::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy0::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	Move();
}

void AEnemy0::Move()
{

	AddMovementInput(GetActorForwardVector(), -0.2f);

	
}

void AEnemy0::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
