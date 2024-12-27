#include "../../../pch.h"
#include "InputSequence.h"

void InputSequence::OnGameStart(MinigameManagerData data)
{
	this->currentState = MGS_InProgress;
	this->selectedIndex = 0;
	this->state = ISS_Start;
	data.timers->push_back(&this->timer);

	int numInputs = 3;

	switch (data.difficulty)
	{
	case MGD_Easy:
		this->guessTime = 8.0f;
		numInputs = 3;
		break;
	case MGD_Medium:
		this->guessTime = 7.0f;
		numInputs = 5;
		break;
	case MGD_Hard:
		this->guessTime = 5.0f;
		numInputs = 7;
		break;
	}

	for (int i = 0; i < numInputs; i++)
	{
		RawInputFlags flag = (RawInputFlags)(RIF_Up << RandomInt(0, 4));
		this->chosenInputs.push_back(flag);
	}
	
	this->CreateHierarchy(data);
}

void InputSequence::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MGS_InProgress)
	{
		return;
	}

	for (int i = 0; i < this->chosenInputs.size(); i++)
	{
		if (i <= this->selectedIndex)
		{
			this->dPads[i]->SetEnabled(true);
		}
		else
		{
			this->dPads[i]->SetEnabled(false);
		}
	}

	switch (this->state)
	{
	case ISS_Start:
		this->timer.Start(this->guessTime);
		this->state = ISS_InGame;
		break;
	case ISS_InGame:
		this->UpdateTimerFill();
		if (timer.IsElapsed())
		{
			this->state = ISS_Lose;
		}
		else
		{
			this->OnFramePlayer(data);
		}
		break;
	case ISS_Win:
		this->currentState = MGS_Victory;
		break;
	case ISS_Lose:
		this->currentState = MGS_Loss;
		break;
	}
}

void InputSequence::OnFramePlayer(MinigameManagerData data)
{
	RawInputFlags correctInput = this->chosenInputs[this->selectedIndex];
	RawInputFlags wrongInputs = (RawInputFlags::RIF_ANY_D_PAD & (~correctInput));

	if ((data.inputPress & wrongInputs) != 0)
	{
		this->state = InputSequenceState::ISS_Lose;

		return;
	}
	else if ((data.inputPress & correctInput) != 0)
	{
		this->selectedIndex++;

		if (this->selectedIndex >= this->chosenInputs.size())
		{
			this->state = InputSequenceState::ISS_Win;

			return;
		}
	}
}

void InputSequence::OnCleanup(MinigameManagerData data)
{
	this->selectedIndex = 0;
	this->dPads.clear();
	this->chosenInputs.clear();
}

void InputSequence::UpdateTimerFill()
{
	float amount = this->timer.TimeRemaining() / this->guessTime;
	amount = amount < 0.0f ? 0.0f : amount;
	amount = amount > 1.0f ? 1.0f : amount;
	float width = this->timerBarBG->displaySize.x * amount;
	float bgX = -(this->timerBarBG->displaySize.x * 0.5f);
	NJS_POINT3 pos = { bgX + width * 0.5f, 0.0f };
	this->timerBar->displaySize.x = width;
	this->timerBar->SetPosition(pos);
}

void InputSequence::CreateHierarchy(MinigameManagerData data)
{
	for (int i = 0; i < this->chosenInputs.size(); i++)
	{
		float x = (320.0f - (this->chosenInputs.size() - 1) * 32.0f) + (i * 64.0f);
		SpriteNode* dPad = AddDPadToHierarchy(this->chosenInputs[i], { x, 240.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
		dPad->SetEnabled(false);
		this->dPads.push_back(dPad);
	}
	
	float xPos = 180.0f;
	this->timerBarBG = data.hierarchy->CreateNode("Timer_Background", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 106.0f });
	this->timerBarBG->color = { 1.0f, 1.0f, 0.0f, 0.0f };
	this->timerBar = data.hierarchy->CreateNode("Timer_Fill", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 106.0f }, this->timerBarBG);
	this->timerBar->color = { 1.0f, 0.0f, 0.0f, 1.0f };
	this->timerBarBG->SetEnabled(true);
}	
