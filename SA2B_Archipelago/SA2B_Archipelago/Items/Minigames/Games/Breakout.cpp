#include "../../../pch.h"
#include "Breakout.h"

#include <cstdlib>

#include "../Backend/Time/Timer.h"
#include "../Components/Rotator.h"

std::vector<NJS_ARGB> brickColors = {
	{ 1.0f, 0.0f, 1.0f, 0.0f },
	{ 1.0f, 1.0f, 1.0f, 0.0f },
	{ 1.0f, 1.0f, 0.5f, 0.0f },
	{ 1.0f, 1.0f, 0.0f, 0.0f },
};

void Breakout::OnGameStart(MinigameManagerData data)
{
	this->currentState = MinigameState::MGS_InProgress;

	this->CreateHierarchy(data);

	this->activePlayerSpeed = BREAKOUT_PLAYER_SPEED;

	float startingAngle = 90.0f * (RandomInt(0, 2) + 1) + (RandomInt(0, 31) + 30);
	this->ballSpeedX = sin(NJM_DEG_RAD(startingAngle)) * BREAKOUT_BALL_SPEED;
	this->ballSpeedY = -cos(NJM_DEG_RAD(startingAngle)) * BREAKOUT_BALL_SPEED;

	PlaySoundProbably(BREAKOUT_SOUND_BEGIN, 0, 0, 0);
}

void Breakout::OnFrame(MinigameManagerData data)
{
	this->OnFramePlayer(data);
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFrameSimulate(data);
	}
}

void Breakout::OnCleanup(MinigameManagerData data)
{
	this->playerPaddle = nullptr;
	this->ball = nullptr;
	this->bricks.clear();
}

void Breakout::OnFramePlayer(MinigameManagerData data)
{
	if (data.input & RawInputFlags::RIF_Left)
	{
		this->playerPaddle->Translate({ -this->activePlayerSpeed, 0, 0 });
	}
	else if (data.input & RawInputFlags::RIF_Right)
	{
		this->playerPaddle->Translate({ this->activePlayerSpeed, 0, 0 });
	}

	//std::string debugstr = std::to_string(this->playerPaddle->GetPositionGlobal().x) + " | " + std::to_string(this->playerPaddle->GetPositionGlobal().y) + " | " + std::to_string(this->playerPaddle->GetPositionGlobal().z);
	//PrintDebug(debugstr.c_str());
}

void Breakout::OnFrameSimulate(MinigameManagerData data)
{
	// Ball
	this->ball->Translate({ this->ballSpeedX , this->ballSpeedY, 0 });

	this->HandleCollision(data);
}

