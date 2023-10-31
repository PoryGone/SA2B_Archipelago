#include "../../pch.h"
#include <cstdlib>
#include "Pong.h"
#include "Components/RotateSpriteNode.h"


float DegToRad(float inDeg)
{
	return inDeg * 3.14159265358979323f / 180.0f;
}

void Pong::OnGameStart(MinigameManagerData data)
{
	this->currentState = MinigameState::MGS_InProgress;

	this->CreateHierarchy(data);

	this->activePlayerSpeed = PONG_PLAYER_SPEED;
	this->activeAISpeed     = PONG_AI_SPEED;

	float startingAngle = 90.0f * ((rand() % 2) + 2) + ((rand() % 31) + 30);
	this->ballSpeedX = sin(DegToRad(startingAngle)) * PONG_BALL_SPEED;
	this->ballSpeedY = -cos(DegToRad(startingAngle)) * PONG_BALL_SPEED;

	if (data.difficulty == MinigameDifficulty::MGD_Easy)
	{
		this->activeAIChance = PONG_AI_EASY_CHANCE;
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Medium)
	{
		this->activeAIChance = PONG_AI_MEDIUM_CHANCE;
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Hard)
	{
		this->activeAIChance = PONG_AI_HARD_CHANCE;
	}

	PlaySoundProbably(PONG_SOUND_BEGIN, 0, 0, 0);
}

void Pong::OnFrame(MinigameManagerData data)
{
	this->OnFramePlayer(data);
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFrameSimulate(data);
	}
}

void Pong::OnFramePlayer(MinigameManagerData data)
{
	if (data.input & RawInputFlags::RIF_Up)
	{
		this->leftPaddle->Translate({ 0,-this->activePlayerSpeed,0 });
	}
	else if (data.input & RawInputFlags::RIF_Down)
	{
		this->leftPaddle->Translate({ 0,this->activePlayerSpeed,0 });
	}
}

void Pong::OnFrameSimulate(MinigameManagerData data)
{
	// AI
	if ((rand() % 100 < this->activeAIChance))
	{
		float paddleToBallDir = (this->ball->GetPositionGlobal().y - this->rightPaddle->GetPositionGlobal().y);

		if (paddleToBallDir < 0.0f)
		{
			this->rightPaddle->Translate({ 0,-this->activeAISpeed,0 });
		}
		else if (paddleToBallDir > 0.0f)
		{
			this->rightPaddle->Translate({ 0,this->activeAISpeed,0 });
		}
	}

	// Ball
	this->ball->Translate({ this->ballSpeedX , this->ballSpeedY, 0 });

	this->HandleCollision(data);
}

