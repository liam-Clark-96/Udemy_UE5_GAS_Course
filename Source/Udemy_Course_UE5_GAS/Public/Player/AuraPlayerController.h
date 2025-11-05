// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"


// Forward declarations of classes and structs used in the AuraPlayerController 
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class UDEMY_COURSE_UE5_GAS_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;


public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;;
	

private:
	// Input Mapping Context for the Aura Player Controller
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	// Input Action for moving the player
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	// Function to handle player movement input
	void Move(const FInputActionValue& InputActionValue);

	// Function to perform a trace under the cursor to detect interactable actors
	void CursorTrace();
	
	// Variables to keep track of the last and current actors under the cursor
	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
};
