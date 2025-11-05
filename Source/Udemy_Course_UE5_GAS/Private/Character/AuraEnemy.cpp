// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

AAuraEnemy::AAuraEnemy()
{
}

void AAuraEnemy::HightlightActor()
{
	bIsHighlighted = true;
}

void AAuraEnemy::UnHighlightActor()
{
	bIsHighlighted = false;
}
