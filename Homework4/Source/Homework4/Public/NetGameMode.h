#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NetGameInstance.h"
#include "NetGameMode.generated.h"

class ANetAvatar;
class ANetPlayerState;

UCLASS()
class HOMEWORK4_API ANetGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANetGameMode();

	virtual FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal) override;
	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;
	virtual void PostLogin(APlayerController* NewPlayer) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BluePlayerIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RestartDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BlueWinTime;

	UPROPERTY()
	TArray<APlayerController*> AllPlayers;

	FTimerHandle RestartTimerHandle;
	FTimerHandle BlueWinTimerHandle;

	FString FindPlayerStartTag(int Index, EPlayerTeam Team) const;
	void AssignTeams();
	void CheckVictory();
	void RedTeamWon(ANetPlayerState* WinningPlayerState);
	void BlueTeamWon();
	void RestartMatchAfterVictory();

	UFUNCTION(BlueprintCallable)
	void OnAvatarOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
