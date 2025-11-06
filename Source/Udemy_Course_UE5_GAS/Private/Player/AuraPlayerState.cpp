// Copyright LiamClark


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	//Create the ability system component and set it to our custom class
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	//Create the ability system component and set it to replicate
	AbilitySystemComponent->SetIsReplicated(true);
	//Set the replication mode to mixed
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	//Create the attribute set and set it to our custom class
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.f);
}

//Implement the GetAbilitySystemComponent function from the IAbilitySystemInterface
UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	//Return the ability system component
	return AbilitySystemComponent;
}
