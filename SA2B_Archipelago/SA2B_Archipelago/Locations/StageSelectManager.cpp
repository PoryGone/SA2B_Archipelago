#include "../pch.h"
#include "StageSelectManager.h"
#include "../Utilities/MessageQueue.h"
#include "../Archipelago/ArchipelagoManager.h"

void* saveLevelDataReadOffset_ptr = (void*)0x6773b6;
const char saveLevelDataReadOffset = '\x3d';
const char unlockByteData = '\x01';
const char lockByteData = '\x00';
const char nullop = '\x90';

DataPointer(char, StoryModeButton, 0x1D1BC01);
DataPointer(char, SP_SelectedButton, 0x1D1BC00);
DataPointer(char, Extras_SelectedButton, 0x1D1BC38);
DataPointer(char, EmblemResultsButton, 0x1D1BC3B);

DataPointer(__int8, Settings_SelectedOption, 0x1D7BAA0);

DataPointer(char, SS_CameraPos, 0x1D1BEC0);
DataPointer(char, SS_SelectedTile, 0x1D1BF08);

DataPointer(char, CannonCore1_Rank, 0x01DEE040);

void StageSelectManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	WriteData<1>(saveLevelDataReadOffset_ptr, saveLevelDataReadOffset);

	InitializeStageSelectData(this->_stageSelectDataMap);
}

void StageSelectManager::OnFrameFunction()
{
	if (CurrentMenu == Menus::Menus_Main)
	{
		SS_SelectedTile = this->_firstStageIndex;
	}

	HideMenuButtons();
	HandleBiolizard();
	SetLevelsLockState();
	HandleStageSelectCamera();

	if (CurrentMenu == Menus::Menus_StageSelect && GameMode == GameMode::GameMode_Advertise)
	{
		_helperFunctions->SetDebugFontColor(0xFFF542C8);
		if (_gateRequirements.size() > 1)
		{
			std::string gateRequirementMessage = "Next Gate Emblems: ";
			gateRequirementMessage.append(std::to_string(EmblemCount));
			gateRequirementMessage.append("/");
			for (int g = 0; g < _gateRequirements.size(); g++)
			{
				if (_gateRequirements[g] > EmblemCount || g == _gateRequirements.size() - 1)
				{
					gateRequirementMessage.append(std::to_string(_gateRequirements[g]));
					break;
				}
			}
			_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 3), gateRequirementMessage.c_str());
		}

		std::string cannonsCoreMessage = "Cannons Core Emblems: ";
		cannonsCoreMessage.append(std::to_string(EmblemCount));
		cannonsCoreMessage.append("/");
		cannonsCoreMessage.append(std::to_string(_emblemsForCannonsCore));
		_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 2), cannonsCoreMessage.c_str());

	}
}

void StageSelectManager::SetEmblemsForCannonsCore(int emblemsRequired)
{
	_emblemsForCannonsCore = emblemsRequired;
}

