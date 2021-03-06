// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FirstSaveGame.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCharactersStats
{
	 GENERATED_BODY()


	UPROPERTY(VisibleAnywhere, Category="SaveGameData")
	FVector Location;
	UPROPERTY(VisibleAnywhere, Category="SaveGameData")
	FRotator Rotation;
	UPROPERTY(VisibleAnywhere, Category="SaveGameData")
	FString MapName;
	UPROPERTY(VisibleAnywhere, Category="SaveGameData")
	FString LevelName;
	
};


UCLASS()
class MYPROJECT3_API UFirstSaveGame : public USaveGame
{
	GENERATED_BODY()

	public:
	UFirstSaveGame();

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FCharactersStats CharacterStats;

		
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;


};
