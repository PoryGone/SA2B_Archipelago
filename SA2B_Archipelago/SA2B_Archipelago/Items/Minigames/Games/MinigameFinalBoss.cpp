#include "../../../pch.h"
#include "MinigameFinalBoss.h"
#include <math.h>

void MinigameFinalBoss::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_InProgress;
	state = FBS_Intro;
	introState = FBIS_FadeIn;
	sonicIsActive = true;
	bossHealth = 100.0f;
	CreateHierarchy(data);
}

void MinigameFinalBoss::OnFrame(MinigameManagerData data)
{
	if (data.managerState == MGS_InProgress)
	{
		switch (state)
		{
		case FBS_Intro:
			RunIntro(data);
			break;
		case FBS_InGame:
			RunInGame(data);
			break;
		case FBS_Swap:
			RunSwap(data);
			break;
		case FBS_Win:

			break;
		case FBS_Loss:

			break;
		}
	}
	if (data.inputPress & RIF_Y)
	{
		currentState = MGS_Draw;
	}
}

void MinigameFinalBoss::RunIntro(MinigameManagerData data)
{
	if (data.inputPress & RIF_B)
	{
		sonic->SetPosition({ 0.0f, 0.0f });
		shadow->SetPosition({ 0.0f, 0.0f });
		shadow->SetEnabled(false);
		FHParent->SetPositionGlobal({ 320.0f, 0.0f });
		state = FBS_InGame;
	}
	switch (introState)
	{
	case FBIS_FadeIn:
		if (background->color.a < 1.0f)
		{
			background->color.a = min(background->color.a + 0.05f, 1.0f);
		}
		else
		{
			introState = FBIS_CharacterEntrance;
		}
		break;
	case FBIS_CharacterEntrance:
		sonic->SetPositionGlobal(Point3MoveTowards(sonic->GetPositionGlobal(), { 230.0f , 420.0f }, characterSpeed));
		shadow->SetPositionGlobal(Point3MoveTowards(shadow->GetPositionGlobal(), { 410.0f , 420.0f }, characterSpeed));
		if (Point3Approximatly(sonic->GetPositionGlobal(), { 230.0f , 420.0f }) && Point3Approximatly(shadow->GetPositionGlobal(), { 410.0f , 420.0f }))
		{
			introState = FBIS_BossEntrance;
		}
		break;
	case FBIS_BossEntrance:
		if (FHParent->GetPositionGlobal().y < 0.0f)
		{
			FHParent->Translate({ 0.0f, 0.25f, 0.0f, });
		}
		else
		{
			introState = FBIS_CharacterToStart;
		}
		break;
	case FBIS_CharacterToStart:
		sonic->SetPosition(Point3MoveTowards(sonic->GetPosition(), { 0.0f , 0.0f }, characterSpeed * 2.0f));
		shadow->SetPositionGlobal(Point3MoveTowards(shadow->GetPositionGlobal(), shadowOffScreenPos, characterSpeed * 2.0f));
		if (Point3Approximatly(sonic->GetPosition(), { 0.0f , 0.0f }) && Point3Approximatly(shadow->GetPositionGlobal(), shadowOffScreenPos))
		{
			sonic->SetPosition({ 0.0f, 0.0f });
			shadow->SetEnabled(false);
			state = FBS_InGame;
		}
		break;
	}
}

void MinigameFinalBoss::RunInGame(MinigameManagerData data)
{
	UpdateCharacterPosition(data);
	if (data.inputPress & RIF_B)
	{
		if (sonicIsActive)
		{
			shadow->SetPositionGlobal(shadowOffScreenPos);
		}
		else
		{
			sonic->SetPositionGlobal(sonicOffScreenPos);
		}
		sonicIsActive = !sonicIsActive;
		state = FBS_Swap;
	}
}

void MinigameFinalBoss::RunSwap(MinigameManagerData data)
{
	sonic->SetEnabled(true);
	shadow->SetEnabled(true);
	NJS_POINT3 sonicToPos = sonicIsActive ? characterParent->GetPositionGlobal() : sonicOffScreenPos;
	NJS_POINT3 shadowToPos = sonicIsActive ? shadowOffScreenPos : characterParent->GetPositionGlobal();
	sonic->SetPositionGlobal(Point3MoveTowards(sonic->GetPositionGlobal(), sonicToPos, characterSpeed * 2.0f));
	shadow->SetPositionGlobal(Point3MoveTowards(shadow->GetPositionGlobal(), shadowToPos, characterSpeed * 2.0f));
	if (Point3Approximatly(sonic->GetPositionGlobal(), sonicToPos) && Point3Approximatly(shadow->GetPositionGlobal(), shadowToPos))
	{
		sonic->SetEnabled(sonicIsActive);
		shadow->SetEnabled(!sonicIsActive);
		state = FBS_InGame;
	}
}

