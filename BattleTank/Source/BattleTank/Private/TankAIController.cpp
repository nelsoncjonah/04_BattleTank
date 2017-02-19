// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Public/Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AIPawn = Cast<ATank>(GetPawn());
	if (!AIPawn) { return; }

	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerPawn) { return; }

	if (PlayerPawn)
	{
		AIPawn->AimAt(PlayerPawn->GetActorLocation());

		AIPawn->Fire();

	}

}

