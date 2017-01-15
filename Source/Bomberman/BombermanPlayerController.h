// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "BombermanPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABombermanPlayerController();

    // Begin PlayerController interface
    virtual void PlayerTick(float DeltaTime) override;
    virtual void SetupInputComponent() override;
    // End PlayerController interface

    // Movement
	void MoveHorizontally(float Value);
    void MoveVertically(float Value);

    // Actions
    void Jump();
    void StopJumping();
    void Use();
};
