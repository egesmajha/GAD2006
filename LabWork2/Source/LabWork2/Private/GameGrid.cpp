// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGrid.h"

// Sets default values
AGameGrid::AGameGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

}

void AGameGrid::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
 for (auto Grid: GridActors)
 {
	 Grid->DestroyComponent();
 }

 GridActors.Empty();

 if(!GridClass->IsValidLowLevel())
 {
	 return;
 }

 AGameSlot* Slot = GridClass->GetDefaultObject<AGameSlot>();

 if(Slot == nullptr)
 {
	 return;
 }
 FVector Extends = Slot->Box->GetUnscaledBoxExtent() * 2.f;


 for (int i = 0 ; i < NumRows; i++)
 {
	 for (int j = 0; j < NumCols; j++)
	 {
		 FName GridName = FName(*FString::Printf(TEXT("Grid_%d_%d"), i, j));
		 auto Grid = NewObject<UChildActorComponent>(this,UChildActorComponent::StaticClass(), GridName);
		 Grid->RegisterComponent();
		 Grid->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		 Grid->SetRelativeLocation(FVector(
			 (NumRows - i - 1) * Extends.X - (NumRows * 0.5f - 0.5f) * Extends.Y,
			 j * Extends.Y - (NumCols * 0.5f - 0.5f) * Extends.Y, 0.f));

		 GridActors.Add(Grid);

		 Grid->SetChildActorClass(GridClass);
		 AGameSlot* GameSlot = Cast<AGameSlot>(Grid->GetChildActor());
		 GameSlot->SetActorLabel(GridName.ToString());
	 }
 }


}

// Called when the game starts or when spawned
void AGameGrid::BeginPlay()
{
	Super::BeginPlay();

	int GridIndex = 0;
	for (int i = 0; i < NumRows; i++)
	{
		for (int j = 0; j < NumCols; j++)
		{
			AGameSlot* GameSlot = Cast<AGameSlot>(GridActors[GridIndex]->GetChildActor());
			GameSlot->GridPosition = FSGridPosition(j, i);
			GridIndex++;
		}
	}
	
}

// Called every frame
void AGameGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

