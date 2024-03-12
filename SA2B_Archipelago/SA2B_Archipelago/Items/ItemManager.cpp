#include "../pch.h"
#include "ItemManager.h"
#include "ItemData.h"
#include "Minigames/MinigameManager.h"

#include "../Aesthetics/MusicManager.h"
#include "../Archipelago/ArchipelagoManager.h"
#include "../Utilities/MessageQueue.h"

#include "../ModLoader/MemAccess.h"
#include <array>
#include <map>
#include <random>


DataPointer(int, SavedChecksReceived, 0x1DEE414);
DataPointer(unsigned int, NewEmblemCount, 0x1DEE418);

DataPointer(char, StoryProgressID_1, 0x1DEB31E);
DataPointer(char, StoryProgressID_2, 0x1DEB31F);
DataPointer(char, StoryProgressID_3, 0x1DEB320);
DataPointer(char, StoryProgressID_4, 0x1DEB321);

DataPointer(int, StoryEventID_1, 0x173A154);
DataPointer(char, StoryEventID_2, 0x173A158);
DataPointer(char, StoryEventID_3, 0x173A159);

// Chao Data
DataArray(ChaoGardenObject, GardenItemInventory, 0x01DBEDA0, 5);
DataPointer(char, GardenItemInventoryCount, 0x01DBEDAC);
DataArray(ChaoAnimalSlot, HeroAnimalInventory, 0x1946F18, 10);
DataPointer(char, HeroAnimalInventoryCount, 0x1946F68);
DataArray(ChaoAnimalSlot, DarkAnimalInventory, 0x1946FCC, 10);
DataPointer(char, DarkAnimalInventoryCount, 0x194701C);

DataPointer(uint16_t, SavedChaoEggsUsed, 0x19F6462);
DataPointer(uint16_t, SavedChaoFruitsUsed, 0x19F6464);
DataPointer(uint16_t, SavedChaoSeedsUsed, 0x19F6466);
DataPointer(uint16_t, SavedChaoHatsUsed, 0x19F6468);
DataPointer(uint16_t, SavedChaoAnimalsUsed, 0x19F646A);

DataArray(ChaoFruitSlot, RealChaoFruitSlots, 0x19F6528, 24);
DataArray(ChaoSeedSlot, RealChaoSeedSlots, 0x19F6848, 12);
DataArray(ChaoHatSlot, RealChaoHatSlots, 0x019F6938, 24);

void* endLevelSave_ptr = (void*)0x4457df;
void* updateSettingsSave_ptr = (void*)0x44390C;
void* exitChaoGardenSave_ptr = (void*)0x4448E1;
void* winChaoKarateSave_ptr = (void*)0x542C0C;
void* winChaoRaceSave_ptr = (void*)0x52C9B9;
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
	this->_BlackMarketTokensReceived = 0;

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
	WriteData<5>(winChaoRaceSave_ptr, nullop);

	// Chaos Control Traps
	this->_p2Obj = new CharObj2Base;
	this->_p2Obj->PlayerNum = 1;
	WriteJump((void*)0x724B40, (void*)0x724BB8);
	WriteData((short*)0x724745, (short)0x9090);

	// Cutscene Trap Setup
	StoryEventID_1 = 2;
}

void ItemManager::OnInputFunction()
{
	if (GameMode == GameMode::GameMode_Event &&
		CurrentMenu == Menus::Menus_StageSelect &&
		StoryProgressID_3 != 0x03)
	{
		Uint32 HeldButtons    = ControllersRaw->on;
		Uint32 PressedButtons = ControllersRaw->press;

		ArchipelagoManager* apm = &ArchipelagoManager::getInstance();
		if (!apm)
		{
			return;
		}

		if (apm->IsDebug()                    &&
			(HeldButtons & 0b100)        != 0 &&
			(PressedButtons & 0b1000)    != 0 &&
			(HeldButtons & 0b100000)     != 0 &&
			(HeldButtons & 0b1000000000) != 0)
		{
			return;
		}

		ControllersRaw->on    = 0;
		ControllersRaw->press = 0;
	}

	if (this->_ReverseTrapActive &&
		(GameState == GameStates::GameStates_Ingame || GameState == GameStates::GameStates_Pause))
	{
		Uint32 HeldButtons = ControllersRaw->on;
		Uint32 PressedButtons = ControllersRaw->press;

		Uint32 NewHeldButtons = 0;
		Uint32 NewPressedButtons = 0;

		if (HeldButtons & 0b10)  NewHeldButtons |= 0b100;
		if (HeldButtons & 0b100) NewHeldButtons |= 0b10;

		if (HeldButtons & 0b1000)  NewHeldButtons |= 0b1000;

		if (HeldButtons & 0b10000)  NewHeldButtons |= 0b100000;
		if (HeldButtons & 0b100000) NewHeldButtons |= 0b10000;

		if (HeldButtons & 0b1000000)  NewHeldButtons |= 0b10000000;
		if (HeldButtons & 0b10000000) NewHeldButtons |= 0b1000000;

		if (HeldButtons & 0b1000000000)  NewHeldButtons |= 0b10000000000;
		if (HeldButtons & 0b10000000000) NewHeldButtons |= 0b1000000000;

		if (HeldButtons & 0b10000000000000000)  NewHeldButtons |= 0b100000000000000000;
		if (HeldButtons & 0b100000000000000000) NewHeldButtons |= 0b10000000000000000;

		if (PressedButtons & 0b10)  NewPressedButtons |= 0b100;
		if (PressedButtons & 0b100) NewPressedButtons |= 0b10;

		if (PressedButtons & 0b1000)  NewPressedButtons |= 0b1000;

		if (PressedButtons & 0b10000)  NewPressedButtons |= 0b100000;
		if (PressedButtons & 0b100000) NewPressedButtons |= 0b10000;

		if (PressedButtons & 0b1000000)  NewPressedButtons |= 0b10000000;
		if (PressedButtons & 0b10000000) NewPressedButtons |= 0b1000000;

		if (PressedButtons & 0b1000000000)  NewPressedButtons |= 0b10000000000;
		if (PressedButtons & 0b10000000000) NewPressedButtons |= 0b1000000000;

		if (PressedButtons & 0b10000000000000000)  NewPressedButtons |= 0b100000000000000000;
		if (PressedButtons & 0b100000000000000000) NewPressedButtons |= 0b10000000000000000;

		ControllersRaw->on = NewHeldButtons;
		ControllersRaw->press = NewPressedButtons;

		ControllersRaw->x1 = -ControllersRaw->x1;
		ControllersRaw->y1 = -ControllersRaw->y1;
		ControllersRaw->x2 = -ControllersRaw->x2;
		ControllersRaw->y2 = -ControllersRaw->y2;

		Uint16 l = ControllersRaw->l;
		Uint16 r = ControllersRaw->r;

		ControllersRaw->r = l;
		ControllersRaw->l = r;
	}
}

