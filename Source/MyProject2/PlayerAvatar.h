// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Avatar.h"
#include "PlayerAvatar.generated.h"



class UPotion;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);

UCLASS()
class MYPROJECT2_API APlayerAvatar : public AAvatar
{
	GENERATED_BODY()


public:

	UPROPERTY()
	FOnInteract OnInteractionEvent;

protected:
	UFUNCTION(BlueprintCallable)
	void Take(UPotion* PotionItem);

	UFUNCTION(BlueprintCallable)
	void UsePotion();

	UFUNCTION(BlueprintCallable)
	void Interact();

	UPROPERTY(VisibleAnywhere)
	TArray<UPotion*> Inventory;
};
