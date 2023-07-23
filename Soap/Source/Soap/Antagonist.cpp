// Fill out your copyright notice in the Description page of Project Settings.

#include "Antagonist.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ItemComponent.h"

#include "Soap.h"
#include "SoapGameState.h"
#include "Components/CapsuleComponent.h"


AAntagonist::AAntagonist(): bMoving(false), MovementForce(1000.0f)	
{
	/*
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	SpringArm->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 1000.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 1.0f;*/

	


	
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

	GameState = Cast<ASoapGameState>(GetWorld()->GetGameState());
}


void AAntagonist::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//Set rotation to mouse position
	{
		//const APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

		//FVector MouseLocation, MouseDirection;
		//PlayerController->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);


		//FVector LookDirection = MouseLocation + (MouseDirection * 1000.0f);
		//LookDirection = LookDirection - GetActorLocation();
		//FRotator TargetRotation = LookDirection.Rotation();
		//FRotator NewRotation = FRotator(0, TargetRotation.Yaw, 0);

		//SetActorRotation(NewRotation);






	}


	const APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	FVector MouseLocation, MouseDirection;
	PlayerController->DeprojectMousePositionToWorld(MouseLocation, MouseDirection);

	float DistanceToEnemy = FLT_MAX;
	AActor* Enemy = nullptr;

	for(int i = 0; i < GameState->EnemyArray.Num(); i++)
	{
		if((GameState->EnemyArray[i]->GetActorLocation() - GetActorLocation()).Length() < DistanceToEnemy)
		{
			Enemy = GameState->EnemyArray[i];
			DistanceToEnemy = (GameState->EnemyArray[i]->GetActorLocation() - GetActorLocation()).Length();
		}
	}

	
	if(Enemy)
	{
		FVector LookDirection = Enemy->GetActorLocation() - GetActorLocation();
		FRotator TargetRotation = LookDirection.Rotation();
		FRotator NewRotation = FRotator(0, TargetRotation.Yaw, 0);

		SetActorRotation(NewRotation);

	}
	
	











	//if (bMoving)
	//{
	//	float Direction = -1;

	//	if(GetActorLocation().X < MoveLocation.X)
	//	{
	//		Direction = 1;
	//	}

	//	AddMovementInput(FVector(Direction, 0.0f, 0.0f), 1.0f);

	//	if (GetActorLocation().X - MoveLocation.X > 5)
	//	{
	//		bMoving = false;
	//	}
	//}



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

	//PlayerInputComponent->BindAxis("MoveForward", this, &AAntagonist::MoveForward);

	//PlayerInputComponent->BindAxis("MoveRight", this, &AAntagonist::MoveRight);

	InputComponent->BindTouch(IE_Pressed, this, &ThisClass::TouchPressed);
	InputComponent->BindTouch(IE_Released, this, &ThisClass::TouchReleased);
	InputComponent->BindTouch(IE_Repeat, this, &ThisClass::TouchMoved);


}

void AAntagonist::MoveForward(float Value)
{
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);

	//UE_LOG(LogSoap, Warning, TEXT("Game is running %s %f"), *Direction.ToString(), Value);
}

void AAntagonist::MoveRight(float Value)
{

	int PlayingField = 1000;
	int Positions = 4;
	int Distance = Value* (PlayingField / Positions);

	int ActorLocation = GetActorLocation().X; 

	int NewLocation = (ActorLocation + Distance) % PlayingField;

	MoveLocation.X = NewLocation;
	


}

void AAntagonist::TouchPressed(ETouchIndex::Type FingerIndex, FVector Location)
{
	/*if(bMoving)
	{
		return;
	}

	if(Location.X <= GSystemResolution.ResX)
	{
		MoveRight(-1);
	}
	else
	{
		MoveRight(1);
	}

	bMoving = true;*/

	const APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	FVector MouseLocation, MouseDirection;

	
	FHitResult HitResult;

	PlayerController->GetHitResultAtScreenPosition(FVector2D(Location.X, Location.Y), ECollisionChannel::ECC_WorldStatic, false, HitResult);


	//UE_LOG(LogSoap, Warning, TEXT("Game is running %s"), *HitResult.Location.ToString());



	//DrawDebugLine(GetWorld(), HitResult.Location ,HitResult.Location + FVector(0.f, 0.f, 1000.0f), FColor::Red, true, 1000.0f);

	FVector LookDirection = HitResult.Location - GetActorLocation();
	
	LookDirection.Normalize();
	LookDirection *= MovementForce;

	GetCapsuleComponent()->AddForce(LookDirection, "", true);
	

}

void AAntagonist::TouchReleased(ETouchIndex::Type FingerIndex, FVector Location)
{
}

void AAntagonist::TouchMoved(ETouchIndex::Type FingerIndex, FVector Location)
{
}
