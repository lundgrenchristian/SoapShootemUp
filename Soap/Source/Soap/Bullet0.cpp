// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet0.h"
#include "BaseCharacter.h"

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
