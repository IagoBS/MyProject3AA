
#include "FloorSwith.h"
#include "UObject/Object.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "TimerManager.h"
// Sets default values
AFloorSwith::AFloorSwith()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;

	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	TriggerBox->SetBoxExtent(FVector(62.f, 62.f, 32.f));
	 
	

	FloorSwith = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor Swith"));
	FloorSwith->SetupAttachment(GetRootComponent());

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(GetRootComponent());

	SwitchTime	 = 2.f;
	bCharacterOnSwith = false;


}

void AFloorSwith::CloseDoor() 
{
	if(!bCharacterOnSwith) {
	LowerDoor();
	LowerFloor();	
	}
}

// Called when the game starts or when spawned
void AFloorSwith::BeginPlay()
{
	Super::BeginPlay();
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AFloorSwith::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AFloorSwith::OnOverlapEnd);

	InitialDoorLocation = Door->GetComponentLocation();
	InitialSwitchLocation = FloorSwith->GetComponentLocation();
	
}

void AFloorSwith::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,  AActor* OtherActor,  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	UE_LOG(LogTemp, Error, TEXT("Abriu"));
	if(!bCharacterOnSwith) bCharacterOnSwith = true;

	RaiseDoor();
	FloowSwith();


}

void AFloorSwith::OnOverlapEnd(UPrimitiveComponent* OverlappedComp,  AActor* OtherActor,  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) 
{
	UE_LOG(LogTemp, Error, TEXT("Fechou"));
	if(bCharacterOnSwith) bCharacterOnSwith = false;
	GetWorldTimerManager().SetTimer(SwithHandle, this, &AFloorSwith::CloseDoor, SwitchTime );

}

// Called every frame
void AFloorSwith::Tick(float DeltaTime)
{


}

void AFloorSwith::UpdateDoorLocation(float Z) 
{
	FVector NewLocation = InitialDoorLocation;
	NewLocation.Z += Z;
	Door->SetWorldLocation(NewLocation);


}

void AFloorSwith::UpdateLocation(float Z) 
{
	FVector NewLocation = InitialSwitchLocation;
	NewLocation.Z += Z;
	FloorSwith->SetWorldLocation(NewLocation);	
}


