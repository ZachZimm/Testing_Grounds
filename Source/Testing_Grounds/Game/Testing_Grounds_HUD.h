// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Testing_Grounds_HUD.generated.h"

UCLASS()
class ATesting_Grounds_HUD : public AHUD
{
	GENERATED_BODY()

public:
	ATesting_Grounds_HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

