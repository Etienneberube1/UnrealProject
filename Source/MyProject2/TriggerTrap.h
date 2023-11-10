// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerTrap.generated.h"

UCLASS()
class MYPROJECT2_API ATriggerTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	ATriggerTrap();

protected:
	UFUNCTION(BlueprintCallable)
	bool TriggerTrap(AActor* other);

	UPROPERTY(EditAnywhere)
	float MinDamage;

	UPROPERTY(EditAnywhere)
	float MaxDamage;

};
