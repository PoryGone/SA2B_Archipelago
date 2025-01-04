#include "../../../pch.h"
#include "PokemonTrivia.h"

#include <cstdlib>
#include <vector>

#include "../Backend/Time/Timer.h"


// TODO: More questions
// TODO: Add Timer
// TODO: Show Correct/Incorrect on selection


enum PokemonQuestionType
{
	PQT_Name,
	PQT_Type,
	PQT_TypeMatchup,

	PQT_MinEasy = PQT_Name,
	PQT_MaxEasy = PQT_Name,
	PQT_MinMedium = PQT_Type,
	PQT_MaxMedium = PQT_Type,
	PQT_MinHard = PQT_TypeMatchup,
	PQT_MaxHard = PQT_TypeMatchup,
};

std::vector<PokemonTriviaQuestion> easy_questions =
{
	PokemonTriviaQuestion("Who is this Pokemon?"),
	PokemonTriviaQuestion("In which generation was this Pokemon introduced?"),
	//PokemonTriviaQuestion(""),
};

std::vector<PokemonTriviaQuestion> medium_questions =
{
	PokemonTriviaQuestion("What type is this Pokemon?"),
	//PokemonTriviaQuestion(""),
};

std::vector<PokemonTriviaQuestion> hard_questions =
{
	PokemonTriviaQuestion("Which of these attacks would be super-effective against this Pokemon?"),
	//PokemonTriviaQuestion(""),
};


void PokemonTrivia::OnGameStart(MinigameManagerData data)
{
	this->currentState = MinigameState::MGS_InProgress;

	this->CreateHierarchy(data);

	PlaySoundProbably(POKEMON_TRIVIA_SOUND_BEGIN, 0, 0, 0);
}

void PokemonTrivia::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFramePlayer(data);
	}
}

void PokemonTrivia::OnFramePlayer(MinigameManagerData data)
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

	if (chosenAnswer == this->correctAnswerSlot)
	{
		this->currentState = MinigameState::MGS_Victory;
	}
	else
	{
		this->currentState = MinigameState::MGS_Loss;
	}
}

