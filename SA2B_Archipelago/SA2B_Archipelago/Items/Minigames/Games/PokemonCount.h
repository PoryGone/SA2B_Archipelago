#pragma once
#include <vector>

#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include "../Components/Wiggle.h"

#include "PokemonData.h"


// Sound Data
#define POKEMON_COUNT_SOUND_BEGIN    0x8019

enum PokemonCountState
{
	PCS_Parade = 0,
	PCS_AnswerTime,
	PCS_Results,
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

	void CreateHierarchy(MinigameManagerData data);

	void OnFramePlayer(MinigameManagerData data);
	void OnFrameSimulate(MinigameManagerData data);

private:
	int correctAnswer = 0;
	int correctAnswerSlot = 0;

	PokemonCountState state = PokemonCountState::PCS_Parade;

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
