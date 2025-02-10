#pragma once
#include <vector>

#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include "../Components/Wiggle.h"

#include "PokemonData.h"


enum PokemonCountState
{
	PCS_Parade = 0,
	PCS_AnswerTime,
	PCS_Win,
	PCS_Lose,
};

struct PokemonSpawn
{
	PokemonSpawn(PokemonData inData) : data(inData) {}

	PokemonData data;

	SpriteNode* node;

	float moveSpeed = 1.5f;

	bool pastEnd = false;
};


class PokemonCount : public MinigameBase
{
public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);
	void UpdateTimerFill();
	void OnFramePlayer(MinigameManagerData data);
	void OnFrameSimulate(MinigameManagerData data);

	int endingTimer;
	SpriteNode* resultNode;
	std::vector<SpriteNode*> inputResults;

	SpriteNode* timerBarBG;
	SpriteNode* timerBar;
	SpriteNode* timerBomb;
	SpriteNode* timerSonic;

	Timer timer;
	float guessTime = 7.0f;

	int correctAnswer = 0;
	int correctAnswerSlot = 0;

	PokemonCountState localState = PokemonCountState::PCS_Parade;

	RawInputFlags anyDPad = RIF_Up | RIF_Down | RIF_Left | RIF_Right;

	SpriteNode* questionNode = nullptr;
	TextBox* questionBox = nullptr;
	std::vector<PokemonSpawn*> pokemonSpawns;

	std::vector<int> questionOptions;

	SpriteNode* answerHolderNode = nullptr;

	SpriteNode* answer1Node = nullptr;
	TextBox* answer1Box = nullptr;

	SpriteNode* answer2Node = nullptr;
	TextBox* answer2Box = nullptr;

	SpriteNode* answer3Node = nullptr;
	TextBox* answer3Box = nullptr;

	SpriteNode* answer4Node = nullptr;
	TextBox* answer4Box = nullptr;
};
