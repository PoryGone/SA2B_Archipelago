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
	if (CurrentLevel != LevelIDs::LevelIDs_ChaoWorld)
	{
		// Only check the data while in Chao World, otherwise it may be wrong
		return;
	}

	this->_chaoTimer++;

	if (this->_chaoTimer > CHAO_MEMORY_CHECK_TIME)
	{
		this->_chaoTimer = 0;

		for (int i = ChaoGardenCheck::CGC_BEGIN; i < ChaoGardenCheck::CGC_END; i++)
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
			int currentRaceProgress = -1;

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
				for (int index = 4; index <= 7; index++)
				{
					if (((dataValue) & (1 << index)) == 0)
					{
						break;
					}

					currentRaceProgress++;
				}
			}

			if (currentRaceProgress > -1)
			{
				WriteData<1>((void*)(address - CHAO_LOCATION_STORAGE_OFFSET), currentRaceProgress);
				WriteData<1>((void*)(address - CHAO_LOCATION_STORAGE_OFFSET - CHAO_LOCATION_INTERNAL_OFFSET), currentRaceProgress);
			}
		}
	}
}

void LocationManager::CheckLocation(int location_id)
{
	if (this->_LevelClearData.find(location_id) != this->_LevelClearData.end())
	{
		LevelClearCheckData& checkData = this->_LevelClearData[location_id];

		if (location_id == LCC_CannonCore_1)
		{
			// Don't Collect Cannon's Core 1
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
		ChaoGardenCheckData& checkData = this->_ChaoGardenData[location_id];

		checkData.CheckSent = true;

		int writeAddress = checkData.Index <= 7 ? (checkData.Address + CHAO_LOCATION_STORAGE_OFFSET) : (checkData.Address + CHAO_LOCATION_STORAGE_OFFSET + 1);
		int writeIndex   = checkData.Index <= 7 ? (checkData.Index) : (checkData.Index - 4);

		WriteData<1>((void*)(writeAddress), (1<<writeIndex));

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

						int packWriteAddress = packCheckData.Index <= 7 ? (packCheckData.Address + CHAO_LOCATION_STORAGE_OFFSET) : (packCheckData.Address + CHAO_LOCATION_STORAGE_OFFSET + 1);
						int packWriteIndex   = packCheckData.Index <= 7 ? packCheckData.Index : packCheckData.Index - 4;

						WriteData<1>((void*)(packWriteAddress), (1<<packWriteIndex));
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
