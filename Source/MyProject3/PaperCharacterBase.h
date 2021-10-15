// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperCharacterBase.generated.h"

/**
 * 
 */
class UInputComponent;
class UHealthComponent;
class USceneComponent;
class AProjectilBase;
class AMainPlayerController;
class AItem;
class PAPER2UPaperFlipbookComponent;
UCLASS()
class MYPROJECT3_API APaperCharacterBase : public APaperCharacter
{
	GENERATED_BODY()
	public:
	APaperCharacterBase();

	
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Projectil")
	bool bHasCombatTarget;

	FORCEINLINE void SetHasCombatTarget(bool HasTarget) { bHasCombatTarget = HasTarget; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Movement")
	FVector CombatTargetLocation;

	
	private:



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent *ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AProjectilBase> ProjectileClass;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent *HealthComponent;

	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase *DeathSound;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* DeathParticle;
	public:
	//pegar arma
	void FireStart();
	void FireStop();
	
	//Destruir ator
	virtual void HandleDestruction();

};
