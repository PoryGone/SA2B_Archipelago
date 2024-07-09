#include "../../../pch.h"
#include "PunchOut.h"

void PunchOut::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_InProgress;
	CreateHierarchy(data);

	playerState = POP_Idle;
	aiState = POA_Idle;
}

void PunchOut::OnFrame(MinigameManagerData data)
{
	UpdateCenterText(data);
	if (data.managerState != MGS_InProgress)
	{
		return;
	}
	UpdatePlayer();
	UpdateAI();
	if (data.inputPress & RIF_Y)
	{
		currentState = MGS_Draw;
	}
}

void PunchOut::OnCleanup(MinigameManagerData data)
{

}

void PunchOut::UpdateCenterText(MinigameManagerData data)
{
	if (data.managerState == MGS_PreGame)
	{
		if (textSize < textMaxSize)
		{
			textSize += textMaxSize / 60.0f;
			centerText->UpdateFontSize(textSize);
		}
	}
	else if (textSize > 0.0f)
	{
		centerText->UpdateText("Fight");
	}
}

void PunchOut::UpdatePlayer()
{

}

void PunchOut::UpdateAI()
{

}

void PunchOut::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(RIF_Left | RIF_Up | RIF_Right, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);

	aiParent = data.hierarchy->CreateNode("AI_Parent");
	aiParent->SetPositionGlobal({ 320.0f, 300.0f });
	aiBody = data.hierarchy->CreateNode("AI_Body", data.icons->GetAnim(MGI_Square), { 80.0f, 120.0f }, {}, aiParent);
	aiBody->SetPosition({});
	aiBody->color = { 1.0f, 0.5f, 0.5f, 0.5f };
	aiHead = data.hierarchy->CreateNode("AI_Head", data.icons->GetAnim(MGI_Beetle), { 100.0f, 100.0f }, {}, aiParent);
	aiHead->SetPosition({ 5.0f, -72.0f });
	aiLeftHand = data.hierarchy->CreateNode("AI_Hand_L", data.icons->GetAnim(MGI_Circle), { 50.0f, 50.0f }, {}, aiParent);
	aiLeftHand->SetPosition({ -50.0f, -24.0f });
	aiLeftHand->color = { 1.0f, 1.0f, 0.0f, 0.0f };
	aiRightHand = data.hierarchy->CreateNode("AI_Hand_R", data.icons->GetAnim(MGI_Circle), { 50.0f, 50.0f }, {}, aiParent);
	aiRightHand->SetPosition({ 50.0f, -24.0f });
	aiRightHand->color = { 1.0f, 1.0f, 0.0f, 0.0f };

	playerParent = data.hierarchy->CreateNode("Player_Parent");
	playerParent->SetPositionGlobal({ 320.0f, 465.0f });
	playerHead = data.hierarchy->CreateNode("Player_Head", data.icons->GetAnim(MGI_Beetle), { 100.0f, 100.0f }, {}, playerParent);
	playerHead->SetPosition({ 5.0f, -72.0f });
	playerLeftHand = data.hierarchy->CreateNode("Player_Hand_L", data.icons->GetAnim(MGI_Circle), { 55.0f, 55.0f }, {}, playerParent);
	playerLeftHand->SetPosition({ -50.0f, -24.0f });
	playerLeftHand->color = { 1.0f, 0.0f, 1.0f, 0.0f };
	playerRightHand = data.hierarchy->CreateNode("Player_Hand_R", data.icons->GetAnim(MGI_Circle), { 55.0f, 55.0f }, {}, playerParent);
	playerRightHand->SetPosition({ 50.0f, -24.0f });
	playerRightHand->color = { 1.0f, 0.0f, 1.0f, 0.0f };
	playerBody = data.hierarchy->CreateNode("Player_Body", data.icons->GetAnim(MGI_Square), { 100.0f, 100.0f }, {}, playerParent);
	playerBody->SetPosition({});
	playerBody->color = { 1.0f, 0.35f, 0.45f, 0.76f };

	centerTextParent = data.hierarchy->CreateNode("Text_Center");
	centerTextParent->SetPosition({ data.icons->xCenter, data.icons->yCenter });

	centerText = new TextBox("Ready", textSize, TextAlignment::Center, data.text);
	centerTextParent->renderComponents.push_back(centerText);
}