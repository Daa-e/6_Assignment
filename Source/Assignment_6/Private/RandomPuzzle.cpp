#include "RandomPuzzle.h"
#include "Components/StaticMeshComponent.h"

ARandomPuzzle::ARandomPuzzle()
{
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;
}

void ARandomPuzzle::BeginPlay()
{
	Super::BeginPlay();

	RandomRotationRate = FRotator(FMath::FRandRange(-100.0f, 100.0f), FMath::FRandRange(-100.0f, 100.0f), FMath::FRandRange(-100.0f, 100.0f));
	MoveDirection = FVector(FMath::FRandRange(-1.0f, 1.0f), FMath::FRandRange(-1.0f, 1.0f), FMath::FRandRange(-1.0f, 1.0f)).GetSafeNormal();
	MoveSpeed = FMath::FRandRange(1.0f, 5.0f);
	MoveRange = FMath::FRandRange(100.0f, 500.0f);
	InitialTimeOffset = FMath::FRandRange(0.0f, 100.0f);
}

void ARandomPuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RandomRotationRate * DeltaTime);

	float CurrentTime = GetWorld()->GetTimeSeconds() + InitialTimeOffset;
	float MovementAlpha = FMath::Sin(CurrentTime * MoveSpeed);
	FVector NewOffset = MoveDirection * (MovementAlpha * MoveRange * DeltaTime);
	AddActorLocalOffset(NewOffset);
}