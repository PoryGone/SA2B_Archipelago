#include "../../../pch.h"
#include "Fishing.h"

void Fishing::OnGameStart(MinigameManagerData data)
{
	switch (data.difficulty)
	{
	case MinigameDifficulty::MGD_Easy:
		easy.OnGameStart(data);
		break;
	case MinigameDifficulty::MGD_Medium:
		medium.OnGameStart(data);
		break;
	case MinigameDifficulty::MGD_Hard:
		hard.OnGameStart(data);
		break;
	}
}

void Fishing::OnFrame(MinigameManagerData data)
{
	switch (data.difficulty)
	{
	case MinigameDifficulty::MGD_Easy:
		easy.OnFrame(data);
		currentState = easy.currentState;
		break;
	case MinigameDifficulty::MGD_Medium:
		medium.OnFrame(data);
		currentState = medium.currentState;
		break;
	case MinigameDifficulty::MGD_Hard:
		hard.OnFrame(data);
		currentState = hard.currentState;
		break;
	}
}