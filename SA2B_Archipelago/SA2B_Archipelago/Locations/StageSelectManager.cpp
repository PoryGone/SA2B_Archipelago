#include "../pch.h"
#include "StageSelectManager.h"
#include "../Utilities/MessageQueue.h"
#include "../Archipelago/ArchipelagoManager.h"
#include "../Aesthetics/StatsManager.h"

void* saveLevelDataReadOffset_ptr = (void*)0x6773b6;
const char saveLevelDataReadOffset = '\x3d';
const char unlockByteData = '\x01';
const char lockByteData = '\x00';
const char nullop = '\x90';
void* japaneseStageTitleAtlas_ptr = (void*)0x676837;

DataPointer(char, StoryModeButton, 0x1D1BC01);
DataPointer(char, KartRaceModeButton, 0x1D1BC03);
DataPointer(char, BossBattleModeButton, 0x1D1BC04);
DataPointer(char, SP_SelectedButton, 0x1D1BC00);
DataPointer(char, Extras_SelectedButton, 0x1D1BC38);
DataPointer(char, EmblemResultsButton, 0x1D1BC3B);

DataPointer(__int8, Settings_SelectedOption, 0x1D7BAA0);

DataPointer(char, SS_CameraPos, 0x1D1BEC0);
DataPointer(char, SS_SelectedTile, 0x1D1BF08);

DataPointer(char, SS_SelectedMission, 0x1D1BF05);
DataPointer(char, ActiveMission, 0x174AFE3);

DataPointer(char, CannonCore1_Rank, 0x01DEE040);

DataArray(char, GateBossSaveData, 0x01DEE59C, 5);

DataArray(int, JapanesseStageHeaders, 0x008A0470, 68);
DataArray(int, EnglishStageHeaders, 0x8A0560, 45);


const void* const loc_Mission_1 = (void*)0x1DEEBBC;
const void* const loc_esi_backup = (void*)0x1DEEBD0;

const void* const loc_6766C8 = (void*)0x6766C8;
void __cdecl MissionDisplay_Begin_ASM()
{
	__asm
	{
		mov dword ptr ds:[0x1DEEBD0], esi
		movzx esi, dword ptr[0x1DEEBBC + esi*4]
		fld dword ptr ds:[0x12D4694]
		jmp loc_6766C8
	}
}

const void* const loc_6767F5 = (void*)0x6767F5;
void __cdecl MissionDisplay_End_ASM()
{
	__asm
	{
		mov esi, dword ptr ds:[0x1DEEBD0]
		inc esi
		add esp, 8
		cmp esi, 5
		jmp loc_6767F5
	}
}


void StageSelectManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	WriteData<1>(saveLevelDataReadOffset_ptr, saveLevelDataReadOffset);

	WriteJump(static_cast<void*>((void*)0x6766C2), (void*)((int)(&MissionDisplay_Begin_ASM) + 0x4));
	WriteData<1>((void*)0x6766C7, nullop);

	WriteJump(static_cast<void*>((void*)0x6767ee), (void*)((int)(&MissionDisplay_End_ASM) + 0x4));
	WriteData<2>((void*)0x6767F3, nullop);

	InitializeStageSelectData(this->_stageSelectDataMap);
	InitializeStageSelectBossData(this->_stageSelectBossDataMap);
	InitializeItemData(this->_itemData);
	InitializeCharacterItemRanges(this->_characterItemRanges);
	UpdateTitleHeaderArrays();
	StageSelectIcons::GetInstance().OnInit(&_stageSelectDataMap);
}

void StageSelectManager::OnFrameFunction()
{
	StageSelectIcons::GetInstance().OnFrame();
	
	if (CurrentMenu == Menus::Menus_Main)
	{
		SS_SelectedTile = this->_firstStageIndex;
	}

	HideMenuButtons();
	HandleGoal();
	HandleBossStage();
	SetLevelsLockState();
	LayoutBossGates();
	HandleStageSelectCamera();
	HandleMissionOrder();

	DrawStageSelectText();
}

