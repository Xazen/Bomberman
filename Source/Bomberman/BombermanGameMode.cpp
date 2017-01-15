// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Bomberman.h"
#include "BombermanGameMode.h"
#include "BombermanCharacter.h"
#include "BombermanPlayerController.h"

ABombermanGameMode::ABombermanGameMode()
{
    // use my own custom PlayerController class
    PlayerControllerClass = ABombermanPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/Players/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

	static ConstructorHelpers::FClassFinder<ABombermanPlayerController> BombermanPlayerController(TEXT("/Game/Blueprints/BP_BombermanPlayerController"));

	if (BombermanPlayerController.Class != NULL)
	{
		PlayerControllerClass = BombermanPlayerController.Class;
	}
}

void ABombermanGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Create a second player
    UGameplayStatics::CreatePlayer(this, 1);
}