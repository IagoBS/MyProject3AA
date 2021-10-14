// Fill out your copyright notice in the Description page of Project Settings.


#include "LightBase.h"
#include "Components/SpotLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Character2D.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
ALightBase::ALightBase()
{
    	FlashLight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlashLight"));
	    FlashLight->SetupAttachment(GetRootComponent());

        LightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	    LightComponent->SetupAttachment(BaseMesh);


	SwitchTime	 = 10.f;
	bCharacterOnSwith = true;
}

void ALightBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) 
{
    if (OtherActor && LightComponent)
	{
		MyCharacter2D = Cast<ACharacter2D>(OtherActor);
		if (MyCharacter2D)
		{
			MyCharacter2D->bIsPlayerAlive = false;
			UGameplayStatics::ApplyDamage(OtherActor, Damage, MyCharacter2D->GetInstigatorController(), this, DamageType);
			MyCharacter2D->HandleDestruction();
		}
	}
}

void ALightBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
{
    
}
void ALightBase::OnLight() {
	if(!bCharacterOnSwith) {
	RaiseLight();
	FloowSwith();
	ToggleLight();
	};

}
void ALightBase::OffLight() {
if(!bCharacterOnSwith) bCharacterOnSwith = true;
	ToggleLight();
	LowerLight();
	LowerFloor();	
	GetWorldTimerManager().SetTimer(SwithHandle, this, &ALightBase::OnLight, SwitchTime );

}

void ALightBase::ToggleLight() {
LightComponent->ToggleVisibility();
}