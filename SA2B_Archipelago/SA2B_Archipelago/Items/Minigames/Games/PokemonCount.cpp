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
		if (this->state == PokemonCountState::PCS_AnswerTime)
		{
			this->OnFramePlayer(data);
		}
		else if (this->state == PokemonCountState::PCS_Parade)
		{
			this->OnFrameSimulate(data);
		}
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

	// TODO: Change to results state here and use that to display answer result, then send victory/loss later
	if (chosenAnswer == this->correctAnswerSlot)
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
	bool anyNotPast = false;
	for (PokemonSpawn* pokemonSpawn : this->pokemonSpawns)
	{
		if (pokemonSpawn->pastEnd || pokemonSpawn->node->GetPositionGlobal().x > data.icons->xMaxSafe + 60.0f)
		{
			pokemonSpawn->pastEnd = true;
			continue;
		}

		anyNotPast = true;

		if (pokemonSpawn->node->GetPositionGlobal().x < data.icons->xMinSafe - 50.0f ||
			pokemonSpawn->node->GetPositionGlobal().x > data.icons->xMaxSafe + 50.0f)
		{
			pokemonSpawn->node->SetEnabled(false);
		}
		else
		{
			pokemonSpawn->node->SetEnabled(true);
		}

		pokemonSpawn->node->Translate({ pokemonSpawn->moveSpeed, 0.0f, 0.0f });
	}
	if (!anyNotPast)
	{
		// Time for the answers
		this->answerHolderNode->SetEnabled(true);
		this->state = PokemonCountState::PCS_AnswerTime;
	}
}

