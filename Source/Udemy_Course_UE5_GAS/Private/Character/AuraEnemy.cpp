// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"
#include "Udemy_Course_UE5_GAS/Udemy_Course_UE5_GAS.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
}

void AAuraEnemy::HightlightActor()
{
	
		// Implement highlight logic here (e.g., change material, outline, etc.)
		GetMesh()->SetRenderCustomDepth(true); // Enable custom depth rendering
		GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED ); // Example stencil value for highlighting
		Weapon->SetRenderCustomDepth(true);
		Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
		


	
}

void AAuraEnemy::UnHighlightActor()
{
	
		// Implement unhighlight logic here (e.g., revert material, outline, etc.)
		GetMesh()->SetRenderCustomDepth(false); // Disable custom depth rendering
		Weapon->SetRenderCustomDepth(false);

}
