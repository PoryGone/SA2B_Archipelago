#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"


class Snake : public MinigameBase
{
	enum SnakeState
	{
		SS_Game = 0,
		SS_EndingWin,
		SS_EndingLose,
	};

	enum SnakeTileType
	{
		STT_None,
		STT_Head,
		STT_BodyStraight,
		STT_BodyTurn,
		STT_Tail,
		STT_Food,
		STT_Food2,
	};

	enum SnakeTileDirection
	{
		STD_None,
		STD_Down,
		STD_Left,
		STD_Up,
		STD_Right,
	};

	struct SnakeGridCell
	{
		SnakeTileType type;
		SnakeTileDirection direction;
		bool mirror = false;
		SpriteNode* cellParent;
	};

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);

	void FillGrid(MinigameManagerData data);
	void Tick();
	void GenerateFood();

	SnakeState localState;
	int endingTimer = 120;
	SpriteNode* resultNode;

	SnakeTileDirection playerDirection = SnakeTileDirection::STD_Right;

	std::vector<std::pair<int, int> > playerCells;
	std::pair<int, int> foodCell;

	int sizeX = 20;
	int sizeY = 15;

	std::vector<NJS_ARGB> colors = {
		{ 0.0f, 0.0f, 0.0f, 0.0f }, // None
		{ 1.0f, 0.0f, 1.0f, 0.0f }, // Head
		{ 1.0f, 0.0f, 0.5f, 0.0f }, // Body
		{ 1.0f, 0.0f, 0.0f, 0.5f }, // Tail
		{ 1.0f, 1.0f, 0.0f, 0.0f }, // Food
	};

	std::vector<MinigameIcon> snakeIcons = {
		MGI_Snake_Head,
		MGI_Snake_Straight,
		MGI_Snake_Turn,
		MGI_Snake_Tail,
		MGI_Super_Sonic,
		MGI_Super_Shadow,
	};

	float cellSize = 16.0f;

	int activeSpeed;
	std::vector<int> speeds = { 30, 15, 8 };
	int goalLength;
	std::vector<int> goalLengths = { 8, 15, 20 };

	SpriteNode* gridParent;
	
	std::vector<std::vector<SnakeGridCell>> grid;

	int frameCount = 0;
};