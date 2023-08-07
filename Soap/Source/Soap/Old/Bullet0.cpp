// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet0.h"
#include "BaseCharacter.h"

ABullet0::ABullet0(): BubbleExpandCounter(0.0f)
{
}

void ABullet0::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(ABaseCharacter* ActorHit = Cast<ABaseCharacter>(OtherActor))
	{
		if(ActorHit != GetInstigator())
		{
			FDamageEvent DamageEvent;

			ActorHit->TakeDamage(20.0f, DamageEvent, GetInstigator()->GetController(), this);
		}
		
	}
}

void ABullet0::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	BubbleExpandCounter += DeltaSeconds;

	if(BubbleExpandCounter <= BubbleExpandTime)
	{
		float const Size = BubbleBulletSize * (BubbleExpandCounter / BubbleExpandTime);

		SetActorScale3D(FVector(Size));
	}
}

void ABullet0::BeginPlay()
{
	Super::BeginPlay();


}


