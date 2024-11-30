#include "../pch.h"
#include "StageSelectManager.h"
#include "LocationManager.h"
#include "../Utilities/MessageQueue.h"
#include "../Archipelago/ArchipelagoManager.h"
#include "../Aesthetics/StatsManager.h"
#include "../Items/Minigames/MinigameManager.h"

void* saveLevelDataReadOffset_ptr = (void*)0x6773b6;
const char saveLevelDataReadOffset = '\x3d';
const char unlockByteData = '\x01';
const char lockByteData = '\x00';
const char nullop = '\x90';
void* japaneseStageTitleAtlas_ptr = (void*)0x676837;

DataPointer(char, StoryModeButton, 0x1D1BC01);
DataPointer(char, StageSelectModeButton, 0x1D1BC02);
DataPointer(char, KartRaceModeButton, 0x1D1BC03);
DataPointer(char, BossBattleModeButton, 0x1D1BC04);
DataPointer(char, SP_SelectedButton, 0x1D1BC00);
DataPointer(char, Extras_SelectedButton, 0x1D1BC38);
DataPointer(char, EmblemResultsButton, 0x1D1BC3B);

DataPointer(__int8, MainMenu_SelectedOption, 0x1D1BBE4);
DataPointer(__int8, Settings_SelectedOption, 0x1D7BAA0);

DataPointer(__int8, BossBattle_SelectedOption, 0x1D1C030);

DataPointer(char, SS_CameraPos, 0x1D1BEC0);
DataPointer(char, SS_SelectedTile, 0x1D1BF08);

DataPointer(char, SS_SelectedMission, 0x1D1BF05);
DataPointer(char, ActiveMission, 0x174AFE3);

DataPointer(char, CannonCore1_Rank, 0x01DEE040);

DataArray(char, GateBossSaveData, 0x01DEE59C, 5);

DataArray(int, JapanesseStageHeaders, 0x008A0470, 68);
DataArray(int, EnglishStageHeaders, 0x8A0560, 45);

DataPointer(char, StoryProgressID_1, 0x1DEB31E);
DataPointer(char, StoryProgressID_2, 0x1DEB31F);
DataPointer(char, StoryProgressID_3, 0x1DEB320);

DataPointer(unsigned int, NewEmblemCount, 0x1DEE418);


const void* const loc_Mission_1 = (void*)0x1DEEBBC;
const void* const loc_esi_backup = (void*)0x1DEEBD0;
const void* const loc_mission_count = (void*)0x1DEEBD4;

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

//67670b
const void* const loc_676712 = (void*)0x676712;
void __cdecl MissionDisplay_CompareActive_ASM() 
{
	__asm
	{
		mov edx, dword ptr [ecx + 4]
		mov eax, dword ptr ds:[0x1DEEBD0]
		movzx eax, dword ptr[0x1DEEBBC + eax * 4 - 4]
		cmp byte ptr[edx + eax], 0
		jmp loc_676712
	}
}

const void* const loc_678504 = (void*)0x678504;
void __cdecl Mission_Enter_ASM()
{
	__asm
	{
		movzx ecx, dword ptr[0x1DEEBBC + ecx*4 - 4]
		cmp byte ptr[edi + ecx + 0x1DEC638], al
		jmp loc_678504
	}
}

const void* const loc_6784DD = (void*)0x6784DD;
void __cdecl Mission_Enter_101_ASM()
{
	__asm
	{
		movzx edx, dword ptr[0x1DEEBBC + edx * 4 - 4]
		cmp byte ptr[ecx + edx + 0x1DEF428], al
		jmp loc_6784DD
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
		cmp esi, dword ptr ds : [0x1DEEBD4]
		jmp loc_6767F5
	}
}

void __cdecl KartRaceEmblem_Display_ASM()
{
	__asm
	{
		push  edx
		movzx edx, byte ptr ds:[0x1D1B814]
		imul  edx, edx, 0x03
		add   ecx, edx
		pop   edx

		fadd  qword ptr ds : [0x904DC0]
	}
}

void __cdecl KartRaceEmblem_Grant_ASM()
{
	__asm
	{
		push  ecx
		movzx ecx, byte ptr ds:[0x1D1B814]
		imul  ecx, ecx, 0x03
		add   edx, ecx
		pop   ecx

		movsx eax, byte ptr ds:[0x1D94422]
	}
}


void StageSelectManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	WriteData<1>(saveLevelDataReadOffset_ptr, saveLevelDataReadOffset);

	WriteJump(static_cast<void*>((void*)0x6766C2), (void*)((int)(&MissionDisplay_Begin_ASM) + 0x4));
	WriteData<1>((void*)0x6766C7, nullop);

	WriteJump(static_cast<void*>((void*)0x67670B), (void*)((int)(&MissionDisplay_CompareActive_ASM) + 0x3));
	WriteData<2>((void*)0x676710, nullop);

	// Most Stages
	WriteJump(static_cast<void*>((void*)0x6784FD), (void*)((int)(&Mission_Enter_ASM) + 0x3));
	WriteData<2>((void*)0x678502, nullop);

	// Route 101
	WriteJump(static_cast<void*>((void*)0x6784D6), (void*)((int)(&Mission_Enter_101_ASM) + 0x3));
	WriteData<2>((void*)0x6784DB, nullop);

	WriteJump(static_cast<void*>((void*)0x6767ee), (void*)((int)(&MissionDisplay_End_ASM) + 0x4));
	WriteData<2>((void*)0x6767F3, nullop);

	InitializeStageSelectData(this->_stageSelectDataMap);
	InitializeStageSelectBossData(this->_stageSelectBossDataMap);
	InitializeItemData(this->_itemData);
	InitializeCharacterItemRanges(this->_characterItemRanges);
	InitializeBossRushChecks(this->_BossRushData);
	UpdateTitleHeaderArrays();
	StageSelectIcons::GetInstance().OnInit(&_stageSelectDataMap);
}

