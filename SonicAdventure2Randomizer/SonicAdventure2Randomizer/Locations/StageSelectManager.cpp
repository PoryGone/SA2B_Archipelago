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
}

void StageSelectManager::UnlockAllLevels()
{
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