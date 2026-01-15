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


void ABird::Look(const FInputActionValue& Value)
{
	FVector2D MouseValue = Value.Get<FVector2D>();
	if(Controller)
	{
		AddControllerYawInput(MouseValue.X);
		AddControllerPitchInput(MouseValue.Y);
	}
}

void ABird::Movement(const FInputActionValue& Value)
{
	FVector2D MovementValue = Value.Get<FVector2D>();
	FVector ForwardVector = GetActorForwardVector();
	FVector RightVector = GetActorRightVector();
	if (Controller)
	{
		AddMovementInput(RightVector, MovementValue.X);
		AddMovementInput(ForwardVector, MovementValue.Y);
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
	EnhancedInputComponent->BindAction(CameraMove, ETriggerEvent::Triggered, this, &ABird::Look);
	EnhancedInputComponent->BindAction(InputMovement, ETriggerEvent::Triggered, this, &ABird::Movement);
}

