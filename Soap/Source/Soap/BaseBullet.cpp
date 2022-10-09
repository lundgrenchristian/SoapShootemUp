// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBullet.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABaseBullet::ABaseBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovement->InitialSpeed = 800.0f;
	ProjectileMovement->MaxSpeed = 800.0f;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));


	
}

// Called when the game starts or when spawned
void ABaseBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
