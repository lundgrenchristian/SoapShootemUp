// Fill out your copyright notice in the Description page of Project Settings.


#include "BFL.h"
#include "../Soap.h"

TArray<FVector> UBFL::ScreenToWorldLocation(FVector2D ScreenLocation, APlayerController* PlayerController)
{
	FHitResult HitResult;

	PlayerController->GetHitResultAtScreenPosition(ScreenLocation, ECC_WorldStatic, false, HitResult);

	UE_LOG(LogSoap, Warning, TEXT("Game is running %s"), *HitResult.Location.ToString());
	DrawDebugLine(PlayerController->GetWorld(), HitResult.Location ,HitResult.Location + FVector(0.f, 0.f, 1000.0f), FColor::Red, true, 1000.0f);

	TArray<FVector> Array;

	Array.Add(HitResult.TraceStart);
	Array.Add(HitResult.TraceEnd);

	return Array;




}
	