// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/LevelScriptActor.h"
#include "BombermanLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Setup", meta = (AllowPrivateAccess = "true"))
	AActor* StaticLevelCamera;
};
