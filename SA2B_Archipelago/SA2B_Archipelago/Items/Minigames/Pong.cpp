#include "../../pch.h"
#include <cstdlib>
#include "Pong.h"


float DegToRad(float inDeg)
{
	return inDeg * 3.14159265358979323f / 180.0f;
}

void Pong::OnGameStart(MinigameManagerData data)
{
	this->currentState = MinigameState::MGS_InProgress;

	this->leftPaddlePos.x  = PONG_LEFT + (PONG_PADDLE_WIDTH / 2.0f);
	this->leftPaddlePos.y  = PONG_TOP + (PONG_BOTTOM - PONG_TOP) / 2.0f;
	this->rightPaddlePos.x = PONG_RIGHT - (PONG_PADDLE_WIDTH / 2.0f);
	this->rightPaddlePos.y = PONG_TOP + (PONG_BOTTOM - PONG_TOP) / 2.0f;

	this->activePlayerSpeed = PONG_PLAYER_SPEED;
	this->activeAISpeed     = PONG_AI_SPEED;

	this->ballPos.x = PONG_RIGHT / 2.0f;
	this->ballPos.y = PONG_TOP + (PONG_BOTTOM - PONG_TOP) / 2.0f;

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
}

void Pong::OnFrame(MinigameManagerData data)
{
	this->OnFramePlayer(data);
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFrameSimulate(data);
	}
	this->OnFrameDraw(data);
}

void Pong::OnFramePlayer(MinigameManagerData data)
{
	if (data.input & RawInputFlags::RIF_Up)
	{
		this->leftPaddlePos.y -= this->activePlayerSpeed;
	}
	else if (data.input & RawInputFlags::RIF_Down)
	{
		this->leftPaddlePos.y += this->activePlayerSpeed;
	}
}

void Pong::OnFrameSimulate(MinigameManagerData data)
{
	// AI
	if ((rand() % 100 < this->activeAIChance))
	{
		float paddleToBallDir = (this->ballPos.y - this->rightPaddlePos.y);

		if (paddleToBallDir < 0.0f)
		{
			this->rightPaddlePos.y -= this->activeAISpeed;
		}
		else if (paddleToBallDir > 0.0f)
		{
			this->rightPaddlePos.y += this->activeAISpeed;
		}
	}

	// Ball
	this->ballPos.x += this->ballSpeedX;
	this->ballPos.y += this->ballSpeedY;

	this->HandleCollision(data);
}

void Pong::HandleCollision(MinigameManagerData data)
{
	// Bounce from Player Paddle
	if ((this->ballPos.x - PONG_BALL_RADIUS) <= (PONG_LEFT + PONG_PADDLE_WIDTH))
	{
		float maxDist     = (PONG_BALL_RADIUS + PONG_PLAYER_PADDLE_HALFLENGTH);
		float currentDist = (this->ballPos.y - this->leftPaddlePos.y);

		if (abs(currentDist) <= maxDist)
		{
			this->ballPos.x = PONG_LEFT + PONG_PADDLE_WIDTH + PONG_BALL_RADIUS + 1;

			float normalizedDist = currentDist / maxDist;
			float newAngle = ((normalizedDist + 1) * PONG_PADDLE_HIT_ANGLE_RANGE / 2.0f) + PONG_PADDLE_HIT_ANGLE_OFFSET;

			this->ballSpeedX = sin(DegToRad(newAngle)) * PONG_BALL_SPEED;
			this->ballSpeedY = -cos(DegToRad(newAngle)) * PONG_BALL_SPEED;
		}
	}

	// Bounce from AI Paddle
	if ((this->ballPos.x + PONG_BALL_RADIUS) >= (PONG_RIGHT - PONG_PADDLE_WIDTH))
	{
		float maxDist = (PONG_BALL_RADIUS + PONG_AI_PADDLE_HALFLENGTH);
		float currentDist = (this->rightPaddlePos.y - this->ballPos.y);

		if (abs(currentDist) <= maxDist)
		{
			this->ballPos.x = PONG_RIGHT - PONG_PADDLE_WIDTH - PONG_BALL_RADIUS - 1;

			float normalizedDist = currentDist / maxDist;
			float newAngle = 180.0f + ((normalizedDist + 1) * PONG_PADDLE_HIT_ANGLE_RANGE / 2.0f) + PONG_PADDLE_HIT_ANGLE_OFFSET;

			this->ballSpeedX = sin(DegToRad(newAngle)) * PONG_BALL_SPEED;
			this->ballSpeedY = -cos(DegToRad(newAngle)) * PONG_BALL_SPEED;
		}
	}

	// You Win (past the AI Paddle)
	if ((this->ballPos.x + PONG_BALL_RADIUS) >= PONG_RIGHT)
	{
		this->currentState = MinigameState::MGS_Victory;
	}

	// You Lose (past the Player Paddle)
	if ((this->ballPos.x - PONG_BALL_RADIUS) <= PONG_LEFT)
	{
		this->currentState = MinigameState::MGS_Loss;
	}

	// Top/bottom bounce
	if ((this->ballPos.y - PONG_BALL_RADIUS) <= PONG_TOP || (this->ballPos.y + PONG_BALL_RADIUS) >= PONG_BOTTOM)
	{
		this->ballSpeedY = -this->ballSpeedY;
	}

	// Paddle Bounding
	if ((this->leftPaddlePos.y - PONG_PLAYER_PADDLE_HALFLENGTH) <= PONG_TOP)
	{
		this->leftPaddlePos.y = PONG_TOP + PONG_PLAYER_PADDLE_HALFLENGTH;
	}
	else if ((this->leftPaddlePos.y + PONG_PLAYER_PADDLE_HALFLENGTH) >= PONG_BOTTOM)
	{
		this->leftPaddlePos.y = PONG_BOTTOM - PONG_PLAYER_PADDLE_HALFLENGTH;
	}

	if ((this->rightPaddlePos.y - PONG_AI_PADDLE_HALFLENGTH) <= PONG_TOP)
	{
		this->rightPaddlePos.y = PONG_TOP + PONG_AI_PADDLE_HALFLENGTH;
	}
	else if ((this->rightPaddlePos.y + PONG_AI_PADDLE_HALFLENGTH) >= PONG_BOTTOM)
	{
		this->rightPaddlePos.y = PONG_BOTTOM - PONG_AI_PADDLE_HALFLENGTH;
	}
}

