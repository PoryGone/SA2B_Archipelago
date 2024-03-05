#include "../../../pch.h"
#include "Trivia.h"

#include <cstdlib>
#include <vector>

#include "../Backend/Time/Timer.h"


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
		this->OnFrameSimulate(data);
	}
}

void Trivia::OnFrameSimulate(MinigameManagerData data)
{

}

void Trivia::CreateHierarchy(MinigameManagerData data)
{
	std::string question_text = std::string("whomst?");
	std::string answer1_text = std::string("Person A");
	std::string answer2_text = std::string("Person B");
	std::string answer3_text = std::string("Person C");
	std::string answer4_text = std::string("Person D");

	// Question
	this->questionNode = data.hierarchy->CreateNode("Question");
	this->questionNode->SetPositionGlobal({ 320.0f, 80.0f, 0.0f });
	this->questionNode->displaySize = { 300.0f, 10.0f, 0.0f };
	this->questionBox = new TextBox(question_text.c_str(), 20.0f, TextAlignment::Center, data.text);
	this->questionNode->renderComponents.push_back(this->questionBox);

	this->answer1Node = data.hierarchy->CreateNode("Answer 1");
	this->answer1Node->SetPositionGlobal({ 320.0f, 180.0f, 0.0f });
	this->answer1Node->displaySize = { 300.0f, 10.0f, 0.0f };
	this->answer1Box = new TextBox(answer1_text.c_str(), 16.0f, TextAlignment::Center, data.text);
	this->answer1Node->renderComponents.push_back(this->questionBox);

	this->answer2Node = data.hierarchy->CreateNode("Answer 2");
	this->answer2Node->SetPositionGlobal({ 200.0f, 280.0f, 0.0f });
	this->answer2Node->displaySize = { 300.0f, 10.0f, 0.0f };
	this->answer2Box = new TextBox(answer2_text.c_str(), 16.0f, TextAlignment::Center, data.text);
	this->answer2Node->renderComponents.push_back(this->questionBox);

	this->answer3Node = data.hierarchy->CreateNode("Answer 3");
	this->answer3Node->SetPositionGlobal({ 440.0f, 280.0f, 0.0f });
	this->answer3Node->displaySize = { 300.0f, 10.0f, 0.0f };
	this->answer3Box = new TextBox(answer3_text.c_str(), 16.0f, TextAlignment::Center, data.text);
	this->answer3Node->renderComponents.push_back(this->questionBox);

	this->answer4Node = data.hierarchy->CreateNode("Answer 4");
	this->answer4Node->SetPositionGlobal({ 320.0f, 380.0f, 0.0f });
	this->answer4Node->displaySize = { 300.0f, 10.0f, 0.0f };
	this->answer4Box = new TextBox(answer4_text.c_str(), 16.0f, TextAlignment::Center, data.text);
	this->answer4Node->renderComponents.push_back(this->questionBox);

	AddDPadToHierarchy(this->anyDPad, { 320.0f, 280.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
}
