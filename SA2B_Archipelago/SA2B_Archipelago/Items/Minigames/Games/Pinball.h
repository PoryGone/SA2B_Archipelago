#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"

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
	void UpdateCountdown(MinigameManagerData data);
	void UpdateBallActive(MinigameManagerData data);
	void UpdateGameEnd(MinigameManagerData data);
	void SpawnBall(bool isFree = false);
	void AddScore(int score, MinigameManagerData data);
	void Win(MinigameManagerData data);
	void Lose(MinigameManagerData data);

	PinballState state;
	int countdown = 3;
	int lives;
	int totalScore;
	int scoreMult;
	int goalScore;
	float ballRotationDelta = 2.0f;
	float gravity = 0.05f;
	float flipperForceMin = 1.0f;
	float flipperForceMax = 10.0f;
	float flipperAngForceAngMin = 35.0f;
	float flipperAngForceAngMax = 95.0f;
	float flipperAngle = 60.0f; //Change in flipper angle when flipped
	float flipperLength = 45.0f;
	float ballRadius = 7.5f;
	float maxVelocity = 9.0f;
	float baseDampening = 0.3f;
	float bumperDampening = 1.3f;
	float ballStuckThreshold = 3.0f;
	float ballStuckTime = 5.0f;

	RawInputFlags leftFlipperInput = RIF_Left | RIF_Up | RIF_Down;
	RawInputFlags rightFlipperInput = RIF_Right | RIF_Up | RIF_Down;

	Timer endTimer;
	Stopwatch resetSW;

	NJS_POINT3 ballVelocity;
	NJS_POINT3 ballStuckPosition;
	SpriteNode* leftFlipper;
	SpriteNode* rightFlipper;
	SpriteNode* ball;
	SpriteNode* drain;
	SpriteNode* boardParent;
	std::vector<SpriteNode*> boardObjs;
	std::vector<SpriteNode*> boardObjsNoFlippers;
	std::vector<SpriteNode*> livesCounter;
	SpriteNode* scoreBoxNode;
	TextBox* scoreBox;
	SpriteNode* countdownNode;
	TextBox* countdownBox;
	SpriteNode* endIcon;

	//DEBUG
	/*
	std::vector<SpriteNode*> normObjs;
	std::vector<SpriteNode*> colPtObjs;
	int normIndex = 0;
	*/
};