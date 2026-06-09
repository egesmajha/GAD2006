#include "TileBase.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

ATileBase::ATileBase()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	InstancedMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedMesh"));
	InstancedMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(
		TEXT("/Engine/BasicShapes/Cube.Cube")
	);

	if (CubeMesh.Succeeded())
	{
		InstancedMesh->SetStaticMesh(CubeMesh.Object);
	}

	InstancedMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ATileBase::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (!BaseMesh) return;

	InstancedMesh->SetStaticMesh(BaseMesh);
}

void ATileBase::BeginPlay()
{
	Super::BeginPlay();
}

void ATileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}