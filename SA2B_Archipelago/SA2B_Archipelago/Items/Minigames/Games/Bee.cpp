#include "../../../pch.h"
#include "Bee.h"

#include <cstdlib>
#include <map>

#include "../Backend/Time/Timer.h"


std::map<int, MinigameIcon> beeWeights = {
	{99, MGI_Bee_Taters},
	{198, MGI_Bee_Pory},
	{297, MGI_Bee_Ras},
	{298, MGI_Bee_Unknown},
	{299, MGI_Beetle_Gun},
	{300, MGI_Beetle},
};


void BeeTrap::OnGameStart(MinigameManagerData data)
{
	this->currentState = MinigameState::MGS_InProgress;

	this->timer.Start(20.0f);

	this->CreateHierarchy(data);
}

void BeeTrap::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MinigameState::MGS_InProgress)
	{
		this->OnFrameSimulate(data);
	}
}

void BeeTrap::OnFrameSimulate(MinigameManagerData data)
{
	bool allBeesPast = true;
	for (Bee& bee : this->bees)
	{
		if (bee.hasPassed)
		{
			bee.sprite->SetEnabled(false);
			continue;
		}
		allBeesPast = false;

		NJS_POINT3 moveDist = {sin(bee.targetAngle) * bee.speed, -cos(bee.targetAngle) * bee.speed, 0};
		Point3AddEQ(bee.position, moveDist);
		bee.sprite->SetPositionGlobal(bee.position);

		if (bee.position.x < data.icons->xMin - (bee.sprite->displaySize.x / 2) ||
			bee.position.x > data.icons->xMax + (bee.sprite->displaySize.x / 2) ||
			bee.position.y < data.icons->yMin - (bee.sprite->displaySize.y / 2) ||
			bee.position.y > data.icons->yMax + (bee.sprite->displaySize.y / 2))
		{
			if (bee.hasBeenOn)
			{
				bee.hasPassed = true;
				bee.sprite->SetEnabled(false);
			}
		}
		else
		{
			bee.hasBeenOn = true;
		}
	}

	if ((this->bees.size() > 0 && allBeesPast) || this->timer.IsElapsed())
	{
		currentState = MGS_Draw;
	}
}

void BeeTrap::OnCleanup(MinigameManagerData data)
{
	this->bees.clear();
}

void BeeTrap::CreateHierarchy(MinigameManagerData data)
{
	for (int b = 0; b < this->beeCount; b++)
	{
		int spawnSpot = RandomInt(0, 400);
		NJS_POINT3 spawnPos = { 0, 0, 0 };

		NJS_POINT3 targetPos = { data.icons->xCenter, data.icons->yCenter };
		targetPos.x += RandomFloat(-250.0f, 150.0f);
		targetPos.y += RandomFloat(-250.0f, 150.0f);

		if (spawnSpot < 100)
		{
			// Top
			spawnPos = { data.icons->xMin + (spawnSpot * (data.icons->xMax - data.icons->xMin) / 100),
							data.icons->yMin - (32 * RandomFloat(1.0f, 7.0f)),
							0 };
		}
		else if (spawnSpot < 200)
		{
			// Right
			spawnPos = { data.icons->xMax + (32 * RandomFloat(1.0f, 7.0f)),
							data.icons->yMin + ((spawnSpot % 100) * (data.icons->yMax - data.icons->yMin) / 100),
							0 };
		}
		else if (spawnSpot < 300)
		{
			// Bottom
			spawnPos = { data.icons->xMax - ((spawnSpot % 100) * (data.icons->xMax - data.icons->xMin) / 100),
							data.icons->yMax + (32 * RandomFloat(1.0f, 7.0f)),
							0 };
		}
		else
		{
			// Left
			spawnPos = { data.icons->xMin - (32 * RandomFloat(1.0f, 7.0f)),
							data.icons->yMin + ((spawnSpot % 100) * (data.icons->yMax - data.icons->yMin) / 100),
							0 };
		}

		int spawnTypeInt = RandomInt(0, 300);
		MinigameIcon spawnType = MGI_Barrel;
		for (std::pair<int, MinigameIcon> weight : beeWeights)
		{
			if (spawnTypeInt < weight.first)
			{
				spawnType = weight.second;
				break;
			}
		}

		SpriteNode* newBeeSprite = data.hierarchy->CreateNode("Spawn", data.icons->GetAnim(spawnType), { 32, 32 }, spawnPos);
		Bee newBee;
		newBee.position = spawnPos;
		newBee.sprite = newBeeSprite;
		newBee.speed = RandomFloat(1.0f, 2.0f);
		newBee.targetAngle = Point3SignedAngleRadians({ 0.0f, -1.0f }, Point3Substract(targetPos, newBee.position));
		this->bees.push_back(newBee);
	}
}