void ItemManager::OnFrameFunction()
{
	// Hacky Thing - Eggman Mystic Melody new spot defaults to 0x1E
	char dataValue = *(char*)0x1DEC650;

	if (dataValue == 0x1E)
	{
		WriteData<1>((void*)0x1DEC650, 0x00);
	}

	NewEmblemCount = this->_EmblemsReceived;

	this->OnFrameJunkQueue();
	this->OnFrameTrapQueue();
	this->OnFrameCutsceneQueue();
	this->OnFrameChaoGardenQueue();
}

void ItemManager::ResetItems()
{
	this->_thisSessionChecksReceived = 0;
	this->_EmblemsReceived = 0;
	this->_BlackMarketTokensReceived = 0;
	NewEmblemCount = 0;

	for (int itemID = ItemValue::IV_WhiteChaosEmerald; itemID <= ItemValue::IV_BlueChaosEmerald; itemID++)
	{
		if (this->_ItemData.find(itemID) != this->_ItemData.end())
		{
			ItemData& itemToReset = this->_ItemData[itemID];
			WriteData<1>((void*)itemToReset.Address, 0x00);
		}
	}

	this->_ChaoEggQueue.clear();
	this->_ChaoFruitQueue.clear();
	this->_ChaoSeedQueue.clear();
	this->_ChaoHatQueue.clear();
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
			unsigned int dataValue = *(unsigned int*)receivedItem.Address;

			this->_EmblemsReceived++;
			dataValue = this->_EmblemsReceived;
			*(unsigned int*)receivedItem.Address = dataValue;

			if (this->_thisSessionChecksReceived > SavedChecksReceived)
			{
				SavedChecksReceived = this->_thisSessionChecksReceived;

				std::string message = std::string("New Emblem Count: ");
				message += std::to_string((unsigned int)dataValue);
				messageQueue->AddMessage(message);
			}
		}
	}
	else if (item_id <= ItemValue::IV_END_UPGRADES) // Upgrades
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
	}
	else if (item_id == ItemValue::IV_BlackMarketToken) // Black Market Tokens
	{
		ItemData& receivedItem = this->_ItemData[item_id];

		if (this->_ItemData.find(item_id) != this->_ItemData.end())
		{
			ItemData& receivedItem = this->_ItemData[item_id];

			unsigned int dataValue = *(unsigned int*)receivedItem.Address;

			this->_BlackMarketTokensReceived++;
			dataValue = this->_BlackMarketTokensReceived;
			*(unsigned int*)receivedItem.Address = dataValue;

			if (this->_thisSessionChecksReceived > SavedChecksReceived)
			{
				SavedChecksReceived = this->_thisSessionChecksReceived;

				std::string message = std::string("New ");
				message += receivedItem.DisplayName;
				message += " Count: ";
				message += std::to_string((unsigned int)dataValue);
				messageQueue->AddMessage(message);
			}
		}
	}
	else if (item_id <= ItemValue::IV_END_JUNK) // Junk
	{
		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			// Don't recollect the junk items
			this->HandleJunk(item_id);

			SavedChecksReceived = this->_thisSessionChecksReceived;

			ItemData& receivedItem = this->_ItemData[item_id];

			std::string message = std::string("Received ");
			message += receivedItem.DisplayName;
			messageQueue->AddMessage(message);
		}
	}
	else if (item_id <= ItemValue::IV_END_TRAPS) // Trap
	{
		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			// Don't recollect the trap items
			this->HandleTrap(item_id);

			SavedChecksReceived = this->_thisSessionChecksReceived;
		}
	}
	else if (item_id <= ItemValue::IV_END_CHAOS_EMERALDS) // Chaos Emerald
	{
		ItemData& receivedItem = this->_ItemData[item_id];

		bool success = WriteData<1>((void*)receivedItem.Address, 0x1);

		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			SavedChecksReceived = this->_thisSessionChecksReceived;

			std::string message = std::string("Received ");
			message += receivedItem.DisplayName;
			messageQueue->AddMessage(message);
		}
	}
	else if (item_id <= ItemValue::IV_END_MINIGAMES) // Minigame Trap
	{
		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			// Don't recollect the trap items
			this->HandleTrap(item_id);

			SavedChecksReceived = this->_thisSessionChecksReceived;
		}
	}
	else if (item_id <= ItemValue::IV_END_EGGS) // Chao Egg
	{
		// Don't recollect the Chao eggs
		this->HandleEgg(item_id);

		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			SavedChecksReceived = this->_thisSessionChecksReceived;
		}
	}
	else if (item_id <= ItemValue::IV_END_FRUITS) // Chao Fruit
	{
		// Don't recollect the Chao fruits
		this->HandleFruit(item_id);

		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			SavedChecksReceived = this->_thisSessionChecksReceived;
		}
	}
	else if (item_id <= ItemValue::IV_END_SEEDS) // Chao Seed
	{
		// Don't recollect the Chao seeds
		this->HandleSeed(item_id);

		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			SavedChecksReceived = this->_thisSessionChecksReceived;
		}
	}
	else if (item_id <= ItemValue::IV_END_HATS) // Chao Hat
	{
		// Don't recollect the Chao hats
		this->HandleHat(item_id);

		if (this->_thisSessionChecksReceived > SavedChecksReceived)
		{
			SavedChecksReceived = this->_thisSessionChecksReceived;
		}
	}
	else if (item_id <= ItemValue::IV_END_ANIMALS) // Chao Animals and Drives
	{
		// Don't recollect the Chao animals
		this->HandleAnimal(item_id);

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

bool ItemManager::IsOmotrapActive()
{
	return (this->_ActiveTrap == ItemValue::IV_OmochaoTrap);
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
	if (!(GameState == GameStates::GameStates_Ingame))
	{
		return;
	}

	if (CurrentLevel == LevelIDs_Route101280 || CurrentLevel == LevelIDs_KartRace || CurrentLevel == LevelIDs_ChaoWorld || CurrentLevel == LevelIDs_FinalHazard)
	{
		return;
	}

	if (MainCharObj2[0] && (MainCharObj2[0]->Powerups & Powerups_Dead))
	{
		return;
	}

	if (MainCharObj1[0] && (MainCharObj1[0]->Action == Action_Death ||
		MainCharObj1[0]->Action == Action_Drown ||
		(MainCharObj1[0]->Action == Action_Quicksand && CurrentLevel != LevelIDs_EggGolemS)))
	{
		return;
	}

	if (TimerStopped)
	{
		this->_JunkCooldownTimer = 60;
		return;
	}

	if (this->_JunkCooldownTimer > 0)
	{
		this->_JunkCooldownTimer--;
		return;
	}

	if (this->_JunkQueue.size() == 0)
	{
		return;
	}

	int itemsPerFrame = 5;
	while (itemsPerFrame > 0 and this->_JunkQueue.size() > 0)
	{
		if (!MainCharacter[0])
		{
			break;
		}

		int itemToGrant = this->_JunkQueue.front();
		this->_JunkQueue.pop();
		ItemData& receivedItem = this->_ItemData[itemToGrant];

		DisplayItemBoxItem(0, ItemBox_Items[receivedItem.Address].Texture);
		ItemBox_Items[receivedItem.Address].Code(MainCharacter[0], 0);

		this->_JunkCooldownTimer = JUNK_COOLDOWN;
		itemsPerFrame--;
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

bool ItemManager::IsActiveTrapValid()
{
	MinigameManager* minigameManager = &MinigameManager::GetInstance();

	switch (this->_ActiveTrap)
	{
	case ItemValue::IV_OmochaoTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_Route101280 ||
			CurrentLevel == LevelIDs_KartRace ||
			CurrentLevel == LevelIDs_ChaoWorld ||
			CurrentLevel == LevelIDs_FinalHazard)
		{
			return false;
		}
		break;
	case ItemValue::IV_TimeStopTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_Route101280 ||
			CurrentLevel == LevelIDs_KartRace ||
			CurrentLevel == LevelIDs_ChaoWorld)
		{
			return false;
		}

		if (StoryProgressID_3 == 0x0E &&
			TimerMinutes == 0 &&
			TimerSeconds == 0 &&
			TimerFrames == 0)
		{
			// Don't interrupt boss rush cutscenes
			return false;
		}

		if (CurrentLevel == LevelIDs_CrazyGadget &&
			(!MainCharObj2[0] || MainCharObj2[0]->NonInteractState == 0x0B || MainCharObj2[0]->gap1C[0] != 0x00))
		{
			// Don't take a Chaos Control Trap in Crazy Gadget Tubes
			return false;
		}

		if ((CurrentLevel == LevelIDs_PyramidCave || CurrentLevel == LevelIDs_RadicalHighway) &&
			(!MainCharObj2[0] || MainCharObj2[0]->NonInteractState >= 0xC0))
		{
			// Don't take a Chaos Control Trap on Spinning Bars
			return false;
		}

		if ((CurrentLevel == LevelIDs_CrazyGadget || CurrentLevel == LevelIDs_PyramidCave || CurrentLevel == LevelIDs_RadicalHighway) &&
			this->_ChaosControlCooldown > 0)
		{
			// Don't take a Chaos Control Trap right in between invalid states
			this->_ChaosControlCooldown--;
			return false;
		}
		break;
	case ItemValue::IV_ConfuseTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_Route101280 ||
			CurrentLevel == LevelIDs_KartRace ||
			CurrentLevel == LevelIDs_ChaoWorld)
		{
			return false;
		}
		break;
	case ItemValue::IV_TinyTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_Route101280 ||
			CurrentLevel == LevelIDs_KartRace ||
			CurrentLevel == LevelIDs_ChaoWorld ||
			CurrentLevel == LevelIDs_FinalHazard)
		{
			return false;
		}

		if (!MainCharObj1[0] || MainCharObj1[0]->Scale.x < 1.0f)
		{
			// Don't take a Tiny Trap when already Tiny
			return false;
		}
		break;
	case ItemValue::IV_GravityTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_Route101280 ||
			CurrentLevel == LevelIDs_KartRace ||
			CurrentLevel == LevelIDs_ChaoWorld ||
			CurrentLevel == LevelIDs_FinalHazard)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_CrazyGadget ||
			CurrentLevel == LevelIDs_MadSpace ||
			CurrentLevel == LevelIDs_FinalChase)
		{
			// These stages do too much weird stuff with gravity
			return false;
		}
		break;
	case ItemValue::IV_ExpositionTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_ChaoWorld)
		{
			return false;
		}

		if (this->_DialogueQueue.size() > 0 || this->_ActiveDialogueTimer > 0)
		{
			return false;
		}
		break;
	case ItemValue::IV_DarknessTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_Route101280 ||
			CurrentLevel == LevelIDs_KartRace ||
			CurrentLevel == LevelIDs_ChaoWorld ||
			CurrentLevel == LevelIDs_FinalHazard)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_WildCanyon || //
			CurrentLevel == LevelIDs_DeathChamber || //
			CurrentLevel == LevelIDs_IronGate || //
			CurrentLevel == LevelIDs_DryLagoon || //
			CurrentLevel == LevelIDs_RadicalHighway ||
			CurrentLevel == LevelIDs_EggQuarters || //
			CurrentLevel == LevelIDs_LostColony ||
			CurrentLevel == LevelIDs_WhiteJungle ||
			CurrentLevel == LevelIDs_SkyRail ||
			CurrentLevel == LevelIDs_MadSpace ||
			CurrentLevel == LevelIDs_CosmicWall || //
			CurrentLevel == LevelIDs_FinalChase || //
			CurrentLevel == LevelIDs_CannonsCoreT || //
			CurrentLevel == LevelIDs_CannonsCoreE || //
			CurrentLevel == LevelIDs_CannonsCoreR || //
			CurrentLevel == LevelIDs_CannonsCoreS || //
			CurrentLevel == LevelIDs_GreenHill || //
			CurrentLevel == LevelIDs_BigFoot || //
			CurrentLevel == LevelIDs_HotShot || //
			CurrentLevel == LevelIDs_EggGolemS || //
			CurrentLevel == LevelIDs_EggGolemE || //
			CurrentLevel == LevelIDs_KingBoomBoo || //
			CurrentLevel == LevelIDs_Biolizard)
		{
			// These stages don't work correctly with the fog
			return false;
		}
		break;
	case ItemValue::IV_IceTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_Route101280 ||
			CurrentLevel == LevelIDs_KartRace ||
			CurrentLevel == LevelIDs_ChaoWorld ||
			CurrentLevel == LevelIDs_FinalHazard)
		{
			return false;
		}

		if (!MainCharObj2[0] || this->_StoredPhysicsData.GroundFriction != 0.0f)
		{
			// Don't take an Ice Trap when already Icy
			return false;
		}
		break;
	case ItemValue::IV_SlowTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (CurrentLevel == LevelIDs_Route101280 ||
			CurrentLevel == LevelIDs_KartRace ||
			CurrentLevel == LevelIDs_ChaoWorld ||
			CurrentLevel == LevelIDs_FinalHazard)
		{
			return false;
		}

		if (!MainCharObj2[0])
		{
			return false;
		}
		break;
	case ItemValue::IV_CutsceneTrap:
		if (GameMode != GameMode::GameMode_Level && GameMode != GameMode::GameMode_Event)
		{
			return false;
		}

		if (StoryProgressID_3 == 0x03 || StoryProgressID_3 == 0x0E)
		{
			// Don't interrupt the ending sequence or boss rush
			return false;
		}

		if (CurrentLevel == LevelIDs_CannonsCoreT ||
			CurrentLevel == LevelIDs_CannonsCoreE ||
			CurrentLevel == LevelIDs_CannonsCoreR ||
			CurrentLevel == LevelIDs_CannonsCoreK ||
			CurrentLevel == LevelIDs_GreenHill ||
			CurrentLevel == LevelIDs_KartRace ||
			CurrentLevel == LevelIDs_ChaoWorld ||
			CurrentLevel == LevelIDs_Biolizard ||
			CurrentLevel == LevelIDs_FinalHazard)
		{
			return false;
		}

		if (StoryEventID_1 != 0x02)
		{
			// Another Cutscene is queued
			return false;
		}
		break;
	case ItemValue::IV_ReverseTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (this->_ReverseTrapActive)
		{
			return false;
		}
		break;
	case ItemValue::IV_LiteratureTrap:
	case ItemValue::IV_PongTrap:
	case ItemValue::IV_PlatformerTrap:
	case ItemValue::IV_FishingTrap:
	case ItemValue::IV_TriviaTrap:
		if (GameMode != GameMode::GameMode_Level)
		{
			return false;
		}

		if (minigameManager->state != MinigameState::MGS_None)
		{
			// Another minigame is already in-progress
			return false;
		}

		break;
	}

	return true;
}

