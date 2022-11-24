#include "../pch.h"
#include "LocationManager.h"
#include "LocationData.h"
#include "StageSelectData.h"
#include "../Utilities/MessageQueue.h"


static Trampoline* sub_6E9C00_trampoline; // Chao Key

// Chao Key Trampoline
void sub_6E9C00_original()
{
	void* target = sub_6E9C00_trampoline->Target();
	__asm
	{
		call target
	}
}

static void __cdecl sub_6E9C00_cpp()
{
	LocationManager::getInstance().SendChaoKeyLocationCheck();

	sub_6E9C00_original();
}
// End Chao Key Trampoline

// Gold Beetle "Trampoline"
static void __cdecl GoldBeetleDestroyed()
{
	LocationManager::getInstance().SendGoldBeetleLocationCheck();
	if (MainCharObj2[0] && (MainCharObj2[0]->Powerups & Powerups_Invincibility) != 0)
	{
		AddScore(2000);
	}
	else
	{
		AddScore(2000);
	}
}
// End Gold Beetle "Trampoline"

void LocationManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	this->_helperFunctions = &helperFunctions;
	this->_archipelagoManager = &ArchipelagoManager::getInstance();

	// Chao Key Trampoline
	sub_6E9C00_trampoline = new Trampoline(reinterpret_cast<intptr_t>((void*)0x006E9C00),
										   static_cast<intptr_t>(0x006E9C05),
										   &sub_6E9C00_cpp);

	// Gold Beetle "Trampoline"
	WriteCall(static_cast<void*>((void*)0x00505F48), &GoldBeetleDestroyed);

	InitializeLevelClearChecks(this->_LevelClearData);
	InitializeChaoKeyChecks(this->_ChaoKeyData);
	InitializePipeChecks(this->_PipeData);
	InitializeHiddenChecks(this->_HiddenData);
	InitializeGoldBeetleChecks(this->_GoldBeetleData);
	InitializeChaoGardenChecks(this->_ChaoGardenData);
	InitializeChaoRacePacks(this->_ChaoRacePacks);
}

void LocationManager::OnFrameFunction()
{
	if (!this->_archipelagoManager->IsInit() || !this->_archipelagoManager->IsAuth())
	{
		return;
	}

	this->_timer++;

	if (this->_timer > MEMORY_CHECK_TIME)
	{
		this->_timer = 0;

		this->OnFrameLevelClears();
		this->OnFrameChaoKeys();
		this->OnFramePipes();
		this->OnFrameHidden();
		this->OnFrameGoldBeetles();
	}

	this->OnFrameWhistle();
	this->OnFrameChaoGarden();
}

void LocationManager::OnFrameLevelClears()
{
	for (int i = 0; i < LevelClearCheck::LCC_NUM_CHECKS; i++)
	{
		if (this->_LevelClearData.find(i) != this->_LevelClearData.end())
		{
			LevelClearCheckData& checkData = this->_LevelClearData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				int requiredValue = 0;

				if (i <= LevelClearCheck::LCC_CannonCore_5)
				{
					requiredValue = this->_requiredRank;
				}

				if (dataValue > requiredValue)
				{
					if (this->_archipelagoManager)
					{
						this->_archipelagoManager->SendItem(i);

						checkData.CheckSent = true;
					}
				}
				else if (dataValue > checkData.PrevValue)
				{
					checkData.PrevValue = dataValue;

					if (GameState != GameStates_Inactive)
					{
						MessageQueue::GetInstance().AddMessage("Mission Rank too low");
					}
				}
			}
			else
			{
				// Capture offline collects, show the proper Rank for them
				char dataValue = *(char*)checkData.Address;

				int requiredValue = 0;

				if (i <= LevelClearCheck::LCC_CannonCore_5)
				{
					requiredValue = this->_requiredRank;
				}

				if (dataValue <= requiredValue)
				{
					WriteData<1>((void*)checkData.Address, requiredValue + 1);
				}
			}
		}
	}
}

