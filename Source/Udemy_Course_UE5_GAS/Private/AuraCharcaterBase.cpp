// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraCharcaterBase.h"

// Sets default values
AAuraCharcaterBase::AAuraCharcaterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAuraCharcaterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAuraCharcaterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAuraCharcaterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