void MinigameFinalBoss::UpdateCharacterPosition(MinigameManagerData data)
{
	float x = 0.0f;
	float y = 0.0f;
	if (data.input & RIF_Up)
	{
		y -= 1.0f;
	}
	if (data.input & RIF_Down)
	{
		y += 1.0f;
	}
	if (data.input & RIF_Left)
	{
		x -= 1.0f;
	}
	if (data.input & RIF_Right)
	{
		x += 1.0f;
	}
	if (x != 0.0f && y != 0.0f)
	{
		x *= 0.707f;
		y *= 0.707f;
	}
	characterParent->Translate(Point3Scale({ x, y }, characterSpeed));
	NJS_POINT3 pos = characterParent->GetPositionGlobal();
	x = characterParent->displaySize.x * 0.5f;
	y = characterParent->displaySize.y * 0.5f;
	pos.y = max(0.0f + y, pos.y);
	pos.y = min(480.0f - y, pos.y);
	pos.x = max(20.0f + x, pos.x);
	pos.x = min(620.0f - x, pos.x);
	characterParent->SetPositionGlobal(pos);
}

void MinigameFinalBoss::CreateHierarchy(MinigameManagerData data)
{
	//Create Background
	background = data.hierarchy->CreateNode("BG", data.icons->GetAnim(MGI_White_Box), { data.icons->xMax - data.icons->xMin + 2.0f, data.icons->yMax + 2.0f, 0.0f }, { data.icons->xCenter, data.icons->yCenter, 0.0f });
	background->color = { 0.0f, 0.0f, 0.0f, 0.0f };

	//Create Boss
	FHParent = data.hierarchy->CreateNode("Final_Hazard_Parent");
	FHParent->SetPositionGlobal({ 320.0f, -120.0f });
	FHLArmBase = data.hierarchy->CreateNode("Final_Hazard_Arm_Base_L", FHParent);
	FHLArmBase->SetPosition({ -128.0f, 0.0f });
	FHLArmBase->SetRotation(320.0f);
	FHLWiggle = new Wiggle(0.25f, 310.0f, 330.0f, true);
	FHLArmBase->components.push_back(FHLWiggle);
	FHRArmBase = data.hierarchy->CreateNode("Final_Hazard_Arm_Base_R", FHParent);
	FHRArmBase->SetPosition({ 128.0f, 0.0f });
	FHRArmBase->SetRotation(40.0f);
	FHRWiggle = new Wiggle(0.25f, 30.0f, 50.0f, false);
	FHRArmBase->components.push_back(FHRWiggle);
	FHLArm = data.hierarchy->CreateNode("Final_Hazard_Arm_L", data.icons->GetAnim(MGI_Square), { 100.0f, 45.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, FHLArmBase);
	FHLArm->SetPosition({ -50.0f, 0.0f });
	FHLArm->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHRArm = data.hierarchy->CreateNode("Final_Hazard_Arm_R", data.icons->GetAnim(MGI_Square), { 100.0f, 45.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, FHRArmBase);
	FHRArm->SetPosition({ 50.0f, 0.0f });
	FHRArm->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHBody = data.hierarchy->CreateNode("Final_Hazard_Body", data.icons->GetAnim(MGI_Circle), { 300.0f, 100.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, FHParent);
	FHBody->SetPosition({ 0.0f, 0.0f });
	FHBody->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHHead = data.hierarchy->CreateNode("Final_Hazard_Body", data.icons->GetAnim(MGI_Circle), { 75.0f, 100.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, FHParent);
	FHHead->SetPosition({ 0.0f, 60.0f });
	FHHead->color = { 1.0f, 1.0f, 0.5f, 0.0f };

	//Create Characters
	characterParent = data.hierarchy->CreateNode("Characters");
	characterParent->SetPositionGlobal({ 320.f, 420.0f });
	characterParent->displaySize = { 64.0f, 64.0f };
	sonic = data.hierarchy->CreateNode("Sonic", data.icons->GetAnim(MGI_Super_Sonic), { 64.0f, 64.0f }, { 0.0f, 0.0f }, characterParent);
	sonic->SetPositionGlobal(sonicOffScreenPos);
	data.collision->AddCollision(sonic, std::make_shared<CircleCollider>(20.0f, NJS_POINT3({ 0.0f, 7.0f })));
	shadow = data.hierarchy->CreateNode("Shadow", data.icons->GetAnim(MGI_Super_Shadow), { 64.0f, 64.0f }, { 0.0f, 0.0f }, characterParent);
	shadow->SetPositionGlobal(shadowOffScreenPos);
	data.collision->AddCollision(shadow, std::make_shared<CircleCollider>(20.0f, NJS_POINT3({ 0.0f, 7.0f})));
}