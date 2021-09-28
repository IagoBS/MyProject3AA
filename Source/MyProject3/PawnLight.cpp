
#include "PawnLight.h"
#include "Character2D.h"
#include "Kismet/GameplayStatics.h"
#include "Critter.h"
#include "Character2D.h"


void APawnLight::BeginPlay() 
{
    Super::BeginPlay();
     GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnLight::CheckFireCondition, FireRate, true);
    
    PlayerCharacter = Cast<ACharacter2D>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void APawnLight::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
    if(!PlayerCharacter || ReturnDistanceToPlayer > FireRange) {
        return;
    }
    
}

void APawnLight::HandleDestruction() 
{
    Super::HandleDestruction();
    Destroy();

    
}



void APawnLight::CheckFireCondition() 
{
    if(!PlayerCharacter || !PlayerCharacter->GetIsPLayerAlive()) {
        return;
    }
    if(ReturnDistanceToPlayer() <= FireRange) {
        //Fire();
        return;

    }
    // IF PLAYER IS in range THEN FIRE!!
}

float APawnLight::ReturnDistanceToPlayer() 
{
    if(!PlayerCharacter || PlayerCharacter->GetIsPlayerAlive()) {
        return 0.0f;
    }
    return FVector::Dist(PlayerCharacter->GetActorLocation(), GetActorLocation());

}