void LocationManager::OnFrameChaoKeys()
{
	if (!this->_chaoKeysEnabled)
	{
		return;
	}

	for (int i = ChaoKeyCheck::CKC_BEGIN; i < ChaoKeyCheck::CKC_NUM_CHECKS; i++)
	{
		if (this->_ChaoKeyData.find(i) != this->_ChaoKeyData.end())
		{
			ChaoKeyCheckData& checkData = this->_ChaoKeyData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
				{
					if (this->_archipelagoManager)
					{
						this->_archipelagoManager->SendItem(i);

						checkData.CheckSent = true;
					}
				}
			}
			else
			{
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameWhistle()
{
	this->_whistleTimer = this->_whistleTimer > 0 ? this->_whistleTimer - 1 : 0;

	if (MainCharObj1[0] && MainCharObj1[0]->Action == Actions::Action_Whistle)
	{
		if (this->_whistleTimer <= 0)
		{
			this->_whistleTimer = WHISTLE_CHECK_TIME;
			this->SendPipeLocationCheck();
			this->SendHiddenLocationCheck();
		}
	}
}

void LocationManager::OnFramePipes()
{
	if (!this->_pipesEnabled)
	{
		return;
	}

	for (int i = PipeCheck::PC_BEGIN; i < PipeCheck::PC_NUM_CHECKS; i++)
	{
		if (this->_PipeData.find(i) != this->_PipeData.end())
		{
			PipeCheckData& checkData = this->_PipeData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
				{
					if (this->_archipelagoManager)
					{
						this->_archipelagoManager->SendItem(i);

						checkData.CheckSent = true;
					}
				}
			}
			else
			{
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameHidden()
{
	if (!this->_hiddensEnabled)
	{
		return;
	}

	for (int i = HiddenCheck::HC_BEGIN; i < HiddenCheck::HC_NUM_CHECKS; i++)
	{
		if (this->_HiddenData.find(i) != this->_HiddenData.end())
		{
			HiddenCheckData& checkData = this->_HiddenData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
				{
					if (this->_archipelagoManager)
					{
						this->_archipelagoManager->SendItem(i);

						checkData.CheckSent = true;
					}
				}
			}
			else
			{
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameGoldBeetles()
{
	if (!this->_goldBeetlesEnabled)
	{
		return;
	}

	for (int i = GoldBeetleCheck::GBC_BEGIN; i < GoldBeetleCheck::GBC_NUM_CHECKS; i++)
	{
		if (this->_GoldBeetleData.find(i) != this->_GoldBeetleData.end())
		{
			GoldBeetleCheckData& checkData = this->_GoldBeetleData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
				{
					if (this->_archipelagoManager)
					{
						this->_archipelagoManager->SendItem(i);

						checkData.CheckSent = true;
					}
				}
			}
			else
			{
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameChaoGarden()
{
	if (!this->_chaoEnabled)
	{
		// Don't do any Chao stuff if no Chao checks are on
		return;
	}

	// Make sure Hero/Dark Gardens are always unlocked
	ChaoGardensUnlocked = 0x56;

	//Make All Characters have Chao Garden Access
	WriteData<8>((void*)0x1DEF829, 0x01);

	// Handle Separate Chao Saves
	std::string chaoFileName = ArchipelagoManager::getInstance().GetSeedName().substr(0, 11);

	for (int i = 0; i < 11; i++)
	{
		WriteData<1>((void*)(0x8ACF4B + i), chaoFileName[i]);
		WriteData<1>((void*)(0xC70E5C + i), chaoFileName[i]);
		WriteData<1>((void*)(0x1366067 + i), chaoFileName[i]);
	}

	if (CurrentLevel != LevelIDs::LevelIDs_ChaoWorld)
	{
		// Only check the data while in Chao World, otherwise it may be wrong
		return;
	}

	this->_chaoTimer++;

	if (this->_chaoTimer > CHAO_MEMORY_CHECK_TIME)
	{
		this->_chaoTimer = 0;

		for (int i = ChaoGardenCheck::CGC_BEGIN; i <= ChaoGardenCheck::CGC_END_RACE; i++)
		{
			if (this->_ChaoGardenData.find(i) != this->_ChaoGardenData.end())
			{
				ChaoGardenCheckData& checkData = this->_ChaoGardenData[i];

				if (!checkData.CheckSent)
				{
					char dataValue = *(char*)checkData.Address;

					if (dataValue == 0xFF)
					{
						continue;
					}

					int requiredValue = checkData.Index;

					if (dataValue >= requiredValue)
					{
						if (this->_archipelagoManager)
						{
							this->_archipelagoManager->SendItem(i);

							checkData.CheckSent = true;
						}
					}
				}
			}
		}

		// Move Race Data over from AP Storage
		for (int address = 0x01DEC7C0; address <= 0x01DEC7CD; address++)
		{
			char dataValue = *(char*)address;
			char currentRaceProgress = -1;

			for (int index = 0; index <= 7; index++)
			{
				// Handle Challenge Race Upper bits
				if (address == 0x01DEC7CB && index >= 4)
				{
					break;
				}

				if (((dataValue) & (1 << index)) == 0)
				{
					break;
				}

				currentRaceProgress++;
			}

			// Handle Challenge Race Upper bits
			if (address == 0x01DEC7CA)
			{
				char dataValue = *(char*)(address + 1);
				for (int index2 = 4; index2 <= 7; index2++)
				{
					if (((dataValue) & (1 << index2)) == 0)
					{
						break;
					}

					if (currentRaceProgress < 7)
					{
						break;
					}

					currentRaceProgress++;
				}
			}

			if (currentRaceProgress != (char)-1)
			{
				WriteData<1>((void*)(address - CHAO_LOCATION_STORAGE_OFFSET), currentRaceProgress);
				WriteData<1>((void*)(address - CHAO_LOCATION_STORAGE_OFFSET - CHAO_LOCATION_INTERNAL_OFFSET), currentRaceProgress);
			}
		}

		for (int i = ChaoGardenCheck::CGC_Beginner_Karate; i <= ChaoGardenCheck::CGC_Super_Karate; i++)
		{
			if (this->_ChaoGardenData.find(i) != this->_ChaoGardenData.end())
			{
				ChaoGardenCheckData& checkData = this->_ChaoGardenData[i];

				if (!checkData.CheckSent)
				{
					char dataValue = *(char*)checkData.Address;

					if (dataValue > 0x00)
					{
						if (this->_archipelagoManager)
						{
							this->_archipelagoManager->SendItem(i);

							checkData.CheckSent = true;
						}
					}
				}
			}
		}
	}
}

void LocationManager::CheckLocation(int location_id)
{
	if (this->_LevelClearData.find(location_id) != this->_LevelClearData.end())
	{
		LevelClearCheckData& checkData = this->_LevelClearData[location_id];

		if (location_id >= LCC_Boss_1)
		{
			// Don't Collect Bosses
			return;
		}

		if (location_id == LCC_CannonCore_1 ||
			location_id == LCC_CannonCore_2 ||
			location_id == LCC_CannonCore_3 ||
			location_id == LCC_CannonCore_4 ||
			location_id == LCC_CannonCore_5)
		{
			// Don't Collect any Cannon's Core Missions
			return;
		}

		checkData.CheckSent = true;

		char dataValue = *(char*)checkData.Address;

		if (dataValue > this->_requiredRank)
		{
			// Don't Overwrite existing Rankings
			return;
		}

		WriteData<1>((void*)checkData.Address, this->_requiredRank + 1);
	}
	else if (this->_ChaoGardenData.find(location_id) != this->_ChaoGardenData.end())
	{
		if (location_id >= ChaoGardenCheck::CGC_Beginner_Karate && location_id <= ChaoGardenCheck::CGC_Super_Karate)
		{
			ChaoGardenCheckData& checkData = this->_ChaoGardenData[location_id];

			checkData.CheckSent = true;

			WriteData<1>((void*)checkData.Address, 0x01);
		}
		else
		{
			ChaoGardenCheckData& checkData = this->_ChaoGardenData[location_id];

			checkData.CheckSent = true;

			// Handle Challenge Race Upper bits
			int writeAddress = (checkData.Index <= 7) ? (checkData.Address + CHAO_LOCATION_STORAGE_OFFSET) : (checkData.Address + CHAO_LOCATION_STORAGE_OFFSET + 1);
			int writeIndex   = (checkData.Index <= 7) ? (checkData.Index) : (checkData.Index - 4);

			char dataValue = *(char*)writeAddress;

			dataValue = (dataValue | (char)(1 << writeIndex));

			WriteData<1>((void*)writeAddress, dataValue);

			// If only Prize races give checks, unlock preceding races too on collect
			if (this->_racesPacked)
			{
				if (this->_ChaoRacePacks.find(location_id) != this->_ChaoRacePacks.end())
				{
					std::vector<int> racePack = this->_ChaoRacePacks[location_id];
					for (unsigned int i = 0; i < racePack.size(); i++)
					{
						if (this->_ChaoGardenData.find(racePack[i]) != this->_ChaoGardenData.end())
						{
							ChaoGardenCheckData& packCheckData = this->_ChaoGardenData[racePack[i]];

							packCheckData.CheckSent = true;

							// Handle Challenge Race Upper bits
							int packWriteAddress = (packCheckData.Index <= 7) ? (packCheckData.Address + CHAO_LOCATION_STORAGE_OFFSET) : (packCheckData.Address + CHAO_LOCATION_STORAGE_OFFSET + 1);
							int packWriteIndex   = (packCheckData.Index <= 7) ? packCheckData.Index : packCheckData.Index - 4;

							char packDataValue = *(char*)packWriteAddress;

							packDataValue = (packDataValue | (char)(1 << packWriteIndex));

							WriteData<1>((void*)packWriteAddress, packDataValue);
						}
					}
				}
			}
		}
	}
	else if (this->_ChaoKeyData.find(location_id) != this->_ChaoKeyData.end())
	{
		ChaoKeyCheckData& checkData = this->_ChaoKeyData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
	else if (this->_PipeData.find(location_id) != this->_PipeData.end())
	{
		PipeCheckData& checkData = this->_PipeData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
	else if (this->_HiddenData.find(location_id) != this->_HiddenData.end())
	{
		HiddenCheckData& checkData = this->_HiddenData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
	else if (this->_GoldBeetleData.find(location_id) != this->_GoldBeetleData.end())
	{
		GoldBeetleCheckData& checkData = this->_GoldBeetleData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
}

void LocationManager::SetRequiredRank(int requiredRank)
{
	this->_requiredRank = requiredRank;
}

void LocationManager::SetChaoKeysEnabled(bool chaoKeysEnabled)
{
	this->_chaoKeysEnabled = chaoKeysEnabled;

	if (this->_chaoKeysEnabled)
	{
		// Overwrite vanilla Chao Key Behavior
		WriteData<7>((void*)0x006E9C05, '\x90');

		WriteData<1>((void*)0x006E9C31, '\x04');
		WriteData<1>((void*)0x006E9C32, '\xB0');
		WriteData<1>((void*)0x006E9C33, '\x74');

		WriteData<1>((void*)0x006E9C36, '\x94');

		WriteData<6>((void*)0x006E9C4A, '\x90');

		WriteData<1>((void*)0x006E9C52, '\x04');
		WriteData<1>((void*)0x006E9C53, '\xB0');
		WriteData<1>((void*)0x006E9C54, '\x74');
		WriteData<1>((void*)0x006E9C56, '\x01');

		WriteData<1>((void*)0x006E9C58, '\x84');
	}
}

void LocationManager::SetPipesEnabled(bool pipesEnabled)
{
	this->_pipesEnabled = pipesEnabled;
}

void LocationManager::SetHiddensEnabled(bool hiddenEnabled)
{
	this->_hiddensEnabled = hiddenEnabled;
}

void LocationManager::SetGoldBeetlesEnabled(bool goldBeetlesEnabled)
{
	this->_goldBeetlesEnabled = goldBeetlesEnabled;
}

void LocationManager::SetRacesPacked(bool racesPacked)
{
	this->_racesPacked = racesPacked;
}

void LocationManager::SetChaoEnabled(bool chaoEnabled)
{
	this->_chaoEnabled = chaoEnabled;
}

void LocationManager::SetRequiredCannonsCoreMissions(bool allMissionsRequired)
{
	this->_requireAllCannonsCoreMissions = allMissionsRequired;
}

void LocationManager::ResetLocations()
{
	for (auto& pair : this->_LevelClearData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_ChaoGardenData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_ChaoKeyData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_PipeData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_HiddenData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_GoldBeetleData)
	{
		pair.second.CheckSent = false;
	}
}


float dist(NJS_POINT3 a, NJS_POINT3 b)
{
	return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2) + pow((b.z - a.z), 2));
}

void LocationManager::SendChaoKeyLocationCheck()
{
	if (!this->_chaoKeysEnabled)
	{
		return;
	}

	if (MainCharObj1[0] == NULL)
	{
		return;
	}

	for (int i = ChaoKeyCheck::CKC_BEGIN; i < ChaoKeyCheck::CKC_NUM_CHECKS; i++)
	{
		if (this->_ChaoKeyData.find(i) != this->_ChaoKeyData.end())
		{
			ChaoKeyCheckData& checkData = this->_ChaoKeyData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				if (dist(checkData.Position, MainCharObj1[0]->Position) < checkData.Range)
				{
					char dataValue = *(char*)checkData.Address;

					if (dataValue != 0x01)
					{
						WriteData<1>((void*)checkData.Address, 0x01);
					}

					return;
				}
			}
		}
	}
}

void LocationManager::SendPipeLocationCheck()
{
	if (!this->_pipesEnabled)
	{
		return;
	}

	if (MainCharObj1[0] == NULL)
	{
		return;
	}

	for (int i = PipeCheck::PC_BEGIN; i < PipeCheck::PC_NUM_CHECKS; i++)
	{
		if (this->_PipeData.find(i) != this->_PipeData.end())
		{
			PipeCheckData& checkData = this->_PipeData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				if (dist(checkData.Position, MainCharObj1[0]->Position) < checkData.Range)
				{
					char dataValue = *(char*)checkData.Address;

					if (dataValue != 0x01)
					{
						WriteData<1>((void*)checkData.Address, 0x01);
					}

					return;
				}
			}
		}
	}
}

void LocationManager::SendHiddenLocationCheck()
{
	if (!this->_hiddensEnabled)
	{
		return;
	}

	if (MainCharObj1[0] == NULL)
	{
		return;
	}

	for (int i = HiddenCheck::HC_BEGIN; i < HiddenCheck::HC_NUM_CHECKS; i++)
	{
		if (this->_HiddenData.find(i) != this->_HiddenData.end())
		{
			HiddenCheckData& checkData = this->_HiddenData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				if (dist(checkData.Position, MainCharObj1[0]->Position) < checkData.Range)
				{
					char dataValue = *(char*)checkData.Address;

					if (dataValue != 0x01)
					{
						WriteData<1>((void*)checkData.Address, 0x01);
					}

					return;
				}
			}
		}
	}
}

void LocationManager::SendGoldBeetleLocationCheck()
{
	if (!this->_goldBeetlesEnabled)
	{
		return;
	}

	for (int i = GoldBeetleCheck::GBC_BEGIN; i < GoldBeetleCheck::GBC_NUM_CHECKS; i++)
	{
		if (this->_GoldBeetleData.find(i) != this->_GoldBeetleData.end())
		{
			GoldBeetleCheckData& checkData = this->_GoldBeetleData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}

				return;
			}
		}
	}
}

std::vector<int> LocationManager::GetChaoKeyLocationsForLevel(int levelID)
{
	std::vector<int> result;

	/*if (this->_chaoKeysEnabled)
	{
		int checkOffset = 0x400;

		for (int j = 0; j < 6; j++)
		{
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_ChaoKeyData.find(locationID) != this->_ChaoKeyData.end())
			{
				ChaoKeyCheckData& checkData = this->_ChaoKeyData[locationID];
				result.push_back(checkData.Address);
			}
		}
	}*/

	int checkOffset = 0x400;

	for (int j = 0; j < 6; j++)
	{
		int locationID = checkOffset + (j * 0x20) + levelID;
		if (this->_ChaoKeyData.find(locationID) != this->_ChaoKeyData.end())
		{
			ChaoKeyCheckData& checkData = this->_ChaoKeyData[locationID];
			result.push_back(checkData.Address);
		}
	}

	return result;
}

std::vector<int> LocationManager::GetPipeLocationsForLevel(int levelID)
{
	std::vector<int> result;

	/*if (this->_pipesEnabled)
	{
		int checkOffset = 0x500;

		for (int j = 0; j < 6; j++)
		{
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_PipeData.find(locationID) != this->_PipeData.end())
			{
				PipeCheckData& checkData = this->_PipeData[locationID];
				result.push_back(checkData.Address);
			}
		}
	}*/

	int checkOffset = 0x500;

	for (int j = 0; j < 6; j++)
	{
		int locationID = checkOffset + (j * 0x20) + levelID;
		if (this->_PipeData.find(locationID) != this->_PipeData.end())
		{
			PipeCheckData& checkData = this->_PipeData[locationID];
			result.push_back(checkData.Address);
		}
	}

	return result;
}

std::vector<int> LocationManager::GetHiddenLocationsForLevel(int levelID)
{
	std::vector<int> result;

	/*if (this->_hiddensEnabled)
	{
		int checkOffset = 0x700;

		for (int j = 0; j < 5; j++)
		{
			int locationID = checkOffset + (j*0x20) + levelID;
			if (this->_HiddenData.find(locationID) != this->_HiddenData.end())
			{
				HiddenCheckData& checkData = this->_HiddenData[locationID];
				result.push_back(checkData.Address);
			}
		}
	}*/

	int checkOffset = 0x700;

	for (int j = 0; j < 5; j++)
	{
		int locationID = checkOffset + (j * 0x20) + levelID;
		if (this->_HiddenData.find(locationID) != this->_HiddenData.end())
		{
			HiddenCheckData& checkData = this->_HiddenData[locationID];
			result.push_back(checkData.Address);
		}
	}

	return result;
}

std::vector<int> LocationManager::GetGoldBeetleLocationsForLevel(int levelID)
{
	std::vector<int> result;

	/*if (this->_goldBeetlesEnabled)
	{
		int checkOffset = 0x600;

		int locationID = checkOffset + levelID;
		if (this->_GoldBeetleData.find(locationID) != this->_GoldBeetleData.end())
		{
			GoldBeetleCheckData& checkData = this->_GoldBeetleData[locationID];
			result.push_back(checkData.Address);
		}
	}*/

	int checkOffset = 0x600;

	int locationID = checkOffset + levelID;
	if (this->_GoldBeetleData.find(locationID) != this->_GoldBeetleData.end())
	{
		GoldBeetleCheckData& checkData = this->_GoldBeetleData[locationID];
		result.push_back(checkData.Address);
	}

	return result;
}