void Pong::OnFrameDraw(MinigameManagerData data)
{
	NJS_SPRITE sprite = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, data.icons->MinigameTex, data.icons->MinigameAnims };

	// Left Paddle Sprite (Player)
	sprite.ang = 0;
	sprite.sx = ((float)(PONG_PADDLE_WIDTH) / (float)(PONG_PADDLE_SPRITE_X));
	sprite.sy = ((float)(PONG_PLAYER_PADDLE_HALFLENGTH * 2) / (float)(PONG_PADDLE_SPRITE_Y));
	sprite.p = this->leftPaddlePos;
	sprite.tanim = data.icons->GetAnim(MinigameIcon::MGI_RoundedBar);
	DrawPaddleBacking(data, this->leftPaddlePos.x);
	DrawSprite2D(&sprite);

	// Right Paddle Sprite (AI)
	sprite.ang = 0;
	sprite.sx = ((float)(PONG_PADDLE_WIDTH) / (float)(PONG_PADDLE_SPRITE_X));
	sprite.sy = ((float)(PONG_AI_PADDLE_HALFLENGTH * 2) / (float)(PONG_PADDLE_SPRITE_Y));
	sprite.p = this->rightPaddlePos;
	sprite.tanim = data.icons->GetAnim(MinigameIcon::MGI_RoundedBar);
	DrawPaddleBacking(data, this->rightPaddlePos.x);
	DrawSprite2D(&sprite);

	// Ball Sprite
	this->ballAngle += rotationDelta;
	this->ballAngle = this->ballAngle > 360.0f ? this->ballAngle - 360.0f : this->ballAngle;
	sprite.ang = NJM_DEG_ANG(ballAngle);
	sprite.sx = ((float)(PONG_BALL_RADIUS * 2) / (float)(PONG_PADDLE_BALL_X));
	sprite.sy = ((float)(PONG_BALL_RADIUS * 2) / (float)(PONG_PADDLE_BALL_Y));
	sprite.p = this->ballPos;
	sprite.tanim = data.icons->GetAnim(MinigameIcon::MGI_Spinball);
	DrawSprite2D(&sprite, 1, 1, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE);
	
}

void Pong::DrawPaddleBacking(MinigameManagerData data, float xPos)
{
	NJS_SPRITE sprite = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, data.icons->MinigameTex, data.icons->MinigameAnims };

	sprite.sx = ((float)(PONG_PADDLE_WIDTH) / (float)(PONG_PADDLE_SPRITE_X));
	sprite.sy = ((float)(PONG_AI_PADDLE_HALFLENGTH * 2) / (float)(PONG_PADDLE_SPRITE_Y));
	sprite.p.x = xPos;

	sprite.p.y = PONG_BOTTOM - PONG_PLAYER_PADDLE_HALFLENGTH;
	sprite.tanim = data.icons->GetAnim(MinigameIcon::MGI_RoundedBarDark_Bottom);
	DrawSprite2D(&sprite);

	sprite.p.y = PONG_TOP + PONG_PLAYER_PADDLE_HALFLENGTH;
	sprite.tanim = data.icons->GetAnim(MinigameIcon::MGI_RoundedBarDark_Top);
	DrawSprite2D(&sprite);

	sprite.p.y += 0.5f;
	sprite.sy = ((float)(PONG_AI_PADDLE_HALFLENGTH * 2 - 1) / (float)(PONG_PADDLE_SPRITE_Y));
	sprite.tanim = data.icons->GetAnim(MinigameIcon::MGI_RoundedBarDark_Mid);

	for (int i = 0; i < 4; i++)
	{
		sprite.p.y += PONG_PLAYER_PADDLE_HALFLENGTH * 2 - 1;
		DrawSprite2D(&sprite);
	}
}
