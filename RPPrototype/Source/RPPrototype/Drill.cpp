// Fill out your copyright notice in the Description page of Project Settings.


#include "Drill.h"
#include "UObject/ConstructorHelpers.h"

ADrill::ADrill()
{

static ConstructorHelpers::FObjectFinder<UStaticMesh> DrillAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
if (DrillAsset.Succeeded())
{
	
	
	
	Super::mesh->SetStaticMesh(DrillAsset.Object);
	Super::mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Super::mesh->SetWorldScale3D(FVector(1.0f));
}
CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("Collision Mesh"));
CollisionMesh->SetupAttachment(RootComponent);
CollisionMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
CollisionMesh->SetRelativeScale3D(FVector(1.2f, 1.2f, 1.8f));
}
void ADrill::BeginPlay() 
{
	Super::BeginPlay();
	CollisionMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
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