// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractionBase.generated.h"

class APlayerAvatar;

UCLASS()

class MYPROJECT2_API AInteractionBase : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AInteractionBase();


protected:	
	UFUNCTION(BlueprintCallable)
	void OnEnterInteractionZone(APlayerAvatar* other);

	UFUNCTION(BlueprintCallable)
	void OnExitInteractionZone(APlayerAvatar* other);


	UFUNCTION(BlueprintImplementableEvent)
	void Activate();

	UFUNCTION()
	void OnInteractActivated();
};
