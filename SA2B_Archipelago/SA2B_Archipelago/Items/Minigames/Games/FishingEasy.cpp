#include "../../../pch.h"
#include "Fishing.h"

void FishingEasy::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_None;
	fs_state = FES_None;
	data.timers->push_back(&timer);

	CreateHierarchy(data);
}

void FishingEasy::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MGS_InProgress)
	{
		switch (fs_state)
		{
		case FishingEasy::FES_None:
			timer.Start(RandomFloat(0.5f, 6.0f));
			fs_state = FES_WaitForFish;
			break;
		case FishingEasy::FES_WaitForFish:
			if (data.inputPress & anyDPad)
			{
				FishEscaped();
			}
			else if (timer.IsElapsed())
			{
				biteIndicator->color = { 1.0f, 0.0f, 0.0f, 1.0f };
				timer.Start(1.0f);
				fs_state = FES_FishOnLine;
			}
			break;
		case FishingEasy::FES_FishOnLine:
			if (data.inputPress & anyDPad)
			{
				biteIndicator->color = { 1.0f, 0.0f, 1.0f, 0.0f };
				timer.Start(2.0f);
				fs_state = FES_Caught;
			}
			else if (timer.IsElapsed())
			{
				FishEscaped();
			}
			break;
		case FishingEasy::FES_Caught:
			if (timer.IsElapsed())
			{
				currentState = MGS_Victory;
			}
			break;
		case FishingEasy::FES_Escaped:
			if (timer.IsElapsed())
			{
				currentState = MGS_Loss;
			}
			break;
		}
	}
}

void FishingEasy::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(anyDPad, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);

	biteIndicator = data.hierarchy->CreateNode("Indicator", data.icons->GetAnim(MGI_Circle), { 100, 100, 0.0f }, { data.icons->xCenter, data.icons->yCenter, 0.0f }, nullptr);
	biteIndicator->color = { 1.0f, 0.5f, 0.5f, 0.5f };
}

void FishingEasy::FishEscaped()
{
	biteIndicator->color = { 1.0f, 1.0f, 0.0f, 0.0f };
	timer.Start(2.0f);
	fs_state = FES_Escaped;
}