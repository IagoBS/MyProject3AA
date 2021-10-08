// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;
class ULightComponent;
class UParticleSystemComponent;
class UParticleSystem;
class UPrimitiveComponent;
class AActor;
class USpotLightComponent;
class ADirectionalLight;
class USoundCue;
class ACharacter2D;
class UParticleSystem;
class USoundBase;
class AMyProject3GameModeBase;
UCLASS()
class MYPROJECT3_API AItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision | Item")
	USphereComponent *CollisionVolume;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Mesh")
	UStaticMeshComponent *BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Flashlight")
	UStaticMeshComponent *FlashLight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Particles");
	UParticleSystemComponent *idleParticleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Particles");
	UParticleSystem *OverlapParticles;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item | Light")
	USpotLightComponent *LightComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item | Sound")
	USoundCue *SoundCue;

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

	AMyProject3GameModeBase* GameModeRef;

	UFUNCTION()
	void OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit);

public:
	void DecrementHealth(float Demout);
	void Died();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// void AttachFlashLight(AActor* Player);

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);
};
