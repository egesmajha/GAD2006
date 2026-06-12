#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "NetGameInstance.h"
#include "NetBaseCharacter.generated.h"

UENUM(BlueprintType)
enum class EBodyPart : uint8
{
	BP_Face = 0,
	BP_Hair = 1,
	BP_Chest = 2,
	BP_Hands = 3,
	BP_Legs = 4,
	BP_Beard = 5,
	BP_BodyType = 6,
	BP_COUNT = 7
};

USTRUCT(BlueprintType)
struct FSMeshAssetList : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<USkeletalMesh*> ListSkeletal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UStaticMesh*> ListStatic;
};

USTRUCT(BlueprintType)
struct FSBodyPartSelection
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Indices[7];

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isFemale;

	FSBodyPartSelection()
	{
		for (int32 i = 0; i < 7; ++i)
		{
			Indices[i] = 0;
		}

		isFemale = false;
	}
};

UCLASS()
class HOMEWORK4_API ANetBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ANetBaseCharacter();

	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ChangeBodyPart(EBodyPart index, int32 value, bool DirectSet);

	UFUNCTION(BlueprintCallable)
	void ChangeGender(bool _isFemale);

	UFUNCTION(BlueprintPure)
	FString GetCustomizationData() const;

	UFUNCTION(BlueprintCallable)
	void ParseCustomizationData(const FString& Data);

	UFUNCTION(BlueprintCallable)
	void SubmitPlayerInfo(const FSPlayerInfo& NewPlayerInfo);

	UFUNCTION(Server, Reliable)
	void SubmitPlayerInfoToServer(FSPlayerInfo Info);

	UFUNCTION()
	void CheckPlayerState();

	UFUNCTION()
	void CheckPlayerInfo();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerInfoChanged();

	UPROPERTY(BlueprintReadWrite)
	FSBodyPartSelection PartSelection;

	UPROPERTY(BlueprintReadOnly)
	FSPlayerInfo PlayerInfo;

	UPROPERTY(BlueprintReadOnly)
	bool bPlayerInfoReceived;

private:
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* PartFace;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PartHair;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PartBeard;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* PartEyes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* PartHands;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* PartLegs;

	static FSMeshAssetList* GetBodyPartList(EBodyPart part, bool isFemale);

	void UpdateBodyParts();

	FTimerHandle CheckPlayerStateTimerHandle;
	FTimerHandle CheckPlayerInfoTimerHandle;
};