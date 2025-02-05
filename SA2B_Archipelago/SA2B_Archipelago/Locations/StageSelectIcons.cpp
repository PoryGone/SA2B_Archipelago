#include "../pch.h"
#include "StageSelectData.h"
#include "StageSelectIcons.h"
#include "StageSelectManager.h"
#include "../Utilities/MessageQueue.h"
#include "LocationManager.h"
#include "ChaoGardenManager.h"
#include "../Items/ItemManager.h"
#include "../Items/Minigames/MinigameManager.h"
#include "../Utilities/SpriteUtilities.h"
#include <map>

FunctionPointer(void, ReleaseTextureList, (NJS_TEXLIST* a1), 0x77F9F0);

DataPointer(char, SS_SelectedTile, 0x1D1BF08);
DataPointer(char, ActiveMission, 0x174AFE3);
DataPointer(char, SS_CameraPos, 0x1D1BEC0);
DataPointer(int, RealEmblemCount, 0x1DEE418);
DataPointer(unsigned int, BlackMarketTokenCount, 0x1DEE41C);

static std::map<int, ItemData>* ItemData_ptr;
static std::vector<CharacterItemRange>* CharacterItemRanges_ptr;
static std::map<int, StageSelectStageData>* StageSelectDataMap_ptr;

static float minXPos;
static float maxXPos;

#define PAGE_SWAP_TIME 120

static int currentPage = 0;
static int paginateTimer = PAGE_SWAP_TIME;
static bool paginateManual = false;
static int lastGameMode;
static int lastTile;

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
	{'X', NumberDisplayData(11, 40.0f, 0.0f, 4.0f)},
};

static const int Anim_Length = 29;
static const int Stage_Anim_Length = 158;
static const int Stage_Tex_Length = 123;
static const int Num_Anim_Length = 24;

static NJS_TEXNAME UpgradeIconsTexName[Anim_Length];
static NJS_TEXNAME UpgradeIconsTexName_Inactive[Anim_Length];
static NJS_TEXNAME StageSelectTexName[Stage_Anim_Length];
static NJS_TEXNAME NumTexName[Num_Anim_Length];

static NJS_TEXANIM UpgradeIconsAnim[Anim_Length];
static NJS_TEXANIM UpgradeIconsAnim_Inactive[Anim_Length];
static NJS_TEXANIM StageSelectAnim[Stage_Anim_Length] = {
	//Padding
	{40, 32, 20, 16, 0x0A, 0x10, 0x34, 0x30, 1, 0},
	//Checks
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 0, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 1, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 2, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 3, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 4, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 5, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 6, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 7, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 8, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 9, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 10, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 11, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 12, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 13, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 14, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 15, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 16, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 17, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 18, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 19, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 20, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 21, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 22, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 23, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 24, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 25, 0},
	{ 128, 256, 64, 128, 0, 0, 0x100, 0x100, 26, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 27, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 28, 0},

	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 29, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 30, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 31, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 32, 0},
	
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 33, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 34, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 35, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 36, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 37, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 38, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 39, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 40, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 41, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 42, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 43, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 44, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 45, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 46, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 47, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 48, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 49, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 50, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 51, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 52, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 53, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 54, 0},

	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 55, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 56, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 57, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 58, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 59, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 60, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 61, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 62, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 63, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 64, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 65, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 66, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 67, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 68, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 69, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 70, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 71, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 72, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 73, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 74, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 75, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 76, 0},

	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 77, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 78, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 79, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 80, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 81, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 82, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 83, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 84, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 85, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 86, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 87, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 88, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 89, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 90, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 91, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 92, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 93, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 94, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 95, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 96, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 97, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 98, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 99, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 100, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 101, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 102, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 103, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 104, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 105, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 106, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 107, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 108, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 109, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 110, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 111, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 112, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 113, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 114, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 115, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 116, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 117, 0},
	{ 128, 128, 0, 0, 0, 0, 0x100, 0x100, 118, 0},
	//Atlas 0
	{ 128, 128, 0, 0, 0x00, 0x00, 0x3F, 0x3F, 119, 0},
	{ 128, 128, 0, 0, 0x40, 0x00, 0x7F, 0x3F, 119, 0},
	{ 128, 128, 0, 0, 0x80, 0x00, 0xBF, 0x3F, 119, 0},
	{ 128, 128, 0, 0, 0xC0, 0x00, 0xFF, 0x3F, 119, 0},
	{ 128, 128, 0, 0, 0x00, 0x40, 0x3F, 0x7F, 119, 0},
	{ 128, 128, 0, 0, 0x40, 0x40, 0x7F, 0x7F, 119, 0},
	{ 128, 128, 0, 0, 0x80, 0x40, 0xBF, 0x7F, 119, 0},
	{ 128, 128, 0, 0, 0xC0, 0x40, 0xFF, 0x7F, 119, 0},
	{ 128, 128, 0, 0, 0x00, 0x80, 0x3F, 0xBF, 119, 0},
	{ 128, 128, 0, 0, 0x40, 0x80, 0x7F, 0xBF, 119, 0},
	{ 128, 128, 0, 0, 0x80, 0x80, 0xBF, 0xBF, 119, 0},
	{ 128, 128, 0, 0, 0xC0, 0x80, 0xFF, 0xBF, 119, 0},
	{ 128, 128, 0, 0, 0x00, 0xC0, 0x3F, 0xFF, 119, 0},
	{ 128, 128, 0, 0, 0x40, 0xC0, 0x7F, 0xFF, 119, 0},
	{ 128, 128, 0, 0, 0x80, 0xC0, 0xBF, 0xFF, 119, 0},
	{ 128, 128, 0, 0, 0xC0, 0xC0, 0xFF, 0xFF, 119, 0},
	//Atlas 1
	{ 128, 128, 0, 0, 0x00, 0x00, 0x3F, 0x3F, 120, 0},
	{ 128, 128, 0, 0, 0x40, 0x00, 0x7F, 0x3F, 120, 0},
	{ 128, 128, 0, 0, 0x80, 0x00, 0xBF, 0x3F, 120, 0},
	{ 128, 128, 0, 0, 0xC0, 0x00, 0xFF, 0x3F, 120, 0},
	{ 128, 128, 0, 0, 0x00, 0x40, 0x3F, 0x7F, 120, 0},
	{ 128, 128, 0, 0, 0x40, 0x40, 0x7F, 0x7F, 120, 0},
	{ 128, 128, 0, 0, 0x80, 0x40, 0xBF, 0x7F, 120, 0},
	{ 128, 128, 0, 0, 0xC0, 0x40, 0xFF, 0x7F, 120, 0},
	{ 128, 128, 0, 0, 0x00, 0x80, 0x3F, 0xBF, 120, 0},
	{ 128, 128, 0, 0, 0x40, 0x80, 0x7F, 0xBF, 120, 0},
	{ 128, 128, 0, 0, 0x80, 0x80, 0xBF, 0xBF, 120, 0},
	{ 128, 128, 0, 0, 0xC0, 0x80, 0xFF, 0xBF, 120, 0},
	{ 128, 128, 0, 0, 0x00, 0xC0, 0x3F, 0xFF, 120, 0},
	{ 128, 128, 0, 0, 0x40, 0xC0, 0x7F, 0xFF, 120, 0},
	{ 128, 128, 0, 0, 0x80, 0xC0, 0xBF, 0xFF, 120, 0},
	{ 128, 128, 0, 0, 0xC0, 0xC0, 0xFF, 0xFF, 120, 0},
	//Atlas 2
	{ 256, 128, 128, 64, 0x00, 0x00, 0x7F, 0x3F, 121, 0},
	{ 256, 128, 128, 64, 0x80, 0x00, 0xFF, 0x3F, 121, 0},
	{ 128, 128, 64, 64, 0x00, 0x40, 0x3F, 0x7F, 121, 0},
	{ 128, 128, 64, 64, 0x40, 0x40, 0x7F, 0x7F, 121, 0},
	{ 128, 128, 0, 0, 0x80, 0x40, 0xBF, 0x7F, 121, 0 },
	//Padding
	{40, 32, 20, 16, 0x0A, 0x10, 0x34, 0x30, 1, 0},
};

