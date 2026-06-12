#include "NetPlayerState.h"
#include "NetBaseCharacter.h"
#include "Net/UnrealNetwork.h"

ANetPlayerState::ANetPlayerState()
{
	PlayerIndex = -1;
	Team = EPlayerTeam::TEAM_Unknown;
	bPlayerInfoReceived = false;
}

void ANetPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANetPlayerState, PlayerInfo);
	DOREPLIFETIME(ANetPlayerState, PlayerIndex);
	DOREPLIFETIME(ANetPlayerState, Team);
	DOREPLIFETIME(ANetPlayerState, PlayerIndex);

}

void ANetPlayerState::OnRep_PlayerInfo()
{
	bPlayerInfoReceived = true;

	ANetBaseCharacter* Char = Cast<ANetBaseCharacter>(GetPawn());

	if (Char)
	{
		Char->SubmitPlayerInfo(PlayerInfo);
	}
}
