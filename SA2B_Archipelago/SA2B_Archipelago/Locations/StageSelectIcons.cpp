#include "../pch.h"
#include "StageSelectData.h"
#include "StageSelectIcons.h"
#include "StageSelectManager.h"
#include "../Utilities/MessageQueue.h"
#include "LocationManager.h"
#include "../Items/ItemManager.h"
#include <map>

FunctionPointer(void, ReleaseTextureList, (NJS_TEXLIST* a1), 0x77F9F0);

DataPointer(char, SS_SelectedTile, 0x1D1BF08);

static std::map<int, ItemData>* ItemData_ptr;
static std::vector<CharacterItemRange>* CharacterItemRanges_ptr;
static std::map<int, StageSelectStageData>* StageSelectDataMap_ptr;

static float minXPos;
static float maxXPos;

std::array<int, 33> TileIDtoStageIndex = {
		SSS_HiddenBase,
		SSS_PyramidCave,
		SSS_DeathChamber,
		SSS_EggQuarters,
		SSS_SandOcean,
		SSS_DryLagoon,
		SSS_WeaponsBed,
		SSS_PrisonLane,
		SSS_WildCanyon,
		SSS_IronGate,
		SSS_SecurityHall,
		SSS_MetalHarbor,
		SSS_SkyRail,
		SSS_WhiteJungle,
		SSS_GreenForest,
		SSS_PumpkinHill,
		SSS_AquaticMine,
		SSS_GreenHill,
		SSS_Route280,
		SSS_RadicalHighway,
		SSS_Route101,
		SSS_MissionStreet,
		SSS_ChaoGarden,
		SSS_CityEscape,
		SSS_CrazyGadget,
		SSS_EternalEngine,
		SSS_CosmicWall,
		SSS_MeteorHerd,
		SSS_LostColony,
		SSS_CannonCore,
		SSS_FinalChase,
		SSS_FinalRush,
		SSS_MadSpace
};

std::map<char, NumberDisplayData> NumberMap = {
	{'0', NumberDisplayData(-1, 40.0f, 0.0f, 4.0f)},
	{'1', NumberDisplayData(0, 18.0f, 0.0f, 4.0f)},
	{'2', NumberDisplayData(1, 40.0f, 0.0f, 4.0f)},
	{'3', NumberDisplayData(2, 40.0f, 0.0f, 4.0f)},
	{'4', NumberDisplayData(3, 40.0f, 0.0f, 4.0f)},
	{'5', NumberDisplayData(4, 40.0f, 0.0f, 4.0f)},
	{'6', NumberDisplayData(5, 40.0f, 0.0f, 4.0f)},
	{'7', NumberDisplayData(6, 40.0f, 0.0f, 4.0f)},
	{'8', NumberDisplayData(7, 40.0f, 0.0f, 4.0f)},
	{'9', NumberDisplayData(8, 40.0f, 0.0f, 4.0f)},
	{'/', NumberDisplayData(9, 32.0f, 0.0f, 4.0f)},
	{':', NumberDisplayData(10, 16.0f, 0.0f, 4.0f)},
};

static const int Anim_Length = 29;
static const int Stage_Anim_Length = 24;
static const int Num_Anim_Length = 13;

static NJS_TEXNAME UpgradeIconsTexName[Anim_Length];
static NJS_TEXNAME UpgradeIconsTexName_Inactive[Anim_Length];
static NJS_TEXNAME StageSelectTexName[Stage_Anim_Length];
static NJS_TEXNAME NumTexName[Num_Anim_Length];

