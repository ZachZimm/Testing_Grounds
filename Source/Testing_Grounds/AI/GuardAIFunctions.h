// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine.h"
#include "AIController.h"
#include "NPC/Character/Guard.h"
#include "GameFramework/Controller.h"
#include "Perception/AIPerceptionTypes.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "GuardAIFunctions.generated.h"

/**
 * 
 */
UCLASS()
class TESTING_GROUNDS_API UGuardAIFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	UFUNCTION(BlueprintCallable, Category = "Perception", meta = (WorldContext = "WorldContextObject"))
	static float GetPlayerPitchRelative(UObject * WorldContextObject, AGuard * guard);

	UFUNCTION(BlueprintCallable, Category = "Perception", meta = (WorldContext = "WorldContextObject"))
	static void UpdateEnemyKey(UObject * WorldContextObject, FAIStimulus stim, UBlackboardComponent * blackboardComp, FName enemyKeyName, AActor * stimActor, TArray<FName> enemyTags);

	UFUNCTION(BlueprintCallable, Category = "Perception", meta = (WorldContext = "WorldContextObject"))
	static void SetLastKnown(UObject * WorldContextObject, FAIStimulus stim, UBlackboardComponent * blackboardComp, FName lastSeenKeyName, AActor * stimActor, TArray<FName> enemyTags);
};
