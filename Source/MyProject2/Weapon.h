// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


class AAvatar;
UCLASS()
class MYPROJECT2_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* WeaponMesh;

	void BeginDamage(AAvatar* WeaponOwner);
	void EndDamage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnActorDamage(AActor* other);

private:
	bool IsAttacking;

	UPROPERTY()
	TArray<AActor*> IgnoredActors;

	UPROPERTY(EditAnywhere)
	float Damage;

};
