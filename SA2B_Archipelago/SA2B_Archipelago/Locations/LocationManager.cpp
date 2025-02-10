#include "../pch.h"
#include "LocationManager.h"
#include "LocationData.h"
#include "StageSelectData.h"
#include "../Items/ItemManager.h"
#include "../Items/Minigames/MinigameManager.h"
#include "../Utilities/MessageQueue.h"

DataPointer(char, ShowHud, 0x0174AFCC);

// Chao Key "Trampoline"
static void __cdecl PickedUpChaoKey()
{
	__asm
	{
		push ecx
	}

	LocationManager::getInstance().SendChaoKeyLocationCheck();

	__asm
	{
		pop ecx
		mov byte ptr[ecx], 0
		add ecx, 14h
	}
}
// End Chao Key Trampoline

// Omochao "Trampoline"
static void __cdecl ActivatedOmochao()
{
	__asm
	{
		fadd qword ptr ds:[0x908348]
		fstp dword ptr[eax + 4]
	}

	LocationManager::getInstance().SendOmochaoLocationCheck();
}
// End Omochao "Trampoline"

// Gold Beetle "Trampoline"
static void __cdecl GoldBeetleDestroyed()
{
	LocationManager::getInstance().SendGoldBeetleLocationCheck();
	if (MainCharObj2[0] && (MainCharObj2[0]->Powerups & Powerups_Invincibility) != 0)
	{
		AddScore(2000);
	}
	else
	{
		AddScore(1000);
	}
}
// End Gold Beetle "Trampoline"

// Item Box "Trampolines"
static void __cdecl ActivatedFloatingItemBox(int pnum, int tnum)
{
	__asm
	{
		push ebx
		push edi
		push ebp
	}

	ObjectMaster* itemBox;
	__asm
	{
		mov itemBox, edx
	}

	LocationManager::getInstance().SendItemBoxLocationCheck(itemBox);

	__asm
	{
		pop ebp
		pop edi
		pop ebx
	}

	DisplayItemBoxItem(pnum, tnum);

	__asm
	{
		movzx ecx, byte ptr[ebx + 3h]
	}
}

static void __cdecl ActivatedGroundedItemBox(int pnum, int tnum)
{
	__asm
	{
		push ebx
		push edi
		push ebp
	}

	ObjectMaster* itemBox;
	__asm
	{
		mov itemBox, edx
	}

	LocationManager::getInstance().SendItemBoxLocationCheck(itemBox);

	__asm
	{
		pop ebp
		pop edi
		pop ebx
	}

	DisplayItemBoxItem(pnum, tnum);

	__asm
	{
		mov	ecx, dword ptr[edi + 3Ch]
	}
}

static void __cdecl ActivatedBalloonItemBox(int pnum, int tnum)
{
	__asm
	{
		push edx
		push ecx
		push ebx
		push edi
	}

	ObjectMaster* itemBox;
	__asm
	{
		mov itemBox, edx
	}

	LocationManager::getInstance().SendItemBoxLocationCheck(itemBox);

	__asm
	{
		pop edi
		pop ebx
		pop ecx
	}

	DisplayItemBoxItem(pnum, tnum);

	__asm
	{
		pop edx
		mov	ecx, dword ptr[edx + 3Ch]
	}
}

static void __cdecl ActivatedSunglassesItemBox(int pnum, int tnum)
{
	__asm
	{
		push ebx
		push edi
		push ebp
	}

	ObjectMaster* itemBox;
	__asm
	{
		mov itemBox, edx
	}

	LocationManager::getInstance().SendItemBoxLocationCheck(itemBox);

	__asm
	{
		pop ebp
		pop edi
		pop ebx
	}

	DisplayItemBoxItem(pnum, tnum);

	__asm
	{
		mov	ecx, dword ptr[esi + 3Ch]
	}
}
// End Item Box "Trampolines"

// Animal Count
struct AnimalCountObj
{
	void* field_0;
	void* field_4;
	int AnimalCount;
	int MaxAnimalCount;
};

struct AnimalCounterObj
{
	int field_0[13];
	AnimalCountObj* AnimalCount;
};

DataPointer(AnimalCounterObj*, AnimalCounter, 0x1A5A344);
DataPointer(char, SS_SelectedTile, 0x1D1BF08);
// End Animal Count


DataPointer(ChaoKarateManager*, KarateManager, 0x1A5D148);
DataPointer(unsigned int, BlackMarketTokenCount, 0x1DEE41C);

ObjectMaster* LoadBig(NJS_VECTOR* position)
{
	ObjectMaster* obj = AllocateObjectMaster(Big_Main_2, 2, "ObjectBig");
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
				position->y += 8.0f;
				ent_data_1->Position = *position;
				ent_data_1->Rotation = MainCharObj1[0]->Rotation;
				ent_data_1->Scale.x = 2;
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

float dist(NJS_POINT3 a, NJS_POINT3 b)
{
	return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2) + pow((b.z - a.z), 2));
}


void LocationManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	this->_helperFunctions = &helperFunctions;
	this->_archipelagoManager = &ArchipelagoManager::getInstance();

	// Gold Beetle "Trampoline"
	WriteCall(static_cast<void*>((void*)0x00505F48), &GoldBeetleDestroyed);

	WriteCall(static_cast<void*>((void*)0x006BE973), &ActivatedOmochao);
	WriteData<4>((void*)0x006BE978, '\x90');


	InitializeLevelClearChecks(this->_LevelClearData);
	InitializeBossRushChecks(this->_BossRushData);
	InitializeChaoKeyChecks(this->_ChaoKeyData);
	InitializePipeChecks(this->_PipeData);
	InitializeHiddenChecks(this->_HiddenData);
	InitializeGoldBeetleChecks(this->_GoldBeetleData);
	InitializeOmochaoChecks(this->_OmochaoData);
	InitializeAnimalChecks(this->_AnimalData);
	InitializeItemBoxChecks(this->_ItemBoxData);
	InitializeBigChecks(this->_BigData);

	InitializeChaoGardenChecks(this->_ChaoGardenData);
	InitializeChaoStatChecks(this->_ChaoStatData);
	InitializeChaoBodyPartChecks(this->_ChaoBodyPartData);
	InitializeChaoKindergartenChecks(this->_ChaoKindergartenData);
	InitializeBlackMarketChecks(this->_BlackMarketLocationData);
	InitializeChaoRacePacks(this->_ChaoRacePacks);

	InitializeKartRaceChecks(this->_KartRaceData);

	for (int i = 0; i < 7; i++)
	{
		this->_CollectedChaoStats[i] = std::vector<int>();
	}
}

void LocationManager::OnInputFunction()
{
	if (GameMode != GameMode::GameMode_Level)
	{
		this->_inBigFishing = false;
		TimeStopped = 0;
		this->_FreezePos = NJS_VECTOR();
		this->_BigIndicators.clear();

		return;
	}

	if (MainCharObj1[0] == NULL)
	{
		return;
	}

	if (this->_bigEnabled)
	{
		shouldShowBigPrompt = false;
		if (GameState != GameStates::GameStates_Pause)
		{
			MinigameManager* minigameManager = &MinigameManager::GetInstance();

			if (minigameManager->state == MinigameState::MGS_None && this->_inBigFishing)
			{
				TimeStopped = 0;
				WriteData<1>((void*)0x4D2E50, 0);
				this->_inBigFishing = false;
				if ((MainCharObj1[0]) && (MainCharObj2[0]))
				{
					MainCharObj1[0]->Status &= ~(1 << StatusBits::StatusBits_DisableControl);
					MainCharObj2[0]->Powerups &= ~(1 << PowerupBits::PowerupBits_Invincibility);
				}
			}

			if (this->_inBigFishing)
			{
				// TODO: Handle Cannon's Core switches
				TimeStopped = 2;
				WriteData<1>((void*)0x4D2E50, 2);
				if ((MainCharObj1[0]) && (MainCharObj2[0]))
				{
					MainCharObj1[0]->Action = Action_None;
					MainCharObj1[0]->NextAction = Action_None;
					MainCharObj1[0]->Status |= (1 << StatusBits::StatusBits_DisableControl);
					MainCharObj2[0]->Powerups |= (1 << PowerupBits::PowerupBits_Invincibility);
					MainCharObj2[0]->UnderwaterTime = 0;
					MainCharObj1[0]->Position = this->_FreezePos;
					MainCharObj2[0]->Speed.x = 0.0;
					MainCharObj2[0]->Speed.y = 0.0;
					MainCharObj2[0]->Speed.z = 0.0;
				}
			}

			Uint32 HeldButtons = ControllersRaw->on;
			Uint32 PressedButtons = ControllersRaw->press;

			if (minigameManager->state == MinigameState::MGS_None)
			{
				for (int i = BigCheck::BC_BEGIN; i < BigCheck::BC_NUM_CHECKS; i++)
				{
					if (this->_BigData.find(i) != this->_BigData.end())
					{
						BigCheckData& checkData = this->_BigData[i];

						if (!checkData.CheckSent && checkData.LevelID == CurrentLevel)
						{
							NJS_VECTOR relevantPos = checkData.Position;

							if (this->_logicDifficulty > 0 && dist(checkData.HardPosition, NJS_VECTOR({ 0.0f, 0.0f, 0.0f })) > 1.0f)
							{
								relevantPos = checkData.HardPosition;
							}

							if ((checkData.ShowIndicator && this->_logicDifficulty == 0) ||
								(checkData.ShowIndicator && this->_logicDifficulty > 0 &&
									(checkData.HardPosition.x + checkData.HardPosition.y + checkData.HardPosition.z) == 0.0f) ||
								(checkData.ShowIndicatorHard && this->_logicDifficulty > 0))
							{
								if (this->_BigIndicators.find(i) == this->_BigIndicators.end())
								{
									ObjectMaster* newBig = LoadBig(&relevantPos);
									this->_BigIndicators[i] = newBig;
								}
								else if (this->_BigIndicators[i] != nullptr && this->_BigIndicators[i]->Data1.Entity != nullptr)
								{
									Angle newZrot = this->_BigIndicators[i]->Data1.Entity->Rotation.z + 1;
									newZrot = newZrot % 360;
									this->_BigIndicators[i]->Data1.Entity->Rotation.z = newZrot;
								}
								else
								{
									ObjectMaster* newBig = LoadBig(&relevantPos);
									this->_BigIndicators[i] = newBig;
								}
							}

							if (dist(relevantPos, MainCharObj1[0]->Position) < checkData.Range)
							{
								shouldShowBigPrompt = true;

								if (PressedButtons & 0b1000000000)
								{
									TimeStopped = 2;

									minigameManager->StartMinigame(ItemValue::IV_FishingTrap, true);

									this->_inBigFishing = true;
									this->_FreezePos = MainCharObj1[0]->Position;
								}
							}
						}
						else if (checkData.CheckSent && checkData.LevelID == CurrentLevel)
						{
							if (this->_BigIndicators.find(i) != this->_BigIndicators.end())
							{
								if (this->_BigIndicators[i] != nullptr)
								{
									this->_BigIndicators[i]->MainSub = DeleteObject_;
								}
								this->_BigIndicators.erase(i);
							}
						}
					}
				}
			}
		}
	}
}

