#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"


// Sound Data
#define MATH_QUIZ_SOUND_BEGIN    0x8019


class MathQuiz : public MinigameBase
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
