#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/Wiggle.h"
#include "../Components/TextBox.h"
#include <array>

class NumberSequence : public MinigameBase
{
	enum NumberSequenceState
	{
		NSS_Start,
		NSS_InGame,
		NSS_Win,
		NSS_Lose,
	};

	struct NumberSequenceNumber
	{
		SpriteNode* parent;
		SpriteNode* upArrow;
		SpriteNode* downArrow;
		SpriteNode* textNode;
		SpriteNode* prevTextNode;
		SpriteNode* prevIcon;
		TextBox* text;
		TextBox* prevText;
		int current;
		int correct;
	};

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);

	void Increment(NumberSequenceNumber* nsNumber);
	void Decrement(NumberSequenceNumber* nsNumber);
	void SetSelectedIndex(int index);
	bool AnySequenceContains(int n);
	void SubmitSequence(MinigameManagerData data);
	void UpdateTimerFill();

	NumberSequenceState localState;
	int endingTimer;
	SpriteNode* resultNode;

	NumberSequenceState state;
	Timer timer;
	int guessesRemaining = 0;

	SpriteNode* timerBarBG;
	SpriteNode* timerBar;
	SpriteNode* timerBomb;
	SpriteNode* timerSonic;

	float guessTime = 10.0f;

	std::array<int, 9> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::array< NumberSequenceNumber, 4> numberObjs;

	NJS_POINT3 smallArrowSize = { 20.0f, 20.0f };
	NJS_POINT3 bigArrowSize = { 40.0f, 40.0f };
	float smallTextSize = 15.0f;
	float bigTextSize = 30.0f;

	NJS_ARGB greenColor = { 1.0f, 0.0f, 0.5647f, 0.2078f };
	NJS_ARGB redColor = { 1.0f, 0.8f, 0.0f, 0.0f };
	NJS_ARGB yellowColor = { 1.0f, 0.949f, 0.9804f, 0.1451f };

	int selectedIndex = 0;

	SpriteNode* submitParent;
	SpriteNode* submitUp;
	SpriteNode* submitDown;
	TextBox* submitText;

	std::array<SpriteNode*, 15> questionMarks;
	//TextBox* questionMarkText;
};