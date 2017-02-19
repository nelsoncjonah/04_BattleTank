// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Public/TankBarrel.h"
#include "Public/TankTurret.h"
#include "Projectile.h"
#include "Public/Tank.h"


void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{

	if (!Barrel) { return; }

	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FRotator StartRotation = Barrel->GetSocketRotation(FName("Projectile"));

	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, StartLocation, StartRotation);

	Projectile->LaunchProjectile(LaunchSpeed);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//no need to protect points as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}