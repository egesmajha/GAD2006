#include "NetBaseCharacter.h"
#include "NetPlayerState.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DataTable.h"
#include "TimerManager.h"

static UDataTable* SBodyParts = nullptr;

static const TArray<FString> BodyPartNames
{
	TEXT("Face"),
	TEXT("Hair"),
	TEXT("Chest"),
	TEXT("Hands"),
	TEXT("Legs"),
	TEXT("Beard"),
	TEXT("BodyType")
};

ANetBaseCharacter::ANetBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bPlayerInfoReceived = false;

	PartFace = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Face"));
	PartFace->SetupAttachment(GetMesh());
	PartFace->SetLeaderPoseComponent(GetMesh());

	PartHands = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hands"));
	PartHands->SetupAttachment(GetMesh());
	PartHands->SetLeaderPoseComponent(GetMesh());

	PartLegs = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Legs"));
	PartLegs->SetupAttachment(GetMesh());
	PartLegs->SetLeaderPoseComponent(GetMesh());

	PartHair = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hair"));
	PartHair->SetupAttachment(PartFace, FName("headSocket"));

	PartBeard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Beard"));
	PartBeard->SetupAttachment(PartFace, FName("headSocket"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SK_Eyes(TEXT("StaticMesh'/Game/StylizedModularChar/Meshes/SM_Eyes.SM_Eyes'"));

	PartEyes = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Eyes"));
	PartEyes->SetupAttachment(PartFace, FName("headSocket"));

	if (SK_Eyes.Succeeded())
	{
		PartEyes->SetStaticMesh(SK_Eyes.Object);
	}

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_BodyParts(TEXT("DataTable'/Game/Blueprints/DT_BodyParts.DT_BodyParts'"));

	if (DT_BodyParts.Succeeded())
	{
		SBodyParts = DT_BodyParts.Object;
	}
}

void ANetBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GetNetMode() == NM_Standalone)
	{
		return;
	}

	SetActorHiddenInGame(true);
	CheckPlayerState();
}

void ANetBaseCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UpdateBodyParts();
}

void ANetBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANetBaseCharacter::ChangeBodyPart(EBodyPart index, int32 value, bool DirectSet)
{
	if (index == EBodyPart::BP_COUNT)
	{
		return;
	}

	FSMeshAssetList* List = GetBodyPartList(index, PartSelection.isFemale);

	if (List == nullptr)
	{
		return;
	}

	int32 CurrentIndex = PartSelection.Indices[(int32)index];

	if (DirectSet)
	{
		CurrentIndex = value;
	}
	else
	{
		CurrentIndex += value;
	}

	int32 Num = List->ListSkeletal.Num() + List->ListStatic.Num();

	if (Num <= 0)
	{
		return;
	}

	if (CurrentIndex < 0)
	{
		CurrentIndex += Num;
	}
	else
	{
		CurrentIndex %= Num;
	}

	PartSelection.Indices[(int32)index] = CurrentIndex;

	switch (index)
	{
	case EBodyPart::BP_Face:
		if (List->ListSkeletal.IsValidIndex(CurrentIndex))
		{
			PartFace->SetSkeletalMeshAsset(List->ListSkeletal[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Beard:
		if (List->ListStatic.IsValidIndex(CurrentIndex))
		{
			PartBeard->SetStaticMesh(List->ListStatic[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Chest:
		if (List->ListSkeletal.IsValidIndex(CurrentIndex))
		{
			GetMesh()->SetSkeletalMeshAsset(List->ListSkeletal[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Hair:
		if (List->ListStatic.IsValidIndex(CurrentIndex))
		{
			PartHair->SetStaticMesh(List->ListStatic[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Hands:
		if (List->ListSkeletal.IsValidIndex(CurrentIndex))
		{
			PartHands->SetSkeletalMeshAsset(List->ListSkeletal[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_Legs:
		if (List->ListSkeletal.IsValidIndex(CurrentIndex))
		{
			PartLegs->SetSkeletalMeshAsset(List->ListSkeletal[CurrentIndex]);
		}
		break;

	case EBodyPart::BP_BodyType:
		UpdateBodyParts();
		break;

	default:
		break;
	}
}

void ANetBaseCharacter::ChangeGender(bool _isFemale)
{
	PartSelection.isFemale = _isFemale;
	UpdateBodyParts();
}

void ANetBaseCharacter::UpdateBodyParts()
{
	ChangeBodyPart(EBodyPart::BP_Face, 0, false);
	ChangeBodyPart(EBodyPart::BP_Beard, 0, false);
	ChangeBodyPart(EBodyPart::BP_Chest, 0, false);
	ChangeBodyPart(EBodyPart::BP_Hair, 0, false);
	ChangeBodyPart(EBodyPart::BP_Hands, 0, false);
	ChangeBodyPart(EBodyPart::BP_Legs, 0, false);
}

FSMeshAssetList* ANetBaseCharacter::GetBodyPartList(EBodyPart part, bool isFemale)
{
	if (SBodyParts == nullptr)
	{
		return nullptr;
	}

	if (!BodyPartNames.IsValidIndex((int32)part))
	{
		return nullptr;
	}

	FString Name = FString::Printf(TEXT("%s%s"), isFemale ? TEXT("Female") : TEXT("Male"), *BodyPartNames[(int32)part]);

	return SBodyParts->FindRow<FSMeshAssetList>(*Name, nullptr);
}

FString ANetBaseCharacter::GetCustomizationData() const
{
	FString Data;

	for (int32 i = 0; i < (int32)EBodyPart::BP_COUNT; ++i)
	{
		Data += FString::FromInt(PartSelection.Indices[i]);

		if (i < ((int32)EBodyPart::BP_COUNT) - 1)
		{
			Data += TEXT(",");
		}
	}

	return Data;
}

void ANetBaseCharacter::ParseCustomizationData(const FString& Data)
{
	TArray<FString> ArrayData;
	Data.ParseIntoArray(ArrayData, TEXT(","));

	for (int32 i = 0; i < ArrayData.Num() && i < (int32)EBodyPart::BP_COUNT; ++i)
	{
		PartSelection.Indices[i] = FCString::Atoi(*ArrayData[i]);
	}
}

void ANetBaseCharacter::SubmitPlayerInfo(const FSPlayerInfo& NewPlayerInfo)
{
	PlayerInfo = NewPlayerInfo;
	bPlayerInfoReceived = true;

	ParseCustomizationData(PlayerInfo.CustomizationData);
	UpdateBodyParts();
	OnPlayerInfoChanged();
	SetActorHiddenInGame(false);
}

void ANetBaseCharacter::SubmitPlayerInfoToServer_Implementation(FSPlayerInfo Info)
{
	ANetPlayerState* State = GetPlayerState<ANetPlayerState>();

	if (!State)
	{
		return;
	}

	State->PlayerInfo.NickName = Info.NickName;
	State->PlayerInfo.CustomizationData = Info.CustomizationData;
	State->PlayerInfo.Team = State->Team;
	State->bPlayerInfoReceived = true;

	SubmitPlayerInfo(State->PlayerInfo);
}

void ANetBaseCharacter::CheckPlayerState()
{
	ANetPlayerState* State = GetPlayerState<ANetPlayerState>();

	if (State == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("State == nullptr"));

		GetWorldTimerManager().SetTimer(
			CheckPlayerStateTimerHandle,
			this,
			&ANetBaseCharacter::CheckPlayerState,
			0.25f,
			false
		);

		return;
	}

	if (IsLocallyControlled())
	{
		UNetGameInstance* Instance = Cast<UNetGameInstance>(GetWorld()->GetGameInstance());

		if (Instance)
		{
			SubmitPlayerInfoToServer(Instance->PlayerInfo);
		}
	}

	CheckPlayerInfo();
}

void ANetBaseCharacter::CheckPlayerInfo()
{
	ANetPlayerState* State = GetPlayerState<ANetPlayerState>();

	if (State && State->bPlayerInfoReceived)
	{
		SubmitPlayerInfo(State->PlayerInfo);
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("State Not Received!"));

	GetWorldTimerManager().SetTimer(
		CheckPlayerInfoTimerHandle,
		this,
		&ANetBaseCharacter::CheckPlayerInfo,
		0.25f,
		false
	);
}