void StageSelectManager::SetRegionEmblemMap(std::map<int, int> map)
{
	_regionEmblemMap = map;
	LayoutLevels();
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

__int8 TileIndexFromAddress(int Address)
{
	__int8 TileIndex = (__int8)((Address - 0xC75078) / 0x10);

	return TileIndex;
}

void StageSelectManager::LayoutLevels()
{
	std::vector<GateLevelCollection> gates = std::vector<GateLevelCollection>();
	_gateRequirements = std::vector<int>();
	for (int i = 0; i < StageSelectStage::SSS_COUNT; i++)
	{
		if (i < _regionEmblemMap.size())
		{
			int index = GateIndex(gates, _regionEmblemMap[i]);
			gates[index].Levels.emplace_back(i);
		}
	}
	std::sort(gates.begin(), gates.end(), CompareGateLevelCollections);
	int col = 1;
	int row = 3;
	for (int g = 0; g < gates.size(); g++)
	{
		_gateRequirements.emplace_back(gates[g].EmblemCount);
		for (int l = 0; l < gates[g].Levels.size(); l++)
		{
			StageSelectStageData data = this->_stageSelectDataMap[gates[g].Levels[l]];
			WriteData<1>((void*)data.TileColumnAddress, col);
			WriteData<1>((void*)data.TileRowAddress, row);

			if (col == 1 && row == 3)
			{
				this->_firstStageIndex = TileIndexFromAddress(data.TileIDAddress);
			}

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
}

void StageSelectManager::SetLevelsLockState()
{
    //Make Route 101 and 280 available
    WriteData<1>((void*)0x6773D0, 0x2D);
    WriteData<1>((void*)0x6773C9, 0xF1);

    for (int i = 0; i < StageSelectStage::SSS_COUNT; i++)
    {
        if (_regionEmblemMap.count(i) != 0)
        {
            if (EmblemCount >= _regionEmblemMap.at(i))
            {
                WriteData<1>((void*)this->_stageSelectDataMap.at(i).UnlockMemAddress, unlockByteData);
            }
            else
            {
                WriteData<1>((void*)this->_stageSelectDataMap.at(i).UnlockMemAddress, lockByteData);
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

	EmblemResultsButton = 0x01;
	if (Extras_SelectedButton == 0x02)
	{
		Extras_SelectedButton = 0x03;
	}

	if (CurrentMenu == Menus::Menus_Settings)
	{
		if (Settings_SelectedOption == 0x01) // File Select Button
		{
			if (this->_previousSettingsSelection == 0x00)
			{
				Settings_SelectedOption = 0x02;
			}
			else
			{
				Settings_SelectedOption = 0x00;
			}
		}

		this->_previousSettingsSelection = Settings_SelectedOption;
	}
}

void StageSelectManager::HandleBiolizard()
{
	if (CannonCore1_Rank > 0)
	{
		// Biolizard Tile
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileIDAddress, 0x41);
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileCharacterAddress, 0x01);
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileColumnAddress, 0x1B);
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileRowAddress, 0x04);

		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_Biolizard].UnlockMemAddress, unlockByteData);
	}

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

void TurnOffVanillaCamera()
{
	WriteData<7>((void*)0x677456, nullop);
	WriteData<7>((void*)0x677492, nullop);
	WriteData<7>((void*)0x67749B, nullop);
	WriteData<7>((void*)0x6774BD, nullop);
	WriteData<7>((void*)0x678137, nullop);
	WriteData<7>((void*)0x678144, nullop);
	WriteData<7>((void*)0x678169, nullop);
	WriteData<7>((void*)0x678191, nullop);
	WriteData<7>((void*)0x6781D3, nullop);
	WriteData<7>((void*)0x6781F5, nullop);
	WriteData<7>((void*)0x678220, nullop);
	WriteData<7>((void*)0x678219, nullop);

	WriteData<2>((void*)0x67745F, nullop);
	WriteData<2>((void*)0x677469, nullop);
}

void StageSelectManager::HandleStageSelectCamera()
{
	TurnOffVanillaCamera();

	bool is4by3 = ((HorizontalResolution / VerticalResolution) < 1.34f);

	if (SS_SelectedTile < TileIDtoStageIndex.size())
	{
		int currentTileStageIndex = this->TileIDtoStageIndex[SS_SelectedTile];

		if (currentTileStageIndex < this->_stageSelectDataMap.size())
		{
			const int currentTileXPosAddress = this->_stageSelectDataMap.at(currentTileStageIndex).TileColumnAddress;

			int currentTileXPos = *(char*)currentTileXPosAddress;

			if (currentTileXPos > 0x13)
			{
				SS_CameraPos = 0x03;
			}
			else if (currentTileXPos > 0x0D && is4by3)
			{
				SS_CameraPos = 0x02;
			}
			else if (currentTileXPos > 0x08)
			{
				SS_CameraPos = 0x01;
			}
			else
			{
				SS_CameraPos = 0x00;
			}
		}
	}
}
