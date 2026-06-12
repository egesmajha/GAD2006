#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "NetGameInstance.h"
#include "NetGameState.generated.h"

class ANetPlayerState;

UCLASS()
class HOMEWORK4_API ANetGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ANetGameState();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing = OnRep_WinningPlayer, EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 WinningPlayer;


	UFUNCTION(BlueprintCallable)
	ANetPlayerState* GetPlayerStateByIndex(int PlayerIndex);

	UPROPERTY(ReplicatedUsing = OnRep_GameResult)
	EGameResult GameResult;

	UFUNCTION()
	void OnRep_WinningPlayer();

	UFUNCTION()
	void OnRep_GameResult();

	UFUNCTION(BlueprintImplementableEvent)
	void OnVictory();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRestart();

	UFUNCTION()
	void TriggerRestart_Implementation();

	ANetPlayerState* GetPlayerStateByIndex(int PlayerIndex) const;
};
