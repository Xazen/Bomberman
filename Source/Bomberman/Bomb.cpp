// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomberman.h"
#include "Bomb.h"

// Sets default values
ABomb::ABomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TimeToExplode = 3.f;
	CurrentTimeToExplode = TimeToExplode;

	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombMesh"));
	RootComponent = BombMesh;
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
	Super::BeginPlay();
}

void ABomb::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CurrentTimeToExplode = FMath::Clamp<float>(CurrentTimeToExplode - DeltaSeconds, 0, TimeToExplode);
	if (CurrentTimeToExplode <= 0)
	{
		Explode();
	}
}

void ABomb::DidExplode_Implementation()
{
	FString BombDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("did explode %s"), *BombDebugString);
}

void ABomb::Explode()
{
	FString BombDebugString = GetName();
	FString DestroySuccess = (Destroy() ? "success" : "failed");

	UE_LOG(LogClass, Log, TEXT("%s will explode: %s"), *BombDebugString, *DestroySuccess);
}
