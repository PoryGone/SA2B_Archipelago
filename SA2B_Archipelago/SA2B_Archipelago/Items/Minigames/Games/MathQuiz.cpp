#include "../../../pch.h"
#include "MathQuiz.h"

#include <cstdlib>
#include <vector>

#include "../Backend/Time/Timer.h"


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
	this->localState = MQS_Start;
	this->endingTimer = 120;
	data.timers->push_back(&this->timer);

	this->CreateHierarchy(data);

	PlayUnshuffledVoice(2, 562);
}

void MathQuiz::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MinigameState::MGS_InProgress)
	{
		return;
	}

	switch (this->localState)
	{
	case MQS_Start:
		this->timer.Start(this->guessTime);
		this->localState = MQS_InGame;
		break;
	case MQS_InGame:
		this->UpdateTimerFill();
		if (timer.IsElapsed())
		{
			PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
			this->localState = MQS_Lose;
		}
		else
		{
			this->OnFramePlayer(data);
		}
		break;
	case MQS_Win:
		if (this->resultNode->color.a < 1.0f)
		{
			this->resultNode->SetEnabled(true);
			this->resultNode->anim = data.icons->GetAnim(MGI_Green_Check);
			this->resultNode->color.a += 1.0f / 30.0f;
			this->resultNode->displaySize = Point3MoveTowards(this->resultNode->displaySize, { 128.0f, 128.0f }, 72.0f / 30.0f);
		}
		else
		{
			if (this->endingTimer == 120)
			{
				PlaySoundProbably((int)MinigameSounds::RankReveal, 0, 0, 0);
			}

			this->endingTimer--;

			if (this->endingTimer <= 0)
			{
				this->currentState = MinigameState::MGS_Victory;
			}
		}
		return;
	case MQS_Lose:
		if (this->resultNode->color.a < 1.0f)
		{
			this->resultNode->SetEnabled(true);
			this->resultNode->anim = data.icons->GetAnim(MGI_F_Rank);
			this->resultNode->color.a += 1.0f / 30.0f;
			this->resultNode->displaySize = Point3MoveTowards(this->resultNode->displaySize, { 128.0f, 128.0f }, 72.0f / 30.0f);
		}
		else
		{
			if (this->endingTimer == 120)
			{
				PlaySoundProbably((int)MinigameSounds::RankReveal, 0, 0, 0);
			}

			this->endingTimer--;

			if (this->endingTimer <= 0)
			{
				this->currentState = MinigameState::MGS_Loss;
			}
		}
		return;
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
		this->inputResults[chosenAnswer - 1]->anim = data.icons->GetAnim(MGI_Green_Circle);
		this->inputResults[chosenAnswer - 1]->SetEnabled(true);
		PlaySoundProbably((int)MinigameSounds::Checkpoint, 0, 0, 0);
		this->localState = MQS_Win;
	}
	else
	{
		this->inputResults[chosenAnswer - 1]->anim = data.icons->GetAnim(MGI_Red_X);
		this->inputResults[chosenAnswer - 1]->SetEnabled(true);
		PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
		this->localState = MQS_Lose;
	}
}

void MathQuiz::OnCleanup(MinigameManagerData data)
{
	this->inputResults.clear();
}

