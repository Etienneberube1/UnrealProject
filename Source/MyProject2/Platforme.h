// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platforme.generated.h"

UCLASS()
class MYPROJECT2_API APlatforme : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatforme();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float maxDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector speedVector;

	UPROPERTY(BlueprintReadWrite)
	bool isPaused = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector currentLocation;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:


};
