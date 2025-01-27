#pragma once
#include <ctime>
#include <vector>

#include "MinigameBase.h"
#include "Games/Literature.h"
#include "Games/Pong.h"
#include "Games/Fishing.h"
#include "Games/Breakout.h"
#include "Games/Trivia.h"
#include "Games/PokemonTrivia.h"
#include "Games/PokemonCount.h"
#include "Games/MinigameFinalBoss.h"
#include "Games/NumberSequence.h"
#include "Games/LightUpPath.h"
#include "Games/PunchOut.h"
#include "Games/Pinball.h"
#include "Games/MathQuiz.h"
#include "Games/Snake.h"
#include "Games/InputSequence.h"
#include "../ItemData.h"
#include "../../Aesthetics/StatsManager.h"
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
	void StartMinigame(ItemValue item, bool locationGame = false, bool linkedTrap = false);

	void HandleVictory();
	void HandleLoss();

	void SetDifficulty(int difficulty);

	void Pause();
	void Resume();

	MinigameState state = MinigameState::MGS_None;
	ObjectMaster* IconObjPtr;
	MinigameIconData iconData = MinigameIconData();
	TextDisplayData textData = TextDisplayData();
	SpriteHierarchy spriteHierarchy = SpriteHierarchy();
	CollisionManager collisionManager = CollisionManager();

	std::vector<Timer*> timers = std::vector<Timer*>();
	std::vector<Stopwatch*> stopwatches = std::vector<Stopwatch*>();

private:
	const HelperFunctions* _helperFunctions;

	MinigameBase* currentMinigame;
	MinigameManagerData _data = MinigameManagerData();
	std::clock_t minigameStart;
	bool isPaused = false;

	MinigameDifficulty _baseDifficulty;

	ItemValue currentMinigameItem;

	//Minigames
	Literature literature			= Literature();
	Pong pong						= Pong();
	Fishing fishing					= Fishing();
	Breakout breakout				= Breakout();
	Trivia trivia					= Trivia();
	PokemonTrivia pokemonTrivia		= PokemonTrivia();
	PokemonCount pokemonCount		= PokemonCount();
	MinigameFinalBoss finalBoss		= MinigameFinalBoss();
	NumberSequence numberSequence	= NumberSequence();
	LightUpPath lightUpPath			= LightUpPath();
	Pinball pinball					= Pinball();
	MathQuiz mathQuiz				= MathQuiz();
	Snake snake						= Snake();
	InputSequence inputSequence		= InputSequence();

	//On Hold
	PunchOut punchOut				= PunchOut();
};
