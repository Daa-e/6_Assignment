#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomPuzzle.generated.h"

UCLASS()
class ASSIGNMENT_6_API ARandomPuzzle : public AActor
{
	GENERATED_BODY()

public:
	ARandomPuzzle();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MeshComponent;

	FRotator RandomRotationRate;
	FVector MoveDirection;
	float MoveSpeed;
	float MoveRange;
	float InitialTimeOffset;
};