void ItemManager::ResetTrapData()
{
	this->_ActiveTrap = 0;
	this->_TimeStopPos = NJS_VECTOR();
	if (MainCharObj1[0])
	{
		MainCharObj1[0]->Scale.x = 1.0f;
		MainCharObj1[0]->Scale.y = 1.0f;
		MainCharObj1[0]->Scale.z = 1.0f;
	}
	this->_StoredFogData = FogData();

	if (this->_CutsceneQueued)
	{
		// We queued a Cutscene, but didn't get to use it
		this->HandleTrap(IV_CutsceneTrap);
		this->_CutsceneQueued = false;

		StoryEventID_1 = 2;
		StoryEventID_2 = 0xFF;
		StoryEventID_3 = 0xFF;
	}

	if (!(CurrentLevel == LevelIDs_CrazyGadget || CurrentLevel == LevelIDs_MadSpace || CurrentLevel == LevelIDs_FinalChase))
	{
		Gravity.x = 0.0f;
		Gravity.y = -1.0f;
		Gravity.z = 0.0f;
	}

	if (MainCharObj2[0])
	{
		if (this->_StoredPhysicsData.SpeedMaxH != MainCharObj2[0]->PhysData.SpeedMaxH &&
			this->_StoredPhysicsData.SpeedMaxH != 0.0f)
		{
			MainCharObj2[0]->PhysData.SpeedMaxH      = this->_StoredPhysicsData.SpeedMaxH;
			MainCharObj2[0]->PhysData.SpeedCapH      = this->_StoredPhysicsData.SpeedCapH;
			MainCharObj2[0]->PhysData.SpeedCapV      = this->_StoredPhysicsData.SpeedCapV;
			MainCharObj2[0]->PhysData.RunSpeed       = this->_StoredPhysicsData.RunSpeed;
			MainCharObj2[0]->PhysData.RushSpeed      = this->_StoredPhysicsData.RushSpeed;
			MainCharObj2[0]->PhysData.DashSpeed      = this->_StoredPhysicsData.DashSpeed;
			MainCharObj2[0]->PhysData.JogSpeed       = this->_StoredPhysicsData.JogSpeed;
			MainCharObj2[0]->PhysData.SlideSpeed     = this->_StoredPhysicsData.SlideSpeed;
			MainCharObj2[0]->PhysData.PushSpeedMax   = this->_StoredPhysicsData.PushSpeedMax;
			MainCharObj2[0]->PhysData.NoControlSpeed = this->_StoredPhysicsData.NoControlSpeed;
			MainCharObj2[0]->PhysData.AirResist      = this->_StoredPhysicsData.AirResist;
		}

		if (this->_StoredPhysicsData.GroundFriction != MainCharObj2[0]->PhysData.GroundFriction &&
			this->_StoredPhysicsData.GroundFriction != 0.0f)
		{
			MainCharObj2[0]->PhysData.GroundFriction = this->_StoredPhysicsData.GroundFriction;
			MainCharObj2[0]->PhysData.RunDecel       = this->_StoredPhysicsData.RunDecel;
			MainCharObj2[0]->PhysData.RunBrake       = this->_StoredPhysicsData.RunBrake;
		}

	}

	this->_StoredPhysicsData = PhysicsData();

	this->_ReverseTrapActive = false;
}

