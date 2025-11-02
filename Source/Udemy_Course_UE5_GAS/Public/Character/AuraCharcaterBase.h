// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharcaterBase.generated.h"

UCLASS(Abstract)
class UDEMY_COURSE_UE5_GAS_API AAuraCharcaterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharcaterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
