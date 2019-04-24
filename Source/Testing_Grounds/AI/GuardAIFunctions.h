// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine.h"
#include "AIController.h"
#include "GameFramework/Controller.h"
#include "GuardAIFunctions.generated.h"

/**
 * 
 */
UCLASS()
class TESTING_GROUNDS_API UGuardAIFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Perception", meta = (WorldContext = "WorldContextObject"))
	static void FocusPlayer(UObject * WorldContextObject, AAIController * aiController);
};
