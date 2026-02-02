// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Weapon.h"

void AWeapon::BeginOverlapSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::BeginOverlapSphere(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
}

void AWeapon::EndOverlapSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::EndOverlapSphere(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

}
