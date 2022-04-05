#include "../pch.h"
#include "ItemManager.h"
#include "ItemData.h"

#include "../Utilities/MessageQueue.h"

#include "../ModLoader/MemAccess.h"
#include <map>


void ItemManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

	this->_ItemData.clear();

	InitializeItemData(this->_ItemData);
}

void ItemManager::OnFrameFunction()
{

}

void ItemManager::ResetItems()
{

}

void ItemManager::ReceiveItem(int item_id, bool notify)
{
	item_id = item_id - AP_ITEM_ID_OFFSET;
	MessageQueue* messageQueue = &MessageQueue::GetInstance();

	if (item_id > ItemValue::IV_NUM_ITEMS)
	{
		std::string message = std::string("Received Invalid ID: ");
		message += std::to_string(item_id);
		messageQueue->AddMessage(message);

		return;
	}
	else if (item_id == ItemValue::IV_Emblem)
	{
		if (this->_ItemData.find(item_id) != this->_ItemData.end())
		{
			ItemData& receivedItem = this->_ItemData[item_id];

			// DataPointer macro creates a static field, which doesn't work for this case
			char dataValue = *(char*)receivedItem.Address;

			dataValue++;
			bool success = WriteData<1>((void*)receivedItem.Address, dataValue);

			if (success)
			{
				std::string message = std::string("New Emblem Count: ");
				message += std::to_string((int)dataValue);
				messageQueue->AddMessage(message);

				ProbablySavesSaveFile();
			}
			else
			{
				std::string message = std::string("Failed to Write");
				messageQueue->AddMessage(message);
			}
		}
	}
	else
	{
		ItemData& receivedItem = this->_ItemData[item_id];

		if (receivedItem.AmountObtained == 0)
		{
			bool success = WriteData<1>((void*)receivedItem.Address, 0x1);

			receivedItem.AmountObtained++;

			if (success)
			{
				//if (notify)
				{
					std::string message = std::string("Successfully received ");
					message += receivedItem.DisplayName;
					messageQueue->AddMessage(message);
				}
			}
			else
			{
				std::string message = std::string("Write failed: ");
				message += std::to_string(item_id);
				messageQueue->AddMessage(message);
			}
		}
		else
		{
			std::string message = std::string("Received Duplicate ID: ");
			message += std::to_string(item_id);
			message += std::string("| Count: ");
			message += std::to_string(receivedItem.AmountObtained);
			messageQueue->AddMessage(message);
		}
	}
}
