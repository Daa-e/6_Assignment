#include "TimeHandle.h"
#include "TimerManager.h"

ATimeHandle::ATimeHandle()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATimeHandle::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ATimeHandle::ExecuteSpawn, SpawnInterval, true);
}

void ATimeHandle::ExecuteSpawn()
{
	if (!SelectClass) return;

	FVector RandomLocation = GetActorLocation() + FVector(
		FMath::FRandRange(-SpawnRange, SpawnRange),
		FMath::FRandRange(-SpawnRange, SpawnRange),
		0.0f
	);

	FRotator RandomRotation = FRotator(0.0f, FMath::FRandRange(0.0f, 360.0f), 0.0f);

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(SelectClass, RandomLocation, RandomRotation);

	if (SpawnedActor)
	{
		SpawnedActor->SetLifeSpan(FootrestLifeSpan);
	}
}