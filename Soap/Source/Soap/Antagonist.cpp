// Fill out your copyright notice in the Description page of Project Settings.

#include "Antagonist.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ItemComponent.h"

#include "Soap.h"


AAntagonist::AAntagonist()
{
	/*
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	SpringArm->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 1000.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 1.0f;*/

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//Camera->SetupAttachment(RootComponent);
	Camera->SetWorldLocation(FVector(0.0f, 0.0f, 1000.0f));
	Camera->SetWorldRotation(FRotator(-90.0f, 0.0f, 0.0f));


	
	ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("Gun Component"));

	
	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun Mesh"));
	GunMesh->SetupAttachment(RootComponent);
	GunMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	Muzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	Muzzle->SetupAttachment(GunMesh);
	


	
	
}

void AAntagonist::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->bShowMouseCursor = true;
}


void AAntagonist::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//Set rotation to mouse position
	{
		const APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

		FVector MouseLocation, MouseDirection;
		PlayerController->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);


		FVector LookDirection = MouseLocation + (MouseDirection * 1000.0f);
		LookDirection = LookDirection - GetActorLocation();
		FRotator TargetRotation = LookDirection.Rotation();
		FRotator NewRotation = FRotator(0, TargetRotation.Yaw, 0);

		SetActorRotation(NewRotation);
	}

}

void AAntagonist::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(Cast<ABaseCharacter>(OtherActor)->Health <= 0.f)
	{
		
	}
}

void AAntagonist::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAntagonist::MoveForward);

	PlayerInputComponent->BindAxis("MoveRight", this, &AAntagonist::MoveRight);

}

void AAntagonist::MoveForward(float Value)
{
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);

	//UE_LOG(LogSoap, Warning, TEXT("Game is running %s %f"), *Direction.ToString(), Value);
}

void AAntagonist::MoveRight(float Value)
{
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}