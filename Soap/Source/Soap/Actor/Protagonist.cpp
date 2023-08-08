// Fill out your copyright notice in the Description page of Project Settings.


#include "Protagonist.h"

#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"

AProtagonist::AProtagonist() : MovementForce(1000.0f)
{

}

void AProtagonist::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->bShowMouseCursor = true;

}


void AProtagonist::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}



void AProtagonist::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindTouch(IE_Pressed, this, &ThisClass::TouchPressed);
	InputComponent->BindTouch(IE_Released, this, &ThisClass::TouchReleased);
	InputComponent->BindTouch(IE_Repeat, this, &ThisClass::TouchMoved);
}




void AProtagonist::TouchPressed(ETouchIndex::Type FingerIndex, FVector Location)
{
	FHitResult HitResult;
	PlayerController->GetHitResultAtScreenPosition(FVector2D(Location.X, Location.Y), ECollisionChannel::ECC_WorldStatic, false, HitResult);

	FVector LookDirection = HitResult.Location - GetActorLocation();

	LookDirection.Normalize();
	LookDirection *= MovementForce;

	GetCollisionComponent()->AddForce(FVector(LookDirection.X, LookDirection.Y, 0.0f), "", true);
}

void AProtagonist::TouchReleased(ETouchIndex::Type FingerIndex, FVector Location)
{
}

void AProtagonist::TouchMoved(ETouchIndex::Type FingerIndex, FVector Location)
{
}
