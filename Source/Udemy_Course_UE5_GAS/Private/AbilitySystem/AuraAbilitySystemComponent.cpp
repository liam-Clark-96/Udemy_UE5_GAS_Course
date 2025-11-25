// Copyright LiamClark


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& Effectspec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1, 8.f, FColor::Blue, FString("EffectApplied!"));
}

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}
