// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Testing_Grounds_GameMode.h"
#include "Game/Testing_Grounds_HUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATesting_Grounds_GameMode::ATesting_Grounds_GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behavior/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATesting_Grounds_HUD::StaticClass();
}
