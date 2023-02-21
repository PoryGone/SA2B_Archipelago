#pragma once
#include "MinigameBase.h"
#include "Pong.h"
#include "../ItemData.h"
#include <ctime>



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
	MinigameState state = MGS_None;
	ObjectMaster* IconObjPtr;
	MinigameIconData iconData = MinigameIconData();

private:
	MinigameBase* currentMinigame;
	MinigameManagerData lastInput = MinigameManagerData();
	std::clock_t minigameStart;
	//Minigames
	Pong pong = Pong();
};
