// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingFootrest.h"

// Sets default values
AMovingFootrest::AMovingFootrest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	MoveVelocity = FVector(0.0f, 0.0f, 200.0f);
	MaxRange = 500.0f;
}

// Called when the game starts or when spawned
void AMovingFootrest::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingFootrest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += (MoveVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceMoved >= MaxRange)
	{
		FVector MoveDirection = MoveVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MaxRange);
		SetActorLocation(StartLocation);
		MoveVelocity = -MoveVelocity;
	}
}

