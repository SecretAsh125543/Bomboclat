// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class BOMBOCLAT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Variables")
	float Amplitude = 0.75f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Variables")
	float Velocity = 1.5f;

	UFUNCTION(BlueprintPure)
	float SineModifier();

	UFUNCTION(BlueprintPure)
	float CosineModifier();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh2;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	template<typename T>
	T Average(T First, T Second);
};

template<typename T>
inline T AItem::Average(T First, T Second)
{
	return (First + Second) / 2;
}
