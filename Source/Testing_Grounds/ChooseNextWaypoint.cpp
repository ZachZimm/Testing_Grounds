// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// TODO Protect against empty patrol routes

	// Get data from blackboard
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	// Get the patrol points
	auto aiController = OwnerComp.GetAIOwner();
	auto controlledPawn = aiController->GetPawn();
	Self = Cast<APatrollingGuard>(controlledPawn);
	TArray<AActor *> & patrolPoints = Self->PatrolPoints;

	// Set next waypoint
	auto index = BlackboardComp->GetValueAsInt(this->IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, patrolPoints[index]);

	// Cycle through waypoints
	index = (++index % patrolPoints.Num());
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, index);

	return EBTNodeResult::Succeeded;
}