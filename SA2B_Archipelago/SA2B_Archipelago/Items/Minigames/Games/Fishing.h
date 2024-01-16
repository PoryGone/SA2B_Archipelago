#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Backend/Time/TimeUtilities.h"

class FishingEasy 
{
	enum FishingState
	{
		FES_None,
		FES_WaitForFish,
		FES_FishOnLine,
		FES_Caught,
		FES_Escaped,
	};

public:
	void OnGameStart(MinigameManagerData data);
	void OnFrame(MinigameManagerData data);
	MinigameState currentState = MGS_None;

private:
	void CreateHierarchy(MinigameManagerData data);
	void FishEscaped();
	SpriteNode* biteIndicator = nullptr;
	float ringSize;
	Timer timer;
	RawInputFlags anyDPad = RIF_Up | RIF_Down | RIF_Left | RIF_Right;
	FishingState fs_state;
};

class FishingMedium
{
public:
	void OnGameStart(MinigameManagerData data);
	void OnFrame(MinigameManagerData data);
	MinigameState currentState = MGS_None;

private:
	void CreateHierarchy(MinigameManagerData data);
	SpriteNode* ring = nullptr;
	SpriteNode* zone = nullptr;
	float ringSize;
	float zoneSize;
	RawInputFlags anyDPad = RIF_Up | RIF_Down | RIF_Left | RIF_Right;
};

class FishingHard
{
public:
	void OnGameStart(MinigameManagerData data);
	void OnFrame(MinigameManagerData data);
	MinigameState currentState = MGS_None;

private:
	void CreateHierarchy(MinigameManagerData data);
};

class Fishing : public MinigameBase
{
public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;

private:
	FishingEasy easy;
	FishingEasy medium;
	FishingEasy hard;
};