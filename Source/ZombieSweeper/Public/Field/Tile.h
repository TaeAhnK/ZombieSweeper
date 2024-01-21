//
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UPaperSprite;
class UPaperSpriteComponent;
class UBoxComponent;

UENUM(BlueprintType)
enum class ETileType : uint8
{
	Tile0,
	Tile1,
	Tile2,
	Tile3,
	Tile4,
	Tile5,
	Tile6,
	Tile7,
	Tile8,
	TileNotOpen,
	TileOpen,
	TileZombie
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTileOverlap, FIntPoint, TileIndex);

UCLASS()
class ZOMBIESWEEPER_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	ATile();
	virtual void BeginPlay() override;
	void SetSprite();
	void DisableCollision();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	ETileType TileType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile")
	FIntPoint TileIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	TArray<UPaperSprite*> TileSprites;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile")
	UPaperSpriteComponent* PaperMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collide")
	UBoxComponent* CollideBox;

	UPROPERTY(BlueprintAssignable, Category = "Collide")
	FOnTileOverlap OnTileOverlapEvent;

protected:
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