void Breakout::HandleCollision(MinigameManagerData data)
{
	// Bounce from Player Paddle
	if ((this->ball->GetPositionGlobal().y + BREAKOUT_BALL_RADIUS) >= (BREAKOUT_BOTTOM - BREAKOUT_PADDLE_THICKNESS))
	{
		float maxDist = (BREAKOUT_BALL_RADIUS + BREAKOUT_PLAYER_PADDLE_HALFLENGTH);
		float currentDist = (this->ball->GetPositionGlobal().x - this->playerPaddle->GetPositionGlobal().x);

		if (abs(currentDist) <= maxDist)
		{
			NJS_POINT3 ballPos = ball->GetPositionGlobal();
			ballPos.y = BREAKOUT_BOTTOM - (BREAKOUT_PADDLE_THICKNESS + BREAKOUT_BALL_RADIUS + 1);
			ball->SetPositionGlobal(ballPos);

			float normalizedDist = currentDist / maxDist;
			float newAngle = ((normalizedDist + 1) * BREAKOUT_PADDLE_HIT_ANGLE_RANGE / 2.0f) + BREAKOUT_PADDLE_HIT_ANGLE_OFFSET - 90.0f;

			this->ballSpeedX = sin(NJM_DEG_RAD(newAngle)) * BREAKOUT_BALL_SPEED;
			this->ballSpeedY = -cos(NJM_DEG_RAD(newAngle)) * BREAKOUT_BALL_SPEED;

			PlaySoundProbably(BREAKOUT_SOUND_PLAYER_PADDLE, 0, 0, 0);
		}
	}

	// You Lose (past the Player Paddle)
	if ((this->ball->GetPositionGlobal().y + BREAKOUT_BALL_RADIUS) >= BREAKOUT_BOTTOM)
	{
		this->currentState = MinigameState::MGS_Loss;

		PlaySoundProbably(BREAKOUT_SOUND_LOSE, 0, 0, 0);
	}

	// Top Bounce
	if ((this->ball->GetPositionGlobal().y - BREAKOUT_BALL_RADIUS) <= BREAKOUT_TOP)
	{
		this->ballSpeedY = -this->ballSpeedY;

		PlaySoundProbably(BREAKOUT_SOUND_BOUNDS, 0, 0, 0);
	}

	// Left/Right Bounce
	if ((this->ball->GetPositionGlobal().x - BREAKOUT_BALL_RADIUS) <= BREAKOUT_LEFT || (this->ball->GetPositionGlobal().x + BREAKOUT_BALL_RADIUS) >= BREAKOUT_RIGHT)
	{
		this->ballSpeedX = -this->ballSpeedX;

		PlaySoundProbably(BREAKOUT_SOUND_BOUNDS, 0, 0, 0);
	}

	// Paddle Bounding
	NJS_POINT3 playerPaddlePos = this->playerPaddle->GetPositionGlobal();
	if ((playerPaddlePos.x - BREAKOUT_PLAYER_PADDLE_HALFLENGTH) < BREAKOUT_LEFT)
	{
		playerPaddlePos.x = BREAKOUT_LEFT + BREAKOUT_PLAYER_PADDLE_HALFLENGTH;
	}
	else if ((playerPaddlePos.x + BREAKOUT_PLAYER_PADDLE_HALFLENGTH) > BREAKOUT_RIGHT)
	{
		playerPaddlePos.x = BREAKOUT_RIGHT - BREAKOUT_PLAYER_PADDLE_HALFLENGTH;
	}
	this->playerPaddle->SetPositionGlobal(playerPaddlePos);

	// Bricks
	bool allBroken = true;

	for (int i = 0; i < this->bricks.size(); i++)
	{
		if (this->bricks[i].health == 0)
		{
			this->bricks[i].sprite->SetEnabled(false);
		}
		else
		{
			allBroken = false;

			if (data.collision->IsColliding(this->bricks[i].sprite, this->ball))
			{
				float xDist = abs(this->bricks[i].sprite->GetPositionGlobal().x - this->ball->GetPositionGlobal().x);
				float yDist = abs(this->bricks[i].sprite->GetPositionGlobal().y - this->ball->GetPositionGlobal().y);

				if (xDist <= (BREAKOUT_BRICK_COLL_WIDTH / 2.0f))
				{
					this->ballSpeedY = -this->ballSpeedY;
				}
				if (yDist <= (BREAKOUT_BRICK_COLL_THICKNESS / 2.0f))
				{
					this->ballSpeedX = -this->ballSpeedX;
				}

				this->bricks[i].health--;
				this->bricks[i].sprite->color = brickColors[this->bricks[i].health - 1];

				if (this->bricks[i].health == 0)
				{
					this->bricks[i].sprite->SetEnabled(false);
				}
			}
		}
	}

	if (allBroken)
	{
		this->currentState = MinigameState::MGS_Victory;

		PlaySoundProbably(BREAKOUT_SOUND_WIN, 0, 0, 0);
	}
}

