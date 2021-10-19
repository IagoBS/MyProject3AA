// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyProject3GameModeBase.generated.h"

/**
 * 
 */
class AMainPaperCharacter2D;
class AMainPlayerController;
class AActor;

UCLASS()
class MYPROJECT3_API AMyProject3GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	private:
	AMainPaperCharacter2D* PlayerCharacter2D;
	// int32 Target = 0;

	// int32 GetTargetCount();
	AMainPlayerController* PlayerControllerRef;

	void HandleGamerOver(bool PlayerWon);

	public:
	void ActorDied(AActor* DeadActor);

	protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Game Loop")
	int32 StartDelay = 3;


	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);

	public:
	
	void HandleGameStart();




};