void ItemManager::OnFrameTrapQueue()
{
	if (GameState == GameStates::GameStates_Pause)
	{
		return;
	}

	if ((GameMode != GameMode::GameMode_LoadStory && GameMode != GameMode::GameMode_Event) &&
		(GameState != GameStates::GameStates_Ingame &&
		 GameState != GameStates::GameStates_Exit_1 &&
		 GameState != GameStates::GameStates_GoToNextLevel))
	{
		ResetTrapData();
		return;
	}

	if (MainCharObj2[0] && (MainCharObj2[0]->Powerups & Powerups_Dead))
	{
		ResetTrapData();
		return;
	}

	if (MainCharObj1[0] && (MainCharObj1[0]->Action == Action_Death ||
		MainCharObj1[0]->Action == Action_Drown ||
		(MainCharObj1[0]->Action == Action_Quicksand && CurrentLevel != LevelIDs_EggGolemS)))
	{
		ResetTrapData();
		return;
	}

	OnFrameDialogueQueue();

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
			if (this->_ActiveTrapTimer > (TRAP_DURATION * 0.9f))
			{
				MainCharObj1[0]->Scale.x -= 0.012f;
				MainCharObj1[0]->Scale.y -= 0.012f;
				MainCharObj1[0]->Scale.z -= 0.012f;
			}
		}
	}
	else if (this->_ActiveTrap == ItemValue::IV_GravityTrap)
	{
		if (this->_ActiveTrapTimer > (TRAP_DURATION * 0.9f))
		{
			Gravity.x *= 1.005f;
			Gravity.y *= 1.005f;
			Gravity.z *= 1.005f;
			ArbitraryGravity.x *= 1.005f;
			ArbitraryGravity.y *= 1.005f;
			ArbitraryGravity.z *= 1.005f;
		}
		else if (this->_ActiveTrapTimer < (TRAP_DURATION * 0.1f))
		{
			Gravity.x *= (1.0f / 1.005f);
			Gravity.y *= (1.0f / 1.005f);
			Gravity.z *= (1.0f / 1.005f);
			ArbitraryGravity.x *= (1.0f / 1.005f);
			ArbitraryGravity.y *= (1.0f / 1.005f);
			ArbitraryGravity.z *= (1.0f / 1.005f);
		}
	}
	else if (this->_ActiveTrap == ItemValue::IV_ExpositionTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_DarknessTrap)
	{
		if (this->_ActiveTrapTimer <= 0)
		{
			if (FogDataPtr)
			{
				FogDataPtr->color = this->_StoredFogData.color;
				FogDataPtr->far_ = this->_StoredFogData.far_;
			}
		}
		else if (this->_ActiveTrapTimer > (TRAP_DURATION * 0.9f))
		{
			if (FogDataPtr)
			{
				_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 0), "Fog Loaded");
				FogDataPtr->color = 0xff000000;
				float fogLerp = (FogDataPtr->far_ - 250.0f) * 0.9f + 250.0f;
				FogDataPtr->far_ = fogLerp;
			}
		}
		else if (this->_ActiveTrapTimer < (TRAP_DURATION * 0.1f))
		{
			if (FogDataPtr)
			{
				FogDataPtr->color = 0xff000000;
				float frac = 1.0f - (float)this->_ActiveTrapTimer / (TRAP_DURATION * 0.1f);
				float fogLerp = FogDataPtr->far_ + (this->_StoredFogData.far_ - FogDataPtr->far_) * frac / (TRAP_DURATION * 0.1f);
				FogDataPtr->far_ = fogLerp;
			}
		}
	}
	else if (this->_ActiveTrap == ItemValue::IV_IceTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_SlowTrap)
	{
		if (MainCharObj2[0] != NULL)
		{
			if (this->_ActiveTrapTimer > (TRAP_DURATION * 0.9f))
			{
				MainCharObj2[0]->PhysData.SpeedMaxH      *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.SpeedCapH      *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.SpeedCapV      *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.RunSpeed       *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.RushSpeed      *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.DashSpeed      *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.JogSpeed       *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.SlideSpeed     *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.PushSpeedMax   *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.NoControlSpeed *= (1.0f / 1.015f);
				MainCharObj2[0]->PhysData.AirResist      *= 1.015f;
			}
			else if (this->_ActiveTrapTimer < (TRAP_DURATION * 0.1f))
			{
				MainCharObj2[0]->PhysData.SpeedMaxH      *= 1.015f;
				MainCharObj2[0]->PhysData.SpeedCapH      *= 1.015f;
				MainCharObj2[0]->PhysData.SpeedCapV      *= 1.015f;
				MainCharObj2[0]->PhysData.RunSpeed       *= 1.015f;
				MainCharObj2[0]->PhysData.RushSpeed      *= 1.015f;
				MainCharObj2[0]->PhysData.DashSpeed      *= 1.015f;
				MainCharObj2[0]->PhysData.JogSpeed       *= 1.015f;
				MainCharObj2[0]->PhysData.SlideSpeed     *= 1.015f;
				MainCharObj2[0]->PhysData.PushSpeedMax   *= 1.015f;
				MainCharObj2[0]->PhysData.NoControlSpeed *= 1.015f;
				MainCharObj2[0]->PhysData.AirResist      *= (1.0f / 1.015f);
			}
		}
	}
	else if (this->_ActiveTrap == ItemValue::IV_CutsceneTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_ReverseTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_LiteratureTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_PongTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_PlatformerTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_FishingTrap)
	{
		// Nothing
	}
	else if (this->_ActiveTrap == ItemValue::IV_TriviaTrap)
	{
		// Nothing
	}

	if (this->_ActiveTrapTimer > 0)
	{
		this->_ActiveTrapTimer--;
		return;
	}

	this->_ActiveTrap = 0;
	this->_TimeStopPos = NJS_VECTOR();

	if (TimerStopped && GameMode != GameMode::GameMode_Event)
	{
		return;
	}

	if (this->_TrapQueue.size() == 0)
	{
		return;
	}

	if (this->_TrapCooldownTimer > 0)
	{
		this->_TrapCooldownTimer--;
		return;
	}

	// Next Trap
	this->_ActiveTrap = this->_TrapQueue.front();
	this->_TrapQueue.pop();

	if (!this->IsActiveTrapValid())
	{
		// Add back to the end of the queue and grab another trap next frame
		this->_TrapQueue.push(this->_ActiveTrap);
		this->_ActiveTrap = 0;

		return;
	}

	this->_ActiveTrapTimer = TRAP_DURATION;
	this->_TrapCooldownTimer = TRAP_COOLDOWN;
	this->_ChaosControlCooldown = TRAP_COOLDOWN;

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
		PlayUnshuffledVoice(2, 1524);
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
			PlayUnshuffledVoice(2, 1413);
		}
		break;
	case ItemValue::IV_TinyTrap:
		PlayUnshuffledVoice(2, 1374);
		break;
	case ItemValue::IV_GravityTrap:
		PlayUnshuffledVoice(2, 671);
		break;
	case ItemValue::IV_ExpositionTrap:
		AddRandomDialogueToQueue();
		break;
	case ItemValue::IV_DarknessTrap:
		if (FogDataPtr)
		{
			this->_StoredFogData.color = FogDataPtr->color;
			this->_StoredFogData.far_ = FogDataPtr->far_;

			PlayUnshuffledVoice(2, 1416);
		}
		//else
		//{
		//	//this->_StoredFogData.color = 0x00000000;
		//	//this->_StoredFogData.far_ = 15000.0f;
		//	//
		//	//LoadFogData_Fogtask("stg13_fog.bin", (FogData*)0x19EEF28);
		//	////LoadFogData_Fogtask("stg10_fog.bin", FogDataPtr);
		//	PlayUnshuffledVoice(2, 1374);
		//}
		break;
	case ItemValue::IV_IceTrap:
		PlayUnshuffledVoice(2, 864);
		if (MainCharObj2[0] != NULL)
		{
			this->_StoredPhysicsData.GroundFriction = MainCharObj2[0]->PhysData.GroundFriction;
			this->_StoredPhysicsData.RunDecel       = MainCharObj2[0]->PhysData.RunDecel;
			this->_StoredPhysicsData.RunBrake       = MainCharObj2[0]->PhysData.RunBrake;

			MainCharObj2[0]->PhysData.GroundFriction = -0.002f;
			MainCharObj2[0]->PhysData.RunDecel       = -0.0012f;
			MainCharObj2[0]->PhysData.RunBrake       = -0.0036f;
		}
		break;
	case ItemValue::IV_SlowTrap:
		PlayUnshuffledVoice(2, 636);
		if (MainCharObj2[0] != NULL)
		{
			this->_StoredPhysicsData.SpeedMaxH      = MainCharObj2[0]->PhysData.SpeedMaxH;
			this->_StoredPhysicsData.SpeedCapH      = MainCharObj2[0]->PhysData.SpeedCapH;
			this->_StoredPhysicsData.SpeedCapV      = MainCharObj2[0]->PhysData.SpeedCapV;
			this->_StoredPhysicsData.RunSpeed       = MainCharObj2[0]->PhysData.RunSpeed;
			this->_StoredPhysicsData.RushSpeed      = MainCharObj2[0]->PhysData.RushSpeed;
			this->_StoredPhysicsData.DashSpeed      = MainCharObj2[0]->PhysData.DashSpeed;
			this->_StoredPhysicsData.JogSpeed       = MainCharObj2[0]->PhysData.JogSpeed;
			this->_StoredPhysicsData.SlideSpeed     = MainCharObj2[0]->PhysData.SlideSpeed;
			this->_StoredPhysicsData.PushSpeedMax   = MainCharObj2[0]->PhysData.PushSpeedMax;
			this->_StoredPhysicsData.NoControlSpeed = MainCharObj2[0]->PhysData.NoControlSpeed;
			this->_StoredPhysicsData.AirResist      = MainCharObj2[0]->PhysData.AirResist;
		}
		break;
	case ItemValue::IV_CutsceneTrap:
		this->AddRandomCutsceneToQueue();
		this->_ActiveTrapTimer = 0;
		this->_TrapCooldownTimer = 0;
		// Don't display Received text until the cutscene actually plays
		return;
		break;
	case ItemValue::IV_ReverseTrap:
		PlayUnshuffledVoice(2, 834);
		this->_ReverseTrapActive = true;
		break;
	case ItemValue::IV_LiteratureTrap:
		PlayUnshuffledVoice(2, 85);
	case ItemValue::IV_PongTrap:
	case ItemValue::IV_PlatformerTrap:
	case ItemValue::IV_FishingTrap:
	case ItemValue::IV_TriviaTrap:
		MinigameManager* minigameManager = &MinigameManager::GetInstance();
		minigameManager->StartMinigame((ItemValue)this->_ActiveTrap);
		break;
	}

	ItemData& receivedItem = this->_ItemData[this->_ActiveTrap];

	std::string message = std::string("Received ");
	message += receivedItem.DisplayName;
	MessageQueue::GetInstance().AddMessage(message);
}

