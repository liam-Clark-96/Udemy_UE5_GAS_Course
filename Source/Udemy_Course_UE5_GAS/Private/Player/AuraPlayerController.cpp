// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
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
