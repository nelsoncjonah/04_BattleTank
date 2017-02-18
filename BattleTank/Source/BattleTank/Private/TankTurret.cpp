// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	auto ClampedSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = ClampedSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	//Sets the new rotation but clams the values between max and min
	SetRelativeRotation(FRotator(0,	RawNewRotation,	0));

}

