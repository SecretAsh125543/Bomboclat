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
	class USphereComponent* Sphere;

	UFUNCTION()
	virtual void BeginOverlapSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndOverlapSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	template<typename T>
	T Average(T First, T Second);

	float RunningTime = 0;
};

template<typename T>
inline T AItem::Average(T First, T Second)
{
	return (First + Second) / 2;
}
