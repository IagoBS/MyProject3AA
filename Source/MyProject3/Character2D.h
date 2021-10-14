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
class AItem;
class PAPER2UPaperFlipbookComponent;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectil")
	bool bHasCombatTarget;

	FORCEINLINE void SetHasCombatTarget(bool HasTarget) { bHasCombatTarget = HasTarget; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement")
	FVector CombatTargetLocation;

	AMainPlayerController* PlayerControllerRef;
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent *ProjectileSpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectilBase> ProjectileClass;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent *HealthComponent;
	

protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaSeconds);
	virtual void SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) override;

	//pegar arma
	void LMBDown();
	void LMBUp();
	
	//Destruir ator
	void HandleDestruction();

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	FVector CurrentVelocity;

public:
	bool bIsPlayerAlive = true;
	bool GetIsPlayerAlive();
	
	


	

};