void Breakout::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(RIF_Left | RIF_Right, { BREAKOUT_LEFT - 55.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);

	// Paddle
	SpriteNode* paddleBack = data.hierarchy->CreateNode("LeftPaddle_BG");
	float width = BREAKOUT_PLAYER_PADDLE_HALFLENGTH * 2;
	float midWidth = BREAKOUT_RIGHT - BREAKOUT_LEFT - (width * 2);
	float middle = BREAKOUT_LEFT + (BREAKOUT_RIGHT - BREAKOUT_LEFT) / 2.0f;

	// Player Paddle
	SpriteNode* top = data.hierarchy->CreateNode("LP_Top", data.icons->GetAnim(MGI_RoundedBarDark_Top), { width, BREAKOUT_PADDLE_THICKNESS, 1 }, { 0, 0, 0 }, paddleBack);
	SpriteNode* bottom = data.hierarchy->CreateNode("LP_Bottom", data.icons->GetAnim(MGI_RoundedBarDark_Bottom), { width, BREAKOUT_PADDLE_THICKNESS, 1 }, { 0, 0, 0 }, paddleBack);
	SpriteNode* mid = data.hierarchy->CreateNode("LP_Mid", data.icons->GetAnim(MGI_RoundedBarDark_Mid), { midWidth, BREAKOUT_PADDLE_THICKNESS, 1 }, { 0, 0, 0 }, paddleBack);
	this->playerPaddle = data.hierarchy->CreateNode("LP_Paddle", data.icons->GetAnim(MGI_RoundedBar), { BREAKOUT_PADDLE_THICKNESS, width, 1 }, { 0, 0, 0 });
	paddleBack->SetPositionGlobal({ middle, BREAKOUT_BOTTOM - (BREAKOUT_PADDLE_THICKNESS), 0 });
	top->SetPosition({ 0, (BREAKOUT_LEFT + BREAKOUT_PLAYER_PADDLE_HALFLENGTH) - middle, 0 });
	bottom->SetPosition({ 0, (BREAKOUT_RIGHT - BREAKOUT_PLAYER_PADDLE_HALFLENGTH) - middle, 0 });
	mid->SetPosition({ 0, 0, 0 });
	paddleBack->SetRotation(90.0f);
	top->SetRotation(90.0f);
	bottom->SetRotation(90.0f);
	mid->SetRotation(90.0f);
	this->playerPaddle->SetPosition({ middle, BREAKOUT_BOTTOM - (BREAKOUT_PADDLE_THICKNESS), 0 });
	this->playerPaddle->SetRotation(90.0f);

	// Ball
	float ballX = BREAKOUT_LEFT + (BREAKOUT_RIGHT - BREAKOUT_LEFT) / 2.0f;
	float ballY = BREAKOUT_TOP + (BREAKOUT_BOTTOM - BREAKOUT_TOP) / 2.0f;
	this->ball = data.hierarchy->CreateNode("Ball", data.icons->GetAnim(MGI_Spinball), { BREAKOUT_BALL_RADIUS * 2, BREAKOUT_BALL_RADIUS * 2, 1 }, { ballX, ballY, 0 });
	this->ball->components.push_back(new Rotator(rotationDelta));

	// Bricks
	int rowCount = BREAKOUT_BRICK_ROWS_EASY;
	if (data.difficulty == MinigameDifficulty::MGD_Medium)
	{
		rowCount = BREAKOUT_BRICK_ROWS_MEDIUM;
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Hard)
	{
		rowCount = BREAKOUT_BRICK_ROWS_HARD;
	}

	data.collision->AddCollision(this->ball, std::make_shared<CircleCollider>(BREAKOUT_BALL_RADIUS));

	for (int row = 0; row < rowCount; row++)
	{
		float brickY = BREAKOUT_TOP + (row * BREAKOUT_BRICK_THICKNESS) + (1.5f * BREAKOUT_BRICK_THICKNESS);

		for (int i = 0; i < BREAKOUT_BRICKS_PER_ROW; i++)
		{
			float brickX = BREAKOUT_LEFT + (i * BREAKOUT_BRICK_WIDTH) + (0.5f * BREAKOUT_BRICK_WIDTH);

			int brickHealth = min((rowCount - row) / 3 + 1, 4);
			BreakoutBrick newBrick;

			newBrick.health = brickHealth;
			newBrick.sprite = data.hierarchy->CreateNode("Brick", data.icons->GetAnim(MGI_Square), { BREAKOUT_BRICK_COLL_WIDTH, BREAKOUT_BRICK_COLL_THICKNESS, 1 }, { brickX, brickY, 0 });
			newBrick.sprite->color = brickColors[brickHealth - 1];
			data.collision->AddCollision(newBrick.sprite, std::make_shared<PolygonCollider>(NJS_POINT3({ BREAKOUT_BRICK_COLL_WIDTH, BREAKOUT_BRICK_COLL_THICKNESS, 0.0f })));

			this->bricks.push_back(newBrick);
		}
	}
}