void StageSelectManager::OnFrameFunction()
{
	if (CurrentMenu == Menus::Menus_Main)
	{
		SS_SelectedTile = this->_firstStageIndex;
	}

	HideMenuButtons();
	SetLevelsLockState();
	HandleGoal();
	HandleBossStage();
	LayoutBossGates();
	HandleStageSelectCamera();
	HandleMissionOrder();

	if (CurrentMenu != Menus::Menus_Kart)
	{
		StageSelectIcons::GetInstance().OnFrame();
	}

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

int StageSelectManager::GetGoal()
{
	return this->_goal;
}

void StageSelectManager::SetKartRacesEnabled(int kartRacesEnabled)
{
	this->_kartRacesEnabled = kartRacesEnabled;
}

void StageSelectManager::SetEmblemsForCannonsCore(int emblemsRequired)
{
	_emblemsForCannonsCore = emblemsRequired;
}

int StageSelectManager::GetCannonsCoreEmblemCount() 
{
	return this->_emblemsForCannonsCore;
}

void StageSelectManager::SetRequiredCannonsCoreMissions(bool allMissionsRequired)
{
	this->_requireAllCannonsCoreMissions = allMissionsRequired;
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

std::vector<int> StageSelectManager::GetGateRequirements() 
{
	return this->_gateRequirements;
}

void StageSelectManager::SetChosenMissionsMap(std::map<int, int> map)
{
	this->_chosenMissionsMap = map;
}

void StageSelectManager::SetChosenBossRushMap(std::map<int, int> map)
{
	this->_chosenBossRushMap = map;

	for (int i = BossRushCheck::BRC_BEGIN; i < BossRushCheck::BRC_NUM_CHECKS; i++)
	{
		if (this->_BossRushData.find(i) != this->_BossRushData.end())
		{
			BossRushCheckData& bossData = this->_BossRushData[i];

			int replacementBoss = this->_chosenBossRushMap[bossData.StoryID];
			BossRushCheckData& replacementBossData = this->_BossRushData[BossRushCheck::BRC_BEGIN + replacementBoss];

			WriteData<1>((void*)(bossData.StoryAddress + 1), replacementBossData.Character);
			WriteData<1>((void*)(bossData.StoryAddress + 2), replacementBossData.LevelID);
		}
	}
}

void StageSelectManager::SetMissionCountMap(std::map<int, int> map)
{
	this->_missionCountMap = map;
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
		if (_gateRequirements[i->first] <= NewEmblemCount)
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
		if (NewEmblemCount >= _gateRequirements[i] && GateBossSaveData[i - 1] >= 1)
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
		else
		{
			WriteData<1>((void*)this->_stageSelectDataMap.at(i).UnlockMemAddress, lockByteData);
		}
    }
    if (NewEmblemCount >= _emblemsForCannonsCore)
    {
        WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_CannonCore].UnlockMemAddress, unlockByteData);
    }
    else
    {
        WriteData<1>((void*)this->_stageSelectDataMap[StageSelectStage::SSS_CannonCore].UnlockMemAddress, lockByteData);
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

bool StageSelectManager::IsCannonsCoreComplete()
{
	bool bCannonCoreComplete = true;

	int missionOrderIndex = this->_chosenMissionsMap.at(StageSelectStage::SSS_CannonCore);

	std::array<int, 5> chosenMissionOrder = this->_potentialMissionOrders.at(missionOrderIndex);

	if (this->_requireAllCannonsCoreMissions)
	{
		int missionCount = this->_missionCountMap.at(StageSelectStage::SSS_CannonCore);

		for (int i = 0; i < missionCount; i++)
		{
			int missionIdx = chosenMissionOrder[i] - 1;
			char dataValue = *(char*)(0x01DEE040 + missionIdx);

			if (dataValue <= this->_requiredRank)
			{
				bCannonCoreComplete = false;

				break;
			}
		}
	}
	else
	{
		int missionIdx = chosenMissionOrder[0] - 1;
		char dataValue = *(char*)(0x01DEE040 + missionIdx);

		if (dataValue <= this->_requiredRank)
		{
			bCannonCoreComplete = false;
		}
	}

	return bCannonCoreComplete;
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
	StageSelectModeButton = 0x00;
	KartRaceModeButton = 0x01;
	BossBattleModeButton = 0x01;

	if (this->_kartRacesEnabled == 2)
	{
		// Full Kart Race
		KartRaceModeButton = 0x00;

		WriteCall(static_cast<void*>((void*)0x68B56C), &KartRaceEmblem_Display_ASM);
		WriteData<1>((void*)0x68B571, nullop);

		WriteData<1>((void*)0x68B582, '\x01');
		WriteData<1>((void*)0x68B583, '\x75');

		WriteCall(static_cast<void*>((void*)0x622999), &KartRaceEmblem_Grant_ASM);
		WriteData<2>((void*)0x62299E, nullop);

		WriteData<2>((void*)0x66542F, nullop); // Make Kart Race button always clickable
	}
	else if (this->_kartRacesEnabled == 1)
	{
		KartRaceModeButton = 0x00;
		WriteData<2>((void*)0x66542F, nullop); // Make Kart Race button always clickable
	}

	if (this->_goal == 4 ||
		(this->_goal == 5 && this->IsCannonsCoreComplete()) ||
		(this->_goal == 6 && this->HaveAllChaosEmeralds()))
	{
		BossBattleModeButton = 0x00;
		WriteData<1>((void*)0x1DEFA93, 0x00);
		WriteData<1>((void*)0x1DEFA94, 0x00);
		WriteData<1>((void*)0x1DEFA95, 0x01);

		if (CurrentMenu == Menus::Menus_BossAttack)
		{
			BossBattle_SelectedOption = 0x02;
		}
	}
	else
	{
		WriteData<1>((void*)0x1DEFA93, 0x00);
		WriteData<1>((void*)0x1DEFA94, 0x00);
		WriteData<1>((void*)0x1DEFA95, 0x00);
	}

	if (this->_goal == 3)
	{
		if (SP_SelectedButton == 0x00)
		{
			SP_SelectedButton = 0x02;
		}

		WriteData<2>((void*)0x6653C9, nullop); // Make Stage Select button never clickable
	}
	else
	{
		if (SP_SelectedButton == 0x00)
		{
			SP_SelectedButton = 0x01;
		}

		WriteData<1>((void*)0x6653C9, '\xEB'); // Make Stage Select button always clickable
	}

	EmblemResultsButton = 0x01;
	if (Extras_SelectedButton == 0x02)
	{
		Extras_SelectedButton = 0x03;
	}

	if (CurrentMenu == Menus::Menus_Main)
	{
		if (MainMenu_SelectedOption == 0x01) // 2 Player Battle Button
		{
			if (this->_previousMainMenuSelection == 0x00)
			{
				MainMenu_SelectedOption = 0x02;
			}
			else
			{
				MainMenu_SelectedOption = 0x00;
			}
		}

		this->_previousMainMenuSelection = MainMenu_SelectedOption;
	}
	else if (CurrentMenu == Menus::Menus_Settings)
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

	if (StoryProgressID_3 != 0x0E)
	{
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
	else if (this->_goal == 3)
	{
		HandleGrandPrix();
	}
	else if (this->_goal == 4 || this->_goal == 5 || this->_goal == 6)
	{
		HandleBossRush();
	}
	else if (this->_goal == 7)
	{
		HandleChaosChao();
	}
	else if (this->_goal == 8)
	{
		HandleMinigameMadness();
	}
}

void StageSelectManager::HandleBiolizard()
{
	ArchipelagoManager* apm = &ArchipelagoManager::getInstance();
	if (!apm || !apm->IsInit() || !apm->IsAuth())
	{
		return;
	}

	if (this->_chosenMissionsMap.find(StageSelectStage::SSS_CannonCore) == this->_chosenMissionsMap.end())
	{
		return;
	}

	if (this->_missionCountMap.find(StageSelectStage::SSS_CannonCore) == this->_missionCountMap.end())
	{
		return;
	}

	if (this->IsCannonsCoreComplete())
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
	bool bHaveChaosEmeralds = this->HaveAllChaosEmeralds();

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
				WriteData<1>((void*)0x1DEB31E, 0x04);
				WriteData<1>((void*)0x1DEB31F, 0x04);
				WriteData<1>((void*)0x1DEB320, 0x03);

				WriteData<1>((void*)0x174B044, 0x0C);

				WriteData<1>((void*)0x173A5B4, 0xCF);
				WriteData<1>((void*)0x173A5B5, 0x00);
				WriteData<1>((void*)0x173A5B6, 0xFF);
				WriteData<1>((void*)0x173A5B7, 0xFF);
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

void StageSelectManager::HandleGrandPrix()
{
	if (this->_victorySent)
	{
		return;
	}

	LocationManager* locationManager = &LocationManager::getInstance();
	if (locationManager->AreAllRacesComplete())
	{
		MessageQueue* messageQueue = &MessageQueue::GetInstance();
		std::string msg = "Victory!";
		messageQueue->AddMessage(msg);

		ArchipelagoManager* apm = &ArchipelagoManager::getInstance();
		apm->SendStoryComplete();

		this->_victorySent = true;
	}
}

void StageSelectManager::HandleBossRush()
{
	if (StoryProgressID_3 == 0x0E)
	{
		if (GameState == GameStates_GoToNextLevel)
		{
			for (int i = BossRushCheck::BRC_BEGIN; i < BossRushCheck::BRC_NUM_CHECKS; i++)
			{
				if (this->_BossRushData.find(i) != this->_BossRushData.end())
				{
					BossRushCheckData& checkData = this->_BossRushData[i];

					if (StoryProgressID_1 > checkData.StoryID)
					{
						char dataValue = *(char*)checkData.Address;
						char bitFlag = (char)(0x01 << checkData.AddressBit);
						char newDataValue = dataValue | bitFlag;

						WriteData<1>((void*)checkData.Address, newDataValue);
					}
				}
			}
		}
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

	if (this->_victorySent)
	{
		return;
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

			this->_victorySent = true;
		}
	}
}

void StageSelectManager::HandleChaosChao()
{
	if (this->_victorySent)
	{
		return;
	}

	if (CurrentLevel != LevelIDs_ChaoWorld)
	{
		return;
	}

	for (int chaoIdx = 0; chaoIdx < 37; chaoIdx++)
	{
		ChaoDataBase chaoData = ChaoSlots[chaoIdx].data;

		if (chaoData.TimescaleTimer == 0)
		{
			// This Chao does not exist yet
			continue;
		}

		if (chaoData.Type == ChaoType::ChaoType_Hero_Chaos ||
			chaoData.Type == ChaoType::ChaoType_Neutral_Chaos ||
			chaoData.Type == ChaoType::ChaoType_Dark_Chaos)
		{
			MessageQueue* messageQueue = &MessageQueue::GetInstance();
			std::string msg = "Victory!";
			messageQueue->AddMessage(msg);

			ArchipelagoManager* apm = &ArchipelagoManager::getInstance();
			apm->SendStoryComplete();

			this->_victorySent = true;

			return;
		}
	}
}

void StageSelectManager::HandleMinigameMadness()
{
	if (this->_victorySent)
	{
		return;
	}

	ArchipelagoManager* apm = &ArchipelagoManager::getInstance();
	if (!apm || !apm->IsInit() || !apm->IsAuth())
	{
		return;
	}

	if (this->_chosenMissionsMap.find(StageSelectStage::SSS_CannonCore) == this->_chosenMissionsMap.end())
	{
		return;
	}

	if (this->_missionCountMap.find(StageSelectStage::SSS_CannonCore) == this->_missionCountMap.end())
	{
		return;
	}

	if (this->HaveAllMinigames())
	{
		// Finalhazard Tile
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
		TimeStopped = 1;

		if (GameState == GameStates_GoToNextLevel)
		{
			MessageQueue* messageQueue = &MessageQueue::GetInstance();
			std::string msg = "Victory!";
			messageQueue->AddMessage(msg);

			ArchipelagoManager* apm = &ArchipelagoManager::getInstance();
			apm->SendStoryComplete();

			return;
		}

		if (TimerMinutes == 0 && TimerSeconds < 5)
		{
			WriteData<1>((void*)0x1DEB060, 0xD0);
			WriteData<1>((void*)0x1DEB061, 0x00);
			WriteData<1>((void*)0x1DEB062, 0x00);
			WriteData<1>((void*)0x1DEB063, 0x00);
			WriteData<1>((void*)0x1DEB064, 0xD1);
			WriteData<1>((void*)0x1DEB065, 0x00);
			WriteData<1>((void*)0x1DEB066, 0x00);
			WriteData<1>((void*)0x1DEB067, 0x00);

			WriteData<1>((void*)0x1DEB31E, 0x06);
			WriteData<1>((void*)0x1DEB31F, 0x06);
			WriteData<1>((void*)0x1DEB320, 0x03);

			WriteData<1>((void*)0x174B044, 0x0C);
		}

		// TODO: Make this not re-proc at the end

		MinigameManager* minigameManager = &MinigameManager::GetInstance();
		if (minigameManager->state == MinigameState::MGS_None)
		{
			minigameManager->StartMinigame(ItemValue::IV_Maria);
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
	if (GameMode == GameMode::GameMode_Advertise &&
		GameState != GameStates::GameStates_Ingame &&
		GameState != GameStates::GameStates_Pause &&
		GameState != GameStates::GameStates_Loading &&
		CurrentLevel == LevelIDs::LevelIDs_ChaoWorld)
	{
		CurrentLevel = 0;
	}

	//Make sure first mission displays as active
	WriteData<1>((void*)0x1DEEBB8, 0x30);

	int currentTileStageIndex = this->TileIDtoStageIndex[SS_SelectedTile];
	bool isBossStage = StageSelectIcons::GetInstance().IsCurrentTileBoss();
	if (isBossStage || this->IsCurrentLevelChaoWorld())
	{
		for (int i = 0; i < 5; i++)
		{
			WriteData<1>((void*)((int)(loc_Mission_1)+i * 4), (char)(i));
		}
		WriteData<1>((void*)((int)(loc_mission_count)), 1);

		// Handle "1st" highlighting
		WriteData<1>((void*)(0xC69218 + 8), 0x00);
		WriteData<1>((void*)(0xC69218 + 10), 0x00);
		WriteData<1>((void*)(0xC69218 + 12), 0x32);
		WriteData<1>((void*)(0xC69218 + 14), 0x33);

		if (*(char*)(0x1DEF5C7) > 0)
		{
			// Highest bit of "Flying Dog" Score Save Byte
			// Overlaps with Centiseconds of 3rd Place Intermediate Kart Race time
			// Crashes at Flying Dog SS tile entry when non-zero
			WriteData<1>((void*)(0x1DEF5C7), 0x00);
		}
	}
	else if (CurrentMenu == Menus::Menus_StageSelect && currentTileStageIndex < this->_chosenMissionsMap.size())
	{
		int missionOrderIndex = this->_chosenMissionsMap.at(currentTileStageIndex);

		if (missionOrderIndex < this->_potentialMissionOrders.size())
		{
			std::array<int, 5> chosenMissionOrder = this->_potentialMissionOrders.at(missionOrderIndex);

			ActiveMission = chosenMissionOrder[SS_SelectedMission] - 1;

			for (int i = 0; i < 5; i++)
			{
				WriteData<1>((void*)((int)(loc_Mission_1) + i*4), (char)(chosenMissionOrder[i] - 1));

				//Update 1st mission anim atlas position
				if (chosenMissionOrder[i] == 1 && i > 0 ) 
				{
					int prevMission = chosenMissionOrder[i - 1];
					char value = *(char*)(this->_stageSelectDataMap.at(currentTileStageIndex).UnlockMemAddress - 6 + prevMission);

					if (currentTileStageIndex == SSS_Route101 || currentTileStageIndex == SSS_Route280)
					{
						value = *(char*)(this->_stageSelectDataMap.at(currentTileStageIndex).UnlockMemAddress - 0x13 + prevMission);
					}

					if (value == 0x00) 
					{
						WriteData<1>((void*)(0xC69218 + 8), 0x96);
						WriteData<1>((void*)(0xC69218 + 10), 0x96);
						WriteData<1>((void*)(0xC69218 + 12), 0xC7);
						WriteData<1>((void*)(0xC69218 + 14), 0xC8);
					} 
					else
					{
						WriteData<1>((void*)(0xC69218 + 8), 0x00);
						WriteData<1>((void*)(0xC69218 + 10), 0x00);
						WriteData<1>((void*)(0xC69218 + 12), 0x32);
						WriteData<1>((void*)(0xC69218 + 14), 0x33);
					}
				}
				else if (chosenMissionOrder[i] == 1)
				{
					WriteData<1>((void*)(0xC69218 + 8), 0x00);
					WriteData<1>((void*)(0xC69218 + 10), 0x00);
					WriteData<1>((void*)(0xC69218 + 12), 0x32);
					WriteData<1>((void*)(0xC69218 + 14), 0x33);
				}
			}

			WriteData<1>((void*)((int)(loc_mission_count)), this->_missionCountMap[currentTileStageIndex]);
			WriteData<1>((void*)(0x677025), this->_missionCountMap[currentTileStageIndex]);
			WriteData<1>((void*)(0x676E47), this->_missionCountMap[currentTileStageIndex]);
		}
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			WriteData<1>((void*)((int)(loc_Mission_1)+i * 4), (char)(i));
		}
		WriteData<1>((void*)((int)(loc_mission_count)), 5);

		// Handle "1st" highlighting
		WriteData<1>((void*)(0xC69218 + 8), 0x00);
		WriteData<1>((void*)(0xC69218 + 10), 0x00);
		WriteData<1>((void*)(0xC69218 + 12), 0x32);
		WriteData<1>((void*)(0xC69218 + 14), 0x33);
	}
}

bool StageSelectManager::HaveAllChaosEmeralds()
{
	for (int i = 0; i < 7; i++)
	{
		unsigned char dataValue = *(unsigned char*)(0x01DEEAF8 + i);

		if (dataValue == 0)
		{
			return false;
		}
	}

	return true;
}

bool StageSelectManager::HaveAllMinigames()
{
	for (int i = 0; i < 9; i++)
	{
		unsigned char dataValue = *(unsigned char*)(0x01DEEAFF + i);

		char bitFlag = (char)(0x01 << 0x01);

		if ((dataValue & bitFlag) == 0x00)
		{
			return false;
		}
	}

	return true;
}

bool StageSelectManager::IsCurrentLevelChaoWorld()
{
	int currentTileStageIndex = this->TileIDtoStageIndex[SS_SelectedTile];
	if (currentTileStageIndex == StageSelectStage::SSS_ChaoGarden)
	{
		return true;
	}

	if (CurrentLevel == LevelIDs::LevelIDs_ChaoWorld && LastLevel != LevelIDs::LevelIDs_ChaoWorld && LastLevel != 0)
	{
		return true;
	}

	return false;
}