static NJS_TEXANIM UpgradeIconsAnim[Anim_Length];
static NJS_TEXANIM UpgradeIconsAnim_Inactive[Anim_Length];
static NJS_TEXANIM StageSelectAnim[Stage_Anim_Length];
static NJS_TEXANIM NumAnim[] = {
	{40, 32, 20, 16, 0x0A, 0x10, 0x34, 0x30, 0, 0},
	{18, 32, 9, 16, 0x57, 0x10, 0x68, 0x30, 0, 0},
	{40, 32, 20, 16, 0x8A, 0x10, 0xB3, 0x30, 0, 0},
	{40, 32, 20, 16, 0xCA, 0x10, 0xF3, 0x30, 0, 0},
	{40, 32, 20, 16, 0x0A, 0x50, 0x34, 0x70, 0, 0},
	{40, 32, 20, 16, 0x4A, 0x50, 0x74, 0x70, 0, 0},
	{40, 32, 20, 16, 0x8A, 0x50, 0xB3, 0x70, 0, 0},
	{40, 32, 20, 16, 0xCA, 0x50, 0xF3, 0x70, 0, 0},
	{40, 32, 20, 16, 0x0A, 0x90, 0x34, 0xB0, 0, 0},
	{40, 32, 20, 16, 0x4A, 0x90, 0x74, 0xB0, 0, 0},
	{32, 32, 16, 16, 0x90, 0x88, 0xAF, 0xB7, 0, 0},
	{16, 32, 8, 16, 0xD8, 0x90, 0xE7, 0xB0, 0, 0},
	{40, 32, 20, 16, 0x0A, 0x10, 0x34, 0x30, 0, 0},
};

static NJS_TEXLIST UpgradeIconsTex = { UpgradeIconsTexName, Anim_Length };
static TexPackInfo TexPack = { "AP_UPGRADEICONS", &UpgradeIconsTex };

static NJS_TEXLIST UpgradeIconsTex_Inactive = { UpgradeIconsTexName_Inactive, Anim_Length };
static TexPackInfo TexPack_Inactive = { "AP_UPGRADEICONS_GREY", &UpgradeIconsTex_Inactive };

static NJS_TEXLIST StageSelectTex = { StageSelectTexName, Stage_Anim_Length };
static TexPackInfo StageSelectPack = { "AP_STAGESELECT", &StageSelectTex };

static NJS_TEXLIST NumTex = { NumTexName, Num_Anim_Length };
static TexPackInfo NumPack = { "AP_Numbers", &NumTex };