void MathQuiz::UpdateTimerFill()
{
	float amount = this->timer.TimeRemaining() / this->guessTime;
	amount = amount < 0.0f ? 0.0f : amount;
	amount = amount > 1.0f ? 1.0f : amount;
	float width = this->timerBarBG->displaySize.x * amount;
	float bgX = -(this->timerBarBG->displaySize.x * 0.5f);
	NJS_POINT3 pos = { bgX + width * 0.5f, 0.0f };
	this->timerBar->displaySize.x = width;
	this->timerBar->SetPosition(pos);

	NJS_POINT3 bombPos = this->timerBomb->GetPosition();
	bombPos.x = bgX + width;
	this->timerBomb->SetPosition(bombPos);
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
		break;
	} // End Arithmetic
	case MathQuestionType::MQT_Hypotenuse:
	{
		int maxInt = 5;

		int num_m = RandomInt(1, maxInt);
		int num_n = RandomInt(0, num_m);

		num_m = (num_m * 2) + 1;
		num_n = (num_n * 2) + 1;

		int num_a = num_m * num_n;
		int num_b = ((num_m * num_m) - (num_n * num_n)) / 2;

		int correctAnswerInt = ((num_m * num_m) + (num_n * num_n)) / 2;

		chosenQuestion += "Find the hypotenuse of a right triangle with legs\n";
		chosenQuestion += std::to_string(num_a);
		chosenQuestion += " and ";
		chosenQuestion += std::to_string(num_b);

		correctAnswer = std::to_string(correctAnswerInt);

		int errorRange = 10;

		while (wrongAnswersInt.size() < 3)
		{
			int wrongAnswer = RandomInt(max(num_a, num_b) + 1, correctAnswerInt + errorRange + 1);

			if (wrongAnswer == correctAnswerInt ||
				std::find(std::begin(wrongAnswersInt), std::end(wrongAnswersInt), wrongAnswer) != std::end(wrongAnswersInt))
			{
				continue;
			}

			wrongAnswersInt.push_back(wrongAnswer);
		}
		break;
	} // End Hypotenuse
	case MathQuestionType::MQT_Quadratic:
	{
		int maxInt = 14;

		int root_1 = RandomInt(1, maxInt);
		int root_2 = RandomInt(1, maxInt);

		if (RandomInt(0, 2) == 0)
		{
			root_1 *= -1;
		}

		if (RandomInt(0, 2) == 0)
		{
			root_2 *= -1;
		}

		int num_b = (-root_1) + (-root_2);
		int num_c = root_1 * root_2;

		chosenQuestion += "Find the real root(s) of the quadratic expression\nx^2";
		if (num_b > 0)
		{
			chosenQuestion += " + ";
			if (num_b != 1)
			{
				chosenQuestion += std::to_string(num_b);
			}
			chosenQuestion += "x";
		}
		else if (num_b < 0)
		{
			chosenQuestion += " - ";
			if (num_b != -1)
			{
				chosenQuestion += std::to_string(abs(num_b));
			}
			chosenQuestion += "x";
		}
		if (num_c > 0)
		{
			chosenQuestion += " + ";
		}
		else if (num_c < 0)
		{
			chosenQuestion += " - ";
		}
		chosenQuestion += std::to_string(abs(num_c));

		correctAnswer = std::to_string(root_1);
		if (root_1 != root_2)
		{
			correctAnswer += " and ";
			correctAnswer += std::to_string(root_2);
		}

		int errorRange = 5;

		while (wrongAnswers.size() < 3)
		{
			int wrong_root_1 = 0;
			int wrong_root_2 = 0;

			if (RandomFloat(0.0f, 1.0f) > 0.2f)
			{
				// 80% Chance to have a correct root
				if (RandomInt(0, 2) == 0)
				{
					wrong_root_1 = root_1;
				}
				else
				{
					wrong_root_1 = root_2;
				}
			}
			else
			{
				if (RandomInt(0, 2) == 0)
				{
					// 10% Chance to have a correct root, but negated
					if (RandomInt(0, 2) == 0)
					{
						wrong_root_1 = -root_1;
					}
					else
					{
						wrong_root_1 = -root_2;
					}
				}
			}

			if (wrong_root_1 == 0)
			{
				wrong_root_1 = RandomInt(root_1 - errorRange, root_1 + errorRange + 1);
				if (RandomInt(0, 2) == 0)
				{
					wrong_root_1 = -wrong_root_1;
				}
			}

			wrong_root_2 = RandomInt(root_2 - errorRange, root_2 + errorRange + 1);
			if (RandomInt(0, 2) == 0)
			{
				wrong_root_2 = -wrong_root_2;
			}

			std::string wrong_answer_1 = std::to_string(wrong_root_1);
			if (wrong_root_1 != wrong_root_2)
			{
				wrong_answer_1 += " and ";
				wrong_answer_1 += std::to_string(wrong_root_2);
			}
			std::string wrong_answer_2 = std::to_string(wrong_root_2);
			if (wrong_root_1 != wrong_root_2)
			{
				wrong_answer_2 += " and ";
				wrong_answer_2 += std::to_string(wrong_root_1);
			}

			if (wrong_answer_1 == correctAnswer ||
				wrong_answer_2 == correctAnswer ||
				std::find(std::begin(wrongAnswers), std::end(wrongAnswers), wrong_answer_1) != std::end(wrongAnswers) ||
				std::find(std::begin(wrongAnswers), std::end(wrongAnswers), wrong_answer_2) != std::end(wrongAnswers))
			{
				continue;
			}

			if (RandomInt(0, 2) == 0)
			{
				wrongAnswers.push_back(wrong_answer_1);
			}
			else
			{
				wrongAnswers.push_back(wrong_answer_2);
			}
		}
		break;
	} // End Quadratic
	}

	// Some question types have to write their answer strings directly
	if (wrongAnswersInt.size() > 0)
	{
		for (int answer : wrongAnswersInt)
		{
			wrongAnswers.push_back(std::to_string(answer));
		}
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

	// Timer
	this->timerBarBG = data.hierarchy->CreateNode("Timer_Background", data.icons->GetAnim(MGI_White_Box), { 160.0f, 13.0f }, { 320.0f, 73.0f });
	this->timerBarBG->color = { 1.0f, 0.0f, 0.0f, 0.0f };
	this->timerBar = data.hierarchy->CreateNode("Timer_Fill", data.icons->GetAnim(MGI_White_Box), { 200.0f, 13.0f }, { 320.0f, 73.0f }, this->timerBarBG);
	this->timerBar->color = { 1.0f, 0.0f, 0.0f, 0.84f };
	SpriteNode* timerBarFG = data.hierarchy->CreateNode("Timer_Foreground", data.icons->GetAnim(MGI_Fishing_Bar_Outline), { 16.0f, 200.0f }, { 320.0f, 74.0f });
	timerBarFG->SetRotation(-90.0f);
	SpriteNode* timeCapL = data.hierarchy->CreateNode("Timer_CapL", data.icons->GetAnim(MGI_Fishing_Bar_Cap), { 15.0f, 20.0f }, { 230.0f, 74.0f });
	timeCapL->SetRotation(-90.0f);
	SpriteNode* timeCapR = data.hierarchy->CreateNode("Timer_CapR", data.icons->GetAnim(MGI_Fishing_Bar_Cap), { 15.0f, 20.0f }, { 410.0f, 72.0f });
	timeCapR->SetRotation(90.0f);
	this->timerBarBG->SetEnabled(true);
	this->timerBomb = data.hierarchy->CreateNode("Timer_Sonic", data.icons->GetAnim(MGI_Sonic_Head), { 32.0f, 32.0f }, { 240.0f, 46.0f }, this->timerBarBG);
	this->timerBomb = data.hierarchy->CreateNode("Timer_Bomb", data.icons->GetAnim(MGI_Bomb), { 32.0f, 32.0f }, { 400.0f, 46.0f }, this->timerBarBG);
	Wiggle* bombWiggle = new Wiggle(RandomFloat(0.45f, 0.65f), -25.0f, 25.0f, true);
	timerBomb->components.push_back(bombWiggle);

	SpriteNode* result_1 = data.hierarchy->CreateNode("Input_Result_1", data.icons->GetAnim(MGI_Green_Circle), { 32.0f, 32.0f }, this->answer1Box->CalculateTextBounds(*this->answer1Node).center);
	SpriteNode* result_2 = data.hierarchy->CreateNode("Input_Result_2", data.icons->GetAnim(MGI_Green_Circle), { 32.0f, 32.0f }, this->answer2Box->CalculateTextBounds(*this->answer2Node).center);
	SpriteNode* result_3 = data.hierarchy->CreateNode("Input_Result_3", data.icons->GetAnim(MGI_Green_Circle), { 32.0f, 32.0f }, this->answer3Box->CalculateTextBounds(*this->answer3Node).center);
	SpriteNode* result_4 = data.hierarchy->CreateNode("Input_Result_4", data.icons->GetAnim(MGI_Green_Circle), { 32.0f, 32.0f }, this->answer4Box->CalculateTextBounds(*this->answer4Node).center);
	result_1->SetEnabled(false);
	result_2->SetEnabled(false);
	result_3->SetEnabled(false);
	result_4->SetEnabled(false);
	this->inputResults.push_back(result_1);
	this->inputResults.push_back(result_2);
	this->inputResults.push_back(result_3);
	this->inputResults.push_back(result_4);

	this->resultNode = data.hierarchy->CreateNode("Result", data.icons->GetAnim(MGI_Green_Check), { 200, 200 },
		{ data.icons->xCenter, data.icons->yCenter });
	this->resultNode->color.a = 0.0f;
	this->resultNode->SetEnabled(false);
}