static NJS_TEXANIM NumAnim[] = {
	//Numbers
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
	{40, 32, 20, 16, 0x0A, 0xD0, 0x34, 0xF0, 0, 0},
	//Missions
	{0x31, 0x19, 0x18, 0x0C, 0x00, 0x00, 0x31, 0x32, 1, 0},
	{0x31, 0x19, 0x18, 0x0C, 0x32, 0x00, 0x63, 0x32, 1, 0},
	{0x31, 0x19, 0x18, 0x0C, 0x64, 0x00, 0x95, 0x32, 1, 0},
	{0x31, 0x19, 0x18, 0x0C, 0x96, 0x00, 0xC7, 0x32, 1, 0},
	{0x31, 0x19, 0x18, 0x0C, 0xC8, 0x00, 0xF9, 0x32, 1, 0},

	{0x31, 0x19, 0x18, 0x0C, 0x96, 0x95, 0xC7, 0xC8, 1, 0},
	{0x31, 0x19, 0x18, 0x0C, 0x00, 0xC7, 0x31, 0xFA, 1, 0},
	{0x31, 0x19, 0x18, 0x0C, 0x32, 0xC7, 0x63, 0xFA, 1, 0},
	{0x31, 0x19, 0x18, 0x0C, 0x64, 0xC7, 0x95, 0xFA, 1, 0},
	{0x31, 0x19, 0x18, 0x0C, 0x96, 0xC7, 0xC7, 0xFA, 1, 0},
	//Ranks
	{0x31, 0x31, 0x18, 0x18, 0xC8, 0x33, 0xF9, 0x96, 1, 0}, // E
	{0x31, 0x31, 0x18, 0x18, 0x96, 0x33, 0xC7, 0x96, 1, 0}, // D
	{0x31, 0x31, 0x18, 0x18, 0x64, 0x33, 0x95, 0x96, 1, 0}, // C
	{0x31, 0x31, 0x18, 0x18, 0x32, 0x33, 0x63, 0x96, 1, 0}, // B
	{0x31, 0x31, 0x18, 0x18, 0x00, 0x33, 0x31, 0x96, 1, 0}, // A
	//Padding
	{40, 32, 20, 16, 0x0A, 0x10, 0x34, 0x30, 1, 0},
};

static NJS_TEXLIST UpgradeIconsTex = { UpgradeIconsTexName, Anim_Length };

static NJS_TEXLIST UpgradeIconsTex_Inactive = { UpgradeIconsTexName_Inactive, Anim_Length };

static NJS_TEXLIST StageSelectTex = { StageSelectTexName, Stage_Tex_Length };

static NJS_TEXLIST NumTex = { NumTexName, Num_Anim_Length };

static TexPackInfo TexPacks[] = {
	{ "AP_UPGRADEICONS", &UpgradeIconsTex },
	{ "AP_UPGRADEICONS_GREY", &UpgradeIconsTex_Inactive },
	{ "AP_STAGESELECT", &StageSelectTex },
	{ "AP_Numbers", &NumTex },
	{ nullptr, nullptr }, //Needs to end in a null entry to prevent the LoadTextures call from iterating past the packs
};

