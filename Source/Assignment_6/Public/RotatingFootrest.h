// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingFootrest.generated.h"

// 생성자 -메모리에 생김. 딱 한번 호출.
// PostInitializeComponents() - 컴포넌트가 완성된 직후 호출. 컴포넌트끼리 데이터 주고받기, 상호작용
// BeginPlay() - 배치 (Spawn) 직후
// Tick(float DeltaTime) - 매 프레임마다 호출
// Destroyed() - 삭제 되기 직전에 호출(리소스 정리)
// EndPlay() - 게임 종료, 파괴 (Destroyed()), 레벨 전환 (사라지는 모든걸 총괄)

UCLASS()
class ASSIGNMENT_6_API ARotatingFootrest : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingFootrest();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Compnents|SceneRoot")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Compnents|StaticMeshComp")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings|RotationSpeed")
	FRotator RotationSpeed;

};
