// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/ChooseNextWaypoint.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	// Get data from blackboard
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();

	// Get the patrol route
	auto aiController = OwnerComp.GetAIOwner();
	Self = aiController->GetPawn();
	UPatrolRoute * patrolRoute = Self->FindComponentByClass<UPatrolRoute>();
		// Protect against owners without a PatrolRoute component
	if (!ensure(patrolRoute)) { return EBTNodeResult::Failed; }
		
		// Warn about empty patrol routes
	if (Self->FindComponentByClass<UPatrolRoute>()->GetPatrolPoints().Num() == 0 )
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has ChooseNextWaypoint component but no patrol points"), *GetNameSafe(Self));
			return EBTNodeResult::Failed;
			
	}

	TArray<AActor *> & patrolPoints = Self->FindComponentByClass<UPatrolRoute>()->GetPatrolPoints();




	// Set next waypoint
	auto index = BlackboardComp->GetValueAsInt(this->IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, patrolPoints[index]);

	// Cycle through waypoints
	index = (++index % patrolPoints.Num());
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, index);

	return EBTNodeResult::Succeeded;
}