static NJS_SPRITE Sprite = { { -32.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &UpgradeIconsTex, &UpgradeIconsAnim[0] };
static NJS_SPRITE Sprite_2 = { { -32.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &UpgradeIconsTex_Inactive, &UpgradeIconsAnim_Inactive[0] };
static NJS_SPRITE StageSelectSprite = { { -32.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &StageSelectTex, &StageSelectAnim[0] };
static NJS_SPRITE NumSprite = { { -32.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &NumTex, &NumAnim[0] };

static int omochaoIconsPerRow = 14;
static int itemBoxIconsPerRow = 14;

static const float maxCCUnlockOffset = 5.0f;
static int currentCCUnlockFrame = 0;
static const int maxCCUnlockFrames = 100;

std::map<int, int> animalOrderMap = {
	{ ChaoBodyPartAnimal::CBPA_Penguin, 10 },
	{ ChaoBodyPartAnimal::CBPA_Seal,	14 },
	{ ChaoBodyPartAnimal::CBPA_Otter,	7 },
	{ ChaoBodyPartAnimal::CBPA_Rabbit,	12 },
	{ ChaoBodyPartAnimal::CBPA_Cheetah, 3 },
	{ ChaoBodyPartAnimal::CBPA_Warthog, 2 },
	{ ChaoBodyPartAnimal::CBPA_Bear,	1 },
	{ ChaoBodyPartAnimal::CBPA_Tiger,	18 },
	{ ChaoBodyPartAnimal::CBPA_Gorilla, 5 },
	{ ChaoBodyPartAnimal::CBPA_Peacock, 9 },
	{ ChaoBodyPartAnimal::CBPA_Parrot,	8 },
	{ ChaoBodyPartAnimal::CBPA_Condor,	20 },
	{ ChaoBodyPartAnimal::CBPA_Skunk,	17 },
	{ ChaoBodyPartAnimal::CBPA_Sheep,	15 },
	{ ChaoBodyPartAnimal::CBPA_Raccoon, 13 },
	{ ChaoBodyPartAnimal::CBPA_Dragon,	4 },
	{ ChaoBodyPartAnimal::CBPA_Unicorn, 19 },
	{ ChaoBodyPartAnimal::CBPA_Phoenix, 11 },
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
		DrawSprite2D(&NumSprite, 1, 1, NJD_SPRITE_ALPHA);
	}
}

float GetStringWidth(std::string string, float scale = 1.0f)
{
	float width = 0;
	for (std::string::iterator it = string.begin(); it != string.end(); ++it)
	{
		auto data = NumberMap[*it];
		width += data.width * scale;
	}
	return width;
}

void UpdateLevelCheckIcons()
{
	bool isBossStage = StageSelectIcons::GetInstance().IsCurrentTileBoss();
	if (isBossStage)
	{
		// Don't show icons on boss tiles
		return;
	}

	LocationManager* locMan = &LocationManager::getInstance();
	int currentTileStageIndex = TileIDtoStageIndex[SS_SelectedTile];
	int xCount = 0;
	int itemCount = 0;
	float yPos = 0.0f;
	int debugIndex = 0;

	if (currentTileStageIndex == SSS_ChaoGarden ||
		(GameState == GameStates_Ingame && CurrentLevel == LevelIDs::LevelIDs_ChaoWorld))
	{
		StageSelectSprite.sx = 0.25f;
		StageSelectSprite.sy = 0.25f;

		std::vector<int> beginnerRaces  = locMan->GetChaoBeginnerRaceLocations();
		std::vector<int> challengeRaces = locMan->GetChaoChallengeRaceLocations();
		std::vector<int> heroRaces      = locMan->GetChaoHeroRaceLocations();
		std::vector<int> darkRaces      = locMan->GetChaoDarkRaceLocations();
		std::vector<int> karateFights   = locMan->GetChaoKarateLocations();

		// Row 1
		if (karateFights.size() > 0)
		{
			int karateIcon = karateFights[1] == karateFights[0] ? SSI_Karate : SSI_KarateDisabled;
			float x = maxXPos - ((xCount + 1) * 32.0f);
			StageSelectSprite.tanim = &StageSelectAnim[karateIcon];
			StageSelectSprite.p = { x, yPos, 0.0f };
			DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			x += 4;
			DrawString(std::to_string(karateFights[1]), x, yPos + 8.0f, 0.25f);
			DrawString(std::to_string(karateFights[0]), x, yPos + 24.0f, 0.25f);
			xCount++;
		}

		for (int i = (int)JewelRaceCategory::JRC_Diamond; i >= JewelRaceCategory::JRC_Aquamarine; i--)
		{
			std::vector<int> jewelRaces = locMan->GetChaoJewelRaceLocations((JewelRaceCategory)i);
			if (jewelRaces.size() > 0)
			{
				int racesIcon = jewelRaces[1] == jewelRaces[0] ? (SSI_Aquamarine + (i * 2)) : (SSI_AquamarineDisabled + (i * 2));
				float x = maxXPos - ((xCount + 1) * 32.0f);
				StageSelectSprite.tanim = &StageSelectAnim[racesIcon];
				StageSelectSprite.p = { x, yPos, 0.0f };
				DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
				x += 4;
				DrawString(std::to_string(jewelRaces[1]), x, yPos + 8.0f, 0.25f);
				DrawString(std::to_string(jewelRaces[0]), x, yPos + 24.0f, 0.25f);
				xCount++;
			}
		}

		if (darkRaces.size() > 0)
		{
			int racesIcon = darkRaces[1] == darkRaces[0] ? SSI_Dark : SSI_DarkDisabled;
			float x = maxXPos - ((xCount + 1) * 32.0f);
			StageSelectSprite.tanim = &StageSelectAnim[racesIcon];
			StageSelectSprite.p = { x, yPos, 0.0f };
			DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			x += 4;
			DrawString(std::to_string(darkRaces[1]), x, yPos + 8.0f, 0.25f);
			DrawString(std::to_string(darkRaces[0]), x, yPos + 24.0f, 0.25f);
			xCount++;
		}

		if (heroRaces.size() > 0)
		{
			int racesIcon = heroRaces[1] == heroRaces[0] ? SSI_Hero : SSI_HeroDisabled;
			float x = maxXPos - ((xCount + 1) * 32.0f);
			StageSelectSprite.tanim = &StageSelectAnim[racesIcon];
			StageSelectSprite.p = { x, yPos, 0.0f };
			DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			x += 4;
			DrawString(std::to_string(heroRaces[1]), x, yPos + 8.0f, 0.25f);
			DrawString(std::to_string(heroRaces[0]), x, yPos + 24.0f, 0.25f);
			xCount++;
		}

		if (challengeRaces.size() > 0)
		{
			int racesIcon = challengeRaces[1] == challengeRaces[0] ? SSI_Challenge : SSI_ChallengeDisabled;
			float x = maxXPos - ((xCount + 1) * 32.0f);
			StageSelectSprite.tanim = &StageSelectAnim[racesIcon];
			StageSelectSprite.p = { x, yPos, 0.0f };
			DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			x += 4;
			DrawString(std::to_string(challengeRaces[1]), x, yPos + 8.0f, 0.25f);
			DrawString(std::to_string(challengeRaces[0]), x, yPos + 24.0f, 0.25f);
			xCount++;
		}

		if (beginnerRaces.size() > 0)
		{
			int racesIcon = beginnerRaces[1] == beginnerRaces[0] ? SSI_Beginner : SSI_BeginnerDisabled;
			float x = maxXPos - ((xCount + 1) * 32.0f);
			StageSelectSprite.tanim = &StageSelectAnim[racesIcon];
			StageSelectSprite.p = { x, yPos, 0.0f };
			DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			x += 4;
			DrawString(std::to_string(beginnerRaces[1]), x, yPos + 8.0f, 0.25f);
			DrawString(std::to_string(beginnerRaces[0]), x, yPos + 24.0f, 0.25f);
			xCount++;
		}
		// End Row 1
		if (xCount > 0)
		{
			xCount = 0;
			yPos = 32.0f;
		}
		// Row 2
		for (int i = (int)ChaoStatCheckType::CSCT_Intelligence; i >= ChaoStatCheckType::CSCT_Swim; i--)
		{
			std::vector<int> statLocs = locMan->GetChaoStatLocations((ChaoStatCheckType)i);
			if (statLocs.size() > 0)
			{
				int racesIcon = statLocs[1] == statLocs[0] ? (SSI_Swim + (i * 2)) : (SSI_SwimDisabled + (i * 2));
				float x = maxXPos - ((xCount + 1) * 32.0f);
				StageSelectSprite.tanim = &StageSelectAnim[racesIcon];
				StageSelectSprite.p = { x, yPos, 0.0f };
				DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
				x += 4;
				DrawString(std::to_string(statLocs[1]), x, yPos + 8.0f, 0.25f);
				DrawString(std::to_string(statLocs[0]), x, yPos + 24.0f, 0.25f);
				xCount++;
			}
		}
		// End Row 2
		if (xCount > 0)
		{
			xCount = 0;
			yPos += 32.0f;
		}
		// Row 3
		for (int i = (int)ChaoLessonType::CLT_Instrument; i >= ChaoLessonType::CLT_Drawing; i--)
		{
			std::vector<int> lessonLocs = locMan->GetChaoLessonLocations((ChaoLessonType)i);
			if (lessonLocs.size() > 0)
			{
				int racesIcon = lessonLocs[1] == lessonLocs[0] ? (SSI_Drawing + (i * 2)) : (SSI_DrawingDisabled + (i * 2));
				float x = maxXPos - ((xCount + 1) * 32.0f);
				StageSelectSprite.tanim = &StageSelectAnim[racesIcon];
				StageSelectSprite.p = { x, yPos, 0.0f };
				DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
				if (lessonLocs[0] > 1)
				{
					x += 4;
					DrawString(std::to_string(lessonLocs[1]), x, yPos + 8.0f, 0.25f);
					DrawString(std::to_string(lessonLocs[0]), x, yPos + 24.0f, 0.25f);
				}
				xCount++;
			}
		}
		std::vector<int> marketLocs = locMan->GetCompletedBlackMarketLocations();
		if (marketLocs.size() > 0)
		{
			int marketIcon = marketLocs[1] == marketLocs[0] ? SSI_BlackMarket : SSI_BlackMarketDisabled;
			float x = maxXPos - ((xCount + 1) * 32.0f);
			StageSelectSprite.tanim = &StageSelectAnim[marketIcon];
			StageSelectSprite.p = { x, yPos, 0.0f };
			DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
			x += 4;
			DrawString(std::to_string(marketLocs[1]), x, yPos + 8.0f, 0.25f);
			DrawString(std::to_string(marketLocs[0]), x, yPos + 24.0f, 0.25f);
			xCount++;
		}
		// End Row 3
		StageSelectSprite.sx = 0.1875f;
		StageSelectSprite.sy = 0.1875f;
		if (xCount > 0)
		{
			xCount = 0;
			yPos += 32.0f;
		}
		// Row 4
		for (int i = (int)ChaoBodyPartAnimal::CBPA_Gorilla; i >= ChaoBodyPartAnimal::CBPA_Penguin; i--)
		{
			std::vector<int> animalParts = locMan->GetChaoAnimalPartLocations((ChaoBodyPartAnimal)i);
			if (animalParts.size() > 0)
			{
				int animalIcon = animalParts[1] == animalParts[0] ? (SSI_Bat + (animalOrderMap[i] * 2)) : (SSI_BatDisabled + (animalOrderMap[i] * 2));
				float x = maxXPos - ((xCount + 1) * 24.0f);
				StageSelectSprite.tanim = &StageSelectAnim[animalIcon];
				StageSelectSprite.p = { x, yPos, 0.0f };
				DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
				x += 4;
				DrawString(std::to_string(animalParts[1]), x, yPos + 6.0f, 0.1875f);
				DrawString(std::to_string(animalParts[0]), x, yPos + 18.0f, 0.1875f);
				xCount++;
			}
		}
		// End Row 4
		if (xCount > 0)
		{
			xCount = 0;
			yPos += 24.0f;
		}
		// Row 5
		for (int i = (int)ChaoBodyPartAnimal::CBPA_Phoenix; i >= ChaoBodyPartAnimal::CBPA_Peacock; i--)
		{
			std::vector<int> animalParts = locMan->GetChaoAnimalPartLocations((ChaoBodyPartAnimal)i);
			if (animalParts.size() > 0)
			{
				int animalIcon = animalParts[1] == animalParts[0] ? (SSI_Bat + (animalOrderMap[i] * 2)) : (SSI_BatDisabled + (animalOrderMap[i] * 2));
				float x = maxXPos - ((xCount + 1) * 24.0f);
				StageSelectSprite.tanim = &StageSelectAnim[animalIcon];
				StageSelectSprite.p = { x, yPos, 0.0f };
				DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
				x += 4;
				DrawString(std::to_string(animalParts[1]), x, yPos + 6.0f, 0.1875f);
				DrawString(std::to_string(animalParts[0]), x, yPos + 18.0f, 0.1875f);
				xCount++;
			}
		}
		// End Row 5
	}
	else
	{
		StageSelectSprite.sx = 0.25f;
		StageSelectSprite.sy = 0.25f;

		std::vector<int> chaoKeys = locMan->GetChaoKeyLocationsForLevel(currentTileStageIndex);
		std::vector<int> pipes = locMan->GetPipeLocationsForLevel(currentTileStageIndex);
		std::vector<int> hiddens = locMan->GetHiddenLocationsForLevel(currentTileStageIndex);
		std::vector<int> beetles = locMan->GetGoldBeetleLocationsForLevel(currentTileStageIndex);
		std::vector<int> omochao = locMan->GetOmochaoLocationsForLevel(currentTileStageIndex);
		std::vector<int> lifeBoxes = locMan->GetLifeBoxLocationsForLevel(currentTileStageIndex);
		std::vector<int> itemBoxes = locMan->GetItemBoxLocationsForLevel(currentTileStageIndex);
		std::vector<int> bigs = locMan->GetBigLocationsForLevel(currentTileStageIndex);
		int animalsFound = locMan->GetCompletedAnimalLocationsForLevel(currentTileStageIndex);
		int animalsTotal = locMan->GetTotalAnimalLocationsForLevel(currentTileStageIndex);

		bool paginate = itemBoxes.size() > 0 && currentTileStageIndex != SSS_Route101 && currentTileStageIndex != SSS_Route280;
		if (paginate)
		{
			if (lastTile != currentTileStageIndex)
			{
				if (!paginateManual)
				{
					lastTile = currentTileStageIndex;
					currentPage = 0;
					paginateTimer = PAGE_SWAP_TIME;
				}
			}
			if (lastGameMode != GameMode)
			{
				lastGameMode = GameMode;
				paginateManual = false;
				currentPage = 0;
				paginateTimer = PAGE_SWAP_TIME;
			}
			if (ControllersRaw->press & 0b1000000000)
			{
				paginateManual = true;
				currentPage = (currentPage == 0) ? 1 : 0;
			}
			paginateTimer--;
			if (paginateTimer <= 0)
			{
				paginateTimer = PAGE_SWAP_TIME;
				if (!paginateManual)
				{
					currentPage = (currentPage == 0) ? 1 : 0;
				}
			}
		}

		if (!paginate || currentPage == 0)
		{
			if ((*StageSelectDataMap_ptr).at(currentTileStageIndex).UpgradeAddress > 0x00)
			{
				int icon = *(char*)(*StageSelectDataMap_ptr).at(currentTileStageIndex).UpgradeAddress > 0x00 ? SSI_Upgrade : SSI_UpgradeDisabled;
				StageSelectSprite.tanim = &StageSelectAnim[icon];
				StageSelectSprite.p = { maxXPos - ((xCount + 1) * 32.0f), yPos, 0.0f };
				DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
				xCount++;
			}
			if (beetles.size() > 0)
			{
				for (int i = beetles.size() - 1; i >= 0; i--)
				{
					int beetleIcon = *(char*)beetles[i] == 0x01 ? SSI_GoldBeetle : SSI_GoldBeetleDisabled;
					StageSelectSprite.tanim = &StageSelectAnim[beetleIcon];
					StageSelectSprite.p = { maxXPos - ((xCount + 1) * 32.0f), yPos, 0.0f };
					DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
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
					DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
					x += 4;
					DrawString(std::to_string(itemCount), x, yPos + 24.0f, 0.25f);
					xCount++;
					itemCount--;
				}
			}
			if (animalsTotal > 0)
			{
				int animalsIcon = animalsFound == animalsTotal ? SSI_Animals : SSI_AnimalsDisabled;
				float x = maxXPos - ((xCount + 1) * 32.0f);
				StageSelectSprite.tanim = &StageSelectAnim[animalsIcon];
				StageSelectSprite.p = { x, yPos, 0.0f };
				DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
				x += 4;
				DrawString(std::to_string(animalsFound), x, yPos + 8.0f, 0.25f);
				DrawString(std::to_string(animalsTotal), x, yPos + 24.0f, 0.25f);
				xCount++;
			}
			if (bigs.size() > 0)
			{
				itemCount = bigs.size();
				for (int i = bigs.size() - 1; i >= 0; i--)
				{
					int bigIcon = bigs[i] == 0x01 ? SSI_Big : SSI_BigDisabled;
					float x = maxXPos - ((xCount + 1) * 32.0f);
					StageSelectSprite.tanim = &StageSelectAnim[bigIcon];
					StageSelectSprite.p = { x, yPos, 0.0f };
					DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
					x += 4;
					if (bigs.size() > 1)
					{
						DrawString(std::to_string(itemCount), x, yPos + 24.0f, 0.25f);
					}
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
					float x = maxXPos - ((xCount + 1 + hiddens.size()) * 24.0f);
					StageSelectSprite.tanim = &StageSelectAnim[pipeIcon];
					StageSelectSprite.p = { x, yPos, 0.0f };
					DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
					x += 2;
					DrawString(std::to_string(itemCount), x, yPos + 18.0f, 0.1875f);
					xCount++;
					itemCount--;
				}
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
					DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
					x += 2;
					DrawString(std::to_string(itemCount), x, yPos + 18.0f, 0.1875f);
					xCount++;
					itemCount--;
				}
			}
			if (pipes.size() > 0 || hiddens.size() > 0)
			{
				yPos += 24.0f;
				xCount = 0;
			}
			if (omochao.size() > 0)
			{
				itemCount = omochao.size();
				int rows = 0;
				for (int i = itemCount; i > 0; i -= omochaoIconsPerRow)
				{
					rows++;
				}
				int numInRow = itemCount % omochaoIconsPerRow;
				numInRow = numInRow == 0 ? omochaoIconsPerRow : numInRow;
				yPos += (rows - 1) * 24.0f;
				while (itemCount > 0)
				{
					int omochaoIcon = *(char*)omochao[itemCount - 1] == 0x01 ? SSI_Omochao : SSI_OmochaoDisabled;
					float x = maxXPos - ((xCount + 1) * 24.0f);
					StageSelectSprite.tanim = &StageSelectAnim[omochaoIcon];
					StageSelectSprite.p = { x, yPos, 0.0f };
					DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
					x += 2;
					DrawString(std::to_string(itemCount), x, yPos + 18.0f, 0.1875f);
					xCount++;
					itemCount--;
					numInRow--;
					if (numInRow <= 0)
					{
						xCount = 0;
						yPos -= 24.0f;
						numInRow = omochaoIconsPerRow;
					}
				}
				for (int omoRows = 0; omoRows < ((float)omochao.size() / (float)omochaoIconsPerRow) + 1; omoRows++)
				{
					yPos += 24.0f;
					xCount = 0;
				}
			}
		}
		if (!paginate || currentPage == 1)
		{
			StageSelectSprite.sx = 0.1875f;
			StageSelectSprite.sy = 0.1875f;
			if (lifeBoxes.size() > 0)
			{
				itemCount = lifeBoxes.size();
				int rows = 0;
				for (int i = itemCount; i > 0; i -= itemBoxIconsPerRow)
				{
					rows++;
				}
				int numInRow = itemCount % itemBoxIconsPerRow;
				numInRow = numInRow == 0 ? itemBoxIconsPerRow : numInRow;
				yPos += (rows - 1) * 24.0f;
				while (itemCount > 0)
				{
					int lifeBoxIcon = lifeBoxes[itemCount - 1] == 0x01 ? SSI_LifeBox : SSI_LifeBoxDisabled;
					float x = maxXPos - ((xCount + 1) * 24.0f);
					StageSelectSprite.tanim = &StageSelectAnim[lifeBoxIcon];
					StageSelectSprite.p = { x, yPos, 0.0f };
					DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
					x += 2;
					DrawString(std::to_string(itemCount), x, yPos + 18.0f, 0.1875f);
					xCount++;
					itemCount--;
					numInRow--;
					if (numInRow <= 0)
					{
						xCount = 0;
						yPos -= 24.0f;
						numInRow = itemBoxIconsPerRow;
					}
				}
				for (int lifeBoxRows = 0; lifeBoxRows < ceil((float)lifeBoxes.size() / (float)itemBoxIconsPerRow) + 1; lifeBoxRows++)
				{
					yPos += 24.0f;
					xCount = 0;
				}
			}
		}
		if ((paginate && currentPage == 1) ||
			(currentTileStageIndex == SSS_Route101 || currentTileStageIndex == SSS_Route280))
		{
			if (itemBoxes.size() > 0)
			{
				itemCount = itemBoxes.size();
				int rows = 0;
				for (int i = itemCount; i > 0; i -= itemBoxIconsPerRow)
				{
					rows++;
				}
				int numInRow = itemCount % itemBoxIconsPerRow;
				numInRow = numInRow == 0 ? itemBoxIconsPerRow : numInRow;
				yPos += (rows - 1) * 24.0f;
				while (itemCount > 0)
				{
					int itemBoxIcon = itemBoxes[itemCount - 1] == 0x01 ? SSI_ItemBox : SSI_ItemBoxDisabled;
					float x = maxXPos - ((xCount + 1) * 24.0f);
					StageSelectSprite.tanim = &StageSelectAnim[itemBoxIcon];
					StageSelectSprite.p = { x, yPos, 0.0f };
					DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
					x += 2;
					DrawString(std::to_string(itemCount), x, yPos + 18.0f, 0.1875f);
					xCount++;
					itemCount--;
					numInRow--;
					if (numInRow <= 0)
					{
						xCount = 0;
						yPos -= 24.0f;
						numInRow = itemBoxIconsPerRow;
					}
				}
				for (int itemBoxRows = 0; itemBoxRows < ceil((float)itemBoxes.size() / (float)itemBoxIconsPerRow) + 1; itemBoxRows++)
				{
					yPos += 24.0f;
					xCount = 0;
				}
			}
		}
		if (paginate)
		{
			StageSelectSprite.sx = 0.5f;
			StageSelectSprite.sy = 0.5f;

			int buttonIcon = (paginateTimer / 60) == 1 ? SSI_UISwitch_0 : SSI_UISwitch_1;
			StageSelectSprite.tanim = &StageSelectAnim[buttonIcon];
			StageSelectSprite.p = { maxXPos - ((xCount + 1) * 64.0f), yPos, 0.0f };
			DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
		}
	}
}

void UpdateChaosEmeraldIcons()
{
	int goal = StageSelectManager::GetInstance().GetGoal();
	if (goal == 1 || goal == 2 || goal == 6)
	{
		ItemManager* itemMan = &ItemManager::getInstance();
		std::vector<int> chaosEmeralds = itemMan->GetChaosEmeraldAddresses();
		StageSelectSprite.sx = 0.25f;
		StageSelectSprite.sy = 0.25f;
		for (int i = 0; i < chaosEmeralds.size(); i++)
		{
			int emeraldIcon = *(char*)chaosEmeralds[i] == 0x01 ? SSI_Emerald_White + i : SSI_Emerald_None;
			float x = 208.0f + (i * 32.0f);
			float y = 380.0f;
			if (GameState == GameStates::GameStates_Pause && GameMode == GameMode::GameMode_Level)
			{
				x = (i * 32.0f);
				y = 448.0f;
			}
			StageSelectSprite.tanim = &StageSelectAnim[emeraldIcon];
			StageSelectSprite.p = { x, y, 0.0f };
			DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
		}
	}
	else if (goal == 8)
	{
		ItemManager* itemMan = &ItemManager::getInstance();
		std::vector<int> minigames = itemMan->GetMinigameAddresses();
		StageSelectSprite.sx = 0.25f;
		StageSelectSprite.sy = 0.25f;
		for (int i = 0; i < minigames.size(); i++)
		{
			char minigamesWon = *(char*)(minigames[i] + 0x30);

			int minigameIcon = minigamesWon >= itemMan->RequiredMinigames ? SSI_Pong + (i * 2) : SSI_Pong + (i * 2) + 1;
			float x = (320.0f - (minigames.size() - 1) * 16.0f) + (i * 32.0f);
			float y = 380.0f;
			if (GameState == GameStates::GameStates_Pause && GameMode == GameMode::GameMode_Level)
			{
				x = (i * 32.0f);
				y = 448.0f;
			}
			StageSelectSprite.tanim = &StageSelectAnim[minigameIcon];
			StageSelectSprite.p = { x, y, 0.0f };
			DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);

			x += 4;
			DrawString(std::to_string(minigamesWon), x, y + 8.0f, 0.25f);
			DrawString(std::to_string(itemMan->RequiredMinigames), x, y + 24.0f, 0.25f);
		}
	}
}

void UpdateUpgradeIcons(bool inLevel)
{
	char overrideCharacter = -1;
	if (inLevel) 
	{
		switch (CurrentLevel)
		{
		case LevelIDs_CannonsCoreE:
			overrideCharacter = Characters_MechEggman;
			break;
		case LevelIDs_CannonsCoreK:
			overrideCharacter = Characters_Knuckles;
			break;
		case LevelIDs_CannonsCoreR:
			overrideCharacter = Characters_Rouge;
			break;
		case LevelIDs_CannonsCoreT:
			overrideCharacter = Characters_MechTails;
			break;
		case LevelIDs_CannonsCoreS:
			overrideCharacter = Characters_Sonic;
			break;

		}
	}
	if (SS_SelectedTile < TileIDtoStageIndex.size())
	{
		int currentTileStageIndex = TileIDtoStageIndex[SS_SelectedTile];
		if (currentTileStageIndex < (*StageSelectDataMap_ptr).size())
		{
			char character = *(char*)(*StageSelectDataMap_ptr).at(currentTileStageIndex).TileCharacterAddress;
			character = overrideCharacter < 0 ? character : overrideCharacter;
			CharacterItemRange range = GetItemRangeForCharacter(character);
			int iconPos = 0;
			Sprite.sx = 0.21875f;
			Sprite.sy = 0.21875f;
			Sprite_2.sx = 0.21875f;
			Sprite_2.sy = 0.21875f;
			for (int i = range.End; i >= range.Start; i--)
			{
				float yPos = inLevel ? 452.0f : 414.0f;
				if (*(char*)(*ItemData_ptr).at(i).Address > 0x00)
				{
					Sprite.tanim = &UpgradeIconsAnim[(*ItemData_ptr).at(i).IconIndex];
					Sprite.p = { maxXPos - ((iconPos + 1) * 28.0f), yPos, 0.0f };
					DrawSprite2D(&Sprite, 1, 1, NJD_SPRITE_ALPHA);
				}
				else
				{
					Sprite_2.tanim = &UpgradeIconsAnim_Inactive[(*ItemData_ptr).at(i).IconIndex];
					Sprite_2.p = { maxXPos - ((iconPos + 1) * 28.0f), yPos, 0.0f };
					DrawSprite2D(&Sprite_2, 1, 1, NJD_SPRITE_ALPHA);
				}			
				iconPos++;
			}
		}
	}
}

void UpdateEmblemRequirements()
{
	int emblemsForCannonsCore = StageSelectManager::GetInstance().GetCannonsCoreEmblemCount();
	std::vector<int> gateRequirements = StageSelectManager::GetInstance().GetGateRequirements();
	StageSelectSprite.sx = 0.4f;
	StageSelectSprite.sy = 0.4f;
	if (gateRequirements.size() > 1)
	{
		if (RealEmblemCount < gateRequirements[gateRequirements.size() - 1])
		{
			std::string gateRequirementMessage = "";
			gateRequirementMessage.append(std::to_string(RealEmblemCount));
			gateRequirementMessage.append("/");
			for (int g = 0; g < gateRequirements.size(); g++)
			{
				if (gateRequirements[g] > RealEmblemCount || g == gateRequirements.size() - 1)
				{
					gateRequirementMessage.append(std::to_string(gateRequirements[g]));
					int gateIcon = SSI_Gate1 + g - 1;
					float gateX = minXPos;
					StageSelectSprite.tanim = &StageSelectAnim[gateIcon];
					StageSelectSprite.p = { gateX, 32.0f, 0.0f };
					DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
					DrawString(gateRequirementMessage, gateX + 53.0f, 54.4f, 0.75f);
					break;
				}
			}
		}
	}

	float coreX = minXPos;
	StageSelectSprite.tanim = &StageSelectAnim[SSI_CannonsCore];
	StageSelectSprite.p = { coreX, -6.4f, 0.0f };
	DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);

	std::string cannonsCoreMessage = "";
	cannonsCoreMessage.append(std::to_string(RealEmblemCount));
	cannonsCoreMessage.append("/");
	cannonsCoreMessage.append(std::to_string(emblemsForCannonsCore));
	DrawString(cannonsCoreMessage, coreX + 53.0f, 16.0f, 0.75f);
	if (RealEmblemCount >= emblemsForCannonsCore && SS_CameraPos < 3)
	{
		currentCCUnlockFrame = currentCCUnlockFrame == maxCCUnlockFrames - 1 ? 0 : currentCCUnlockFrame + 1;
		float progress = currentCCUnlockFrame / (float)maxCCUnlockFrames;
		progress = abs(progress * 2.0f - 1.0f);
		progress = (cos(3.1415f * progress) - 1.0f) * -0.5f;
		StageSelectSprite.sx = 0.25f;
		StageSelectSprite.sy = 0.25f;
		StageSelectSprite.tanim = &StageSelectAnim[SSI_CCUnlocked];
		StageSelectSprite.p = { maxXPos - 16.0f - (maxCCUnlockOffset * progress), 380.0f, 0.0f };
		DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
	}
}

