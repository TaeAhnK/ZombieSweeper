// Fill out your copyright notice in the Description page of Project Settings.

#include "Field/Destination.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ADestination::ADestination()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	DestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	DestMesh->SetupAttachment(RootComponent);

	CollideBox = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	CollideBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADestination::BeginPlay()
{
	Super::BeginPlay();

	//CollideBox->OnComponentBeginOverlap.AddDynamic(this, &ATile::OnOverlap);
}

