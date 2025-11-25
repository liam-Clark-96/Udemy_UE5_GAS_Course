// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharcaterBase.h"


AAuraCharcaterBase::AAuraCharcaterBase()
{
 
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AAuraCharcaterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AAuraCharcaterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharcaterBase::InitAbilityActorInfo()
{

}



