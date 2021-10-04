// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"



APickup::APickup() 
{
    
}
void APickup::OnOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
    Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp ,OtherBodyIndex, bFromSweep, SweepResult);


}
void APickup::OnOverlapEnd(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex) {
    Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp,OtherBodyIndex);
}