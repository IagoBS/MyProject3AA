// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "MyProject3GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	Health =  DefaultHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	GameModeRef = Cast<AMyProject3GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	
	
}

void UHealthComponent::TakeDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) 
{
	if(Damage == 0 || Health == 0 ) {
		return;
	} 
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
	UE_LOG(LogTemp, Warning, TEXT("Sua vida é: %f"), Health);
	if(Health <= 0) {
		if(GameModeRef) {
			GameModeRef->ActorDied(GetOwner());
		} else {
			UE_LOG(LogTemp, Warning, TEXT("O component de vida não referencia o GameMode"));
		}
	}
}


