#pragma once
#include <ctime>

#include "MinigameBase.h"
#include "../ItemData.h"

#include "Minigames/Pong.h"
#include "Minigames/Platformer.h"



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

	MinigameState state = MinigameState::MGS_None;
	ObjectMaster* IconObjPtr;
	MinigameIconData iconData = MinigameIconData();
	SpriteHierarchy spriteHierarchy = SpriteHierarchy();
	CollisionManager collisionManager = CollisionManager();

private:
	MinigameBase* currentMinigame;
	MinigameManagerData _data = MinigameManagerData();
	std::clock_t minigameStart;

	//Minigames
	Pong pong             = Pong();
	Platformer platformer = Platformer();
};
