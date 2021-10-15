// Fill out your copyright notice in the Description page of Project Settings.

#include "PaperCharacterBase.h"
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
APaperCharacterBase::APaperCharacterBase()
{

   

    HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));

    ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
    ProjectileSpawnPoint->SetupAttachment(GetRootComponent());

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = true;
    bUseControllerRotationRoll = false;

    GetCapsuleComponent()->SetCapsuleSize(24.f, 100.f);

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.f, 0.f);
    GetCharacterMovement()->JumpZVelocity = 650.f;
    GetCharacterMovement()->AirControl = 0.2f;


}

void APaperCharacterBase::HandleDestruction()
{
    UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticle, GetActorLocation());
    UGameplayStatics::SpawnSoundAtLocation(this, DeathSound, GetActorLocation());
}

void APaperCharacterBase::FireStart()
{
    bHasCombatTarget = true;
    UE_LOG(LogTemp, Error, TEXT("Fogo neles!!"));
    if (ProjectileClass && bHasCombatTarget)
    {
        FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
        FRotator SpawnRotation = GetControlRotation();
        AProjectilBase *TemProjectile = GetWorld()->SpawnActor<AProjectilBase>(ProjectileClass, SpawnLocation, SpawnRotation);
        TemProjectile->SetOwner(this);
    }
}
void APaperCharacterBase::FireStop()
{
    bHasCombatTarget = false;
}