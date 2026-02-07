// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Item.h"
#include "Components/SphereComponent.h"
#include "Bomboclat/DebugMacros.h"
#include "Characters/FirstCharacter.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	Sphere->SetupAttachment(GetRootComponent());
}

float AItem::SineModifier()
{
	return Amplitude * FMath::Sin(RunningTime * Velocity);
}

float AItem::CosineModifier()
{
	return Amplitude * FMath::Cos(RunningTime * Velocity);
}

void AItem::BeginOverlapSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFirstCharacter* Character = Cast<AFirstCharacter>(OtherActor);
	if (Character)
	{
		Character->OverlappedItemSetter(this);
	}
}

void AItem::EndOverlapSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AFirstCharacter* Character = Cast<AFirstCharacter>(OtherActor);
	if (Character)
	{
		Character->OverlappedItemSetter(nullptr);
	}
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::BeginOverlapSphere);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::EndOverlapSphere);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

	GEngine->AddOnScreenDebugMessage(0, -1.f, FColor::Emerald, FString::Printf(TEXT("%f"), RunningTime));
}

