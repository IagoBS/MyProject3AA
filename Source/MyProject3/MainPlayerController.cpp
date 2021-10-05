#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMainPlayerController::BeginPlay() {
Super::BeginPlay();
if(HUDOverlayAsset) {
    HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
}
HUDOverlay->AddToViewport();
HUDOverlay->SetVisibility(ESlateVisibility::Visible);

}

void AMainPlayerController::SetPlayerEnable(bool SetPlayerEnable) 
{
    if(SetPlayerEnable) {
        GetPawn()->EnableInput(this);
    } else {
        GetPawn()->DisableInput(this);
    }
    bShowMouseCursor = SetPlayerEnabled;
}