void UpdateChaoCoinRequirements()
{
	int currentTileStageIndex = TileIDtoStageIndex[SS_SelectedTile];
	if (currentTileStageIndex != SSS_ChaoGarden && CurrentLevel != LevelIDs::LevelIDs_ChaoWorld)
	{
		return;
	}

	if (CurrentChaoArea == 0x04 ||
		CurrentChaoArea == 0x05 ||
		CurrentChaoArea == 0x08 ||
		CurrentChaoArea == 0x09 ||
		CurrentChaoArea == 0x0A ||
		CurrentChaoArea == 0x0C)
	{
		return;
	}

	float tokenY = 48.0f;

	if (GameMode != GameMode::GameMode_Level)
	{
		tokenY = 92.8f;
	}

	int maxRequiredTokens = LocationManager::getInstance().GetMaxMarketTokens();

	if (maxRequiredTokens == 0)
	{
		return;
	}

	StageSelectSprite.sx = 0.25f;
	StageSelectSprite.sy = 0.25f;

	float tokenX = minXPos;
	StageSelectSprite.tanim = &StageSelectAnim[SSI_ChaoCoin];
	StageSelectSprite.p = { tokenX + 4, tokenY - 12.0f, 0.0f };
	DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);

	StageSelectSprite.sx = 0.4f;
	StageSelectSprite.sy = 0.4f;

	std::string marketTokensMessage = "";
	marketTokensMessage.append(std::to_string(BlackMarketTokenCount));
	marketTokensMessage.append("/");
	marketTokensMessage.append(std::to_string(maxRequiredTokens));
	DrawString(marketTokensMessage, tokenX + 40.0f, tokenY, 0.75f);
}

