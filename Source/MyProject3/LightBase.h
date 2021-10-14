// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "LightBase.generated.h"

/**
 * 
 */
class UStaticMeshComponent;
class USpotLightComponent;
class FSphere;

UCLASS()
class MYPROJECT3_API ALightBase : public AItem
{
	GENERATED_BODY()

public:
	ALightBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Light")
	USpotLightComponent *LightComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Flashlight")
	UStaticMeshComponent *FlashLight;


	UPROPERTY(EditAnywhere, Category="Floor Switch")
	float SwitchTime;
	bool bCharacterOnSwith;

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Swith")
	void RaiseLight();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Swith")
	void LowerLight();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Swith")
	void FloowSwith();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Swith")
	void LowerFloor();


	FTimerHandle SwithHandle;

	void OnLight();
	void OffLight();




	UFUNCTION(BlueprintCallable, Category = "Light Switch")
	void ToggleLight();

	
private:
	UPROPERTY(EditAnywhere, Category = "Item | Character")
	ACharacter2D *MyCharacter2D;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage", meta = (AllowPrivateAccess = "true"))
	float Damage = 100.0f;

	UPROPERTY(EditAnywhere)
	UParticleSystem *ImpactEffect;

	UPROPERTY(EditAnywhere)
	USoundBase *ImpactSound;

	AMyProject3GameModeBase *GameModeRef;

public:
	virtual void OnOverlapBegin(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) override;

	virtual void OnOverlapEnd(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<UDamageType> DamageTypeClass;
};
