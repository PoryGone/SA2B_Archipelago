#include "../pch.h"
#include "ItemManager.h"
#include "ItemData.h"

#include "../Utilities/MessageQueue.h"

#include "../ModLoader/MemAccess.h"
#include <map>


DataPointer(char, SavedChecksReceived, 0x1DEF5D9);

void* endLevelSave_ptr = (void*)0x4457df;
void* updateSettingsSave_ptr = (void*)0x44390C;
void* exitChaoGardenSave_ptr = (void*)0x4448E1;
void* winChaoKarateSave_ptr = (void*)0x542C0C;
//void* winChaoRaceSave_ptr = (void*)0x46F8E4; // This seems like a generic helper function that gets called all the time
const char nullop = '\x90';

void ItemManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

	this->_ItemData.clear();

	this->_thisSessionChecksReceived = 0;
	this->_EmblemsReceived = 0;

	InitializeItemData(this->_ItemData);

	// Retarget Equipment Save File Data to 0x1DEC638 
	WriteData<1>((void*)0x6D87FB, 0x38);
	WriteData<1>((void*)0x6D87FC, 0xC6);

	WriteData<1>((void*)0x6D864B, 0x38);
	WriteData<1>((void*)0x6D864C, 0xC6);

	// Prevent Upgrades from being Temporarily Granted at Upgade Spots
	WriteData<1>((void*)0x6D881B, 0x90);
	WriteData<1>((void*)0x6D881C, 0x90);
	WriteData<1>((void*)0x6D881D, 0x90);

	// Emblem Recalculation Calls
	WriteData<5>(endLevelSave_ptr, nullop);
	WriteData<5>(updateSettingsSave_ptr, nullop);
	WriteData<5>(exitChaoGardenSave_ptr, nullop);
	WriteData<5>(winChaoKarateSave_ptr, nullop);
	//WriteData<2>(winChaoRaceSave_ptr, nullop);
}

void ItemManager::OnFrameFunction()
{
	// Hacky Thing - Eggman Mystic Melody new spot defaults to 0x1E
	char dataValue = *(char*)0x1DEC650;

	if (dataValue == 0x1E)
	{
		WriteData<1>((void*)0x1DEC650, 0x00);
	}

	if (this->_EmblemsReceived > EmblemCount)
	{
		EmblemCount = this->_EmblemsReceived;
		WriteData<1>((void*)0x0174B032, this->_EmblemsReceived);
	}

	this->OnFrameJunkQueue();
	this->OnFrameTrapQueue();
}

void ItemManager::ResetItems()
{
	this->_EmblemsReceived = 0;
	EmblemCount = 0;
}

void ItemManager::ReceiveItem(int item_id, bool notify)
{
	item_id = item_id - AP_ITEM_ID_OFFSET;
	MessageQueue* messageQueue = &MessageQueue::GetInstance();

	this->_thisSessionChecksReceived++;

	if (item_id == ItemValue::IV_Maria)
	{
		return;
	}
	else if (item_id == ItemValue::IV_Emblem)
	{
		if (this->_ItemData.find(item_id) != this->_ItemData.end())
		{
			ItemData& receivedItem = this->_ItemData[item_id];

			// DataPointer macro creates a static field, which doesn't work for this case
			char dataValue = *(char*)receivedItem.Address;

			this->_EmblemsReceived++;
			dataValue = this->_EmblemsReceived;
			bool success = WriteData<1>((void*)receivedItem.Address, dataValue);

			if (success)
			{
				if (this->_thisSessionChecksReceived > SavedChecksReceived)
				{
					SavedChecksReceived = this->_thisSessionChecksReceived;

					std::string message = std::string("New Emblem Count: ");
					message += std::to_string((int)dataValue);
					messageQueue->AddMessage(message);
				}

				// Cutscene Emblem Count
				WriteData<1>((void*)0x0174B032, dataValue);
			}
			else
			{
				std::string message = std::string("Failed to Write Emblem Count");
				messageQueue->AddMessage(message);
			}
		}
	}
	else if (item_id < ItemValue::IV_Maria) // Upgrades
	{
		ItemData& receivedItem = this->_ItemData[item_id];

		if (receivedItem.AmountObtained == 0)
		{
			bool success = WriteData<1>((void*)receivedItem.Address, 0x1);

			receivedItem.AmountObtained++;

			if (success)
			{
				this->HandleEquipment(item_id);

				if (this->_thisSessionChecksReceived > SavedChecksReceived)
				{
					SavedChecksReceived = this->_thisSessionChecksReceived;

					std::string message = std::string("Received ");
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
			std::string message = std::string("Received Duplicate Item: ");
			message += receivedItem.DisplayName;
			messageQueue->AddMessage(message);
		}
	}
	else if (item_id <= ItemValue::IV_Invincibility) // Junk
	{
		this->HandleJunk(item_id);

		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			SavedChecksReceived = this->_thisSessionChecksReceived;

			ItemData& receivedItem = this->_ItemData[item_id];

			std::string message = std::string("Received ");
			message += receivedItem.DisplayName;
			messageQueue->AddMessage(message);
		}
	}
	else if (item_id <= ItemValue::IV_TinyTrap) // Trap
	{
		this->HandleTrap(item_id);

		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			SavedChecksReceived = this->_thisSessionChecksReceived;

			ItemData& receivedItem = this->_ItemData[item_id];

			std::string message = std::string("Received ");
			message += receivedItem.DisplayName;
			messageQueue->AddMessage(message);
		}
	}
	else
	{
		std::string message = std::string("Received Invalid ID: ");
		message += std::to_string(item_id);
		messageQueue->AddMessage(message);

		return;
	}
}

