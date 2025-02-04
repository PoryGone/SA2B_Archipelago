#include "../../../pch.h"
#include "Fishing.h"
#include "../Components/TextBox.h"

void FishingHard::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_None;
	fs_state = FHS_Fishing;
	progress = 0.3f;
	fishDestination = 290.0f;
	data.timers->push_back(&fishTimer);
	data.timers->push_back(&endTimer);
	fishTimer.Start(0.0f);

	CreateHierarchy(data);
}

void FishingHard::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MGS_InProgress)
	{
		switch (fs_state)
		{
		case FHS_Fishing:
			zoneVelocity += gravity;
			if (data.input & anyDPad)
			{
				zoneVelocity += inputForce;
			}
			if (fishTimer.IsElapsed())
			{
				fishDestination = RandomFloat(130.0f, 450.0f);
				fishTimer.Start(RandomFloat(0.5f, 2.0f));
			}
			MoveFish();
			UpdateZone();
			UpdateProgress(data);
			break;
		case FHS_Caught:
			if (endTimer.IsElapsed())
			{
				currentState = MGS_Victory;
			}
			break;
		case FHS_Escaped:
			if (endTimer.IsElapsed())
			{
				currentState = MGS_Loss;
			}
			break;

		}
	}
}

void FishingHard::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(anyDPad, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);

	data.hierarchy->CreateNode("FishingBG", data.icons->GetAnim(MGI_Fishing_BG), { 24.0f, 324.0f, 0.0f }, { 320.0f, 290.0f, 0.0f }, nullptr);
	progressBar = data.hierarchy->CreateNode("ProgressBar", data.icons->GetAnim(MGI_Square), { 11.0f, 320.0f, 0.0f }, { 351.0f, 290.0f, 0.0f }, nullptr);
	data.hierarchy->CreateNode("ProgressBG", data.icons->GetAnim(MGI_Fishing_Bar_Outline), { 15.0f, 280.0f, 0.0f }, { 350.0f, 290.0f, 0.0f }, nullptr);
	SpriteNode* barBottom = data.hierarchy->CreateNode("ProgressBG_Bottom", data.icons->GetAnim(MGI_Fishing_Bar_Cap), { 15.0f, 20.0f, 0.0f }, { 350.0f, 440.0f, 0.0f }, nullptr);
	data.hierarchy->CreateNode("ProgressBG_Top", data.icons->GetAnim(MGI_Fishing_Bar_Cap), { 15.0f, 20.0f, 0.0f }, { 350.0f, 140.0f, 0.0f }, nullptr);
	catchZone = data.hierarchy->CreateNode("CatchZone", data.icons->GetAnim(MGI_Fishing_Catch_Bar), { 20.0f, 65.0f, 0.0f }, { 320.0f, 290.0f, 0.0f }, nullptr);
	fish = data.hierarchy->CreateNode("Fish", data.icons->GetAnim(MGI_Chopper), { 24.0f, 24.0f, 0.0f }, { 320.0f, 290.0f, 0.0f }, nullptr);

	progressBar->color = { 1.0f,0.0f,0.0f,0.84f };

	data.collision->AddCollision(catchZone, std::make_shared<PolygonCollider>(NJS_POINT3({ 20.0f, 65.0f, 0.0f })));
	data.collision->AddCollision(fish, std::make_shared<PolygonCollider>(NJS_POINT3({ 24.0f, 24.0f, 0.0f })));


	endIcon = data.hierarchy->CreateNode("Indicator", data.icons->GetAnim(MGI_Caught_Banner), { 200, 100, 0.0f }, { data.icons->xCenter, data.icons->yCenter, 0.0f }, nullptr);
	endIcon->SetEnabled(false);
	/*
	SpriteNode* textOne = data.hierarchy->CreateNode("Haha_One");
	textOne->SetPositionGlobal({ 320.0f, 290.0f, 0.0f });
	textOne->renderComponents.push_back(new TextBox("1", 30.0f, TextAlignment::Left, data.text));
	*/
}

void FishingHard::SetFillAmount(float amount)
{
	amount = amount < 0.0f ? 0.0f : amount;
	amount = amount > 1.0f ? 1.0f : amount;
	float height = 280.0f * amount;
	NJS_POINT3 pos = { 351.0f, 430.0f - height * 0.5f, 0.0f };
	progressBar->displaySize.y = height;
	progressBar->SetPositionGlobal(pos);
}

void FishingHard::MoveFish()
{
	NJS_POINT3 pos = fish->GetPosition();
	float dif = fishDestination - pos.y;
	dif = dif < -fishSpeed ? -fishSpeed : dif;
	dif = dif > fishSpeed ? fishSpeed : dif;
	pos.y += dif;
	fish->SetPosition(pos);
}

void FishingHard::UpdateZone()
{
	float min = 162.5f;
	float max = 417.5f;
	NJS_POINT3 pos = catchZone->GetPosition();
	pos.y += zoneVelocity;
	float dif = 0.0f;
	if (pos.y < min)
	{
		dif = min - pos.y;
		zoneVelocity = 0.0f;
	}
	if (pos.y > max)
	{
		dif = (max - pos.y) * 2.0f;
		zoneVelocity = -(zoneVelocity * 0.5f);
		if (zoneVelocity > -1.0f)
		{
			zoneVelocity = 0.0f;
		}
	}
	pos.y += dif;
	catchZone->SetPosition(pos);
}

void FishingHard::UpdateProgress(MinigameManagerData data)
{
	if (data.collision->IsColliding(fish, catchZone))
	{
		catchZone->color = { 1.0f, 1.0f, 1.0f, 1.0f };
		progress += progressChangeRate * progressIncreaseMultiplier;
		if (progress >= 1.0f)
		{
			Caught(data);
		}
	}
	else
	{
		catchZone->color = { 0.5f, 1.0f, 1.0f, 1.0f };
		progress -= progressChangeRate;
		if (progress <= 0.0f)
		{
			Escaped(data);
		}
	}
	SetFillAmount(progress);
}

void FishingHard::Caught(MinigameManagerData data)
{
	endIcon->anim = data.icons->GetAnim(data.isLocationCheck ? MGI_Caught_Big_Banner : MGI_Caught_Banner);
	endIcon->SetEnabled(true);
	fs_state = FHS_Caught;
	endTimer.Start(2.0f);
}

void FishingHard::Escaped(MinigameManagerData data)
{
	endIcon->anim = data.icons->GetAnim(data.isLocationCheck ? MGI_Miss_Big_Banner : MGI_Miss_Banner);
	endIcon->SetEnabled(true);
	fs_state = FHS_Escaped;
	endTimer.Start(2.0f);
	catchZone->color = { 1.0f,1.0f,0.0f,0.0f };
}