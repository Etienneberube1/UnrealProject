#include "TriggerTrap.h"
#include "PlayerAvatar.h"
#include "Kismet/GameplayStatics.h"

ATriggerTrap::ATriggerTrap()
{
	PrimaryActorTick.bCanEverTick = false;
	MinDamage = 0.0f;
	MaxDamage = 0.0f;
}

bool ATriggerTrap::TriggerTrap(AActor* other)
{
	if (!other) return false;

	APlayerAvatar* otherAvatar = Cast<APlayerAvatar>(other);

	if (!otherAvatar) return false;
	if (otherAvatar->IsDead()) return false;

	const float TotalDamage = FMath::RandRange(MinDamage, MaxDamage);
	UGameplayStatics::ApplyDamage(otherAvatar, TotalDamage, nullptr, this, UDamageType::StaticClass());
	return true;
}



