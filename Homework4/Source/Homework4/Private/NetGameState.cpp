#include "NetGameState.h"
#include "NetPlayerState.h"
#include "Net/UnrealNetwork.h"

ANetGameState::ANetGameState()
{
	WinningPlayer = -1;

	GameResult = EGameResult::RESULT_Undefined;
}

void ANetGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANetGameState, WinningPlayer);
	DOREPLIFETIME(ANetGameState, GameResult);
}
ANetPlayerState* ANetGameState::GetPlayerStateByIndex(int PlayerIndex)
{
	for (APlayerState* PS : PlayerArray)
	{
		ANetPlayerState* State = Cast<ANetPlayerState>(PS);

		if (State && State->PlayerIndex == PlayerIndex)
		{
			return State;
		}
	}

	return nullptr;
}
void ANetGameState::OnRep_WinningPlayer()
{
	if (WinningPlayer >= 0)
	{
		OnVictory();
	}
}

void ANetGameState::OnRep_GameResult()
{
	if (GameResult != EGameResult::RESULT_Undefined)
	{
		OnVictory();
	}
}

void ANetGameState::TriggerRestart_Implementation()
{
	OnRestart();
}

ANetPlayerState* ANetGameState::GetPlayerStateByIndex(int PlayerIndexToFind) const
{
	for (APlayerState* PS : PlayerArray)
	{
		ANetPlayerState* NetPS = Cast<ANetPlayerState>(PS);

		if (NetPS && NetPS->PlayerIndex == PlayerIndexToFind)
		{
			return NetPS;
		}
	}

	return nullptr;
}
