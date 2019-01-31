// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayTimerComponent.h"

// Sets default values for this component's properties
UGameplayTimerComponent::UGameplayTimerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	if (!StartingTimerValue)
	{
		StartingTimerValue = 600;
	}
}


// Called when the game starts
void UGameplayTimerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGameplayTimerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (TimerValue > 0)
	{
		TimerValue -= DeltaTime;
	}
}

void UGameplayTimerComponent::StartGame()
{
	TimerValue = StartingTimerValue;
}

int UGameplayTimerComponent::GetTimerValue()
{
	return FMath::FloorToInt(TimerValue);
}