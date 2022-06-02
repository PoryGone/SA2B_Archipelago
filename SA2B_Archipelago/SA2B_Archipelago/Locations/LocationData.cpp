#include "../pch.h"
#pragma once
#include "LocationData.h"
#include <map>


void InitializeLevelClearChecks(std::map<int, LevelClearCheckData> &outLevelClearChecks)
{
    outLevelClearChecks.clear();

    outLevelClearChecks[LevelClearCheck::LCC_GreenForest_1] = LevelClearCheckData(0x01DEC884);
    outLevelClearChecks[LevelClearCheck::LCC_GreenForest_2] = LevelClearCheckData(0x01DEC885);
    outLevelClearChecks[LevelClearCheck::LCC_GreenForest_3] = LevelClearCheckData(0x01DEC886);
    outLevelClearChecks[LevelClearCheck::LCC_GreenForest_4] = LevelClearCheckData(0x01DEC887);
    outLevelClearChecks[LevelClearCheck::LCC_GreenForest_5] = LevelClearCheckData(0x01DEC888);
    outLevelClearChecks[LevelClearCheck::LCC_GreenForest_Upgrade] = LevelClearCheckData(0x01DEC639);

    outLevelClearChecks[LevelClearCheck::LCC_WhiteJungle_1] = LevelClearCheckData(0x01DEC948);
    outLevelClearChecks[LevelClearCheck::LCC_WhiteJungle_2] = LevelClearCheckData(0x01DEC949);
    outLevelClearChecks[LevelClearCheck::LCC_WhiteJungle_3] = LevelClearCheckData(0x01DEC94A);
    outLevelClearChecks[LevelClearCheck::LCC_WhiteJungle_4] = LevelClearCheckData(0x01DEC94B);
    outLevelClearChecks[LevelClearCheck::LCC_WhiteJungle_5] = LevelClearCheckData(0x01DEC94C);
    outLevelClearChecks[LevelClearCheck::LCC_WhiteJungle_Upgrade] = LevelClearCheckData(0x01DEC648);

    outLevelClearChecks[LevelClearCheck::LCC_PumpkinHill_1] = LevelClearCheckData(0x01DECA0C);
    outLevelClearChecks[LevelClearCheck::LCC_PumpkinHill_2] = LevelClearCheckData(0x01DECA0D);
    outLevelClearChecks[LevelClearCheck::LCC_PumpkinHill_3] = LevelClearCheckData(0x01DECA0E);
    outLevelClearChecks[LevelClearCheck::LCC_PumpkinHill_4] = LevelClearCheckData(0x01DECA0F);
    outLevelClearChecks[LevelClearCheck::LCC_PumpkinHill_5] = LevelClearCheckData(0x01DECA10);
    outLevelClearChecks[LevelClearCheck::LCC_PumpkinHill_Upgrade] = LevelClearCheckData(0x01DEC642);

    outLevelClearChecks[LevelClearCheck::LCC_SkyRail_1] = LevelClearCheckData(0x01DECAD0);
    outLevelClearChecks[LevelClearCheck::LCC_SkyRail_2] = LevelClearCheckData(0x01DECAD1);
    outLevelClearChecks[LevelClearCheck::LCC_SkyRail_3] = LevelClearCheckData(0x01DECAD2);
    outLevelClearChecks[LevelClearCheck::LCC_SkyRail_4] = LevelClearCheckData(0x01DECAD3);
    outLevelClearChecks[LevelClearCheck::LCC_SkyRail_5] = LevelClearCheckData(0x01DECAD4);
    outLevelClearChecks[LevelClearCheck::LCC_SkyRail_Upgrade] = LevelClearCheckData(0x01DEC649);

    outLevelClearChecks[LevelClearCheck::LCC_AquaticMine_1] = LevelClearCheckData(0x01DECB94);
    outLevelClearChecks[LevelClearCheck::LCC_AquaticMine_2] = LevelClearCheckData(0x01DECB95);
    outLevelClearChecks[LevelClearCheck::LCC_AquaticMine_3] = LevelClearCheckData(0x01DECB96);
    outLevelClearChecks[LevelClearCheck::LCC_AquaticMine_4] = LevelClearCheckData(0x01DECB97);
    outLevelClearChecks[LevelClearCheck::LCC_AquaticMine_5] = LevelClearCheckData(0x01DECB98);
    outLevelClearChecks[LevelClearCheck::LCC_AquaticMine_Upgrade] = LevelClearCheckData(0x01DEC645);

    outLevelClearChecks[LevelClearCheck::LCC_SecurityHall_1] = LevelClearCheckData(0x01DECC58);
    outLevelClearChecks[LevelClearCheck::LCC_SecurityHall_2] = LevelClearCheckData(0x01DECC59);
    outLevelClearChecks[LevelClearCheck::LCC_SecurityHall_3] = LevelClearCheckData(0x01DECC5A);
    outLevelClearChecks[LevelClearCheck::LCC_SecurityHall_4] = LevelClearCheckData(0x01DECC5B);
    outLevelClearChecks[LevelClearCheck::LCC_SecurityHall_5] = LevelClearCheckData(0x01DECC5C);
    outLevelClearChecks[LevelClearCheck::LCC_SecurityHall_Upgrade] = LevelClearCheckData(0x01DEC652);

    outLevelClearChecks[LevelClearCheck::LCC_PrisonLane_1] = LevelClearCheckData(0x01DECD1C);
    outLevelClearChecks[LevelClearCheck::LCC_PrisonLane_2] = LevelClearCheckData(0x01DECD1D);
    outLevelClearChecks[LevelClearCheck::LCC_PrisonLane_3] = LevelClearCheckData(0x01DECD1E);
    outLevelClearChecks[LevelClearCheck::LCC_PrisonLane_4] = LevelClearCheckData(0x01DECD1F);
    outLevelClearChecks[LevelClearCheck::LCC_PrisonLane_5] = LevelClearCheckData(0x01DECD20);
    outLevelClearChecks[LevelClearCheck::LCC_PrisonLane_Upgrade] = LevelClearCheckData(0x01DEC640);

    outLevelClearChecks[LevelClearCheck::LCC_MetalHarbor_1] = LevelClearCheckData(0x01DECDE0);
    outLevelClearChecks[LevelClearCheck::LCC_MetalHarbor_2] = LevelClearCheckData(0x01DECDE1);
    outLevelClearChecks[LevelClearCheck::LCC_MetalHarbor_3] = LevelClearCheckData(0x01DECDE2);
    outLevelClearChecks[LevelClearCheck::LCC_MetalHarbor_4] = LevelClearCheckData(0x01DECDE3);
    outLevelClearChecks[LevelClearCheck::LCC_MetalHarbor_5] = LevelClearCheckData(0x01DECDE4);
    outLevelClearChecks[LevelClearCheck::LCC_MetalHarbor_Upgrade] = LevelClearCheckData(0x01DEC638);

    outLevelClearChecks[LevelClearCheck::LCC_IronGate_1] = LevelClearCheckData(0x01DECEA4);
    outLevelClearChecks[LevelClearCheck::LCC_IronGate_2] = LevelClearCheckData(0x01DECEA5);
    outLevelClearChecks[LevelClearCheck::LCC_IronGate_3] = LevelClearCheckData(0x01DECEA6);
    outLevelClearChecks[LevelClearCheck::LCC_IronGate_4] = LevelClearCheckData(0x01DECEA7);
    outLevelClearChecks[LevelClearCheck::LCC_IronGate_5] = LevelClearCheckData(0x01DECEA8);
    outLevelClearChecks[LevelClearCheck::LCC_IronGate_Upgrade] = LevelClearCheckData(0x01DEC64E);

    outLevelClearChecks[LevelClearCheck::LCC_WeaponsBed_1] = LevelClearCheckData(0x01DECF68);
    outLevelClearChecks[LevelClearCheck::LCC_WeaponsBed_2] = LevelClearCheckData(0x01DECF69);
    outLevelClearChecks[LevelClearCheck::LCC_WeaponsBed_3] = LevelClearCheckData(0x01DECF6A);
    outLevelClearChecks[LevelClearCheck::LCC_WeaponsBed_4] = LevelClearCheckData(0x01DECF6B);
    outLevelClearChecks[LevelClearCheck::LCC_WeaponsBed_5] = LevelClearCheckData(0x01DECF6C);
    outLevelClearChecks[LevelClearCheck::LCC_WeaponsBed_Upgrade] = LevelClearCheckData(0x01DEC64D);

    outLevelClearChecks[LevelClearCheck::LCC_CityEscape_1] = LevelClearCheckData(0x01DED02C);
    outLevelClearChecks[LevelClearCheck::LCC_CityEscape_2] = LevelClearCheckData(0x01DED02D);
    outLevelClearChecks[LevelClearCheck::LCC_CityEscape_3] = LevelClearCheckData(0x01DED02E);
    outLevelClearChecks[LevelClearCheck::LCC_CityEscape_4] = LevelClearCheckData(0x01DED02F);
    outLevelClearChecks[LevelClearCheck::LCC_CityEscape_5] = LevelClearCheckData(0x01DED030);
    outLevelClearChecks[LevelClearCheck::LCC_CityEscape_Upgrade] = LevelClearCheckData(0x01DEC63A);

    outLevelClearChecks[LevelClearCheck::LCC_RadicalHighway_1] = LevelClearCheckData(0x01DED0F0);
    outLevelClearChecks[LevelClearCheck::LCC_RadicalHighway_2] = LevelClearCheckData(0x01DED0F1);
    outLevelClearChecks[LevelClearCheck::LCC_RadicalHighway_3] = LevelClearCheckData(0x01DED0F2);
    outLevelClearChecks[LevelClearCheck::LCC_RadicalHighway_4] = LevelClearCheckData(0x01DED0F3);
    outLevelClearChecks[LevelClearCheck::LCC_RadicalHighway_5] = LevelClearCheckData(0x01DED0F4);
    outLevelClearChecks[LevelClearCheck::LCC_RadicalHighway_Upgrade] = LevelClearCheckData(0x01DEC64A);

    outLevelClearChecks[LevelClearCheck::LCC_WildCanyon_1] = LevelClearCheckData(0x01DED278);
    outLevelClearChecks[LevelClearCheck::LCC_WildCanyon_2] = LevelClearCheckData(0x01DED279);
    outLevelClearChecks[LevelClearCheck::LCC_WildCanyon_3] = LevelClearCheckData(0x01DED27A);
    outLevelClearChecks[LevelClearCheck::LCC_WildCanyon_4] = LevelClearCheckData(0x01DED27B);
    outLevelClearChecks[LevelClearCheck::LCC_WildCanyon_5] = LevelClearCheckData(0x01DED27C);
    outLevelClearChecks[LevelClearCheck::LCC_WildCanyon_Upgrade] = LevelClearCheckData(0x01DEC646);

    outLevelClearChecks[LevelClearCheck::LCC_MissionStreet_1] = LevelClearCheckData(0x01DED33C);
    outLevelClearChecks[LevelClearCheck::LCC_MissionStreet_2] = LevelClearCheckData(0x01DED33D);
    outLevelClearChecks[LevelClearCheck::LCC_MissionStreet_3] = LevelClearCheckData(0x01DED33E);
    outLevelClearChecks[LevelClearCheck::LCC_MissionStreet_4] = LevelClearCheckData(0x01DED33F);
    outLevelClearChecks[LevelClearCheck::LCC_MissionStreet_5] = LevelClearCheckData(0x01DED340);
    outLevelClearChecks[LevelClearCheck::LCC_MissionStreet_Upgrade] = LevelClearCheckData(0x01DEC63E);

    outLevelClearChecks[LevelClearCheck::LCC_DryLagoon_1] = LevelClearCheckData(0x01DED400);
    outLevelClearChecks[LevelClearCheck::LCC_DryLagoon_2] = LevelClearCheckData(0x01DED401);
    outLevelClearChecks[LevelClearCheck::LCC_DryLagoon_3] = LevelClearCheckData(0x01DED402);
    outLevelClearChecks[LevelClearCheck::LCC_DryLagoon_4] = LevelClearCheckData(0x01DED403);
    outLevelClearChecks[LevelClearCheck::LCC_DryLagoon_5] = LevelClearCheckData(0x01DED404);
    outLevelClearChecks[LevelClearCheck::LCC_DryLagoon_Upgrade] = LevelClearCheckData(0x01DEC654);

    outLevelClearChecks[LevelClearCheck::LCC_SandOcean_1] = LevelClearCheckData(0x01DED64C);
    outLevelClearChecks[LevelClearCheck::LCC_SandOcean_2] = LevelClearCheckData(0x01DED64D);
    outLevelClearChecks[LevelClearCheck::LCC_SandOcean_3] = LevelClearCheckData(0x01DED64E);
    outLevelClearChecks[LevelClearCheck::LCC_SandOcean_4] = LevelClearCheckData(0x01DED64F);
    outLevelClearChecks[LevelClearCheck::LCC_SandOcean_5] = LevelClearCheckData(0x01DED650);
    outLevelClearChecks[LevelClearCheck::LCC_SandOcean_Upgrade] = LevelClearCheckData(0x01DEC650);

    outLevelClearChecks[LevelClearCheck::LCC_CrazyGadget_1] = LevelClearCheckData(0x01DED710);
    outLevelClearChecks[LevelClearCheck::LCC_CrazyGadget_2] = LevelClearCheckData(0x01DED711);
    outLevelClearChecks[LevelClearCheck::LCC_CrazyGadget_3] = LevelClearCheckData(0x01DED712);
    outLevelClearChecks[LevelClearCheck::LCC_CrazyGadget_4] = LevelClearCheckData(0x01DED713);
    outLevelClearChecks[LevelClearCheck::LCC_CrazyGadget_5] = LevelClearCheckData(0x01DED714);
    outLevelClearChecks[LevelClearCheck::LCC_CrazyGadget_Upgrade] = LevelClearCheckData(0x01DEC63B);

    outLevelClearChecks[LevelClearCheck::LCC_HiddenBase_1] = LevelClearCheckData(0x01DED7D4);
    outLevelClearChecks[LevelClearCheck::LCC_HiddenBase_2] = LevelClearCheckData(0x01DED7D5);
    outLevelClearChecks[LevelClearCheck::LCC_HiddenBase_3] = LevelClearCheckData(0x01DED7D6);
    outLevelClearChecks[LevelClearCheck::LCC_HiddenBase_4] = LevelClearCheckData(0x01DED7D7);
    outLevelClearChecks[LevelClearCheck::LCC_HiddenBase_5] = LevelClearCheckData(0x01DED7D8);
    outLevelClearChecks[LevelClearCheck::LCC_HiddenBase_Upgrade] = LevelClearCheckData(0x01DEC641);

    outLevelClearChecks[LevelClearCheck::LCC_EternalEngine_1] = LevelClearCheckData(0x01DED898);
    outLevelClearChecks[LevelClearCheck::LCC_EternalEngine_2] = LevelClearCheckData(0x01DED899);
    outLevelClearChecks[LevelClearCheck::LCC_EternalEngine_3] = LevelClearCheckData(0x01DED89A);
    outLevelClearChecks[LevelClearCheck::LCC_EternalEngine_4] = LevelClearCheckData(0x01DED89B);
    outLevelClearChecks[LevelClearCheck::LCC_EternalEngine_5] = LevelClearCheckData(0x01DED89C);
    outLevelClearChecks[LevelClearCheck::LCC_EternalEngine_Upgrade] = LevelClearCheckData(0x01DEC63F);

    outLevelClearChecks[LevelClearCheck::LCC_DeathChamber_1] = LevelClearCheckData(0x01DED95C);
    outLevelClearChecks[LevelClearCheck::LCC_DeathChamber_2] = LevelClearCheckData(0x01DED95D);
    outLevelClearChecks[LevelClearCheck::LCC_DeathChamber_3] = LevelClearCheckData(0x01DED95E);
    outLevelClearChecks[LevelClearCheck::LCC_DeathChamber_4] = LevelClearCheckData(0x01DED95F);
    outLevelClearChecks[LevelClearCheck::LCC_DeathChamber_5] = LevelClearCheckData(0x01DED960);
    outLevelClearChecks[LevelClearCheck::LCC_DeathChamber_Upgrade] = LevelClearCheckData(0x01DEC644);

    outLevelClearChecks[LevelClearCheck::LCC_EggQuarters_1] = LevelClearCheckData(0x01DEDA20);
    outLevelClearChecks[LevelClearCheck::LCC_EggQuarters_2] = LevelClearCheckData(0x01DEDA21);
    outLevelClearChecks[LevelClearCheck::LCC_EggQuarters_3] = LevelClearCheckData(0x01DEDA22);
    outLevelClearChecks[LevelClearCheck::LCC_EggQuarters_4] = LevelClearCheckData(0x01DEDA23);
    outLevelClearChecks[LevelClearCheck::LCC_EggQuarters_5] = LevelClearCheckData(0x01DEDA24);
    outLevelClearChecks[LevelClearCheck::LCC_EggQuarters_Upgrade] = LevelClearCheckData(0x01DEC651);

    outLevelClearChecks[LevelClearCheck::LCC_LostColony_1] = LevelClearCheckData(0x01DEDAE4);
    outLevelClearChecks[LevelClearCheck::LCC_LostColony_2] = LevelClearCheckData(0x01DEDAE5);
    outLevelClearChecks[LevelClearCheck::LCC_LostColony_3] = LevelClearCheckData(0x01DEDAE6);
    outLevelClearChecks[LevelClearCheck::LCC_LostColony_4] = LevelClearCheckData(0x01DEDAE7);
    outLevelClearChecks[LevelClearCheck::LCC_LostColony_5] = LevelClearCheckData(0x01DEDAE8);
    outLevelClearChecks[LevelClearCheck::LCC_LostColony_Upgrade] = LevelClearCheckData(0x01DEC64C);

    outLevelClearChecks[LevelClearCheck::LCC_PyramidCave_1] = LevelClearCheckData(0x01DEDBA8);
    outLevelClearChecks[LevelClearCheck::LCC_PyramidCave_2] = LevelClearCheckData(0x01DEDBA9);
    outLevelClearChecks[LevelClearCheck::LCC_PyramidCave_3] = LevelClearCheckData(0x01DEDBAA);
    outLevelClearChecks[LevelClearCheck::LCC_PyramidCave_4] = LevelClearCheckData(0x01DEDBAB);
    outLevelClearChecks[LevelClearCheck::LCC_PyramidCave_5] = LevelClearCheckData(0x01DEDBAC);
    outLevelClearChecks[LevelClearCheck::LCC_PyramidCave_Upgrade] = LevelClearCheckData(0x01DEC63C);

    outLevelClearChecks[LevelClearCheck::LCC_FinalRush_1] = LevelClearCheckData(0x01DEDD30);
    outLevelClearChecks[LevelClearCheck::LCC_FinalRush_2] = LevelClearCheckData(0x01DEDD31);
    outLevelClearChecks[LevelClearCheck::LCC_FinalRush_3] = LevelClearCheckData(0x01DEDD32);
    outLevelClearChecks[LevelClearCheck::LCC_FinalRush_4] = LevelClearCheckData(0x01DEDD33);
    outLevelClearChecks[LevelClearCheck::LCC_FinalRush_5] = LevelClearCheckData(0x01DEDD34);
    outLevelClearChecks[LevelClearCheck::LCC_FinalRush_Upgrade] = LevelClearCheckData(0x01DEC63D);

    outLevelClearChecks[LevelClearCheck::LCC_GreenHill] = LevelClearCheckData(0x01DEDDF4);

    outLevelClearChecks[LevelClearCheck::LCC_MeteorHerd_1] = LevelClearCheckData(0x01DEDEB8);
    outLevelClearChecks[LevelClearCheck::LCC_MeteorHerd_2] = LevelClearCheckData(0x01DEDEB9);
    outLevelClearChecks[LevelClearCheck::LCC_MeteorHerd_3] = LevelClearCheckData(0x01DEDEBA);
    outLevelClearChecks[LevelClearCheck::LCC_MeteorHerd_4] = LevelClearCheckData(0x01DEDEBB);
    outLevelClearChecks[LevelClearCheck::LCC_MeteorHerd_5] = LevelClearCheckData(0x01DEDEBC);
    outLevelClearChecks[LevelClearCheck::LCC_MeteorHerd_Upgrade] = LevelClearCheckData(0x01DEC643);

    outLevelClearChecks[LevelClearCheck::LCC_CannonCore_1] = LevelClearCheckData(0x01DEE040);
    outLevelClearChecks[LevelClearCheck::LCC_CannonCore_2] = LevelClearCheckData(0x01DEE041);
    outLevelClearChecks[LevelClearCheck::LCC_CannonCore_3] = LevelClearCheckData(0x01DEE042);
    outLevelClearChecks[LevelClearCheck::LCC_CannonCore_4] = LevelClearCheckData(0x01DEE043);
    outLevelClearChecks[LevelClearCheck::LCC_CannonCore_5] = LevelClearCheckData(0x01DEE044);

    outLevelClearChecks[LevelClearCheck::LCC_FinalChase_1] = LevelClearCheckData(0x01DEE4D8);
    outLevelClearChecks[LevelClearCheck::LCC_FinalChase_2] = LevelClearCheckData(0x01DEE4D9);
    outLevelClearChecks[LevelClearCheck::LCC_FinalChase_3] = LevelClearCheckData(0x01DEE4DA);
    outLevelClearChecks[LevelClearCheck::LCC_FinalChase_4] = LevelClearCheckData(0x01DEE4DB);
    outLevelClearChecks[LevelClearCheck::LCC_FinalChase_5] = LevelClearCheckData(0x01DEE4DC);
    outLevelClearChecks[LevelClearCheck::LCC_FinalChase_Upgrade] = LevelClearCheckData(0x01DEC64B);

    outLevelClearChecks[LevelClearCheck::LCC_CosmicWall_1] = LevelClearCheckData(0x01DEE724);
    outLevelClearChecks[LevelClearCheck::LCC_CosmicWall_2] = LevelClearCheckData(0x01DEE725);
    outLevelClearChecks[LevelClearCheck::LCC_CosmicWall_3] = LevelClearCheckData(0x01DEE726);
    outLevelClearChecks[LevelClearCheck::LCC_CosmicWall_4] = LevelClearCheckData(0x01DEE727);
    outLevelClearChecks[LevelClearCheck::LCC_CosmicWall_5] = LevelClearCheckData(0x01DEE728);
    outLevelClearChecks[LevelClearCheck::LCC_CosmicWall_Upgrade] = LevelClearCheckData(0x01DEC64F);

    outLevelClearChecks[LevelClearCheck::LCC_MadSpace_1] = LevelClearCheckData(0x01DEE7E8);
    outLevelClearChecks[LevelClearCheck::LCC_MadSpace_2] = LevelClearCheckData(0x01DEE7E9);
    outLevelClearChecks[LevelClearCheck::LCC_MadSpace_3] = LevelClearCheckData(0x01DEE7EA);
    outLevelClearChecks[LevelClearCheck::LCC_MadSpace_4] = LevelClearCheckData(0x01DEE7EB);
    outLevelClearChecks[LevelClearCheck::LCC_MadSpace_5] = LevelClearCheckData(0x01DEE7EC);
    outLevelClearChecks[LevelClearCheck::LCC_MadSpace_Upgrade] = LevelClearCheckData(0x01DEC653);

    outLevelClearChecks[LevelClearCheck::LCC_Route101_1] = LevelClearCheckData(0x01DEF428);
    outLevelClearChecks[LevelClearCheck::LCC_Route101_2] = LevelClearCheckData(0x01DEF429);
    outLevelClearChecks[LevelClearCheck::LCC_Route101_3] = LevelClearCheckData(0x01DEF42A);
    outLevelClearChecks[LevelClearCheck::LCC_Route101_4] = LevelClearCheckData(0x01DEF42B);
    outLevelClearChecks[LevelClearCheck::LCC_Route101_5] = LevelClearCheckData(0x01DEF42C);

    outLevelClearChecks[LevelClearCheck::LCC_Route280_1] = LevelClearCheckData(0x01DEF4EC);
    outLevelClearChecks[LevelClearCheck::LCC_Route280_2] = LevelClearCheckData(0x01DEF4ED);
    outLevelClearChecks[LevelClearCheck::LCC_Route280_3] = LevelClearCheckData(0x01DEF4EE);
    outLevelClearChecks[LevelClearCheck::LCC_Route280_4] = LevelClearCheckData(0x01DEF4EF);
    outLevelClearChecks[LevelClearCheck::LCC_Route280_5] = LevelClearCheckData(0x01DEF4F0);
}

