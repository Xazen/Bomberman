// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomberman.h"
#include "BombermanLevelScriptActor.h"

void ABombermanLevelScriptActor::BeginPlay() 
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController) 
	{
		if ((PlayerController->GetViewTarget() != StaticLevelCamera) && (StaticLevelCamera != nullptr)) 
		{
			PlayerController->SetViewTarget(StaticLevelCamera);
		}
	}
}