void PokemonCount::CreateHierarchy(MinigameManagerData data)
{
	this->pokemonSpawns.clear();
	this->questionOptions.clear();
	this->state = PokemonCountState::PCS_Parade;

	float x = -60.0f;
	float y = 80.0f;

	this->correctAnswer = 0;
	int correctPokemon = RandomInt(0, 32);
	int totalToSpawn = 0;

	int maxCorrect = 0;

	if (data.difficulty == MinigameDifficulty::MGD_Easy)
	{
		maxCorrect = 8;
		totalToSpawn = RandomInt(10, 20);
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Medium)
	{
		maxCorrect = 12;
		totalToSpawn = RandomInt(20, 35);
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Hard)
	{
		maxCorrect = 20;
		totalToSpawn = RandomInt(30, 50);
	}

	this->correctAnswer = RandomInt(1, maxCorrect + 1);
	this->questionOptions.push_back(this->correctAnswer);

	while (this->questionOptions.size() < 4)
	{
		int wrongOption = RandomInt(1, maxCorrect + 1);

		if (std::find(std::begin(this->questionOptions), std::end(this->questionOptions), wrongOption) == std::end(this->questionOptions))
		{
			this->questionOptions.push_back(wrongOption);
		}
	}

	this->correctAnswerSlot = RandomInt(1, 5);

	std::vector<std::string> displayedAnswers;

	int wrongAnswersPlaced = 0;
	for (int i = 1; i < 5; i++)
	{
		if (i == this->correctAnswerSlot)
		{
			displayedAnswers.push_back(std::to_string(this->correctAnswer));
		}
		else
		{
			displayedAnswers.push_back(std::to_string(questionOptions[wrongAnswersPlaced + 1]));
			wrongAnswersPlaced++;
		}
	}

	std::vector<PokemonData> pokemonToSpawn;

	for (int x = 0; x < this->correctAnswer; x++)
	{
		pokemonToSpawn.push_back(allPokemon[correctPokemon]);
	}

	while (pokemonToSpawn.size() < totalToSpawn)
	{
		int wrongPokemon = RandomInt(0, 32);

		if (wrongPokemon != correctPokemon)
		{
			pokemonToSpawn.push_back(allPokemon[wrongPokemon]);
		}
	}

	std::shuffle(pokemonToSpawn.begin(), pokemonToSpawn.end(), RNG());

	for (PokemonData pokemonData : pokemonToSpawn)
	{
		y = RandomInt(data.icons->yMinSafe + 30.0f, data.icons->yMaxSafe - 30.0f);

		PokemonSpawn* pokemon = new PokemonSpawn(pokemonData);

		SpriteNode* newSpawnBase = data.hierarchy->CreateNode("SpawnBase");
		newSpawnBase->SetPositionGlobal({ x, y, 0.0f });
		Wiggle* pokeWiggle = new Wiggle(RandomFloat(0.45f, 0.95f), -25.0f, 25.0f, true);
		newSpawnBase->components.push_back(pokeWiggle);

		pokemon->node = newSpawnBase;
		pokemon->moveSpeed = RandomFloat(1.5f, 4.0f);

		SpriteNode* newSpawn = data.hierarchy->CreateNode("Spawn", newSpawnBase);
		newSpawn->anim = data.icons->GetAnim(pokemonData.icon);
		newSpawn->SetPosition({ 0.0f, -30.0f, 0.0f });
		newSpawn->displaySize = { 60.0f, 60.0f, 0.0f };
		this->pokemonSpawns.push_back(pokemon);

		x -= 41.0f;
	}

	this->answerHolderNode = AddDPadToHierarchy(this->anyDPad, { 320.0f, 280.0f, 0.0f }, 45.0f, * data.icons, * data.hierarchy);

	// Question
	std::string questionStr = "Count the ";
	questionStr.append(allPokemon[correctPokemon].name.c_str());

	this->questionNode = data.hierarchy->CreateNode("Question");
	this->questionNode->SetPositionGlobal({ 320.0f, 80.0f, 0.0f });
	this->questionNode->displaySize = { 400.0f, 10.0f, 0.0f };
	this->questionBox = new TextBox(questionStr.c_str(), 28.0f, TextAlignment::Center, data.text);
	this->questionNode->renderComponents.push_back(this->questionBox);

	this->answer1Node = data.hierarchy->CreateNode("Answer 1", this->answerHolderNode);
	this->answer1Node->SetPositionGlobal({ 320.0f, 206.0f, 0.0f });
	this->answer1Node->displaySize = { 200.0f, 10.0f, 0.0f };
	this->answer1Box = new TextBox(displayedAnswers[0].c_str(), 24.0f, TextAlignment::Center, data.text);
	this->answer1Node->renderComponents.push_back(this->answer1Box);

	this->answer2Node = data.hierarchy->CreateNode("Answer 2", this->answerHolderNode);
	this->answer2Node->SetPositionGlobal({ 160.0f, 280.0f, 0.0f });
	this->answer2Node->displaySize = { 200.0f, 10.0f, 0.0f };
	this->answer2Box = new TextBox(displayedAnswers[1].c_str(), 24.0f, TextAlignment::Right, data.text);
	this->answer2Node->renderComponents.push_back(this->answer2Box);

	this->answer3Node = data.hierarchy->CreateNode("Answer 3", this->answerHolderNode);
	this->answer3Node->SetPositionGlobal({ 480.0f, 280.0f, 0.0f });
	this->answer3Node->displaySize = { 200.0f, 10.0f, 0.0f };
	this->answer3Box = new TextBox(displayedAnswers[2].c_str(), 24.0f, TextAlignment::Left, data.text);
	this->answer3Node->renderComponents.push_back(this->answer3Box);

	this->answer4Node = data.hierarchy->CreateNode("Answer 4", this->answerHolderNode);
	this->answer4Node->SetPositionGlobal({ 320.0f, 342.0f, 0.0f });
	this->answer4Node->displaySize = { 200.0f, 10.0f, 0.0f };
	this->answer4Box = new TextBox(displayedAnswers[3].c_str(), 24.0f, TextAlignment::Center, data.text);
	this->answer4Node->renderComponents.push_back(this->answer4Box);

	this->answerHolderNode->SetEnabled(false);
}
