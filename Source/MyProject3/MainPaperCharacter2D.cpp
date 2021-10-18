// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPaperCharacter2D.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperCharacter.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HealthComponent.h"
#include "MainPlayerController.h"
#include "Components/CapsuleComponent.h"
#include "ProjectilBase.h"
#include "Weapon.h"
#include "Engine/World.h"

AMainPaperCharacter2D::AMainPaperCharacter2D()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 600.f;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm);

	CurrentVelocity = FVector(0.f);
	MaxSpeed = 1000.f;
}

void AMainPaperCharacter2D::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = Cast<AMainPlayerController>(GetController());
}

void AMainPaperCharacter2D::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector NewLocation = GetActorLocation() + CurrentVelocity * DeltaSeconds;
	SetActorLocation(NewLocation);

	if (PlayerControllerRef)
	{
		FHitResult TraceHitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);
	}
}

void AMainPaperCharacter2D::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMainPaperCharacter2D::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAction(TEXT("LMB"), IE_Pressed, this, &APaperCharacterBase::FireStart);
	PlayerInputComponent->BindAction(TEXT("LMB"), IE_Released, this, &APaperCharacterBase::FireStop);
}

void AMainPaperCharacter2D::MoveRight(float Value)
{
	CurrentVelocity.X = FMath::Clamp(Value, -1.f, 1.f) * MaxSpeed;
}
void AMainPaperCharacter2D::MoveForward(float Value)
{
	CurrentVelocity.Y = FMath::Clamp(Value, -1.f, 1.f) * MaxSpeed;
}

void AMainPaperCharacter2D::HandleDestruction()
{
	bIsPlayerAlive = false;
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
}

bool AMainPaperCharacter2D::GetIsPlayerAlive()
{
	return bIsPlayerAlive;
}
void AMainPaperCharacter2D::SwitchLevel(FName LevelName)
{
	UWorld *World = GetWorld();
	if (World)
	{
		FString CurrentLevel = World->GetMapName();
		CurrentLevel.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

		FName CurrentLevelName(*CurrentLevel);
		if (CurrentLevelName != LevelName)
		{
			FString Level = LevelName.ToString();
			UE_LOG(LogTemp, Warning, TEXT("CurrentLevel: %s"), *CurrentLevel)
			UE_LOG(LogTemp, Warning, TEXT("LevelName: %s"), *Level)
			UGameplayStatics::OpenLevel(World, LevelName);
		}
	}
}