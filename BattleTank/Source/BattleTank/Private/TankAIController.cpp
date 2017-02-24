// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AIPawn = GetPawn();

	if (!ensure(AIPawn)) { return; }
	if (!ensure(PlayerPawn)) { return; }

	//Move towardPlayer
	auto AimingComponent = AIPawn->FindComponentByClass<UTankAimingComponent>();
	MoveToActor(PlayerPawn, AcceptanceRadius);
	AimingComponent->AimAt(PlayerPawn->GetActorLocation());

	AimingComponent->Fire();


}

