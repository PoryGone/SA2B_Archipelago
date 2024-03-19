#include "../../../pch.h"
#include "PokemonTrivia.h"

#include <cstdlib>
#include <vector>

#include "../Backend/Time/Timer.h"


// TODO: More questions
// TODO: Add Timer
// TODO: Show Correct/Incorrect on selection


std::vector<PokemonTriviaQuestion> easy_questions =
{
	PokemonTriviaQuestion("Which of these stages contains no Omochao?", {"Green Forest", "Green Hill", "Sky Rail"}, {"White Jungle", "Cosmic Wall", "Final Chase", "Final Rush", "Security Hall", "City Escape", "Meteor Herd", "Pyramid Cave", "Egg Quarters", "Death Chamber"}),
	PokemonTriviaQuestion("Which character says 'I found you, faker!'?", {"Sonic"}, {"Shadow", "Knuckles", "Tails", "Amy", "Eggman", "Rouge"}),
	PokemonTriviaQuestion("Who created Shadow?", {"Doctor Gerald Robotnik"}, {"Doctor Ivo Robotnik", "Sonic", "G.U.N.", "Chaos", "Maria Robotnik"}),
	PokemonTriviaQuestion("In which stage does Sonic gain the Ancient Light Upgrade?", {"Green Forest"}, {"Green Jungle", "White Jungle", "Final Rush", "Final Chase", "Pyramid Cave", "City Escape"}),
	//PokemonTriviaQuestion("", {"", ""}, {"", ""}),
};

std::vector<PokemonTriviaQuestion> medium_questions =
{
	PokemonTriviaQuestion("Into how many total pieces was the Master Emerald shattered?", {"12"}, {"18", "15", "30", "9", "27"}),
	PokemonTriviaQuestion("On which real-world city was City Escape based?", {"San Francisco"}, {"San Diego", "New York", "Boston", "Tokyo", "Osaka", "Seattle"}),
	PokemonTriviaQuestion("Which stage has exactly two Chao Containers?", {"Hidden Base"}, {"City Escape", "Green Hill", "Cannon's Core ", "Sky Rail"}),
	PokemonTriviaQuestion("Which stage in Hero Story is Route 101?", {"9th"}, {"1st", "7th", "8th", "10th", "11th", "15th"}),
	PokemonTriviaQuestion("Which stage in Dark Story is Sky Rail?", {"11th"}, {"7th", "8th", "9th", "10th", "12th", "3rd"}),
	//PokemonTriviaQuestion("", {"", ""}, {"", ""}),
};

std::vector<PokemonTriviaQuestion> hard_questions =
{
	PokemonTriviaQuestion("How many different colors of mono-tone Chao Eggs are there in this game?", {"13"}, {"10", "20", "15", "11", "17"}),
	PokemonTriviaQuestion("How many types of Animals exist in SA2?", {"21"}, {"20", "15", "22", "25"}),
	PokemonTriviaQuestion("In which stage does an Omochao say 'Be careful not to fall!'? ", {"White Jungle"}, {"Cosmic Wall", "Metal Harbor", "Radical Highway", "Final Rush"}),
	PokemonTriviaQuestion("Where was the Yellow Chaos Emerald located at the beginning of the game?", {"Tails had it"}, {"Eggman had it", "Security Hall", "Shadow stole it"}),
	//PokemonTriviaQuestion("", {"", ""}, {"", ""}),
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

	PokemonTriviaQuestion chosenQuestion;

	int questionIndex = 0;
	switch (questionDifficulty)
	{
	case MinigameDifficulty::MGD_Hard:
		questionIndex = RandomInt(0, hard_questions.size());
		chosenQuestion = hard_questions[questionIndex];
		break;
	case MinigameDifficulty::MGD_Medium:
		questionIndex = RandomInt(0, medium_questions.size());
		chosenQuestion = medium_questions[questionIndex];
		break;
	default:
		questionIndex = RandomInt(0, easy_questions.size());
		chosenQuestion = easy_questions[questionIndex];
		break;
	}

	std::string correctAnswer = chosenQuestion.correctAnswers[RandomInt(0, chosenQuestion.correctAnswers.size())];

	std::shuffle(chosenQuestion.wrongAnswers.begin(), chosenQuestion.wrongAnswers.end(), RNG());
	std::vector<std::string> wrongAnswers;
	wrongAnswers.push_back(chosenQuestion.wrongAnswers[0]);
	wrongAnswers.push_back(chosenQuestion.wrongAnswers[1]);
	wrongAnswers.push_back(chosenQuestion.wrongAnswers[2]);

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
	this->questionBox = new TextBox(chosenQuestion.question.c_str(), 28.0f, TextAlignment::Center, data.text);
	this->questionNode->renderComponents.push_back(this->questionBox);

	this->answer1Node = data.hierarchy->CreateNode("Answer 1");
	this->answer1Node->SetPositionGlobal({ 320.0f, 206.0f, 0.0f });
	this->answer1Node->displaySize = { 200.0f, 10.0f, 0.0f };
	this->answer1Box = new TextBox(displayedAnswers[0].c_str(), 24.0f, TextAlignment::Center, data.text);
	this->answer1Node->renderComponents.push_back(this->answer1Box);

	this->answer2Node = data.hierarchy->CreateNode("Answer 2");
	this->answer2Node->SetPositionGlobal({ 160.0f, 280.0f, 0.0f });
	this->answer2Node->displaySize = { 200.0f, 10.0f, 0.0f };
	this->answer2Box = new TextBox(displayedAnswers[1].c_str(), 24.0f, TextAlignment::Right, data.text);
	this->answer2Node->renderComponents.push_back(this->answer2Box);

	this->answer3Node = data.hierarchy->CreateNode("Answer 3");
	this->answer3Node->SetPositionGlobal({ 480.0f, 280.0f, 0.0f });
	this->answer3Node->displaySize = { 200.0f, 10.0f, 0.0f };
	this->answer3Box = new TextBox(displayedAnswers[2].c_str(), 24.0f, TextAlignment::Left, data.text);
	this->answer3Node->renderComponents.push_back(this->answer3Box);

	this->answer4Node = data.hierarchy->CreateNode("Answer 4");
	this->answer4Node->SetPositionGlobal({ 320.0f, 342.0f, 0.0f });
	this->answer4Node->displaySize = { 200.0f, 10.0f, 0.0f };
	this->answer4Box = new TextBox(displayedAnswers[3].c_str(), 24.0f, TextAlignment::Center, data.text);
	this->answer4Node->renderComponents.push_back(this->answer4Box);

	AddDPadToHierarchy(this->anyDPad, { 320.0f, 280.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
}
