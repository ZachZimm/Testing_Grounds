// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardAIFunctions.h"

void UGuardAIFunctions::FocusPlayer(UObject * WorldContextObject, AAIController * aiController)
{
	UObject *const World = GEngine->GetWorldFromContextObject(WorldContextObject); // Set World from WorldContextObject

	ACharacter * playerCharacter = UGameplayStatics::GetPlayerCharacter(World, 0); // Get player location with World object
	FVector playerLocation = playerCharacter->GetActorLocation();

	aiController->SetFocalPoint(playerLocation); // Set AI focus to player's location

	//UE_LOG(LogTemp, Warning, TEXT("Player location is : %s"), *(playerLocation.ToString()));
}