#include "../../pch.h"
#include "MinigameManager.h"

void DeleteUpgradeIcon_MG(ObjectMaster* obj)
{
	MinigameManager::GetInstance().EndMinigame();
	MinigameManager::GetInstance().iconData.ReleaseIcons();
	MinigameManager::GetInstance().IconObjPtr = nullptr;
}

void DrawUpgradeIcon_MG(ObjectMaster* obj)
{
	if (GameState == GameStates_Ingame)
	{
		MinigameManager::GetInstance().UpdateCurrentMinigame();
	}
}

void DrawUpgradeIconMain_MG(ObjectMaster* obj)
{
	if (GameState != GameStates_LoadFinished && GameState != GameStates_LoadLevel)
	{
		return;
	}

	if (obj->Data1.Entity->Action == 0) {
		obj->DeleteSub = DeleteUpgradeIcon_MG;
		obj->DisplaySub_Delayed3 = DrawUpgradeIcon_MG;
		obj->Data1.Entity->Action = 1;
	}
}

void MinigameManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{

}

void MinigameManager::OnFrameFunction()
{
	if (!IconObjPtr && GameState == GameStates_Ingame)
	{
		iconData.LoadIcons();
		lastInput.icons = &iconData;
		IconObjPtr = LoadObject(0, "MinigameIcons", DrawUpgradeIconMain_MG, LoadObj_Data1 | LoadObj_Data2);
		IconObjPtr->DeleteSub = DeleteUpgradeIcon_MG;
		IconObjPtr->MainSub = DrawUpgradeIconMain_MG;
		IconObjPtr->DisplaySub_Delayed3 = DrawUpgradeIcon_MG;
		IconObjPtr->Data1.Entity->Action = 1;
	}
}

void MinigameManager::OnInputFunction()
{
	lastInput.input = (RawInputFlags)ControllersRaw->on;
	//Below is test code
	//if (GameState == GameStates_Ingame && !currentMinigame && lastInput.input & RIF_Down)
	//{
	//	state = MGS_None;
	//	currentMinigame = &pong;
	//}
}

void MinigameManager::UpdateCurrentMinigame()
{
	if (currentMinigame)
	{
		if (state == MGS_None)
		{
			currentMinigame->OnGameStart();
			minigameStart = std::clock();
			state = MGS_PreGame;
		}
		if (state == MGS_PreGame)
		{
			if (((std::clock() - minigameStart) / (double)CLOCKS_PER_SEC) > currentMinigame->pregameTime)
			{
				state = MGS_InProgress;
			}
		}
		if (state == MGS_InProgress || state == MGS_PreGame)
		{
			lastInput.managerState = state;
			currentMinigame->OnFrame(lastInput);
		}
		if (currentMinigame->currentState == MGS_Victory || currentMinigame->currentState == MGS_Loss)
		{
			state = currentMinigame->currentState;
			if (state == MGS_Victory)
			{
				HandleVictory();
			}
			else
			{
				HandleLoss();
			}
			currentMinigame = nullptr;
		}
	}
}

void MinigameManager::EndMinigame()
{
	currentMinigame = nullptr;
	state = MGS_None;
}

void MinigameManager::StartMinigame(ItemValue item)
{
	if (state != MGS_None)
	{
		return;
	}

	switch (item)
	{
	case IV_PongTrap:
		currentMinigame = &pong;
		break;
	}
}

void MinigameManager::HandleVictory()
{
	state = MGS_None;
}

void MinigameManager::HandleLoss()
{
	state = MGS_None;
}