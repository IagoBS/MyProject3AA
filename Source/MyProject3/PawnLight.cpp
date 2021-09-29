#include "PawnLight.h"
#include "Kismet/GameplayStatics.h"
#include "Critter.h"
#include "Character2D.h"
#include "Engine/EngineTypes.h"

void APawnLight::BeginPlay()
{
    Super::BeginPlay();
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnLight::CheckFireCondition, FireRate, true);
    PlayerCharacter = Cast<ACharacter2D>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnLight::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (!PlayerCharacter || ReturnDistanceToPlayer() > FireRange)
    {
        return;
    }
}

void APawnLight::CheckFireCondition()
{
    if (!PlayerCharacter || !PlayerCharacter->GetIsPlayerAlive())
    {
        return;
    }
    if (ReturnDistanceToPlayer() <= FireRange)
    {
        //Fire();
        UE_LOG(LogTemp, Error, TEXT("Tiro tiro"));
    }
    // IF PLAYER IS in range THEN FIRE!!
}

float APawnLight::ReturnDistanceToPlayer()
{
    if (!PlayerCharacter || PlayerCharacter->GetIsPlayerAlive())
    {
        return 0.0f;
    }
    return FVector::Dist(PlayerCharacter->GetActorLocation(), GetActorLocation());
}