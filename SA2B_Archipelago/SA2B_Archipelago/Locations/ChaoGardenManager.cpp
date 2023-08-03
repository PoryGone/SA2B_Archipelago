#include "../pch.h"
#include "ChaoGardenManager.h"
#include "LocationManager.h"
#include "../Utilities/MessageQueue.h"


DataPointer(char, ChaoEggsRandomized, 0x19F6460);
DataPointer(char, ChaoNamesUsed, 0x19F6461);
DataPointer(char, ChaoGardenTimescale, 0x01312DE4);


struct BlackMarketStockItem
{
	int Cost;
	int gap_4;
	int16_t unknown_8;
	int16_t NameTextIndex;
	int16_t DescTextIndex;
	int16_t gap_E;
};

DataArray(BlackMarketStockItem, BlackMarketEggStock,   0x8A7B68, 0x45);
DataArray(BlackMarketStockItem, BlackMarketSeedStock,  0x8A7FB8, 0x7);
DataArray(BlackMarketStockItem, BlackMarketFruitStock, 0x8A8028, 0x18);
DataArray(BlackMarketStockItem, BlackMarketHatStock,   0x8A81A8, 0x55);
DataArray(BlackMarketStockItem, BlackMarketMenuStock,  0x8A86F8, 0x3);


ObjectMaster* BlackMarketObject = nullptr;
void __cdecl alg_blackmarket_prolog_r(ObjectMaster* obj);
Trampoline alg_blackmarket_prolog_t(0x58BFC0, 0x58BFC5, alg_blackmarket_prolog_r);
void __cdecl alg_blackmarket_prolog_r(ObjectMaster* obj)
{
	((void(*)(ObjectMaster*))alg_blackmarket_prolog_t.Target())(obj);
	BlackMarketObject = obj;
}

// Black Market Purchase "Trampoline"
static void __cdecl BlackMarketPurchase()
{
	if (BlackMarketObject && BlackMarketObject->Data2.BlackMarket)
	{
		LocationManager::getInstance().SendBlackMarketLocationCheck(BlackMarketObject->Data2.BlackMarket->MenuSelection);
		BlackMarketObject->Data2.BlackMarket->MenuSelection = 0;
		BlackMarketObject->Data2.BlackMarket->MenuOffset = 0;
	}
}
// End Black Market Purchase "Trampoline"


void ChaoGardenManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	this->_helperFunctions = &helperFunctions;
	this->_archipelagoManager = &ArchipelagoManager::getInstance();

}

