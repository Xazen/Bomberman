// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Bomberman.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "BombermanCharacter.h"
#include "Bomb.h"

//////////////////////////////////////////////////////////////////////////
// ABombermanCharacter

ABombermanCharacter::ABombermanCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character)
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

// Input
void ABombermanCharacter::MoveHorizontally(float Value)
{
    if ((Controller != NULL) && (Value != 0.0f))
    {
        // find out which way is forward
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation (0, Rotation.Yaw, 0);

        // get forward vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

        // add movement in that direction
        AddMovementInput(Direction, Value);
    }
}

void ABombermanCharacter::MoveVertically(float Value)
{
    if ((Controller != NULL) && (Value != 0.0f))
    {
        // find out which way is forward
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation (0, Rotation.Yaw, 0);

        // get forward vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

        // add movement in that direction
        AddMovementInput(Direction, Value);
    }
}

void ABombermanCharacter::PlaceBomb()
{
	if (Bomb != NULL)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
            SpawnParams.Template = Cast<AActor>(Bomb);

            FVector SpawnLocation = GetActorLocation();

            FRotator SpawnRotation = FRotator::ZeroRotator;
            World->SpawnActor<ABomb>(Bomb, SpawnLocation, SpawnRotation, SpawnParams);
		}
	}
}
