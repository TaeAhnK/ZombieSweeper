//
#include "Field/GridField.h"
#include "Field/Tile.h"
#include "Field/FieldMap.h"

AGridField::AGridField()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AGridField::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("Grid"));
	if (!MapData)
	{
		return;
	}

	GridArray.SetNumZeroed(GridHeight);
	for (int32 y = 0; y < GridHeight; y++)
	{
		GridArray[y].SetNumZeroed(GridWidth);
		for (int32 x = 0; x < GridWidth; x++)
		{
			TSubclassOf<ATile> TileToSpawn = Tile;
			ATile* NewTile = GetWorld()->SpawnActor<ATile>(TileToSpawn, FVector(GetActorLocation().X + x * GridOffset, GetActorLocation().Y + y * GridOffset, 0.1f), FRotator(0.f, 90.f, 0.f));
			NewTile->TileIndex = FIntPoint(x, y);
            NewTile->TileType = ETileType::TileNotOpen;
            //NewTile->TileType = IndexToTileType(MapData->Map[y][x]);
			NewTile->SetSprite();
			GridArray[y][x] = NewTile;
		}
	}
}


void AGridField::OpenTile(FIntPoint StepIndex)
{
    //const int8 dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    //const int8 dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };

    GridArray[StepIndex.Y][StepIndex.X]->TileType = IndexToTileType(MapData->Map[StepIndex.Y][StepIndex.X]);
    GridArray[StepIndex.Y][StepIndex.X]->SetSprite();
    GridArray[StepIndex.Y][StepIndex.X]->DisableCollision();
    //for (int8 i = 0; i < 8; i++)
    //{
    //    if (isValidXY(StepIndex.X + dx[i], StepIndex.Y + dy[i]))
    //    {
    //        uint8 index = MapData->Map[StepIndex.Y + dy[i]][StepIndex.X + dx[i]];
    //        switch (index)
    //        {
    //        case 0:
    //            if (GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType == ETileType::TileOpen)
    //            {
    //                break;
    //            }
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType = ETileType::Tile0;
    //            break;
    //        case 1:
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType = ETileType::Tile1;
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->DisableCollision();
    //            break;
    //        case 2:
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType = ETileType::Tile2;
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->DisableCollision();
    //            break;
    //        case 3:
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType = ETileType::Tile3;
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->DisableCollision();
    //            break;
    //        case 4:
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType = ETileType::Tile4;
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->DisableCollision();
    //            break;
    //        case 5:
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType = ETileType::Tile5;
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->DisableCollision();
    //            break;
    //        case 6:
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType = ETileType::Tile6;
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->DisableCollision();
    //            break;
    //        case 7:
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType = ETileType::Tile7;
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->DisableCollision();
    //            break;
    //        case 8:
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->TileType = ETileType::Tile8;
    //            GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->DisableCollision();
    //            break;
    //        default:
    //            break;
    //        }
    //        GridArray[StepIndex.Y + dy[i]][StepIndex.X + dx[i]]->SetSprite();
    //    }
    //}
}

ETileType AGridField::IndexToTileType(int8 index)
{
    switch (index)
    {
    case -1:
        return ETileType::TileZombie;
    case 0:
        return ETileType::TileOpen;
    case 1:
        return ETileType::Tile1;
    case 2:
        return ETileType::Tile2;
    case 3:
        return ETileType::Tile3;
    case 4:
        return ETileType::Tile4;
    case 5:
        return ETileType::Tile5;
    case 6:
        return ETileType::Tile6;
    case 7:
        return ETileType::Tile7;
    case 8:
        return ETileType::Tile8;
    }
    
    return ETileType::TileNotOpen;
}

bool AGridField::isValidXY(int8 X, int8 Y)
{
    if (X < 0 || GridWidth <= X || Y < 0 || GridHeight <= Y)
    {
        return false;
    }

    return true;
}

