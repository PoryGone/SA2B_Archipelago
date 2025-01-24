#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include "../Components/Wiggle.h"


struct TriviaQuestion
{
	TriviaQuestion() {}

	TriviaQuestion(const char* question, std::vector<const char*> correctAnswers, std::vector<const char*> wrongAnswers)
	{
		this->question = std::string(question);

		this->correctAnswers = correctAnswers;
		this->wrongAnswers = wrongAnswers;
	}

	std::string question;

	std::vector<const char*> correctAnswers;
	std::vector<const char*> wrongAnswers;
};


class Trivia : public MinigameBase
{
public:
	enum TriviaState
	{
		TS_Start,
		TS_InGame,
		TS_Win,
		TS_Lose,
	};

	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);
	void UpdateTimerFill();
	void OnFramePlayer(MinigameManagerData data);

	TriviaState localState;
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
