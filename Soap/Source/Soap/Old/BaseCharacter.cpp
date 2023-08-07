// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "../Soap.h"
#include "Components/CapsuleComponent.h"


// Sets default values
ABaseCharacter::ABaseCharacter(): Health(100.0f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
}

float ABaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Health -= DamageAmount;

	return DamageAmount;
}

void ABaseCharacter::Death()
{
	Destroy();
}

void ABaseCharacter::RestoreHealth(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.0f, 100.0f); 
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
		Death();
	}

}





