// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Item.h"
#include "Bomboclat/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = ItemMesh;

	ItemMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshSecondaryComponent"));
	ItemMesh2->SetupAttachment(ItemMesh);
}

float AItem::SineModifier()
{
	return Amplitude * FMath::Sin(RunningTime * Velocity);
}

float AItem::CosineModifier()
{
	return Amplitude * FMath::Cos(RunningTime * Velocity);
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

	GEngine->AddOnScreenDebugMessage(0, -1.f, FColor::Emerald, FString::Printf(TEXT("%f"), RunningTime));
}

