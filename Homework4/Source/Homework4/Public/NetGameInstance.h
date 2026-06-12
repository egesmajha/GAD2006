#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NetGameInstance.generated.h"

UENUM(BlueprintType)
enum class EPlayerTeam : uint8
{
	TEAM_Unknown,
	TEAM_Blue,
	TEAM_Red
};

UENUM(BlueprintType)
enum class EGameResult : uint8
{
	RESULT_Undefined,
	RESULT_Lost,
	RESULT_Won
};

USTRUCT(BlueprintType)
struct FSPlayerInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NickName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CustomizationData;

	UPROPERTY(BlueprintReadOnly)
	EPlayerTeam Team;

	FSPlayerInfo()
		: NickName(TEXT("Player"))
		, CustomizationData(TEXT(""))
		, Team(EPlayerTeam::TEAM_Unknown)
	{
	}
};

UCLASS()
class HOMEWORK4_API UNetGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSPlayerInfo PlayerInfo;

	UFUNCTION(BlueprintCallable)
	void HostGame(FString MapName, FSPlayerInfo Info);

	UFUNCTION(BlueprintCallable)
	void Join(FString Address, FSPlayerInfo Info);
};
