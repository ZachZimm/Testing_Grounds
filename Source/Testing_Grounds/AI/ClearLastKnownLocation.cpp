// Fill out your copyright notice in the Description page of Project Settings.

#include "ClearLastKnownLocation.h"

EBTNodeResult::Type UClearLastKnownLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	UBlackboardComponent * blackboardData = OwnerComp.GetBlackboardComponent();
	
	blackboardData->ClearValue(LastKnownLocation.SelectedKeyName);
	return EBTNodeResult::Succeeded;
}