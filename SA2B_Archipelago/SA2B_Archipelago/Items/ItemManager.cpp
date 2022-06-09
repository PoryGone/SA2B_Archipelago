#include "../pch.h"
#include "ItemManager.h"
#include "ItemData.h"

#include "../Utilities/MessageQueue.h"

#include "../ModLoader/MemAccess.h"
#include <map>
#include <random>
//#include <math.h>


DataPointer(char, SavedChecksReceived, 0x1DEF5D9);

void* endLevelSave_ptr = (void*)0x4457df;
void* updateSettingsSave_ptr = (void*)0x44390C;
void* exitChaoGardenSave_ptr = (void*)0x4448E1;
void* winChaoKarateSave_ptr = (void*)0x542C0C;
//void* winChaoRaceSave_ptr = (void*)0x46F8E4; // This seems like a generic helper function that gets called all the time
const char nullop = '\x90';


static Trampoline* sub_724780_trampoline;

void sub_724780_original(ObjectMaster* a1)
{
	void* target = sub_724780_trampoline->Target();
	__asm
	{
		push[a1]
		call target
	}
}

static void __cdecl sub_724780_cpp(ObjectMaster* a1)
{
	ItemManager::getInstance()._TimeStopTimer = sa2b_ceil((double)(*((unsigned __int16*)a1->Data2.Undefined + 2) - *((unsigned __int16*)a1->Data2.Undefined + 1)));

	sub_724780_original(a1);
}


void ItemManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

	sub_724780_trampoline = new Trampoline(reinterpret_cast<intptr_t>((void*)0x00724780),
										   static_cast<intptr_t>(0x00724786),
										   &sub_724780_cpp);

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

	// Chaos Control Traps
	this->_p2Obj = new CharObj2Base;
	this->_p2Obj->PlayerNum = 1;
	WriteJump((void*)0x724B40, (void*)0x724BB8);
	WriteData((short*)0x724745, (short)0x9090);
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

void ItemManager::OnFrameJunkQueue()
{
	if (!(GameState == GameStates::GameStates_Ingame || GameState == GameStates::GameStates_Pause))
	{
		return;
	}

	if (CurrentLevel == LevelIDs_Route101280 || CurrentLevel == LevelIDs_ChaoWorld || CurrentLevel == LevelIDs_FinalHazard)
	{
		return;
	}

	if (MainCharObj2[0] && (MainCharObj2[0]->Powerups & Powerups_Dead))
	{
		return;
	}

	while (this->_JunkQueue.size() > 0)
	{
		int itemToGrant = this->_JunkQueue.front();
		this->_JunkQueue.pop();
		ItemData& receivedItem = this->_ItemData[itemToGrant];

		DisplayItemBoxItem(0, ItemBox_Items[receivedItem.Address].Texture);
		ItemBox_Items[receivedItem.Address].Code(MainCharacter[0], 0);
	}
}


std::random_device rand_dev;
std::default_random_engine rng(rand_dev());
DataPointer(int, StageMessageCount, 0xB5D200);
ObjectMaster* LoadOmochao(NJS_VECTOR* position)
{
	ObjectMaster* obj = AllocateObjectMaster(Omochao_Main, 2, "ObjectMessenger");
	if (obj)
	{
		EntityData1* ent_data_1 = AllocateEntityData1();
		if (ent_data_1)
		{
			obj->Data1.Entity = ent_data_1;
			void* ent_data_2 = AllocateEntityData2();
			if (ent_data_2)
			{
				obj->EntityData2 = (UnknownData2*)ent_data_2;
				ent_data_1->Position = *position;
				ent_data_1->Scale.x = (float)(rng() % StageMessageCount); // select a random hint from the level's hint message file
				ent_data_1->Scale.y = 15;
				ent_data_1->Scale.z = 0;
				ent_data_1->NextAction |= 3; // force Omochao to follow the player
				ent_data_1->Action = 5; // force Omochao into the talking action
				return obj;
			}
			else
			{
				DeleteObject_(obj);
			}
		}
		else
		{
			DeleteObject_(obj);
		}
	}
	return nullptr;
}

void CheckLoadOmochao(ObjectMaster* obj)
{
	if (*(void**)0xB5838C) // make sure Omochao's textures are loaded before spawning
	{
		LoadOmochao(&MainCharObj1[0]->Position);
		DeleteObject_(obj);
	}
}

void RestoreOmochao()
{
	// Revert changes made by the "Disable Omochao" Code
	if ((*(char*)0x6C0780) != (char)0x83)
	{
		MessageQueue::GetInstance().AddMessage("You thought you were clever, didn't you?");

		WriteData<1>((void*)0x6C0780, 0x83);

		WriteData<1>((void*)0x6C0A9A, 0x0F);
		WriteData<1>((void*)0x6C0A9B, 0x84);
		WriteData<1>((void*)0x6C0A9C, 0x94);
		WriteData<1>((void*)0x6C0A9D, 0x01);
		WriteData<1>((void*)0x6C0A9E, 0x00);
		WriteData<1>((void*)0x6C0A9F, 0x00);
		WriteData<1>((void*)0x6C0AA0, 0x83);
		WriteData<1>((void*)0x6C0AA1, 0xE8);
		WriteData<1>((void*)0x6C0AA2, 0x01);
		WriteData<1>((void*)0x6C0AA3, 0x0F);
		WriteData<1>((void*)0x6C0AA4, 0x84);
		WriteData<1>((void*)0x6C0AA5, 0xE9);
		WriteData<1>((void*)0x6C0AA6, 0x00);
		WriteData<1>((void*)0x6C0AA7, 0x00);
		WriteData<1>((void*)0x6C0AA8, 0x00);
		WriteData<1>((void*)0x6C0AA9, 0x83);
		WriteData<1>((void*)0x6C0AAA, 0xE8);
		WriteData<1>((void*)0x6C0AAB, 0x01);
		WriteData<1>((void*)0x6C0AAC, 0x74);
		WriteData<1>((void*)0x6C0AAD, 0x06);
	}
}

