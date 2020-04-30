// Fill out your copyright notice in the Description page of Project Settings.


#include "Drill.h"
ADrill::ADrill()
{
CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));

}
void ADrill::BeginPlay() 
{
	Super::BeginPlay();
}
void ADrill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void ADrill::PAttack1()
{
	UE_LOG(LogTemp, Warning, TEXT("PA1"));
}
void ADrill::PAttack2()
{
	UE_LOG(LogTemp, Warning, TEXT("PA2"));
}
void ADrill::SAttack1()
{
	UE_LOG(LogTemp, Warning, TEXT("SA1"));
}
void ADrill::SAttack2()
{
UE_LOG(LogTemp, Warning, TEXT("SA2"));
}