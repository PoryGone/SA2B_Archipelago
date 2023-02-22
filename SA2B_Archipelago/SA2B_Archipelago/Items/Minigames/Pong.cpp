#include "../../pch.h"
#include "Pong.h"


void Pong::OnGameStart()
{
	this->currentState = MGS_InProgress;

	this->leftPaddlePos.x  = PONG_LEFT + PONG_PADDLE_WIDTH;
	this->leftPaddlePos.y  = PONG_BOTTOM / 2.0f;
	this->rightPaddlePos.x = PONG_RIGHT - PONG_PADDLE_WIDTH;
	this->rightPaddlePos.y = PONG_BOTTOM / 2.0f;

	this->ballPos.x = PONG_RIGHT / 2.0f;
	this->ballPos.y = PONG_BOTTOM / 2.0f;

	this->ballSpeedX = 2.0f;
	this->ballSpeedY = 2.0f;
}

void Pong::OnFrame(MinigameManagerData data)
{
	this->OnFramePlayer(data);
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFrameSimulate(data);
	}
	this->OnFrameDraw(data);

	if (data.managerState & MGS_InProgress && data.input & RIF_Left)
	{
		this->currentState = MGS_Victory;
	}
}

void Pong::OnFramePlayer(MinigameManagerData data)
{
	if (data.input & RIF_Up)
	{
		this->leftPaddlePos.y -= playerSpeed;
	}
	else if (data.input & RIF_Down)
	{
		this->leftPaddlePos.y += playerSpeed;
	}
}

void Pong::OnFrameSimulate(MinigameManagerData data)
{
	if (data.input & RIF_Up)
	{
		this->rightPaddlePos.y -= AISpeed;
	}
	else if (data.input & RIF_Down)
	{
		this->rightPaddlePos.y += AISpeed;
	}

	this->ballPos.x += this->ballSpeedX;
	this->ballPos.y += this->ballSpeedY;

	this->ValidatePositions(data);
}

void Pong::ValidatePositions(MinigameManagerData data)
{
	if ((this->ballPos.x - PONG_BALL_RADIUS) <= PONG_LEFT || (this->ballPos.x + PONG_BALL_RADIUS) >= PONG_RIGHT)
	{
		this->ballSpeedX = -this->ballSpeedX;
	}

	if ((this->ballPos.y - PONG_BALL_RADIUS) <= PONG_TOP || (this->ballPos.y + PONG_BALL_RADIUS) >= PONG_BOTTOM)
	{
		this->ballSpeedY = -this->ballSpeedY;
	}

	if ((this->leftPaddlePos.y - PONG_PADDLE_HALFLENGTH) <= PONG_TOP)
	{
		this->leftPaddlePos.y = PONG_TOP + PONG_PADDLE_HALFLENGTH;
	}
	else if ((this->leftPaddlePos.y + PONG_PADDLE_HALFLENGTH) >= PONG_BOTTOM)
	{
		this->leftPaddlePos.y = PONG_BOTTOM - PONG_PADDLE_HALFLENGTH;
	}

	if ((this->rightPaddlePos.y - PONG_PADDLE_HALFLENGTH) <= PONG_TOP)
	{
		this->rightPaddlePos.y = PONG_TOP + PONG_PADDLE_HALFLENGTH;
	}
	else if ((this->rightPaddlePos.y + PONG_PADDLE_HALFLENGTH) >= PONG_BOTTOM)
	{
		this->rightPaddlePos.y = PONG_BOTTOM - PONG_PADDLE_HALFLENGTH;
	}
}

void Pong::OnFrameDraw(MinigameManagerData data)
{
	NJS_SPRITE sprite = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, data.icons->MinigameTex, data.icons->MinigameAnims };

	// Ball Sprite
	ballAngle += rotationDelta;
	ballAngle = ballAngle > 360.0f ? ballAngle - 360.0f : ballAngle;
	sprite.ang = NJM_DEG_ANG(ballAngle);
	sprite.sx = ((float)(PONG_BALL_RADIUS * 2) / (float)(PONG_PADDLE_BALL_X));
	sprite.sy = ((float)(PONG_BALL_RADIUS * 2) / (float)(PONG_PADDLE_BALL_Y));
	sprite.p = this->ballPos;
	sprite.tanim = data.icons->GetAnim(MGI_Spinball);
	DrawSprite2D(&sprite, 1, 1, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE);

	// Left Paddle Sprite
	sprite.ang = 0;
	sprite.sx = ((float)(PONG_PADDLE_WIDTH) / (float)(PONG_PADDLE_SPRITE_X));
	sprite.sy = ((float)(PONG_PADDLE_HALFLENGTH * 2) / (float)(PONG_PADDLE_SPRITE_Y));
	sprite.p = this->leftPaddlePos;
	sprite.tanim = data.icons->GetAnim(MGI_RoundedBar);
	DrawSprite2D(&sprite);

	// Right Paddle Sprite
	sprite.ang = 0;
	sprite.sx = ((float)(PONG_PADDLE_WIDTH) / (float)(PONG_PADDLE_SPRITE_X));
	sprite.sy = ((float)(PONG_PADDLE_HALFLENGTH * 2) / (float)(PONG_PADDLE_SPRITE_Y));
	sprite.p = this->rightPaddlePos;
	sprite.tanim = data.icons->GetAnim(MGI_RoundedBar);
	DrawSprite2D(&sprite);
}
