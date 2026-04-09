// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingFootrest.generated.h"

UCLASS()
class ASSIGNMENT_6_API AMovingFootrest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingFootrest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Compnents|Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting|MoveVelocity")
	FVector MoveVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting|MaxRange")
	float MaxRange;

	FVector StartLocation;
};
