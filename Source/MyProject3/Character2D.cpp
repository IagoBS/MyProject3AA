// Fill out your copyright notice in the Description page of Project Settings.


#include "Character2D.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperCharacter.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ACharacter2D::ACharacter2D() 
{
    PrimaryActorTick.bCanEverTick = true;



	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 600.f;
	SpringArm->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = true;

	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	GetCapsuleComponent()->SetCapsuleSize(24.f, 75.f);


	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f, 0.f);
	GetCharacterMovement()->JumpZVelocity = 650.f;
	GetCharacterMovement()->AirControl = 0.2f;

    CurrentVelocity = FVector(0.f);
    MaxSpeed = 1000.f;
}

void ACharacter2D::BeginPlay() 
{
	Super::BeginPlay();

}

void ACharacter2D::Tick(float DeltaSeconds) 
{
	Super::Tick(DeltaSeconds);
    FVector NewLocation = GetActorLocation() + CurrentVelocity * DeltaSeconds;
    SetActorLocation(NewLocation);
}

void ACharacter2D::SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) 
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACharacter2D::MoveRight);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
}

void ACharacter2D::MoveForward(float Value) 
{
	 CurrentVelocity.Y = FMath::Clamp(Value, -1.f, 1.f) * MaxSpeed;
}

void ACharacter2D::MoveRight(float Value) 
{
	 CurrentVelocity.X = FMath::Clamp(Value, -1.f, 1.f) * MaxSpeed;	
}


bool ACharacter2D::GetIsPlayerAlive() 
{
	 return bIsPlayerAlive;
}


