#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Backend/Time/TimeUtilities.h"

class FishingEasy 
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

class FishingMedium
{
public:
	void OnGameStart(MinigameManagerData data);
	void OnFrame(MinigameManagerData data);
	MinigameState currentState = MGS_None;

private:
	void CreateHierarchy(MinigameManagerData data);
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