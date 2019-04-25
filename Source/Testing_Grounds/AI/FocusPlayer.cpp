// Fill out your copyright notice in the Description page of Project Settings.

#include "FocusPlayer.h"


EBTNodeResult::Type UFocusPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();	// Get Blackboard
	BlackboardComp->SetValueAsObject(EnemyKey.SelectedKeyName, GetWorld()->GetFirstPlayerController()->GetPawn()); // Set blackboard key value
	OwnerComp.GetAIOwner()->SetFocus(GetWorld()->GetFirstPlayerController()->GetPawn());

	float pitch = OwnerComp.GetAIOwner()->GetControlRotation().Pitch;
	UE_LOG(LogTemp, Warning, TEXT("Pitch : %f"), pitch);
	return EBTNodeResult::Succeeded;
}