int APItemIDtoSA2ItemID(int APID)
{
	switch (APID)
	{
	case ItemValue::IV_SonicGloves:			return Upgrades_SonicMagicGloves;
	case ItemValue::IV_SonicLightShoes:		return Upgrades_SonicLightShoes;
	case ItemValue::IV_SonicAncientLight:	return Upgrades_SonicAncientLight;
	case ItemValue::IV_SonicBounceBracelet: return Upgrades_SonicBounceBracelet;
	case ItemValue::IV_SonicFlameRing:		return Upgrades_SonicFlameRing;
	case ItemValue::IV_SonicMysticMelody:	return Upgrades_SonicMysticMelody;

	case ItemValue::IV_TailsLaserBlaster: return Upgrades_TailsLaserBlaster;
	case ItemValue::IV_TailsBooster:	  return Upgrades_TailsBooster;
	case ItemValue::IV_TailsMysticMelody: return Upgrades_TailsMysticMelody;
	case ItemValue::IV_TailsBazooka:	  return Upgrades_TailsBazooka;

	case ItemValue::IV_KnucklesMysticMelody: return Upgrades_KnucklesMysticMelody;
	case ItemValue::IV_KnucklesShovelClaw:   return Upgrades_KnucklesShovelClaw;
	case ItemValue::IV_KnucklesAirNecklace:  return Upgrades_KnucklesAirNecklace;
	case ItemValue::IV_KnucklesHammerGloves: return Upgrades_KnucklesHammerGloves;
	case ItemValue::IV_KnucklesSunglasses:   return Upgrades_KnucklesSunglasses;

	case ItemValue::IV_ShadowFlameRing:    return Upgrades_ShadowFlameRing;
	case ItemValue::IV_ShadowAirShoes:     return Upgrades_ShadowAirShoes;
	case ItemValue::IV_ShadowAncientLight: return Upgrades_ShadowAncientLight;
	case ItemValue::IV_ShadowMysticMelody: return Upgrades_ShadowMysticMelody;

	case ItemValue::IV_EggmanLaserBlaster:    return Upgrades_EggmanLaserBlaster;
	case ItemValue::IV_EggmanMysticMelody:    return Upgrades_EggmanMysticMelody;
	case ItemValue::IV_EggmanJetEngine:       return Upgrades_EggmanJetEngine;
	case ItemValue::IV_EggmanLargeCannon:     return Upgrades_EggmanLargeCannon;
	case ItemValue::IV_EggmanProtectiveArmor: return Upgrades_EggmanProtectiveArmor;

	case ItemValue::IV_RougeMysticMelody:  return Upgrades_RougeMysticMelody;
	case ItemValue::IV_RougePickNails:     return Upgrades_RougePickNails;
	case ItemValue::IV_RougeTreasureScope: return Upgrades_RougeTreasureScope;
	case ItemValue::IV_RougeIronBoots:     return Upgrades_RougeIronBoots;

	default: return Upgrades_SonicLightShoes;
	}
}

void ItemManager::HandleEquipment(int EquipmentItem)
{
	if (!(GameState == GameStates::GameStates_Ingame || GameState == GameStates::GameStates_Pause))
	{
		return;
	}

	if ((CurrentCharacter == Characters_Sonic      && EquipmentItem >= IV_SonicGloves          && EquipmentItem <= IV_SonicMysticMelody) ||
		(CurrentCharacter == Characters_MechTails  && EquipmentItem >= IV_TailsLaserBlaster    && EquipmentItem <= IV_TailsBazooka) ||
		(CurrentCharacter == Characters_Knuckles   && EquipmentItem >= IV_KnucklesMysticMelody && EquipmentItem <= IV_KnucklesSunglasses) ||
		(CurrentCharacter == Characters_Shadow     && EquipmentItem >= IV_ShadowFlameRing      && EquipmentItem <= IV_ShadowMysticMelody) ||
		(CurrentCharacter == Characters_MechEggman && EquipmentItem >= IV_EggmanLaserBlaster   && EquipmentItem <= IV_EggmanProtectiveArmor) ||
		(CurrentCharacter == Characters_Rouge      && EquipmentItem >= IV_RougeMysticMelody    && EquipmentItem <= IV_RougeIronBoots))
	{
		if (MainCharObj2[0] != NULL)
		{
			int NewEquipBit = APItemIDtoSA2ItemID(EquipmentItem);

			MainCharObj2[0]->Upgrades |= NewEquipBit;
		}
	}
}

void ItemManager::HandleJunk(int item_id)
{
	this->_JunkQueue.push(item_id);
}

void ItemManager::HandleTrap(int item_id)
{
	this->_TrapQueue.push(item_id);
}

void ItemManager::OnFrameJunkQueue()
{
	if (!(GameState == GameStates::GameStates_Ingame || GameState == GameStates::GameStates_Pause))
	{
		return;
	}
}

void ItemManager::OnFrameTrapQueue()
{
	if (!(GameState == GameStates::GameStates_Ingame || GameState == GameStates::GameStates_Pause))
	{
		return;
	}

	if (this->_TrapQueue.size() == 0)
	{
		return;
	}

	// Timer Stuff

	int trap_id = this->_TrapQueue.front();
	this->_TrapQueue.pop();
	switch (trap_id)
	{
	case ItemValue::IV_TimeStopTrap:

		break;
	}
}
