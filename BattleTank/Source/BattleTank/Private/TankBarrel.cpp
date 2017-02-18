// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto ClampedSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = ClampedSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	//Sets the new rotation but clams the values between max and min
	SetRelativeRotation(
		FRotator(
			FMath::Clamp<float>(
				RawNewElevation, 
				MinElevationDegrees, 
				MaxElevationDegrees), 
			0,
			0));
	
}
