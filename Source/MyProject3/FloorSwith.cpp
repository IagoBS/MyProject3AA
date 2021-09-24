
#include "FloorSwith.h"
#include "UObject/Object.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
// Sets default values
AFloorSwith::AFloorSwith()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;
	TriggerBox->OnComponentBeginOverlap.addDynamic(this, &AFloorSwith::OnOverLapBegin);

	FloorSwith = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor Swith"));
	FloorSwith->SetupAttachment(GetRootComponent();

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(GetRootComponent());



}

// Called when the game starts or when spawned
void AFloorSwith::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFloorSwith::OnOverLapBegin(UPrimitiveComponent* OnComponentBeginOverlap,  UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) 
{
	
}



// Called every frame
void AFloorSwith::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

