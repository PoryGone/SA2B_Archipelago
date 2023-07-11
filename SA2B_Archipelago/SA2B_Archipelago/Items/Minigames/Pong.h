#pragma once
#include "MinigameBase.h"
#include "MinigameUtilities.h"


// Pong Boundaries
#define PONG_TOP    100
#define PONG_BOTTOM 480
#define PONG_LEFT   20
#define PONG_RIGHT  620

// Sprite Data
#define PONG_PADDLE_SPRITE_X 64
#define PONG_PADDLE_SPRITE_Y 256
#define PONG_PADDLE_BALL_X   64
#define PONG_PADDLE_BALL_Y   64

// Desired Size
#define PONG_BALL_RADIUS              12
#define PONG_PLAYER_PADDLE_HALFLENGTH 32
#define PONG_AI_PADDLE_HALFLENGTH     32
#define PONG_PADDLE_WIDTH             16

// Speed Data
#define PONG_BALL_SPEED   3.5f
#define PONG_PLAYER_SPEED 3.0f
#define PONG_AI_SPEED     1.5f

#define PONG_PADDLE_HIT_ANGLE_RANGE  120.0f
#define PONG_PADDLE_HIT_ANGLE_OFFSET ((180.0f - PONG_PADDLE_HIT_ANGLE_RANGE) / 2.0f)

#define PONG_AI_EASY_CHANCE   60
#define PONG_AI_MEDIUM_CHANCE 75
#define PONG_AI_HARD_CHANCE   95

// Sound Data
#define PONG_SOUND_BEGIN         0x8019
#define PONG_SOUND_PLAYER_PADDLE 0x8001
#define PONG_SOUND_AI_PADDLE     0x8002
#define PONG_SOUND_BOUNDS        0x8000
#define PONG_SOUND_WIN           0x8006
#define PONG_SOUND_LOSE          0x8012


class Pong : public MinigameBase
{
public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

	void OnFramePlayer(MinigameManagerData data);
	void OnFrameSimulate(MinigameManagerData data);

	void HandleCollision(MinigameManagerData data);

	void DrawPaddleBacking(MinigameManagerData data, float xPos);

private:
	float ballSpeedX = 2.0f;
	float ballSpeedY = 2.0f;

	float activePlayerSpeed = 3.0f;
	float activeAISpeed     = 1.5f;

	int activeAIChance = 60;

	float ballAngle     = 0.0f;
	float rotationDelta = 2.0f;

	SpriteNode* leftPaddle = nullptr;
	SpriteNode* rightPaddle = nullptr;
	SpriteNode* ball = nullptr;
};