void InitializeChaoGardenChecks(std::map<int, ChaoGardenCheckData>& outChaoGardenChecks)
{
    outChaoGardenChecks.clear();

    outChaoGardenChecks[ChaoGardenCheck::CGC_CrabPool_1]       = ChaoGardenCheckData(0x01A0F993, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_CrabPool_2]       = ChaoGardenCheckData(0x01A0F993, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_CrabPool_3]       = ChaoGardenCheckData(0x01A0F993, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_StumpValley_1]    = ChaoGardenCheckData(0x01A0F994, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_StumpValley_2]    = ChaoGardenCheckData(0x01A0F994, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_StumpValley_3]    = ChaoGardenCheckData(0x01A0F994, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_MushroomForest_1] = ChaoGardenCheckData(0x01A0F995, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_MushroomForest_2] = ChaoGardenCheckData(0x01A0F995, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_MushroomForest_3] = ChaoGardenCheckData(0x01A0F995, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_BlockCanyon_1]    = ChaoGardenCheckData(0x01A0F996, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_BlockCanyon_2]    = ChaoGardenCheckData(0x01A0F996, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_BlockCanyon_3]    = ChaoGardenCheckData(0x01A0F996, 2);

    outChaoGardenChecks[ChaoGardenCheck::CGC_Aquamarine_1] = ChaoGardenCheckData(0x01A0F997, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Aquamarine_2] = ChaoGardenCheckData(0x01A0F997, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Aquamarine_3] = ChaoGardenCheckData(0x01A0F997, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Aquamarine_4] = ChaoGardenCheckData(0x01A0F997, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Aquamarine_5] = ChaoGardenCheckData(0x01A0F997, 4);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Topaz_1]      = ChaoGardenCheckData(0x01A0F998, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Topaz_2]      = ChaoGardenCheckData(0x01A0F998, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Topaz_3]      = ChaoGardenCheckData(0x01A0F998, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Topaz_4]      = ChaoGardenCheckData(0x01A0F998, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Topaz_5]      = ChaoGardenCheckData(0x01A0F998, 4);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Peridot_1]    = ChaoGardenCheckData(0x01A0F999, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Peridot_2]    = ChaoGardenCheckData(0x01A0F999, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Peridot_3]    = ChaoGardenCheckData(0x01A0F999, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Peridot_4]    = ChaoGardenCheckData(0x01A0F999, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Peridot_5]    = ChaoGardenCheckData(0x01A0F999, 4);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Garnet_1]     = ChaoGardenCheckData(0x01A0F99A, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Garnet_2]     = ChaoGardenCheckData(0x01A0F99A, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Garnet_3]     = ChaoGardenCheckData(0x01A0F99A, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Garnet_4]     = ChaoGardenCheckData(0x01A0F99A, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Garnet_5]     = ChaoGardenCheckData(0x01A0F99A, 4);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Onyx_1]       = ChaoGardenCheckData(0x01A0F99B, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Onyx_2]       = ChaoGardenCheckData(0x01A0F99B, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Onyx_3]       = ChaoGardenCheckData(0x01A0F99B, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Onyx_4]       = ChaoGardenCheckData(0x01A0F99B, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Onyx_5]       = ChaoGardenCheckData(0x01A0F99B, 4);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Diamond_1]    = ChaoGardenCheckData(0x01A0F99C, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Diamond_2]    = ChaoGardenCheckData(0x01A0F99C, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Diamond_3]    = ChaoGardenCheckData(0x01A0F99C, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Diamond_4]    = ChaoGardenCheckData(0x01A0F99C, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Diamond_5]    = ChaoGardenCheckData(0x01A0F99C, 4);

    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_1]  = ChaoGardenCheckData(0x01A0F99D, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_2]  = ChaoGardenCheckData(0x01A0F99D, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_3]  = ChaoGardenCheckData(0x01A0F99D, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_4]  = ChaoGardenCheckData(0x01A0F99D, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_5]  = ChaoGardenCheckData(0x01A0F99D, 4);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_6]  = ChaoGardenCheckData(0x01A0F99D, 5);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_7]  = ChaoGardenCheckData(0x01A0F99D, 6);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_8]  = ChaoGardenCheckData(0x01A0F99D, 7);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_9]  = ChaoGardenCheckData(0x01A0F99D, 8);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_10] = ChaoGardenCheckData(0x01A0F99D, 9);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_11] = ChaoGardenCheckData(0x01A0F99D, 10);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Challenge_12] = ChaoGardenCheckData(0x01A0F99D, 11);

    outChaoGardenChecks[ChaoGardenCheck::CGC_Hero_1] = ChaoGardenCheckData(0x01A0F99E, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Hero_2] = ChaoGardenCheckData(0x01A0F99E, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Hero_3] = ChaoGardenCheckData(0x01A0F99E, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Hero_4] = ChaoGardenCheckData(0x01A0F99E, 3);

    outChaoGardenChecks[ChaoGardenCheck::CGC_Dark_1] = ChaoGardenCheckData(0x01A0F99F, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Dark_2] = ChaoGardenCheckData(0x01A0F99F, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Dark_3] = ChaoGardenCheckData(0x01A0F99F, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Dark_4] = ChaoGardenCheckData(0x01A0F99F, 3);

    outChaoGardenChecks[ChaoGardenCheck::CGC_Beginner_Karate]     = ChaoGardenCheckData(0x019F6C00, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Intermediate_Karate] = ChaoGardenCheckData(0x019F6C00, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Expert_Karate]       = ChaoGardenCheckData(0x019F6C00, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Super_Karate]        = ChaoGardenCheckData(0x019F6C00, 3);
}

