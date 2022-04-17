#include "../pch.h"
#include "StageSelectManager.h"

void* saveLevelDataReadOffset_ptr = (void*)0x6773b6;
const char saveLevelDataReadOffset = '\x3d';
const char unlockByteData = '\x01';

DataPointer(char, StoryModeButton, 0x1D1BC01);
DataPointer(char, SP_SelectedButton, 0x1D1BC00);

void StageSelectManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	WriteData<1>(saveLevelDataReadOffset_ptr, saveLevelDataReadOffset);

	InitializeStageSelectData(this->_stageSelectDataMap);
}

void StageSelectManager::OnFrameFunction()
{
	UnlockAllLevels();
	HideMenuButtons();
	HandleBiolizard();
}

void StageSelectManager::UnlockAllLevels()
{
	// Biolizard Tile
	WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileIDAddress, 0x41);
	WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileCharacterAddress, 0x01);

	// Route 101
	WriteData<1>((void*)0x6773D0, 0x2D);

	// Route 280
	WriteData<1>((void*)0x6773C9, 0xF1);

	// Everything Else
	for (int i = 0; i < StageSelectStage::SSS_COUNT; i++)
	{
		WriteData<1>((void*)this->_stageSelectDataMap[i].UnlockMemAddress, unlockByteData);
	}
}

void StageSelectManager::HideMenuButtons()
{
	StoryModeButton = 0x01;
	if (SP_SelectedButton == 0x00)
	{
		SP_SelectedButton = 0x01;
	}
}

void StageSelectManager::HandleBiolizard()
{
	if (CurrentLevel == LevelIDs_Biolizard)
	{
		if (TimerMinutes == 0 && TimerSeconds < 5)
		{
			WriteData<1>((void*)0x1DEB060, 0xCC);
			WriteData<1>((void*)0x1DEB061, 0x00);
			WriteData<1>((void*)0x1DEB062, 0x00);
			WriteData<1>((void*)0x1DEB063, 0x00);
			WriteData<1>((void*)0x1DEB064, 0xCD);
			WriteData<1>((void*)0x1DEB065, 0x00);
			WriteData<1>((void*)0x1DEB066, 0x00);
			WriteData<1>((void*)0x1DEB067, 0x00);

			WriteData<1>((void*)0x1DEB31E, 0x03);
			WriteData<1>((void*)0x1DEB31F, 0x03);
			WriteData<1>((void*)0x1DEB320, 0x03);

			WriteData<1>((void*)0x174B044, 0x0C);
		}
	}
}