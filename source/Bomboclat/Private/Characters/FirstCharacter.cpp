// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/FirstCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AFirstCharacter::AFirstCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFirstCharacter::Look(const FInputActionValue& Value)
{
	FVector2D CameraValue = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("Look: %s"), *CameraValue.ToString());

	if (Controller)
	{
		AddControllerPitchInput(CameraValue.Y);
		AddControllerYawInput(CameraValue.X);
	}

}

void AFirstCharacter::Movement(const FInputActionValue& Value)
{
	FVector2D MovementValue = Value.Get<FVector2D>();
	FVector ForwardVector = GetActorForwardVector();
	FVector RightVector = GetActorRightVector();
	if (Controller)
	{
		AddMovementInput(ForwardVector, MovementValue.Y);
		AddMovementInput(RightVector, MovementValue.X);
	}
}

// Called when the game starts or when spawned
void AFirstCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	EnhancedInputComponent->BindAction(IMovement, ETriggerEvent::Triggered, this, &AFirstCharacter::Movement);
	EnhancedInputComponent->BindAction(ICameraMove, ETriggerEvent::Triggered, this, &AFirstCharacter::Look);
}

