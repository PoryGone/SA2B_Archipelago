#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"


class LightUpPath : public MinigameBase
{
	enum LightUpPathTileType
	{
		LTT_None, //Grid position does not exist
		LTT_Open,
		LTT_Closed,
		LTT_Start,
	};

	struct PathGridCell
	{
		bool active;
		bool used;
		SpriteNode* cellParent;
		SpriteNode* upArrow;
		SpriteNode* downArrow;
		SpriteNode* leftArrow;
		SpriteNode* rightArrow;
	};

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);

	void FillGrid();
	void Move(int x, int y);
	void Set(int x, int y);
	LightUpPathTileType GetCellType(int index, int x, int y);
	PathGridCell* GetCell(int x, int y);

	//0,0 is top left
	int cursorX;
	int cursorY;

	int sizeX = 5;
	int sizeY = 5;

	NJS_ARGB closedColor = { 1.0f, 1.0f, 0.0f, 0.0f };
	NJS_ARGB openColor = { 1.0f, 1.0f, 1.0f, 1.0f };
	NJS_ARGB usedColor = { 1.0f, 1.0f, 1.0f, 0.0f };

	float cellSize = 50.0f;

	SpriteNode* gridParent;
	
	std::vector<std::vector<PathGridCell>> grid;

	std::vector<std::vector<std::vector<LightUpPathTileType>>> layouts {
		{
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Start, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//S-000
		},
		{
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Closed, LTT_Start, LTT_Open, LTT_Open},			//0-S00
		},
	};

};