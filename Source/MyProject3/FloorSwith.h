// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwith.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UPrimitiveComponent;
class AActor;

UCLASS()
class MYPROJECT3_API AFloorSwith : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFloorSwith();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BoxCompoent")
	UBoxComponent *TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Swith")
	UStaticMeshComponent *FloorSwith;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Door Swith")
	UStaticMeshComponent *Door;


	UPROPERTY(BlueprintReadWrite, Category="Floor Switch")
	FVector InitialDoorLocation;

	UPROPERTY(BlueprintReadWrite, Category="Floor Switch")
	FVector InitialSwitchLocation;

	FTimerHandle SwithHandle;


	UPROPERTY(EditAnywhere, Category="Floor Switch")
	float SwitchTime;
	bool bCharacterOnSwith;
	
	void CloseDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	// declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	// declare overlap end function
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Swith")
	void RaiseDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Swith")
	void LowerDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Swith")
	void FloowSwith();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Swith")
	void LowerFloor();

	UFUNCTION(BlueprintCallable, Category = "Floor Swith")
	void UpdateDoorLocation(float Z);

	UFUNCTION(BlueprintCallable, Category = "Floor Swith")
	void UpdateLocation(float Z);

};
