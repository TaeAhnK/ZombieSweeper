//
#pragma once

#include "CoreMinimal.h"

class ZOMBIESWEEPER_API FieldMap
{

public:
	FieldMap(int8 Width, int8 Height, FIntPoint StartXY, FIntPoint TargetXY);
	void PlantZombie(int16 ZNum);

	TArray<TArray<int8>> Map;

protected:
	int8 MapWidth;
	int8 MapHeight;
	FIntPoint StartXY;
	FIntPoint TargetXY;

	void InitMap();
	bool RootExist();

private:
	void SetAdjNum(int8 x, int8 y);
	bool isValidXY(int8 x, int8 y);
	void Search(TArray<TArray<bool>>& Visited, int8 sx, int8 sy);

	const int8 dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	const int8 dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
};
