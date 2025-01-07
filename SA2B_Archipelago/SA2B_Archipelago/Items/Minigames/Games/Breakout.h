#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"


// Breakout Boundaries
#define BREAKOUT_TOP    100
#define BREAKOUT_BOTTOM 480
#define BREAKOUT_LEFT   100
#define BREAKOUT_RIGHT  540

// Sprite Data
#define BREAKOUT_PADDLE_SPRITE_X   64
#define BREAKOUT_PADDLE_SPRITE_Y   256
#define BREAKOUT_PADDLE_BALL_X     64
#define BREAKOUT_PADDLE_BALL_Y     64

#define BREAKOUT_BRICKS_PER_ROW    6
#define BREAKOUT_BRICK_ROWS_EASY   2
#define BREAKOUT_BRICK_ROWS_MEDIUM 4
#define BREAKOUT_BRICK_ROWS_HARD   6

// Desired Size
#define BREAKOUT_BALL_RADIUS              12
#define BREAKOUT_PLAYER_PADDLE_HALFLENGTH 32
#define BREAKOUT_PADDLE_THICKNESS         16

#define BREAKOUT_BRICK_WIDTH             ((BREAKOUT_RIGHT - BREAKOUT_LEFT) / BREAKOUT_BRICKS_PER_ROW)
#define BREAKOUT_BRICK_COLL_WIDTH        ((BREAKOUT_BRICK_WIDTH) - 4)
#define BREAKOUT_BRICK_THICKNESS         24
#define BREAKOUT_BRICK_COLL_THICKNESS    ((BREAKOUT_BRICK_THICKNESS) - 4)

// Speed Data
#define BREAKOUT_BALL_SPEED   3.5f
#define BREAKOUT_PLAYER_SPEED 5.0f

#define BREAKOUT_PADDLE_HIT_ANGLE_RANGE  120.0f
#define BREAKOUT_PADDLE_HIT_ANGLE_OFFSET ((180.0f - BREAKOUT_PADDLE_HIT_ANGLE_RANGE) / 2.0f)

// Sound Data
#define BREAKOUT_SOUND_BEGIN         0x8019
#define BREAKOUT_SOUND_PLAYER_PADDLE 0x8001
#define BREAKOUT_SOUND_BRICK         0x8002
#define BREAKOUT_SOUND_BOUNDS        0x8000
#define BREAKOUT_SOUND_WIN           0x8006
#define BREAKOUT_SOUND_LOSE          0x8012


struct BreakoutBrick
{
	SpriteNode* sprite;
	int health = 1;
};

class Breakout : public MinigameBase
{
public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

	void OnFramePlayer(MinigameManagerData data);
	void OnFrameSimulate(MinigameManagerData data);

	void HandleCollision(MinigameManagerData data);

private:
	float ballSpeedX = 2.0f;
	float ballSpeedY = 2.0f;

	float activePlayerSpeed = 3.0f;

	float ballAngle     = 0.0f;
	float rotationDelta = 2.0f;

	SpriteNode* playerPaddle = nullptr;
	SpriteNode* ball = nullptr;
	std::vector<BreakoutBrick> bricks;
};
