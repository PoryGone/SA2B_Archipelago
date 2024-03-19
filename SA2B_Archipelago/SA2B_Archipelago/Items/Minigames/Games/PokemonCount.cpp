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
		this->OnFrameSimulate(data);
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

void PokemonCount::OnFrameSimulate(MinigameManagerData data)
{
	for (SpriteNode* pokemonNode : this->pokemonSpawnNodes)
	{
		pokemonNode->Translate({ 1.5f, 0.0f, 0.0f });
	}
}

void PokemonCount::CreateHierarchy(MinigameManagerData data)
{
	// Question
	this->questionNode = data.hierarchy->CreateNode("Question");
	this->questionNode->SetPositionGlobal({ 320.0f, 80.0f, 0.0f });
	this->questionNode->displaySize = { 400.0f, 10.0f, 0.0f };
	this->questionBox = new TextBox("", 28.0f, TextAlignment::Center, data.text);
	this->questionNode->renderComponents.push_back(this->questionBox);

	AddDPadToHierarchy(this->anyDPad, { 320.0f, 280.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);

	this->pokemonSpawnNodes.clear();

	float x = -60.0f;
	float y = 80.0f;
	for (PokemonData pokemon : allPokemon)
	{
		SpriteNode* newSpawnBase = data.hierarchy->CreateNode("SpawnBase");
		newSpawnBase->SetPositionGlobal({ x, y, 0.0f });
		Wiggle* pokeWiggle = new Wiggle(RandomFloat(0.45f, 0.95f), -25.0f, 25.0f, true);
		newSpawnBase->components.push_back(pokeWiggle);

		SpriteNode* newSpawn = data.hierarchy->CreateNode("Spawn", newSpawnBase);
		newSpawn->anim = data.icons->GetAnim(pokemon.icon);
		newSpawn->SetPosition({ 0.0f, -30.0f, 0.0f });
		newSpawn->displaySize = { 60.0f, 60.0f, 0.0f };
		this->pokemonSpawnNodes.push_back(newSpawnBase);

		x -= 65.0f;
		y += 10.0f;
	}
}