void ChaoGardenManager::OnFrameFunction()
{
	if (!this->_archipelagoManager->IsInit() || !this->_archipelagoManager->IsAuth())
	{
		//Make No Characters have Chao Garden Access
		WriteData<8>((void*)0x1DEF829, 0x00);

		return;
	}

	//Make All Characters have Chao Garden Access
	WriteData<8>((void*)0x1DEF829, 0x01);

	if (!this->_chaoEnabled)
	{
		return;
	}

	// Make sure Hero/Dark Gardens are always unlocked
	ChaoGardensUnlocked = 0x56;

	// Remove Hero/Dark Race restrictions
	WriteData<2>((void*)0x531774, '\x90');
	WriteData<2>((void*)0x5314CF, '\x90');

	// Handle Separate Chao Saves
	std::string chaoFileName = ArchipelagoManager::getInstance().GetSeedNameAndPlayer().substr(0, 12);

	for (int i = 0; i < 12; i++)
	{
		WriteData<1>((void*)(0x8ACF4B + i), chaoFileName[i]);
		WriteData<1>((void*)(0xC70E5C + i), chaoFileName[i]);
		WriteData<1>((void*)(0x1366067 + i), chaoFileName[i]);
	}

	if (CurrentLevel != LevelIDs::LevelIDs_ChaoWorld)
	{
		return;
	}

	// Prevent Game Overs in Chao Garden
	Life_Count[0] = 3;

	this->HandleStartingEggs();
	this->HandleSubsequentEggs();

	// Handle Time Scale
	std::string timescaleStr = "Chao Timescale: ";
	timescaleStr += std::to_string(this->_timescale);
	timescaleStr += "x";
	_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 2), timescaleStr.c_str());
	ChaoGardenTimescale = 120.0f / this->_timescale;

	// Black Market
	if (this->_blackMarketSlots > 0)
	{
		// Write jump at first 5 bytes here to function handling sending location check
		WriteCall(static_cast<void*>((void*)0x58AFD5), &BlackMarketPurchase);
		WriteData<3>((void*)0x58AFDA, '\x90');
		WriteData<5>((void*)0x58AFDF, '\x90');

		WriteData<3>((void*)0x58B090, '\x90');

		if (CurrentChaoArea == 0x06 && BlackMarketObject != nullptr && BlackMarketObject->Data2.BlackMarket != nullptr)
		{
			std::vector<int> ActiveMarketSlots = LocationManager::getInstance().GetAvailableBlackMarketLocations();
			BlackMarketItemCount = min(10, ActiveMarketSlots.size());

			for (int i = 0; i < BlackMarketItemCount; i++)
			{
				int SlotIdx = ActiveMarketSlots[i];

				BlackMarketInventory[i].Category = ChaoItemCategory::ChaoItemCategory_Egg;
				BlackMarketInventory[i].Type = i;

				BlackMarketEggStock[i].NameTextIndex = this->_NameStringIndeces[i];
				BlackMarketEggStock[i].DescTextIndex = 96;
				if (this->_blackMarketData.find((SlotIdx * 40) + 36) != this->_blackMarketData.end())
				{
					BlackMarketEggStock[i].Cost = this->_blackMarketData[(SlotIdx * 40) + 36];
				}
				// Hopefully handle Model stuff here

				// Item Names
				std::string newName = "";
				for (int chr_idx = 0; chr_idx < 20; chr_idx++)
				{
					if (this->_blackMarketData.find((SlotIdx * 40) + chr_idx) != this->_blackMarketData.end())
					{
						newName += this->_blackMarketData[(SlotIdx * 40) + chr_idx];
					}
				}

				for (int j = 0; j < newName.length(); j++)
				{
					int writeAddr = (int)BlackMarketObject->Data2.BlackMarket->textPtr + this->_NameStringOffsets[i] + j;
					WriteData<1>((void*)writeAddr, newName[j]);
				}
				int writeAddr = (int)BlackMarketObject->Data2.BlackMarket->textPtr + this->_NameStringOffsets[i] + newName.length();
				WriteData<1>((void*)writeAddr, '\x00');
				// End Item Names
			}

			if (BlackMarketItemCount == 0)
			{
				BlackMarketInventory[0].Category = ChaoItemCategory::ChaoItemCategory_Fruit;
				BlackMarketInventory[0].Type = 1;
				BlackMarketItemCount = 1;
			}

			// Item Descriptions
			if (ActiveMarketSlots.size())
			{
				int SlotIdx = ActiveMarketSlots[BlackMarketObject->Data2.BlackMarket->MenuSelection];
				std::string newDesc = "for ";
				for (int chr_idx = 0; chr_idx < 16; chr_idx++)
				{
					if (this->_blackMarketData.find((SlotIdx * 40) + 20 + chr_idx) != this->_blackMarketData.end())
					{
						newDesc += this->_blackMarketData[(SlotIdx * 40) + 20 + chr_idx];
					}
				}
				newDesc += ".";

				for (int j = 0; j < newDesc.length(); j++)
				{
					int writeAddr = (int)BlackMarketObject->Data2.BlackMarket->textPtr + 0X757 + j;
					WriteData<1>((void*)writeAddr, newDesc[j]);
				}
				int writeAddr = (int)BlackMarketObject->Data2.BlackMarket->textPtr + 0X757 + newDesc.length();
				WriteData<1>((void*)writeAddr, '\x00');
			}
			// End Item Descriptions




			//WriteData<1>((void*)((int)BlackMarketObject->Data2.BlackMarket->textPtr + 0x194), '\x47');
			//
			//if (BlackMarketObject->Data2.BlackMarket->SubMenu == 0x01)
			//{
			//	std::string timescaleStr = "Black Market Obj: ";
			//	timescaleStr += std::to_string((int)BlackMarketObject->Data2.BlackMarket->textPtr);
			//	_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 3), timescaleStr.c_str());
			//}
		}
	}
	// End Black Market

	if (GameState == GameStates::GameStates_Pause)
	{
		return;
	}

	this->_timer++;

	if (this->_timer < CGM_MEMORY_CHECK_TIME)
	{
		return;
	}

	this->_timer = 0;
}

