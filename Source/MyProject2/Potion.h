// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Potion.generated.h"

class APlayerAvatar;

UCLASS(BlueprintType, blueprintable)
class MYPROJECT2_API UPotion : public UObject
{
	GENERATED_BODY()
	
public:
	UPotion();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HealAmount;

	UFUNCTION(BlueprintCallable)
	bool Drink(APlayerAvatar* avatar);


	void PlayPickUpSound(const FVector& Location);

protected:
	float HealingPercent;

	UPROPERTY(EditAnywhere)
	USoundBase* PickupSound;

};
