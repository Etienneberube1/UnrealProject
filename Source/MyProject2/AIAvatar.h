// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Avatar.h"
#include "AIAvatar.generated.h"


enum class EAIState : uint8
{
	AI_Idle,
	AI_Wander,
	AI_Chase,
	AI_Attack,
	AI_Return,
	AI_Death
};

class APlayerAvatar;

UCLASS()
class MYPROJECT2_API AAIAvatar : public AAvatar
{
	GENERATED_BODY()
protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(blueprintCallable)
	void OnEnterPerception(APlayerAvatar* other);

	UFUNCTION(blueprintCallable)
	void OnExitPerception(APlayerAvatar* other);

	bool HasTarget() const;

	bool CanSeeTarget() const;

	void EnterIdleState();
	void EnterWanderState();
	void EnterChaseState();
	void EnterAttackState();
	void EnterReturnState();
	void EnterDeathState();

	void UpdateIdleState(float DeltaTime);
	void UpdateWanderState(float DeltaTime);
	void UpdateChaseState(float DeltaTime);
	void UpdateAttackState(float DeltaTime);


	FVector PickRandomDestination(const FVector& Center, const float Range);

	void SetWalkSpeed();
	void SetRunSpeed();

	UPROPERTY(EditAnywhere)
	float WalkSpeed;

	UPROPERTY(EditAnywhere)
	float RunSpeed;

	// Idle Variable
	UPROPERTY(EditAnywhere)
	float MinIdleTime;

	UPROPERTY(EditAnywhere)
	float MaxIdleTime;

	float CurrentIdleTime;





	// Wander Variable
	FVector WanderDestination;

	UPROPERTY(EditAnywhere)
	float MaxWanderRange;

	UPROPERTY(EditAnywhere)
	float StoppingDistance;




	FVector SpawnLocation;

	EAIState CurrentState;

	UPROPERTY(EditAnywhere)
	bool bIsDebug = false;

private:

	UPROPERTY()
	APlayerAvatar* CurrentTarget;
};
