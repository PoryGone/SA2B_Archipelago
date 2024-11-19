#include "../../../pch.h"
#include "Trivia.h"

#include <cstdlib>
#include <vector>

#include "../Backend/Time/Timer.h"


// TODO: More questions
// TODO: Add Timer
// TODO: Show Correct/Incorrect on selection


std::vector<TriviaQuestion> easy_questions =
{
	TriviaQuestion("Which of these stages contains no Omochao?", {"Green Forest", "Green Hill", "Sky Rail"}, {"White Jungle", "Cosmic Wall", "Final Chase", "Final Rush", "Security Hall", "City Escape", "Meteor Herd", "Pyramid Cave", "Egg Quarters", "Death Chamber"}),
	TriviaQuestion("Which character says 'I found you, faker!'?", {"Sonic"}, {"Shadow", "Knuckles", "Tails", "Amy", "Eggman", "Rouge"}),
	TriviaQuestion("Who created Shadow?", {"Doctor Gerald Robotnik"}, {"Doctor Ivo Robotnik", "Sonic", "G.U.N.", "Chaos", "Maria Robotnik"}),
	TriviaQuestion("In which stage does Sonic gain the Ancient Light Upgrade?", {"Green Forest"}, {"Green Jungle", "White Jungle", "Final Rush", "Final Chase", "Pyramid Cave", "City Escape"}),
	TriviaQuestion("For what anniversary of Sonic the Hedgehog was Sonic Adventure 2 developed?", {"10th"}, {"15th", "5th", "20th", "25th", "30th"}),
	TriviaQuestion("What is the name of the main theme of this game?", {"Live & Learn"}, {"Open Your Heart", "Knight of the Wind", "Seven Rings in Hand", "Sonic Heroes", "It Doesn't Matter", "I am... All of Me", "His World", "A New Venture", "Endless Possibility", "Reach for the Stars"}),
	TriviaQuestion("How many (real) Chaos Emeralds are there (in this game)?", {"7"}, {"6", "8", "5", "16"}),
	TriviaQuestion("Which character is known to have met the President of the United States in person?", {"Sonic", "Tails"}, {"Knuckles", "Eggman", "Rouge", "Amy", "Shadow"}),
	//TriviaQuestion("", {"", ""}, {"", ""}),
};

std::vector<TriviaQuestion> medium_questions =
{
	TriviaQuestion("Into how many total pieces was the Master Emerald shattered?", {"12"}, {"18", "15", "30", "9", "27"}),
	TriviaQuestion("On which real-world city was City Escape based?", {"San Francisco"}, {"San Diego", "New York", "Boston", "Tokyo", "Osaka", "Seattle"}),
	TriviaQuestion("Which stage has exactly two Chao Containers?", {"Hidden Base"}, {"City Escape", "Green Hill", "Cannon's Core ", "Sky Rail"}),
	TriviaQuestion("Which stage in Hero Story is Route 101?", {"9th"}, {"1st", "7th", "8th", "10th", "11th", "15th"}),
	TriviaQuestion("Which stage in Dark Story is Sky Rail?", {"11th"}, {"7th", "8th", "9th", "10th", "12th", "3rd"}),
	TriviaQuestion("What was the prototype name for Rouge the Bat?", {"Nails the Bat"}, {"Rouge the Cat", "Boots the Bat", "Terios the Bat", "Wings the Bat"}),
	TriviaQuestion("Which character has no stage in the desert or pyramid areas?", {"Shadow"}, {"Sonic", "Rouge", "Tails", "Knuckles", "Eggman"}),
	TriviaQuestion("Which character cannot be the menu narrator?", {"Chaos", "Tikal"}, {"Sonic", "Shadow", "Tails", "Eggman", "Knuckles", "Rouge", "Maria", "Omochao", "President's Secretary", "Amy"}),
	TriviaQuestion("What is the name of Tails's mech in this game?", {"The Cyclone"}, {"The Tornado", "The Tornado 2", "The Hurricane", "The Tailsmobile", "The Tails Walker"}),
	//TriviaQuestion("", {"", ""}, {"", ""}),
};

std::vector<TriviaQuestion> hard_questions =
{
	TriviaQuestion("How many different colors of mono-tone Chao Eggs are there in this game?", {"13"}, {"10", "20", "15", "11", "17"}),
	TriviaQuestion("How many types of Animals exist in SA2?", {"21"}, {"20", "15", "22", "25"}),
	TriviaQuestion("In which stage does an Omochao say 'Be careful not to fall!'? ", {"White Jungle"}, {"Cosmic Wall", "Metal Harbor", "Radical Highway", "Final Rush"}),
	TriviaQuestion("Where was the Yellow Chaos Emerald located at the beginning of the game?", {"Tails had it"}, {"Eggman had it", "Security Hall", "Shadow stole it"}),
	TriviaQuestion("In which stage does Knuckles first encounter a ghost?", {"Pumpkin Hill"}, {"Wild Canyon", "Egg Quarters", "Death Chamber", "Aquatic Mine", "Meteor Herd"}),
	TriviaQuestion("Which of Shadow's stages was Sonic seen navigating in an early preview of the game?", {"Sky Rail"}, {"Radical Highway", "Final Chase", "White Jungle"}),
	TriviaQuestion("In which stage does Big the Cat appear more than once?", {"White Jungle", "Cannon's Core"}, {"Cosmic Wall", "Final Chase", "Final Rush", "Security Hall", "City Escape", "Meteor Herd", "Pyramid Cave", "Egg Quarters", "Death Chamber", "Metal Harbor", "Mission Street"}),
	TriviaQuestion("What language does Maria speak when launching Shadow to earth in the Japanese dub?", {"Spanish"}, {"English", "Japanese", "Italian", "Chinese", "German", "French"}),
	//TriviaQuestion("", {"", ""}, {"", ""}),
};


void Trivia::OnGameStart(MinigameManagerData data)
{
	this->currentState = MinigameState::MGS_InProgress;

	this->CreateHierarchy(data);

	PlaySoundProbably(TRIVIA_SOUND_BEGIN, 0, 0, 0);
}

void Trivia::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFramePlayer(data);
	}
}

void Trivia::OnFramePlayer(MinigameManagerData data)
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

void Trivia::CreateHierarchy(MinigameManagerData data)
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

	TriviaQuestion chosenQuestion;

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
