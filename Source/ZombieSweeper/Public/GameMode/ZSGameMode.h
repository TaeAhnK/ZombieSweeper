//
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ZSGameMode.generated.h"

class FieldMap;
class AGridField;
class ATile;

UCLASS()
class ZOMBIESWEEPER_API AZSGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	~AZSGameMode();
	virtual void BeginPlay() override;

	FieldMap* MapData;
	AGridField* Field;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
	FIntPoint StartXY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
	FIntPoint TargetXY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
	TSubclassOf<AGridField> BP_Map;

	UPROPERTY()
	ATile* TileInstance;

protected:
	UFUNCTION()
	void BindTileOverlapEvent(ATile* Tile);

	UFUNCTION()
	void OnTileOverlap(FIntPoint TileIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStepZombie();

private:
};
