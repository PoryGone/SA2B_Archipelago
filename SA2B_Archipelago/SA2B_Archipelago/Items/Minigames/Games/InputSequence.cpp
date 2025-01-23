#include "../../../pch.h"
#include "InputSequence.h"

void InputSequence::OnGameStart(MinigameManagerData data)
{
	this->currentState = MGS_InProgress;
	this->selectedIndex = 0;
	this->localState = ISS_Start;
	this->endingTimer = 150;
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

	PlaySoundProbably((int)MinigameSounds::LevelStart, 0, 0, 0);
}

void InputSequence::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MGS_InProgress)
	{
		return;
	}

	for (int i = 0; i < this->chosenInputs.size(); i++)
	{
		if (i < this->selectedIndex)
		{
			this->dPads[i]->SetEnabled(true);
			this->inputResults[i]->anim = data.icons->GetAnim(MGI_Green_Circle);
			this->inputResults[i]->SetEnabled(true);
		}
		else if(i == this->selectedIndex)
		{
			this->dPads[i]->SetEnabled(true);
			if (this->localState == ISS_Lose)
			{
				this->inputResults[i]->anim = data.icons->GetAnim(MGI_Red_X);
				this->inputResults[i]->SetEnabled(true);
			}
			else if (this->localState == ISS_Win)
			{
				this->inputResults[i]->anim = data.icons->GetAnim(MGI_Green_Circle);
				this->inputResults[i]->SetEnabled(true);
			}
			else
			{
				this->inputResults[i]->SetEnabled(false);
			}
		}
		else
		{
			this->dPads[i]->SetEnabled(false);
			this->inputResults[i]->SetEnabled(false);
		}
	}

	switch (this->localState)
	{
	case ISS_Start:
		this->timer.Start(this->guessTime);
		this->localState = ISS_InGame;
		break;
	case ISS_InGame:
		this->UpdateTimerFill();
		if (timer.IsElapsed())
		{
			PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
			this->localState = ISS_Lose;
		}
		else
		{
			this->OnFramePlayer(data);
		}
		break;
	case ISS_Win:
		this->endingTimer--;

		if (this->endingTimer == 90)
		{
			PlaySoundProbably((int)MinigameSounds::RankReveal, 0, 0, 0);
			this->resultNode->anim = data.icons->GetAnim(MGI_Green_Check);
			this->resultNode->SetEnabled(true);
		}
		else if (this->endingTimer <= 0)
		{
			this->currentState = MinigameState::MGS_Victory;
		}
		return;
	case ISS_Lose:
		this->endingTimer--;

		if (this->endingTimer == 90)
		{
			PlaySoundProbably((int)MinigameSounds::RankReveal, 0, 0, 0);
			this->resultNode->anim = data.icons->GetAnim(MGI_F_Rank);
			this->resultNode->SetEnabled(true);
		}
		else if (this->endingTimer <= 0)
		{
			this->currentState = MinigameState::MGS_Loss;
		}
		return;
	}
}

void InputSequence::OnFramePlayer(MinigameManagerData data)
{
	RawInputFlags correctInput = this->chosenInputs[this->selectedIndex];
	RawInputFlags wrongInputs = (RawInputFlags::RIF_ANY_D_PAD & (~correctInput));

	if ((data.inputPress & wrongInputs) != 0)
	{
		PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
		this->localState = InputSequenceState::ISS_Lose;

		return;
	}
	else if ((data.inputPress & correctInput) != 0)
	{
		this->selectedIndex++;

		if (this->selectedIndex >= this->chosenInputs.size())
		{
			PlaySoundProbably((int)MinigameSounds::GoToChaoGarden, 0, 0, 0);
			this->localState = InputSequenceState::ISS_Win;

			return;
		}
		else
		{
			PlaySoundProbably((int)MinigameSounds::Checkpoint, 0, 0, 0);
		}
	}
}

void InputSequence::OnCleanup(MinigameManagerData data)
{
	this->selectedIndex = 0;
	this->dPads.clear();
	this->inputResults.clear();
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

	NJS_POINT3 bombPos = this->timerBomb->GetPosition();
	bombPos.x = bgX + width;
	this->timerBomb->SetPosition(bombPos);
}

void InputSequence::CreateHierarchy(MinigameManagerData data)
{
	for (int i = 0; i < this->chosenInputs.size(); i++)
	{
		float x = (320.0f - (this->chosenInputs.size() - 1) * 32.0f) + (i * 64.0f);
		SpriteNode* dPad = AddDPadToHierarchy(this->chosenInputs[i], { x, 240.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
		SpriteNode* result = data.hierarchy->CreateNode("Input_Result", data.icons->GetAnim(MGI_Green_Circle), { 45.0f, 45.0f }, { x, 240.0f, 0.0f });
		dPad->SetEnabled(false);
		this->dPads.push_back(dPad);
		result->SetEnabled(false);
		this->inputResults.push_back(result);
	}
	
	float xPos = 180.0f;
	this->timerBarBG = data.hierarchy->CreateNode("Timer_Background", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 106.0f });
	this->timerBarBG->color = { 1.0f, 0.0f, 0.0f, 0.0f };
	this->timerBar = data.hierarchy->CreateNode("Timer_Fill", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 106.0f }, this->timerBarBG);
	this->timerBar->color = { 1.0f, 0.0f, 1.0f, 0.0f };
	this->timerBarBG->SetEnabled(true);
	this->timerBomb = data.hierarchy->CreateNode("Timer_Sonic", data.icons->GetAnim(MGI_Sonic_Head), { 32.0f, 32.0f }, { 220.0f, 80.0f }, this->timerBarBG);
	this->timerBomb = data.hierarchy->CreateNode("Timer_Bomb", data.icons->GetAnim(MGI_Bomb), { 32.0f, 32.0f }, { 420.0f, 80.0f }, this->timerBarBG);

	this->resultNode = data.hierarchy->CreateNode("Result", data.icons->GetAnim(MGI_Green_Check), { 128, 128 },
													{ data.icons->xCenter, data.icons->yCenter });
	this->resultNode->SetEnabled(false);
}	
