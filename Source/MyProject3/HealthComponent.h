// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class AMyProject3GameModeBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT3_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:

UPROPERTY(EditAnywhere, Category="Health")
float DefaultHealth = 100.0f;
UPROPERTY(EditAnywhere, Category="Health")

float Health = 0.0f;

private:
AMyProject3GameModeBase* GameModeRef;


public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void TakeDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);	
		
};
