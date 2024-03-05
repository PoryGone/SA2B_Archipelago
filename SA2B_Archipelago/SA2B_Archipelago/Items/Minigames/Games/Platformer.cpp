#include "../../../pch.h"
#include "Platformer.h"

#include <cstdlib>

#include "../Backend/Time/Timer.h"
#include "../Components/Rotator.h"


void Platformer::OnGameStart(MinigameManagerData data)
{
	this->currentState = MinigameState::MGS_InProgress;

	this->CreateHierarchy(data);

	if (data.difficulty == MinigameDifficulty::MGD_Easy)
	{
		this->enemySpeedX = PLATFORMER_AI_EASY_SPEED;
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Medium)
	{
		this->enemySpeedX = PLATFORMER_AI_MEDIUM_SPEED;
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Hard)
	{
		this->enemySpeedX = PLATFORMER_AI_HARD_SPEED;
	}

	PlaySoundProbably(PLATFORMER_SOUND_BEGIN, 0, 0, 0);
}

void Platformer::OnFrame(MinigameManagerData data)
{
	this->OnFramePlayer(data);
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFrameSimulate(data);
	}
}

void Platformer::OnFramePlayer(MinigameManagerData data)
{
	if (data.inputPress & RawInputFlags::RIF_Up)
	{
		if (this->playerSpeedY == 0.0f)
		{
			this->playerSpeedY = -PLATFORMER_PLAYER_JUMP_SPEED;
		}
	}
}

void Platformer::OnFrameSimulate(MinigameManagerData data)
{
	// Player
	this->player->Translate({ 0, this->playerSpeedY, 0 });

	if (this->player->GetPositionGlobal().y <= PLATFORMER_PLAYER_START_Y - PLATFORMER_PLAYER_JUMP_HEIGHT)
	{
		this->player->SetPositionGlobal({ this->player->GetPositionGlobal().x, PLATFORMER_PLAYER_START_Y - PLATFORMER_PLAYER_JUMP_HEIGHT, 0 });
		this->playerSpeedY = -this->playerSpeedY;
	}
	else if (this->player->GetPositionGlobal().y >= PLATFORMER_PLAYER_START_Y)
	{
		this->playerSpeedY = 0.0f;
		this->player->SetPositionGlobal({ this->player->GetPositionGlobal().x, PLATFORMER_PLAYER_START_Y, 0 });
	}

	// AI
	this->enemy->Translate({ -this->enemySpeedX, 0, 0 });

	this->HandleCollision(data);
}

void Platformer::HandleCollision(MinigameManagerData data)
{
	// You Win (past the AI Paddle)
	//if ((this->ball->GetPositionGlobal().x + PONG_BALL_RADIUS) >= PONG_RIGHT)
	//{
	//	this->currentState = MinigameState::MGS_Victory;
	//
	//	PlaySoundProbably(PONG_SOUND_WIN, 0, 0, 0);
	//}

	// You Lose (past the Player Paddle)
	//if ((this->ball->GetPositionGlobal().x - PONG_BALL_RADIUS) <= PONG_LEFT)
	//{
	//	this->currentState = MinigameState::MGS_Loss;
	//
	//	PlaySoundProbably(PONG_SOUND_LOSE, 0, 0, 0);
	//}

	if (data.collision->IsColliding(this->player, this->enemy))
	{
		this->currentState = MinigameState::MGS_Loss;

		PlaySoundProbably(PLATFORMER_SOUND_LOSE, 0, 0, 0);
	}
}

void Platformer::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(RIF_Up, { PLATFORMER_LEFT + 45.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
	
	// Player
	this->player = data.hierarchy->CreateNode("Player",
											  data.icons->GetAnim(MGI_Spinball),
											  { PLATFORMER_PLAYER_WIDTH, PLATFORMER_PLAYER_HEIGHT, 1 },
											  { PLATFORMER_PLAYER_START_X, PLATFORMER_PLAYER_START_Y, 0 });
	
	// Enemy
	this->enemy = data.hierarchy->CreateNode("Enemy",
											 data.icons->GetAnim(MGI_Spinball),
											 { PLATFORMER_ENEMY_WIDTH, PLATFORMER_ENEMY_HEIGHT, 1 },
											 { PLATFORMER_ENEMY_START_X, PLATFORMER_ENEMY_LOW_Y, 0 });
	this->enemy->components.push_back(new Rotator(this->rotationDelta));

	data.collision->AddCollision(this->player, std::make_shared<PolygonCollider>(this->player->displaySize));
	data.collision->AddCollision(this->enemy, std::make_shared<CircleCollider>(this->enemy->displaySize.x));

	//data.collision->AddCollision(this->player, std::make_shared<PolygonCollider>(this->player->displaySize));
	//data.collision->AddCollision(this->enemy, std::make_shared<CircleCollider>(this->enemy->displaySize.x / 2.0f));
}
