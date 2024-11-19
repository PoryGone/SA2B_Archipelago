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
	float ballRadius = 5.0f;
	float baseDampening = 0.7f;

	NJS_POINT3 ballVelocity;
	SpriteNode* ball;
	SpriteNode* drain;
	Timer timer;
	SpriteNode* boardParent;
	std::vector<SpriteNode*> boardObjs;
	std::vector<SpriteNode*> normObjs;
	std::vector<SpriteNode*> colPtObjs;
	int normIndex = 0;

};