void StageSelectManager::DrawDebugText(int location, const char* message)
{
	GetInstance()._helperFunctions->SetDebugFontColor(0xFFF542C8);
	GetInstance()._helperFunctions->DisplayDebugString(location, message);
}

void StageSelectManager::SetGoal(int goal)
{
	this->_goal = goal;
}

void StageSelectManager::SetEmblemsForCannonsCore(int emblemsRequired)
{
	_emblemsForCannonsCore = emblemsRequired;
}

void StageSelectManager::SetRequiredCannonsCoreMissions(bool allMissionsRequired)
{
	this->_requireAllCannonsCoreMissions = allMissionsRequired;
}

void StageSelectManager::SetMissionCount(int missionCount)
{
	this->_missionCount = missionCount;
}

void StageSelectManager::SetRequiredRank(int requiredRank)
{
	this->_requiredRank = requiredRank;
	WriteData<1>((void*)0x67675C, (char)requiredRank);
}

void StageSelectManager::SetRegionEmblemMap(std::map<int, int> map)
{
	_regionEmblemMap = map;
	LayoutLevels();
}

void StageSelectManager::SetChosenMissionsMap(std::map<int, int> map)
{
	this->_chosenMissionsMap = map;
}

void StageSelectManager::SetBossGates(std::map<int, int> map)
{
	_bossGates = map;
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
	_gateBossLayoutData = std::vector<GateBossLayout>();
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
		if (g > 0)
		{
			//Generate gate boss tile data
			_gateBossLayoutData.push_back(GateBossLayout(
				StageIconLocation(col - 1, 4),
				StageIconLocation(col, row),
				(StageSelectStage)gates[g].Levels[0]));
		}
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

			if (row == 5 && l < (gates[g].Levels.size() - 1))
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

	if (this->_goal == 1 || this->_goal == 2)
	{
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileColumnAddress, col);
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileRowAddress, 4);
	}
}

void StageSelectManager::LayoutBossGates()
{
	if (_gateRequirements.size() == 0 || _bossGates.size() == 0 || _gateBossLayoutData.size() == 0)
	{
		return;
	}
	for (std::map<int, int>::iterator i = _bossGates.begin(); i != _bossGates.end(); ++i)
	{
		if (_gateRequirements[i->first] <= EmblemCount)
		{
			if (i->first > 1 && GateBossSaveData[i->first - 2] == 0)
			{
				break;
			}
			bool unlocked = GateBossSaveData[i->first - 1] >= 1;
			if (unlocked)
			{
				StageSelectStageData tileData = this->_stageSelectDataMap[_gateBossLayoutData[i->first - 1].FirstGateStage];
				WriteData<1>((void*)tileData.TileColumnAddress, _gateBossLayoutData[i->first - 1].StageLocation.X);
				WriteData<1>((void*)tileData.TileRowAddress, _gateBossLayoutData[i->first - 1].StageLocation.Y);
				WriteData<1>((void*)tileData.TileCharacterAddress, tileData.DefaultCharacter);
				WriteData<1>((void*)tileData.TileIDAddress, StageSelectStageToLevelID(_gateBossLayoutData[i->first - 1].FirstGateStage));
			}
			else
			{
				BossStageData stageData = _stageSelectBossDataMap[i->second].GetBossStage(_gateBossLayoutData[i->first - 1].FirstGateStage);
				StageSelectStageData tileData = this->_stageSelectDataMap[_gateBossLayoutData[i->first - 1].FirstGateStage];
				WriteData<1>((void*)tileData.TileColumnAddress, _gateBossLayoutData[i->first - 1].BossLocation.X);
				WriteData<1>((void*)tileData.TileRowAddress, _gateBossLayoutData[i->first - 1].BossLocation.Y);
				WriteData<1>((void*)tileData.TileCharacterAddress, stageData.Character);
				WriteData<1>((void*)tileData.TileIDAddress, stageData.LevelID);
				WriteData<1>((void*)stageData.UnlockMemAddress, unlockByteData);
			}
		}
	}

	WriteData<5>((void*)0x1DEF5B0, lockByteData);
}

