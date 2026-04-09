// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingFootrest.h"

// Sets default values
ARotatingFootrest::ARotatingFootrest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    // 회전 속도
    RotationSpeed = FRotator(0.0f, 90.0f, 0.0f);
}

// Called when the game starts or when spawned
void ARotatingFootrest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingFootrest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    AddActorLocalRotation(RotationSpeed * DeltaTime);
}

