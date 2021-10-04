// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;
class ULightComponent;

class UPrimitiveComponent;
class AActor;

UCLASS()
class MYPROJECT3_API AItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision | Item")
	USphereComponent *CollisionVolume;;;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Item | Mesh")
	UStaticMeshComponent* BaseMesh; 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Item | Particles");
	UParticleSystemComponent* idleParticleComponent;
	// UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Item | Light")
	// ULightComponent* LightComponent;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);
};
