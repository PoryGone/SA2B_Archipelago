#include "../pch.h"
#include <map>
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
    SSS_Biolizard,

    SSS_COUNT
};

struct StageSelectStageData
{
    StageSelectStageData() : UnlockMemAddress(0x00), TileIDAddress(0x00), TileCharacterAddress(0x00), TileColumnAddress(0x00), TileRowAddress(0x00) {}
    StageSelectStageData(int unlockMemAddress, int tileMemAddress) : UnlockMemAddress(unlockMemAddress), 
                                                                     TileIDAddress(tileMemAddress), 
                                                                     TileCharacterAddress(tileMemAddress + 4), 
                                                                     TileColumnAddress(tileMemAddress + 8), 
                                                                     TileRowAddress(tileMemAddress + 12) {}

    int UnlockMemAddress = 0x00;
    int TileIDAddress = 0x00;
    int TileCharacterAddress;
    int TileColumnAddress;
    int TileRowAddress;
};

void InitializeStageSelectData(std::map<int, StageSelectStageData>& outStageSelectData);