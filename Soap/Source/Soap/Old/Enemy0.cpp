// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy0.h"
#include "ItemComponent.h"
#include "OldGameState.h"

AEnemy0::AEnemy0()
{
	AutoPossessAI = EAutoPossessAI::Spawned;

	/*ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("Item Component"));*/

}

AEnemy0::~AEnemy0()
{

	
}

void AEnemy0::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld()->GetGameState())
	{
		Cast<AOldGameState>(GetWorld()->GetGameState())->EnemyArray.Add(this);
	}
}

void AEnemy0::Destroyed()
{
	if (GetWorld()->GetGameState())
	{
		Cast<AOldGameState>(GetWorld()->GetGameState())->EnemyArray.Remove(this);
	}
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

void AEnemy0::Death()
{
	if (DropRatePercentage >= FMath::RandRange(0.0f, 100.0f))
	{
		const TSubclassOf<AItemActor> RandomItemActor = DroppableItems[FMath::RandRange(0, DroppableItems.Num() - 1)];
		GetWorld()->SpawnActor<AItemActor>(RandomItemActor, GetActorLocation(), GetActorRotation());
	}

	Super::Death();
}

void AEnemy0::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