void ItemManager::AddRandomDialogueToQueue()
{
	int nextDialogue = rng() % this->_dialogueOptions.size();
	int dialogueSetLength = this->_dialogueOptions[nextDialogue].size();

	for (int i = 0; i < dialogueSetLength; i++)
	{
		DialogueData data = this->_dialogueOptions[nextDialogue][i];

		if (data.Duration == 0.0f)
		{
			break;
		}

		this->_DialogueQueue.push(data);
	}
}

void ItemManager::OnFrameDialogueQueue()
{
	if (this->_ActiveDialogueTimer > 0)
	{
		this->_ActiveDialogueTimer--;
		return;
	}

	if (TimerStopped)
	{
		return;
	}

	if (this->_DialogueQueue.size() == 0)
	{
		return;
	}

	DialogueData data = this->_DialogueQueue.front();
	this->_DialogueQueue.pop();

	PlayUnshuffledVoice(2, data.VoiceID);
	this->_ActiveDialogueTimer = data.Duration * 60;
}

void ItemManager::AddRandomCutsceneToQueue()
{
	StoryProgressID_1 = (char)0;
	StoryProgressID_2 = (char)1;
	StoryProgressID_3 = (char)1;
	StoryProgressID_4 = (char)0;

	int nextCutscene = rng() % this->_cutsceneOptions.size();
	CutsceneData data = this->_cutsceneOptions[nextCutscene];

	StoryEventID_1 = 0;
	StoryEventID_2 = data.LowID;
	StoryEventID_3 = data.HighID;

	this->_CutsceneQueued = true;
}