void ChaoGardenManager::OnInputFunction()
{
	Uint32 PressedButtons = ControllersRaw->press;
	if ((PressedButtons & 0b100000) != 0) // Down
	{
		switch (this->_timescale)
		{
		case 2:
			this->_timescale = 1;
			break;
		case 5:
			this->_timescale = 2;
			break;
		case 10:
			this->_timescale = 5;
			break;
		case 15:
			this->_timescale = 10;
			break;
		}
	}
	else if ((PressedButtons & 0b10000) != 0) // Up
	{
		switch (this->_timescale)
		{
		case 1:
			this->_timescale = 2;
			break;
		case 2:
			this->_timescale = 5;
			break;
		case 5:
			this->_timescale = 10;
			break;
		case 10:
			this->_timescale = 15;
			break;
		}
	}
}

void ChaoGardenManager::HandleStartingEggs()
{
	if (ChaoEggsRandomized != 0b1111)
	{
		for (int chaoIdx = 0; chaoIdx < 24; chaoIdx++)
		{
			ChaoDataBase chaoData = ChaoSlots[chaoIdx].data;

			if (chaoData.Type != ChaoType::ChaoType_Egg)
			{
				continue;
			}

			if (chaoData.Garden != CurrentChaoArea)
			{
				continue;
			}

			if (this->_defaultEggMap.find(chaoIdx) != this->_defaultEggMap.end())
			{
				switch (CurrentChaoArea)
				{
				case 0x01:
					// Neutral Garden
					if ((ChaoEggsRandomized & 0b11) == 0b11)
					{
						continue;
					}
					else if ((ChaoEggsRandomized & 0b11) == 0b01)
					{
						ChaoEggsRandomized = ChaoEggsRandomized | 0b11;
					}
					else
					{
						ChaoEggsRandomized = ChaoEggsRandomized | 0b01;
					}
					break;
				case 0x02:
					// Hero Garden
					if ((ChaoEggsRandomized & 0b100) == 0b100)
					{
						continue;
					}
					else
					{
						ChaoEggsRandomized = ChaoEggsRandomized | 0b100;
					}
					break;
				case 0x03:
					// Dark Garden
					if ((ChaoEggsRandomized & 0b1000) == 0b1000)
					{
						continue;
					}
					else
					{
						ChaoEggsRandomized = ChaoEggsRandomized | 0b1000;
					}
					break;
				}

				// Starting Chao Names
				for (int i = 0; i < 7; i++)
				{
					ChaoSlots[chaoIdx].data.Name[i] = (char)this->_defaultChaoNameMap[i + (chaoIdx * 7)];
				}

				// Starting Chao Colors
				unsigned char color = this->_defaultEggMap[chaoIdx];

				if (color != 255)
				{
					bool twoTone = false, shiny = false, jewel = false;

					if (color == 0)
					{
						twoTone = true;
					}

					if (color > 13)
					{
						color -= 13;
						twoTone = true;
					}

					if (color > 13)
					{
						color -= 14;
						twoTone = false;
						shiny = true;
					}

					if (color > 13)
					{
						color -= 13;
						twoTone = false;
						shiny = false;
						jewel = true;
					}

					if (jewel)
					{
						ChaoSlots[chaoIdx].data.Texture = color;
					}
					else
					{
						ChaoSlots[chaoIdx].data.MonotoneHighlights = !twoTone;
						ChaoSlots[chaoIdx].data.Color = color;
						ChaoSlots[chaoIdx].data.Shiny = shiny;
					}
					ChaoSlots[chaoIdx].data.EggColor = color;
				}
			}
		}
	}
}

