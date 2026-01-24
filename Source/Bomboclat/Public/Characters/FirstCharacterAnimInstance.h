// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FirstCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOMBOCLAT_API UFirstCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override; 
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class AFirstCharacter* Character;

	UPROPERTY(BlueprintReadOnly)
	class UCharacterMovementComponent* CharacterMovement;

	UPROPERTY(BlueprintReadOnly)
	float GroundVelocity;
};
