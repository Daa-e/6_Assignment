#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeHandle.generated.h"

UCLASS()
class ASSIGNMENT_6_API ATimeHandle : public AActor
{
	GENERATED_BODY()

public:
	ATimeHandle();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Settings")
	TSubclassOf<AActor> SelectClass;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float SpawnInterval = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float SpawnRange = 1000.0f;

	UPROPERTY(EditAnywhere, Category = "Settings")
	float FootrestLifeSpan = 5.0f;

	FTimerHandle SpawnTimerHandle;

	void ExecuteSpawn();
};