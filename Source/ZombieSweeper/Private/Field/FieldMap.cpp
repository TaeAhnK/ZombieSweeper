//

#include "Field/FieldMap.h"
#include "Math/UnrealMathUtility.h"

FieldMap::FieldMap(int8 Width, int8 Height, FIntPoint StartXY, FIntPoint TargetXY)
{
	MapWidth = Width;
	MapHeight = Height;
	this->StartXY = StartXY;
	this->TargetXY = TargetXY;

	Map.Init(TArray<int8>(), MapHeight);
	PlantZombie(200);
}

void FieldMap::PlantZombie(int16 ZNum)
{
	int32 random;
	int8 rx, ry;

	do
	{
		InitMap();
		for (int16 i = 0; i < ZNum; i++)
		{
			random = FMath::RandRange(0, (MapHeight * MapWidth) - 1);
			ry = random / MapHeight;
			rx = random % MapHeight;

			if ((Map[ry][rx] != -1) && !(ry == TargetXY.Y && rx == TargetXY.X) && !(ry == StartXY.Y && rx == StartXY.X))
			{
				Map[ry][rx] = -1;
				SetAdjNum(rx, ry);
			}
		}
	} while (!RootExist());
}

void FieldMap::InitMap()
{
	for (int8 y = 0; y < MapHeight; y++)
	{
		Map[y].Init(0, MapWidth);
	}
}

bool FieldMap::RootExist()
{
	TArray<TArray<bool>> Visited;
	Visited.Init(TArray<bool>(), MapHeight);

	for (int8 i = 0; i < MapHeight; i++)
	{
		Visited[i].Init(false, MapWidth);
	}
	
	Search(Visited, StartXY.X, StartXY.Y);

	if (Visited[TargetXY.Y][TargetXY.X])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void FieldMap::SetAdjNum(int8 x, int8 y)
{
	for (int8 i = 0; i < 8; i++)
	{
		if (isValidXY(x + dx[i], y + dy[i]))
		{
			(Map[dy[i] + y][dx[i] + x])++;
		}
	}
}

bool FieldMap::isValidXY(int8 x, int8 y)
{
	if (x < 0 || MapWidth <= x || y < 0 || MapHeight <= y || Map[y][x] == -1)
	{
		return false;
	}

	return true;
}

void FieldMap::Search(TArray<TArray<bool>>& Visited, int8 sx, int8 sy)
{
	Visited[sy][sx] = true;

	for (int8 i = 0; i < 8; i++)
	{
		if (isValidXY(sx + dx[i], sy + dy[i]) && !Visited[sy + dy[i]][sx + dx[i]])
		{
			if (sx + dx[i] == TargetXY.X && sy + dy[i] == TargetXY.Y)
			{
				Visited[sy + dy[i]][sx + dx[i]] = true;
				return;
			}
			Search(Visited, sx + dx[i], sy + dy[i]);
		}
	}
}
