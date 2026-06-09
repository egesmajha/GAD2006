// Fill out your copyright notice in the Description page of Project Settings.

#include "TileGameManager.h"
#include "TileBase.h"
#include "GameFramework/PlayerInput.h"
#include "TilePlayerController.h"

ATileGameManager::ATileGameManager() :
	GridSize(100),
	GridOffset(0, 0, 0.5f),
	MapExtendsInGrids(25),
	CurrentTileIndex(0),
	CurrentTileYaw(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	GridSelection = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GridMesh"));
	GridSelection->SetupAttachment(RootComponent);

	CurrentTileDisplay = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CurrentTileDisplay"));
	CurrentTileDisplay->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneMesh(TEXT("/Engine/BasicShapes/Plane"));

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> GridMaterial(
		TEXT("/Game/UI/MAT_GridSlot.MAT_GridSlot"));

	GridSelection->SetStaticMesh(PlaneMesh.Object);
	GridSelection->SetMaterial(0, GridMaterial.Object);
	GridSelection->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CurrentTileDisplay->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	for (int X = 0; X < MAX_MAP_GRID_SIZE; X++)
	{
		for (int Y = 0; Y < MAX_MAP_GRID_SIZE; Y++)
		{
			Map[X][Y] = nullptr;
		}
	}
}

void ATileGameManager::BeginPlay()
{
	Super::BeginPlay();

	if (auto PlayerController = Cast<ATilePlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		PlayerController->GameManager = this;
	}
}

void ATileGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATileGameManager::OnActorInteraction(AActor* Actor, FVector Location, bool IsPressed)
{
	FVector GridLoc = GridOffset;
	GridLoc.X += FMath::GridSnap(Location.X, GridSize);
	GridLoc.Y += FMath::GridSnap(Location.Y, GridSize);
	GridLoc.Z += Location.Z;

	UPlayerInput* Input = GetWorld()->GetFirstPlayerController()->PlayerInput;

	if (TileTypes.Num() > 0 && TileTypes.IsValidIndex(CurrentTileIndex))
	{
		ATileBase* SelectedTile = TileTypes[CurrentTileIndex];

		if (SelectedTile && SelectedTile->BaseMesh)
		{
			CurrentTileDisplay->SetStaticMesh(SelectedTile->BaseMesh);
			CurrentTileDisplay->SetWorldLocation(GridLoc);
			CurrentTileDisplay->SetWorldRotation(FRotator(0.0f, CurrentTileYaw, 0.0f));
		}
	}

	if (Input->WasJustPressed(EKeys::LeftMouseButton))
	{
		int GridX = GridLoc.X / GridSize + MapExtendsInGrids;
		int GridY = GridLoc.Y / GridSize + MapExtendsInGrids;

		if (GridX < 0 || GridY < 0 || GridX >= MapExtendsInGrids * 2 || GridY >= MapExtendsInGrids * 2)
		{
			return;
		}

		if (Map[GridX][GridY] != nullptr)
		{
			return;
		}

		if (TileTypes.IsValidIndex(CurrentTileIndex))
		{
			ATileBase* SelectedTile = TileTypes[CurrentTileIndex];

			if (!SelectedTile || !SelectedTile->InstancedMesh)
			{
				return;
			}

			Map[GridX][GridY] = SelectedTile;

			FTransform TileTransform(GridLoc + GridOffset);
			TileTransform.SetRotation(FQuat(FRotator(0.0f, CurrentTileYaw, 0.0f)));

			SelectedTile->InstancedMesh->AddInstance(
				SelectedTile->InstancedMesh->GetRelativeTransform() * TileTransform,
				true
			);
			
		}

		UE_LOG(LogTemp, Warning, TEXT("Hit: %s - %f,%f,%f"),
			Actor ? *Actor->GetName() : TEXT("None"),
			Location.X,
			Location.Y,
			Location.Z
		);
	}
	else if (Input->WasJustPressed(EKeys::RightMouseButton))
	{
		CurrentTileYaw += 90.0f;

		if (CurrentTileYaw >= 360.0f)
		{
			CurrentTileYaw = 0.0f;
		}

		UE_LOG(LogTemp, Warning, TEXT("Tile Rotation: %f"), CurrentTileYaw);
	}
	else if (Input->WasJustPressed(EKeys::MouseScrollDown))
	{
		if (TileTypes.Num() > 0)
		{
			CurrentTileIndex = (CurrentTileIndex + 1) % TileTypes.Num();

			UE_LOG(LogTemp, Warning, TEXT("TileType: %s"),
				TileTypes[CurrentTileIndex] ? *TileTypes[CurrentTileIndex]->GetName() : TEXT("None")
			);
		}
	}
	else if (Input->WasJustPressed(EKeys::MouseScrollUp))
	{
		if (TileTypes.Num() > 0)
		{
			CurrentTileIndex--;

			if (CurrentTileIndex < 0)
			{
				CurrentTileIndex = TileTypes.Num() - 1;
			}

			UE_LOG(LogTemp, Warning, TEXT("TileType: %s"),
				TileTypes[CurrentTileIndex] ? *TileTypes[CurrentTileIndex]->GetName() : TEXT("None")
			);
		}
	}
	else
	{
		GridSelection->SetWorldLocation(GridLoc);
	}
}