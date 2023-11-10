// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FristActor.generated.h"

UCLASS()
class MYPROJECT2_API AFristActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFristActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;

	UPROPERTY(EditDefaultsOnly)
	float DeafaultOnly;

	UPROPERTY(EditInstanceOnly)
	float InstanceOnly;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
