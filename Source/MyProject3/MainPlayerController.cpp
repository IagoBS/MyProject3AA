#include "MainPlayerController.h"


#include "Components/SlateWrapperTypes.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Actor.h"

void AMainPlayerController::BeginPlay() {

Super::BeginPlay();

if(HUDOverlayAsset) {
    HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
}

HUDOverlay->AddToViewport();
HUDOverlay->SetVisibility(ESlateVisibility::Visible);

}

void AMainPlayerController::SetPlayerEnabledState(bool SetPlayerEnable) 
{
    if(SetPlayerEnable) {
        AActor::EnableInput(this);
    } else {
        AActor::DisableInput(this);
    }
    bShowMouseCursor = SetPlayerEnable;
}
