// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PatrollingGuard.h" // TODO Remove Coupling
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTING_GROUNDS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

private:
	APatrollingGuard * Self;
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector WaypointKey;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector IndexKey;
};
