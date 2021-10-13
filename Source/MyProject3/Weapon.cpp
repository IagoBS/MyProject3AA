// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/EngineTypes.h"
#include "PaperCharacter.h"
#include "Character2D.h"
#include "PaperCharacter.h"

AWeapon::AWeapon()
{
    SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
    SkeletalMesh->SetupAttachment(GetRootComponent());
    
    CombatCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Combat"));
    CombatCollision->SetupAttachment(GetRootComponent());
    CombatCollision->SetVisibility(false);

    bWeaponParticles = false;

    WeaponState = EWeaponState::EWS_Pickup;

    Damage = 25.f;
}

void AWeapon::BeginPlay() 
{
    // CombatCollision->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::CombatOnOverlapBegin);
    // CombatCollision->OnComponentEndOverlap.AddDynamic(this, &AWeapon::CombatOnOverlapEnd);

    CombatCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CombatCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
    
    CombatCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CombatCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

}

void AWeapon::OnOverlapBegin(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    if ((WeaponState == EWeaponState::EWS_Pickup) && OtherActor) {
        ACharacter2D* Main = Cast<ACharacter2D>(OtherActor);
        if(Main) {
        Main->SetEquippedOverlapingItem(this);
        Equip(Main);


        }
    }
}
void AWeapon::OnOverlapEnd(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
    Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
    if ((WeaponState == EWeaponState::EWS_Pickup) && OtherActor) {
        ACharacter2D* Main = Cast<ACharacter2D>(OtherActor);
        if(Main) {
        Main->SetEquippedOverlapingItem(nullptr);
        }
    }
}

void AWeapon::Equip(ACharacter2D* Char) 
{
    if(Char) {

        SetInstigator(Char->GetController());

        SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Overlap);
        SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
        SkeletalMesh->SetSimulatePhysics(false);

     const USkeletalMeshSocket* RightHandSocket = Char->GetMesh()->GetSocketByName("Sprite0");
        if(RightHandSocket) {
            RightHandSocket->AttachActor(this, Char->GetMesh());
            bRotate = false;
            Char->SetEquippedWeapon(this);
            Char->SetEquippedOverlapingItem(nullptr);
            
        } else {
            UE_LOG(LogTemp, Error, TEXT("Error"));
        }
    }
}

// void AWeapon::CombatOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) 
// {
    
// }

// void AWeapon::CombatOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
// {
    
// }

void AWeapon::ActivateCollision() 
{
    
}

void AWeapon::DeactivateCollision() 
{
    
}
