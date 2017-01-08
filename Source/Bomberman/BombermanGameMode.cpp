// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Bomberman.h"
#include "BombermanGameMode.h"
#include "BombermanCharacter.h"

ABombermanGameMode::ABombermanGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
