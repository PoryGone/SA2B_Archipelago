#include "../pch.h"
#include "StageSelectManager.h"

void* saveLevelDataReadOffset_ptr = (void*)0x6773b6;
const char saveLevelDataReadOffset = '\x3d';
const char unlockByteData = '\x01';

void StageSelectManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	WriteData<1>(saveLevelDataReadOffset_ptr, saveLevelDataReadOffset);

	InitializeStageSelectData(this->_stageSelectDataMap);
}

void StageSelectManager::OnFrameFunction()
{
	UnlockAllLevels();
}

void StageSelectManager::UnlockAllLevels()
{
	for (int i = 0; i < StageSelectStage::SSS_COUNT; i++)
	{
		WriteData<1>((void*)this->_stageSelectDataMap[i].UnlockMemAddress, unlockByteData);
	}
}