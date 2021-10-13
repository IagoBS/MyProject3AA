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
class AWeapon;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent *ProjectileSpawnPoint;




	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon")
	AWeapon* EquipedWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Components")
	AItem* ActiveOverlappingItem;



	FORCEINLINE void SetEquippedWeapon(AWeapon* WeaponToSet) { EquipedWeapon = WeaponToSet;}
	FORCEINLINE void SetEquippedOverlapingItem(AItem* ItemToSet) { ActiveOverlappingItem = ItemToSet;}


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

	//pegar arma
	bool LMBbShiftKeyDown = false;
	bool bLMBDown = false;
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
