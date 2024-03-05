#include "../../../pch.h"
#include "MinigameFinalBoss.h"

void MinigameFinalBoss::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_InProgress;
	state = FBS_Intro;
	introState = FBIS_CharacterEntrance;
	CreateHierarchy(data);
}

void MinigameFinalBoss::OnFrame(MinigameManagerData data)
{
	if (FHParent->GetPositionGlobal().y < 0.0f)
	{
		FHParent->Translate({ 0.0f, 0.25f, 0.0f, });
	}
	if (background->color.a < 1.0f)
	{
		background->color.a = min(background->color.a + 0.05f, 1.0f);
	}
	if (data.inputPress & RIF_Y)
	{
		currentState = MGS_Draw;
	}
}

void MinigameFinalBoss::CreateHierarchy(MinigameManagerData data)
{
	background = data.hierarchy->CreateNode("BG", data.icons->GetAnim(MGI_White_Box), { data.icons->xMax - data.icons->xMin + 2.0f, data.icons->yMax + 2.0f, 0.0f }, { data.icons->xCenter, data.icons->yCenter, 0.0f });
	background->color = { 0.0f, 0.0f, 0.0f, 0.0f };

	FHParent = data.hierarchy->CreateNode("Final_Hazard_Parent");
	FHParent->SetPositionGlobal({ 320.0f, -120.0f });
	FHLArmBase = data.hierarchy->CreateNode("Final_Hazard_Arm_Base_L", FHParent);
	FHLArmBase->SetPosition({ -128.0f, 0.0f, 0.0f });
	FHLArmBase->SetRotation(320.0f);
	FHLWiggle = new Wiggle(0.25f, 310.0f, 330.0f, true);
	FHLArmBase->components.push_back(FHLWiggle);
	FHRArmBase = data.hierarchy->CreateNode("Final_Hazard_Arm_Base_R", FHParent);
	FHRArmBase->SetPosition({ 128.0f, 0.0f, 0.0f });
	FHRArmBase->SetRotation(40.0f);
	FHRWiggle = new Wiggle(0.25f, 30.0f, 50.0f, false);
	FHRArmBase->components.push_back(FHRWiggle);
	FHLArm = data.hierarchy->CreateNode("Final_Hazard_Arm_L", data.icons->GetAnim(MGI_Square), { 100.0f, 45.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, FHLArmBase);
	FHLArm->SetPosition({ -50.0f, 0.0f, 0.0f });
	FHLArm->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHRArm = data.hierarchy->CreateNode("Final_Hazard_Arm_R", data.icons->GetAnim(MGI_Square), { 100.0f, 45.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, FHRArmBase);
	FHRArm->SetPosition({ 50.0f, 0.0f, 0.0f });
	FHRArm->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHBody = data.hierarchy->CreateNode("Final_Hazard_Body", data.icons->GetAnim(MGI_Circle), { 300.0f, 100.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, FHParent);
	FHBody->SetPosition({ 0.0f, 0.0f, 0.0f });
	FHBody->color = { 1.0f, 1.0f, 0.5f, 0.0f };
	FHHead = data.hierarchy->CreateNode("Final_Hazard_Body", data.icons->GetAnim(MGI_Circle), { 75.0f, 100.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, FHParent);
	FHHead->SetPosition({ 0.0f, 60.0f, 0.0f });
	FHHead->color = { 1.0f, 1.0f, 0.5f, 0.0f };

	characterParent = data.hierarchy->CreateNode("Characters");
	characterParent->SetPositionGlobal({ 320.f, 420.0f, 0.0f });
	sonic = data.hierarchy->CreateNode("Sonic", data.icons->GetAnim(MGI_Super_Sonic), { 64.0f, 64.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, characterParent);
	sonic->SetPosition({ 0.0f, 0.0f, 0.0f });
}