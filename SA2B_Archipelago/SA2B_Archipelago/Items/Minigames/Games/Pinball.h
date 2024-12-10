#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"

class Pinball : public MinigameBase
{

	enum PinballState
	{
		PS_None,
		PS_Countdown,
		PS_BallActive,
		PS_Victory,
		PS_Defeat,
	};

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);

	void UpdateBallActive(MinigameManagerData data);

	float ballRotationDelta = 2.0f;
	float gravity = 0.05f;
	float flipperForce = 3.0f;
	float flipperAngle = 60.0f; //Change in flipper angle when flipped
	float ballRadius = 5.0f;
	float baseDampening = 0.7f;

	RawInputFlags leftFlipperInput = RIF_Left | RIF_Up | RIF_Down;
	RawInputFlags rightFlipperInput = RIF_Right | RIF_Up | RIF_Down;

	NJS_POINT3 ballVelocity;
	SpriteNode* leftFlipper;
	SpriteNode* rightFlipper;
	SpriteNode* ball;
	SpriteNode* drain;
	Timer timer;
	SpriteNode* boardParent;
	std::vector<SpriteNode*> boardObjs;
	std::vector<SpriteNode*> normObjs;
	std::vector<SpriteNode*> colPtObjs;
	int normIndex = 0;

};