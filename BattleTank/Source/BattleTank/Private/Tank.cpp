// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Public/TankBarrel.h"
#include "Public/TankTurret.h"
#include "Projectile.h"
#include "Public/Tank.h"

void ATank::BeginPlay()
{
	Super::BeginPlay();
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();

}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (!ensure(Barrel)) { return; }
	if (isReloaded) {

		FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator StartRotation = Barrel->GetSocketRotation(FName("Projectile"));

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, StartLocation, StartRotation);

		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}


void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}