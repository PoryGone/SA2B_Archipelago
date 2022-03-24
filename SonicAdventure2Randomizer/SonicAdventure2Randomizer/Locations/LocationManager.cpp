#include "../pch.h"
#include "LocationManager.h"
#include "LocationData.h"

void LocationManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	this->_helperFunctions = &helperFunctions;
	this->_archipelagoManager = &ArchipelagoManager::getInstance();

	this->_LevelClearData.clear();

	InitializeLevelClearChecks(this->_LevelClearData);
}

void LocationManager::OnFrameFunction()
{
	this->_helperFunctions->SetDebugFontColor(0xFFF542C8);
	this->_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 1), "On Frame Locations");

	this->_timer++;

	if (this->_timer > MEMORY_CHECK_TIME)
	{
		this->_timer = 0;

		for (int i = 0; i < LevelClearCheck::LCC_NUM_CHECKS; i++)
		{
			if (this->_LevelClearData.find(i) != this->_LevelClearData.end())
			{
				LevelClearCheckData checkData = this->_LevelClearData[i];

				if (!checkData.CheckSent)
				{
					// DataPointer macro creates a static field, which doesn't work for this case
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

void LocationManager::OnInputFunction()
{

}

void LocationManager::OnControlFunction()
{

}