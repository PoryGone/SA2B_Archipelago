#include "../../../pch.h"
#include "Fishing.h"
#include "../Components/Flipbook.h"

void Fishing::OnGameStart(MinigameManagerData data)
{
	if (data.isLocationCheck)
	{
		SpriteNode* bigNode = data.hierarchy->CreateNode("Big", data.icons->GetAnim(MGI_Big_0), { 200.0f, 100.0f }, { data.icons->xCenter, 60.0f });
		bigNode->components.push_back(new Flipbook({ data.icons->GetAnim(MGI_Big_0), data.icons->GetAnim(MGI_Big_1) }, 60));
	}

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