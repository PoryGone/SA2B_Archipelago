#include "../pch.h"
#include "LocationManager.h"
#include "LocationData.h"
#include "../Utilities/MessageQueue.h"

void LocationManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	this->_helperFunctions = &helperFunctions;
	this->_archipelagoManager = &ArchipelagoManager::getInstance();

	InitializeLevelClearChecks(this->_LevelClearData);
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

	this->OnFrameChaoGarden();
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

		if (location_id == LCC_CannonCore_1 || location_id >= LCC_Boss_1)
		{
			// Don't Collect Cannon's Core 1 or Bosses
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

			if (checkData.CheckSent)
			{
				return;
			}

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
}

void LocationManager::SetRequiredRank(int requiredRank)
{
	this->_requiredRank = requiredRank;
}

void LocationManager::SetRacesPacked(bool racesPacked)
{
	this->_racesPacked = racesPacked;
}

void LocationManager::SetChaoEnabled(bool chaoEnabled)
{
	this->_chaoEnabled = chaoEnabled;
}
