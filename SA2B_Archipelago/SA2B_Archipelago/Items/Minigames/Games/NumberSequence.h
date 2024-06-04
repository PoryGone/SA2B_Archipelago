#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include <array>

class NumberSequence : public MinigameBase
{
	enum NumberSequenceState
	{
		NSS_InGame,
		NSS_Win,
	};

	struct NumberSequenceNumber
	{
		SpriteNode* parent;
		SpriteNode* upArrow;
		SpriteNode* downArrow;
		SpriteNode* textNode;
		TextBox* text;
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
	void SubmitSequence();

	NumberSequenceState state;
	Timer timer;

	std::array<int, 10> numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::array< NumberSequenceNumber, 4> numberObjs;

	NJS_POINT3 smallArrowSize = { 20.0f, 20.0f };
	NJS_POINT3 bigArrowSize = { 40.0f, 40.0f };
	float smallTextSize = 15.0f;
	float bigTextSize = 30.0f;

	int selectedIndex = 0;

	RawInputFlags anyDPad = RIF_Up | RIF_Down | RIF_Left | RIF_Right;

	SpriteNode* submitParent;
	SpriteNode* submitUp;
	SpriteNode* submitDown;
	TextBox* submitText;
};