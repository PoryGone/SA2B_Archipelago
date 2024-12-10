#include "../../../pch.h"
#include "MathQuiz.h"

#include <cstdlib>
#include <vector>

#include "../Backend/Time/Timer.h"


// TODO: More questions
// TODO: Add Timer
// TODO: Show Correct/Incorrect on selection


enum MathQuestionType
{
	MQT_Arithmetic,
	MQT_Hypotenuse,
	MQT_Quadratic,

	MQT_MinEasy = MQT_Arithmetic,
	MQT_MaxEasy = MQT_Arithmetic,
	MQT_MinMedium = MQT_Hypotenuse,
	MQT_MaxMedium = MQT_Hypotenuse,
	MQT_MinHard = MQT_Quadratic,
	MQT_MaxHard = MQT_Quadratic,
};

enum ArithmeticType
{
	AT_Addition,
	AT_Subtraction,
	AT_Multiplication,
	AT_Division,
	AT_ENDTYPES,
};


void MathQuiz::OnGameStart(MinigameManagerData data)
{
	this->currentState = MinigameState::MGS_InProgress;

	this->CreateHierarchy(data);

	PlaySoundProbably(MATH_QUIZ_SOUND_BEGIN, 0, 0, 0);
}

void MathQuiz::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFramePlayer(data);
	}
}

void MathQuiz::OnFramePlayer(MinigameManagerData data)
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

void MathQuiz::CreateHierarchy(MinigameManagerData data)
{
	MathQuestionType questionType = MathQuestionType::MQT_Arithmetic;

	if (data.difficulty == MinigameDifficulty::MGD_Easy)
	{
		questionType = (MathQuestionType)RandomInt(MathQuestionType::MQT_MinEasy, MathQuestionType::MQT_MaxEasy + 1);
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Medium)
	{
		questionType = (MathQuestionType)RandomInt(MathQuestionType::MQT_MinMedium, MathQuestionType::MQT_MaxMedium + 1);
	}
	else if (data.difficulty == MinigameDifficulty::MGD_Hard)
	{
		questionType = (MathQuestionType)RandomInt(MathQuestionType::MQT_MinHard, MathQuestionType::MQT_MaxHard + 1);
	}

	std::string chosenQuestion = "";
	std::string correctAnswer = "";
	std::vector<std::string> wrongAnswers;
	std::vector<int> wrongAnswersInt;

	switch (questionType)
	{
	case MathQuestionType::MQT_Arithmetic:
	{
		ArithmeticType subType = (ArithmeticType)RandomInt(0, ArithmeticType::AT_ENDTYPES);
		switch (subType)
		{
		case ArithmeticType::AT_Addition:
		{
			int maxInt = 50;

			int num_a = RandomInt(0, maxInt);
			int num_b = RandomInt(0, maxInt);

			int correctAnswerInt = num_a + num_b;

			chosenQuestion += std::to_string(num_a);
			chosenQuestion += " + ";
			chosenQuestion += std::to_string(num_b);

			correctAnswer = std::to_string(correctAnswerInt);

			int errorRange = 5;

			while (wrongAnswersInt.size() < 3)
			{
				int wrongAnswer = RandomInt(correctAnswerInt - errorRange, correctAnswerInt + errorRange + 1);

				if (wrongAnswer == correctAnswerInt ||
					std::find(std::begin(wrongAnswersInt), std::end(wrongAnswersInt), wrongAnswer) != std::end(wrongAnswersInt))
				{
					continue;
				}

				wrongAnswersInt.push_back(wrongAnswer);
			}
			break;
		} // End Addition
		case ArithmeticType::AT_Subtraction:
		{
			int maxInt = 50;

			int num_a = RandomInt(0, maxInt);
			int num_b = RandomInt(0, maxInt);

			int correctAnswerInt = num_a - num_b;

			chosenQuestion += std::to_string(num_a);
			chosenQuestion += " - ";
			chosenQuestion += std::to_string(num_b);

			correctAnswer = std::to_string(correctAnswerInt);

			int errorRange = 5;

			while (wrongAnswersInt.size() < 3)
			{
				int wrongAnswer = RandomInt(correctAnswerInt - errorRange, correctAnswerInt + errorRange + 1);

				if (wrongAnswer == correctAnswerInt ||
					std::find(std::begin(wrongAnswersInt), std::end(wrongAnswersInt), wrongAnswer) != std::end(wrongAnswersInt))
				{
					continue;
				}

				wrongAnswersInt.push_back(wrongAnswer);
			}
			break;
		} // End Subtraction
		case ArithmeticType::AT_Multiplication:
		{
			int maxInt = 13;

			int num_a = RandomInt(0, maxInt);
			int num_b = RandomInt(0, maxInt);

			int correctAnswerInt = num_a * num_b;

			chosenQuestion += std::to_string(num_a);
			chosenQuestion += " * ";
			chosenQuestion += std::to_string(num_b);

			correctAnswer = std::to_string(correctAnswerInt);

			int errorRange = 2;

			while (wrongAnswersInt.size() < 3)
			{
				int wrong_a = RandomInt(num_a - errorRange, num_a + errorRange + 1);
				int wrong_b = RandomInt(num_b - errorRange, num_b + errorRange + 1);
				int wrongAnswer = wrong_a * wrong_b;

				if (wrongAnswer == correctAnswerInt ||
					std::find(std::begin(wrongAnswersInt), std::end(wrongAnswersInt), wrongAnswer) != std::end(wrongAnswersInt))
				{
					continue;
				}

				wrongAnswersInt.push_back(wrongAnswer);
			}
			break;
		} // End Multiplication
		case ArithmeticType::AT_Division:
		{
			int maxInt = 13;

			int correctAnswerInt = RandomInt(0, maxInt);
			int num_b = RandomInt(0, maxInt);

			int num_a = correctAnswerInt * num_b;

			chosenQuestion += std::to_string(num_a);
			chosenQuestion += " / ";
			chosenQuestion += std::to_string(num_b);

			correctAnswer = std::to_string(correctAnswerInt);

			int errorRange = 5;

			while (wrongAnswersInt.size() < 3)
			{
				int wrongAnswer = RandomInt(correctAnswerInt - errorRange, correctAnswerInt + errorRange + 1);

				if (wrongAnswer == correctAnswerInt ||
					std::find(std::begin(wrongAnswersInt), std::end(wrongAnswersInt), wrongAnswer) != std::end(wrongAnswersInt))
				{
					continue;
				}

				wrongAnswersInt.push_back(wrongAnswer);
			}
			break;
		} // End Division
		}
	} // End Arithmetic
	}

	for (int answer : wrongAnswersInt)
	{
		wrongAnswers.push_back(std::to_string(answer));
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
