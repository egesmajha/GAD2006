// Fill out your copyright notice in the Description page of Project Settings.

#include "TilePlayerController.h"
#include "TileGameManager.h"

void ATilePlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
}

void ATilePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GameManager == nullptr) return;

	FHitResult HitResult;
	FVector WorldLocation;
	FVector WorldDirection;

	if (DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
	{
		if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			WorldLocation,
			WorldLocation + WorldDirection * 50000.0f,
			ECC_Visibility
		))
		{
			AActor* HitActor = HitResult.GetActor();

			GameManager->OnActorInteraction(
				HitActor,
				HitResult.Location,
				IsInputKeyDown(EKeys::LeftMouseButton)
			);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No hit detected"));
		}
	}
}