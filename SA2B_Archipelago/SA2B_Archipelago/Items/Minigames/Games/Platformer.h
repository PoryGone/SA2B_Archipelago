#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"


// Platformer Boundaries
#define PLATFORMER_TOP    100
#define PLATFORMER_BOTTOM 480
#define PLATFORMER_LEFT   20
#define PLATFORMER_RIGHT  620

// Position Data
#define PLATFORMER_PLAYER_START_X 100
#define PLATFORMER_PLAYER_START_Y 300

#define PLATFORMER_ENEMY_START_X 620
#define PLATFORMER_ENEMY_LOW_Y   300
#define PLATFORMER_ENEMY_HIGH_Y  150

// Desired Size
#define PLATFORMER_PLAYER_WIDTH  24.0f
#define PLATFORMER_PLAYER_HEIGHT 48.0f
#define PLATFORMER_ENEMY_WIDTH   24
#define PLATFORMER_ENEMY_HEIGHT  24

// Speed Data
#define PLATFORMER_PLAYER_JUMP_SPEED  4.0f
#define PLATFORMER_PLAYER_JUMP_HEIGHT 96

#define PLATFORMER_AI_EASY_SPEED   2.0f
#define PLATFORMER_AI_MEDIUM_SPEED 3.0f
#define PLATFORMER_AI_HARD_SPEED   4.0f

// Sound Data
#define PLATFORMER_SOUND_BEGIN         0x8019
#define PLATFORMER_SOUND_PLAYER_JUMP   0x8001
#define PLATFORMER_SOUND_PLAYER_HIT    0x8002
#define PLATFORMER_SOUND_BOUNDS        0x8000
#define PLATFORMER_SOUND_WIN           0x8006
#define PLATFORMER_SOUND_LOSE          0x8012


class Platformer : public MinigameBase
{
public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

	void OnFramePlayer(MinigameManagerData data);
	void OnFrameSimulate(MinigameManagerData data);

	void HandleCollision(MinigameManagerData data);

private:
	float playerSpeedY = 0.0f;

	float enemySpeedX = 1.5f;

	float ballAngle     = 0.0f;
	float rotationDelta = 2.0f;

	SpriteNode* player = nullptr;
	SpriteNode* enemy = nullptr;
};