void ItemManager::OnFrameCutsceneQueue()
{
	if (!this->_CutsceneQueued &&
		GameMode == GameMode::GameMode_Event &&
		StoryProgressID_3 != 0x03)
	{
		// Place the "Finished" Event
		StoryProgressID_1 = (char)0;
		StoryProgressID_2 = (char)1;
		StoryProgressID_3 = (char)1;

		StoryEventID_1 = 2;
		StoryEventID_2 = 0xFF;
		StoryEventID_3 = 0xFF;
	}

	if (GameMode == GameMode::GameMode_LoadStory)
	{
		if (this->_CutsceneQueued)
		{
			std::string message = std::string("Received Cutscene Trap");
			MessageQueue::GetInstance().AddMessage(message);
		}

		this->_CutsceneQueued = false;
	}
}

std::vector<int> ItemManager::GetChaosEmeraldAddresses()
{
	std::vector<int> result;

	for (int i = IV_WhiteChaosEmerald; i <= IV_BlueChaosEmerald; i++)
	{
		if (this->_ItemData.find(i) != this->_ItemData.end())
		{
			ItemData& itemData = this->_ItemData[i];
			result.push_back(itemData.Address);
		}
	}

	return result;
}

bool AnimalSlotAvailable()
{
	int animalsInInventory = 0;

	if (CurrentCharacter == Characters_Sonic ||
		CurrentCharacter == Characters_Tails ||
		CurrentCharacter == Characters_MechTails ||
		CurrentCharacter == Characters_Knuckles)
	{
		animalsInInventory = HeroAnimalInventoryCount;
	}
	else
	{
		animalsInInventory = DarkAnimalInventoryCount;
	}

	return animalsInInventory < 10;
}

