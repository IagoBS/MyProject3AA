#include "Explosive.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "Components/PrimitiveComponent.h"

AExplosive::AExplosive() 
{
    
}
void AExplosive::OnOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult) {
    Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp ,OtherBodyIndex, bFromSweep, SweepResult);


}
void AExplosive::OnOverlapEnd(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex) {
    Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp,OtherBodyIndex);
}