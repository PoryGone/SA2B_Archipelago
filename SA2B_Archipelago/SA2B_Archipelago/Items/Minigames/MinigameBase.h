#pragma once
#include "MinigameIconData.h"
#include "../../Utilities/SpriteUtilities.h"
#include "Backend/MinigameBackend.h"

enum RawInputFlags
{
	RIF_None = 0,
	RIF_B = 2,
	RIF_A = 4,
	RIF_Start = 8,
	RIF_Up = 16,
	RIF_Down = 32,
	RIF_Left = 64,
	RIF_Right = 128,
	RIF_Y = 512,
	RIF_X = 1024,
	RIF_RightTrigger = 65536,
	RIF_LeftTrigger = 131072,
};
DEFINE_ENUM_FLAG_OPERATORS(RawInputFlags);

enum MinigameState
{
	MGS_None,
	MGS_PreGame,
	MGS_InProgress,
	MGS_Victory,
	MGS_Loss,
};

enum MinigameDifficulty
{
	MGD_Easy,
	MGD_Medium,
	MGD_Hard,
};

struct MinigameManagerData
{
public:
	RawInputFlags input;
	MinigameState managerState;
	MinigameIconData* icons;
	MinigameDifficulty difficulty;
	SpriteHierarchy* hierarchy;
};

class MinigameBase
{
public:
	virtual void OnGameStart(MinigameManagerData data) = 0;
	virtual void OnFrame(MinigameManagerData data) = 0;
	MinigameState currentState;
	float pregameTime = 1.0f;
};