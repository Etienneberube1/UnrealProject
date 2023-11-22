// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Avatar.generated.h"

class AWeapon;

UCLASS()
class MYPROJECT2_API AAvatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAvatar();

	UFUNCTION(BlueprintCallable)
	bool IsDead() const;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	float health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float maxHealth;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	virtual void Heal(float healAmount);

	UFUNCTION(BlueprintCallable)
	float GetPourcentHealth() const;
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHealthChange();

	UPROPERTY(EditAnywhere)
	UAnimMontage* DeathMontage;

	UPROPERTY(EditAnywhere)
	UAnimMontage* AttackMontage;

	UPROPERTY()
	AWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AWeapon> StartingWeaponClass;

	UFUNCTION(BlueprintCallable)
	void BeginAttack();

	UFUNCTION(BlueprintCallable)
	void EndAttack();

	UFUNCTION(BlueprintCallable)
	void NormalAttack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
