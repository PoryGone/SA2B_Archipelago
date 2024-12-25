#include "../../../pch.h"
#include "InputSequence.h"

void InputSequence::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_InProgress;
	selectedIndex = 0;
	state = ISS_Start;
	data.timers->push_back(&timer);

	switch (data.difficulty)
	{
	case MGD_Easy:
		guessTime = 15.0f;
		break;
	case MGD_Medium:
		guessTime = 12.0f;
		break;
	case MGD_Hard:
		guessTime = 10.0f;
		break;
	}
	
	CreateHierarchy(data);
}

void InputSequence::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MGS_InProgress)
	{
		return;
	}
	switch (state)
	{
	case ISS_Start:
		timer.Start(guessTime);
		state = ISS_InGame;
		break;
	case ISS_InGame:
		//UpdateTimerFill();
		/*
		if (timer.IsElapsed())
		{
			SubmitSequence();
		}
		*/
		break;
	case ISS_Win:
		if (timer.IsElapsed())
		{
			currentState = MGS_Victory;
		}
		break;
	case ISS_Lose:
		if (timer.IsElapsed())
		{
			currentState = MGS_Loss;
		}
		break;
	}
	
}

void InputSequence::OnCleanup(MinigameManagerData data)
{

}

void InputSequence::UpdateTimerFill()
{
	float amount = timer.TimeRemaining() / guessTime;
	amount = amount < 0.0f ? 0.0f : amount;
	amount = amount > 1.0f ? 1.0f : amount;
	float width = timerBarBG->displaySize.x * amount;
	float bgX = -(timerBarBG->displaySize.x * 0.5f);
	NJS_POINT3 pos = { bgX + width * 0.5f, 0.0f };
	timerBar->displaySize.x = width;
	timerBar->SetPosition(pos);
}

void InputSequence::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(RIF_ANY_D_PAD, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);
	
	float xPos = 180.0f;
	timerBarBG = data.hierarchy->CreateNode("Timer_Background", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 106.0f });
	timerBarBG->color = { 1.0f, 1.0f, 0.0f, 0.0f };
	timerBar = data.hierarchy->CreateNode("Timer_Fill", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 106.0f }, timerBarBG);
	timerBar->color = { 1.0f, 0.0f, 0.0f, 1.0f };
	timerBarBG->SetEnabled(false); //Disabling timer for now
}	
