#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include <array>

class InputSequence : public MinigameBase
{
	enum InputSequenceState
	{
		ISS_Start,
		ISS_InGame,
		ISS_Win,
		ISS_Lose,
	};

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);
	void UpdateTimerFill();

	InputSequenceState state;
	Timer timer;
	float guessTime = 10.0f;

	int selectedIndex = 0;

	SpriteNode* timerBarBG;
	SpriteNode* timerBar;
};