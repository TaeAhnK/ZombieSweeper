// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Destination.generated.h"

class USphereComponent;

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDestOverlap);

UCLASS()
class ZOMBIESWEEPER_API ADestination : public AActor
{
	GENERATED_BODY()
	
public:	
	ADestination();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dest")
	UStaticMeshComponent* DestMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collide")
	USphereComponent* CollideBox;

	//UPROPERTY(BlueprintAssignable, Category = "Collide")
	//FOnDestOverlap OnTileOverlapEvent;

protected:
	virtual void BeginPlay() override;

	//UFUNCTION()
	//void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
