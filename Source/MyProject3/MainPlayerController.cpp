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

    if(WPauseMenu) {
       	PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);
		if (PauseMenu)
		{
			PauseMenu->AddToViewport();
			PauseMenu->SetVisibility(ESlateVisibility::Hidden);
		}
    }
    
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
