#pragma once
#include "CoreMinimal.h"
#include "Critter.h"
#include "Character2D.h"
#include "PawnLight.generated.h"


class ACharacter2D;

UCLASS()

class MYPROJECT3_API APawnLight : public ACritter
{
	GENERATED_BODY()

private:


UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
float FireRate = 2.0f;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combate", meta = (AllowPrivateAccess = "true"))
float FireRange = 5.0f;

 FTimerHandle FireRateTimerHandle;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
ACharacter2D* PlayerCharacter;

void CheckFireCondition();
float ReturnDistanceToPlayer();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input

protected:
virtual void BeginPlay() override;
	

	
};
