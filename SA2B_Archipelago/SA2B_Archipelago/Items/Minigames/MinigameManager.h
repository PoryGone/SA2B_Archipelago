#pragma once
#include "MinigameBase.h"
#include "Games/Pong.h"
#include "../ItemData.h"
#include "Backend/Time/TimeUtilities.h"
#include <ctime>
#include <vector>



class MinigameManager
{
public:
	static MinigameManager& GetInstance()
	{
		static MinigameManager instance;
		return instance;
	}

	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();
	void OnInputFunction();

	void UpdateCurrentMinigame();
	void EndMinigame();
	void StartMinigame(ItemValue item);

	void HandleVictory();
	void HandleLoss();

	void SetDifficulty(int difficulty);

	void Pause();
	void Resume();

	MinigameState state = MinigameState::MGS_None;
	ObjectMaster* IconObjPtr;
	MinigameIconData iconData = MinigameIconData();
	SpriteHierarchy spriteHierarchy = SpriteHierarchy();
	CollisionManager collisionManager = CollisionManager();

	std::vector<Timer> timers = std::vector<Timer>();
	std::vector<Stopwatch> stopwatches = std::vector<Stopwatch>();

private:
	MinigameBase* currentMinigame;
	MinigameManagerData _data = MinigameManagerData();
	std::clock_t minigameStart;
	bool isPaused = false;

	//Minigames
	Pong pong = Pong();
};