void UpdateTimescale()
{
	int currentTileStageIndex = TileIDtoStageIndex[SS_SelectedTile];
	if (currentTileStageIndex != SSS_ChaoGarden && CurrentLevel != LevelIDs::LevelIDs_ChaoWorld)
	{
		return;
	}

	float timescaleY = 16.0f;

	int chaoTimescale = ChaoGardenManager::GetInstance().GetTimescale();

	if (chaoTimescale == 0)
	{
		return;
	}

	StageSelectSprite.sx = 0.3f;
	StageSelectSprite.sy = 0.3f;

	float timescaleX = minXPos + 20.0f;
	StageSelectSprite.tanim = &StageSelectAnim[SSI_DPad_Up_Down];
	StageSelectSprite.p = { timescaleX + 4, timescaleY + 4, 0.0f };
	DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);

	timescaleX += 20.0f;
	StageSelectSprite.sx = 0.25f;
	StageSelectSprite.sy = 0.25f;

	StageSelectSprite.tanim = &StageSelectAnim[SSI_Clock];
	StageSelectSprite.p = { timescaleX + 4, timescaleY - 12.0f, 0.0f };
	DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);

	StageSelectSprite.sx = 0.4f;
	StageSelectSprite.sy = 0.4f;

	std::string timescaleMessage = "";
	timescaleMessage.append(std::to_string(chaoTimescale));
	timescaleMessage.append("X");
	DrawString(timescaleMessage, timescaleX + 40.0f, timescaleY, 0.75f);
}