void LocationManager::OnFrameFunction()
{
	this->SendAnimalLocationCheck();
	this->OnFrameWhistle();

	if (!this->_archipelagoManager->IsInit() || !this->_archipelagoManager->IsAuth())
	{
		return;
	}

	this->OnFrameChaoGarden();
	this->OnFrameRouteBalloons();
	this->OnFrameBig();

	this->_timer++;

	if (this->_timer > MEMORY_CHECK_TIME)
	{
		this->_timer = 0;

		this->OnFrameLevelClears();
		this->OnFrameBossRush();
		this->OnFrameChaoKeys();
		this->OnFramePipes();
		this->OnFrameHidden();
		this->OnFrameGoldBeetles();
		this->OnFrameOmochao();
		this->OnFrameAnimals();
		this->OnFrameItemBoxes();
		this->OnFrameKartRace();
	}
}

void LocationManager::OnFrameLevelClears()
{
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
				else if (dataValue > checkData.PrevValue)
				{
					checkData.PrevValue = dataValue;

					if (GameState != GameStates_Inactive)
					{
						MessageQueue::GetInstance().AddMessage("Mission Rank too low");
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

void LocationManager::OnFrameBossRush()
{
	if (!(this->_goal == 4 or this->_goal == 5 or this->_goal == 6))
	{
		return;
	}

	for (int i = BossRushCheck::BRC_BEGIN; i < BossRushCheck::BRC_NUM_CHECKS; i++)
	{
		if (this->_BossRushData.find(i) != this->_BossRushData.end())
		{
			BossRushCheckData& checkData = this->_BossRushData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) != 0x00)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) == 0x00)
				{
					char newDataValue = dataValue | bitFlag;

					WriteData<1>((void*)checkData.Address, newDataValue);
				}
			}
		}
	}
}

void LocationManager::OnFrameChaoKeys()
{
	if (!this->_chaoKeysEnabled)
	{
		return;
	}

	for (int i = ChaoKeyCheck::CKC_BEGIN; i < ChaoKeyCheck::CKC_NUM_CHECKS; i++)
	{
		if (this->_ChaoKeyData.find(i) != this->_ChaoKeyData.end())
		{
			ChaoKeyCheckData& checkData = this->_ChaoKeyData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameWhistle()
{
	this->_whistleTimer = this->_whistleTimer > 0 ? this->_whistleTimer - 1 : 0;

	if (MainCharObj1[0] && MainCharObj1[0]->Action == Actions::Action_Whistle)
	{
		if (this->_whistleTimer <= 0)
		{
			this->_whistleTimer = WHISTLE_CHECK_TIME;
			this->SendPipeLocationCheck();
			this->SendHiddenLocationCheck();
		}
	}
}

void LocationManager::OnFramePipes()
{
	if (!this->_pipesEnabled)
	{
		return;
	}

	for (int i = PipeCheck::PC_BEGIN; i < PipeCheck::PC_NUM_CHECKS; i++)
	{
		if (this->_PipeData.find(i) != this->_PipeData.end())
		{
			PipeCheckData& checkData = this->_PipeData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameHidden()
{
	if (!this->_hiddensEnabled)
	{
		return;
	}

	for (int i = HiddenCheck::HC_BEGIN; i < HiddenCheck::HC_NUM_CHECKS; i++)
	{
		if (this->_HiddenData.find(i) != this->_HiddenData.end())
		{
			HiddenCheckData& checkData = this->_HiddenData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameGoldBeetles()
{
	if (!this->_goldBeetlesEnabled)
	{
		return;
	}

	for (int i = GoldBeetleCheck::GBC_BEGIN; i < GoldBeetleCheck::GBC_NUM_CHECKS; i++)
	{
		if (this->_GoldBeetleData.find(i) != this->_GoldBeetleData.end())
		{
			GoldBeetleCheckData& checkData = this->_GoldBeetleData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameOmochao()
{
	if (!this->_omochaoEnabled)
	{
		return;
	}

	for (int i = OmochaoCheck::OC_BEGIN; i < OmochaoCheck::OC_NUM_CHECKS; i++)
	{
		if (this->_OmochaoData.find(i) != this->_OmochaoData.end())
		{
			OmochaoCheckData& checkData = this->_OmochaoData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameAnimals()
{
	if (!this->_animalsEnabled)
	{
		return;
	}

	for (int i = AnimalCheck::AC_BEGIN; i < AnimalCheck::AC_NUM_CHECKS; i++)
	{
		if (this->_AnimalData.find(i) != this->_AnimalData.end())
		{
			AnimalCheckData& checkData = this->_AnimalData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag ) != 0x00)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) == 0x00)
				{
					char newDataValue = dataValue | bitFlag;

					WriteData<1>((void*)checkData.Address, newDataValue);
				}
			}
		}
	}

	if (AnimalCounter == NULL || AnimalCounter->AnimalCount == NULL)
	{
		return;
	}

	if (GameState == GameStates::GameStates_Ingame || GameState == GameStates::GameStates_Pause)
	{
		AnimalCounter->AnimalCount->MaxAnimalCount = this->GetTotalAnimalLocationsForLevel(TileIDtoStageIndex[SS_SelectedTile]);
	}
}

void LocationManager::OnFrameItemBoxes()
{
	if (!this->_lifeBoxesEnabled && !this->_itemBoxesEnabled)
	{
		return;
	}

	for (int i = ItemBoxCheck::IBC_BEGIN; i < ItemBoxCheck::IBC_NUM_CHECKS; i++)
	{
		if (this->_ItemBoxData.find(i) != this->_ItemBoxData.end())
		{
			ItemBoxCheckData& checkData = this->_ItemBoxData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) != 0x00)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) == 0x00)
				{
					char newDataValue = dataValue | bitFlag;

					WriteData<1>((void*)checkData.Address, newDataValue);
				}
			}
		}
	}
}

void LocationManager::OnFrameBig()
{
	if (!this->_bigEnabled)
	{
		return;
	}

	for (int i = BigCheck::BC_BEGIN; i < BigCheck::BC_NUM_CHECKS; i++)
	{
		if (this->_BigData.find(i) != this->_BigData.end())
		{
			BigCheckData& checkData = this->_BigData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) != 0x00)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) == 0x00)
				{
					char newDataValue = dataValue | bitFlag;

					WriteData<1>((void*)checkData.Address, newDataValue);
				}
			}
		}
	}
}

void LocationManager::OnFrameKartRace()
{
	if (this->_kartRacesEnabled == 0)
	{
		return;
	}

	for (int i = KartRaceCheck::KRC_BEGIN; i < KartRaceCheck::KRC_NUM_CHECKS; i++)
	{
		if (this->_KartRaceData.find(i) != this->_KartRaceData.end())
		{
			KartRaceCheckData& checkData = this->_KartRaceData[i];

			if (!checkData.CheckSent)
			{
				// DataPointer macro creates a static field, which doesn't work for this case
				char dataValue = *(char*)checkData.Address;

				if (dataValue == 0x01)
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
				// Capture offline collects
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}
			}
		}
	}
}

