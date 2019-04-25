// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardAIFunctions.h"

void UGuardAIFunctions::FocusPlayer(UObject * WorldContextObject, AAIController * aiController) // Deprecated?
{
	UObject *const World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject); // Set World from WorldContextObject

	ACharacter * playerCharacter = UGameplayStatics::GetPlayerCharacter(World, 0); // Get player location with World object
	//FVector playerLocation = playerCharacter->GetActorLocation();

	//aiController->SetFocalPoint(playerLocation); // Set AI focus to player's location - doesn't account for elevation
	aiController->SetFocus(playerCharacter, EAIFocusPriority::Move); // Set AI focus to player
	float pitch = aiController->GetControlRotation().Pitch;
	
	UE_LOG(LogTemp, Warning, TEXT("Player location is : %f"), pitch);
}

float UGuardAIFunctions::GetPlayerPitchRelative (UObject * WorldContextObject, AGuard * guard) 
{
	return guard->GetControlRotation().Pitch;
}