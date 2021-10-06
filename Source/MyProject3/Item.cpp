// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/LightComponent.h"
#include "Components/SpotLightComponent.h"
#include "Engine/DirectionalLight.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/DamageType.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundCue.h"
#include "Character2D.h"
#include "MyProject3GameModeBase.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundBase.h"
	
// Sets default values
AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	RootComponent = CollisionVolume;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->OnComponentHit.AddDynamic(this, &AItem::OnHit);
	BaseMesh->SetupAttachment(GetRootComponent());


	FlashLight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlashLight"));
	FlashLight->SetupAttachment(BaseMesh);
	
	idleParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	idleParticleComponent->SetupAttachment(GetRootComponent());

	LightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	LightComponent->SetupAttachment(BaseMesh);

}



void AItem::BeginPlay()
{
	Super::BeginPlay();

	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AItem::OnOverlapEnd);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AItem::OnOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{

	if(!MyCharacter2D || !MyCharacter2D->GetIsPlayerAlive()) {
		return;
	}
	
	if(LightComponent) {
		UE_LOG(LogTemp, Error,TEXT("A luz está acesa"));
		
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticles, GetActorLocation(), FRotator(0.f), true);
	}
}

void AItem::OnOverlapEnd(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{

}

void AItem::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
{
	AActor* MyOwner = GetOwner();
	if(!MyOwner) {
		return;
	}
	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwner->GetInstigatorController(), this, DamageType);
		
		Destroy();
	}
}