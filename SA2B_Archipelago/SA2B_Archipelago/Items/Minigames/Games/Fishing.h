#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Backend/Time/TimeUtilities.h"
#include <vector>

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
	enum FishingState
	{
		FMS_Fishing,
		FMS_Caught,
		FMS_Escaped,
	};

public:
	void OnGameStart(MinigameManagerData data);
	void OnFrame(MinigameManagerData data);
	MinigameState currentState = MGS_None;

private:
	void CreateHierarchy(MinigameManagerData data);
	std::vector<float> zoneSizes = { 50.0f, 50.0f, 50.0f };
	std::vector<float> ringSizes = { 200.0f, 200.0f, 200.0f };
	std::vector<Timer> timers = { Timer(),Timer() };
	Timer endTimer;
	std::vector<SpriteNode*> rings = { nullptr, nullptr, nullptr };
	std::vector<SpriteNode*> zones = { nullptr, nullptr, nullptr };
	int successCount;
	int ringCount;
	RawInputFlags anyDPad = RIF_Up | RIF_Down | RIF_Left | RIF_Right;
	std::vector<float> yPositions = { 220.0f, 290.0f, 360.0f };
	std::vector<float> xPositions = { 140.0f, 320.0f, 500.0f };
	FishingState fs_state;
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
	FishingMedium easy;
	FishingMedium medium;
	FishingMedium hard;
};