bool HatSlotAvailable()
{
	int emptySlotCount = 0;

	for (int i = 0; i < 24; i++)
	{
		SA2BHat hatType = RealChaoHatSlots[i].Type;
		if (hatType == (SA2BHat)-1)
		{
			// This slot is empty
			emptySlotCount++;
		}
	}

	int hatsInInventory = 0;

	for (int i = 0; i < GardenItemInventoryCount; i++)
	{
		ChaoGardenObject gardenObject = GardenItemInventory[i];

		if (gardenObject.ItemCategory == ChaoItemCategory::ChaoItemCategory_Hat)
		{
			// This is a hat
			hatsInInventory++;
		}
	}

	return (emptySlotCount - hatsInInventory) > 0;
}

bool SeedSlotAvailable()
{
	int emptySlotCount = 0;

	for (int i = 0; i < 12; i++)
	{
		ChaoSeed fruitType = RealChaoSeedSlots[i].Type;
		if (fruitType == ChaoSeed::ChaoSeed_None)
		{
			// This slot is empty
			emptySlotCount++;
		}
	}

	int seedsInInventory = 0;

	for (int i = 0; i < GardenItemInventoryCount; i++)
	{
		ChaoGardenObject gardenObject = GardenItemInventory[i];

		if (gardenObject.ItemCategory == ChaoItemCategory::ChaoItemCategory_Seed)
		{
			// This is a seed
			seedsInInventory++;
		}
	}

	return (emptySlotCount - seedsInInventory) > 0;
}

bool FruitSlotAvailable()
{
	int emptySlotCount = 0;

	for (int i = 0; i < 20; i++)
	{
		SA2BFruit fruitType = RealChaoFruitSlots[i].Type;
		if (fruitType == SA2BFruit::SA2BFruit_None)
		{
			// This slot is empty
			emptySlotCount++;
		}
	}

	int fruitsInInventory = 0;

	for (int i = 0; i < GardenItemInventoryCount; i++)
	{
		ChaoGardenObject gardenObject = GardenItemInventory[i];

		if (gardenObject.ItemCategory == ChaoItemCategory::ChaoItemCategory_Fruit)
		{
			// This is a fruit
			fruitsInInventory++;
		}
	}

	return (emptySlotCount - fruitsInInventory) > 0;
}

bool ChaoSlotAvailable()
{
	int emptySlotCount = 0;

	for (int i = 0; i < 24; i++)
	{
		ChaoType chaoType = ChaoSlots[i].data.Type;
		if (chaoType == ChaoType::ChaoType_Empty)
		{
			// This slot is empty
			emptySlotCount++;
		}
	}

	int eggsInInventory = 0;

	for (int i = 0; i < GardenItemInventoryCount; i++)
	{
		ChaoGardenObject gardenObject = GardenItemInventory[i];

		if (gardenObject.ItemCategory == ChaoItemCategory::ChaoItemCategory_Egg)
		{
			// This is an egg
			eggsInInventory++;
		}
	}

	return (emptySlotCount - eggsInInventory) > 0;
}