static NJS_SPRITE Sprite = { { -32.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &UpgradeIconsTex, &UpgradeIconsAnim[0] };
static NJS_SPRITE Sprite_2 = { { -32.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &UpgradeIconsTex_Inactive, &UpgradeIconsAnim_Inactive[0] };
static NJS_SPRITE StageSelectSprite = { { -32.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &StageSelectTex, &StageSelectAnim[0] };
static NJS_SPRITE NumSprite = { { -32.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &NumTex, &NumAnim[0] };
static NJS_SPRITE EmeraldSprites[] = { 
	{ { 208.0f, 0.0f, 0.0f }, 0.25f, 0.25f, 0, &StageSelectTex, &StageSelectAnim[0] },
	{ { 208.0f, 0.0f, 0.0f }, 0.25f, 0.25f, 0, &StageSelectTex, &StageSelectAnim[0] },
	{ { 208.0f, 0.0f, 0.0f }, 0.25f, 0.25f, 0, &StageSelectTex, &StageSelectAnim[0] },
	{ { 208.0f, 0.0f, 0.0f }, 0.25f, 0.25f, 0, &StageSelectTex, &StageSelectAnim[0] },
	{ { 208.0f, 0.0f, 0.0f }, 0.25f, 0.25f, 0, &StageSelectTex, &StageSelectAnim[0] },
	{ { 208.0f, 0.0f, 0.0f }, 0.25f, 0.25f, 0, &StageSelectTex, &StageSelectAnim[0] },
	{ { 208.0f, 0.0f, 0.0f }, 0.25f, 0.25f, 0, &StageSelectTex, &StageSelectAnim[0] },
};

CharacterItemRange GetItemRangeForCharacter(char character)
{
	for (int i = 0; i < (*CharacterItemRanges_ptr).size(); i++)
	{
		if ((*CharacterItemRanges_ptr)[i].Character == character)
		{
			return (*CharacterItemRanges_ptr)[i];
		}
	}
	return CharacterItemRange();
}

void DrawString(std::string string, float xPos, float yPos, float scale = 1.0f) 
{
	for (std::string::iterator it = string.begin(); it != string.end(); ++it) 
	{
		auto data = NumberMap[*it];
		xPos += data.width * 0.5f * scale;
		NumSprite.tanim = &NumAnim[data.index];
		NumSprite.p = { xPos + (data.xOffset * scale), yPos + (data.yOffset * scale), 0.0f };
		NumSprite.sx = scale;
		NumSprite.sy = scale;
		xPos += data.width * 0.5f * scale;
		njDrawSprite2D(&NumSprite, 1, 1, NJD_SPRITE_ALPHA);
	}
}

void UpdateLevelCheckIcons()
{
	int currentTileStageIndex = TileIDtoStageIndex[SS_SelectedTile];
	LocationManager* locMan = &LocationManager::getInstance();
	std::vector<int> chaoKeys = locMan->GetChaoKeyLocationsForLevel(currentTileStageIndex);
	std::vector<int> pipes = locMan->GetPipeLocationsForLevel(currentTileStageIndex);
	std::vector<int> hiddens = locMan->GetHiddenLocationsForLevel(currentTileStageIndex);
	std::vector<int> beetles = locMan->GetGoldBeetleLocationsForLevel(currentTileStageIndex);
	StageSelectSprite.sx = 0.25f;
	StageSelectSprite.sy = 0.25f;
	int xCount = 0;
	int itemCount = 0;
	float yPos = 0.0f;
	int debugIndex = 0;
	if ((*StageSelectDataMap_ptr).at(currentTileStageIndex).UpgradeAddress > 0x00) 
	{
		int icon = *(char*)(*StageSelectDataMap_ptr).at(currentTileStageIndex).UpgradeAddress > 0x00 ? SSI_Upgrade : SSI_UpgradeDisabled;
		StageSelectSprite.tanim = &StageSelectAnim[icon];
		StageSelectSprite.p = { maxXPos - ((xCount + 1) * 32.0f), yPos, 0.0f };
		njDrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
		xCount++;
	}
	if (beetles.size() > 0) 
	{
		for (int i = beetles.size() - 1; i >= 0; i--)
		{
			int beetleIcon = *(char*)beetles[i] == 0x01 ? SSI_GoldBeetle : SSI_GoldBeetleDisabled;
			StageSelectSprite.tanim = &StageSelectAnim[beetleIcon];
			StageSelectSprite.p = { maxXPos - ((xCount + 1) * 32.0f), yPos, 0.0f };
			njDrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			xCount++;
		}
	}
	if (chaoKeys.size() > 0) 
	{
		itemCount = chaoKeys.size();
		for (int i = chaoKeys.size() - 1; i >= 0; i--)
		{
			int chaoIcon = *(char*)chaoKeys[i] == 0x01 ? SSI_ChaoKey : SSI_ChaoKeyDisabled;
			float x = maxXPos - ((xCount + 1) * 32.0f);
			StageSelectSprite.tanim = &StageSelectAnim[chaoIcon];
			StageSelectSprite.p = { x, yPos, 0.0f };
			njDrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			StageSelectManager::DrawDebugText(NJM_LOCATION(0, 0), "");
			//x += 4;
			DrawString(std::to_string(itemCount), (maxXPos - ((xCount + 1) * 32.0f)) + 4.0f, yPos + 24.0f, 0.25f);
			xCount++;
			itemCount--;
		}
	}
	StageSelectSprite.sx = 0.1875f;
	StageSelectSprite.sy = 0.1875f;
	if (xCount > 0) 
	{
		xCount = 0;
		yPos = 32.0f;
	}
	if (pipes.size() > 0)
	{
		itemCount = pipes.size();
		for (int i = pipes.size() - 1; i >= 0; i--)
		{
			int pipeIcon = *(char*)pipes[i] == 0x01 ? SSI_Pipe : SSI_PipeDisabled;
			float x = maxXPos - ((xCount + 1) * 24.0f);
			StageSelectSprite.tanim = &StageSelectAnim[pipeIcon];
			StageSelectSprite.p = { x, yPos, 0.0f };
			njDrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			StageSelectManager::DrawDebugText(NJM_LOCATION(0, 0), "");
			//x += 2;
			DrawString(std::to_string(itemCount), (maxXPos - ((xCount + 1) * 24.0f)) + 2.0f, yPos + 18.0f, 0.1875f);
			xCount++;
			itemCount--;
		}
		yPos += 24.0f;
		xCount = 0;
	}
	if (hiddens.size() > 0)
	{
		itemCount = hiddens.size();
		for (int i = hiddens.size() - 1; i >= 0; i--)
		{
			int hiddenIcon = *(char*)hiddens[i] == 0x01 ? SSI_Hidden : SSI_HiddenDisabled;
			float x = maxXPos - ((xCount + 1) * 24.0f);
			StageSelectSprite.tanim = &StageSelectAnim[hiddenIcon];
			StageSelectSprite.p = { x, yPos, 0.0f };
			njDrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			StageSelectManager::DrawDebugText(NJM_LOCATION(0, 0), "");
			//x += 2;
			DrawString(std::to_string(itemCount), (maxXPos - ((xCount + 1) * 24.0f)) + 2.0f, yPos + 18.0f, 0.1875f);
			xCount++;
			itemCount--;
		}
	}
}

void UpdateChaosEmeraldIcons()
{
	int goal = StageSelectManager::GetInstance().GetGoal();
	if (goal == 1 || goal == 2) 
	{
		ItemManager* itemMan = &ItemManager::getInstance();
		std::vector<int> chaosEmeralds = itemMan->GetChaosEmeraldAddresses();
		StageSelectSprite.sx = 0.25f;
		StageSelectSprite.sy = 0.25f;
		//float xStart = 208.0f;
		for (int i = 0; i < chaosEmeralds.size(); i++)
		{
			int emeraldIcon = *(char*)chaosEmeralds[i] == 0x01 ? SSI_Emerald_White + i : SSI_Emerald_None;
			float x = 208.0f + (i * 32.0f);
			EmeraldSprites[i].tanim = &StageSelectAnim[emeraldIcon];
			EmeraldSprites[i].p = { x, 380.0f, 0.0f };
			njDrawSprite2D(&EmeraldSprites[i], 1, 1, NJD_SPRITE_ALPHA);
			//StageSelectManager::DrawDebugText(NJM_LOCATION(0, 0), "");
		}
	}
}

void UpdateUpgradeIcons()
{
	if (SS_SelectedTile < TileIDtoStageIndex.size())
	{
		int currentTileStageIndex = TileIDtoStageIndex[SS_SelectedTile];
		if (currentTileStageIndex < (*StageSelectDataMap_ptr).size())
		{
			char character = *(char*)(*StageSelectDataMap_ptr).at(currentTileStageIndex).TileCharacterAddress;
			CharacterItemRange range = GetItemRangeForCharacter(character);
			int iconPos = 0;
			Sprite.sx = 0.21875f;
			Sprite.sy = 0.21875f;
			Sprite_2.sx = 0.21875f;
			Sprite_2.sy = 0.21875f;
			for (int i = range.End; i >= range.Start; i--)
			{
				if (*(char*)(*ItemData_ptr).at(i).Address > 0x00)
				{
					Sprite.tanim = &UpgradeIconsAnim[(*ItemData_ptr).at(i).IconIndex];
					Sprite.p = { maxXPos - ((iconPos + 1) * 28.0f), 414.0f, 0.0f };
					njDrawSprite2D(&Sprite, 1, 1, NJD_SPRITE_ALPHA);
				}
				else
				{
					Sprite_2.tanim = &UpgradeIconsAnim_Inactive[(*ItemData_ptr).at(i).IconIndex];
					Sprite_2.p = { maxXPos - ((iconPos + 1) * 28.0f), 414.0f, 0.0f };
					njDrawSprite2D(&Sprite_2, 1, 1, NJD_SPRITE_ALPHA);
				}			
				iconPos++;
			}
		}
	}
}

void DeleteUpgradeIcon(ObjectMaster* obj)
{
	ReleaseTextureList(&UpgradeIconsTex);
	ReleaseTextureList(&UpgradeIconsTex_Inactive);
	ReleaseTextureList(&StageSelectTex);
	ReleaseTextureList(&NumTex);
	StageSelectIcons::GetInstance().DrawIconObj = nullptr;
}

void DrawUpgradeIcon(ObjectMaster* obj)
{
	if (CurrentMenu == Menus::Menus_StageSelect && GameMode == GameMode::GameMode_Advertise)
	{
		UpdateChaosEmeraldIcons();
		UpdateUpgradeIcons();
		UpdateLevelCheckIcons();
	}
}

void DrawUpgradeIconMain(ObjectMaster* obj)
{
	if (GameState != GameStates_LoadFinished)
		return;

	if (obj->Data1.Entity->Action == 0) {
		obj->DeleteSub = DeleteUpgradeIcon;
		obj->DisplaySub_Delayed3 = DrawUpgradeIcon;
		obj->Data1.Entity->Action = 1;
	}
}

void StageSelectIcons::OnInit(std::map<int, StageSelectStageData>* stageSelectDataMap)
{
	InitializeItemData(this->ItemData);
	InitializeCharacterItemRanges(this->CharacterItemRanges);
	CharacterItemRanges_ptr = &CharacterItemRanges;
	ItemData_ptr = &ItemData;
	StageSelectDataMap_ptr = stageSelectDataMap;

	for (int i = 0; i < Anim_Length; i++)
	{
		UpgradeIconsAnim[i] = { 0x80, 0x80, 0, 0, 0, 0, 0x100, 0x100, (Sint16)(i - 1), NJD_SPRITE_ALPHA };
		UpgradeIconsAnim_Inactive[i] = { 0x80, 0x80, 0, 0, 0, 0, 0x100, 0x100, (Sint16)(i - 1), NJD_SPRITE_ALPHA };
	}

	for (int i = 0; i < Stage_Anim_Length; i++)
	{
		StageSelectAnim[i] = { 0x80, 0x80, 0, 0, 0, 0, 0x100, 0x100, (Sint16)(i - 1), NJD_SPRITE_ALPHA };
	}

	float ratio = 480.0f / VerticalResolution;
	float adjustedHorizontal = HorizontalResolution * ratio;
	float adjustedMin = (adjustedHorizontal - 640.0f) / 2.0f;
	float adjustedMax = adjustedHorizontal - adjustedMin;
	adjustedMin = -adjustedMin;
	minXPos = adjustedMin;
	maxXPos = adjustedMax;
}

void StageSelectIcons::OnFrame() 
{
	if (!DrawIconObj && CurrentMenu == Menus::Menus_StageSelect && GameMode == GameMode::GameMode_Advertise) //GameState == GameStates_LoadItems)
	{
		LoadTextures(&TexPack);
		LoadTextures(&TexPack_Inactive);
		LoadTextures(&StageSelectPack);
		LoadTextures(&NumPack);
		DrawIconObj = LoadObject(0, "UpgradeIcon", DrawUpgradeIconMain, LoadObj_Data1 | LoadObj_Data2);
		DrawIconObj->DeleteSub = DeleteUpgradeIcon;
		DrawIconObj->MainSub = DrawUpgradeIconMain;
		DrawIconObj->DisplaySub_Delayed3 = DrawUpgradeIcon;
	}
}