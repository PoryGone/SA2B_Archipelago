#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include "../Components/Wiggle.h"
#include "PokemonData.h"
#include "Trivia.h"


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
	enum PokemonTriviaState
	{
		PTS_Start,
		PTS_InGame,
		PTS_Win,
		PTS_Lose,
	};

	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);
	void UpdateTimerFill();
	void OnFramePlayer(MinigameManagerData data);

	PokemonTriviaState localState;
	int endingTimer = 150;
	SpriteNode* resultNode;
	std::vector<SpriteNode*> inputResults;

	SpriteNode* timerBarBG;
	SpriteNode* timerBar;
	SpriteNode* timerBomb;
	SpriteNode* timerSonic;

	Timer timer;
	float guessTime = 10.0f;

	int correctAnswerSlot = 0;

	RawInputFlags anyDPad = RIF_Up | RIF_Down | RIF_Left | RIF_Right;

	SpriteNode* pokemonNode = nullptr;
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
