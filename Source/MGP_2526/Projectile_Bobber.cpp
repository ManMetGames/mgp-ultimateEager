// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile_Bobber.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile_Bobber::AProjectile_Bobber()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectile_Bobber::BeginPlay()
{
	Super::BeginPlay();
	UProjectileMovementComponent* ProjectileMovement = FindComponentByClass<UProjectileMovementComponent>();
	ProjectileMovement->InitialSpeed = 1000.f;	
	ProjectileMovement->MaxSpeed = 1000.f;
	
	
	CollisionSphere = FindComponentByClass<USphereComponent>();

	if (!CollisionSphere)
	{
		return;
	}
}

// Called every frame
void AProjectile_Bobber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CollisionSphere)
	{
		return;
	}

	TArray<UPrimitiveComponent*> OverlappingComponents;

	CollisionSphere->GetOverlappingComponents(OverlappingComponents);

	for (UPrimitiveComponent* Component : OverlappingComponents)
	{
		if(Component->GetCollisionObjectType() == ECC_GameTraceChannel2)
		//everything that happens here is happening when it overlaps with the fishing zone
		{
			CanReelIn = true;
		}
		else
		//everything that happens here is happening when it does not overlap with the fishing zone
		{
			CanReelIn = false;
		}
	}

}


