// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacterBase.h"
#include "MainPaperCharacter2D.generated.h"

/**
 * 
 */
class USpringArmComponent;
class UCameraComponent;
class UInputComponent;
class UHealthComponent;
class USceneComponent;
class AProjectilBase;
class AMainPlayerController;
class AItem;
class PAPER2UPaperFlipbookComponent;

UCLASS()
class MYPROJECT3_API AMainPaperCharacter2D : public APaperCharacterBase
{
	GENERATED_BODY()
	public:
	AMainPaperCharacter2D();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent *SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent *FollowCamera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed;


	public:
	

	virtual void Tick(float DeltaSeconds);

	virtual void SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) override;

	virtual void HandleDestruction() override;

	AMainPlayerController* PlayerControllerRef;

	
	protected:
	virtual void BeginPlay() override;

	private:

	void MoveForward(float Value);
	void MoveRight(float Value);
	FVector CurrentVelocity;



	private:

	void FireStart();
	void FireStop();

	public:
	
	bool GetIsPlayerAlive();
	bool bIsPlayerAlive = true;

	

};
