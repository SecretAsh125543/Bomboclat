// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/FirstCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFirstCharacter::AFirstCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);
}

void AFirstCharacter::Look(const FInputActionValue& Value)
{
	FVector2D CameraValue = Value.Get<FVector2D>();
	if (Controller)
	{
		AddControllerPitchInput(CameraValue.Y);
		AddControllerYawInput(CameraValue.X);
	}
}

void AFirstCharacter::Zoom(const FInputActionValue& Value)
{
	float ZoomValue = Value.Get<float>();
	
	if (Controller && CameraBoom)
	{
		CameraBoom->TargetArmLength = FMath::Clamp(CameraBoom->TargetArmLength -= 20 * ZoomValue, 75.f, 750.f);
	}
}

void AFirstCharacter::Movement(const FInputActionValue& Value)
{
	FVector2D MovementValue = Value.Get<FVector2D>();
	const FRotator YawRotation(0.f, GetControlRotation().Yaw, 0.f);

	FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardVector, MovementValue.Y);
	AddMovementInput(RightVector, MovementValue.X);
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
	EnhancedInputComponent->BindAction(IJump, ETriggerEvent::Triggered, this, &AFirstCharacter::Jump);
	EnhancedInputComponent->BindAction(IZoom, ETriggerEvent::Triggered, this, &AFirstCharacter::Zoom);
}

