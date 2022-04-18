#include "../pch.h"
#include "StageSelectManager.h"
#include "../Utilities/MessageQueue.h"

void* saveLevelDataReadOffset_ptr = (void*)0x6773b6;
const char saveLevelDataReadOffset = '\x3d';
const char unlockByteData = '\x01';
const char lockByteData = '\x00';

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
	HideMenuButtons();
	HandleBiolizard();
	SetLevelsLockState();
}

void StageSelectManager::SetEmblemsForCannonsCore(int emblemsRequired)
{
	_emblemsForCannonsCore = emblemsRequired;
	std::string message = "Emblems For Core: ";
	message.append(std::to_string(_emblemsForCannonsCore));
	MessageQueue::GetInstance().AddMessage(message);
}

void StageSelectManager::SetRegionEmblemMap(std::map<int, int> map)
{
	_regionEmblemMap = map;
	LayoutLevels();
	std::string message = "Region Map Regions: ";
	message.append(std::to_string(map.size()));
	MessageQueue::GetInstance().AddMessage(message);
}

int GateIndex(std::vector<GateLevelCollection>& gates, int emblemCount)
{
	for (int i = 0; i < gates.size(); i++)
	{
		if (gates[i].EmblemCount == emblemCount)
		{
			return i;
		}
	}
	gates.emplace_back(GateLevelCollection(emblemCount));
	return gates.size() - 1;
}

bool CompareGateLevelCollections(GateLevelCollection a, GateLevelCollection b)
{
	return a.EmblemCount < b.EmblemCount;
}

void StageSelectManager::LayoutLevels()
{
	std::vector<GateLevelCollection> gates = std::vector<GateLevelCollection>();
	for (int i = 0; i < StageSelectStage::SSS_COUNT; i++)
	{
		if (i < _regionEmblemMap.size())
		{
			int index = GateIndex(gates, _regionEmblemMap[i]);
			gates[index].Levels.emplace_back(i);
		}
	}
	std::string debugStr = "Gate Levels: ";
	std::sort(gates.begin(), gates.end(), CompareGateLevelCollections);
	int col = 1;
	int row = 3;
	for (int g = 0; g < gates.size(); g++)
	{
		debugStr.append(std::to_string(gates[g].Levels.size()));
		debugStr.append(", ");
		for (int l = 0; l < gates[g].Levels.size(); l++)
		{
			StageSelectStageData data = this->_stageSelectDataMap[gates[g].Levels[l]];
			WriteData<1>((void*)data.TileColumnAddress, col);
			WriteData<1>((void*)data.TileRowAddress, row);
			if (row == 5)
			{
				row = 3;
				col++;
			}
			else
			{
				row++;
			}
		}
		col += 2;
		row = 3;
	}
	MessageQueue::GetInstance().AddMessage(debugStr);
}

void StageSelectManager::SetLevelsLockState()
{
	for (int i = 0; i < StageSelectStage::SSS_COUNT; i++)
	{
		if (i < _regionEmblemMap.size() && EmblemCount >= _regionEmblemMap[i])
		{
			WriteData<1>((void*)this->_stageSelectDataMap[i].UnlockMemAddress, unlockByteData);
			if (i == StageSelectStage::SSS_Route101)
			{
				WriteData<1>((void*)0x6773D0, 0x2D);
			}
			if (i == StageSelectStage::SSS_Route280)
			{
				WriteData<1>((void*)0x6773C9, 0xF1);
			}
		}
	}
	if (EmblemCount >= _emblemsForCannonsCore)
	{
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_CannonCore].UnlockMemAddress, unlockByteData);
	}
	else
	{
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_CannonCore].UnlockMemAddress, lockByteData);
	}
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