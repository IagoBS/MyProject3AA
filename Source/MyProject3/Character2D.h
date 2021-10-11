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
class UInputComponent;
class UHealthComponent;
class USceneComponent;
class AProjectilBase;

class AMainPlayerController;


UCLASS()
class MYPROJECT3_API ACharacter2D : public APaperCharacter
{
	GENERATED_BODY()
public:
	ACharacter2D();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent *SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent *FollowCamera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent *ProjectileSpawnPoint;
private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectilBase> ProjectileClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent *HealthComponent;
	
	AMainPlayerController* PlayerControllerRef;

protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaSeconds);
	virtual void SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) override;
	void HandleDestruction();

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	FVector CurrentVelocity;

public:
	bool bIsPlayerAlive = true;
	bool GetIsPlayerAlive();
	protected:
	
	void Fire();

};