void StageSelectManager::SetLevelsLockState()
{
    //Make Route 101 and 280 available
    WriteData<1>((void*)0x6773D0, 0x3A);
    WriteData<1>((void*)0x6773C9, 0xFE);

	//Lock levels behind an uncleared boss gate
	int lastUnlockedGateEmblemCount = 0;
	for (int i = 1; i < _gateRequirements.size(); i++)
	{
		if (EmblemCount >= _gateRequirements[i] && GateBossSaveData[i - 1] >= 1)
		{
			lastUnlockedGateEmblemCount = _gateRequirements[i];
		}
	}

    for (int i = 0; i < StageSelectStage::SSS_COUNT; i++)
    {
        if (_regionEmblemMap.count(i) != 0)
        {
            if (lastUnlockedGateEmblemCount >= _regionEmblemMap.at(i))
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

void StageSelectManager::DrawStageSelectText()
{
	if (CurrentMenu == Menus::Menus_StageSelect && GameMode == GameMode::GameMode_Advertise)
	{
		_helperFunctions->SetDebugFontColor(0xFFF542C8);
		if (_gateRequirements.size() > 1)
		{
			if (EmblemCount >= _gateRequirements[_gateRequirements.size() - 1])
			{
				_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 4), "All Gates Unlocked");
			}
			else
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
				_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 4), gateRequirementMessage.c_str());
			}
		}

		std::string cannonsCoreMessage = "Cannons Core Emblems: ";
		cannonsCoreMessage.append(std::to_string(EmblemCount));
		cannonsCoreMessage.append("/");
		cannonsCoreMessage.append(std::to_string(_emblemsForCannonsCore));
		_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 3), cannonsCoreMessage.c_str());

		std::string missionCountMessage = "Missions Active: ";
		missionCountMessage.append(std::to_string(this->_missionCount));
		_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 2), missionCountMessage.c_str());

		DrawCurrentLevelUpgrade();
		DrawCurrentCharacterUpgrades();
	}
}

void StageSelectManager::DrawDebugTextOnScreenRight(std::string text, int row)
{
	int missionCountMessageXPos = ((HorizontalResolution / MessageQueue::GetInstance().GetFontSize()) - text.length());
	_helperFunctions->DisplayDebugString(NJM_LOCATION(missionCountMessageXPos, row), text.c_str());
}

void StageSelectManager::DrawCurrentLevelUpgrade()
{
	if (SS_SelectedTile < TileIDtoStageIndex.size())
	{
		int currentTileStageIndex = this->TileIDtoStageIndex[SS_SelectedTile];
		if (currentTileStageIndex < this->_stageSelectDataMap.size())
		{
			std::string message = "";
			if (this->_stageSelectDataMap.at(currentTileStageIndex).UpgradeAddress == 0x00)
			{
				message = "Level Upgrade: None";
			}
			else
			{
				if (*(char*)this->_stageSelectDataMap.at(currentTileStageIndex).UpgradeAddress > 0x00)
				{
					message = "Level Upgrade: Acquired";
				}
				else
				{
					message = "Level Upgrade: Not Acquired";
				}
			}
			DrawDebugTextOnScreenRight(message, 0);
		}
	}
}

void StageSelectManager::DrawCurrentCharacterUpgrades()
{
	if (SS_SelectedTile < TileIDtoStageIndex.size())
	{
		int currentTileStageIndex = this->TileIDtoStageIndex[SS_SelectedTile];
		if (currentTileStageIndex < this->_stageSelectDataMap.size())
		{
			char character = *(char*)this->_stageSelectDataMap.at(currentTileStageIndex).TileCharacterAddress;
			CharacterItemRange range = GetItemRangeForCharacter(character);
			int row = 2;
			for (int i = range.Start; i <= range.End; i++)
			{
				if (*(char*)this->_itemData.at(i).Address > 0x00)
				{
					DrawDebugTextOnScreenRight(_itemData.at(i).DisplayNameShort, row);
					row++;
				}
			}
		}
	}
}

