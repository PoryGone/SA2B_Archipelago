#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"

class PunchOut : public MinigameBase
{
	enum PunchOutPlayerState
	{
		POP_Idle,
		POP_DodgeRight,
		POP_DodgeLeft,
		POP_PunchRight,
		POP_PunchLeft,
	};

	enum PunchOutAIState
	{
		POA_Idle,
		POA_Blocking,
		POA_PunchRight,
		POA_PunchLeft,
	};

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);

	void UpdateCenterText(MinigameManagerData data);
	void UpdateAI();
	void UpdatePlayer();

	PunchOutAIState aiState;
	PunchOutPlayerState playerState;

	Timer aiTimer;
	Timer playerTimer;

	SpriteNode* aiParent;
	SpriteNode* aiBody;
	SpriteNode* aiHead;
	SpriteNode* aiRightHand;
	SpriteNode* aiLeftHand;

	SpriteNode* playerParent;
	SpriteNode* playerBody;
	SpriteNode* playerHead;
	SpriteNode* playerRightHand;
	SpriteNode* playerLeftHand;

	SpriteNode* centerTextParent;
	TextBox* centerText;
	float textMaxSize = 70.0f;
	float textSize = 0.0f;
};