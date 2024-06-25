#pragma once
#include "MinigameIconData.h"
#include "TextDisplayData.h"
#include "../../Utilities/SpriteUtilities.h"
#include "../../Utilities/EasingUtilities.h"
#include "Backend/MinigameBackend.h"
#include "Backend/Time/TimeUtilities.h"
#include <vector>

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
	//C-C-C-Combo Inputs!
	RIF_ANY_D_PAD = 0b11110000,
};
DEFINE_ENUM_FLAG_OPERATORS(RawInputFlags);

enum MinigameState
{
	MGS_None,
	MGS_PreGame,
	MGS_InProgress,
	MGS_Victory,
	MGS_Draw,
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
	RawInputFlags inputPress;
	RawInputFlags inputRelease;
	MinigameState managerState;
	MinigameIconData* icons;
	TextDisplayData* text;
	MinigameDifficulty difficulty;
	SpriteHierarchy* hierarchy;
	CollisionManager* collision;

	std::vector<Timer*>* timers;
	std::vector<Stopwatch*>* stopwatches;
};

class MinigameBase
{
public:
	virtual void OnGameStart(MinigameManagerData data) = 0;
	virtual void OnFrame(MinigameManagerData data) = 0;
	virtual void OnCleanup(MinigameManagerData data) {};
	MinigameState currentState;
	float pregameTime = 1.0f;
};