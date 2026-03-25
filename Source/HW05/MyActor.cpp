// Fill out your copyright notice in the Description page of Project Settings.
// MyActor.cpp
#include "Engine/Engine.h"
#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentLocation = FVector(0.f, 50.f, 0.f);
	CurrentRotation = FRotator::ZeroRotator;

	SetActorLocation(CurrentLocation);
	SetActorRotation(CurrentRotation);

	for (int32 i = 0; i < 10; i++)
	{
		float RandomDistance = FMath::RandRange(100.f, 300.f);
		float RandomAngle = FMath::RandRange(-90.f, 90.f);

		Move(RandomDistance);
		Turn(RandomAngle);
	}
}

void AMyActor::Move(float Distance)
{
	FVector ForwardVector = GetActorForwardVector();
	CurrentLocation += ForwardVector * Distance;
	SetActorLocation(CurrentLocation);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			3.0f,
			FColor::Green,
			FString::Printf(
				TEXT("Location: X=%.1f Y=%.1f Z=%.1f"),
				CurrentLocation.X,
				CurrentLocation.Y,
				CurrentLocation.Z
			)
		);
	}
}

void AMyActor::Turn(float Angle)
{
	CurrentRotation.Yaw += Angle;
	SetActorRotation(CurrentRotation);
}