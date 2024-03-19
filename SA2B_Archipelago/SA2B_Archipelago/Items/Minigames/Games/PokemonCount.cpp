#include "../../../pch.h"
#include "PokemonCount.h"

#include <cstdlib>
#include <vector>

#include "../Backend/Time/Timer.h"


// TODO: More questions
// TODO: Add Timer
// TODO: Show Correct/Incorrect on selection


void PokemonCount::OnGameStart(MinigameManagerData data)
{
	this->currentState = MinigameState::MGS_InProgress;

	this->CreateHierarchy(data);

	PlaySoundProbably(POKEMON_COUNT_SOUND_BEGIN, 0, 0, 0);
}

void PokemonCount::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFramePlayer(data);
	}
}

void PokemonCount::OnFramePlayer(MinigameManagerData data)
{
	int chosenAnswer = 0;
	if (data.inputPress & RawInputFlags::RIF_Up)
	{
		chosenAnswer = 1;
	}
	else if (data.inputPress & RawInputFlags::RIF_Left)
	{
		chosenAnswer = 2;
	}
	else if (data.inputPress & RawInputFlags::RIF_Right)
	{
		chosenAnswer = 3;
	}
	else if (data.inputPress & RawInputFlags::RIF_Down)
	{
		chosenAnswer = 4;
	}

	if (chosenAnswer == 0)
	{
		return;
	}

	if (chosenAnswer == this->correctAnswer)
	{
		this->currentState = MinigameState::MGS_Victory;
	}
	else
	{
		this->currentState = MinigameState::MGS_Loss;
	}
}

void PokemonCount::CreateHierarchy(MinigameManagerData data)
{
	MinigameDifficulty questionDifficulty = MinigameDifficulty::MGD_Easy;

	if (data.difficulty == MinigameDifficulty::MGD_Medium)
	{
		if (RandomFloat(0.0f, 1.0f) > 0.3f)
		{
			questionDifficulty = MinigameDifficulty::MGD_Medium;
		}
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Hard)
	{
		if (RandomFloat(0.0f, 1.0f) > 0.5f)
		{
			questionDifficulty = MinigameDifficulty::MGD_Hard;
		}
		else if(RandomFloat(0.0f, 1.0f) > 0.2f)
		{
			questionDifficulty = MinigameDifficulty::MGD_Medium;
		}
	}

	// Question
	this->questionNode = data.hierarchy->CreateNode("Question");
	this->questionNode->SetPositionGlobal({ 320.0f, 80.0f, 0.0f });
	this->questionNode->displaySize = { 400.0f, 10.0f, 0.0f };
	this->questionBox = new TextBox("", 28.0f, TextAlignment::Center, data.text);
	this->questionNode->renderComponents.push_back(this->questionBox);

	AddDPadToHierarchy(this->anyDPad, { 320.0f, 280.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
}
