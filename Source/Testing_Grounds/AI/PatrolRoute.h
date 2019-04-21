// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTING_GROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	

public:	
	TArray<AActor *> & GetPatrolPoints();

private:
	UPROPERTY(EditAnywhere, Category = "Patrol")
	TArray<AActor *> PatrolPoints;
		
};
