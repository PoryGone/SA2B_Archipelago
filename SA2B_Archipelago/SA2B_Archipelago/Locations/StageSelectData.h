#include "../pch.h"
#include "../Items/ItemData.h"
#include <map>
#include <vector>
#pragma once

enum StageSelectStage
{
    SSS_CityEscape = 0x00,
    SSS_WildCanyon,
    SSS_PrisonLane,
    SSS_MetalHarbor,
    SSS_GreenForest,
    SSS_PumpkinHill,
    SSS_MissionStreet,
    SSS_AquaticMine,
    SSS_Route101,
    SSS_HiddenBase,
    SSS_PyramidCave,
    SSS_DeathChamber,
    SSS_EternalEngine,
    SSS_MeteorHerd,
    SSS_CrazyGadget,
    SSS_FinalRush,
    SSS_IronGate,
    SSS_DryLagoon,
    SSS_SandOcean,
    SSS_RadicalHighway,
    SSS_EggQuarters,
    SSS_LostColony,
    SSS_WeaponsBed,
    SSS_SecurityHall,
    SSS_WhiteJungle,
    SSS_Route280,
    SSS_SkyRail,
    SSS_MadSpace,
    SSS_CosmicWall,
    SSS_FinalChase,
    SSS_CannonCore,
    SSS_GreenHill,
    SSS_ChaoGarden,
    SSS_Biolizard,

    SSS_COUNT
};

extern std::array<int, 33> TileIDtoStageIndex;

struct StageSelectStageData
{
    StageSelectStageData() : UnlockMemAddress(0x00), TileIDAddress(0x00), TileCharacterAddress(0x00), TileColumnAddress(0x00), TileRowAddress(0x00), UpgradeAddress(0x00), DefaultCharacter() {}
    StageSelectStageData(int unlockMemAddress, int tileMemAddress, int upgradeAddress, Characters defaultCharacter) : UnlockMemAddress(unlockMemAddress), 
                                                                     TileIDAddress(tileMemAddress), 
                                                                     TileCharacterAddress(tileMemAddress + 4), 
                                                                     TileColumnAddress(tileMemAddress + 8), 
                                                                     TileRowAddress(tileMemAddress + 12),
                                                                     UpgradeAddress(upgradeAddress),
                                                                     DefaultCharacter(defaultCharacter) {}

    int UnlockMemAddress = 0x00;
    int TileIDAddress = 0x00;
    int TileCharacterAddress;
    int TileColumnAddress;
    int TileRowAddress;
    int UpgradeAddress;
    Characters DefaultCharacter;
};

enum StageSelectBoss
{
    SSB_Speed_1 = 0x00,
    SSB_Speed_2,
    SSB_Mech_1,
    SSB_Mech_2,
    SSB_Hunt_1,
    SSB_BigFoot,
    SSB_HotShot,
    SSB_FlyingDog,
    SSB_EggGolem_Sonic,
    SSB_EggGolem_Eggman,
    SSB_KingBoomBoo,

    SSB_COUNT
};

struct BossStageData
{
    BossStageData() : Character(Characters::Characters_Sonic), LevelID(0x00), UnlockMemAddress(0x00) {}
    BossStageData(Characters character, int levelID, int unlockMemAddress) : Character(character), LevelID(levelID), UnlockMemAddress(unlockMemAddress) {}

    Characters Character;
    int LevelID;
    int UnlockMemAddress = 0x00;

    bool IsValid()
    {
        return LevelID != 0x00;
    }
};

struct StageSelectBossData
{
    StageSelectBossData() : Stage_0(), Stage_1() {}
    StageSelectBossData(BossStageData stage_0, BossStageData stage_1) : Stage_0(stage_0), Stage_1(stage_1) {}

    BossStageData Stage_0;
    BossStageData Stage_1;

    BossStageData GetBossStage(int nextLevelID)
    {
        if (Stage_1.IsValid() && nextLevelID % 2 == 1)
        {
            return Stage_1;
        }
        return Stage_0;
    }
};

struct CharacterItemRange
{
    CharacterItemRange() : Character(Characters_Sonic), Start(IV_SonicGloves), End(IV_SonicMysticMelody) {}
    CharacterItemRange(Characters character, ItemValue start, ItemValue end) : Character(character), Start(start), End(end) {}

    Characters Character;
    ItemValue Start;
    ItemValue End;
};

void InitializeStageSelectData(std::map<int, StageSelectStageData>& outStageSelectData);

void InitializeStageSelectBossData(std::map<int, StageSelectBossData>& outStageBossData);

void InitializeCharacterItemRanges(std::vector<CharacterItemRange>& outCharacterItemRanges);

LevelIDs StageSelectStageToLevelID(StageSelectStage stage);
