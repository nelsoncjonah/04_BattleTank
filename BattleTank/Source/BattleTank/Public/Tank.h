// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


class UTankBarrel; //Forward Declaration
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


public:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Play")
		void Fire();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint; // TODO find sensible firing value



private:
	// Sets default values for this pawn's properties
	ATank();
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 40000; // TODO find sensible firing value

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3.0f;


	//LOcal Variable for shooting
	UTankBarrel* Barrel = nullptr;


	double LastFireTime = 0;
	
};
