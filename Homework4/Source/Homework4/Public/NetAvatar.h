#pragma once

#include "CoreMinimal.h"
#include "NetBaseCharacter.h"
#include "NetAvatar.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class HOMEWORK4_API ANetAvatar : public ANetBaseCharacter
{
	GENERATED_BODY()

public:
	ANetAvatar();

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* Camera;

	UPROPERTY(ReplicatedUsing = OnRep_RunPressed)
	bool bRunPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DashStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementScale;

	UFUNCTION()
	void OnRep_RunPressed();

	void MoveForward(float Scale);
	void MoveRight(float Scale);
	void RunPressed();
	void RunReleased();
	void DashPressed();

	UFUNCTION(Server, Reliable)
	void ServerSetRunPressed(bool bPressed);

	UFUNCTION(Server, Reliable)
	void ServerDash(FVector DashDirection);
};
