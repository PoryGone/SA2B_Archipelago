#include "../pch.h"
#include "LocationManager.h"
#include "LocationData.h"
#include "../Utilities/MessageQueue.h"

void LocationManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	this->_helperFunctions = &helperFunctions;
	this->_archipelagoManager = &ArchipelagoManager::getInstance();

	this->_LevelClearData.clear();

	InitializeLevelClearChecks(this->_LevelClearData);
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
}

void LocationManager::SetRequiredRank(int requiredRank)
{
	this->_requiredRank = requiredRank;
}