void ChaoGardenManager::HandleSubsequentEggs()
{
	if (ChaoNamesUsed == 0)
	{
		ChaoNamesUsed = 4;
	}

	if (ChaoNamesUsed > this->_namesUsed)
	{
		this->_namesUsed = ChaoNamesUsed;
	}

	if (this->_namesUsed >= 30)
	{
		return;
	}

	for (int chaoIdx = 0; chaoIdx < 24; chaoIdx++)
	{
		ChaoDataBase chaoData = ChaoSlots[chaoIdx].data;

		if (chaoData.Type != ChaoType::ChaoType_Egg)
		{
			continue;
		}

		if (chaoData.Garden != CurrentChaoArea)
		{
			continue;
		}

		bool emptyName = true;
		for (int i = 0; i < 7; i++)
		{
			if (chaoData.Name[i] != 0x00)
			{
				emptyName = false;
				break;
			}
		}

		if (!emptyName)
		{
			continue;
		}

		for (int i = 0; i < 7; i++)
		{
			ChaoSlots[chaoIdx].data.Name[i] = (char)this->_defaultChaoNameMap[i + (this->_namesUsed * 7)];
		}

		this->_namesUsed++;
		ChaoNamesUsed++;
	}
}

void ChaoGardenManager::SetChaoEnabled(bool chaoEnabled)
{
	// Anything Chao-related is active
	this->_chaoEnabled = chaoEnabled;
}

void ChaoGardenManager::SetChaoRaceEnabled(bool chaoRaceEnabled)
{
	this->_chaoRaceEnabled = chaoRaceEnabled;

	if (chaoRaceEnabled)
	{
		this->SetChaoEnabled(true);
	}
}

void ChaoGardenManager::SetChaoKarateEnabled(bool chaoKarateEnabled)
{
	this->_chaoKarateEnabled = chaoKarateEnabled;

	if (chaoKarateEnabled)
	{
		this->SetChaoEnabled(true);
	}
}

void ChaoGardenManager::SetChaoStatsEnabled(int chaoStatsEnabled)
{
	this->_chaoStatsEnabled = chaoStatsEnabled;

	if (chaoStatsEnabled > 0)
	{
		this->SetChaoEnabled(true);
	}
}

void ChaoGardenManager::SetChaoBodyPartsEnabled(bool chaoBodyPartsEnabled)
{
	this->_chaoBodyPartsEnabled = chaoBodyPartsEnabled;

	if (chaoBodyPartsEnabled)
	{
		this->SetChaoEnabled(true);
	}
}

void ChaoGardenManager::SetChaoKindergartenEnabled(bool chaoKindergartenEnabled)
{
	this->_chaoKindergartenEnabled = chaoKindergartenEnabled;

	if (chaoKindergartenEnabled)
	{
		this->SetChaoEnabled(true);
	}
}

void ChaoGardenManager::SetBlackMarketSlots(int blackMarketSlots)
{
	this->_blackMarketSlots = blackMarketSlots;

	if (blackMarketSlots > 0)
	{
		this->SetChaoEnabled(true);
	}
}

void ChaoGardenManager::SetBlackMarketData(std::map<int, int> map)
{
	this->_blackMarketData = map;
}

void ChaoGardenManager::SetDefaultEggMap(std::map<int, int> map)
{
	this->_defaultEggMap = map;
}

void ChaoGardenManager::SetDefaultChaoNameMap(std::map<int, int> map)
{
	this->_defaultChaoNameMap = map;
}