void ItemManager::OnFrameChaoGardenQueue()
{
	if (CurrentLevel != LevelIDs::LevelIDs_ChaoWorld)
	{
		this->_chaoEntryTimer = 0;
		this->_lastAnimalCount = 10;
		return;
	}
	else
	{
		this->_chaoEntryTimer++;
	}

	if (this->_chaoEntryTimer < IM_CHAO_MEMORY_CHECK_ENTRY_TIME)
	{
		// Only handle items while in Chao World, otherwise it may be wrong
		return;
	}

	// Animal Handling
	if (this->_ChaoAnimalsUsed < SavedChaoAnimalsUsed)
	{
		this->_ChaoAnimalsUsed = SavedChaoAnimalsUsed;
	}

	bool droppingAnimals = false;

	if (this->_animalDropoffTimer < ANIMAL_DROPOFF_COOLDOWN)
	{
		droppingAnimals = true;
		if (GameState != GameStates::GameStates_Pause)
		{
			this->_animalDropoffTimer++;
		}
	}
	else if (CurrentCharacter == Characters_Sonic ||
			 CurrentCharacter == Characters_Tails ||
			 CurrentCharacter == Characters_MechTails ||
			 CurrentCharacter == Characters_Knuckles)
	{
		if (this->_lastAnimalCount > HeroAnimalInventoryCount)
		{
			droppingAnimals = true;
			this->_lastAnimalCount = HeroAnimalInventoryCount;
			this->_animalDropoffTimer = 0;
		}
	}
	else
	{
		if (this->_lastAnimalCount > DarkAnimalInventoryCount)
		{
			droppingAnimals = true;
			this->_lastAnimalCount = DarkAnimalInventoryCount;
			this->_animalDropoffTimer = 0;
		}
	}

	if (this->_ChaoAnimalQueue.size() > this->_ChaoAnimalsUsed &&
		!droppingAnimals &&
		AnimalSlotAvailable())
	{
		ItemData& receivedItem = this->_ItemData[0x500 + this->_ChaoAnimalQueue[this->_ChaoAnimalsUsed].ItemType];

		std::string message = std::string("Received ");
		message += receivedItem.DisplayName;
		MessageQueue::GetInstance().AddMessage(message);

		if (CurrentCharacter == Characters_Sonic ||
			CurrentCharacter == Characters_Tails ||
			CurrentCharacter == Characters_MechTails ||
			CurrentCharacter == Characters_Knuckles)
		{
			HeroAnimalInventory[HeroAnimalInventoryCount].Type = (SA2BAnimal)this->_ChaoAnimalQueue[this->_ChaoAnimalsUsed].ItemType;
			HeroAnimalInventoryCount++;
			this->_lastAnimalCount = HeroAnimalInventoryCount;
		}
		else
		{
			DarkAnimalInventory[DarkAnimalInventoryCount].Type = (SA2BAnimal)this->_ChaoAnimalQueue[this->_ChaoAnimalsUsed].ItemType;
			DarkAnimalInventoryCount++;
			this->_lastAnimalCount = HeroAnimalInventoryCount;
		}

		SavedChaoAnimalsUsed++;
		this->_ChaoAnimalsUsed++;
	}
	// End Animal Handling

	// Hat Handling
	if (this->_ChaoHatsUsed < SavedChaoHatsUsed)
	{
		this->_ChaoHatsUsed = SavedChaoHatsUsed;
	}

	if (GardenItemInventoryCount < 5 &&
		this->_ChaoHatQueue.size() > this->_ChaoHatsUsed &&
		HatSlotAvailable())
	{
		ItemData& receivedItem = this->_ItemData[0x400 + this->_ChaoHatQueue[this->_ChaoHatsUsed].ItemType];

		std::string message = std::string("Received ");
		message += receivedItem.DisplayName;
		MessageQueue::GetInstance().AddMessage(message);

		GardenItemInventory[GardenItemInventoryCount].ItemCategory = this->_ChaoHatQueue[this->_ChaoHatsUsed].ItemCategory;
		GardenItemInventory[GardenItemInventoryCount].ItemType     = this->_ChaoHatQueue[this->_ChaoHatsUsed].ItemType;

		GardenItemInventoryCount++;
		SavedChaoHatsUsed++;
		this->_ChaoHatsUsed++;
	}
	// End Hat Handling

	// Seed Handling
	if (this->_ChaoSeedsUsed < SavedChaoSeedsUsed)
	{
		this->_ChaoSeedsUsed = SavedChaoSeedsUsed;
	}

	if (GardenItemInventoryCount < 5 &&
		this->_ChaoSeedQueue.size() > this->_ChaoSeedsUsed &&
		SeedSlotAvailable())
	{
		ItemData& receivedItem = this->_ItemData[0x300 + this->_ChaoSeedQueue[this->_ChaoSeedsUsed].ItemType];

		std::string message = std::string("Received ");
		message += receivedItem.DisplayName;
		MessageQueue::GetInstance().AddMessage(message);

		GardenItemInventory[GardenItemInventoryCount].ItemCategory = this->_ChaoSeedQueue[this->_ChaoSeedsUsed].ItemCategory;
		GardenItemInventory[GardenItemInventoryCount].ItemType     = this->_ChaoSeedQueue[this->_ChaoSeedsUsed].ItemType;

		GardenItemInventoryCount++;
		SavedChaoSeedsUsed++;
		this->_ChaoSeedsUsed++;
	}
	// End Seed Handling

	// Fruit Handling
	if (this->_ChaoFruitsUsed < SavedChaoFruitsUsed)
	{
		this->_ChaoFruitsUsed = SavedChaoFruitsUsed;
	}

	if (GardenItemInventoryCount < 5 &&
		this->_ChaoFruitQueue.size() > this->_ChaoFruitsUsed &&
		FruitSlotAvailable())
	{
		ItemData& receivedItem = this->_ItemData[0x200 + this->_ChaoFruitQueue[this->_ChaoFruitsUsed].ItemType];

		std::string message = std::string("Received ");
		message += receivedItem.DisplayName;
		MessageQueue::GetInstance().AddMessage(message);

		GardenItemInventory[GardenItemInventoryCount].ItemCategory = this->_ChaoFruitQueue[this->_ChaoFruitsUsed].ItemCategory;
		GardenItemInventory[GardenItemInventoryCount].ItemType     = this->_ChaoFruitQueue[this->_ChaoFruitsUsed].ItemType;

		GardenItemInventoryCount++;
		SavedChaoFruitsUsed++;
		this->_ChaoFruitsUsed++;
	}
	// End Fruit Handling

	// Egg Handling
	if (this->_ChaoEggsUsed < SavedChaoEggsUsed)
	{
		this->_ChaoEggsUsed = SavedChaoEggsUsed;
	}

	if (GardenItemInventoryCount < 5 &&
		this->_ChaoEggQueue.size() > this->_ChaoEggsUsed &&
		ChaoSlotAvailable())
	{
		ItemData& receivedItem = this->_ItemData[0x100 + this->_ChaoEggQueue[this->_ChaoEggsUsed].ItemType];

		std::string message = std::string("Received ");
		message += receivedItem.DisplayName;
		MessageQueue::GetInstance().AddMessage(message);

		GardenItemInventory[GardenItemInventoryCount].ItemCategory = this->_ChaoEggQueue[this->_ChaoEggsUsed].ItemCategory;
		GardenItemInventory[GardenItemInventoryCount].ItemType     = this->_ChaoEggQueue[this->_ChaoEggsUsed].ItemType;

		GardenItemInventoryCount++;
		SavedChaoEggsUsed++;
		this->_ChaoEggsUsed++;
	}
	// End Egg Handling
}

void ItemManager::HandleEgg(int item_id)
{
	this->_ChaoEggQueue.push_back(ChaoGardenObject(1, item_id - 0x100));
}

void ItemManager::HandleFruit(int item_id)
{
	this->_ChaoFruitQueue.push_back(ChaoGardenObject(3, item_id - 0x200));
}

void ItemManager::HandleSeed(int item_id)
{
	this->_ChaoSeedQueue.push_back(ChaoGardenObject(7, item_id - 0x300));
}

void ItemManager::HandleHat(int item_id)
{
	this->_ChaoHatQueue.push_back(ChaoGardenObject(9, item_id - 0x400));
}

void ItemManager::HandleAnimal(int item_id)
{
	this->_ChaoAnimalQueue.push_back(ChaoGardenObject(13, item_id - 0x500));
}
