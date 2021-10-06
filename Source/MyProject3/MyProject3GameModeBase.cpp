// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyProject3GameModeBase.h"
#include "MainPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Character2D.h"

void AMyProject3GameModeBase::BeginPlay() {
    Super::BeginPlay();

    HandleGameStart();
}


void AMyProject3GameModeBase::ActorDied(AActor* DeadActor) {
    if(DeadActor ==  PlayerCharacter2D) {
        PlayerCharacter2D->HandleDestruction();
        HandleGamerOver(false);
        if(PlayerControllerRef) {
            PlayerControllerRef->SetPlayerEnabledState(false);
        }
    } 
}

void AMyProject3GameModeBase::HandleGameStart() {
PlayerCharacter2D = Cast<ACharacter2D>(UGameplayStatics::GetPlayerCharacter(this, 0));
PlayerControllerRef = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
GameStart();

if(PlayerControllerRef) {
    PlayerControllerRef->SetPlayerEnabledState(true);
    FTimerHandle PlayerTimerHandler;
    FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(PlayerControllerRef, &AMainPlayerController::SetPlayerEnabledState, true);
    GetWorld()->GetTimerManager().SetTimer(PlayerTimerHandler, PlayerEnableDelegate, StartDelay, false);
}

}
void AMyProject3GameModeBase::HandleGamerOver(bool PlayerWon) {
UE_LOG(LogTemp, Error, TEXT("Gamer Over Tente novamente"));
GameOver(PlayerWon);
}
