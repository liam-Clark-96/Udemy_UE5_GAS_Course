// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharcaterBase.h"
#include "Player/AuraPlayerState.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class UDEMY_COURSE_UE5_GAS_API AAuraCharacter : public AAuraCharcaterBase
{
	GENERATED_BODY()

protected:


public:
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();

	
};
