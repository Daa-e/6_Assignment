// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomPuzzle.h"

// Sets default values
ARandomPuzzle::ARandomPuzzle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARandomPuzzle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARandomPuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

