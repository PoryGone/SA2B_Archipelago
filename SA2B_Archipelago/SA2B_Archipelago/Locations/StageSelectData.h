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

struct StageSelectStageData
{
    StageSelectStageData() : UnlockMemAddress(0x00), TileIDAddress(0x00), TileCharacterAddress(0x00), TileColumnAddress(0x00), TileRowAddress(0x00), UpgradeAddress(0x00) {}
    StageSelectStageData(int unlockMemAddress, int tileMemAddress, int upgradeAddress) : UnlockMemAddress(unlockMemAddress), 
                                                                     TileIDAddress(tileMemAddress), 
                                                                     TileCharacterAddress(tileMemAddress + 4), 
                                                                     TileColumnAddress(tileMemAddress + 8), 
                                                                     TileRowAddress(tileMemAddress + 12),
                                                                     UpgradeAddress(upgradeAddress) {}

    int UnlockMemAddress = 0x00;
    int TileIDAddress = 0x00;
    int TileCharacterAddress;
    int TileColumnAddress;
    int TileRowAddress;
    int UpgradeAddress;
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

void InitializeCharacterItemRanges(std::vector<CharacterItemRange>& outCharacterItemRanges);
