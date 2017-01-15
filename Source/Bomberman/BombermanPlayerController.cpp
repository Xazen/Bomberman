// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomberman.h"
#include "BombermanPlayerController.h"
#include "BombermanCharacter.h"


ABombermanPlayerController::ABombermanPlayerController()
{
}

void ABombermanPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
}

void ABombermanPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAxis("MoveHorizontally", this, &ABombermanPlayerController::MoveHorizontally);
    InputComponent->BindAxis("MoveVertically", this, &ABombermanPlayerController::MoveVertically);

    InputComponent->BindAction("Jump", IE_Pressed, this, &ABombermanPlayerController::Jump);
    InputComponent->BindAction("Jump", IE_Released, this, &ABombermanPlayerController::StopJumping);

    InputComponent->BindAction("Use", IE_Pressed, this, &ABombermanPlayerController::Use);
}

void ABombermanPlayerController::MoveHorizontally(float Value)
{
    ABombermanCharacter* const PlayerPawn = Cast<ABombermanCharacter>(GetPawn());
    if (PlayerPawn)
    {
        PlayerPawn->MoveHorizontally(Value);
    }
}

void ABombermanPlayerController::MoveVertically(float Value)
{
    ABombermanCharacter* const PlayerPawn = Cast<ABombermanCharacter>(GetPawn());
    if (PlayerPawn)
    {
        PlayerPawn->MoveVertically(Value);
    }
}

void ABombermanPlayerController::Jump()
{
    ACharacter* const PlayerPawn = Cast<ACharacter>(GetPawn());
    if (PlayerPawn)
    {
        PlayerPawn->Jump();
    }
}

void ABombermanPlayerController::StopJumping()
{
    ACharacter* const PlayerPawn = Cast<ACharacter>(GetPawn());
    if (PlayerPawn)
    {
        PlayerPawn->StopJumping();
    }
}

void ABombermanPlayerController::Use()
{
    ABombermanCharacter* const PlayerPawn = Cast<ABombermanCharacter>(GetPawn());
    if (PlayerPawn)
    {
        PlayerPawn->PlaceBomb();
    }
};