#pragma once
#include "MinigameBase.h"


// Desired Size
#define PONG_BALL_RADIUS       8
#define PONG_PADDLE_HALFLENGTH 32
#define PONG_PADDLE_WIDTH      16

// Pong Boundaries
#define PONG_TOP    0
#define PONG_BOTTOM 480
#define PONG_LEFT   0
#define PONG_RIGHT  640

// Sprite Data
#define PONG_PADDLE_SPRITE_X 64
#define PONG_PADDLE_SPRITE_Y 256
#define PONG_PADDLE_BALL_X   64
#define PONG_PADDLE_BALL_Y   64


class Pong : public MinigameBase
{
public:
	void OnGameStart() override;
	void OnFrame(MinigameManagerData data) override;

	void OnFramePlayer(MinigameManagerData data);
	void OnFrameSimulate(MinigameManagerData data);
	void OnFrameDraw(MinigameManagerData data);

	void ValidatePositions(MinigameManagerData data);

private:
	float ballSpeedX = 2.0f;
	float ballSpeedY = 2.0f;

	float playerSpeed = 2.0f;
	float AISpeed     = 4.0f;

	float ballAngle     = 0;
	float rotationDelta = 2.0f;

	NJS_POINT3 leftPaddlePos  = NJS_POINT3();
	NJS_POINT3 rightPaddlePos = NJS_POINT3();
	NJS_POINT3 ballPos        = NJS_POINT3();
};
