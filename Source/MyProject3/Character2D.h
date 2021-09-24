// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Character2D.generated.h"

/**
 * 
 */
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MYPROJECT3_API ACharacter2D : public APaperCharacter
{
	GENERATED_BODY()
	public: 
	ACharacter2D();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= Camera)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	UCameraComponent* FollowCamera;


	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed;


	protected: 
	virtual void BeginPlay() override;


	public:


	virtual void Tick(float DeltaSeconds);
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	private:

	void MoveForward(float Value);
	void MoveRight(float Value);
	bool bIsPlayerAlive = true;
	FVector CurrentVelocity;
	
};
