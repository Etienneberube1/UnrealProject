// Fill out your copyright notice in the Description page of Project Settings.


#include "AIAvatar.h"
#include "NavigationSystem.h" 
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerAvatar.h"


void AAIAvatar::BeginPlay()
{
	Super::BeginPlay();
	CurrentTarget = nullptr; 
	SpawnLocation = GetActorLocation();
	EnterIdleState();
}

void AAIAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (CurrentState)
	{
	case EAIState::AI_Idle:
		UpdateIdleState(DeltaTime);
		break;

	case EAIState::AI_Wander:
		UpdateWanderState(DeltaTime);
		break;

	case EAIState::AI_Chase:
		break;

	case EAIState::AI_Attack:
		break;

	case EAIState::AI_Return:
		break;

	case EAIState::AI_Death:
		break;
	}

	if (bIsDebug)
	{
		UWorld* world = GetWorld();
		DrawDebugSphere(world, SpawnLocation, MaxWanderRange, 12, FColor::Yellow);
		DrawDebugSphere(world, WanderDestination, StoppingDistance, 12, FColor::Blue);
		DrawDebugLine(world, GetActorLocation(), WanderDestination, FColor::Blue);

		if (HasTarget() && CanSeeTarget())
		{
			DrawDebugSphere(world, CurrentTarget->GetActorLocation(), 20.0f, 12, FColor::Red);
			DrawDebugLine(world, GetActorLocation(), CurrentTarget->GetActorLocation(), FColor::Blue);

		}
	}
}





void AAIAvatar::OnEnterPerception(APlayerAvatar* other)
{
	if (other)
	{
		if (!HasTarget())
		{
			CurrentTarget = other;
		}
	}
}

void AAIAvatar::OnExitPerception(APlayerAvatar* other)
{
	if (other)
	{
		if (HasTarget() && CurrentTarget == other)
		{
			CurrentTarget = nullptr;
		}
	}
}

bool AAIAvatar::HasTarget() const
{
	return CurrentTarget != nullptr;
}

bool AAIAvatar::CanSeeTarget() const
{
	if (!HasTarget()) return false;
	if (IsDead()) return false;

	FHitResult HitResult;
	FCollisionQueryParams QueryParam;
	QueryParam.AddIgnoredActor(this);

	FVector LineStart = GetActorLocation();
	FVector LineEnd  = CurrentTarget->GetActorLocation();

	UWorld* world = GetWorld();

	if (world->LineTraceSingleByChannel(HitResult, LineStart, LineEnd, ECC_Pawn, QueryParam))
	{
		return HitResult.GetActor() == CurrentTarget;
	}

	

	return false;
}





void AAIAvatar::EnterIdleState()
{

	UE_LOG(LogTemp, Log, TEXT("EAIState::AI_Idle"));
	CurrentState = EAIState::AI_Idle;
	CurrentIdleTime = FMath::RandRange(MinIdleTime, MaxIdleTime);

	AAIController* AiController = Cast<AAIController>(GetController());
	if (AiController)
	{
		AiController->StopMovement();
	}
}


void AAIAvatar::EnterWanderState()
{
	UE_LOG(LogTemp, Log, TEXT("EAIState::AI_Wander"))
	CurrentState = EAIState::AI_Wander;

	AAIController* AiController = Cast<AAIController>(GetController());
	if (AiController)
	{
		WanderDestination = PickRandomDestination(SpawnLocation, MaxWanderRange);
		AiController->MoveToLocation(WanderDestination);
		SetWalkSpeed();
	}
	else
	{
		EnterIdleState();
	}
}

void AAIAvatar::EnterChaseState()
{

	AAIController* AiController = Cast<AAIController>(GetController());
	if (AiController)
	{
		AiController->MoveToLocation(CurrentTarget->GetActorLocation());
		SetRunSpeed();
	}
	else
	{
		
		EnterWanderState();
	}

	CurrentState = EAIState::AI_Chase;

}

void AAIAvatar::EnterAttackState()
{
	CurrentState = EAIState::AI_Attack;
	AAIController* AiController = Cast<AAIController>(GetController());
	if (AiController)
	{
		AiController->StopMovement();
		NormalAttack();

	}

}

void AAIAvatar::EnterReturnState()
{
	CurrentState = EAIState::AI_Return;
}

void AAIAvatar::EnterDeathState()
{
	CurrentState = EAIState::AI_Death;
}




void AAIAvatar::UpdateIdleState(float DeltaTime)
{
	CurrentIdleTime -= DeltaTime;
	if (CurrentIdleTime <= 0.0f)
	{
		EnterWanderState();
	}
}

void AAIAvatar::UpdateWanderState(float DeltaTime)
{
	const float Distance = FVector::Distance(GetActorLocation(), WanderDestination);

	if (Distance <= StoppingDistance)
	{
		EnterIdleState();
	}

	if (HasTarget() && !IsDead())
	{
		EnterChaseState();
	}
}

void AAIAvatar::UpdateChaseState(float DeltaTime)
{
	const float Distance = FVector::Distance(GetActorLocation(), CurrentTarget->GetActorLocation());

	if (Distance <= StoppingDistance)
	{
		EnterAttackState();
	}
	else
	{
		AAIController* AiController = Cast<AAIController>(GetController());
		if (AiController)
		{
			AiController->MoveToLocation(CurrentTarget->GetActorLocation());
		}

	}

	if(!HasTarget())
	{
		EnterIdleState();
	}
}

void AAIAvatar::UpdateAttackState(float DeltaTime)
{
}

FVector AAIAvatar::PickRandomDestination(const FVector& Center, const float Range)
{
	const UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	
	FNavLocation RandomLocation;
	if (navSystem->GetRandomPointInNavigableRadius(Center, Range, RandomLocation)) {
		return RandomLocation.Location;
	}

	return Center;
}

void AAIAvatar::SetWalkSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AAIAvatar::SetRunSpeed()
{
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;

}