void Pong::HandleCollision(MinigameManagerData data)
{
	// Bounce from Player Paddle
	if ((this->ball->GetPositionGlobal().x - PONG_BALL_RADIUS) <= (PONG_LEFT + PONG_PADDLE_WIDTH))
	{
		float maxDist     = (PONG_BALL_RADIUS + PONG_PLAYER_PADDLE_HALFLENGTH);
		float currentDist = (this->ball->GetPositionGlobal().y - this->leftPaddle->GetPositionGlobal().y);

		if (abs(currentDist) <= maxDist)
		{
			NJS_POINT3 ballPos = ball->GetPositionGlobal();
			ballPos.x = PONG_LEFT + PONG_PADDLE_WIDTH + PONG_BALL_RADIUS + 1;
			ball->SetPositionGlobal(ballPos);

			float normalizedDist = currentDist / maxDist;
			float newAngle = ((normalizedDist + 1) * PONG_PADDLE_HIT_ANGLE_RANGE / 2.0f) + PONG_PADDLE_HIT_ANGLE_OFFSET;

			this->ballSpeedX = sin(DegToRad(newAngle)) * PONG_BALL_SPEED;
			this->ballSpeedY = -cos(DegToRad(newAngle)) * PONG_BALL_SPEED;

			PlaySoundProbably(PONG_SOUND_PLAYER_PADDLE, 0, 0, 0);
		}
	}

	// Bounce from AI Paddle
	if ((ball->GetPositionGlobal().x + PONG_BALL_RADIUS) >= (PONG_RIGHT - PONG_PADDLE_WIDTH))
	{
		float maxDist = (PONG_BALL_RADIUS + PONG_AI_PADDLE_HALFLENGTH);
		float currentDist = (this->rightPaddle->GetPositionGlobal().y - this->ball->GetPositionGlobal().y);

		if (abs(currentDist) <= maxDist)
		{
			NJS_POINT3 ballPos = ball->GetPositionGlobal();
			ballPos.x = PONG_RIGHT - PONG_PADDLE_WIDTH - PONG_BALL_RADIUS - 1;
			ball->SetPositionGlobal(ballPos);

			float normalizedDist = currentDist / maxDist;
			float newAngle = 180.0f + ((normalizedDist + 1) * PONG_PADDLE_HIT_ANGLE_RANGE / 2.0f) + PONG_PADDLE_HIT_ANGLE_OFFSET;

			this->ballSpeedX = sin(DegToRad(newAngle)) * PONG_BALL_SPEED;
			this->ballSpeedY = -cos(DegToRad(newAngle)) * PONG_BALL_SPEED;

			PlaySoundProbably(PONG_SOUND_AI_PADDLE, 0, 0, 0);
		}
	}

	// You Win (past the AI Paddle)
	if ((this->ball->GetPositionGlobal().x + PONG_BALL_RADIUS) >= PONG_RIGHT)
	{
		this->currentState = MinigameState::MGS_Victory;

		PlaySoundProbably(PONG_SOUND_WIN, 0, 0, 0);
	}

	// You Lose (past the Player Paddle)
	if ((this->ball->GetPositionGlobal().x - PONG_BALL_RADIUS) <= PONG_LEFT)
	{
		this->currentState = MinigameState::MGS_Loss;

		PlaySoundProbably(PONG_SOUND_LOSE, 0, 0, 0);
	}

	// Top/bottom bounce
	if ((this->ball->GetPositionGlobal().y - PONG_BALL_RADIUS) <= PONG_TOP || (this->ball->GetPositionGlobal().y + PONG_BALL_RADIUS) >= PONG_BOTTOM)
	{
		this->ballSpeedY = -this->ballSpeedY;

		PlaySoundProbably(PONG_SOUND_BOUNDS, 0, 0, 0);
	}

	// Paddle Bounding
	NJS_POINT3 leftPaddlePos = this->leftPaddle->GetPositionGlobal();
	if ((leftPaddlePos.y - PONG_PLAYER_PADDLE_HALFLENGTH) <= PONG_TOP)
	{
		leftPaddlePos.y = PONG_TOP + PONG_PLAYER_PADDLE_HALFLENGTH;
	}
	else if ((leftPaddlePos.y + PONG_PLAYER_PADDLE_HALFLENGTH) >= PONG_BOTTOM)
	{
		leftPaddlePos.y = PONG_BOTTOM - PONG_PLAYER_PADDLE_HALFLENGTH;
	}
	this->leftPaddle->SetPositionGlobal(leftPaddlePos);

	NJS_POINT3 rightPaddlePos = this->rightPaddle->GetPositionGlobal();
	if ((rightPaddlePos.y - PONG_AI_PADDLE_HALFLENGTH) <= PONG_TOP)
	{
		rightPaddlePos.y = PONG_TOP + PONG_AI_PADDLE_HALFLENGTH;
	}
	else if ((rightPaddlePos.y + PONG_AI_PADDLE_HALFLENGTH) >= PONG_BOTTOM)
	{
		rightPaddlePos.y = PONG_BOTTOM - PONG_AI_PADDLE_HALFLENGTH;
	}
	this->rightPaddle->SetPositionGlobal(rightPaddlePos);
}

