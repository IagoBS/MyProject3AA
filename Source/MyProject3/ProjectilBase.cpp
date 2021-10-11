// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectilBase.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
// Sets default values
AProjectilBase::AProjectilBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectil Mesh"));
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectilBase::OnHit);

	RootComponent = ProjectileMesh;

	ProjectilMoviment = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Project Movement"));

	ProjectilMoviment->InitialSpeed = MovementSpeed;
	ProjectilMoviment->MaxSpeed = MovementSpeed;
	

	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AProjectilBase::BeginPlay()
{
	Super::BeginPlay();
	
}




void AProjectilBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
{
	AActor* MyOwner = GetOwner();

	if (!MyOwner)
	{
		return;
	}

	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{

	Destroy();
	}
}
