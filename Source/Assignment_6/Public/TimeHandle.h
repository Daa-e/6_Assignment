// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeHandle.generated.h"

UCLASS()
class ASSIGNMENT_6_API ATimeHandle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeHandle();

protected:
	virtual void BeginPlay() override;
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere, Category = "Settings")
	TSubclassOf<AActor> SelectClass;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float SpawnInterval = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float SpawnRange = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float FootrestLifeSpan = 2.0f;

	FTimerHandle SpawnTimerHandle;

	void ExecuteSpawn();
};
