// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Soap.h"
	

// Sets default values
ABaseCharacter::ABaseCharacter(): Health(100.0f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Health -= DamageAmount;

	return DamageAmount;
}

void ABaseCharacter::K2_DestroyActor()
{
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Health <= 0.0f)	
	{
		Destroy();
	}

}