void UpdateMissionInLevel() 
{
	std::vector<int> activeMissions = StageSelectManager::GetInstance().GetCurrentStageMissions();
	std::vector<int> activeRanks = StageSelectManager::GetInstance().GetCurrentStageRanks();

	int iconWidth = 48;
	float x_pos = minXPos + (iconWidth / 2);

	for (int i = 0; i < activeMissions.size(); i++)
	{
		int animIndex = (Num_Anim_Length - 12) + (activeMissions[i] - 1);
		if (activeMissions[i] - 1 != ActiveMission)
		{
			animIndex += 5;
		}
		NumSprite.tanim = &NumAnim[animIndex];
		NumSprite.p = { x_pos, 12.0f, 0.0f };
		NumSprite.sx = 1.0f;
		NumSprite.sy = 1.0f;
		DrawSprite2D(&NumSprite, 1, 1, NJD_SPRITE_ALPHA);

		if (activeRanks[i] > 0)
		{
			animIndex = (Num_Anim_Length - 2) + (activeRanks[i] - 1);
			NumSprite.tanim = &NumAnim[animIndex];
			NumSprite.p = { x_pos, 48.0f, 0.0f };
			NumSprite.sx = 1.0f;
			NumSprite.sy = 1.0f;
			DrawSprite2D(&NumSprite, 1, 1, NJD_SPRITE_ALPHA);
		}

		x_pos += iconWidth;
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
		UpdateLevelCheckIcons();

		int currentTileStageIndex = TileIDtoStageIndex[SS_SelectedTile];
		if (currentTileStageIndex != SSS_ChaoGarden)
		{
			UpdateUpgradeIcons(false);
		}

		UpdateChaosEmeraldIcons();
		UpdateEmblemRequirements();
		UpdateChaoCoinRequirements();
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

void DeleteUpgradeIcon_IL(ObjectMaster* obj)
{
	ReleaseTextureList(&UpgradeIconsTex);
	ReleaseTextureList(&UpgradeIconsTex_Inactive);
	ReleaseTextureList(&StageSelectTex);
	ReleaseTextureList(&NumTex);
	StageSelectIcons::GetInstance().InLevelIconObj = nullptr;
}

void DrawUpgradeIcon_IL(ObjectMaster* obj)
{
	if (CurrentMenu == Menus::Menus_BossAttack || CurrentMenu == Menus::Menus_Kart)
	{
		return;
	}

	if (GameState == GameStates::GameStates_Pause && GameMode == GameMode::GameMode_Level)
	{
		if (CurrentLevel != LevelIDs_ChaoWorld)
		{
			UpdateUpgradeIcons(true);
			UpdateMissionInLevel();
		}
		UpdateLevelCheckIcons();
		UpdateChaosEmeraldIcons();
	}

	if (GameMode == GameMode::GameMode_Level)
	{
		UpdateChaoCoinRequirements();
		UpdateTimescale();

		StageSelectIcons::GetInstance().MinigameReplaySystem();
	}
}

void DrawUpgradeIconMain_IL(ObjectMaster* obj)
{
	if (GameState != GameStates_LoadFinished && GameState != GameStates_LoadLevel)
		return;

	if (obj->Data1.Entity->Action == 0) {
		obj->DeleteSub = DeleteUpgradeIcon_IL;
		obj->DisplaySub_Delayed3 = DrawUpgradeIcon_IL;
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

	/*for (int i = 0; i < Stage_Anim_Length; i++)
	{
		if (i == SSI_CCUnlocked + 1)
		{
			StageSelectAnim[i] = { 128, 256, 64, 128, 0, 0, 0x100, 0x100, (Sint16)(i - 1), NJD_SPRITE_ALPHA };
		}
		else
		{
			StageSelectAnim[i] = { 0x80, 0x80, 0, 0, 0, 0, 0x100, 0x100, (Sint16)(i - 1), NJD_SPRITE_ALPHA };
		}
	}*/

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
	if (!DrawIconObj && CurrentMenu == Menus::Menus_StageSelect && GameMode == GameMode::GameMode_Advertise)
	{
		LoadTextures(&TexPacks[0]);
		DrawIconObj = LoadObject(0, "UpgradeIcon", DrawUpgradeIconMain, LoadObj_Data1 | LoadObj_Data2);
		DrawIconObj->DeleteSub = DeleteUpgradeIcon;
		DrawIconObj->MainSub = DrawUpgradeIconMain;
		DrawIconObj->DisplaySub_Delayed3 = DrawUpgradeIcon;
	}

	if (!InLevelIconObj && GameState == GameStates_Ingame) //GameState == GameStates_LoadItems)
	{
		LoadTextures(&TexPacks[0]);
		InLevelIconObj = LoadObject(0, "UpgradeIcon_IL", DrawUpgradeIconMain, LoadObj_Data1 | LoadObj_Data2);
		InLevelIconObj->DeleteSub = DeleteUpgradeIcon_IL;
		InLevelIconObj->MainSub = DrawUpgradeIconMain_IL;
		InLevelIconObj->DisplaySub_Delayed3 = DrawUpgradeIcon_IL;
		InLevelIconObj->Data1.Entity->Action = 1;
	}
}

bool StageSelectIcons::IsCurrentTileBoss()
{
	int currentTileStageIndex = TileIDtoStageIndex[SS_SelectedTile];
	char levelID = *(char*)(*StageSelectDataMap_ptr).at(currentTileStageIndex).TileIDAddress;
	bool isBossStage = (std::count(StageSelectIcons::GetInstance().bossIDs.begin(), StageSelectIcons::GetInstance().bossIDs.end(), levelID) != 0);

	return isBossStage;
}

void StageSelectIcons::MinigameReplaySystem()
{
	int goal = StageSelectManager::GetInstance().GetGoal();

	if (goal != 8)
	{
		// Only use this on Minigame Madness
		return;
	}

	MinigameManager* mingameManager = &MinigameManager::GetInstance();

	if (mingameManager->state != MinigameState::MGS_None)
	{
		// Don't show/handle system during Minigame
		return;
	}

	if (GameState != GameStates_Ingame)
	{
		this->minigameReplayIndex = 0;

		return;
	}

	if (CurrentLevel != LevelIDs::LevelIDs_ChaoWorld)
	{
		return;
	}

	if (CurrentChaoArea != 0x07)
	{
		// Only display in Lobby

		return;
	}

	ItemManager* itemMan = &ItemManager::getInstance();
	std::vector<int> minigames = itemMan->GetMinigameAddresses();
	StageSelectSprite.sx = 0.5f;
	StageSelectSprite.sy = 0.5f;
	char minigamesReceived = *(char*)(minigames[this->minigameReplayIndex]);
	char minigamesWon = *(char*)(minigames[this->minigameReplayIndex] + 0x30);
	bool isActivatable = minigamesReceived >= itemMan->RequiredMinigames;
	bool isComplete = minigamesWon >= itemMan->RequiredMinigames;

	int minigameIcon = isActivatable ? SSI_Pong + (this->minigameReplayIndex * 2) : SSI_Pong + (this->minigameReplayIndex * 2) + 1;
	float x = maxXPos - 64.0f;
	float y = 32.0f;
	StageSelectSprite.tanim = &StageSelectAnim[minigameIcon];
	StageSelectSprite.p = { x, y, 0.0f };
	DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);

	if (isComplete)
	{
		StageSelectSprite.tanim = &StageSelectAnim[SSI_Check_Mark];
		StageSelectSprite.p = { x, y, 0.0f };
		DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
	}

	x = maxXPos - 96.0f;
	y = 64.0f;
	StageSelectSprite.tanim = &StageSelectAnim[SSI_DPad_Left_Right];
	StageSelectSprite.p = { x, y, 0.0f };
	DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);

	if (isActivatable)
	{
		x = maxXPos - 60.0f;
		y = 16.0f;
		StageSelectSprite.tanim = &StageSelectAnim[SSI_Y_To_Play];
		StageSelectSprite.p = { x, y, 0.0f };
		DrawSprite2D(&StageSelectSprite, 1, 1, NJD_SPRITE_ALPHA);
	}

	std::string minigameMessage = "";
	minigameMessage.append(std::to_string(minigamesReceived));
	minigameMessage.append("/");
	minigameMessage.append(std::to_string(minigamesWon));
	minigameMessage.append("/");
	minigameMessage.append(std::to_string(itemMan->RequiredMinigames));
	float stringWidth = GetStringWidth(minigameMessage, 0.75f);
	x = maxXPos - stringWidth - 10.0f;
	DrawString(minigameMessage, x, 112.0f, 0.75f);

	Uint32 PressedButtons = ControllersRaw->press;
	if ((PressedButtons & 0b1000000) != 0) // Left
	{
		this->minigameReplayIndex--;
	}
	else if ((PressedButtons & 0b10000000) != 0) // Right
	{
		this->minigameReplayIndex++;
	}
	else if ((PressedButtons & 0b1000000000) != 0) // Y
	{
		if (isActivatable)
		{
			ItemValue minigameToActivate = (ItemValue)(ItemValue::IV_PongTrap + this->minigameReplayIndex);
			mingameManager->StartMinigame(minigameToActivate);
		}
	}

	if (this->minigameReplayIndex < 0)
	{
		this->minigameReplayIndex = (minigames.size() - 1);
	}
	else if (this->minigameReplayIndex > (minigames.size() - 1))
	{
		this->minigameReplayIndex = 0;
	}
}