void PokemonTrivia::CreateHierarchy(MinigameManagerData data)
{
	PokemonQuestionType questionType = PokemonQuestionType::PQT_Name;

	if (data.difficulty == MinigameDifficulty::MGD_Easy)
	{
		questionType = (PokemonQuestionType)RandomInt(PokemonQuestionType::PQT_MinEasy, PokemonQuestionType::PQT_MaxEasy + 1);
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Medium)
	{
		questionType = (PokemonQuestionType)RandomInt(PokemonQuestionType::PQT_MinMedium, PokemonQuestionType::PQT_MaxMedium + 1);
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Hard)
	{
		questionType = (PokemonQuestionType)RandomInt(PokemonQuestionType::PQT_MinHard, PokemonQuestionType::PQT_MaxHard + 1);
	}

	int chosenPokemonIndex = RandomInt(0, allPokemon.size());
	PokemonData chosenPokemon = allPokemon[chosenPokemonIndex];

	std::string chosenQuestion = "";
	std::string correctAnswer = "";
	std::vector<std::string> wrongAnswers;

	PrintDebug(chosenPokemon.name.c_str());
	PrintDebug(std::to_string(questionType).c_str());

	switch (questionType)
	{
	case PokemonQuestionType::PQT_Name:
	{
		chosenQuestion = "Who's that Pokemon?";

		correctAnswer = chosenPokemon.name;

		std::vector<int> wrongAnswersIndex;
		while (wrongAnswersIndex.size() < 3)
		{
			int wrongAnswerIndex = RandomInt(0, allPokemon.size());

			if (wrongAnswerIndex == chosenPokemonIndex ||
				std::find(std::begin(wrongAnswersIndex), std::end(wrongAnswersIndex), wrongAnswerIndex) != std::end(wrongAnswersIndex))
			{
				continue;
			}

			wrongAnswersIndex.push_back(wrongAnswerIndex);
			wrongAnswers.push_back(allPokemon[wrongAnswerIndex].name);
		}

		break;
	} // End Name
	case PokemonQuestionType::PQT_Type:
	{
		chosenQuestion = "What type is this Pokemon?";

		correctAnswer = typeNames[chosenPokemon.type1];

		if (chosenPokemon.type2 != PokemonType::No_Type)
		{
			correctAnswer += "/" + typeNames[chosenPokemon.type2];
		}

		std::vector<std::pair<PokemonType, PokemonType> > wrongAnswerTypes;
		while (wrongAnswers.size() < 3)
		{
			PokemonType wrongType1 = (PokemonType)RandomInt(1, (int)PokemonType::Fairy + 1);
			PokemonType wrongType2 = (PokemonType)RandomInt(1, (int)PokemonType::Fairy + 1);

			if (RandomInt(0, 12) >= 8)
			{
				wrongType2 = PokemonType::No_Type;
			}

			std::pair<PokemonType, PokemonType> wrongTypePair = std::make_pair(wrongType1, wrongType2);
			std::pair<PokemonType, PokemonType> wrongTypePairRev = std::make_pair(wrongType2, wrongType1);

			if ((wrongType1 == chosenPokemon.type1 && wrongType2 == chosenPokemon.type2) || (wrongType1 == chosenPokemon.type2 && wrongType2 == chosenPokemon.type1) ||
				std::find(std::begin(wrongAnswerTypes), std::end(wrongAnswerTypes), wrongTypePair) != std::end(wrongAnswerTypes) ||
				std::find(std::begin(wrongAnswerTypes), std::end(wrongAnswerTypes), wrongTypePairRev) != std::end(wrongAnswerTypes))
			{
				continue;
			}

			wrongAnswerTypes.push_back(wrongTypePair);

			std::string wrongAnswer = typeNames[wrongType1];

			if (wrongType2 != PokemonType::No_Type)
			{
				wrongAnswer += "/" + typeNames[wrongType2];
			}
			wrongAnswers.push_back(wrongAnswer);
		}

		break;
	} // End Type
	case PokemonQuestionType::PQT_TypeMatchup:
	{
		PokemonType attackType = (PokemonType)RandomInt(1, (int)PokemonType::Fairy + 1);

		chosenQuestion = "How effective would a " + typeNames[attackType] + "-type move be if used on this Pokemon?";

		PokemonTypeMatchup matchup1 = typeMatchupData[std::make_pair(attackType, chosenPokemon.type1)];
		PokemonTypeMatchup matchup2 = typeMatchupData[std::make_pair(attackType, chosenPokemon.type2)];

		int matchupCombo = (int)matchup1 * (int)matchup2;
		PokemonTypeMatchup finalMatchup = PokemonTypeMatchup::NeutralEffective;

		if (matchupCombo == 9 || matchupCombo == 6)
		{
			finalMatchup = PokemonTypeMatchup::SuperEffective;
		}
		else if (matchupCombo == 4 || matchupCombo == 3)
		{
			finalMatchup = PokemonTypeMatchup::NeutralEffective;
		}
		else if (matchupCombo == 2 || matchupCombo == 1)
		{
			finalMatchup = PokemonTypeMatchup::NotVeryEffective;
		}
		else if (matchupCombo == 0)
		{
			finalMatchup = PokemonTypeMatchup::NoEffect;
		}

		correctAnswer = typeEffectivenessNames[finalMatchup];

		std::vector<PokemonTypeMatchup> wrongMatchups;
		while (wrongMatchups.size() < 3)
		{
			PokemonTypeMatchup wrongMatchup = (PokemonTypeMatchup)RandomInt(0, (int)PokemonTypeMatchup::SuperEffective + 1);

			if (wrongMatchup == finalMatchup ||
				std::find(std::begin(wrongMatchups), std::end(wrongMatchups), wrongMatchup) != std::end(wrongMatchups))
			{
				continue;
			}

			wrongMatchups.push_back(wrongMatchup);
			wrongAnswers.push_back(typeEffectivenessNames[wrongMatchup]);
		}

		break;
	} // End Type Matchup
	}

	this->correctAnswerSlot = RandomInt(1, 5);

	std::vector<std::string> displayedAnswers;

	int wrongAnswersPlaced = 0;
	for (int i = 1; i < 5; i++)
	{
		if (i == this->correctAnswerSlot)
		{
			displayedAnswers.push_back(correctAnswer);
		}
		else
		{
			displayedAnswers.push_back(wrongAnswers[wrongAnswersPlaced]);
			wrongAnswersPlaced++;
		}
	}

	// Question
	this->questionNode = data.hierarchy->CreateNode("Question");
	this->questionNode->SetPositionGlobal({ 320.0f, 80.0f, 0.0f });
	this->questionNode->displaySize = { 400.0f, 10.0f, 0.0f };
	this->questionBox = new TextBox(chosenQuestion.c_str(), 28.0f, TextAlignment::Center, data.text);
	this->questionNode->renderComponents.push_back(this->questionBox);

	this->pokemonNode = data.hierarchy->CreateNode("Pokemon", data.icons->GetAnim(chosenPokemon.icon), { 48.0f, 48.0f, 0.0f }, { 320.0f, 190.0f, 0.0f });

	this->answer1Node = data.hierarchy->CreateNode("Answer 1");
	this->answer1Node->SetPositionGlobal({ 320.0f, 246.0f, 0.0f });
	this->answer1Node->displaySize = { 260.0f, 10.0f, 0.0f };
	this->answer1Box = new TextBox(displayedAnswers[0].c_str(), 24.0f, TextAlignment::Center, data.text);
	this->answer1Node->renderComponents.push_back(this->answer1Box);

	this->answer2Node = data.hierarchy->CreateNode("Answer 2");
	this->answer2Node->SetPositionGlobal({ 130.0f, 320.0f, 0.0f });
	this->answer2Node->displaySize = { 260.0f, 10.0f, 0.0f };
	this->answer2Box = new TextBox(displayedAnswers[1].c_str(), 24.0f, TextAlignment::Right, data.text);
	this->answer2Node->renderComponents.push_back(this->answer2Box);

	this->answer3Node = data.hierarchy->CreateNode("Answer 3");
	this->answer3Node->SetPositionGlobal({ 510.0f, 320.0f, 0.0f });
	this->answer3Node->displaySize = { 260.0f, 10.0f, 0.0f };
	this->answer3Box = new TextBox(displayedAnswers[2].c_str(), 24.0f, TextAlignment::Left, data.text);
	this->answer3Node->renderComponents.push_back(this->answer3Box);

	this->answer4Node = data.hierarchy->CreateNode("Answer 4");
	this->answer4Node->SetPositionGlobal({ 320.0f, 382.0f, 0.0f });
	this->answer4Node->displaySize = { 260.0f, 10.0f, 0.0f };
	this->answer4Box = new TextBox(displayedAnswers[3].c_str(), 24.0f, TextAlignment::Center, data.text);
	this->answer4Node->renderComponents.push_back(this->answer4Box);

	AddDPadToHierarchy(this->anyDPad, { 320.0f, 330.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
}