void Pong::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(RIF_Down | RIF_Up, { PONG_LEFT + 45.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
	
	//Paddles
	SpriteNode* leftPaddleBack = data.hierarchy->CreateNode("LeftPaddle_BG");
	SpriteNode* rightPaddleBack = data.hierarchy->CreateNode("RightPaddle_BG");
	float height = PONG_PLAYER_PADDLE_HALFLENGTH * 2;
	float midHeight = PONG_BOTTOM - PONG_TOP - (height * 2);
	float middle = PONG_TOP + (PONG_BOTTOM - PONG_TOP) / 2.0f;
	
	//Left Paddle
	SpriteNode* top = data.hierarchy->CreateNode("LP_Top", data.icons->GetAnim(MGI_RoundedBarDark_Top), { PONG_PADDLE_WIDTH, height, 1 }, { 0, 0, 0}, leftPaddleBack);
	SpriteNode* bottom = data.hierarchy->CreateNode("LP_Bottom", data.icons->GetAnim(MGI_RoundedBarDark_Bottom), { PONG_PADDLE_WIDTH, height, 1 }, { 0, 0, 0 }, leftPaddleBack);
	SpriteNode* mid = data.hierarchy->CreateNode("LP_Mid", data.icons->GetAnim(MGI_RoundedBarDark_Mid), { PONG_PADDLE_WIDTH, midHeight, 1 }, { 0, 0, 0 }, leftPaddleBack);
	leftPaddle = data.hierarchy->CreateNode("LP_Paddle", data.icons->GetAnim(MGI_RoundedBar), { PONG_PADDLE_WIDTH, height, 1 }, { 0, 0, 0 }, leftPaddleBack);
	leftPaddleBack->SetPositionGlobal({ PONG_LEFT + (PONG_PADDLE_WIDTH * 0.5f), 0, 0 });
	top->SetPosition({ 0, PONG_TOP + PONG_PLAYER_PADDLE_HALFLENGTH, 0 });
	bottom->SetPosition({ 0, PONG_BOTTOM - PONG_PLAYER_PADDLE_HALFLENGTH, 0 });
	mid->SetPosition({ 0, middle, 0 });
	leftPaddle->SetPosition({ 0, middle, 0 });
	
	//Right Padde
	top = data.hierarchy->CreateNode("RP_Top", data.icons->GetAnim(MGI_RoundedBarDark_Top), { PONG_PADDLE_WIDTH, height, 1 }, { 0, 0, 0 }, rightPaddleBack);
	bottom = data.hierarchy->CreateNode("RP_Bottom", data.icons->GetAnim(MGI_RoundedBarDark_Bottom), { PONG_PADDLE_WIDTH, height, 1 }, { 0, 0, 0 }, rightPaddleBack);
	mid = data.hierarchy->CreateNode("RP_Mid", data.icons->GetAnim(MGI_RoundedBarDark_Mid), { PONG_PADDLE_WIDTH, midHeight, 1 }, { 0, 0, 0 }, rightPaddleBack);
	rightPaddle = data.hierarchy->CreateNode("RP_Paddle", data.icons->GetAnim(MGI_RoundedBar), { PONG_PADDLE_WIDTH, height, 1 }, { 0, 0, 0 }, rightPaddleBack);
	rightPaddleBack->SetPositionGlobal({ PONG_RIGHT - (PONG_PADDLE_WIDTH * 0.5f), 0, 0 });
	top->SetPosition({ 0, PONG_TOP + PONG_PLAYER_PADDLE_HALFLENGTH, 0 });
	bottom->SetPosition({ 0, PONG_BOTTOM - PONG_PLAYER_PADDLE_HALFLENGTH, 0 });
	mid->SetPosition({ 0, middle, 0 });
	rightPaddle->SetPosition({ 0, middle, 0 });

	//Ball
	float ballX = PONG_LEFT + (PONG_RIGHT - PONG_LEFT) / 2.0f;
	float ballY = PONG_TOP + (PONG_BOTTOM - PONG_TOP) / 2.0f;
	ball = data.hierarchy->CreateNode("Ball", data.icons->GetAnim(MGI_Spinball), { PONG_BALL_RADIUS * 2, PONG_BALL_RADIUS * 2, 1 }, { ballX, ballY, 0 });
	ball->components.push_back(new RotateSpriteNode(0.0f, rotationDelta));
	
}
