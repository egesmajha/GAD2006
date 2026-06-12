#include "NetAvatar.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"

ANetAvatar::ANetAvatar()
{
	bReplicates = true;
	SetReplicateMovement(true);

	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

	bRunPressed = false;
	WalkSpeed = 600.0f;
	RunSpeed = 1000.0f;
	DashStrength = 2500.0f;
	MovementScale = 1.0f;

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ANetAvatar::BeginPlay()
{
	Super::BeginPlay();
	OnRep_RunPressed();
}

void ANetAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ANetAvatar::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ANetAvatar::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction(TEXT("Run"), IE_Pressed, this, &ANetAvatar::RunPressed);
	PlayerInputComponent->BindAction(TEXT("Run"), IE_Released, this, &ANetAvatar::RunReleased);
	PlayerInputComponent->BindAction(TEXT("Dash"), IE_Pressed, this, &ANetAvatar::DashPressed);
}

void ANetAvatar::MoveForward(float Scale)
{
	if (Controller && Scale != 0.0f && MovementScale != 0.0f)
	{
		FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, Scale * MovementScale);
	}
}

void ANetAvatar::MoveRight(float Scale)
{
	if (Controller && Scale != 0.0f && MovementScale != 0.0f)
	{
		FRotator Rotation = Controller->GetControlRotation();
		FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, Scale * MovementScale);
	}
}

void ANetAvatar::RunPressed()
{
	if (HasAuthority())
	{
		bRunPressed = true;
		OnRep_RunPressed();
	}
	else
	{
		ServerSetRunPressed(true);
	}
}

void ANetAvatar::RunReleased()
{
	if (HasAuthority())
	{
		bRunPressed = false;
		OnRep_RunPressed();
	}
	else
	{
		ServerSetRunPressed(false);
	}
}

void ANetAvatar::DashPressed()
{
	FVector DashDirection = GetActorForwardVector();

	if (HasAuthority())
	{
		ServerDash(DashDirection);
	}
	else
	{
		ServerDash(DashDirection);
	}
}

void ANetAvatar::ServerSetRunPressed_Implementation(bool bPressed)
{
	bRunPressed = bPressed;
	OnRep_RunPressed();
}

void ANetAvatar::ServerDash_Implementation(FVector DashDirection)
{
	GetCharacterMovement()->AirControl = 0.0f;
	LaunchCharacter(DashDirection.GetSafeNormal() * DashStrength, true, true);
}

void ANetAvatar::OnRep_RunPressed()
{
	GetCharacterMovement()->MaxWalkSpeed = bRunPressed ? RunSpeed : WalkSpeed;
}

void ANetAvatar::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANetAvatar, bRunPressed);
}
