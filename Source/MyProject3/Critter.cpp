// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ACritter::ACritter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Comp"));
	RootComponent = CapsuleComp;


	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(GetRootComponent());
	
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turrent Light"));
	TurretMesh->SetupAttachment(BaseMesh);


	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}	


// Called when the game starts or when spawned


// Called every frame


// Called to bind functionality to input


void ACritter::Fire() 
{
	if(ProjectileSpawnPoint) {
		FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();
		// AProjectilBase* TempProjectile = GetWorld()->SpawnActor<AProjectilBase>(ProjectileClass, SpawnLocation, SpawnRotation);
		//TempProjectile->SetOwner(this);
	}
}




void ACritter::RotateTurrentFunction(FVector LookAtTarget) 
{
	
}