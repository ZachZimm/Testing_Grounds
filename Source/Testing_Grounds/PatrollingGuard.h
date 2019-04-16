// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * Gets and sets the next waypoint for patrolling guards
 */
UCLASS()
class TESTING_GROUNDS_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
public: // TODO Remove or create get function
	UPROPERTY(EditAnywhere, Category = "Patrol")
	TArray<AActor *> PatrolPoints;
};
