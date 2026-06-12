#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "NetGameInstance.h"
#include "NetPlayerState.generated.h"

UCLASS()
class HOMEWORK4_API ANetPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ANetPlayerState();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	int PlayerIndex;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing = OnRep_PlayerInfo, BlueprintReadOnly)
	FSPlayerInfo PlayerInfo;


	UPROPERTY(Replicated, BlueprintReadOnly)
	EPlayerTeam Team;

	UPROPERTY(BlueprintReadOnly)
	bool bPlayerInfoReceived;

	UFUNCTION()
	void OnRep_PlayerInfo();
};
