// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Avatar.h"
#include "PlayerAvatar.generated.h"

/**
 * 
 */

class UPotion;

UCLASS()
class MYPROJECT2_API APlayerAvatar : public AAvatar
{
	GENERATED_BODY()
protected:

	UFUNCTION(BlueprintCallable)
	void Take(UPotion* PotionItem);

	UFUNCTION(BlueprintCallable)
	void UsePotion();

	UPROPERTY(VisibleAnywhere)
	TArray<UPotion*> Inventory;
};