void ItemManager::HandleTrap(int item_id)
{
	this->_TrapQueue.push(item_id);
}

void ItemManager::OnFrameTrapQueue()
{
	if (!(GameState == GameStates::GameStates_Ingame))
	{
		this->_ActiveTrap = 0;
		this->_TimeStopPos = NJS_VECTOR();
		return;
	}

	if (CurrentLevel == LevelIDs_Route101280 || CurrentLevel == LevelIDs_ChaoWorld || CurrentLevel == LevelIDs_FinalHazard)
	{
		this->_ActiveTrap = 0;
		this->_TimeStopPos = NJS_VECTOR();
		return;
	}

	if (MainCharObj2[0] && (MainCharObj2[0]->Powerups & Powerups_Dead))
	{
		this->_ActiveTrap = 0;
		this->_TimeStopPos = NJS_VECTOR();
		return;
	}

	if (MainCharObj1[0] && (MainCharObj1[0]->Action == Action_Death ||
		MainCharObj1[0]->Action == Action_Drown ||
		MainCharObj1[0]->Action == Action_Quicksand))
	{
		this->_ActiveTrap = 0;
		this->_TimeStopPos = NJS_VECTOR();
		return;
	}

	// Active Trap
	if (this->_ActiveTrap == ItemValue::IV_OmochaoTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_TimeStopTrap)
	{
		if (CurrentCharacter != Characters_Sonic && CurrentCharacter != Characters_Shadow)
		{
			if ((MainCharObj1[0]) && (MainCharObj2[0]))
			{
				// Needs some work to get the timing better
				if (this->_TimeStopTimer > 0)
				{
					MainCharObj1[0]->Action = Action_None;
					MainCharObj1[0]->Position = this->_TimeStopPos;
					MainCharObj2[0]->Speed.x = 0.0;
					MainCharObj2[0]->Speed.y = 0.0;
					MainCharObj2[0]->Speed.z = 0.0;
				}
			}
		}
	}
	else if (this->_ActiveTrap == ItemValue::IV_ConfuseTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_TinyTrap)
	{
		if (MainCharObj1[0])
		{
			if (this->_ActiveTrapTimer <= 0)
			{
				MainCharObj1[0]->Scale.x = 1.0f;
				MainCharObj1[0]->Scale.y = 1.0f;
				MainCharObj1[0]->Scale.z = 1.0f;
			}
			else if (this->_ActiveTrapTimer > (TRAP_DURATION * 0.9f))
			{
				MainCharObj1[0]->Scale.x -= 0.012f;
				MainCharObj1[0]->Scale.y -= 0.012f;
				MainCharObj1[0]->Scale.z -= 0.012f;
			}
			else if (this->_ActiveTrapTimer < (TRAP_DURATION * 0.1f))
			{
				MainCharObj1[0]->Scale.x += 0.012f;
				MainCharObj1[0]->Scale.y += 0.012f;
				MainCharObj1[0]->Scale.z += 0.012f;
			}
		}
	}

	if (this->_ActiveTrapTimer > 0)
	{
		this->_ActiveTrapTimer--;
		return;
	}

	this->_ActiveTrap = 0;
	this->_TimeStopPos = NJS_VECTOR();

	if (this->_TrapCooldownTimer > 0)
	{
		this->_TrapCooldownTimer--;
		return;
	}

	if (this->_TrapQueue.size() == 0)
	{
		return;
	}

	// Next Trap
	this->_ActiveTrapTimer = TRAP_DURATION;
	this->_TrapCooldownTimer = TRAP_COOLDOWN;

	this->_ActiveTrap = this->_TrapQueue.front();
	this->_TrapQueue.pop();
	ItemData& receivedItem = this->_ItemData[this->_ActiveTrap];

	std::string message = std::string("Received ");
	message += receivedItem.DisplayName;
	MessageQueue::GetInstance().AddMessage(message);

	switch (this->_ActiveTrap)
	{
	case ItemValue::IV_OmochaoTrap:
		RestoreOmochao();
		for (int i = 0; i < 5; i++)
		{
			AllocateObjectMaster(CheckLoadOmochao, 2, "CheckLoadOmochao");
		}
		break;
	case ItemValue::IV_TimeStopTrap:
		Sonic2PTimeStopMan_Load(this->_p2Obj);
		PlayVoice(2, 1524);
		if (MainCharObj1[0])
		{
			this->_TimeStopPos = MainCharObj1[0]->Position;
		}
		break;
	case ItemValue::IV_ConfuseTrap:
		if (MainCharObj2[0])
		{
			MainCharObj2[0]->ConfuseTime = TRAP_DURATION;
			ConfuStar_Load(0);
			PlayVoice(2, 671);
		}
		break;
	case ItemValue::IV_TinyTrap:
		// Nothing
		PlayVoice(2, 1374);
		break;
	}
}