void InitializeChaoRacePacks(std::map<int, std::vector<int>>& outChaoRacePacks)
{
    outChaoRacePacks.clear();

    outChaoRacePacks[ChaoGardenCheck::CGC_CrabPool_3]       = std::vector<int>{ CGC_CrabPool_1, CGC_CrabPool_2 };
    outChaoRacePacks[ChaoGardenCheck::CGC_StumpValley_3]    = std::vector<int>{ CGC_StumpValley_1, CGC_StumpValley_2 };
    outChaoRacePacks[ChaoGardenCheck::CGC_MushroomForest_3] = std::vector<int>{ CGC_MushroomForest_1, CGC_MushroomForest_2 };
    outChaoRacePacks[ChaoGardenCheck::CGC_BlockCanyon_3]    = std::vector<int>{ CGC_BlockCanyon_1, CGC_BlockCanyon_2 };

    outChaoRacePacks[ChaoGardenCheck::CGC_Aquamarine_5] = std::vector<int>{ CGC_Aquamarine_1, CGC_Aquamarine_2, CGC_Aquamarine_3, CGC_Aquamarine_4 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Topaz_5]      = std::vector<int>{ CGC_Topaz_1, CGC_Topaz_2, CGC_Topaz_3, CGC_Topaz_4 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Peridot_5]    = std::vector<int>{ CGC_Peridot_1, CGC_Peridot_2, CGC_Peridot_3, CGC_Peridot_4 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Garnet_5]     = std::vector<int>{ CGC_Garnet_1, CGC_Garnet_2, CGC_Garnet_3, CGC_Garnet_4 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Onyx_5]       = std::vector<int>{ CGC_Onyx_1, CGC_Onyx_2, CGC_Onyx_3, CGC_Onyx_4 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Diamond_5]    = std::vector<int>{ CGC_Diamond_1, CGC_Diamond_2, CGC_Diamond_3, CGC_Diamond_4 };

    outChaoRacePacks[ChaoGardenCheck::CGC_Challenge_4]  = std::vector<int>{ CGC_Challenge_1, CGC_Challenge_2, CGC_Challenge_3 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Challenge_8]  = std::vector<int>{ CGC_Challenge_5, CGC_Challenge_6, CGC_Challenge_7 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Challenge_12] = std::vector<int>{ CGC_Challenge_9, CGC_Challenge_10, CGC_Challenge_11 };

    outChaoRacePacks[ChaoGardenCheck::CGC_Hero_2] = std::vector<int>{ CGC_Hero_1 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Hero_4] = std::vector<int>{ CGC_Hero_3 };

    outChaoRacePacks[ChaoGardenCheck::CGC_Dark_2] = std::vector<int>{ CGC_Dark_1 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Dark_4] = std::vector<int>{ CGC_Dark_3 };
}
