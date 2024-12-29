#include "../pch.h"
#pragma once
#include <map>
#include <vector>
#include <array>
#include "../Items/ItemData.h"

class StageSelectIcons
{
public:
	static StageSelectIcons& GetInstance()
	{
		static StageSelectIcons instance;
		return instance;
	}
	void OnFrame();
	void OnInit(std::map<int, StageSelectStageData>* stageSelectDataMap);

	bool IsCurrentTileBoss();
	void MinigameReplaySystem();

	std::map<int, ItemData> ItemData;
	std::vector<CharacterItemRange> CharacterItemRanges;
	ObjectMaster* DrawIconObj;
	ObjectMaster* InLevelIconObj;

	std::vector<int> bossIDs{ 0x13, 0x14, 0x1D, 0x21, 0x2A, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x43 };

	int minigameReplayIndex = 0;
};

struct NumberDisplayData 
{
	NumberDisplayData() : index(0), width(0.0f), xOffset(0.0f), yOffset(0.0f) {}
	NumberDisplayData(int _index, float _width, float _xOffset, float _yOffset) : index(_index), width(_width), xOffset(_xOffset), yOffset(_yOffset) {}

	int index;
	float width;
	float xOffset;
	float yOffset;
};

enum StageSelectIcon {
	SSI_ChaoKey					= 0,
	SSI_ChaoKeyDisabled			= 1,
	SSI_Pipe					= 2,
	SSI_PipeDisabled			= 3,
	SSI_GoldBeetle				= 4,
	SSI_GoldBeetleDisabled		= 5,
	SSI_Hidden					= 6,
	SSI_HiddenDisabled			= 7,
	SSI_Upgrade					= 8,
	SSI_UpgradeDisabled			= 9,
	SSI_Gate1					= 10,
	SSI_Gate2					= 11,
	SSI_Gate3					= 12,
	SSI_Gate4					= 13,
	SSI_Gate5					= 14,
	SSI_Emerald_None			= 15,
	SSI_Emerald_White			= 16,
	SSI_Emerald_Red				= 17,
	SSI_Emerald_Cyan			= 18,
	SSI_Emerald_Purple			= 19,
	SSI_Emerald_Green			= 20,
	SSI_Emerald_Yellow			= 21,
	SSI_Emerald_Blue			= 22,
	SSI_CannonsCore				= 23,
	SSI_Omochao					= 24,
	SSI_OmochaoDisabled			= 25,
	SSI_CCUnlocked				= 26,
	SSI_Animals					= 27,
	SSI_AnimalsDisabled			= 28,

	SSI_Clock					= 29,
	SSI_ChaoCoin				= 30,
	SSI_BlackMarket				= 31,
	SSI_BlackMarketDisabled		= 32,

	SSI_Beginner				= 33,
	SSI_BeginnerDisabled		= 34,
	SSI_Challenge				= 35,
	SSI_ChallengeDisabled		= 36,
	SSI_Hero					= 37,
	SSI_HeroDisabled			= 38,
	SSI_Dark					= 39,
	SSI_DarkDisabled			= 40,
	SSI_Aquamarine				= 41,
	SSI_AquamarineDisabled		= 42,
	SSI_Topaz					= 43,
	SSI_TopazDisabled			= 44,
	SSI_Peridot					= 45,
	SSI_PeridotDisabled			= 46,
	SSI_Garnet					= 47,
	SSI_GarnetDisabled			= 48,
	SSI_Onyx					= 49,
	SSI_OnyxDisabled			= 50,
	SSI_Diamond					= 51,
	SSI_DiamondDisabled			= 52,
	SSI_Karate					= 53,
	SSI_KarateDisabled			= 54,

	SSI_Swim					= 55,
	SSI_SwimDisabled			= 56,
	SSI_Fly						= 57,
	SSI_FlyDisabled				= 58,
	SSI_Run						= 59,
	SSI_RunDisabled				= 60,
	SSI_Power					= 61,
	SSI_PowerDisabled			= 62,
	SSI_Stamina					= 63,
	SSI_StaminaDisabled			= 64,
	SSI_Luck					= 65,
	SSI_LuckDisabled			= 66,
	SSI_Intelligence			= 67,
	SSI_IntelligenceDisabled	= 68,
	SSI_Drawing					= 69,
	SSI_DrawingDisabled			= 70,
	SSI_Dance					= 71,
	SSI_DanceDisabled			= 72,
	SSI_Song					= 73,
	SSI_SongDisabled			= 74,
	SSI_Instrument				= 75,
	SSI_InstrumentDisabled		= 76,

	SSI_Bat						= 77,
	SSI_BatDisabled				= 78,
	SSI_Bear					= 79,
	SSI_BearDisabled			= 80,
	SSI_Boar					= 81,
	SSI_BoarDisabled			= 82,
	SSI_Cheetah					= 83,
	SSI_CheetahDisabled			= 84,
	SSI_Dragon					= 85,
	SSI_DragonDisabled			= 86,
	SSI_Gorilla					= 87,
	SSI_GorillaDisabled			= 88,
	SSI_HalfFish				= 89,
	SSI_HalfFishDisabled		= 90,
	SSI_Otter					= 91,
	SSI_OtterDisabled			= 92,
	SSI_Parrot					= 93,
	SSI_ParrotDisabled			= 94,
	SSI_Peacock					= 95,
	SSI_PeacockDisabled			= 96,
	SSI_Penguin					= 97,
	SSI_PenguinDisabled			= 98,
	SSI_Phoenix					= 99,
	SSI_PhoenixDisabled			= 100,
	SSI_Rabbit					= 101,
	SSI_RabbitDisabled			= 102,
	SSI_Raccoon					= 103,
	SSI_RaccoonDisabled			= 104,
	SSI_Seal					= 105,
	SSI_SealDisabled			= 106,
	SSI_Sheep					= 107,
	SSI_SheepDisabled			= 108,
	SSI_SkeletonDog				= 109,
	SSI_SkeletonDogDisabled		= 100,
	SSI_Skunk					= 111,
	SSI_SkunkDisabled			= 112,
	SSI_Tigern					= 113,
	SSI_TigernDisabled			= 114,
	SSI_Unicorn					= 115,
	SSI_UnicornDisabled			= 116,
	SSI_Vulture					= 117,
	SSI_VultureDisabled			= 118,
};