void LocationManager::OnFrameChaoGarden()
{
	if (!this->_chaoEnabled)
	{
		// Don't do any Chao stuff if no Chao checks are on
		return;
	}

	if (CurrentLevel != LevelIDs::LevelIDs_ChaoWorld)
	{
		this->_chaoEntryTimer = 0;
	}
	else
	{
		this->_chaoEntryTimer++;
	}

	this->_chaoTimer++;

	if (this->_chaoTimer > CHAO_MEMORY_CHECK_TIME)
	{
		this->_chaoTimer = 0;

		// Sending of Chao Locations to Server

		// Chao Stats
		for (int statLevel = 1; statLevel <= this->_chaoStatsEnabled; statLevel++)
		{
			for (int statType = ChaoStatCheckType::CSCT_Swim; statType <= ChaoStatCheckType::CSCT_Intelligence; statType++)
			{
				int locationID = 0xE00 + (statType * 0x80) + statLevel;
				if (this->_ChaoStatData.find(locationID) != this->_ChaoStatData.end())
				{
					ChaoStatCheckData& checkData = this->_ChaoStatData[locationID];

					if (!checkData.CheckSent)
					{
						char dataValue = *(char*)checkData.Address;
						if (dataValue >= statLevel)
						{
							this->_archipelagoManager->SendItem(locationID);

							checkData.CheckSent = true;
						}
					}
				}
			}
		}

		// Handle Collected Chao Stats
		for (int i = 0; i < 7; i++)
		{
			for (auto locID : this->_CollectedChaoStats[i])
			{
				if (this->_ChaoStatData.find(locID) != this->_ChaoStatData.end())
				{
					ChaoStatCheckData& checkData = this->_ChaoStatData[locID];

					if ((checkData.Level % this->_chaoStatsFrequency) == (this->_chaoStatsEnabled % this->_chaoStatsFrequency))
					{
						for (int subLocID = (locID - 1); subLocID > locID - this->_chaoStatsFrequency; subLocID--)
						{
							ChaoStatCheckData& subCheckData = this->_ChaoStatData[subLocID];
							subCheckData.CheckSent = true;
						}
					}

					char dataValue = *(char*)checkData.Address;
					if ((dataValue == 0 && checkData.Level < this->_chaoStatsFrequency) ||
						dataValue == (checkData.Level - this->_chaoStatsFrequency))
					{
						WriteData<1>((void*)checkData.Address, checkData.Level);
					}
				}
			}
		}
		// End Handle Collected Chao Stats

		// Chao Animal Parts
		if (this->_chaoBodyPartsEnabled)
		{
			for (int i = ChaoBodyPartCheck::CBPC_BEGIN; i < ChaoBodyPartCheck::CBPC_NUM_CHECKS; i++)
			{
				if (this->_ChaoBodyPartData.find(i) != this->_ChaoBodyPartData.end())
				{
					ChaoBodyPartCheckData& checkData = this->_ChaoBodyPartData[i];

					if (!checkData.CheckSent)
					{
						char dataValue = *(char*)checkData.Address;

						char bitFlag = (char)(0x01 << (char)checkData.BodyPart);

						if ((dataValue & bitFlag) != 0x00)
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


		// Chao Kindergarten
		if (this->_chaoKindergartenEnabled > 0)
		{
			for (int i = ChaoKindergartenCheck::CKgC_BEGIN; i < ChaoKindergartenCheck::CKgC_NUM_CHECKS; i++)
			{
				if (this->_ChaoKindergartenData.find(i) != this->_ChaoKindergartenData.end())
				{
					ChaoKindergartenCheckData& checkData = this->_ChaoKindergartenData[i];

					if (!checkData.CheckSent)
					{
						int dataValue = *(int*)checkData.Address;

						int bitFlag = (int)(0x01 << (int)(checkData.LessonNum % 0x20));

						if ((dataValue & bitFlag) != 0x00)
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


		// Black Market
		if (this->_blackMarketSlots > 0)
		{
			for (int i = BlackMarketCheck::BMC_BEGIN; i <= BlackMarketCheck::BMC_BEGIN + 64; i++)
			{
				if (this->_BlackMarketLocationData.find(i) != this->_BlackMarketLocationData.end())
				{
					BlackMarketCheckData& checkData = this->_BlackMarketLocationData[i];

					if (!checkData.CheckSent)
					{
						int byteNum = (checkData.SlotNum - 1) / 8;
						int bitNum  = (checkData.SlotNum - 1) % 8;
						int dataValue = *(int*)(checkData.Address + byteNum);

						int bitFlag = (int)(0x01 << bitNum);

						if ((dataValue & bitFlag) != 0x00)
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
		// End Sending of Chao Locations to Server

		if (this->_chaoEntryTimer < CHAO_MEMORY_CHECK_ENTRY_TIME)
		{
			// Only check the below data while in Chao World, otherwise it may be wrong
			return;
		}

		// In-Garden Tracking of Locations
		if (this->_chaoRaceEnabled > 0)
		{
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
		}

		if (this->_chaoKarateEnabled)
		{
			// Only display Emblem on SS if all Karate fights are done
			WriteData<1>((void*)0x676968, '\x80');
			WriteData<1>((void*)0x676969, '\xBE');
			WriteData<1>((void*)0x67696A, '\x2C');
			WriteData<1>((void*)0x67696B, '\xF8');
			WriteData<1>((void*)0x67696C, '\xDE');
			WriteData<1>((void*)0x67696D, '\x01');
			WriteData<1>((void*)0x67696E, '\x1F');
			WriteData<1>((void*)0x67696F, '\x74');
			WriteData<1>((void*)0x676970, '\xCD');
			WriteData<6>((void*)0X542C06, '\x90');

			if (KarateManager != nullptr)
			{
				for (int difficulty = 0; difficulty < 4; difficulty++)
				{
					for (int fights = 0; fights < 5; fights++)
					{
						if (KarateManager->Difficulty == difficulty && KarateManager->CurrentWins > fights)
						{
							char dataValue = *(char*)(0x01DEF831 + difficulty);
							char bitFlag = (char)(0x01 << fights);

							WriteData<1>((void*)(0x01DEF831 + difficulty), (dataValue | bitFlag));
						}
					}
				}
			}

			for (int i = ChaoGardenCheck::CGC_BEGIN_KARATE; i <= ChaoGardenCheck::CGC_END_KARATE; i++)
			{
				if (this->_ChaoGardenData.find(i) != this->_ChaoGardenData.end())
				{
					ChaoGardenCheckData& checkData = this->_ChaoGardenData[i];

					if (!checkData.CheckSent)
					{
						char dataValue = *(char*)checkData.Address;
						char bitFlag = (char)(0x01 << checkData.Index);

						if ((dataValue & bitFlag) != 0)
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

		for (int chaoIdx = 0; chaoIdx < 24; chaoIdx++)
		{
			ChaoDataBase chaoData = ChaoSlots[chaoIdx].data;

			if (chaoData.TimescaleTimer == 0)
			{
				// This Chao does not exist yet
				continue;
			}

			// Chao Stats
			for (int statLevel = 1; statLevel <= this->_chaoStatsEnabled; statLevel++)
			{
				for (int statType = ChaoStatCheckType::CSCT_Swim; statType <= ChaoStatCheckType::CSCT_Intelligence; statType++)
				{
					int locationID = 0xE00 + (statType * 0x80) + statLevel;
					if (this->_ChaoStatData.find(locationID) != this->_ChaoStatData.end())
					{
						ChaoStatCheckData& checkData = this->_ChaoStatData[locationID];

						if (!checkData.CheckSent)
						{
							char chaoLevel = chaoData.StatLevels[statType];

							char dataValue = *(char*)checkData.Address;
							if (chaoLevel > dataValue)
							{
								WriteData<1>((void*)checkData.Address, chaoLevel);
							}
						}
					}
				}
			}

			// Chao Animal Parts
			if (this->_chaoBodyPartsEnabled)
			{
				for (int i = ChaoBodyPartCheck::CBPC_BEGIN; i < ChaoBodyPartCheck::CBPC_NUM_CHECKS; i++)
				{
					if (this->_ChaoBodyPartData.find(i) != this->_ChaoBodyPartData.end())
					{
						ChaoBodyPartCheckData& checkData = this->_ChaoBodyPartData[i];

						if (!checkData.CheckSent)
						{
							SA2BAnimal currentChaoAnimal = SA2BAnimal_None;
							switch (checkData.BodyPart)
							{
							case ChaoBodyPart::CBP_Arms:
								currentChaoAnimal = chaoData.SA2BArmType;
								break;
							case ChaoBodyPart::CBP_Ears:
								currentChaoAnimal = chaoData.SA2BEarType;
								break;
							case ChaoBodyPart::CBP_Forehead:
								currentChaoAnimal = chaoData.SA2BForeheadType;
								break;
							case ChaoBodyPart::CBP_Face:
								currentChaoAnimal = chaoData.SA2BFaceType;
								break;
							case ChaoBodyPart::CBP_Legs:
								currentChaoAnimal = chaoData.SA2BLegType;
								break;
							case ChaoBodyPart::CBP_Horn:
								currentChaoAnimal = chaoData.SA2BHornType;
								break;
							case ChaoBodyPart::CBP_Tail:
								currentChaoAnimal = chaoData.SA2BTailType;
								break;
							case ChaoBodyPart::CBP_Wings:
								currentChaoAnimal = chaoData.SA2BWingType;
								break;
							}

							if (currentChaoAnimal == checkData.AnimalType)
							{
								char dataValue = *(char*)checkData.Address;
								char bitFlag = (char)(0x01 << (char)checkData.BodyPart);
								char newDataValue = dataValue | bitFlag;

								WriteData<1>((void*)checkData.Address, newDataValue);
							}
						}
					}
				}
			}

			// Chao Kindergarten
			if (this->_chaoKindergartenEnabled > 0)
			{
				for (int i = ChaoKindergartenCheck::CKgC_BEGIN; i < ChaoKindergartenCheck::CKgC_NUM_CHECKS; i++)
				{
					if (this->_ChaoKindergartenData.find(i) != this->_ChaoKindergartenData.end())
					{
						ChaoKindergartenCheckData& checkData = this->_ChaoKindergartenData[i];

						if (!checkData.CheckSent)
						{
							if (checkData.LessonNum < 0x20)
							{
								char byteNum = checkData.LessonNum / 8;
								char bitNum = checkData.LessonNum % 8;
								char bitFlag = (char)(0x01 << bitNum);

								char lessonData = chaoData.ClassRoomFlags[byteNum];

								if ((lessonData & bitFlag) != 0)
								{
									char dataValue = *(char*)(checkData.Address + byteNum);
									char newDataValue = dataValue | bitFlag;

									WriteData<1>((void*)(checkData.Address + byteNum), newDataValue);
								}
							}
							else
							{
								char byteNum = checkData.LessonNum % 0x20;
								char lessonData = chaoData.ClassRoomFlags[byteNum];

								if (lessonData > 0)
								{
									char dataValue = *(char*)(checkData.Address + byteNum);
									char bitNum = checkData.LessonNum % 8;
									char bitFlag = (char)(0x01 << bitNum);
									char newDataValue = dataValue | bitFlag;

									WriteData<1>((void*)(checkData.Address), newDataValue);
								}
							}
						}
					}
				}
			}
		}
		// End In-Garden Tracking of Locations
	}
}

void LocationManager::OnFrameRouteBalloons()
{
	if (!this->_itemBoxesEnabled)
	{
		return;
	}

	if (CurrentLevel != LevelIDs_Route101280)
	{
		return;
	}

	if (MainCharObj1[0] == nullptr)
	{
		return;
	}

	for (int i = ItemBoxCheck::IBC_BEGIN; i < ItemBoxCheck::IBC_NUM_CHECKS; i++)
	{
		if (this->_ItemBoxData.find(i) != this->_ItemBoxData.end())
		{
			if (i % 0x20 == 8 || i % 0x20 == 25)
			{
				ItemBoxCheckData& checkData = this->_ItemBoxData[i];

				if (dist(checkData.Position, MainCharObj1[0]->Position) < checkData.Range)
				{
					char dataValue = *(char*)checkData.Address;

					char bitFlag = (char)(0x01 << checkData.AddressBit);

					if ((dataValue & bitFlag) == 0x00)
					{
						char dataValue = *(char*)checkData.Address;
						char bitFlag = (char)(0x01 << checkData.AddressBit);
						char newDataValue = dataValue | bitFlag;

						WriteData<1>((void*)checkData.Address, newDataValue);
					}

					return;
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

		if (location_id >= LCC_Boss_1)
		{
			// Don't Collect Bosses
			return;
		}

		if (location_id == LCC_CannonCore_1 ||
			location_id == LCC_CannonCore_2 ||
			location_id == LCC_CannonCore_3 ||
			location_id == LCC_CannonCore_4 ||
			location_id == LCC_CannonCore_5)
		{
			// Don't Collect any Cannon's Core Missions
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
	else if (this->_BossRushData.find(location_id) != this->_BossRushData.end())
	{
		BossRushCheckData& checkData = this->_BossRushData[location_id];

		checkData.CheckSent = true;

		char dataValue = *(char*)checkData.Address;
		char bitFlag = (char)(0x01 << checkData.AddressBit);
		char newDataValue = dataValue | bitFlag;

		WriteData<1>((void*)checkData.Address, newDataValue);
	}
	else if (this->_ChaoGardenData.find(location_id) != this->_ChaoGardenData.end())
	{
		if (location_id >= ChaoGardenCheck::CGC_BEGIN_KARATE && location_id <= ChaoGardenCheck::CGC_END_KARATE)
		{
			ChaoGardenCheckData& checkData = this->_ChaoGardenData[location_id];

			checkData.CheckSent = true;

			char dataValue = *(char*)checkData.Address;
			dataValue      = (dataValue | (char)(1 << checkData.Index));

			WriteData<1>((void*)checkData.Address, dataValue);

			// If only Prize fights give checks, complete preceding fights too on collect
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

							char dataValue = *(char*)packCheckData.Address;
							dataValue      = (dataValue | (char)(1 << packCheckData.Index));

							WriteData<1>((void*)packCheckData.Address, dataValue);
						}
					}
				}
			}
		}
		else
		{
			ChaoGardenCheckData& checkData = this->_ChaoGardenData[location_id];

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
	else if (this->_ChaoStatData.find(location_id) != this->_ChaoStatData.end())
	{
		ChaoStatCheckData& checkData = this->_ChaoStatData[location_id];
		checkData.CheckSent = true;

		this->_CollectedChaoStats[checkData.StatType].push_back(location_id);
		std::sort(this->_CollectedChaoStats[checkData.StatType].begin(), this->_CollectedChaoStats[checkData.StatType].end());
	}
	else if (this->_ChaoBodyPartData.find(location_id) != this->_ChaoBodyPartData.end())
	{
		ChaoBodyPartCheckData& checkData = this->_ChaoBodyPartData[location_id];

		checkData.CheckSent = true;

		char dataValue = *(char*)checkData.Address;
		char bitFlag = (char)(0x01 << (int)checkData.BodyPart);
		char newDataValue = dataValue | bitFlag;

		WriteData<1>((void*)checkData.Address, newDataValue);
	}
	else if (this->_ChaoKindergartenData.find(location_id) != this->_ChaoKindergartenData.end())
	{
		ChaoKindergartenCheckData& checkData = this->_ChaoKindergartenData[location_id];

		checkData.CheckSent = true;

		char dataValue = *(char*)checkData.Address;
		char bitFlag = (char)(0x01 << (int)checkData.LessonNum);
		char newDataValue = dataValue | bitFlag;

		WriteData<1>((void*)checkData.Address, newDataValue);
	}
	else if (this->_BlackMarketLocationData.find(location_id) != this->_BlackMarketLocationData.end())
	{
		BlackMarketCheckData& checkData = this->_BlackMarketLocationData[location_id];

		checkData.CheckSent = true;

		int byteNum = (checkData.SlotNum - 1) / 8;
		int bitNum = (checkData.SlotNum - 1) % 8;
		int dataValue = *(int*)(checkData.Address + byteNum);
		int bitFlag = (int)(0x01 << bitNum);
		char newDataValue = dataValue | bitFlag;

		WriteData<1>((void*)(checkData.Address + byteNum), newDataValue);
	}
	else if (this->_ChaoKeyData.find(location_id) != this->_ChaoKeyData.end())
	{
		ChaoKeyCheckData& checkData = this->_ChaoKeyData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
	else if (this->_PipeData.find(location_id) != this->_PipeData.end())
	{
		PipeCheckData& checkData = this->_PipeData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
	else if (this->_HiddenData.find(location_id) != this->_HiddenData.end())
	{
		HiddenCheckData& checkData = this->_HiddenData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
	else if (this->_GoldBeetleData.find(location_id) != this->_GoldBeetleData.end())
	{
		GoldBeetleCheckData& checkData = this->_GoldBeetleData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
	else if (this->_OmochaoData.find(location_id) != this->_OmochaoData.end())
	{
		OmochaoCheckData& checkData = this->_OmochaoData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
	else if (this->_AnimalData.find(location_id) != this->_AnimalData.end())
	{
		AnimalCheckData& checkData = this->_AnimalData[location_id];

		checkData.CheckSent = true;

		char dataValue = *(char*)checkData.Address;
		char bitFlag = (char)(0x01 << checkData.AddressBit);
		char newDataValue = dataValue | bitFlag;

		WriteData<1>((void*)checkData.Address, newDataValue);
	}
	else if (this->_ItemBoxData.find(location_id) != this->_ItemBoxData.end())
	{
		ItemBoxCheckData& checkData = this->_ItemBoxData[location_id];

		checkData.CheckSent = true;

		char dataValue = *(char*)checkData.Address;
		char bitFlag = (char)(0x01 << checkData.AddressBit);
		char newDataValue = dataValue | bitFlag;

		WriteData<1>((void*)checkData.Address, newDataValue);
	}
	else if (this->_BigData.find(location_id) != this->_BigData.end())
	{
		BigCheckData& checkData = this->_BigData[location_id];

		checkData.CheckSent = true;

		char dataValue = *(char*)checkData.Address;
		char bitFlag = (char)(0x01 << checkData.AddressBit);
		char newDataValue = dataValue | bitFlag;

		WriteData<1>((void*)checkData.Address, newDataValue);
	}
	else if (this->_KartRaceData.find(location_id) != this->_KartRaceData.end())
	{
		KartRaceCheckData& checkData = this->_KartRaceData[location_id];

		checkData.CheckSent = true;

		WriteData<1>((void*)checkData.Address, 0x01);
	}
}

void LocationManager::SetGoal(int goal)
{
	this->_goal = goal;
}

void LocationManager::SetRequiredRank(int requiredRank)
{
	this->_requiredRank = requiredRank;
}

void LocationManager::SetLogicDifficulty(int logicDifficulty)
{
	this->_logicDifficulty = logicDifficulty;
}

void LocationManager::SetChaoKeysEnabled(bool chaoKeysEnabled)
{
	this->_chaoKeysEnabled = chaoKeysEnabled;

	if (this->_chaoKeysEnabled)
	{
		// Handle Picking Up Chao Key
		WriteCall(static_cast<void*>((void*)0x006E99E0), &PickedUpChaoKey);
		WriteData<1>((void*)0x006E99E5, '\x90');

		// Overwrite vanilla Chao Key Behavior
		WriteData<7>((void*)0x006E9AD6, '\x90');
		WriteData<7>((void*)0x006E9B70, '\x90');
		WriteData<7>((void*)0x006E9C05, '\x90');

		WriteData<1>((void*)0x006E9C31, '\x04');
		WriteData<1>((void*)0x006E9C32, '\xB0');
		WriteData<1>((void*)0x006E9C33, '\x74');

		WriteData<1>((void*)0x006E9C36, '\x94');

		WriteData<6>((void*)0x006E9C4A, '\x90');

		WriteData<1>((void*)0x006E9C52, '\x04');
		WriteData<1>((void*)0x006E9C53, '\xB0');
		WriteData<1>((void*)0x006E9C54, '\x74');
		WriteData<1>((void*)0x006E9C56, '\x01');

		WriteData<1>((void*)0x006E9C58, '\x84');
	}
}

void LocationManager::SetPipesEnabled(bool pipesEnabled)
{
	this->_pipesEnabled = pipesEnabled;
}

void LocationManager::SetHiddensEnabled(bool hiddenEnabled)
{
	this->_hiddensEnabled = hiddenEnabled;
}

void LocationManager::SetGoldBeetlesEnabled(bool goldBeetlesEnabled)
{
	this->_goldBeetlesEnabled = goldBeetlesEnabled;
}

void LocationManager::SetOmochaoEnabled(bool omochaoEnabled)
{
	this->_omochaoEnabled = omochaoEnabled;
}

void LocationManager::SetAnimalsEnabled(bool animalsEnabled)
{
	this->_animalsEnabled = animalsEnabled;
}

void LocationManager::SetItemBoxesEnabled(int itemBoxesEnabled)
{
	this->_lifeBoxesEnabled = (itemBoxesEnabled > 0);
	this->_itemBoxesEnabled = (itemBoxesEnabled > 1);

	if (this->_lifeBoxesEnabled || this->_itemBoxesEnabled)
	{
		// Floating Item Boxes
		WriteData<1>((void*)0x006C9273, '\x89');
		WriteData<1>((void*)0x006C9274, '\xea');
		WriteData<2>((void*)0x006C9275, '\x90');
		WriteCall(static_cast<void*>((void*)0x006C9277), &ActivatedFloatingItemBox);

		// Grounded Item Boxes
		WriteData<1>((void*)0x006C810D, '\x89');
		WriteData<1>((void*)0x006C810E, '\xfa');
		WriteData<1>((void*)0x006C810F, '\x90');
		WriteCall(static_cast<void*>((void*)0x006C8110), &ActivatedGroundedItemBox);

		// Balloon Item Boxes
		WriteData<1>((void*)0x006DB297, '\x89');
		WriteData<1>((void*)0x006DB298, '\xea');
		WriteData<1>((void*)0x006DB299, '\x90');
		WriteCall(static_cast<void*>((void*)0x006DB29A), &ActivatedBalloonItemBox);

		// Sunglasses Item Boxes
		WriteData<1>((void*)0x006EAE00, '\x89');
		WriteData<1>((void*)0x006EAE01, '\xf2');
		WriteData<1>((void*)0x006EAE02, '\x90');
		WriteCall(static_cast<void*>((void*)0x006EAE03), &ActivatedSunglassesItemBox);
	}
}

void LocationManager::SetBigEnabled(bool bigEnabled)
{
	this->_bigEnabled = bigEnabled;
}

void LocationManager::SetKartRacesEnabled(int kartRacesEnabled)
{
	this->_kartRacesEnabled = kartRacesEnabled;
}

void LocationManager::SetRacesPacked(bool racesPacked)
{
	this->_racesPacked = racesPacked;

	for (auto& pair : this->_ChaoGardenData)
	{
		if (pair.second.CheckSent)
		{
			// Redo the "check" of the location, as we may have already incorrectly processed it before we got this bool set
			CheckLocation(pair.first);
		}
	}
}

void LocationManager::SetChaoEnabled(bool chaoEnabled)
{
	// Anything Chao-related is active
	this->_chaoEnabled = chaoEnabled;
}

void LocationManager::SetChaoRaceEnabled(int chaoRaceEnabled)
{
	this->_chaoRaceEnabled = chaoRaceEnabled;

	if (chaoRaceEnabled)
	{
		this->SetChaoEnabled(true);
	}
}

void LocationManager::SetChaoKarateEnabled(int chaoKarateEnabled)
{
	this->_chaoKarateEnabled = chaoKarateEnabled;

	if (chaoKarateEnabled)
	{
		this->SetChaoEnabled(true);
	}
}

void LocationManager::SetChaoStatsEnabled(int chaoStatsEnabled)
{
	this->_chaoStatsEnabled = chaoStatsEnabled;

	if (chaoStatsEnabled > 0)
	{
		this->SetChaoEnabled(true);
	}
}

void LocationManager::SetChaoStatsFrequency(int chaoStatsFrequency)
{
	this->_chaoStatsFrequency = chaoStatsFrequency;
}

void LocationManager::SetChaoStatsStaminaEnabled(bool chaoStatsStaminaEnabled)
{
	this->_chaoStatsStaminaEnabled = chaoStatsStaminaEnabled;
}

void LocationManager::SetChaoStatsHiddenEnabled(bool chaoStatsHiddenEnabled)
{
	this->_chaoStatsHiddenEnabled = chaoStatsHiddenEnabled;
}

void LocationManager::SetChaoBodyPartsEnabled(bool chaoBodyPartsEnabled)
{
	this->_chaoBodyPartsEnabled = chaoBodyPartsEnabled;

	if (chaoBodyPartsEnabled)
	{
		this->SetChaoEnabled(true);
	}
}

void LocationManager::SetChaoKindergartenEnabled(int chaoKindergartenEnabled)
{
	this->_chaoKindergartenEnabled = chaoKindergartenEnabled;

	if (chaoKindergartenEnabled > 0)
	{
		this->SetChaoEnabled(true);
	}
}

void LocationManager::SetBlackMarketSlots(int blackMarketSlots)
{
	this->_blackMarketSlots = blackMarketSlots;

	if (blackMarketSlots)
	{
		this->SetChaoEnabled(true);
	}
}

void LocationManager::SetBlackMarketUnlockCosts(std::map<int, int> map)
{
	this->_blackMarketUnlockCosts = map;
}

void LocationManager::SetRequiredCannonsCoreMissions(bool allMissionsRequired)
{
	this->_requireAllCannonsCoreMissions = allMissionsRequired;
}

void LocationManager::ResetLocations()
{
	for (auto& pair : this->_LevelClearData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_BossRushData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_ChaoGardenData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_ChaoStatData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_ChaoBodyPartData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_ChaoKindergartenData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_BlackMarketLocationData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_ChaoKeyData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_PipeData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_HiddenData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_GoldBeetleData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_OmochaoData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_AnimalData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_ItemBoxData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_BigData)
	{
		pair.second.CheckSent = false;
	}

	for (auto& pair : this->_KartRaceData)
	{
		pair.second.CheckSent = false;
	}
}

void LocationManager::SendChaoKeyLocationCheck()
{
	if (!this->_chaoKeysEnabled)
	{
		return;
	}

	if (MainCharObj1[0] == NULL)
	{
		return;
	}

	for (int i = ChaoKeyCheck::CKC_BEGIN; i < ChaoKeyCheck::CKC_NUM_CHECKS; i++)
	{
		if (this->_ChaoKeyData.find(i) != this->_ChaoKeyData.end())
		{
			ChaoKeyCheckData& checkData = this->_ChaoKeyData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				if (dist(checkData.Position, MainCharObj1[0]->Position) < checkData.Range ||
					(checkData.AltPosition.x != 0 && dist(checkData.AltPosition, MainCharObj1[0]->Position) < checkData.Range))
				{
					char dataValue = *(char*)checkData.Address;

					if (dataValue != 0x01)
					{
						WriteData<1>((void*)checkData.Address, 0x01);
					}

					return;
				}
			}
		}
	}
}

void LocationManager::SendPipeLocationCheck()
{
	if (!this->_pipesEnabled)
	{
		return;
	}

	if (MainCharObj1[0] == NULL)
	{
		return;
	}

	for (int i = PipeCheck::PC_BEGIN; i < PipeCheck::PC_NUM_CHECKS; i++)
	{
		if (this->_PipeData.find(i) != this->_PipeData.end())
		{
			PipeCheckData& checkData = this->_PipeData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				if (dist(checkData.Position, MainCharObj1[0]->Position) < checkData.Range)
				{
					char dataValue = *(char*)checkData.Address;

					if (dataValue != 0x01)
					{
						WriteData<1>((void*)checkData.Address, 0x01);
					}

					return;
				}
			}
		}
	}
}

void LocationManager::SendHiddenLocationCheck()
{
	if (!this->_hiddensEnabled)
	{
		return;
	}

	if (MainCharObj1[0] == NULL)
	{
		return;
	}

	for (int i = HiddenCheck::HC_BEGIN; i < HiddenCheck::HC_NUM_CHECKS; i++)
	{
		if (this->_HiddenData.find(i) != this->_HiddenData.end())
		{
			HiddenCheckData& checkData = this->_HiddenData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				if (dist(checkData.Position, MainCharObj1[0]->Position) < checkData.Range)
				{
					char dataValue = *(char*)checkData.Address;

					if (dataValue != 0x01)
					{
						WriteData<1>((void*)checkData.Address, 0x01);
					}

					return;
				}
			}
		}
	}
}

void LocationManager::SendGoldBeetleLocationCheck()
{
	if (!this->_goldBeetlesEnabled)
	{
		return;
	}

	for (int i = GoldBeetleCheck::GBC_BEGIN; i < GoldBeetleCheck::GBC_NUM_CHECKS; i++)
	{
		if (this->_GoldBeetleData.find(i) != this->_GoldBeetleData.end())
		{
			GoldBeetleCheckData& checkData = this->_GoldBeetleData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				char dataValue = *(char*)checkData.Address;

				if (dataValue != 0x01)
				{
					WriteData<1>((void*)checkData.Address, 0x01);
				}

				return;
			}
		}
	}
}

void LocationManager::SendOmochaoLocationCheck()
{
	if (!this->_omochaoEnabled)
	{
		return;
	}

	if (ItemManager::getInstance().IsOmotrapActive())
	{
		return;
	}

	if (MainCharObj1[0] == NULL)
	{
		return;
	}

	for (int i = OmochaoCheck::OC_BEGIN; i < OmochaoCheck::OC_NUM_CHECKS; i++)
	{
		if (this->_OmochaoData.find(i) != this->_OmochaoData.end())
		{
			OmochaoCheckData& checkData = this->_OmochaoData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				if (dist(checkData.Position, MainCharObj1[0]->Position) < checkData.Range)
				{
					char dataValue = *(char*)checkData.Address;

					if (dataValue != 0x01)
					{
						MessageQueue::GetInstance().AddMessage("");
						WriteData<1>((void*)checkData.Address, 0x01);
					}

					return;
				}
			}
		}
	}
}

void LocationManager::SendAnimalLocationCheck()
{
	if (!this->_animalsEnabled)
	{
		return;
	}

	if (AnimalCounter == NULL || AnimalCounter->AnimalCount == NULL)
	{
		return;
	}

	for (int i = AnimalCheck::AC_BEGIN; i < AnimalCheck::AC_NUM_CHECKS; i++)
	{
		if (this->_AnimalData.find(i) != this->_AnimalData.end())
		{
			AnimalCheckData& checkData = this->_AnimalData[i];

			if (checkData.LevelID == CurrentLevel ||
				(checkData.LevelID == LevelIDs::LevelIDs_CannonsCoreS &&
				 (CurrentLevel == LevelIDs::LevelIDs_CannonsCoreT ||
				  CurrentLevel == LevelIDs::LevelIDs_CannonsCoreE ||
				  CurrentLevel == LevelIDs::LevelIDs_CannonsCoreR ||
				  CurrentLevel == LevelIDs::LevelIDs_CannonsCoreK)))
			{
				if ((int)(AnimalCounter->AnimalCount->AnimalCount) > checkData.AnimalCount)
				{
					char dataValue = *(char*)checkData.Address;
					char bitFlag = (char)(0x01 << checkData.AddressBit);
					char newDataValue = dataValue | bitFlag;

					WriteData<1>((void*)checkData.Address, newDataValue);
				}
			}
		}
	}
}

void LocationManager::SendItemBoxLocationCheck(ObjectMaster* itemBox)
{
	if (!this->_lifeBoxesEnabled && !this->_itemBoxesEnabled)
	{
		return;
	}

	if (!itemBox)
	{
		return;
	}

	NJS_VECTOR Position = NJS_VECTOR();
	short ID = 0;
	if (itemBox->SETData && itemBox->SETData->SETEntry)
	{
		Position = itemBox->SETData->SETEntry->Position;
		ID = itemBox->SETData->SETEntry->ID;
	}
	else if (itemBox->Data1.Entity)
	{
		Position = itemBox->Data1.Entity->Position;
	}
	else
	{
		// Couldn't Determine Position Data
		return;
	}

#if 0
	std::string message = std::string("Item Box Pos: ");
	message += std::to_string(ID);
	message += std::string(" | ");
	message += std::to_string(int(Position.x));
	message += std::string(" | ");
	message += std::to_string(int(Position.y));
	message += std::string(" | ");
	message += std::to_string(int(Position.z));
	MessageQueue::GetInstance().AddMessage(message);
#endif

	for (int i = ItemBoxCheck::IBC_BEGIN; i < ItemBoxCheck::IBC_NUM_CHECKS; i++)
	{
		if (this->_ItemBoxData.find(i) != this->_ItemBoxData.end())
		{
			ItemBoxCheckData& checkData = this->_ItemBoxData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				if (dist(checkData.Position, Position) < checkData.Range)
				{
					char dataValue = *(char*)checkData.Address;

					char bitFlag = (char)(0x01 << checkData.AddressBit);

					if ((dataValue & bitFlag) == 0x00)
					{
						char dataValue = *(char*)checkData.Address;
						char bitFlag = (char)(0x01 << checkData.AddressBit);
						char newDataValue = dataValue | bitFlag;

						WriteData<1>((void*)checkData.Address, newDataValue);
					}

					return;
				}
			}
		}
	}
}

void LocationManager::SendBigLocationCheck()
{
	if (!this->_bigEnabled)
	{
		return;
	}

	if (MainCharObj1[0] == NULL)
	{
		return;
	}

	for (int i = BigCheck::BC_BEGIN; i < BigCheck::BC_NUM_CHECKS; i++)
	{
		if (this->_BigData.find(i) != this->_BigData.end())
		{
			BigCheckData& checkData = this->_BigData[i];

			if (checkData.LevelID == CurrentLevel)
			{
				NJS_VECTOR relevantPos = checkData.Position;

				if (this->_logicDifficulty > 0 && dist(checkData.HardPosition, NJS_VECTOR({ 0.0f, 0.0f, 0.0f })) > 1.0f)
				{
					relevantPos = checkData.HardPosition;
				}

				if (dist(relevantPos, MainCharObj1[0]->Position) < checkData.Range)
				{
					char dataValue = *(char*)checkData.Address;

					char bitFlag = (char)(0x01 << checkData.AddressBit);

					if ((dataValue & bitFlag) == 0x00)
					{
						char dataValue = *(char*)checkData.Address;
						char bitFlag = (char)(0x01 << checkData.AddressBit);
						char newDataValue = dataValue | bitFlag;

						WriteData<1>((void*)checkData.Address, newDataValue);
					}

					if (checkData.TeleAfter)
					{
						MainCharObj1[0]->Position = checkData.TelePosition;
					}

					return;
				}
			}
		}
	}
}

void LocationManager::SendBlackMarketLocationCheck(int menuSelection)
{
	if (this->_blackMarketSlots == 0)
	{
		return;
	}

	std::vector<int> activeLocations = this->GetAvailableBlackMarketLocations();

	if (activeLocations.size() <= menuSelection)
	{
		return;
	}

	int locationID = BlackMarketCheck::BMC_BEGIN + activeLocations[menuSelection] + 1;

	if (this->_BlackMarketLocationData.find(locationID) != this->_BlackMarketLocationData.end())
	{
		BlackMarketCheckData& checkData = this->_BlackMarketLocationData[locationID];

		if (!checkData.CheckSent)
		{
			int byteNum = (checkData.SlotNum - 1) / 8;
			int bitNum = (checkData.SlotNum - 1) % 8;
			int dataValue = *(int*)(checkData.Address + byteNum);
			int bitFlag = (int)(0x01 << bitNum);
			char newDataValue = dataValue | bitFlag;

			WriteData<1>((void*)(checkData.Address + byteNum), newDataValue);
		}
	}
}

std::vector<int> LocationManager::GetChaoKeyLocationsForLevel(int levelID)
{
	std::vector<int> result;

	if (this->_chaoKeysEnabled)
	{
		int checkOffset = 0x400;

		for (int j = 0; j < 6; j++)
		{
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_ChaoKeyData.find(locationID) != this->_ChaoKeyData.end())
			{
				ChaoKeyCheckData& checkData = this->_ChaoKeyData[locationID];
				result.push_back(checkData.Address);
			}
		}
	}

	return result;
}

std::vector<int> LocationManager::GetPipeLocationsForLevel(int levelID)
{
	std::vector<int> result;

	if (this->_pipesEnabled)
	{
		int checkOffset = 0x500;

		for (int j = 0; j < 6; j++)
		{
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_PipeData.find(locationID) != this->_PipeData.end())
			{
				PipeCheckData& checkData = this->_PipeData[locationID];
				result.push_back(checkData.Address);
			}
		}
	}

	return result;
}

std::vector<int> LocationManager::GetHiddenLocationsForLevel(int levelID)
{
	std::vector<int> result;

	if (this->_hiddensEnabled)
	{
		int checkOffset = 0x700;

		for (int j = 0; j < 5; j++)
		{
			int locationID = checkOffset + (j*0x20) + levelID;
			if (this->_HiddenData.find(locationID) != this->_HiddenData.end())
			{
				HiddenCheckData& checkData = this->_HiddenData[locationID];
				result.push_back(checkData.Address);
			}
		}
	}

	return result;
}

std::vector<int> LocationManager::GetGoldBeetleLocationsForLevel(int levelID)
{
	std::vector<int> result;

	if (this->_goldBeetlesEnabled)
	{
		int checkOffset = 0x600;

		int locationID = checkOffset + levelID;
		if (this->_GoldBeetleData.find(locationID) != this->_GoldBeetleData.end())
		{
			GoldBeetleCheckData& checkData = this->_GoldBeetleData[locationID];
			result.push_back(checkData.Address);
		}
	}

	return result;
}

std::vector<int> LocationManager::GetOmochaoLocationsForLevel(int levelID)
{
	std::vector<int> result;

	if (this->_omochaoEnabled)
	{
		int checkOffset = 0x800;

		for (int j = 0; j < 14; j++)
		{
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_OmochaoData.find(locationID) != this->_OmochaoData.end())
			{
				OmochaoCheckData& checkData = this->_OmochaoData[locationID];
				result.push_back(checkData.Address);
			}
		}
	}

	return result;
}

int LocationManager::GetCompletedAnimalLocationsForLevel(int levelID)
{
	int result = 0;

	if (this->_animalsEnabled)
	{
		int checkOffset = 0xB00;

		for (int j = 0; j <= 20; j++)
		{
			result = j;
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_AnimalData.find(locationID) != this->_AnimalData.end())
			{
				AnimalCheckData& checkData = this->_AnimalData[locationID];
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) == 0x00)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	return result;
}

int LocationManager::GetTotalAnimalLocationsForLevel(int levelID)
{
	int result = 0;

	if (this->_animalsEnabled)
	{
		int checkOffset = 0xB00;

		for (int j = 0; j < 20; j++)
		{
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_AnimalData.find(locationID) != this->_AnimalData.end())
			{
				result = j + 1;
			}
			else
			{
				break;
			}
		}
	}

	return result;
}

std::vector<int> LocationManager::GetLifeBoxLocationsForLevel(int levelID)
{
	std::vector<int> result;

	if (this->_lifeBoxesEnabled)
	{
		int checkOffset = 0x1400;

		for (int j = 0; j < 13; j++)
		{
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_ItemBoxData.find(locationID) != this->_ItemBoxData.end())
			{
				ItemBoxCheckData& checkData = this->_ItemBoxData[locationID];
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) == 0x00)
				{
					result.push_back(0x00);
				}
				else
				{
					result.push_back(0x01);
				}
			}
		}
	}

	return result;
}

std::vector<int> LocationManager::GetItemBoxLocationsForLevel(int levelID)
{
	std::vector<int> result;

	if (this->_itemBoxesEnabled)
	{
		int checkOffset = 0x1600;

		for (int j = 0; j < 40; j++)
		{
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_ItemBoxData.find(locationID) != this->_ItemBoxData.end())
			{
				ItemBoxCheckData& checkData = this->_ItemBoxData[locationID];
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) == 0x00)
				{
					result.push_back(0x00);
				}
				else
				{
					result.push_back(0x01);
				}
			}
		}
	}

	return result;
}

std::vector<int> LocationManager::GetBigLocationsForLevel(int levelID)
{
	std::vector<int> result;

	if (this->_bigEnabled)
	{
		int checkOffset = 0x1B00;

		for (int j = 0; j < 5; j++)
		{
			int locationID = checkOffset + (j * 0x20) + levelID;
			if (this->_BigData.find(locationID) != this->_BigData.end())
			{
				BigCheckData& checkData = this->_BigData[locationID];
				char dataValue = *(char*)checkData.Address;

				char bitFlag = (char)(0x01 << checkData.AddressBit);

				if ((dataValue & bitFlag) == 0x00)
				{
					result.push_back(0x00);
				}
				else
				{
					result.push_back(0x01);
				}
			}
		}
	}

	return result;
}

int LocationManager::GetMaxMarketTokens()
{
	if (this->_blackMarketSlots > 0)
	{
		return this->_blackMarketUnlockCosts[this->_blackMarketSlots - 1];
	}
	else
	{
		return 0;
	}
}

bool LocationManager::AreAllRacesComplete()
{
	for (auto& pair : this->_KartRaceData)
	{
		if (this->_kartRacesEnabled == 1)
		{
			// Mini
			if (pair.first <= KartRaceCheck::KRC_Expert_Rouge)
			{
				continue;
			}
		}
		else
		{
			// Full
			if (pair.first > KartRaceCheck::KRC_Expert_Rouge)
			{
				continue;
			}
		}

		if (!pair.second.CheckSent)
		{
			return false;
		}
	}

	return true;
}

std::vector<int> LocationManager::GetChaoBeginnerRaceLocations()
{
	std::vector<int> result;

	if (this->_chaoRaceEnabled > 0)
	{
		if (this->_racesPacked)
		{
			result.push_back(4);
		}
		else
		{
			result.push_back(12);
		}

		int count = 0;

		for (auto& pair : this->_ChaoGardenData)
		{
			if (pair.first > ChaoGardenCheck::CGC_BlockCanyon_3)
			{
				continue;
			}

			if (this->_racesPacked == 1)
			{
				// Prize
				if (pair.first != ChaoGardenCheck::CGC_CrabPool_3 &&
					pair.first != ChaoGardenCheck::CGC_StumpValley_3 &&
					pair.first != ChaoGardenCheck::CGC_MushroomForest_3 &&
					pair.first != ChaoGardenCheck::CGC_BlockCanyon_3)
				{
					continue;
				}
			}

			if (pair.second.CheckSent)
			{
				count++;
			}
		}

		result.push_back(count);
	}

	return result;
}

std::vector<int> LocationManager::GetChaoChallengeRaceLocations()
{
	std::vector<int> result;

	if (this->_chaoRaceEnabled > 1)
	{
		if (this->_racesPacked)
		{
			result.push_back(3);
		}
		else
		{
			result.push_back(12);
		}

		int count = 0;

		for (auto& pair : this->_ChaoGardenData)
		{
			if (pair.first < ChaoGardenCheck::CGC_Challenge_1 || pair.first > ChaoGardenCheck::CGC_Challenge_12)
			{
				continue;
			}

			if (this->_racesPacked == 1)
			{
				// Prize
				if (pair.first != ChaoGardenCheck::CGC_Challenge_4 &&
					pair.first != ChaoGardenCheck::CGC_Challenge_8 &&
					pair.first != ChaoGardenCheck::CGC_Challenge_12)
				{
					continue;
				}
			}

			if (pair.second.CheckSent)
			{
				count++;
			}
		}

		result.push_back(count);
	}

	return result;
}

std::vector<int> LocationManager::GetChaoHeroRaceLocations()
{
	std::vector<int> result;

	if (this->_chaoRaceEnabled > 1)
	{
		if (this->_racesPacked)
		{
			result.push_back(2);
		}
		else
		{
			result.push_back(4);
		}

		int count = 0;

		for (auto& pair : this->_ChaoGardenData)
		{
			if (pair.first < ChaoGardenCheck::CGC_Hero_1 || pair.first > ChaoGardenCheck::CGC_Hero_4)
			{
				continue;
			}

			if (this->_racesPacked == 1)
			{
				// Prize
				if (pair.first != ChaoGardenCheck::CGC_Hero_2 &&
					pair.first != ChaoGardenCheck::CGC_Hero_4)
				{
					continue;
				}
			}

			if (pair.second.CheckSent)
			{
				count++;
			}
		}

		result.push_back(count);
	}

	return result;
}

std::vector<int> LocationManager::GetChaoDarkRaceLocations()
{
	std::vector<int> result;

	if (this->_chaoRaceEnabled > 1)
	{
		if (this->_racesPacked)
		{
			result.push_back(2);
		}
		else
		{
			result.push_back(4);
		}

		int count = 0;

		for (auto& pair : this->_ChaoGardenData)
		{
			if (pair.first < ChaoGardenCheck::CGC_Dark_1 || pair.first > ChaoGardenCheck::CGC_Dark_4)
			{
				continue;
			}

			if (this->_racesPacked == 1)
			{
				// Prize
				if (pair.first != ChaoGardenCheck::CGC_Dark_2 &&
					pair.first != ChaoGardenCheck::CGC_Dark_4)
				{
					continue;
				}
			}

			if (pair.second.CheckSent)
			{
				count++;
			}
		}

		result.push_back(count);
	}

	return result;
}

std::vector<int> LocationManager::GetChaoJewelRaceLocations(JewelRaceCategory jewel)
{
	std::vector<int> result;

	if (this->_chaoRaceEnabled > 2)
	{
		if (this->_racesPacked)
		{
			result.push_back(1);
		}
		else
		{
			result.push_back(5);
		}

		int count = 0;

		for (auto& pair : this->_ChaoGardenData)
		{
			if (pair.first < (ChaoGardenCheck::CGC_Aquamarine_1 + (5 * jewel)) ||
			   (pair.first > (ChaoGardenCheck::CGC_Aquamarine_5 + (5 * jewel))))
			{
				continue;
			}

			if (this->_racesPacked == 1)
			{
				// Prize
				if (pair.first != (ChaoGardenCheck::CGC_Aquamarine_5 + (5 * jewel)))
				{
					continue;
				}
			}

			if (pair.second.CheckSent)
			{
				count++;
			}
		}

		result.push_back(count);
	}

	return result;
}

std::vector<int> LocationManager::GetChaoKarateLocations()
{
	std::vector<int> result;

	if (this->_chaoKarateEnabled > 0)
	{
		if (this->_racesPacked)
		{
			result.push_back(this->_chaoKarateEnabled);
		}
		else
		{
			result.push_back(this->_chaoKarateEnabled * 5);
		}

		int count = 0;

		for (auto& pair : this->_ChaoGardenData)
		{
			if (pair.first < ChaoGardenCheck::CGC_BEGIN_KARATE || pair.first > ChaoGardenCheck::CGC_END_KARATE)
			{
				continue;
			}

			if (this->_racesPacked == 1)
			{
				// Prize
				if (pair.first != ChaoGardenCheck::CGC_Beginner_Karate_5 &&
					pair.first != ChaoGardenCheck::CGC_Intermediate_Karate_5 &&
					pair.first != ChaoGardenCheck::CGC_Expert_Karate_5 &&
					pair.first != ChaoGardenCheck::CGC_Super_Karate_5)
				{
					continue;
				}
			}

			if (pair.second.CheckSent)
			{
				if (pair.first - ChaoGardenCheck::CGC_BEGIN_KARATE < this->_chaoKarateEnabled * 5)
				{
					count++;
				}
			}
		}

		if (count > result[0])
		{
			count = result[0];
		}

		result.push_back(count);
	}

	return result;
}

std::vector<int> LocationManager::GetChaoStatLocations(ChaoStatCheckType stat)
{
	std::vector<int> result;

	if (this->_chaoStatsEnabled > 0)
	{
		if (stat == ChaoStatCheckType::CSCT_Stamina && !this->_chaoStatsStaminaEnabled)
		{
			return result;
		}

		if ((stat == ChaoStatCheckType::CSCT_Luck || stat == ChaoStatCheckType::CSCT_Intelligence) && !this->_chaoStatsHiddenEnabled)
		{
			return result;
		}

		result.push_back(this->_chaoStatsEnabled);
		int countDone = 0;

		int locID = ChaoStatCheck::CSC_BEGIN + (0x80 * stat) + 1;
		if (this->_ChaoStatData.find(locID) != this->_ChaoStatData.end())
		{
			ChaoStatCheckData& checkData = this->_ChaoStatData[locID];
			char dataValue = *(char*)checkData.Address;
			countDone = (int)dataValue;
			result.push_back(countDone);
		}
	}

	return result;
}

std::vector<int> LocationManager::GetChaoAnimalPartLocations(ChaoBodyPartAnimal animal)
{
	std::vector<int> result;

	if (this->_chaoBodyPartsEnabled)
	{
		int countTotal = 0;
		int countDone = 0;

		for (int i = (ChaoBodyPartCheck::CBPC_BEGIN + (8 * animal)); i < (ChaoBodyPartCheck::CBPC_BEGIN + (8 * (animal + 1))); i++)
		{
			if (this->_ChaoBodyPartData.find(i) != this->_ChaoBodyPartData.end())
			{
				countTotal++;

				ChaoBodyPartCheckData& checkData = this->_ChaoBodyPartData[i];
				if (checkData.CheckSent)
				{
					countDone++;
				}
			}
		}

		if (countTotal > 0)
		{
			result.push_back(countTotal);
			result.push_back(countDone);
		}
	}

	return result;
}

std::vector<int> LocationManager::GetChaoLessonLocations(ChaoLessonType lesson)
{
	std::vector<int> result;

	if (this->_chaoKindergartenEnabled == 2)
	{
		int countTotal = 0;
		int countDone = 0;

		for (int i = (ChaoKindergartenCheck::CKgC_BEGIN + (0x8 * lesson)); i < (ChaoKindergartenCheck::CKgC_BEGIN + (0x8 * (lesson + 1))); i++)
		{
			if (this->_ChaoKindergartenData.find(i) != this->_ChaoKindergartenData.end())
			{
				countTotal++;

				ChaoKindergartenCheckData& checkData = this->_ChaoKindergartenData[i];
				if (checkData.CheckSent)
				{
					countDone++;
				}
			}
		}

		result.push_back(countTotal);
		result.push_back(countDone);
	}
	else if (this->_chaoKindergartenEnabled == 1)
	{
		int countTotal = 0;
		int countDone = 0;

		if (this->_ChaoKindergartenData.find(ChaoKindergartenCheck::CKgC_AnyDrawing + lesson) != this->_ChaoKindergartenData.end())
		{
			countTotal++;

			ChaoKindergartenCheckData& checkData = this->_ChaoKindergartenData[ChaoKindergartenCheck::CKgC_AnyDrawing + lesson];
			if (checkData.CheckSent)
			{
				countDone++;
			}
		}

		result.push_back(countTotal);
		result.push_back(countDone);
	}

	return result;
}

std::vector<int> LocationManager::GetCompletedBlackMarketLocations()
{
	std::vector<int> result;

	if (this->_blackMarketSlots > 0)
	{
		int countTotal = 0;
		int countDone = 0;

		for (int i = (BlackMarketCheck::BMC_BEGIN + 1); i <= (BlackMarketCheck::BMC_BEGIN + this->_blackMarketSlots); i++)
		{
			if (this->_BlackMarketLocationData.find(i) != this->_BlackMarketLocationData.end())
			{
				countTotal++;

				BlackMarketCheckData& checkData = this->_BlackMarketLocationData[i];
				if (checkData.CheckSent)
				{
					countDone++;
				}
			}
		}

		result.push_back(countTotal);
		result.push_back(countDone);
	}

	return result;
}

std::vector<int> LocationManager::GetAvailableBlackMarketLocations()
{
	std::vector<int> result;

	if (this->_blackMarketSlots > 0)
	{
		for (int i = 0; i < this->_blackMarketSlots; i++)
		{
			if (this->_BlackMarketLocationData.find(BlackMarketCheck::BMC_BEGIN + 1 + i) != this->_BlackMarketLocationData.end())
			{
				if (BlackMarketTokenCount >= this->_blackMarketUnlockCosts[i])
				{
					BlackMarketCheckData& checkData = this->_BlackMarketLocationData[BlackMarketCheck::BMC_BEGIN + 1 + i];
					if (!checkData.CheckSent)
					{
						result.push_back(i);
					}
				}
			}
		}
	}

	return result;
}
