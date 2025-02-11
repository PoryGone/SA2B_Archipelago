#include "../../../pch.h"
#include "Fishing.h"
#include "../Components/TextBox.h"

void FishingEasy::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_None;
	fs_state = FES_None;
	data.timers->push_back(&timer);

	CreateHierarchy(data);
	PlaySoundProbably((int)MinigameSounds::LevelStart, 0, 0, 0);
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
				biteIndicator->anim = data.icons->GetAnim(data.isLocationCheck ? MGI_Miss_Big_Banner : MGI_Miss_Banner);
				FishEscaped();
				PlayUnshuffledVoice(2, 1798);
			}
			else if (timer.IsElapsed())
			{
				biteIndicator->anim = data.icons->GetAnim(MGI_Bobber_Splash);
				//biteIndicator->color = { 1.0f, 0.0f, 0.0f, 1.0f };
				timer.Start(1.0f);
				fs_state = FES_FishOnLine;
				PlayUnshuffledVoice(2, 2687);
			}
			break;
		case FishingEasy::FES_FishOnLine:
			if (data.inputPress & anyDPad)
			{
				biteIndicator->anim = data.icons->GetAnim(data.isLocationCheck ? MGI_Caught_Big_Banner : MGI_Caught_Banner);
				//biteIndicator->color = { 1.0f, 0.0f, 1.0f, 0.0f };
				timer.Start(2.0f);
				fs_state = FES_Caught;
				PlayUnshuffledVoice(2, 104);
			}
			else if (timer.IsElapsed())
			{
				biteIndicator->anim = data.icons->GetAnim(data.isLocationCheck ? MGI_Miss_Big_Banner : MGI_Miss_Banner);
				FishEscaped();
				PlayUnshuffledVoice(2, 1798);
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

	biteIndicator = data.hierarchy->CreateNode("Indicator", data.icons->GetAnim(MGI_Bobber), { 200, 100, 0.0f }, { data.icons->xCenter, data.icons->yCenter, 0.0f }, nullptr);
	//biteIndicator->color = { 1.0f, 0.5f, 0.5f, 0.5f };
	
	/*
	SpriteNode* textOne = data.hierarchy->CreateNode("Haha_One");
	textOne->SetPositionGlobal({ 320.0f, 290.0f, 0.0f });
	textOne->renderComponents.push_back(new TextBox("1", 30.0f, TextAlignment::Left, data.text));
	*/
}

void FishingEasy::FishEscaped()
{
	//biteIndicator->color = { 1.0f, 1.0f, 0.0f, 0.0f };
	timer.Start(2.0f);
	fs_state = FES_Escaped;
}