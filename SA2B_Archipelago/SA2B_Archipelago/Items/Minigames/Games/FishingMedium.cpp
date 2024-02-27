#include "../../../pch.h"
#include "Fishing.h"
#include "../Components/TextBox.h"
#include "../Components/RotateSpriteNode.h"

void FishingMedium::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_None;
	fs_state = FMS_Fishing;
	data.timers->push_back(&endTimer);
	data.timers->push_back(&timers[0]);
	data.timers->push_back(&timers[1]);
	successCount = 0;
	for (int i = 0; i < 3; i++)
	{
		zoneSizes[i] = 50.0f;
		ringSizes[i] = 200.0f;
	}
	float time = RandomFloat(0.5f, 3.0f);
	timers[0].Start(time);
	timers[0].Pause();
	time = RandomFloat(time + 0.5f, time + 3.0f);
	timers[1].Start(time);
	timers[1].Pause();
	ringCount = RandomInt(2, 4);
	std::shuffle(xPositions.begin(), xPositions.end(), RNG());
	std::shuffle(yPositions.begin(), yPositions.end(), RNG());
	CreateHierarchy(data);
}

void FishingMedium::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MGS_InProgress)
	{
		switch (fs_state)
		{
		case FishingMedium::FMS_Fishing:
		{
			if (timers[0].IsPaused())
			{
				timers[0].Resume();
				timers[1].Resume();
			}
			bool inputUsed = false;
			for (int i = successCount; i < ringCount; i++)
			{
				if (rings[i]->IsEnabled())
				{
					ringSizes[i] -= 1.0f;
					rings[i]->displaySize = { ringSizes[i], ringSizes[i], 0.0f };
					if (ringSizes[i] <= zoneSizes[i])
					{
						rings[i]->color = { 1.0f, 0.0f, 1.0f, 0.0f };
					}
					if (ringSizes[i] <= 0.0f)
					{
						fs_state = FMS_Escaped;
						endTimer.Start(2.0f);
						zones[i]->color = { 1.0f, 1.0f, 0.0f, 0.0f };
						return;
					}
					if (!inputUsed && (data.inputPress & anyDPad))
					{
						inputUsed = true;
						if (ringSizes[i] <= zoneSizes[i])
						{
							successCount++;
							rings[i]->color = { 1.0f, 0.0f, 1.0f, 0.0f };
							//Maybe disable ring and zone, put code here just in case
							//rings[i]->SetEnabled(false);
							//zones[i]->SetEnabled(false);
							if (successCount == ringCount)
							{
								fs_state = FMS_Caught;
								endTimer.Start(2.0f);
								return;
							}
						}
						else
						{
							fs_state = FMS_Escaped;
							endTimer.Start(2.0f);
							zones[i]->color = { 1.0f, 1.0f, 0.0f, 0.0f };
							return;
						}
					}
				}
				else if (i > 0 && timers[i - 1].IsElapsed())
				{
					rings[i]->SetEnabled(true);
					zones[i]->SetEnabled(true);
				}
			}
		
		break;
		}
		case FishingMedium::FMS_Caught:
			if (endTimer.IsElapsed())
			{
				currentState = MGS_Victory;
			}
			break;
		case FishingMedium::FMS_Escaped:
			if (endTimer.IsElapsed())
			{
				currentState = MGS_Loss;
			}
			break;
		}
	}
}

void FishingMedium::CreateHierarchy(MinigameManagerData data)
{
	SpriteNode* zoneParent = data.hierarchy->CreateNode("Zones");
	SpriteNode* ringParent = data.hierarchy->CreateNode("Rings");
	for (int i = 0; i < ringCount; i++)
	{
		float x = xPositions[i] + RandomFloat(-20.0f, 20.0f);
		float y = yPositions[i] + RandomFloat(-20.0f, 20.0f);
		zones[i] = data.hierarchy->CreateNode("Zone", data.icons->GetAnim(MGI_Circle), { zoneSizes[i], zoneSizes[i], 0.0f }, { x, y, 0.0f }, zoneParent);
		rings[i] = data.hierarchy->CreateNode("Ring", data.icons->GetAnim(MGI_Circle_Outline), { ringSizes[i], ringSizes[i], 0.0f }, { x, y, 0.0f }, ringParent);
		zones[i]->color = { 0.7f, 0.91f, 0.58f, 0.03f };
		rings[i]->color = { 1.0f, 0.0f, 0.0f, 1.0f };
		if (i > 0)
		{
			rings[i]->SetEnabled(false);
			zones[i]->SetEnabled(false);
		}
	}

	AddDPadToHierarchy(anyDPad, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);

	/*
	SpriteNode* textOne = data.hierarchy->CreateNode("Haha_One");
	textOne->SetPositionGlobal({ 320.0f, 290.0f, 0.0f });
	textOne->displaySize = { 300.0f,150.0f,0.0f };
	textOne->renderComponents.push_back(new TextBox("Shadow: That blue hedgehog again of all places... \nSonic: I've found you, faker! \nShadow: Faker? I think you're the fake hedgehog around here. You're comparing yourself to me? Ha! You're not even good enough to be my fake! \nSonic: I'll make you eat those words!", 12.0f, TextAlignment::Center, data.text));
	textOne->components.push_back(new RotateSpriteNode(0.0f, 0.1f));
	*/
}