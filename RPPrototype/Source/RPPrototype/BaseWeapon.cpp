// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	mesh->SetupAttachment(RootComponent);
	mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseWeapon::PAttack1(){ UE_LOG(LogTemp, Warning, TEXT("PA1")); }
void ABaseWeapon::PAttack2(){ UE_LOG(LogTemp, Warning, TEXT("PA2")); }
void ABaseWeapon::SAttack1(){ UE_LOG(LogTemp, Warning, TEXT("SA1")); }
void ABaseWeapon::SAttack2(){ UE_LOG(LogTemp, Warning, TEXT("SA2")); }