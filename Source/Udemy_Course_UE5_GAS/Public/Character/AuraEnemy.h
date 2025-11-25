// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharcaterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class UDEMY_COURSE_UE5_GAS_API AAuraEnemy : public AAuraCharcaterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();


	//Start Enemy Interface
	virtual void HightlightActor() override;
	virtual void UnHighlightActor() override;
	//End Enemy Interface

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	
};
