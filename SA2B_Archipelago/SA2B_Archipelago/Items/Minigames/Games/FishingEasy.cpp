#include "../../../pch.h"
#include "Fishing.h"

void FishingEasy::OnGameStart(MinigameManagerData data)
{
	zoneSize = 50.0f;
	ringSize = 100.0f;

	CreateHierarchy(data);
}

void FishingEasy::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MGS_InProgress)
	{
		ringSize -= 1.0f;
		ring->displaySize = { ringSize, ringSize, 0.0f };
		if (ringSize <= zoneSize)
		{
			ring->color = { 1.0f, 0.0f, 1.0f, 0.0f };
		}
		if (ringSize <= 0.0f)
		{
			currentState = MGS_Loss;
			return;
		}
		if (data.inputPress & anyDPad)
		{
			currentState = ringSize <= zoneSize ? MGS_Victory : MGS_Loss;
		}
	}
}

void FishingEasy::CreateHierarchy(MinigameManagerData data)
{
	zone = data.hierarchy->CreateNode("Zone", data.icons->GetAnim(MGI_Circle), { zoneSize, zoneSize, 0.0f }, { 320.0f, 190.0f, 0.0f }, nullptr);
	ring = data.hierarchy->CreateNode("Ring", data.icons->GetAnim(MGI_Circle_Outline), { ringSize, ringSize, 0.0f }, { 320.0f, 190.0f, 0.0f }, nullptr);
	zone->color = { 0.5f, 0.0f, 0.0f, 0.0f };
	ring->color = { 1.0f, 0.0f, 0.0f, 1.0f };
}