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

					if (dataValue > 0x00)
					{
						if (this->_archipelagoManager)
						{
							this->_archipelagoManager->SendItem(i);

							checkData.CheckSent = true;

							MessageQueue* messageQueue = &MessageQueue::GetInstance();

							std::string message = std::string("Sent Check: ");
							message += std::to_string(i);
							messageQueue->AddMessage(message);
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