#include "NetGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void UNetGameInstance::HostGame(FString MapName, FSPlayerInfo Info)
{
	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Red, TEXT("Hosting Game..."));

	PlayerInfo = Info;

	if (MapName.IsEmpty())
	{
		MapName = TEXT("DashCrash");
	}

	UGameplayStatics::OpenLevel(GetWorld(), FName(*MapName), true, TEXT("listen"));
}

void UNetGameInstance::Join(FString Address, FSPlayerInfo Info)
{
	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Green, FString::Printf(TEXT("Joining Game at %s..."), *Address));

	PlayerInfo = Info;

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		PC->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
	}
}
