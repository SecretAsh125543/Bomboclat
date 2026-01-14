// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h" 
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;

	Swarm = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Swarm"));
	Swarm->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ABird::Move(const FInputActionValue& Value)
{
	float MoveValue = Value.Get<float>();
	if (Controller && (MoveValue != 0))
	{
		FVector ForwardVector = GetActorForwardVector();
		AddMovementInput(ForwardVector, MoveValue);
	}
}
// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(MoveForward, ETriggerEvent::Triggered, this, &ABird::Move);
}

