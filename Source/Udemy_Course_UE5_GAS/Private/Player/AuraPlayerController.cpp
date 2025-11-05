// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"
#include "GameFramework/PlayerController.h"

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Chekcing if the AuraContext is valid
	check(AuraContext);
	
	// Get the Enhanced Input Local Player Subsystem to add the mapping context checking it first then adding the context
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	// Show the mouse cursor and set the default cursor type
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	// Setting the input mode to Game and UI so that both game and UI inputs are processed 
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);;
	InputModeData.SetHideCursorDuringCapture(false);

}

// Setting up the input component to bind input actions
void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Set up the enhanced input component cast checking it first
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	//Binding the Move action to the Move function 
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

AAuraPlayerController::AAuraPlayerController()
{
	// Enable replication for the player controller to support multiplayer functionality
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	// Call the base class PlayerTick function
	Super::PlayerTick(DeltaTime);
	// Perform a cursor trace to detect interactable actors under the cursor
		CursorTrace();
}
void AAuraPlayerController::CursorTrace()
{
	// Perform a hit result trace under the cursor to detect interactable actors
	FHitResult CursorHit;
	// Storing the last actor before updating
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	// If no blocking hit is detected, return early
	if (!CursorHit.bBlockingHit) return;
	// Updating the last and current actors based on the hit result
	LastActor = ThisActor;
	// Getting the actor from the hit result and casting it to the IEnemyInterface
	ThisActor = CursorHit.GetActor();

	/**
	* Line Trace from cursor, there are several scenarios
	* A. Last Actor is null && This actor is null
	*		 - Do nothing
	* B. LastActor is null && This actor is valid
	*		- Highlight This actor
	* C. LastActor is valid && This actor is null
	*		- UnHighlight Last actor
	* D. LastActor is valid, But LastActor != ThisActor
	* 		- UnHighlight Last actor, Highlight This actor
	* E. Both are valid, and both are the same
	*		- Do nothing
	*/
	
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Scenario B: LastActor is null && This actor is valid
			ThisActor->HightlightActor();
		}
		else
		{
			// Scenario A: Last Actor is null && This actor is null
			// Do nothing
		}
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			// Scenario C: LastActor is valid && This actor is null
			LastActor->UnHighlightActor();
		}
		else // both actors are valid
		{

			if (LastActor != ThisActor)
			{
				// Scenario D: LastActor is valid, But LastActor != ThisActor
				LastActor->UnHighlightActor();
				ThisActor->HightlightActor();
			}
			else
			{
				// Scenario E: Both are valid, and both are the same
				// Do nothing
			}
		}
	}
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// Getting the input axis vector from the input action value
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	// Getting the control rotation of the player controller
	const FRotator Rotation = GetControlRotation();
	// Isolating the yaw rotation to ignore pitch and roll for movement direction
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	// Getting the forward and right direction vectors based on the yaw rotation
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	// Adding movement input to the controlled pawn based on the input axis vector and direction vectors
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}

}


