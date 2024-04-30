#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include "PokemonData.h"
#include "Trivia.h"


// Sound Data
#define POKEMON_TRIVIA_SOUND_BEGIN    0x8019

struct PokemonTriviaQuestion: public TriviaQuestion
{
	PokemonTriviaQuestion() {}

	PokemonTriviaQuestion(const char* question)
	{
		this->question = std::string(question);

	}

	void SetPokemon(PokemonData inPokemon)
	{
		this->pokemon = inPokemon;

		// Handle generating correct answers here
		this->correctAnswers;
		this->wrongAnswers;
	}

	//std::string question;

	PokemonData pokemon;

	//std::vector<const char*> correctAnswers;
	//std::vector<const char*> wrongAnswers;
};


class PokemonTrivia : public Trivia
{
public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

	void OnFramePlayer(MinigameManagerData data);

private:
	int correctAnswerSlot = 0;

	RawInputFlags anyDPad = RIF_Up | RIF_Down | RIF_Left | RIF_Right;

	SpriteNode* questionNode = nullptr;
	TextBox* questionBox = nullptr;

	SpriteNode* answer1Node = nullptr;
	TextBox* answer1Box = nullptr;

	SpriteNode* answer2Node = nullptr;
	TextBox* answer2Box = nullptr;

	SpriteNode* answer3Node = nullptr;
	TextBox* answer3Box = nullptr;

	SpriteNode* answer4Node = nullptr;
	TextBox* answer4Box = nullptr;
};
