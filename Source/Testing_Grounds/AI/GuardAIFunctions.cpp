// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardAIFunctions.h"

float UGuardAIFunctions::GetPlayerPitchRelative (UObject * WorldContextObject, AGuard * guard) 
{
	return guard->GetControlRotation().Pitch;
}

void UGuardAIFunctions::UpdateEnemyKey(UObject * WorldContextObject, FAIStimulus stim, UBlackboardComponent * blackboardComp, FName enemyKeyName, AActor * stimActor, TArray<FName> enemyTags)
{
	UObject *const World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject); // Get World from WorldContextObject
	//FString sensedString = "False"; // Debug
	TArray<FName> stimTags = stimActor->Tags;
	bool isEnemy = false;
	
	for (int i = 0; i < stimTags.Num(); i++) 
	{
		if (enemyTags.Contains(stimTags[i])) 
		{
			isEnemy = true;
		}
	}

	if (isEnemy) 
	{
		if (stim.WasSuccessfullySensed())
		{
			ACharacter * enemyCharacter = UGameplayStatics::GetPlayerCharacter(World, 0);

			//sensedString = "True";
			blackboardComp->SetValueAsObject(enemyKeyName, enemyCharacter);
		}
		else
		{
			blackboardComp->ClearValue(enemyKeyName);
		}
	}
	
	//UE_LOG(LogTemp, Warning, TEXT("Sensed : %s"), *(stimTags[0].ToString()));
}

void UGuardAIFunctions::SetLastKnown(UObject * WorldContextObject, FAIStimulus stim, UBlackboardComponent * blackboardComp, FName lastSeenKeyName, AActor * stimActor, TArray<FName> enemyTags)
{
	UObject *const World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject); // Get World from WorldContextObject

	TArray<FName> stimTags = stimActor->Tags;
	bool isEnemy = false;

	for (int i = 0; i < stimTags.Num(); i++)
	{
		if (enemyTags.Contains(stimTags[i]))
		{
			isEnemy = true;
		}
	}
	if (isEnemy) 
	{
		if (stim.WasSuccessfullySensed())
		{
			//blackboardComp->ClearValue(lastSeenKeyName);
			FString stimString = blackboardComp->GetValueAsVector(lastSeenKeyName).ToString();
			//UE_LOG(LogTemp, Warning, TEXT("Last Seen Location : %s"), *stimString)
		}
		else
		{
			blackboardComp->SetValueAsVector(lastSeenKeyName, stim.StimulusLocation);
			FString stimString = blackboardComp->GetValueAsVector(lastSeenKeyName).ToString();
			//UE_LOG(LogTemp, Warning, TEXT("Last Seen Location : %s"), *stimString)

		}
	}
}