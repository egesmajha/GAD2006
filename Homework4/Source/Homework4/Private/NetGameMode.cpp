#include "NetGameMode.h"
#include "NetAvatar.h"
#include "NetPlayerState.h"
#include "NetGameState.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "TimerManager.h"

ANetGameMode::ANetGameMode()
{
	DefaultPawnClass = ANetAvatar::StaticClass();
	PlayerStateClass = ANetPlayerState::StaticClass();
	GameStateClass = ANetGameState::StaticClass();

	BluePlayerIndex = 0;
	RestartDelay = 2.5f;
	BlueWinTime = 30.0f;
}

FString ANetGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{
	FString Result = Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);

	AllPlayers.AddUnique(NewPlayerController);
	AssignTeams();

	return Result;
}

void ANetGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	AllPlayers.AddUnique(NewPlayer);
	AssignTeams();

	if (ANetAvatar* Avatar = Cast<ANetAvatar>(NewPlayer->GetPawn()))
	{
		Avatar->OnActorBeginOverlap.AddDynamic(this, &ANetGameMode::OnAvatarOverlap);
	}

	GetWorldTimerManager().ClearTimer(BlueWinTimerHandle);
	GetWorldTimerManager().SetTimer(BlueWinTimerHandle, this, &ANetGameMode::BlueTeamWon, BlueWinTime, false);
}

AActor* ANetGameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	ANetPlayerState* NetPS = Player ? Player->GetPlayerState<ANetPlayerState>() : nullptr;

	if (!NetPS)
	{
		return Super::ChoosePlayerStart_Implementation(Player);
	}

	const FString DesiredTag = FindPlayerStartTag(NetPS->PlayerIndex, NetPS->Team);

	TArray<AActor*> PlayerStarts;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), PlayerStarts);

	for (AActor* Start : PlayerStarts)
	{
		APlayerStart* PS = Cast<APlayerStart>(Start);

		if (PS && PS->PlayerStartTag == FName(*DesiredTag))
		{
			return PS;
		}
	}

	return Super::ChoosePlayerStart_Implementation(Player);
}

FString ANetGameMode::FindPlayerStartTag(int Index, EPlayerTeam Team) const
{
	if (Team == EPlayerTeam::TEAM_Blue)
	{
		return TEXT("Blue");
	}

	return FString::Printf(TEXT("Red_%d"), Index);
}

void ANetGameMode::AssignTeams()
{
	for (int32 i = 0; i < AllPlayers.Num(); ++i)
	{
		APlayerController* PC = AllPlayers[i];

		if (!PC)
		{
			continue;
		}

		ANetPlayerState* NetPS = PC->GetPlayerState<ANetPlayerState>();

		if (!NetPS)
		{
			continue;
		}

		NetPS->PlayerIndex = i;
		NetPS->Team = (i == BluePlayerIndex) ? EPlayerTeam::TEAM_Blue : EPlayerTeam::TEAM_Red;
		NetPS->PlayerInfo.Team = NetPS->Team;
	}
}

void ANetGameMode::OnAvatarOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ANetAvatar* AvatarA = Cast<ANetAvatar>(OverlappedActor);
	ANetAvatar* AvatarB = Cast<ANetAvatar>(OtherActor);

	if (!AvatarA || !AvatarB)
	{
		return;
	}

	ANetPlayerState* PSA = AvatarA->GetPlayerState<ANetPlayerState>();
	ANetPlayerState* PSB = AvatarB->GetPlayerState<ANetPlayerState>();

	if (!PSA || !PSB)
	{
		return;
	}

	if (PSA->Team == EPlayerTeam::TEAM_Red && PSB->Team == EPlayerTeam::TEAM_Blue)
	{
		RedTeamWon(PSA);
	}
	else if (PSB->Team == EPlayerTeam::TEAM_Red && PSA->Team == EPlayerTeam::TEAM_Blue)
	{
		RedTeamWon(PSB);
	}
}

void ANetGameMode::CheckVictory()
{
	// Victory is checked by overlap for Red team and by timer for Blue team.
}

void ANetGameMode::RedTeamWon(ANetPlayerState* WinningPlayerState)
{
	if (!WinningPlayerState)
	{
		return;
	}

	ANetGameState* NetGS = GetGameState<ANetGameState>();

	if (NetGS)
	{
		NetGS->WinningPlayer = WinningPlayerState->PlayerIndex;
		NetGS->GameResult = EGameResult::RESULT_Won;
		NetGS->OnRep_WinningPlayer();
	}

	GetWorldTimerManager().ClearTimer(BlueWinTimerHandle);
	GetWorldTimerManager().SetTimer(RestartTimerHandle, this, &ANetGameMode::RestartMatchAfterVictory, RestartDelay, false);
}

void ANetGameMode::BlueTeamWon()
{
	ANetGameState* NetGS = GetGameState<ANetGameState>();

	if (NetGS)
	{
		NetGS->WinningPlayer = BluePlayerIndex;
		NetGS->GameResult = EGameResult::RESULT_Won;
		NetGS->OnRep_WinningPlayer();
	}

	GetWorldTimerManager().SetTimer(RestartTimerHandle, this, &ANetGameMode::RestartMatchAfterVictory, RestartDelay, false);
}

void ANetGameMode::RestartMatchAfterVictory()
{
	if (AllPlayers.Num() > 1)
	{
		// Simple picking logic: blue role moves to the next connected player.
		// This satisfies the assignment requirement and is predictable for testing.
		BluePlayerIndex = (BluePlayerIndex + 1) % AllPlayers.Num();
	}

	AssignTeams();

	ANetGameState* NetGS = GetGameState<ANetGameState>();

	if (NetGS)
	{
		NetGS->WinningPlayer = -1;
		NetGS->GameResult = EGameResult::RESULT_Undefined;
		NetGS->TriggerRestart_Implementation();
	}

	for (APlayerController* PC : AllPlayers)
	{
		if (!PC)
		{
			continue;
		}

		if (APawn* Pawn = PC->GetPawn())
		{
			Pawn->Destroy();
		}

		RestartPlayer(PC);

		if (ANetAvatar* Avatar = Cast<ANetAvatar>(PC->GetPawn()))
		{
			Avatar->OnActorBeginOverlap.AddDynamic(this, &ANetGameMode::OnAvatarOverlap);
		}
	}

	GetWorldTimerManager().ClearTimer(BlueWinTimerHandle);
	GetWorldTimerManager().SetTimer(BlueWinTimerHandle, this, &ANetGameMode::BlueTeamWon, BlueWinTime, false);
}
