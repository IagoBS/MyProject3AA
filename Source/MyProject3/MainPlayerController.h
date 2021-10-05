// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
class UUserWidget;

UCLASS()
class MYPROJECT3_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Controller | HUD")
	TSubclassOf<UUserWidget> HUDOverlayAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Controller | HUD")
	UUserWidget* HUDOverlay;

	void SetPlayerEnableState(bool SetPlayerEnable);
	

	protected: 
	virtual void BeginPlay() override;






};