CharacterItemRange StageSelectManager::GetItemRangeForCharacter(char character)
{
	for (int i = 0; i < _characterItemRanges.size(); i++)
	{
		if (_characterItemRanges[i].Character == character)
		{
			return _characterItemRanges[i];
		}
	}
	return CharacterItemRange();
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

void StageSelectManager::UpdateTitleHeaderArrays()
{
	//Japanese Stage Title Atlas ptr
	//Point English stage titles to the start of the Japanese stage titles
	//to make room for the boss headers
	WriteData<1>((void*)0x676837, '\x70');
	WriteData<1>((void*)0x676838, '\x04');

	for (int i = 0; i < EnglishStageHeaders_Length; i++)
	{
		JapanesseStageHeaders[i] = EnglishStageHeaders[i];
	}

	for (int i = 0; i < SSB_COUNT; i++)
	{
		JapanesseStageHeaders[_stageSelectBossDataMap[i].GetBossStage(0).LevelID] = 0x07;
	}
	//Set Biolizard header
	JapanesseStageHeaders[0x41] = 0x00;
}

void StageSelectManager::HideMenuButtons()
{
	StoryModeButton = 0x01;
	if (SP_SelectedButton == 0x00)
	{
		SP_SelectedButton = 0x01;
	}
	KartRaceModeButton = 0x01;
	BossBattleModeButton = 0x01;

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

bool IsBossLevel()
{
	return CurrentLevel == LevelIDs_SonicVsShadow1 || CurrentLevel == LevelIDs_SonicVsShadow2 ||
		   CurrentLevel == LevelIDs_TailsVsEggman1 || CurrentLevel == LevelIDs_TailsVsEggman2 || CurrentLevel == LevelIDs_KnucklesVsRouge ||
		   CurrentLevel == LevelIDs_BigFoot || CurrentLevel == LevelIDs_HotShot || CurrentLevel == LevelIDs_FlyingDog ||
		   CurrentLevel == LevelIDs_EggGolemS || CurrentLevel == LevelIDs_EggGolemE || CurrentLevel == LevelIDs_KingBoomBoo;
}

void StageSelectManager::HandleBossStage()
{
	if (this->_needsSave && GameState == GameStates_Inactive)
	{
		ProbablySavesSaveFile();
		this->_needsSave = false;
	}

	if (IsBossLevel())
	{
		if (GameState == GameStates_GoToNextLevel)
		{
			for (std::map<int, int>::iterator it = _bossGates.begin(); it != _bossGates.end(); ++it)
			{
				if (CurrentLevel == this->_stageSelectBossDataMap[it->second].GetBossStage(0).LevelID)
				{
					GateBossSaveData[it->first - 1] = 0x05;
					this->_needsSave = true;
					StatsManager::GetInstance().GateUnlocked(it->first - 1);
				}
			}
		}
	}
}

void StageSelectManager::HandleGoal()
{
	if (this->_goal == 0)
	{
		HandleBiolizard();
	}
	else if (this->_goal == 1 || this->_goal == 2)
	{
		HandleGreenHill();
	}
}

void StageSelectManager::HandleBiolizard()
{
	bool bCannonCoreComplete = true;

	if (this->_requireAllCannonsCoreMissions)
	{
		// TODO: Adjust this when Mission Order changes go in
		for (int i = 0; i < this->_missionCount; i++)
		{
			char dataValue = *(char*)(0x01DEE040 + i);

			if (dataValue <= this->_requiredRank)
			{
				bCannonCoreComplete = false;

				break;
			}
		}
	}
	else if (CannonCore1_Rank <= this->_requiredRank)
	{
		bCannonCoreComplete = false;
	}

	if (bCannonCoreComplete)
	{
		// Biolizard Tile
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileIDAddress, 0x41);
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileCharacterAddress, 0x01);
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileColumnAddress, 0x1B);
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].TileRowAddress, 0x04);

		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_Biolizard].UnlockMemAddress, unlockByteData);
	}
	else
	{
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_Biolizard].UnlockMemAddress, lockByteData);
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

	if (CurrentLevel == LevelIDs_FinalHazard)
	{
		if (GameState == GameStates_GoToNextLevel)
		{
			MessageQueue* messageQueue = &MessageQueue::GetInstance();
			std::string msg = "Victory!";
			messageQueue->AddMessage(msg);

			ArchipelagoManager* apm = &ArchipelagoManager::getInstance();
			apm->SendStoryComplete();
		}
	}
}

