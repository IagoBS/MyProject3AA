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
#include "Particles/ParticleSystem.h"
// Sets default values
AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	RootComponent = CollisionVolume;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(GetRootComponent());


	FlashLight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlashLight"));
	FlashLight->SetupAttachment(BaseMesh);
	
	idleParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	idleParticleComponent->SetupAttachment(GetRootComponent());

	LightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("Light"));
	LightComponent->SetupAttachment(BaseMesh);

}

// Called when the game starts or when spawned
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
	if(LightComponent) {
	UGameplayStatics::SpawnEmitterAtLocation(GetOwner(), OverlapParticles, GetActorLocation(), FRotator(0.f), true);
	}
	
	
	
}

void AItem::OnOverlapEnd(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
}

// void AItem::AttachFlashLight(AActor* Player) {
// 	this->SetActorLocation(Player->GetActorLocation());
// 	this->AttachToActor(Player, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
// 	UE_LOG(LogTemp, Warning, TEXT("Spawning FlashLight"));

// }