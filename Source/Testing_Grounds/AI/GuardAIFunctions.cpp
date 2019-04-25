// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardAIFunctions.h"

float UGuardAIFunctions::GetPlayerPitchRelative (UObject * WorldContextObject, AGuard * guard) 
{
	return guard->GetControlRotation().Pitch;
}

void UGuardAIFunctions::UpdateEnemyKey(UObject * WorldContextObject, FAIStimulus stim, UBlackboardComponent * blackboardComp, FName enemyKeyName)
{
	UObject *const World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject); // Get World from WorldContextObject
	FString sensedString = "False";
	if (stim.WasSuccessfullySensed()) 
	{
		ACharacter * enemyCharacter = UGameplayStatics::GetPlayerCharacter(World, 0);

		sensedString = "True";
		blackboardComp->SetValueAsObject(enemyKeyName, enemyCharacter);

	}
	else 
	{
		blackboardComp->ClearValue(enemyKeyName);
	}

	UE_LOG(LogTemp, Warning, TEXT("Successfully sensed : %s"), *sensedString);
}

void UGuardAIFunctions::SetLastKnown(UObject * WorldContextObject, FAIStimulus stim, UBlackboardComponent * blackboardComp, FName lastSeenKeyName) 
{
	UObject *const World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject); // Get World from WorldContextObject

	if (stim.WasSuccessfullySensed())
	{
		blackboardComp->ClearValue(lastSeenKeyName);
		FString stimString = blackboardComp->GetValueAsVector(lastSeenKeyName).ToString();
		UE_LOG(LogTemp, Warning, TEXT("Last Seen Location : %s"), *stimString)
	}
	else
	{
		blackboardComp->SetValueAsVector(lastSeenKeyName, stim.StimulusLocation);
		FString stimString = blackboardComp->GetValueAsVector(lastSeenKeyName).ToString();
		UE_LOG(LogTemp, Warning, TEXT("Last Seen Location : %s"), *stimString)
	}
}