void StageSelectManager::HandleGreenHill()
{
	bool bHaveChaosEmeralds = true;

	for (int i = 0; i < 7; i++)
	{
		unsigned char dataValue = *(unsigned char*)(0x01DEEAF8 + i);

		if (dataValue == 0)
		{
			bHaveChaosEmeralds = false;
		}
	}

	if (bHaveChaosEmeralds)
	{
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].UnlockMemAddress, unlockByteData);
	}
	else
	{
		WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_GreenHill].UnlockMemAddress, lockByteData);
	}

	if (CurrentLevel == LevelIDs_GreenHill)
	{
		if (TimerMinutes == 0 && TimerSeconds < 5)
		{
			if (this->_goal == 1)
			{
				WriteData<1>((void*)0x1DEB060, 0xCE);
				WriteData<1>((void*)0x1DEB061, 0x00);
				WriteData<1>((void*)0x1DEB062, 0x00);
				WriteData<1>((void*)0x1DEB063, 0x00);
				WriteData<1>((void*)0x1DEB064, 0xCF);
				WriteData<1>((void*)0x1DEB065, 0x00);
				WriteData<1>((void*)0x1DEB066, 0x00);
				WriteData<1>((void*)0x1DEB067, 0x00);

				WriteData<1>((void*)0x1DEB31E, 0x05);
				WriteData<1>((void*)0x1DEB31F, 0x05);
				WriteData<1>((void*)0x1DEB320, 0x03);

				WriteData<1>((void*)0x174B044, 0x0C);
			}
			else if (this->_goal == 2)
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

	if (CurrentLevel == LevelIDs_GreenHill)
	{
		if (GameState == GameStates_GoToNextLevel)
		{
			if (this->_goal == 1)
			{
				MessageQueue* messageQueue = &MessageQueue::GetInstance();
				std::string msg = "Victory!";
				messageQueue->AddMessage(msg);

				ArchipelagoManager* apm = &ArchipelagoManager::getInstance();
				apm->SendStoryComplete();
			}
			else if (this->_goal == 2)
			{
				WriteData<1>((void*)0x01DEDDF4, 0x01);
			}
		}
	}

	if (this->_goal == 2 && CurrentLevel == LevelIDs_FinalHazard)
	{
		if (GameState == GameStates_GoToNextLevel)
		{
			MessageQueue* messageQueue = &MessageQueue::GetInstance();
			std::string msg = "Victory!";
			messageQueue->AddMessage(msg);

			ArchipelagoManager* apm = &ArchipelagoManager::getInstance();
			apm->SendStoryComplete();
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

			if (currentTileXPos > 0x14)
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

void StageSelectManager::HandleMissionOrder()
{
	int currentTileStageIndex = this->TileIDtoStageIndex[SS_SelectedTile];
	if (currentTileStageIndex < this->_chosenMissionsMap.size())
	{
		int missionOrderIndex = this->_chosenMissionsMap.at(currentTileStageIndex);

		if (missionOrderIndex < this->_potentialMissionOrders.size())
		{
			std::array<int, 5> chosenMissionOrder = this->_potentialMissionOrders.at(missionOrderIndex);

			ActiveMission = chosenMissionOrder[SS_SelectedMission] - 1;

			for (int i = 0; i < 5; i++)
			{
				WriteData<1>((void*)((int)(loc_Mission_1) + i*4), (char)(chosenMissionOrder[i] - 1));
			}
		}
	}
}
