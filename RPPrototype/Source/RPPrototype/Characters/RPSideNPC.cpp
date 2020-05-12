// Fill out your copyright notice in the Description page of Project Settings.


#include "RPSideNPC.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"
#include "RPSideCharacter.h"


// Sets default values
ARPSideNPC::ARPSideNPC()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	collisionComponent = CreateDefaultSubobject<UCollisionComponent>(TEXT("collision component"));
	collisionComponent->SetupAttachment(GetCapsuleComponent());

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
}

// Called when the game starts or when spawned
void ARPSideNPC::BeginPlay()
{
	Super::BeginPlay();
	
	collisionComponent->SetPlayerRef(this);
}

// Called every frame
void ARPSideNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARPSideNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARPSideNPC::onUse(AActor* otherActor_)
{
	ARPSideCharacter* player = Cast<ARPSideCharacter>(otherActor_);

	//if (player)
		//if (hudDisplay) hudDisplay->DisplayDialogue(FText::FromString("Test char"), FText::FromString("Test dialogue"));

	onUseUIElement();
}
