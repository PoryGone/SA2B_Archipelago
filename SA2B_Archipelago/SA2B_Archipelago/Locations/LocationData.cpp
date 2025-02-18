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

    outLevelClearChecks[LevelClearCheck::LCC_Boss_1] = LevelClearCheckData(0x01DEE59C);
    outLevelClearChecks[LevelClearCheck::LCC_Boss_2] = LevelClearCheckData(0x01DEE59D);
    outLevelClearChecks[LevelClearCheck::LCC_Boss_3] = LevelClearCheckData(0x01DEE59E);
    outLevelClearChecks[LevelClearCheck::LCC_Boss_4] = LevelClearCheckData(0x01DEE59F);
    outLevelClearChecks[LevelClearCheck::LCC_Boss_5] = LevelClearCheckData(0x01DEE5A0);
}

void InitializeBossRushChecks(std::map<int, BossRushCheckData>& outBossRushChecks)
{
    outBossRushChecks[BossRushCheck::BRC_Boss_1]  = BossRushCheckData(0x01DEE5A1, 0x00, 0x00, 0x173A708, 0x00, 0x13);
    outBossRushChecks[BossRushCheck::BRC_Boss_2]  = BossRushCheckData(0x01DEE5A1, 0x01, 0x01, 0x173A714, 0x00, 0x2A);
    outBossRushChecks[BossRushCheck::BRC_Boss_3]  = BossRushCheckData(0x01DEE5A1, 0x02, 0x02, 0x173A720, 0x06, 0x14);
    outBossRushChecks[BossRushCheck::BRC_Boss_4]  = BossRushCheckData(0x01DEE5A1, 0x03, 0x03, 0x173A72C, 0x06, 0x1D);
    outBossRushChecks[BossRushCheck::BRC_Boss_5]  = BossRushCheckData(0x01DEE5A1, 0x04, 0x04, 0x173A738, 0x04, 0x21);
    outBossRushChecks[BossRushCheck::BRC_Boss_6]  = BossRushCheckData(0x01DEE5A1, 0x05, 0x05, 0x173A744, 0x00, 0x3C);
    outBossRushChecks[BossRushCheck::BRC_Boss_7]  = BossRushCheckData(0x01DEE5A1, 0x06, 0x06, 0x173A750, 0x01, 0x3D);
    outBossRushChecks[BossRushCheck::BRC_Boss_8]  = BossRushCheckData(0x01DEE5A1, 0x07, 0x07, 0x173A75C, 0x05, 0x3E);
    outBossRushChecks[BossRushCheck::BRC_Boss_9]  = BossRushCheckData(0x01DEE5A2, 0x00, 0x08, 0x173A768, 0x00, 0x40);
    outBossRushChecks[BossRushCheck::BRC_Boss_10] = BossRushCheckData(0x01DEE5A2, 0x01, 0x09, 0x173A774, 0x07, 0x43);
    outBossRushChecks[BossRushCheck::BRC_Boss_11] = BossRushCheckData(0x01DEE5A2, 0x02, 0x0A, 0x173A780, 0x04, 0x3F);
    outBossRushChecks[BossRushCheck::BRC_Boss_12] = BossRushCheckData(0x01DEE5A2, 0x03, 0x0B, 0x173A78C, 0x01, 0x13);
    outBossRushChecks[BossRushCheck::BRC_Boss_13] = BossRushCheckData(0x01DEE5A2, 0x04, 0x0C, 0x173A798, 0x01, 0x2A);
    outBossRushChecks[BossRushCheck::BRC_Boss_14] = BossRushCheckData(0x01DEE5A2, 0x05, 0x0D, 0x173A7A4, 0x07, 0x14);
    outBossRushChecks[BossRushCheck::BRC_Boss_15] = BossRushCheckData(0x01DEE5A2, 0x06, 0x0E, 0x173A7B0, 0x07, 0x1D);
    outBossRushChecks[BossRushCheck::BRC_Boss_16] = BossRushCheckData(0x01DEE5A2, 0x07, 0x0F, 0x173A7BC, 0x05, 0x21);
}

void InitializeChaoKeyChecks(std::map<int, ChaoKeyCheckData>& outChaoKeyChecks)
{
    outChaoKeyChecks.clear();

    outChaoKeyChecks[ChaoKeyCheck::CKC_GreenForest_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8AC, LevelIDs_GreenForest, { 620, -1220, 3050 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_GreenForest_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8AD, LevelIDs_GreenForest, { 6070, -1865, 7550 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_GreenForest_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8AE, LevelIDs_GreenForest, { 8330, -1245, 8025 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_WhiteJungle_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8AF, LevelIDs_WhiteJungle, { 3840, -2205, -1020 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_WhiteJungle_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8B0, LevelIDs_WhiteJungle, { 12175, -3594, -7820 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_WhiteJungle_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8B1, LevelIDs_WhiteJungle, { 13520, -3600, -6075 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_PumpkinHill_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8B2, LevelIDs_PumpkinHill, { 95, -800, -180 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_PumpkinHill_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8B3, LevelIDs_PumpkinHill, { 370, -986, -1060 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_PumpkinHill_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8B4, LevelIDs_PumpkinHill, { 1940, -955, -1090 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_SkyRail_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8B5, LevelIDs_SkyRail, { -540, -775, 2345 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_SkyRail_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8B6, LevelIDs_SkyRail, { -3340, -2158, 3180 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_SkyRail_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8B7, LevelIDs_SkyRail, { -2015, -2070, 4535 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_AquaticMine_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8B8, LevelIDs_AquaticMine, { -130, 310, 130 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_AquaticMine_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8B9, LevelIDs_AquaticMine, { -640, 25, -270 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_AquaticMine_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8BA, LevelIDs_AquaticMine, { 255, -248, -300 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_SecurityHall_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8BB, LevelIDs_SecurityHall, { -175, -933, -110 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_SecurityHall_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8BC, LevelIDs_SecurityHall, { 75, 27, -10 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_SecurityHall_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8BD, LevelIDs_SecurityHall, { 480, -513, 540 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_PrisonLane_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8BE, LevelIDs_PrisonLane, { 105, -3, -210 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_PrisonLane_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8BF, LevelIDs_PrisonLane, { -775, 97, 410 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_PrisonLane_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8C0, LevelIDs_PrisonLane, { -1480, 237, -130 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_MetalHarbor_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8C1, LevelIDs_MetalHarbor, { 2011, -170, -2090 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MetalHarbor_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8C2, LevelIDs_MetalHarbor, { 1850, -170, -5600 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MetalHarbor_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8C3, LevelIDs_MetalHarbor, { 4820, -270, -9225 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_IronGate_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8C4, LevelIDs_IronGate, { 730, -230, -550 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_IronGate_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8C5, LevelIDs_IronGate, { 3635, -864, -365 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_IronGate_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8C6, LevelIDs_IronGate, { 6065, -1521, -1235 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_WeaponsBed_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8C7, LevelIDs_WeaponsBed, { -200, -170, -1805 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_WeaponsBed_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8C8, LevelIDs_WeaponsBed, { 2150, -170, -4385 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_WeaponsBed_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8C9, LevelIDs_WeaponsBed, { 3750, -170, -9015 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_CityEscape_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8CA, LevelIDs_CityEscape, { 2850, -8555, 6418 }, { 2810, -8505, 6375 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CityEscape_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8CB, LevelIDs_CityEscape, { 6040, -10690, 4395 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CityEscape_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8CC, LevelIDs_CityEscape, { 7728, -14355, 6278 }, { 7660, -14605, 6025 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_RadicalHighway_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8CD, LevelIDs_RadicalHighway, { -1500, -1020, -4310 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_RadicalHighway_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8CE, LevelIDs_RadicalHighway, { -5070, -2763, -4360 }, { -5344, -2813, -4347 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_RadicalHighway_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8CF, LevelIDs_RadicalHighway, { -6360, -5116, -11245 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_WildCanyon_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8D0, LevelIDs_WildCanyon, { 300, 235, 150 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_WildCanyon_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8D1, LevelIDs_WildCanyon, { 1070, 812, 20 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_WildCanyon_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8D2, LevelIDs_WildCanyon, { -405, 927, -120 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_MissionStreet_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8D3, LevelIDs_MissionStreet, { -1250, -58, -2265 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MissionStreet_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8D4, LevelIDs_MissionStreet, { -1260, 35, -3025 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MissionStreet_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8D5, LevelIDs_MissionStreet, { 2835, 200, -3460 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_DryLagoon_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8D6, LevelIDs_DryLagoon, { -160, 55, 135 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_DryLagoon_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8D7, LevelIDs_DryLagoon, { -140, 457, 255 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_DryLagoon_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8D8, LevelIDs_DryLagoon, { -70, 429, 1410 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_SandOcean_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8D9, LevelIDs_SandOcean, { 320, 30, -1980 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_SandOcean_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8DA, LevelIDs_SandOcean, { 990, 90, -3420 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_SandOcean_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8DB, LevelIDs_SandOcean, { 2625, 20, -4065 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_CrazyGadget_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8DC, LevelIDs_CrazyGadget, { -5755, -1238, -3205 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CrazyGadget_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8DD, LevelIDs_CrazyGadget, { -8300, -1065, -3805 }, { -9588, -798, -3325 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CrazyGadget_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8DE, LevelIDs_CrazyGadget, { -10950, -1027, -2737 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_HiddenBase_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8DF, LevelIDs_HiddenBase, { 150, 110, -2875 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_HiddenBase_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8E0, LevelIDs_HiddenBase, { -3850, 110, -3080 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_EternalEngine_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8E1, LevelIDs_EternalEngine, { -920, 578, -2200 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_EternalEngine_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8E2, LevelIDs_EternalEngine, { -1600, 786, -5310 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_EternalEngine_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8E3, LevelIDs_EternalEngine, { -2745, 836, -5200 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_DeathChamber_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8E4, LevelIDs_DeathChamber, { 215, 0, 215 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_DeathChamber_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8E5, LevelIDs_DeathChamber, { -980, -130, 290 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_DeathChamber_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8E6, LevelIDs_DeathChamber, { 600, 59, 1805 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_EggQuarters_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8E7, LevelIDs_EggQuarters, { -660, -30, 940 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_EggQuarters_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8E8, LevelIDs_EggQuarters, { -80, 50, 395 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_EggQuarters_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8E9, LevelIDs_EggQuarters, { -500, 40, 2680 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_LostColony_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8EA, LevelIDs_LostColony, { -1553, -614, -2110 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_LostColony_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8EB, LevelIDs_LostColony, { -881, -568, -2050 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_LostColony_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8EC, LevelIDs_LostColony, { 1430, -918, -2400 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_PyramidCave_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8ED, LevelIDs_PyramidCave, { -1450, -2010, -6415 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_PyramidCave_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8EE, LevelIDs_PyramidCave, { -2505, -1731, -8560 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_PyramidCave_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8EF, LevelIDs_PyramidCave, { -2750, -4050, -19270 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_FinalRush_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8F0, LevelIDs_FinalRush, { 3855, -795, -705 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_FinalRush_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8F1, LevelIDs_FinalRush, { 4290, -2641, 2895 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_FinalRush_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8F2, LevelIDs_FinalRush, { 6025, -12751, 15862 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_MeteorHerd_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8F3, LevelIDs_MeteorHerd, { 325, -600, -1020 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MeteorHerd_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8F4, LevelIDs_MeteorHerd, { 0, -440, -195 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MeteorHerd_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8F5, LevelIDs_MeteorHerd, { -425, 895, -420 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_CannonCore_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8F6, LevelIDs_CannonsCoreE, { 570, 120, -2590 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CannonCore_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8F7, LevelIDs_CannonsCoreR, { -80, -131, -990 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CannonCore_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8F8, LevelIDs_CannonsCoreS, { -50, -480, -990 }, { -510, -1650, -4533 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_FinalChase_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8F9, LevelIDs_FinalChase, { 3715, -4575, 3375 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_FinalChase_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8FA, LevelIDs_FinalChase, { 4275, -5170, 8645 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_FinalChase_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8FB, LevelIDs_FinalChase, { 1490, -7614, 18210 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_CosmicWall_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8FC, LevelIDs_CosmicWall, { 3090, 1750, -725 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CosmicWall_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8FD, LevelIDs_CosmicWall, { 5678, 3167, 3530 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CosmicWall_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8FE, LevelIDs_CosmicWall, { 6648, 4317, 9268 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_MadSpace_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8FF, LevelIDs_MadSpace, { 140, 327, -80 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MadSpace_Chao_Key_2] = ChaoKeyCheckData(0x01DEE900, LevelIDs_MadSpace, { -620, 1699, 185 }, { -613, 1699, 149 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MadSpace_Chao_Key_3] = ChaoKeyCheckData(0x01DEE901, LevelIDs_MadSpace, { 100, 4099, -60 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_GreenHill_Chao_Key_1] = ChaoKeyCheckData(0x01DEE902, LevelIDs_GreenHill, { -790, -70, -2715 });
}

void InitializePipeChecks(std::map<int, PipeCheckData>& outPipeChecks)
{
    outPipeChecks.clear();

    outPipeChecks[PipeCheck::PC_GreenForest_Pipe_1] = PipeCheckData(0x01DEE970, LevelIDs_GreenForest, { 2222, -951, 3956 });
    outPipeChecks[PipeCheck::PC_GreenForest_Pipe_2] = PipeCheckData(0x01DEE971, LevelIDs_GreenForest, { 8276, -727, 7726 });

    outPipeChecks[PipeCheck::PC_WhiteJungle_Pipe_1] = PipeCheckData(0x01DEE972, LevelIDs_WhiteJungle, { 4163, -2224, -677 });
    outPipeChecks[PipeCheck::PC_WhiteJungle_Pipe_2] = PipeCheckData(0x01DEE973, LevelIDs_WhiteJungle, { 6971, -1937, -3717 });
    outPipeChecks[PipeCheck::PC_WhiteJungle_Pipe_3] = PipeCheckData(0x01DEE974, LevelIDs_WhiteJungle, { 10416, -3572, -7511 });
    outPipeChecks[PipeCheck::PC_WhiteJungle_Pipe_4] = PipeCheckData(0x01DEE975, LevelIDs_WhiteJungle, { 11801, -3510, -7531 });

    outPipeChecks[PipeCheck::PC_PumpkinHill_Pipe_1] = PipeCheckData(0x01DEE976, LevelIDs_PumpkinHill, { 64, -870, -1607 });

    outPipeChecks[PipeCheck::PC_SkyRail_Pipe_1] = PipeCheckData(0x01DEE977, LevelIDs_SkyRail, { -525, -775, 1928 });
    outPipeChecks[PipeCheck::PC_SkyRail_Pipe_2] = PipeCheckData(0x01DEE978, LevelIDs_SkyRail, { -3633, -1821, 3079 });
    outPipeChecks[PipeCheck::PC_SkyRail_Pipe_3] = PipeCheckData(0x01DEE979, LevelIDs_SkyRail, { -3323, -1501, 3143 });
    outPipeChecks[PipeCheck::PC_SkyRail_Pipe_4] = PipeCheckData(0x01DEE97A, LevelIDs_SkyRail, { -1938, -2051, 4611 });
    outPipeChecks[PipeCheck::PC_SkyRail_Pipe_5] = PipeCheckData(0x01DEE97B, LevelIDs_SkyRail, { -2288, -4026, 8453 });
    outPipeChecks[PipeCheck::PC_SkyRail_Pipe_6] = PipeCheckData(0x01DEE97C, LevelIDs_SkyRail, { -2291, -3876, 8523 });

    outPipeChecks[PipeCheck::PC_AquaticMine_Pipe_1] = PipeCheckData(0x01DEE97D, LevelIDs_AquaticMine, { 124, 310, -25 });
    outPipeChecks[PipeCheck::PC_AquaticMine_Pipe_2] = PipeCheckData(0x01DEE97E, LevelIDs_AquaticMine, { 339, -86, -184 });
    outPipeChecks[PipeCheck::PC_AquaticMine_Pipe_3] = PipeCheckData(0x01DEE97F, LevelIDs_AquaticMine, { 151, -248, -329 });

    outPipeChecks[PipeCheck::PC_SecurityHall_Pipe_1] = PipeCheckData(0x01DEE980, LevelIDs_SecurityHall, { -178, -883, 117 });

    outPipeChecks[PipeCheck::PC_PrisonLane_Pipe_1] = PipeCheckData(0x01DEE981, LevelIDs_PrisonLane, { 105, -3, 215 });
    outPipeChecks[PipeCheck::PC_PrisonLane_Pipe_2] = PipeCheckData(0x01DEE982, LevelIDs_PrisonLane, { -1483, 277, -78 });
    outPipeChecks[PipeCheck::PC_PrisonLane_Pipe_3] = PipeCheckData(0x01DEE983, LevelIDs_PrisonLane, { -3450, 679, -175 });

    outPipeChecks[PipeCheck::PC_MetalHarbor_Pipe_1] = PipeCheckData(0x01DEE984, LevelIDs_MetalHarbor, { 1649, -299, -2170 });

    outPipeChecks[PipeCheck::PC_IronGate_Pipe_1] = PipeCheckData(0x01DEE985, LevelIDs_IronGate, { 1165, -271, -723 });
    outPipeChecks[PipeCheck::PC_IronGate_Pipe_2] = PipeCheckData(0x01DEE986, LevelIDs_IronGate, { 2396, -663, -667 });
    outPipeChecks[PipeCheck::PC_IronGate_Pipe_3] = PipeCheckData(0x01DEE987, LevelIDs_IronGate, { 3917, -903, -608 });
    outPipeChecks[PipeCheck::PC_IronGate_Pipe_4] = PipeCheckData(0x01DEE988, LevelIDs_IronGate, { 4965, -1436, -1040 });
    outPipeChecks[PipeCheck::PC_IronGate_Pipe_5] = PipeCheckData(0x01DEE989, LevelIDs_IronGate, { 5409, -1421, -1261 });

    outPipeChecks[PipeCheck::PC_WeaponsBed_Pipe_1] = PipeCheckData(0x01DEE98A, LevelIDs_WeaponsBed, { 108, -170, -234 });
    outPipeChecks[PipeCheck::PC_WeaponsBed_Pipe_2] = PipeCheckData(0x01DEE98B, LevelIDs_WeaponsBed, { 259, -170, -1761 });
    outPipeChecks[PipeCheck::PC_WeaponsBed_Pipe_3] = PipeCheckData(0x01DEE98C, LevelIDs_WeaponsBed, { 1864, -270, -5951 });
    outPipeChecks[PipeCheck::PC_WeaponsBed_Pipe_4] = PipeCheckData(0x01DEE98D, LevelIDs_WeaponsBed, { 3264, -170, -8747 });
    outPipeChecks[PipeCheck::PC_WeaponsBed_Pipe_5] = PipeCheckData(0x01DEE98E, LevelIDs_WeaponsBed, { 3523, -220, -9523 });

    outPipeChecks[PipeCheck::PC_CityEscape_Pipe_1] = PipeCheckData(0x01DEE98F, LevelIDs_CityEscape, { -1301, -6260, 9432 });
    outPipeChecks[PipeCheck::PC_CityEscape_Pipe_2] = PipeCheckData(0x01DEE990, LevelIDs_CityEscape, { 380, -6570, 9970 });
    outPipeChecks[PipeCheck::PC_CityEscape_Pipe_3] = PipeCheckData(0x01DEE991, LevelIDs_CityEscape, { 5815, -10790, 4506 });
    outPipeChecks[PipeCheck::PC_CityEscape_Pipe_4] = PipeCheckData(0x01DEE992, LevelIDs_CityEscape, { 6383, -15950, 8675 });

    outPipeChecks[PipeCheck::PC_RadicalHighway_Pipe_1] = PipeCheckData(0x01DEE993, LevelIDs_RadicalHighway, { -4966, -2713, -4319 });
    outPipeChecks[PipeCheck::PC_RadicalHighway_Pipe_2] = PipeCheckData(0x01DEE994, LevelIDs_RadicalHighway, { -6338, -4550, -10033 });
    outPipeChecks[PipeCheck::PC_RadicalHighway_Pipe_3] = PipeCheckData(0x01DEE995, LevelIDs_RadicalHighway, { -8263, -6455, -14335 });

    outPipeChecks[PipeCheck::PC_WildCanyon_Pipe_1] = PipeCheckData(0x01DEE996, LevelIDs_WildCanyon, { 197, 200, -285 });
    outPipeChecks[PipeCheck::PC_WildCanyon_Pipe_2] = PipeCheckData(0x01DEE997, LevelIDs_WildCanyon, { 318, 650, -197 });
    outPipeChecks[PipeCheck::PC_WildCanyon_Pipe_3] = PipeCheckData(0x01DEE998, LevelIDs_WildCanyon, { 771, 950, 48 });

    outPipeChecks[PipeCheck::PC_MissionStreet_Pipe_1] = PipeCheckData(0x01DEE999, LevelIDs_MissionStreet, { -1250, -165, -2516 });
    outPipeChecks[PipeCheck::PC_MissionStreet_Pipe_2] = PipeCheckData(0x01DEE99A, LevelIDs_MissionStreet, { 2322, 200, -3303 });
    outPipeChecks[PipeCheck::PC_MissionStreet_Pipe_3] = PipeCheckData(0x01DEE99B, LevelIDs_MissionStreet, { 4427, 448, -4018 });

    outPipeChecks[PipeCheck::PC_DryLagoon_Pipe_1] = PipeCheckData(0x01DEE99C, LevelIDs_DryLagoon, { 164, 457, -432 });

    outPipeChecks[PipeCheck::PC_SandOcean_Pipe_1] = PipeCheckData(0x01DEE99D, LevelIDs_SandOcean, { 1305, 30, -3765 });
    outPipeChecks[PipeCheck::PC_SandOcean_Pipe_2] = PipeCheckData(0x01DEE99E, LevelIDs_SandOcean, { 1571, 30, -3760 });
    outPipeChecks[PipeCheck::PC_SandOcean_Pipe_3] = PipeCheckData(0x01DEE99F, LevelIDs_SandOcean, { 2691, -61, -3794 });
    outPipeChecks[PipeCheck::PC_SandOcean_Pipe_4] = PipeCheckData(0x01DEE9A0, LevelIDs_SandOcean, { 3411, 30, -4353 });
    outPipeChecks[PipeCheck::PC_SandOcean_Pipe_5] = PipeCheckData(0x01DEE9A1, LevelIDs_SandOcean, { 3540, -100, -6033 });

    outPipeChecks[PipeCheck::PC_CrazyGadget_Pipe_1] = PipeCheckData(0x01DEE9A2, LevelIDs_CrazyGadget, { 78, -31, -324 });
    outPipeChecks[PipeCheck::PC_CrazyGadget_Pipe_2] = PipeCheckData(0x01DEE9A3, LevelIDs_CrazyGadget, { -2908, 150, -660 });
    outPipeChecks[PipeCheck::PC_CrazyGadget_Pipe_3] = PipeCheckData(0x01DEE9A4, LevelIDs_CrazyGadget, { -4464, -618, -1603 });
    outPipeChecks[PipeCheck::PC_CrazyGadget_Pipe_4] = PipeCheckData(0x01DEE9A5, LevelIDs_CrazyGadget, { -10315, -1352, -5534 });

    outPipeChecks[PipeCheck::PC_HiddenBase_Pipe_1] = PipeCheckData(0x01DEE9A6, LevelIDs_HiddenBase, { -41, 110, -2944 });
    outPipeChecks[PipeCheck::PC_HiddenBase_Pipe_2] = PipeCheckData(0x01DEE9A7, LevelIDs_HiddenBase, { -3050, 300, -3296 });
    outPipeChecks[PipeCheck::PC_HiddenBase_Pipe_3] = PipeCheckData(0x01DEE9A8, LevelIDs_HiddenBase, { -3199, 250, -2979 });
    outPipeChecks[PipeCheck::PC_HiddenBase_Pipe_4] = PipeCheckData(0x01DEE9A9, LevelIDs_HiddenBase, { -4027, 560, -3374 });
    outPipeChecks[PipeCheck::PC_HiddenBase_Pipe_5] = PipeCheckData(0x01DEE9AA, LevelIDs_HiddenBase, { -4143, 610, -4428 });

    outPipeChecks[PipeCheck::PC_EternalEngine_Pipe_1] = PipeCheckData(0x01DEE9AB, LevelIDs_EternalEngine, { 249, -30, -1187 });
    outPipeChecks[PipeCheck::PC_EternalEngine_Pipe_2] = PipeCheckData(0x01DEE9AC, LevelIDs_EternalEngine, { 141, 597, -1838 });
    outPipeChecks[PipeCheck::PC_EternalEngine_Pipe_3] = PipeCheckData(0x01DEE9AD, LevelIDs_EternalEngine, { -2396, 936, -5835 });
    outPipeChecks[PipeCheck::PC_EternalEngine_Pipe_4] = PipeCheckData(0x01DEE9AE, LevelIDs_EternalEngine, { -1945, 335, -7964 });
    outPipeChecks[PipeCheck::PC_EternalEngine_Pipe_5] = PipeCheckData(0x01DEE9AF, LevelIDs_EternalEngine, { 234, -1827, -9190 });

    outPipeChecks[PipeCheck::PC_DeathChamber_Pipe_1] = PipeCheckData(0x01DEE9B0, LevelIDs_DeathChamber, { 577, 100, 514 });
    outPipeChecks[PipeCheck::PC_DeathChamber_Pipe_2] = PipeCheckData(0x01DEE9B1, LevelIDs_DeathChamber, { 570, 100, -500 });
    outPipeChecks[PipeCheck::PC_DeathChamber_Pipe_3] = PipeCheckData(0x01DEE9B2, LevelIDs_DeathChamber, { 1292, -30, -391 });

    outPipeChecks[PipeCheck::PC_EggQuarters_Pipe_1] = PipeCheckData(0x01DEE9B3, LevelIDs_EggQuarters, { 325, -31, 1207 });
    outPipeChecks[PipeCheck::PC_EggQuarters_Pipe_2] = PipeCheckData(0x01DEE9B4, LevelIDs_EggQuarters, { 2, 181, 273 });

    outPipeChecks[PipeCheck::PC_LostColony_Pipe_1] = PipeCheckData(0x01DEE9B5, LevelIDs_LostColony, { -418, -643, -652 });
    outPipeChecks[PipeCheck::PC_LostColony_Pipe_2] = PipeCheckData(0x01DEE9B6, LevelIDs_LostColony, { 585, -518, -2560 });

    outPipeChecks[PipeCheck::PC_PyramidCave_Pipe_1] = PipeCheckData(0x01DEE9B7, LevelIDs_PyramidCave, { -2595, -1880, -8302 });
    outPipeChecks[PipeCheck::PC_PyramidCave_Pipe_2] = PipeCheckData(0x01DEE9B8, LevelIDs_PyramidCave, { -2530, -1880, -8176 });
    outPipeChecks[PipeCheck::PC_PyramidCave_Pipe_3] = PipeCheckData(0x01DEE9B9, LevelIDs_PyramidCave, { -2597, -1731, -8548 });
    outPipeChecks[PipeCheck::PC_PyramidCave_Pipe_4] = PipeCheckData(0x01DEE9BA, LevelIDs_PyramidCave, { -2521, -1730, -8549 });

    outPipeChecks[PipeCheck::PC_FinalRush_Pipe_1] = PipeCheckData(0x01DEE9BB, LevelIDs_FinalRush, { 4273, -3400, 3258 });
    outPipeChecks[PipeCheck::PC_FinalRush_Pipe_2] = PipeCheckData(0x01DEE9BC, LevelIDs_FinalRush, { 6427, -9675, 5440 });

    outPipeChecks[PipeCheck::PC_MeteorHerd_Pipe_1] = PipeCheckData(0x01DEE9BD, LevelIDs_MeteorHerd, { -525, -600, -876 });
    outPipeChecks[PipeCheck::PC_MeteorHerd_Pipe_2] = PipeCheckData(0x01DEE9BE, LevelIDs_MeteorHerd, { 451, -600, 1129 });
    outPipeChecks[PipeCheck::PC_MeteorHerd_Pipe_3] = PipeCheckData(0x01DEE9BF, LevelIDs_MeteorHerd, { 376, 707, 292 });

    outPipeChecks[PipeCheck::PC_CannonCore_Pipe_1] = PipeCheckData(0x01DEE9C0, LevelIDs_CannonsCoreT, { -1108, -919, -1540 });
    outPipeChecks[PipeCheck::PC_CannonCore_Pipe_2] = PipeCheckData(0x01DEE9C1, LevelIDs_CannonsCoreT, { -1822, -1299, -2559 });
    outPipeChecks[PipeCheck::PC_CannonCore_Pipe_3] = PipeCheckData(0x01DEE9C2, LevelIDs_CannonsCoreE, { 986, 120, -1877 });
    outPipeChecks[PipeCheck::PC_CannonCore_Pipe_4] = PipeCheckData(0x01DEE9C3, LevelIDs_CannonsCoreR, { -96, 144, 94 });
    outPipeChecks[PipeCheck::PC_CannonCore_Pipe_5] = PipeCheckData(0x01DEE9C4, LevelIDs_CannonsCoreS, { -461, -480, -2080 });

    outPipeChecks[PipeCheck::PC_FinalChase_Pipe_1] = PipeCheckData(0x01DEE9C5, LevelIDs_FinalChase, { 3687, -4225, 5395 });
    outPipeChecks[PipeCheck::PC_FinalChase_Pipe_2] = PipeCheckData(0x01DEE9C6, LevelIDs_FinalChase, { 4361, -5416, 10140 });
    outPipeChecks[PipeCheck::PC_FinalChase_Pipe_3] = PipeCheckData(0x01DEE9C7, LevelIDs_FinalChase, { 1481, -7614, 18249 });

    outPipeChecks[PipeCheck::PC_CosmicWall_Pipe_1] = PipeCheckData(0x01DEE9C8, LevelIDs_CosmicWall, { 603, 250, 29 });
    outPipeChecks[PipeCheck::PC_CosmicWall_Pipe_2] = PipeCheckData(0x01DEE9C9, LevelIDs_CosmicWall, { 3774, 2660, -889 });
    outPipeChecks[PipeCheck::PC_CosmicWall_Pipe_3] = PipeCheckData(0x01DEE9CA, LevelIDs_CosmicWall, { 4302, 3167, -928 });
    outPipeChecks[PipeCheck::PC_CosmicWall_Pipe_4] = PipeCheckData(0x01DEE9CB, LevelIDs_CosmicWall, { 5523, 3167, 3538 });
    outPipeChecks[PipeCheck::PC_CosmicWall_Pipe_5] = PipeCheckData(0x01DEE9CC, LevelIDs_CosmicWall, { 6123, 2800, 7977 });

    outPipeChecks[PipeCheck::PC_MadSpace_Pipe_1] = PipeCheckData(0x01DEE9CD, LevelIDs_MadSpace, { -133, 327, -79 });
    outPipeChecks[PipeCheck::PC_MadSpace_Pipe_2] = PipeCheckData(0x01DEE9CE, LevelIDs_MadSpace, { 1182, 188, -405 });
    outPipeChecks[PipeCheck::PC_MadSpace_Pipe_3] = PipeCheckData(0x01DEE9CF, LevelIDs_MadSpace, { 570, 3950, 866 });
    outPipeChecks[PipeCheck::PC_MadSpace_Pipe_4] = PipeCheckData(0x01DEE9D0, LevelIDs_MadSpace, { 530, 4098, -426 });
}

void InitializeHiddenChecks(std::map<int, HiddenCheckData>& outHiddenChecks)
{
    outHiddenChecks.clear();

    outHiddenChecks[HiddenCheck::HC_GreenForest_Hidden_1] = HiddenCheckData(0x01DEE9D1, LevelIDs_GreenForest, { 4537, -850, 5156 });
    outHiddenChecks[HiddenCheck::HC_GreenForest_Hidden_2] = HiddenCheckData(0x01DEE9D2, LevelIDs_GreenForest, { 6040, -1884, 7530 });
    outHiddenChecks[HiddenCheck::HC_GreenForest_Hidden_3] = HiddenCheckData(0x01DEE9D3, LevelIDs_GreenForest, { 6209, -1729, 7482 });
    outHiddenChecks[HiddenCheck::HC_GreenForest_Hidden_4] = HiddenCheckData(0x01DEE9D4, LevelIDs_GreenForest, { 8253, -1797, 7933 });

    outHiddenChecks[HiddenCheck::HC_WhiteJungle_Hidden_1] = HiddenCheckData(0x01DEE9D5, LevelIDs_WhiteJungle, { 160, -1704, 1517 });
    outHiddenChecks[HiddenCheck::HC_WhiteJungle_Hidden_2] = HiddenCheckData(0x01DEE9D6, LevelIDs_WhiteJungle, { 5703, -2212, -1518 });
    outHiddenChecks[HiddenCheck::HC_WhiteJungle_Hidden_3] = HiddenCheckData(0x01DEE9D7, LevelIDs_WhiteJungle, { 13430, -3587, -6092 });

    outHiddenChecks[HiddenCheck::HC_PumpkinHill_Hidden_1] = HiddenCheckData(0x01DEE9D8, LevelIDs_PumpkinHill, { 901, -1000, -700 });

    outHiddenChecks[HiddenCheck::HC_SecurityHall_Hidden_1] = HiddenCheckData(0x01DEE9D9, LevelIDs_SecurityHall, { -320, 264, -215 });

    outHiddenChecks[HiddenCheck::HC_PrisonLane_Hidden_1] = HiddenCheckData(0x01DEE9DA, LevelIDs_PrisonLane, { -2483, 630, -527 });
    outHiddenChecks[HiddenCheck::HC_PrisonLane_Hidden_2] = HiddenCheckData(0x01DEE9DB, LevelIDs_PrisonLane, { -3450, 729, 40 });
    outHiddenChecks[HiddenCheck::HC_PrisonLane_Hidden_3] = HiddenCheckData(0x01DEE9DC, LevelIDs_PrisonLane, { -4361, 885, -336 });

    outHiddenChecks[HiddenCheck::HC_CityEscape_Hidden_1] = HiddenCheckData(0x01DEE9DD, LevelIDs_CityEscape, { 4702, -10030, 4708 });
    outHiddenChecks[HiddenCheck::HC_CityEscape_Hidden_2] = HiddenCheckData(0x01DEE9DE, LevelIDs_CityEscape, { 5727, -10740, 4362 });
    outHiddenChecks[HiddenCheck::HC_CityEscape_Hidden_3] = HiddenCheckData(0x01DEE9DF, LevelIDs_CityEscape, { 7670, -14555, 5615 });
    outHiddenChecks[HiddenCheck::HC_CityEscape_Hidden_4] = HiddenCheckData(0x01DEE9E0, LevelIDs_CityEscape, { 7709, -14455, 6186 });
    outHiddenChecks[HiddenCheck::HC_CityEscape_Hidden_5] = HiddenCheckData(0x01DEE9E1, LevelIDs_CityEscape, { 3843, -22175, 16175 });

    outHiddenChecks[HiddenCheck::HC_RadicalHighway_Hidden_1] = HiddenCheckData(0x01DEE9E2, LevelIDs_RadicalHighway, { -69, 0, -1332 });
    outHiddenChecks[HiddenCheck::HC_RadicalHighway_Hidden_2] = HiddenCheckData(0x01DEE9E3, LevelIDs_RadicalHighway, { -7380, -5115, -11962 });
    outHiddenChecks[HiddenCheck::HC_RadicalHighway_Hidden_3] = HiddenCheckData(0x01DEE9E4, LevelIDs_RadicalHighway, { -9074, -7008, -15726 });

    outHiddenChecks[HiddenCheck::HC_MissionStreet_Hidden_1] = HiddenCheckData(0x01DEE9E5, LevelIDs_MissionStreet, { 69, -7, -131 });
    outHiddenChecks[HiddenCheck::HC_MissionStreet_Hidden_2] = HiddenCheckData(0x01DEE9E6, LevelIDs_MissionStreet, { 276, -7, -863 });
    outHiddenChecks[HiddenCheck::HC_MissionStreet_Hidden_3] = HiddenCheckData(0x01DEE9E7, LevelIDs_MissionStreet, { 5010, 598, -5505 });
    outHiddenChecks[HiddenCheck::HC_MissionStreet_Hidden_4] = HiddenCheckData(0x01DEE9F0, LevelIDs_MissionStreet, { 5993, 598, -6198 });

    outHiddenChecks[HiddenCheck::HC_DryLagoon_Hidden_1] = HiddenCheckData(0x01DEE9E8, LevelIDs_DryLagoon, { 210, 211, 1312 });

    outHiddenChecks[HiddenCheck::HC_CrazyGadget_Hidden_1] = HiddenCheckData(0x01DEE9E9, LevelIDs_CrazyGadget, { -6009, -1238, -3258 });

    outHiddenChecks[HiddenCheck::HC_DeathChamber_Hidden_1] = HiddenCheckData(0x01DEE9EA, LevelIDs_DeathChamber, { 1024, -31, -564 });
    outHiddenChecks[HiddenCheck::HC_DeathChamber_Hidden_2] = HiddenCheckData(0x01DEE9EB, LevelIDs_DeathChamber, { -661, -31, 935 });

    outHiddenChecks[HiddenCheck::HC_EggQuarters_Hidden_1] = HiddenCheckData(0x01DEE9EC, LevelIDs_EggQuarters, { 980, -31, 605 });
    outHiddenChecks[HiddenCheck::HC_EggQuarters_Hidden_2] = HiddenCheckData(0x01DEE9ED, LevelIDs_EggQuarters, { -1000, -1, 1001 });

    outHiddenChecks[HiddenCheck::HC_LostColony_Hidden_1] = HiddenCheckData(0x01DEE9EE, LevelIDs_LostColony, { -1518, -784, -1383 });

    outHiddenChecks[HiddenCheck::HC_CannonCore_Hidden_1] = HiddenCheckData(0x01DEE9EF, LevelIDs_CannonsCoreR, { 0, -61, -991 });
}

void InitializeGoldBeetleChecks(std::map<int, GoldBeetleCheckData>& outGoldBeetleChecks)
{
    outGoldBeetleChecks.clear();

    outGoldBeetleChecks[GoldBeetleCheck::GBC_GreenForest_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA34, LevelIDs_GreenForest);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_WhiteJungle_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA35, LevelIDs_WhiteJungle);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_SkyRail_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA37, LevelIDs_SkyRail);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_AquaticMine_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA38, LevelIDs_AquaticMine);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_SecurityHall_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA39, LevelIDs_SecurityHall);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_PrisonLane_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA3A, LevelIDs_PrisonLane);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_MetalHarbor_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA3B, LevelIDs_MetalHarbor);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_IronGate_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA3C, LevelIDs_IronGate);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_CityEscape_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA3E, LevelIDs_CityEscape);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_RadicalHighway_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA3F, LevelIDs_RadicalHighway);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_WildCanyon_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA40, LevelIDs_WildCanyon);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_MissionStreet_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA41, LevelIDs_MissionStreet);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_DryLagoon_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA42, LevelIDs_DryLagoon);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_SandOcean_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA43, LevelIDs_SandOcean);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_CrazyGadget_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA44, LevelIDs_CrazyGadget);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_HiddenBase_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA45, LevelIDs_HiddenBase);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_EternalEngine_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA46, LevelIDs_EternalEngine);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_DeathChamber_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA47, LevelIDs_DeathChamber);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_EggQuarters_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA48, LevelIDs_EggQuarters);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_LostColony_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA49, LevelIDs_LostColony);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_PyramidCave_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA4A, LevelIDs_PyramidCave);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_FinalRush_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA4B, LevelIDs_FinalRush);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_MeteorHerd_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA4C, LevelIDs_MeteorHerd);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_CannonCore_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA4D, LevelIDs_CannonsCoreS);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_FinalChase_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA4E, LevelIDs_FinalChase);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_CosmicWall_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA4F, LevelIDs_CosmicWall);
    outGoldBeetleChecks[GoldBeetleCheck::GBC_MadSpace_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA50, LevelIDs_MadSpace);
}

void InitializeOmochaoChecks(std::map<int, OmochaoCheckData>& outOmochaoChecks)
{
    outOmochaoChecks.clear();

    int memoryAddress = 0x01DEEC80;

    outOmochaoChecks[OmochaoCheck::OC_WhiteJungle_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_WhiteJungle, { 2137, -1301, 1122 });
    outOmochaoChecks[OmochaoCheck::OC_WhiteJungle_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_WhiteJungle, { 4219, -2190, -556 });
    outOmochaoChecks[OmochaoCheck::OC_WhiteJungle_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_WhiteJungle, { 9108, -3141, -5092 });
    outOmochaoChecks[OmochaoCheck::OC_WhiteJungle_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_WhiteJungle, { 9049, -3414, -5100 });
    outOmochaoChecks[OmochaoCheck::OC_WhiteJungle_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_WhiteJungle, { 13252, -3600, -5552 });

    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_1]  = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { 208, -1362, -1059 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_2]  = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { 791, -1362, -1189 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_3]  = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { 375, -1362, -1563 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_4]  = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { -192, -1362, -367 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_5]  = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { -61, -250, -125 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_6]  = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { -1, -146, 14 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_7]  = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { 187, -920, 126 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_8]  = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { 345, -986, -513 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_9]  = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { -91, -654, -1751 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_10] = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { 14, -830, -1809 });
    outOmochaoChecks[OmochaoCheck::OC_PumpkinHill_Omochao_11] = OmochaoCheckData(memoryAddress++, LevelIDs_PumpkinHill, { 881, -730, -1048 });

    outOmochaoChecks[OmochaoCheck::OC_AquaticMine_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_AquaticMine, { 26, 130, -365 }, 30.0f);
    outOmochaoChecks[OmochaoCheck::OC_AquaticMine_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_AquaticMine, { -29, 130, -365 }, 30.0f);
    outOmochaoChecks[OmochaoCheck::OC_AquaticMine_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_AquaticMine, { -4, 310, -79 });
    outOmochaoChecks[OmochaoCheck::OC_AquaticMine_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_AquaticMine, { 9, -80, 248 });
    outOmochaoChecks[OmochaoCheck::OC_AquaticMine_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_AquaticMine, { 250, -80, -70 });
    outOmochaoChecks[OmochaoCheck::OC_AquaticMine_Omochao_6] = OmochaoCheckData(memoryAddress++, LevelIDs_AquaticMine, { 109, -80, -249 });
    outOmochaoChecks[OmochaoCheck::OC_AquaticMine_Omochao_7] = OmochaoCheckData(memoryAddress++, LevelIDs_AquaticMine, { 325, -420, -672 });

    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_1]  = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { 333, -933, 366 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_2]  = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { -5, -933, 198 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_3]  = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { -330, -933, 500 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_4]  = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { -181, -753, 537 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_5]  = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { 453, -573, 506 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_6]  = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { -470, -524, 517 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_7]  = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { 437, -596, 110 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_8]  = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { 143, -713, -27 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_9]  = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { -21, -525, 236 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_10] = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { -1, -143, 305 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_11] = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { 304, -143, 216 });
    outOmochaoChecks[OmochaoCheck::OC_SecurityHall_Omochao_12] = OmochaoCheckData(memoryAddress++, LevelIDs_SecurityHall, { -42, 27, -92 });

    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_1]  = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { 63, -3, -15 });
    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_2]  = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { 124, -3, 217 });
    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_3]  = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { -456, -3, 12 });
    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_4]  = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { -366, 96, 541 });
    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_5]  = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { -1146, 177, 572 });
    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_6]  = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { -1148, 237, 347 });
    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_7]  = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { -1501, 236, -161 });
    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_8]  = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { -1629, 237, -472 });
    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_9]  = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { -2550, 630, -632 });
    outOmochaoChecks[OmochaoCheck::OC_PrisonLane_Omochao_10] = OmochaoCheckData(memoryAddress++, LevelIDs_PrisonLane, { -4482, 870, -438 });

    outOmochaoChecks[OmochaoCheck::OC_MetalHarbor_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_MetalHarbor, { 2107, -270, -2875 });
    outOmochaoChecks[OmochaoCheck::OC_MetalHarbor_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_MetalHarbor, { 2088, -220, -3428 });
    outOmochaoChecks[OmochaoCheck::OC_MetalHarbor_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_MetalHarbor, { 2004, -21, -3313 });
    outOmochaoChecks[OmochaoCheck::OC_MetalHarbor_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_MetalHarbor, { 3240, -225, -7115 });
    outOmochaoChecks[OmochaoCheck::OC_MetalHarbor_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_MetalHarbor, { 4763, -181, -9839 });

    outOmochaoChecks[OmochaoCheck::OC_IronGate_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_IronGate, { 137, -270, -2 });
    outOmochaoChecks[OmochaoCheck::OC_IronGate_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_IronGate, { 579, -270, -290 });
    outOmochaoChecks[OmochaoCheck::OC_IronGate_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_IronGate, { 788, -270, -671 });
    outOmochaoChecks[OmochaoCheck::OC_IronGate_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_IronGate, { 1115, -270, -700 });
    outOmochaoChecks[OmochaoCheck::OC_IronGate_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_IronGate, { 4811, -1366, -770 });
    outOmochaoChecks[OmochaoCheck::OC_IronGate_Omochao_6] = OmochaoCheckData(memoryAddress++, LevelIDs_IronGate, { 5404, -1421, -1202 });

    outOmochaoChecks[OmochaoCheck::OC_WeaponsBed_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_WeaponsBed, { -41, -160, -1906 }, 80.0f);
    outOmochaoChecks[OmochaoCheck::OC_WeaponsBed_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_WeaponsBed, { 15, -130, -2033 }, 100.0f);
    outOmochaoChecks[OmochaoCheck::OC_WeaponsBed_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_WeaponsBed, { 898, -220, -3277 });

    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_1]  = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { -1383, -6260, 9362 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_2]  = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { -767, -6365, 9802 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_3]  = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { -546, -6270, 9989 }, 90.0f);
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_4]  = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { -410, -6270, 9995 }, 90.0f);
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_5]  = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 382, -6570, 9963 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_6]  = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 349, -6470, 9623 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_7]  = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 2048, -9005, 6426 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_8]  = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 2829, -8555, 6418 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_9]  = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 5743, -10740, 4358 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_10] = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 6016, -10690, 4414 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_11] = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 7588, -14455, 6176 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_12] = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 7600, -14355, 6316 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_13] = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 6412, -15915, 9139 });
    outOmochaoChecks[OmochaoCheck::OC_CityEscape_Omochao_14] = OmochaoCheckData(memoryAddress++, LevelIDs_CityEscape, { 3830, -22175, 16165 });

    outOmochaoChecks[OmochaoCheck::OC_RadicalHighway_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_RadicalHighway, { -1249, -820, -4067 });
    outOmochaoChecks[OmochaoCheck::OC_RadicalHighway_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_RadicalHighway, { -1078, -670, -4378 });
    outOmochaoChecks[OmochaoCheck::OC_RadicalHighway_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_RadicalHighway, { -2964, -472, -4481 });
    outOmochaoChecks[OmochaoCheck::OC_RadicalHighway_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_RadicalHighway, { -5373, -2761, -4311 });
    outOmochaoChecks[OmochaoCheck::OC_RadicalHighway_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_RadicalHighway, { -6341, -4915, -8991 });
    outOmochaoChecks[OmochaoCheck::OC_RadicalHighway_Omochao_6] = OmochaoCheckData(memoryAddress++, LevelIDs_RadicalHighway, { -6355, -5115, -9959 });
    outOmochaoChecks[OmochaoCheck::OC_RadicalHighway_Omochao_7] = OmochaoCheckData(memoryAddress++, LevelIDs_RadicalHighway, { -6214, -4515, -10070 });
    outOmochaoChecks[OmochaoCheck::OC_RadicalHighway_Omochao_8] = OmochaoCheckData(memoryAddress++, LevelIDs_RadicalHighway, { -6444, -4515, -10070 });

    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_1]  = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { 200, 65, -350 });
    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_2]  = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { 200, 0, -150 });
    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_3]  = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { 392, 14, 185 });
    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_4]  = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { -16, 127, 259 });
    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_5]  = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { 222, 457, 298 });
    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_6]  = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { 61, 650, 2 });
    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_7]  = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { 184, 856, 144 });
    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_8]  = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { -373, 927, -23 });
    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_9]  = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { 462, 1010, -65 });
    outOmochaoChecks[OmochaoCheck::OC_WildCanyon_Omochao_10] = OmochaoCheckData(memoryAddress++, LevelIDs_WildCanyon, { 1147, 927, 12 });

    outOmochaoChecks[OmochaoCheck::OC_MissionStreet_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_MissionStreet, { -302, -8, -1974 });
    outOmochaoChecks[OmochaoCheck::OC_MissionStreet_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_MissionStreet, { -1284, -166, -2089 });
    outOmochaoChecks[OmochaoCheck::OC_MissionStreet_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_MissionStreet, { -1221, 35, -2614 });
    outOmochaoChecks[OmochaoCheck::OC_MissionStreet_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_MissionStreet, { 257, 200, -3420 });
    outOmochaoChecks[OmochaoCheck::OC_MissionStreet_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_MissionStreet, { 3268, 199, -3421 });
    outOmochaoChecks[OmochaoCheck::OC_MissionStreet_Omochao_6] = OmochaoCheckData(memoryAddress++, LevelIDs_MissionStreet, { 3381, 349, -3713 });
    outOmochaoChecks[OmochaoCheck::OC_MissionStreet_Omochao_7] = OmochaoCheckData(memoryAddress++, LevelIDs_MissionStreet, { 4998, 598, -5078 });
    outOmochaoChecks[OmochaoCheck::OC_MissionStreet_Omochao_8] = OmochaoCheckData(memoryAddress++, LevelIDs_MissionStreet, { 5739, 598, -6284 });

    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_1]  = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 200, 65, -370 });
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_2]  = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 200, 15, 0 });
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_3]  = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 280, 40, 429 });
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_4]  = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 190, 170, -66 });
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_5]  = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { -106, 170, -112 });
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_6]  = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 193, 457, 307 });
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_7]  = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 72, 203, 1347 }, 100.0f);
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_8]  = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 195, 224, 1619 }, 70.0f);
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_9]  = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 182, 89, 1665 });
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_10] = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 86, 200, 949 });
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_11] = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { 1069, 310, 1410 });
    outOmochaoChecks[OmochaoCheck::OC_DryLagoon_Omochao_12] = OmochaoCheckData(memoryAddress++, LevelIDs_DryLagoon, { -319, 281, 1417 });

    outOmochaoChecks[OmochaoCheck::OC_SandOcean_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_SandOcean, { -15, 30, -195 });
    outOmochaoChecks[OmochaoCheck::OC_SandOcean_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_SandOcean, { -26, 80, -1330 });

    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_1]  = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { 21, -30, 149 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_2]  = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -120, -30, -424 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_3]  = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -817, -140, -421 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_4]  = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -1816, -129, -450 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_5]  = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -1945, 479, -388 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_6]  = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -2884, 150, -578 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_7]  = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -3500, 152, -530 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_8]  = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -3671, 150, -579 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_9]  = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -4405, -1138, -3205 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_10] = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -5235, -1247, -3237 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_11] = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -8945, -965, -3835 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_12] = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -11051, -1227, -3042 });
    outOmochaoChecks[OmochaoCheck::OC_CrazyGadget_Omochao_13] = OmochaoCheckData(memoryAddress++, LevelIDs_CrazyGadget, { -8713, -1097, -2884 });

    outOmochaoChecks[OmochaoCheck::OC_HiddenBase_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_HiddenBase, { -13, 80, -64 });
    outOmochaoChecks[OmochaoCheck::OC_HiddenBase_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_HiddenBase, { -35, 50, -713 });
    outOmochaoChecks[OmochaoCheck::OC_HiddenBase_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_HiddenBase, { -1, 80, -1137 });
    outOmochaoChecks[OmochaoCheck::OC_HiddenBase_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_HiddenBase, { -3881, 920, -4985 });

    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_1]  = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { 261, 578, -2058 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_2]  = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -959, 578, -2254 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_3]  = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -692, 578, -2500 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_4]  = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -623, 578, -3184 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_5]  = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -629, 578, -3831 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_6]  = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -618, 178, -4664 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_7]  = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -626, 786, -4889 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_8]  = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -2106, 946, -7877 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_9]  = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -2099, 336, -7767 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_10] = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -2033, 336, -8033 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_11] = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -1733, 944, -9128 });
    outOmochaoChecks[OmochaoCheck::OC_EternalEngine_Omochao_12] = OmochaoCheckData(memoryAddress++, LevelIDs_EternalEngine, { -132, 966, -9171 });

    outOmochaoChecks[OmochaoCheck::OC_DeathChamber_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_DeathChamber, { 827, 20, 799 });
    outOmochaoChecks[OmochaoCheck::OC_DeathChamber_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_DeathChamber, { 952, -30, 628 });
    outOmochaoChecks[OmochaoCheck::OC_DeathChamber_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_DeathChamber, { 718, 20, 608 });
    outOmochaoChecks[OmochaoCheck::OC_DeathChamber_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_DeathChamber, { -130, 100, -130 });
    outOmochaoChecks[OmochaoCheck::OC_DeathChamber_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_DeathChamber, { -941, -130, 448 });
    outOmochaoChecks[OmochaoCheck::OC_DeathChamber_Omochao_6] = OmochaoCheckData(memoryAddress++, LevelIDs_DeathChamber, { -350, -30, 830 });
    outOmochaoChecks[OmochaoCheck::OC_DeathChamber_Omochao_7] = OmochaoCheckData(memoryAddress++, LevelIDs_DeathChamber, { 1300, 60, 1790 });
    outOmochaoChecks[OmochaoCheck::OC_DeathChamber_Omochao_8] = OmochaoCheckData(memoryAddress++, LevelIDs_DeathChamber, { 251, 150, -278 });
    outOmochaoChecks[OmochaoCheck::OC_DeathChamber_Omochao_9] = OmochaoCheckData(memoryAddress++, LevelIDs_DeathChamber, { -200, -280, -200 });

    outOmochaoChecks[OmochaoCheck::OC_EggQuarters_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_EggQuarters, { 886, -10, 870 }, 70.0f);
    outOmochaoChecks[OmochaoCheck::OC_EggQuarters_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_EggQuarters, { 792, 20, 791 }, 70.0f);
    outOmochaoChecks[OmochaoCheck::OC_EggQuarters_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_EggQuarters, { -382, -30, 1295 });
    outOmochaoChecks[OmochaoCheck::OC_EggQuarters_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_EggQuarters, { -828, 20, 824 });
    outOmochaoChecks[OmochaoCheck::OC_EggQuarters_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_EggQuarters, { -2, 70, 219 });
    outOmochaoChecks[OmochaoCheck::OC_EggQuarters_Omochao_6] = OmochaoCheckData(memoryAddress++, LevelIDs_EggQuarters, { -150, 110, 473 });
    outOmochaoChecks[OmochaoCheck::OC_EggQuarters_Omochao_7] = OmochaoCheckData(memoryAddress++, LevelIDs_EggQuarters, { 148, 110, 474 });

    outOmochaoChecks[OmochaoCheck::OC_LostColony_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_LostColony, { 30, -35, -194 });
    outOmochaoChecks[OmochaoCheck::OC_LostColony_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_LostColony, { -1426, -643, -719 });
    outOmochaoChecks[OmochaoCheck::OC_LostColony_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_LostColony, { -1375, -793, -1471 });
    outOmochaoChecks[OmochaoCheck::OC_LostColony_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_LostColony, { -1573, -633, -2031 }, 100.0f);
    outOmochaoChecks[OmochaoCheck::OC_LostColony_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_LostColony, { -1656, -568, -2142 }, 100.0f);
    outOmochaoChecks[OmochaoCheck::OC_LostColony_Omochao_6] = OmochaoCheckData(memoryAddress++, LevelIDs_LostColony, { 560, -518, -2290 });
    outOmochaoChecks[OmochaoCheck::OC_LostColony_Omochao_7] = OmochaoCheckData(memoryAddress++, LevelIDs_LostColony, { 3289, 1911, -2374 });
    outOmochaoChecks[OmochaoCheck::OC_LostColony_Omochao_8] = OmochaoCheckData(memoryAddress++, LevelIDs_LostColony, { 4026, 1552, -2442 });

    outOmochaoChecks[OmochaoCheck::OC_PyramidCave_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_PyramidCave, { -1, -1920, -6327 });
    outOmochaoChecks[OmochaoCheck::OC_PyramidCave_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_PyramidCave, { -2560, -1680, -9021 });
    outOmochaoChecks[OmochaoCheck::OC_PyramidCave_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_PyramidCave, { -2482, -2240, -10997 });
    outOmochaoChecks[OmochaoCheck::OC_PyramidCave_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_PyramidCave, { -2561, -2260, -12000 });

    outOmochaoChecks[OmochaoCheck::OC_FinalRush_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_FinalRush, { 3304, -975, -20 });
    outOmochaoChecks[OmochaoCheck::OC_FinalRush_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_FinalRush, { 4323 ,-1735, 1222 });
    outOmochaoChecks[OmochaoCheck::OC_FinalRush_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_FinalRush, { 6755, -14795, 13765 });

    outOmochaoChecks[OmochaoCheck::OC_MeteorHerd_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_MeteorHerd, { 1, -500, -887 });
    outOmochaoChecks[OmochaoCheck::OC_MeteorHerd_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_MeteorHerd, { 0, -600, -382 });
    outOmochaoChecks[OmochaoCheck::OC_MeteorHerd_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_MeteorHerd, { 25, 1025, 441 });

    outOmochaoChecks[OmochaoCheck::OC_CannonCore_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_CannonsCoreT, { -70, -30, -527 });
    outOmochaoChecks[OmochaoCheck::OC_CannonCore_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_CannonsCoreT, { -700, -638, -1128 });
    outOmochaoChecks[OmochaoCheck::OC_CannonCore_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_CannonsCoreT, { -1065, -638, -1564 });
    outOmochaoChecks[OmochaoCheck::OC_CannonCore_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_CannonsCoreE, { 58, -30, -1600 });
    outOmochaoChecks[OmochaoCheck::OC_CannonCore_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_CannonsCoreR, { 9, 19, 108 });
    outOmochaoChecks[OmochaoCheck::OC_CannonCore_Omochao_6] = OmochaoCheckData(memoryAddress++, LevelIDs_CannonsCoreK, { -17, 660, -204 });
    outOmochaoChecks[OmochaoCheck::OC_CannonCore_Omochao_7] = OmochaoCheckData(memoryAddress++, LevelIDs_CannonsCoreK, { -8, 355, -910 });
    outOmochaoChecks[OmochaoCheck::OC_CannonCore_Omochao_8] = OmochaoCheckData(memoryAddress++, LevelIDs_CannonsCoreS, { 340, -480, -1764 });
    outOmochaoChecks[OmochaoCheck::OC_CannonCore_Omochao_9] = OmochaoCheckData(memoryAddress++, LevelIDs_CannonsCoreS, { -549, -530, -2470 });

    outOmochaoChecks[OmochaoCheck::OC_FinalChase_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_FinalChase, { 3174, -4775, 3191 });

    outOmochaoChecks[OmochaoCheck::OC_CosmicWall_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_CosmicWall, { 73, 0, 0 });

    outOmochaoChecks[OmochaoCheck::OC_MadSpace_Omochao_1] = OmochaoCheckData(memoryAddress++, LevelIDs_MadSpace, { -75, 620, 43 });
    outOmochaoChecks[OmochaoCheck::OC_MadSpace_Omochao_2] = OmochaoCheckData(memoryAddress++, LevelIDs_MadSpace, { 240, 620, 138 });
    outOmochaoChecks[OmochaoCheck::OC_MadSpace_Omochao_3] = OmochaoCheckData(memoryAddress++, LevelIDs_MadSpace, { -437, 1528, -600 });
    outOmochaoChecks[OmochaoCheck::OC_MadSpace_Omochao_4] = OmochaoCheckData(memoryAddress++, LevelIDs_MadSpace, { -268, 2202, 614 });
    outOmochaoChecks[OmochaoCheck::OC_MadSpace_Omochao_5] = OmochaoCheckData(memoryAddress++, LevelIDs_MadSpace, { 548, 2286, -505 });
}

void InitializeAnimalChecks(std::map<int, AnimalCheckData>& outAnimalChecks)
{
    outAnimalChecks.clear();

    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_1]  = AnimalCheckData(0x01DEED44, 0x00, 0x00, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_2]  = AnimalCheckData(0x01DEED44, 0x01, 0x01, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_3]  = AnimalCheckData(0x01DEED44, 0x02, 0x02, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_4]  = AnimalCheckData(0x01DEED44, 0x03, 0x03, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_5]  = AnimalCheckData(0x01DEED44, 0x04, 0x04, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_6]  = AnimalCheckData(0x01DEED44, 0x05, 0x05, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_7]  = AnimalCheckData(0x01DEED44, 0x06, 0x06, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_8]  = AnimalCheckData(0x01DEED44, 0x07, 0x07, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_9]  = AnimalCheckData(0x01DEED45, 0x00, 0x08, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_10] = AnimalCheckData(0x01DEED45, 0x01, 0x09, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_11] = AnimalCheckData(0x01DEED45, 0x02, 0x0A, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_12] = AnimalCheckData(0x01DEED45, 0x03, 0x0B, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_13] = AnimalCheckData(0x01DEED45, 0x04, 0x0C, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_14] = AnimalCheckData(0x01DEED45, 0x05, 0x0D, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_15] = AnimalCheckData(0x01DEED45, 0x06, 0x0E, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_16] = AnimalCheckData(0x01DEED45, 0x07, 0x0F, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_17] = AnimalCheckData(0x01DEED46, 0x00, 0x10, LevelIDs_GreenForest);
    outAnimalChecks[AnimalCheck::AC_GreenForest_Animal_18] = AnimalCheckData(0x01DEED46, 0x01, 0x11, LevelIDs_GreenForest);

    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_1]  = AnimalCheckData(0x01DEED47, 0x00, 0x00, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_2]  = AnimalCheckData(0x01DEED47, 0x01, 0x01, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_3]  = AnimalCheckData(0x01DEED47, 0x02, 0x02, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_4]  = AnimalCheckData(0x01DEED47, 0x03, 0x03, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_5]  = AnimalCheckData(0x01DEED47, 0x04, 0x04, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_6]  = AnimalCheckData(0x01DEED47, 0x05, 0x05, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_7]  = AnimalCheckData(0x01DEED47, 0x06, 0x06, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_8]  = AnimalCheckData(0x01DEED47, 0x07, 0x07, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_9]  = AnimalCheckData(0x01DEED48, 0x00, 0x08, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_10] = AnimalCheckData(0x01DEED48, 0x01, 0x09, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_11] = AnimalCheckData(0x01DEED48, 0x02, 0x0A, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_12] = AnimalCheckData(0x01DEED48, 0x03, 0x0B, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_13] = AnimalCheckData(0x01DEED48, 0x04, 0x0C, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_14] = AnimalCheckData(0x01DEED48, 0x05, 0x0D, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_15] = AnimalCheckData(0x01DEED48, 0x06, 0x0E, LevelIDs_WhiteJungle);
    outAnimalChecks[AnimalCheck::AC_WhiteJungle_Animal_16] = AnimalCheckData(0x01DEED48, 0x07, 0x0F, LevelIDs_WhiteJungle);

    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_1]  = AnimalCheckData(0x01DEEDA0, 0x00, 0x00, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_2]  = AnimalCheckData(0x01DEEDA0, 0x01, 0x01, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_3]  = AnimalCheckData(0x01DEEDA0, 0x02, 0x02, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_4]  = AnimalCheckData(0x01DEEDA0, 0x03, 0x03, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_5]  = AnimalCheckData(0x01DEEDA0, 0x04, 0x04, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_6]  = AnimalCheckData(0x01DEEDA0, 0x05, 0x05, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_7]  = AnimalCheckData(0x01DEEDA0, 0x06, 0x06, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_8]  = AnimalCheckData(0x01DEEDA0, 0x07, 0x07, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_9]  = AnimalCheckData(0x01DEEDA1, 0x00, 0x08, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_10] = AnimalCheckData(0x01DEEDA1, 0x01, 0x09, LevelIDs_PumpkinHill);
    outAnimalChecks[AnimalCheck::AC_PumpkinHill_Animal_11] = AnimalCheckData(0x01DEEDA1, 0x02, 0x0A, LevelIDs_PumpkinHill);

    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_1]  = AnimalCheckData(0x01DEED4A, 0x00, 0x00, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_2]  = AnimalCheckData(0x01DEED4A, 0x01, 0x01, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_3]  = AnimalCheckData(0x01DEED4A, 0x02, 0x02, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_4]  = AnimalCheckData(0x01DEED4A, 0x03, 0x03, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_5]  = AnimalCheckData(0x01DEED4A, 0x04, 0x04, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_6]  = AnimalCheckData(0x01DEED4A, 0x05, 0x05, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_7]  = AnimalCheckData(0x01DEED4A, 0x06, 0x06, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_8]  = AnimalCheckData(0x01DEED4A, 0x07, 0x07, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_9]  = AnimalCheckData(0x01DEED4B, 0x00, 0x08, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_10] = AnimalCheckData(0x01DEED4B, 0x01, 0x09, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_11] = AnimalCheckData(0x01DEED4B, 0x02, 0x0A, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_12] = AnimalCheckData(0x01DEED4B, 0x03, 0x0B, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_13] = AnimalCheckData(0x01DEED4B, 0x04, 0x0C, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_14] = AnimalCheckData(0x01DEED4B, 0x05, 0x0D, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_15] = AnimalCheckData(0x01DEED4B, 0x06, 0x0E, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_16] = AnimalCheckData(0x01DEED4B, 0x07, 0x0F, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_17] = AnimalCheckData(0x01DEED4C, 0x00, 0x10, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_18] = AnimalCheckData(0x01DEED4C, 0x01, 0x11, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_19] = AnimalCheckData(0x01DEED4C, 0x02, 0x12, LevelIDs_SkyRail);
    outAnimalChecks[AnimalCheck::AC_SkyRail_Animal_20] = AnimalCheckData(0x01DEED4C, 0x03, 0x13, LevelIDs_SkyRail);

    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_1]  = AnimalCheckData(0x01DEED4D, 0x00, 0x00, LevelIDs_AquaticMine);
    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_2]  = AnimalCheckData(0x01DEED4D, 0x01, 0x01, LevelIDs_AquaticMine);
    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_3]  = AnimalCheckData(0x01DEED4D, 0x02, 0x02, LevelIDs_AquaticMine);
    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_4]  = AnimalCheckData(0x01DEED4D, 0x03, 0x03, LevelIDs_AquaticMine);
    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_5]  = AnimalCheckData(0x01DEED4D, 0x04, 0x04, LevelIDs_AquaticMine);
    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_6]  = AnimalCheckData(0x01DEED4D, 0x05, 0x05, LevelIDs_AquaticMine);
    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_7]  = AnimalCheckData(0x01DEED4D, 0x06, 0x06, LevelIDs_AquaticMine);
    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_8]  = AnimalCheckData(0x01DEED4D, 0x07, 0x07, LevelIDs_AquaticMine);
    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_9]  = AnimalCheckData(0x01DEED4E, 0x00, 0x08, LevelIDs_AquaticMine);
    outAnimalChecks[AnimalCheck::AC_AquaticMine_Animal_10] = AnimalCheckData(0x01DEED4E, 0x01, 0x09, LevelIDs_AquaticMine);
 
    outAnimalChecks[AnimalCheck::AC_SecurityHall_Animal_1] = AnimalCheckData(0x01DEED4F, 0x00, 0x00, LevelIDs_SecurityHall);
    outAnimalChecks[AnimalCheck::AC_SecurityHall_Animal_2] = AnimalCheckData(0x01DEED4F, 0x01, 0x01, LevelIDs_SecurityHall);
    outAnimalChecks[AnimalCheck::AC_SecurityHall_Animal_3] = AnimalCheckData(0x01DEED4F, 0x02, 0x02, LevelIDs_SecurityHall);
    outAnimalChecks[AnimalCheck::AC_SecurityHall_Animal_4] = AnimalCheckData(0x01DEED4F, 0x03, 0x03, LevelIDs_SecurityHall);
    outAnimalChecks[AnimalCheck::AC_SecurityHall_Animal_5] = AnimalCheckData(0x01DEED4F, 0x04, 0x04, LevelIDs_SecurityHall);
    outAnimalChecks[AnimalCheck::AC_SecurityHall_Animal_6] = AnimalCheckData(0x01DEED4F, 0x05, 0x05, LevelIDs_SecurityHall);
    outAnimalChecks[AnimalCheck::AC_SecurityHall_Animal_7] = AnimalCheckData(0x01DEED4F, 0x06, 0x06, LevelIDs_SecurityHall);
    outAnimalChecks[AnimalCheck::AC_SecurityHall_Animal_8] = AnimalCheckData(0x01DEED4F, 0x07, 0x07, LevelIDs_SecurityHall);

    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_1]  = AnimalCheckData(0x01DEED51, 0x00, 0x00, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_2]  = AnimalCheckData(0x01DEED51, 0x01, 0x01, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_3]  = AnimalCheckData(0x01DEED51, 0x02, 0x02, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_4]  = AnimalCheckData(0x01DEED51, 0x03, 0x03, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_5]  = AnimalCheckData(0x01DEED51, 0x04, 0x04, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_6]  = AnimalCheckData(0x01DEED51, 0x05, 0x05, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_7]  = AnimalCheckData(0x01DEED51, 0x06, 0x06, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_8]  = AnimalCheckData(0x01DEED51, 0x07, 0x07, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_9]  = AnimalCheckData(0x01DEED52, 0x00, 0x08, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_10] = AnimalCheckData(0x01DEED52, 0x01, 0x09, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_11] = AnimalCheckData(0x01DEED52, 0x02, 0x0A, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_12] = AnimalCheckData(0x01DEED52, 0x03, 0x0B, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_13] = AnimalCheckData(0x01DEED52, 0x04, 0x0C, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_14] = AnimalCheckData(0x01DEED52, 0x05, 0x0D, LevelIDs_PrisonLane);
    outAnimalChecks[AnimalCheck::AC_PrisonLane_Animal_15] = AnimalCheckData(0x01DEED52, 0x06, 0x0E, LevelIDs_PrisonLane);

    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_1]  = AnimalCheckData(0x01DEED53, 0x00, 0x00, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_2]  = AnimalCheckData(0x01DEED53, 0x01, 0x01, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_3]  = AnimalCheckData(0x01DEED53, 0x02, 0x02, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_4]  = AnimalCheckData(0x01DEED53, 0x03, 0x03, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_5]  = AnimalCheckData(0x01DEED53, 0x04, 0x04, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_6]  = AnimalCheckData(0x01DEED53, 0x05, 0x05, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_7]  = AnimalCheckData(0x01DEED53, 0x06, 0x06, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_8]  = AnimalCheckData(0x01DEED53, 0x07, 0x07, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_9]  = AnimalCheckData(0x01DEED54, 0x00, 0x08, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_10] = AnimalCheckData(0x01DEED54, 0x01, 0x09, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_11] = AnimalCheckData(0x01DEED54, 0x02, 0x0A, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_12] = AnimalCheckData(0x01DEED54, 0x03, 0x0B, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_13] = AnimalCheckData(0x01DEED54, 0x04, 0x0C, LevelIDs_MetalHarbor);
    outAnimalChecks[AnimalCheck::AC_MetalHarbor_Animal_14] = AnimalCheckData(0x01DEED54, 0x05, 0x0D, LevelIDs_MetalHarbor);

    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_1]  = AnimalCheckData(0x01DEED56, 0x00, 0x00, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_2]  = AnimalCheckData(0x01DEED56, 0x01, 0x01, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_3]  = AnimalCheckData(0x01DEED56, 0x02, 0x02, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_4]  = AnimalCheckData(0x01DEED56, 0x03, 0x03, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_5]  = AnimalCheckData(0x01DEED56, 0x04, 0x04, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_6]  = AnimalCheckData(0x01DEED56, 0x05, 0x05, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_7]  = AnimalCheckData(0x01DEED56, 0x06, 0x06, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_8]  = AnimalCheckData(0x01DEED56, 0x07, 0x07, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_9]  = AnimalCheckData(0x01DEED57, 0x00, 0x08, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_10] = AnimalCheckData(0x01DEED57, 0x01, 0x09, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_11] = AnimalCheckData(0x01DEED57, 0x02, 0x0A, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_12] = AnimalCheckData(0x01DEED57, 0x03, 0x0B, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_13] = AnimalCheckData(0x01DEED57, 0x04, 0x0C, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_14] = AnimalCheckData(0x01DEED57, 0x05, 0x0D, LevelIDs_IronGate);
    outAnimalChecks[AnimalCheck::AC_IronGate_Animal_15] = AnimalCheckData(0x01DEED57, 0x06, 0x0E, LevelIDs_IronGate);

    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_1]  = AnimalCheckData(0x01DEEDA2, 0x00, 0x00, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_2]  = AnimalCheckData(0x01DEEDA2, 0x01, 0x01, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_3]  = AnimalCheckData(0x01DEEDA2, 0x02, 0x02, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_4]  = AnimalCheckData(0x01DEEDA2, 0x03, 0x03, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_5]  = AnimalCheckData(0x01DEEDA2, 0x04, 0x04, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_6]  = AnimalCheckData(0x01DEEDA2, 0x05, 0x05, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_7]  = AnimalCheckData(0x01DEEDA2, 0x06, 0x06, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_8]  = AnimalCheckData(0x01DEEDA3, 0x07, 0x07, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_9]  = AnimalCheckData(0x01DEEDA3, 0x00, 0x08, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_10] = AnimalCheckData(0x01DEEDA3, 0x01, 0x09, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_11] = AnimalCheckData(0x01DEEDA3, 0x02, 0x0A, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_12] = AnimalCheckData(0x01DEEDA3, 0x03, 0x0B, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_13] = AnimalCheckData(0x01DEEDA3, 0x04, 0x0C, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_14] = AnimalCheckData(0x01DEEDA3, 0x05, 0x0D, LevelIDs_WeaponsBed);
    outAnimalChecks[AnimalCheck::AC_WeaponsBed_Animal_15] = AnimalCheckData(0x01DEEDA3, 0x06, 0x0E, LevelIDs_WeaponsBed);

    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_1]  = AnimalCheckData(0x01DEED58, 0x00, 0x00, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_2]  = AnimalCheckData(0x01DEED58, 0x01, 0x01, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_3]  = AnimalCheckData(0x01DEED58, 0x02, 0x02, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_4]  = AnimalCheckData(0x01DEED58, 0x03, 0x03, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_5]  = AnimalCheckData(0x01DEED58, 0x04, 0x04, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_6]  = AnimalCheckData(0x01DEED58, 0x05, 0x05, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_7]  = AnimalCheckData(0x01DEED58, 0x06, 0x06, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_8]  = AnimalCheckData(0x01DEED58, 0x07, 0x07, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_9]  = AnimalCheckData(0x01DEED59, 0x00, 0x08, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_10] = AnimalCheckData(0x01DEED59, 0x01, 0x09, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_11] = AnimalCheckData(0x01DEED59, 0x02, 0x0A, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_12] = AnimalCheckData(0x01DEED59, 0x03, 0x0B, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_13] = AnimalCheckData(0x01DEED59, 0x04, 0x0C, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_14] = AnimalCheckData(0x01DEED59, 0x05, 0x0D, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_15] = AnimalCheckData(0x01DEED59, 0x06, 0x0E, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_16] = AnimalCheckData(0x01DEED59, 0x07, 0x0F, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_17] = AnimalCheckData(0x01DEED5A, 0x00, 0x10, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_18] = AnimalCheckData(0x01DEED5A, 0x01, 0x11, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_19] = AnimalCheckData(0x01DEED5A, 0x02, 0x12, LevelIDs_CityEscape);
    outAnimalChecks[AnimalCheck::AC_CityEscape_Animal_20] = AnimalCheckData(0x01DEED5A, 0x03, 0x13, LevelIDs_CityEscape);

    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_1]  = AnimalCheckData(0x01DEED60, 0x00, 0x00, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_2]  = AnimalCheckData(0x01DEED60, 0x01, 0x01, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_3]  = AnimalCheckData(0x01DEED60, 0x02, 0x02, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_4]  = AnimalCheckData(0x01DEED60, 0x03, 0x03, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_5]  = AnimalCheckData(0x01DEED60, 0x04, 0x04, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_6]  = AnimalCheckData(0x01DEED60, 0x05, 0x05, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_7]  = AnimalCheckData(0x01DEED60, 0x06, 0x06, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_8]  = AnimalCheckData(0x01DEED60, 0x07, 0x07, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_9]  = AnimalCheckData(0x01DEED61, 0x00, 0x08, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_10] = AnimalCheckData(0x01DEED61, 0x01, 0x09, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_11] = AnimalCheckData(0x01DEED61, 0x02, 0x0A, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_12] = AnimalCheckData(0x01DEED61, 0x03, 0x0B, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_13] = AnimalCheckData(0x01DEED61, 0x04, 0x0C, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_14] = AnimalCheckData(0x01DEED61, 0x05, 0x0D, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_15] = AnimalCheckData(0x01DEED61, 0x06, 0x0E, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_16] = AnimalCheckData(0x01DEED62, 0x07, 0x0F, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_17] = AnimalCheckData(0x01DEED62, 0x00, 0x10, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_18] = AnimalCheckData(0x01DEED62, 0x01, 0x11, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_19] = AnimalCheckData(0x01DEED62, 0x02, 0x12, LevelIDs_RadicalHighway);
    outAnimalChecks[AnimalCheck::AC_RadicalHighway_Animal_20] = AnimalCheckData(0x01DEED62, 0x03, 0x13, LevelIDs_RadicalHighway);

    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_1]  = AnimalCheckData(0x01DEED63, 0x00, 0x00, LevelIDs_WildCanyon);
    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_2]  = AnimalCheckData(0x01DEED63, 0x01, 0x01, LevelIDs_WildCanyon);
    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_3]  = AnimalCheckData(0x01DEED63, 0x02, 0x02, LevelIDs_WildCanyon);
    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_4]  = AnimalCheckData(0x01DEED63, 0x03, 0x03, LevelIDs_WildCanyon);
    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_5]  = AnimalCheckData(0x01DEED63, 0x04, 0x04, LevelIDs_WildCanyon);
    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_6]  = AnimalCheckData(0x01DEED63, 0x05, 0x05, LevelIDs_WildCanyon);
    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_7]  = AnimalCheckData(0x01DEED63, 0x06, 0x06, LevelIDs_WildCanyon);
    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_8]  = AnimalCheckData(0x01DEED63, 0x07, 0x07, LevelIDs_WildCanyon);
    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_9]  = AnimalCheckData(0x01DEED64, 0x00, 0x08, LevelIDs_WildCanyon);
    outAnimalChecks[AnimalCheck::AC_WildCanyon_Animal_10] = AnimalCheckData(0x01DEED64, 0x01, 0x09, LevelIDs_WildCanyon);

    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_1]  = AnimalCheckData(0x01DEED65, 0x00, 0x00, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_2]  = AnimalCheckData(0x01DEED65, 0x01, 0x01, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_3]  = AnimalCheckData(0x01DEED65, 0x02, 0x02, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_4]  = AnimalCheckData(0x01DEED65, 0x03, 0x03, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_5]  = AnimalCheckData(0x01DEED65, 0x04, 0x04, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_6]  = AnimalCheckData(0x01DEED65, 0x05, 0x05, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_7]  = AnimalCheckData(0x01DEED65, 0x06, 0x06, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_8]  = AnimalCheckData(0x01DEED65, 0x07, 0x07, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_9]  = AnimalCheckData(0x01DEED66, 0x00, 0x08, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_10] = AnimalCheckData(0x01DEED66, 0x01, 0x09, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_11] = AnimalCheckData(0x01DEED66, 0x02, 0x0A, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_12] = AnimalCheckData(0x01DEED66, 0x03, 0x0B, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_13] = AnimalCheckData(0x01DEED66, 0x04, 0x0C, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_14] = AnimalCheckData(0x01DEED66, 0x05, 0x0D, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_15] = AnimalCheckData(0x01DEED66, 0x06, 0x0E, LevelIDs_MissionStreet);
    outAnimalChecks[AnimalCheck::AC_MissionStreet_Animal_16] = AnimalCheckData(0x01DEED66, 0x07, 0x0F, LevelIDs_MissionStreet);

    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_1]  = AnimalCheckData(0x01DEED6C, 0x00, 0x00, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_2]  = AnimalCheckData(0x01DEED6C, 0x01, 0x01, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_3]  = AnimalCheckData(0x01DEED6C, 0x02, 0x02, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_4]  = AnimalCheckData(0x01DEED6C, 0x03, 0x03, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_5]  = AnimalCheckData(0x01DEED6C, 0x04, 0x04, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_6]  = AnimalCheckData(0x01DEED6C, 0x05, 0x05, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_7]  = AnimalCheckData(0x01DEED6C, 0x06, 0x06, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_8]  = AnimalCheckData(0x01DEED6C, 0x07, 0x07, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_9]  = AnimalCheckData(0x01DEED6D, 0x00, 0x08, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_10] = AnimalCheckData(0x01DEED6D, 0x01, 0x09, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_11] = AnimalCheckData(0x01DEED6D, 0x02, 0x0A, LevelIDs_DryLagoon);
    outAnimalChecks[AnimalCheck::AC_DryLagoon_Animal_12] = AnimalCheckData(0x01DEED6D, 0x03, 0x0B, LevelIDs_DryLagoon);

    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_1]  = AnimalCheckData(0x01DEED6E, 0x00, 0x00, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_2]  = AnimalCheckData(0x01DEED6E, 0x01, 0x01, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_3]  = AnimalCheckData(0x01DEED6E, 0x02, 0x02, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_4]  = AnimalCheckData(0x01DEED6E, 0x03, 0x03, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_5]  = AnimalCheckData(0x01DEED6E, 0x04, 0x04, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_6]  = AnimalCheckData(0x01DEED6E, 0x05, 0x05, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_7]  = AnimalCheckData(0x01DEED6E, 0x06, 0x06, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_8]  = AnimalCheckData(0x01DEED6E, 0x07, 0x07, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_9]  = AnimalCheckData(0x01DEED6F, 0x00, 0x08, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_10] = AnimalCheckData(0x01DEED6F, 0x01, 0x09, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_11] = AnimalCheckData(0x01DEED6F, 0x02, 0x0A, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_12] = AnimalCheckData(0x01DEED6F, 0x03, 0x0B, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_13] = AnimalCheckData(0x01DEED6F, 0x04, 0x0C, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_14] = AnimalCheckData(0x01DEED6F, 0x05, 0x0D, LevelIDs_SandOcean);
    outAnimalChecks[AnimalCheck::AC_SandOcean_Animal_15] = AnimalCheckData(0x01DEED6F, 0x06, 0x0E, LevelIDs_SandOcean);

    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_1]  = AnimalCheckData(0x01DEED70, 0x00, 0x00, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_2]  = AnimalCheckData(0x01DEED70, 0x01, 0x01, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_3]  = AnimalCheckData(0x01DEED70, 0x02, 0x02, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_4]  = AnimalCheckData(0x01DEED70, 0x03, 0x03, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_5]  = AnimalCheckData(0x01DEED70, 0x04, 0x04, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_6]  = AnimalCheckData(0x01DEED70, 0x05, 0x05, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_7]  = AnimalCheckData(0x01DEED70, 0x06, 0x06, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_8]  = AnimalCheckData(0x01DEED70, 0x07, 0x07, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_9]  = AnimalCheckData(0x01DEED71, 0x00, 0x08, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_10] = AnimalCheckData(0x01DEED71, 0x01, 0x09, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_11] = AnimalCheckData(0x01DEED71, 0x02, 0x0A, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_12] = AnimalCheckData(0x01DEED71, 0x03, 0x0B, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_13] = AnimalCheckData(0x01DEED71, 0x04, 0x0C, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_14] = AnimalCheckData(0x01DEED71, 0x05, 0x0D, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_15] = AnimalCheckData(0x01DEED71, 0x06, 0x0E, LevelIDs_CrazyGadget);
    outAnimalChecks[AnimalCheck::AC_CrazyGadget_Animal_16] = AnimalCheckData(0x01DEED71, 0x07, 0x0F, LevelIDs_CrazyGadget);

    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_1]  = AnimalCheckData(0x01DEED78, 0x00, 0x00, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_2]  = AnimalCheckData(0x01DEED78, 0x01, 0x01, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_3]  = AnimalCheckData(0x01DEED78, 0x02, 0x02, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_4]  = AnimalCheckData(0x01DEED78, 0x03, 0x03, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_5]  = AnimalCheckData(0x01DEED78, 0x04, 0x04, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_6]  = AnimalCheckData(0x01DEED78, 0x05, 0x05, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_7]  = AnimalCheckData(0x01DEED78, 0x06, 0x06, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_8]  = AnimalCheckData(0x01DEED78, 0x07, 0x07, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_9]  = AnimalCheckData(0x01DEED79, 0x00, 0x08, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_10] = AnimalCheckData(0x01DEED79, 0x01, 0x09, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_11] = AnimalCheckData(0x01DEED79, 0x02, 0x0A, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_12] = AnimalCheckData(0x01DEED79, 0x03, 0x0B, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_13] = AnimalCheckData(0x01DEED79, 0x04, 0x0C, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_14] = AnimalCheckData(0x01DEED79, 0x05, 0x0D, LevelIDs_HiddenBase);
    outAnimalChecks[AnimalCheck::AC_HiddenBase_Animal_15] = AnimalCheckData(0x01DEED79, 0x06, 0x0E, LevelIDs_HiddenBase);

    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_1]  = AnimalCheckData(0x01DEED7A, 0x00, 0x00, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_2]  = AnimalCheckData(0x01DEED7A, 0x01, 0x01, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_3]  = AnimalCheckData(0x01DEED7A, 0x02, 0x02, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_4]  = AnimalCheckData(0x01DEED7A, 0x03, 0x03, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_5]  = AnimalCheckData(0x01DEED7A, 0x04, 0x04, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_6]  = AnimalCheckData(0x01DEED7A, 0x05, 0x05, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_7]  = AnimalCheckData(0x01DEED7A, 0x06, 0x06, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_8]  = AnimalCheckData(0x01DEED7A, 0x07, 0x07, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_9]  = AnimalCheckData(0x01DEED7B, 0x00, 0x08, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_10] = AnimalCheckData(0x01DEED7B, 0x01, 0x09, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_11] = AnimalCheckData(0x01DEED7B, 0x02, 0x0A, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_12] = AnimalCheckData(0x01DEED7B, 0x03, 0x0B, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_13] = AnimalCheckData(0x01DEED7B, 0x04, 0x0C, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_14] = AnimalCheckData(0x01DEED7B, 0x05, 0x0D, LevelIDs_EternalEngine);
    outAnimalChecks[AnimalCheck::AC_EternalEngine_Animal_15] = AnimalCheckData(0x01DEED7B, 0x06, 0x0E, LevelIDs_EternalEngine);

    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_1]  = AnimalCheckData(0x01DEED7C, 0x00, 0x00, LevelIDs_DeathChamber);
    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_2]  = AnimalCheckData(0x01DEED7C, 0x01, 0x01, LevelIDs_DeathChamber);
    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_3]  = AnimalCheckData(0x01DEED7C, 0x02, 0x02, LevelIDs_DeathChamber);
    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_4]  = AnimalCheckData(0x01DEED7C, 0x03, 0x03, LevelIDs_DeathChamber);
    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_5]  = AnimalCheckData(0x01DEED7C, 0x04, 0x04, LevelIDs_DeathChamber);
    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_6]  = AnimalCheckData(0x01DEED7C, 0x05, 0x05, LevelIDs_DeathChamber);
    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_7]  = AnimalCheckData(0x01DEED7C, 0x06, 0x06, LevelIDs_DeathChamber);
    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_8]  = AnimalCheckData(0x01DEED7C, 0x07, 0x07, LevelIDs_DeathChamber);
    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_9]  = AnimalCheckData(0x01DEED7D, 0x00, 0x08, LevelIDs_DeathChamber);
    outAnimalChecks[AnimalCheck::AC_DeathChamber_Animal_10] = AnimalCheckData(0x01DEED7D, 0x01, 0x09, LevelIDs_DeathChamber);

    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_1]  = AnimalCheckData(0x01DEED7E, 0x00, 0x00, LevelIDs_EggQuarters);
    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_2]  = AnimalCheckData(0x01DEED7E, 0x01, 0x01, LevelIDs_EggQuarters);
    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_3]  = AnimalCheckData(0x01DEED7E, 0x02, 0x02, LevelIDs_EggQuarters);
    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_4]  = AnimalCheckData(0x01DEED7E, 0x03, 0x03, LevelIDs_EggQuarters);
    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_5]  = AnimalCheckData(0x01DEED7E, 0x04, 0x04, LevelIDs_EggQuarters);
    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_6]  = AnimalCheckData(0x01DEED7E, 0x05, 0x05, LevelIDs_EggQuarters);
    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_7]  = AnimalCheckData(0x01DEED7E, 0x06, 0x06, LevelIDs_EggQuarters);
    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_8]  = AnimalCheckData(0x01DEED7E, 0x07, 0x07, LevelIDs_EggQuarters);
    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_9]  = AnimalCheckData(0x01DEED7F, 0x00, 0x08, LevelIDs_EggQuarters);
    outAnimalChecks[AnimalCheck::AC_EggQuarters_Animal_10] = AnimalCheckData(0x01DEED7F, 0x01, 0x09, LevelIDs_EggQuarters);

    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_1]  = AnimalCheckData(0x01DEED84, 0x00, 0x00, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_2]  = AnimalCheckData(0x01DEED84, 0x01, 0x01, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_3]  = AnimalCheckData(0x01DEED84, 0x02, 0x02, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_4]  = AnimalCheckData(0x01DEED84, 0x03, 0x03, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_5]  = AnimalCheckData(0x01DEED84, 0x04, 0x04, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_6]  = AnimalCheckData(0x01DEED84, 0x05, 0x05, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_7]  = AnimalCheckData(0x01DEED84, 0x06, 0x06, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_8]  = AnimalCheckData(0x01DEED84, 0x07, 0x07, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_9]  = AnimalCheckData(0x01DEED85, 0x00, 0x08, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_10] = AnimalCheckData(0x01DEED85, 0x01, 0x09, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_11] = AnimalCheckData(0x01DEED85, 0x02, 0x0A, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_12] = AnimalCheckData(0x01DEED85, 0x03, 0x0B, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_13] = AnimalCheckData(0x01DEED85, 0x04, 0x0C, LevelIDs_LostColony);
    outAnimalChecks[AnimalCheck::AC_LostColony_Animal_14] = AnimalCheckData(0x01DEED85, 0x05, 0x0D, LevelIDs_LostColony);

    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_1]  = AnimalCheckData(0x01DEED86, 0x00, 0x00, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_2]  = AnimalCheckData(0x01DEED86, 0x01, 0x01, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_3]  = AnimalCheckData(0x01DEED86, 0x02, 0x02, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_4]  = AnimalCheckData(0x01DEED86, 0x03, 0x03, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_5]  = AnimalCheckData(0x01DEED86, 0x04, 0x04, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_6]  = AnimalCheckData(0x01DEED86, 0x05, 0x05, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_7]  = AnimalCheckData(0x01DEED86, 0x06, 0x06, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_8]  = AnimalCheckData(0x01DEED86, 0x07, 0x07, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_9]  = AnimalCheckData(0x01DEED87, 0x00, 0x08, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_10] = AnimalCheckData(0x01DEED87, 0x01, 0x09, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_11] = AnimalCheckData(0x01DEED87, 0x02, 0x0A, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_12] = AnimalCheckData(0x01DEED87, 0x03, 0x0B, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_13] = AnimalCheckData(0x01DEED87, 0x04, 0x0C, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_14] = AnimalCheckData(0x01DEED87, 0x05, 0x0D, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_15] = AnimalCheckData(0x01DEED87, 0x06, 0x0E, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_16] = AnimalCheckData(0x01DEED87, 0x07, 0x0F, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_17] = AnimalCheckData(0x01DEED88, 0x00, 0x10, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_18] = AnimalCheckData(0x01DEED88, 0x01, 0x11, LevelIDs_PyramidCave);
    outAnimalChecks[AnimalCheck::AC_PyramidCave_Animal_19] = AnimalCheckData(0x01DEED88, 0x02, 0x12, LevelIDs_PyramidCave);

    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_1]  = AnimalCheckData(0x01DEED89, 0x00, 0x00, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_2]  = AnimalCheckData(0x01DEED89, 0x01, 0x01, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_3]  = AnimalCheckData(0x01DEED89, 0x02, 0x02, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_4]  = AnimalCheckData(0x01DEED89, 0x03, 0x03, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_5]  = AnimalCheckData(0x01DEED89, 0x04, 0x04, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_6]  = AnimalCheckData(0x01DEED89, 0x05, 0x05, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_7]  = AnimalCheckData(0x01DEED89, 0x06, 0x06, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_8]  = AnimalCheckData(0x01DEED89, 0x07, 0x07, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_9]  = AnimalCheckData(0x01DEED8A, 0x00, 0x08, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_10] = AnimalCheckData(0x01DEED8A, 0x01, 0x09, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_11] = AnimalCheckData(0x01DEED8A, 0x02, 0x0A, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_12] = AnimalCheckData(0x01DEED8A, 0x03, 0x0B, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_13] = AnimalCheckData(0x01DEED8A, 0x04, 0x0C, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_14] = AnimalCheckData(0x01DEED8A, 0x05, 0x0D, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_15] = AnimalCheckData(0x01DEED8A, 0x06, 0x0E, LevelIDs_FinalRush);
    outAnimalChecks[AnimalCheck::AC_FinalRush_Animal_16] = AnimalCheckData(0x01DEED8A, 0x07, 0x0F, LevelIDs_FinalRush);

    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_1]  = AnimalCheckData(0x01DEED90, 0x00, 0x00, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_2]  = AnimalCheckData(0x01DEED90, 0x01, 0x01, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_3]  = AnimalCheckData(0x01DEED90, 0x02, 0x02, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_4]  = AnimalCheckData(0x01DEED90, 0x03, 0x03, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_5]  = AnimalCheckData(0x01DEED90, 0x04, 0x04, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_6]  = AnimalCheckData(0x01DEED90, 0x05, 0x05, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_7]  = AnimalCheckData(0x01DEED90, 0x06, 0x06, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_8]  = AnimalCheckData(0x01DEED90, 0x07, 0x07, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_9]  = AnimalCheckData(0x01DEED91, 0x00, 0x08, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_10] = AnimalCheckData(0x01DEED91, 0x01, 0x09, LevelIDs_MeteorHerd);
    outAnimalChecks[AnimalCheck::AC_MeteorHerd_Animal_11] = AnimalCheckData(0x01DEED91, 0x02, 0x0A, LevelIDs_MeteorHerd);

    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_1]  = AnimalCheckData(0x01DEED92, 0x00, 0x00, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_2]  = AnimalCheckData(0x01DEED92, 0x01, 0x01, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_3]  = AnimalCheckData(0x01DEED92, 0x02, 0x02, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_4]  = AnimalCheckData(0x01DEED92, 0x03, 0x03, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_5]  = AnimalCheckData(0x01DEED92, 0x04, 0x04, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_6]  = AnimalCheckData(0x01DEED92, 0x05, 0x05, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_7]  = AnimalCheckData(0x01DEED92, 0x06, 0x06, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_8]  = AnimalCheckData(0x01DEED92, 0x07, 0x07, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_9]  = AnimalCheckData(0x01DEED93, 0x00, 0x08, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_10] = AnimalCheckData(0x01DEED93, 0x01, 0x09, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_11] = AnimalCheckData(0x01DEED93, 0x02, 0x0A, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_12] = AnimalCheckData(0x01DEED93, 0x03, 0x0B, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_13] = AnimalCheckData(0x01DEED93, 0x04, 0x0C, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_14] = AnimalCheckData(0x01DEED93, 0x05, 0x0D, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_15] = AnimalCheckData(0x01DEED93, 0x06, 0x0E, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_16] = AnimalCheckData(0x01DEED93, 0x07, 0x0F, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_17] = AnimalCheckData(0x01DEED94, 0x00, 0x10, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_18] = AnimalCheckData(0x01DEED94, 0x01, 0x11, LevelIDs_CannonsCoreS);
    outAnimalChecks[AnimalCheck::AC_CannonCore_Animal_19] = AnimalCheckData(0x01DEED94, 0x02, 0x12, LevelIDs_CannonsCoreS);

    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_1]  = AnimalCheckData(0x01DEED95, 0x00, 0x00, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_2]  = AnimalCheckData(0x01DEED95, 0x01, 0x01, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_3]  = AnimalCheckData(0x01DEED95, 0x02, 0x02, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_4]  = AnimalCheckData(0x01DEED95, 0x03, 0x03, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_5]  = AnimalCheckData(0x01DEED95, 0x04, 0x04, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_6]  = AnimalCheckData(0x01DEED95, 0x05, 0x05, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_7]  = AnimalCheckData(0x01DEED95, 0x06, 0x06, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_8]  = AnimalCheckData(0x01DEED95, 0x07, 0x07, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_9]  = AnimalCheckData(0x01DEED96, 0x00, 0x08, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_10] = AnimalCheckData(0x01DEED96, 0x01, 0x09, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_11] = AnimalCheckData(0x01DEED96, 0x02, 0x0A, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_12] = AnimalCheckData(0x01DEED96, 0x03, 0x0B, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_13] = AnimalCheckData(0x01DEED96, 0x04, 0x0C, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_14] = AnimalCheckData(0x01DEED96, 0x05, 0x0D, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_15] = AnimalCheckData(0x01DEED96, 0x06, 0x0E, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_16] = AnimalCheckData(0x01DEED96, 0x07, 0x0F, LevelIDs_FinalChase);
    outAnimalChecks[AnimalCheck::AC_FinalChase_Animal_17] = AnimalCheckData(0x01DEED97, 0x00, 0x10, LevelIDs_FinalChase);

    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_1]  = AnimalCheckData(0x01DEED9C, 0x00, 0x00, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_2]  = AnimalCheckData(0x01DEED9C, 0x01, 0x01, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_3]  = AnimalCheckData(0x01DEED9C, 0x02, 0x02, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_4]  = AnimalCheckData(0x01DEED9C, 0x03, 0x03, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_5]  = AnimalCheckData(0x01DEED9C, 0x04, 0x04, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_6]  = AnimalCheckData(0x01DEED9C, 0x05, 0x05, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_7]  = AnimalCheckData(0x01DEED9C, 0x06, 0x06, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_8]  = AnimalCheckData(0x01DEED9C, 0x07, 0x07, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_9]  = AnimalCheckData(0x01DEED9D, 0x00, 0x08, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_10] = AnimalCheckData(0x01DEED9D, 0x01, 0x09, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_11] = AnimalCheckData(0x01DEED9D, 0x02, 0x0A, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_12] = AnimalCheckData(0x01DEED9D, 0x03, 0x0B, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_13] = AnimalCheckData(0x01DEED9D, 0x04, 0x0C, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_14] = AnimalCheckData(0x01DEED9D, 0x05, 0x0D, LevelIDs_CosmicWall);
    outAnimalChecks[AnimalCheck::AC_CosmicWall_Animal_15] = AnimalCheckData(0x01DEED9D, 0x06, 0x0E, LevelIDs_CosmicWall);

    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_1]  = AnimalCheckData(0x01DEED9E, 0x00, 0x00, LevelIDs_MadSpace);
    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_2]  = AnimalCheckData(0x01DEED9E, 0x01, 0x01, LevelIDs_MadSpace);
    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_3]  = AnimalCheckData(0x01DEED9E, 0x02, 0x02, LevelIDs_MadSpace);
    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_4]  = AnimalCheckData(0x01DEED9E, 0x03, 0x03, LevelIDs_MadSpace);
    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_5]  = AnimalCheckData(0x01DEED9E, 0x04, 0x04, LevelIDs_MadSpace);
    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_6]  = AnimalCheckData(0x01DEED9E, 0x05, 0x05, LevelIDs_MadSpace);
    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_7]  = AnimalCheckData(0x01DEED9E, 0x06, 0x06, LevelIDs_MadSpace);
    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_8]  = AnimalCheckData(0x01DEED9E, 0x07, 0x07, LevelIDs_MadSpace);
    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_9]  = AnimalCheckData(0x01DEED9F, 0x00, 0x08, LevelIDs_MadSpace);
    outAnimalChecks[AnimalCheck::AC_MadSpace_Animal_10] = AnimalCheckData(0x01DEED9F, 0x01, 0x09, LevelIDs_MadSpace);
}

void InitializeItemBoxChecks(std::map<int, ItemBoxCheckData>& outItemBoxChecks)
{
    outItemBoxChecks.clear();

    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_LifeBox_1]  = ItemBoxCheckData(0x01DEEDA8, 0x00, LevelIDs_GreenForest, { 4565,	 -588,	4984 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_LifeBox_2]  = ItemBoxCheckData(0x01DEEDA8, 0x01, LevelIDs_GreenForest, { 6144,	-1735,	7418 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_LifeBox_3]  = ItemBoxCheckData(0x01DEEDA8, 0x02, LevelIDs_GreenForest, { 8196,	  -44,  7818 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_LifeBox_4]  = ItemBoxCheckData(0x01DEEDA8, 0x03, LevelIDs_GreenForest, { 8510,	-2259,	8455 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_1]  = ItemBoxCheckData(0x01DEEDA9, 0x00, LevelIDs_GreenForest, { 4590,	 -850,	5041 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_2]  = ItemBoxCheckData(0x01DEEDA9, 0x01, LevelIDs_GreenForest, { 4628,	 -850,	5042 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_3]  = ItemBoxCheckData(0x01DEEDA9, 0x02, LevelIDs_GreenForest, { 4563,	 -595,	5208 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_4]  = ItemBoxCheckData(0x01DEEDA9, 0x03, LevelIDs_GreenForest, { 4551,	 -597,	5059 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_5]  = ItemBoxCheckData(0x01DEEDA9, 0x04, LevelIDs_GreenForest, { 5890,	-2073,	7565 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_6]  = ItemBoxCheckData(0x01DEEDA9, 0x05, LevelIDs_GreenForest, { 8212,	-1797,	7838 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_7]  = ItemBoxCheckData(0x01DEEDA9, 0x06, LevelIDs_GreenForest, { 8214,	-2122,	7774 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_8]  = ItemBoxCheckData(0x01DEEDA9, 0x07, LevelIDs_GreenForest, { 8282,	-2122,	8036 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_9]  = ItemBoxCheckData(0x01DEEDAA, 0x00, LevelIDs_GreenForest, { 8224,	-1404,	7995 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_10] = ItemBoxCheckData(0x01DEEDAA, 0x01, LevelIDs_GreenForest, { 8233,	 -725,	7790 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_11] = ItemBoxCheckData(0x01DEEDAA, 0x02, LevelIDs_GreenForest, { 8370,	 -499,	7434 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_12] = ItemBoxCheckData(0x01DEEDAA, 0x03, LevelIDs_GreenForest, { 8267,	 -139,	7594 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenForest_ItemBox_13] = ItemBoxCheckData(0x01DEEDAA, 0x04, LevelIDs_GreenForest, { 8512,	-1399,	8446 });

    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_LifeBox_1] = ItemBoxCheckData(0x01DEEDAB, 0x00, LevelIDs_WhiteJungle, { 2183,	-1540,	 1081 });
    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_LifeBox_2] = ItemBoxCheckData(0x01DEEDAB, 0x01, LevelIDs_WhiteJungle, { 4061,	-2162,	-1530 });
    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_ItemBox_1] = ItemBoxCheckData(0x01DEEDAC, 0x00, LevelIDs_WhiteJungle, { 4209,	-2099,	 -546 });
    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_ItemBox_2] = ItemBoxCheckData(0x01DEEDAC, 0x01, LevelIDs_WhiteJungle, { 4079,	-2221,	-1218 });
    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_ItemBox_3] = ItemBoxCheckData(0x01DEEDAC, 0x02, LevelIDs_WhiteJungle, { 5743,	-2149,	-1531 });
    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_ItemBox_4] = ItemBoxCheckData(0x01DEEDAC, 0x03, LevelIDs_WhiteJungle, { 5868,	-1836,	-1386 });
    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_ItemBox_5] = ItemBoxCheckData(0x01DEEDAC, 0x04, LevelIDs_WhiteJungle, { 6698,	-1890,	-3716 });
    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_ItemBox_6] = ItemBoxCheckData(0x01DEEDAC, 0x05, LevelIDs_WhiteJungle, { 12173,	-3599,	-7852 });
    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_ItemBox_7] = ItemBoxCheckData(0x01DEEDAC, 0x06, LevelIDs_WhiteJungle, { 12189,	-3599,	-7849 });
    outItemBoxChecks[ItemBoxCheck::IBC_WhiteJungle_ItemBox_8] = ItemBoxCheckData(0x01DEEDAC, 0x07, LevelIDs_WhiteJungle, { 12205,	-3599,	-7845 });

    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_LifeBox_1]  = ItemBoxCheckData(0x01DEEDAD, 0x00, LevelIDs_PumpkinHill, {  461,	-1402,	-1253 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_1]  = ItemBoxCheckData(0x01DEEDAE, 0x00, LevelIDs_PumpkinHill, {  316,	-1331,	-1131 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_2]  = ItemBoxCheckData(0x01DEEDAE, 0x01, LevelIDs_PumpkinHill, {  124,	-1338,	 -834 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_3]  = ItemBoxCheckData(0x01DEEDAE, 0x02, LevelIDs_PumpkinHill, { 1049,	 -709,	-1173 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_4]  = ItemBoxCheckData(0x01DEEDAE, 0x03, LevelIDs_PumpkinHill, { 1184,	 -691,	-1181 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_5]  = ItemBoxCheckData(0x01DEEDAE, 0x04, LevelIDs_PumpkinHill, { 1431,	 -705,	-1267 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_6]  = ItemBoxCheckData(0x01DEEDAE, 0x05, LevelIDs_PumpkinHill, { 1799,	 -712,	-1256 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_7]  = ItemBoxCheckData(0x01DEEDAE, 0x06, LevelIDs_PumpkinHill, { 1147,	-1000,	 -711 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_8]  = ItemBoxCheckData(0x01DEEDAE, 0x07, LevelIDs_PumpkinHill, { 1137,	-1000,	 -723 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_9]  = ItemBoxCheckData(0x01DEEDAF, 0x00, LevelIDs_PumpkinHill, {  189,	 -435,	 -384 });
    outItemBoxChecks[ItemBoxCheck::IBC_PumpkinHill_ItemBox_10] = ItemBoxCheckData(0x01DEEDAF, 0x01, LevelIDs_PumpkinHill, {    0,	-1078,	-1426 });

    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_LifeBox_1]  = ItemBoxCheckData(0x01DEEDB4, 0x00, LevelIDs_SkyRail, {  -119,	-1256,	1389 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_LifeBox_2]  = ItemBoxCheckData(0x01DEEDB4, 0x01, LevelIDs_SkyRail, { -2679,	-1452,	2937 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_LifeBox_3]  = ItemBoxCheckData(0x01DEEDB4, 0x02, LevelIDs_SkyRail, { -3279,	-1500,	3162 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_LifeBox_4]  = ItemBoxCheckData(0x01DEEDB4, 0x03, LevelIDs_SkyRail, { -2879,	-1762,	3900 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_LifeBox_5]  = ItemBoxCheckData(0x01DEEDB4, 0x04, LevelIDs_SkyRail, { -2080,	-2330,	4685 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_LifeBox_6]  = ItemBoxCheckData(0x01DEEDB4, 0x05, LevelIDs_SkyRail, { -2084,	-2070,	4681 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_LifeBox_7]  = ItemBoxCheckData(0x01DEEDB4, 0x06, LevelIDs_SkyRail, { -1941,	-1850,	4601 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_LifeBox_8]  = ItemBoxCheckData(0x01DEEDB4, 0x07, LevelIDs_SkyRail, { -2094,	-1920,	4502 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_LifeBox_9]  = ItemBoxCheckData(0x01DEEDB5, 0x00, LevelIDs_SkyRail, { -2266,	-3759,	8915 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_1]  = ItemBoxCheckData(0x01DEEDB6, 0x00, LevelIDs_SkyRail, {  -346,	 -750,	1902 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_2]  = ItemBoxCheckData(0x01DEEDB6, 0x01, LevelIDs_SkyRail, { -1098,	 -552,	2553 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_3]  = ItemBoxCheckData(0x01DEEDB6, 0x02, LevelIDs_SkyRail, { -1838,	-1215,	2543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_4]  = ItemBoxCheckData(0x01DEEDB6, 0x03, LevelIDs_SkyRail, { -2393,	-1363,	2592 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_5]  = ItemBoxCheckData(0x01DEEDB6, 0x04, LevelIDs_SkyRail, { -3373,	-2157,	3184 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_6]  = ItemBoxCheckData(0x01DEEDB6, 0x05, LevelIDs_SkyRail, { -3360,	-2157,	3205 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_7]  = ItemBoxCheckData(0x01DEEDB6, 0x06, LevelIDs_SkyRail, { -3582,	-1150,	3022 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_8]  = ItemBoxCheckData(0x01DEEDB6, 0x07, LevelIDs_SkyRail, { -3365,	-1150,	2881 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_9]  = ItemBoxCheckData(0x01DEEDB7, 0x00, LevelIDs_SkyRail, { -2916,	-1762,	3941 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_10] = ItemBoxCheckData(0x01DEEDB7, 0x01, LevelIDs_SkyRail, { -2920,	-1762,	3901 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_11] = ItemBoxCheckData(0x01DEEDB7, 0x02, LevelIDs_SkyRail, { -2698,	-1841,	3848 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_12] = ItemBoxCheckData(0x01DEEDB7, 0x03, LevelIDs_SkyRail, { -2075,	-2180,	4424 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_13] = ItemBoxCheckData(0x01DEEDB7, 0x04, LevelIDs_SkyRail, { -2166,	-2250,	4415 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_14] = ItemBoxCheckData(0x01DEEDB7, 0x05, LevelIDs_SkyRail, { -2073,	-2070,	4687 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_15] = ItemBoxCheckData(0x01DEEDB7, 0x06, LevelIDs_SkyRail, { -2002,	-1880,	4723 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_16] = ItemBoxCheckData(0x01DEEDB7, 0x07, LevelIDs_SkyRail, { -2183,	-2018,	5281 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_17] = ItemBoxCheckData(0x01DEEDB8, 0x00, LevelIDs_SkyRail, { -2362,	-3057,	6552 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_18] = ItemBoxCheckData(0x01DEEDB8, 0x01, LevelIDs_SkyRail, { -2427,	-3165,	6598 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_19] = ItemBoxCheckData(0x01DEEDB8, 0x02, LevelIDs_SkyRail, { -2376,	-3489,	7228 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_20] = ItemBoxCheckData(0x01DEEDB8, 0x03, LevelIDs_SkyRail, { -2348,	-4226,	8136 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_21] = ItemBoxCheckData(0x01DEEDB8, 0x04, LevelIDs_SkyRail, { -2276,	-4026,	8453 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_22] = ItemBoxCheckData(0x01DEEDB8, 0x05, LevelIDs_SkyRail, { -2216,	-3874,	8651 });
    outItemBoxChecks[ItemBoxCheck::IBC_SkyRail_ItemBox_23] = ItemBoxCheckData(0x01DEEDB8, 0x06, LevelIDs_SkyRail, { -2589,	-3786,	8912 });

    outItemBoxChecks[ItemBoxCheck::IBC_AquaticMine_LifeBox_1] = ItemBoxCheckData(0x01DEEDB9, 0x00, LevelIDs_AquaticMine, { -591,	  81,	 472 });
    outItemBoxChecks[ItemBoxCheck::IBC_AquaticMine_ItemBox_1] = ItemBoxCheckData(0x01DEEDBA, 0x00, LevelIDs_AquaticMine, {  -37,	 310,	-123 });
    outItemBoxChecks[ItemBoxCheck::IBC_AquaticMine_ItemBox_2] = ItemBoxCheckData(0x01DEEDBA, 0x01, LevelIDs_AquaticMine, { -665,	 -59,	-228 });
    outItemBoxChecks[ItemBoxCheck::IBC_AquaticMine_ItemBox_3] = ItemBoxCheckData(0x01DEEDBA, 0x02, LevelIDs_AquaticMine, {  119,	-578,	 531 });
    outItemBoxChecks[ItemBoxCheck::IBC_AquaticMine_ItemBox_4] = ItemBoxCheckData(0x01DEEDBA, 0x03, LevelIDs_AquaticMine, {  113,	-650,	 563 });
    outItemBoxChecks[ItemBoxCheck::IBC_AquaticMine_ItemBox_5] = ItemBoxCheckData(0x01DEEDBA, 0x04, LevelIDs_AquaticMine, {   48,	-669,	 566 });
    outItemBoxChecks[ItemBoxCheck::IBC_AquaticMine_ItemBox_6] = ItemBoxCheckData(0x01DEEDBA, 0x05, LevelIDs_AquaticMine, {  249,	-693,	 558 });

    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_LifeBox_1]  = ItemBoxCheckData(0x01DEEDBB, 0x00, LevelIDs_SecurityHall, {  146,	-713,	  41 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_1]  = ItemBoxCheckData(0x01DEEDC0, 0x00, LevelIDs_SecurityHall, {  537,	-872,	 -70 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_2]  = ItemBoxCheckData(0x01DEEDC0, 0x01, LevelIDs_SecurityHall, {  539,	-933,	 110 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_3]  = ItemBoxCheckData(0x01DEEDC0, 0x02, LevelIDs_SecurityHall, {  536,	-873,	 349 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_4]  = ItemBoxCheckData(0x01DEEDC0, 0x03, LevelIDs_SecurityHall, {  180,	-933,	 543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_5]  = ItemBoxCheckData(0x01DEEDC0, 0x04, LevelIDs_SecurityHall, { -359,	-873,	 543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_6]  = ItemBoxCheckData(0x01DEEDC0, 0x05, LevelIDs_SecurityHall, { -420,	-932,	 543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_7]  = ItemBoxCheckData(0x01DEEDC0, 0x06, LevelIDs_SecurityHall, { -537,	-872,	 349 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_8]  = ItemBoxCheckData(0x01DEEDC0, 0x07, LevelIDs_SecurityHall, { -182,	-883,	-204 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_9]  = ItemBoxCheckData(0x01DEEDC1, 0x00, LevelIDs_SecurityHall, {  537,	-692,	 169 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_10] = ItemBoxCheckData(0x01DEEDC1, 0x01, LevelIDs_SecurityHall, {  537,	-692,	 349 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_11] = ItemBoxCheckData(0x01DEEDC1, 0x02, LevelIDs_SecurityHall, {  239,	-692,	 543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_12] = ItemBoxCheckData(0x01DEEDC1, 0x03, LevelIDs_SecurityHall, {  -60,	-752,	 543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_13] = ItemBoxCheckData(0x01DEEDC1, 0x04, LevelIDs_SecurityHall, { -359,	-753,	 543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_14] = ItemBoxCheckData(0x01DEEDC1, 0x05, LevelIDs_SecurityHall, { -420,	-692,	 543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_15] = ItemBoxCheckData(0x01DEEDC1, 0x06, LevelIDs_SecurityHall, { -537,	-692,	-130 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_16] = ItemBoxCheckData(0x01DEEDC1, 0x07, LevelIDs_SecurityHall, {  -20,	-613,	 169 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_17] = ItemBoxCheckData(0x01DEEDC2, 0x00, LevelIDs_SecurityHall, {   19,	-613,	 169 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_18] = ItemBoxCheckData(0x01DEEDC2, 0x01, LevelIDs_SecurityHall, {  537,	-572,	 349 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_19] = ItemBoxCheckData(0x01DEEDC2, 0x02, LevelIDs_SecurityHall, {  239,	-572,	 543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_20] = ItemBoxCheckData(0x01DEEDC2, 0x03, LevelIDs_SecurityHall, {    0,	-512,	 543 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_21] = ItemBoxCheckData(0x01DEEDC2, 0x04, LevelIDs_SecurityHall, { -537,	-572,	 349 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_22] = ItemBoxCheckData(0x01DEEDC2, 0x05, LevelIDs_SecurityHall, { -537,	-572,	-130 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_23] = ItemBoxCheckData(0x01DEEDC2, 0x06, LevelIDs_SecurityHall, {  414,	-143,	   3 });
    outItemBoxChecks[ItemBoxCheck::IBC_SecurityHall_ItemBox_24] = ItemBoxCheckData(0x01DEEDC2, 0x07, LevelIDs_SecurityHall, { -170,	 129,	  60 });

    outItemBoxChecks[ItemBoxCheck::IBC_PrisonLane_LifeBox_1] = ItemBoxCheckData(0x01DEEDC3, 0x00, LevelIDs_PrisonLane, {  -469,	197,	 -4	 });
    outItemBoxChecks[ItemBoxCheck::IBC_PrisonLane_LifeBox_2] = ItemBoxCheckData(0x01DEEDC3, 0x01, LevelIDs_PrisonLane, {  -854,	 97,	 394 });
    outItemBoxChecks[ItemBoxCheck::IBC_PrisonLane_ItemBox_1] = ItemBoxCheckData(0x01DEEDC4, 0x00, LevelIDs_PrisonLane, {  -869,	 97,	 394 });
    outItemBoxChecks[ItemBoxCheck::IBC_PrisonLane_ItemBox_2] = ItemBoxCheckData(0x01DEEDC4, 0x01, LevelIDs_PrisonLane, { -1085,	177,	 575 });
    outItemBoxChecks[ItemBoxCheck::IBC_PrisonLane_ItemBox_3] = ItemBoxCheckData(0x01DEEDC4, 0x02, LevelIDs_PrisonLane, { -1238,	140,	 667 });
    outItemBoxChecks[ItemBoxCheck::IBC_PrisonLane_ItemBox_4] = ItemBoxCheckData(0x01DEEDC4, 0x03, LevelIDs_PrisonLane, { -1649,	237,	-447 });
    outItemBoxChecks[ItemBoxCheck::IBC_PrisonLane_ItemBox_5] = ItemBoxCheckData(0x01DEEDC4, 0x04, LevelIDs_PrisonLane, { -3162,	700,	-261 });
    outItemBoxChecks[ItemBoxCheck::IBC_PrisonLane_ItemBox_6] = ItemBoxCheckData(0x01DEEDC4, 0x05, LevelIDs_PrisonLane, { -3162,	700,	-231 });

    outItemBoxChecks[ItemBoxCheck::IBC_MetalHarbor_LifeBox_1] = ItemBoxCheckData(0x01DEEDC5, 0x00, LevelIDs_MetalHarbor, { 1941,	-241,	 -3140 });
    outItemBoxChecks[ItemBoxCheck::IBC_MetalHarbor_LifeBox_2] = ItemBoxCheckData(0x01DEEDC5, 0x01, LevelIDs_MetalHarbor, { 1836,	 -99,	 -5110 });
    outItemBoxChecks[ItemBoxCheck::IBC_MetalHarbor_LifeBox_3] = ItemBoxCheckData(0x01DEEDC5, 0x02, LevelIDs_MetalHarbor, { 7022,	 275,	-10413 });
    outItemBoxChecks[ItemBoxCheck::IBC_MetalHarbor_ItemBox_1] = ItemBoxCheckData(0x01DEEDC6, 0x00, LevelIDs_MetalHarbor, { 4683,	-269,	 -9260 });
    outItemBoxChecks[ItemBoxCheck::IBC_MetalHarbor_ItemBox_2] = ItemBoxCheckData(0x01DEEDC6, 0x01, LevelIDs_MetalHarbor, { 5817,	1478,	-10234 });
    outItemBoxChecks[ItemBoxCheck::IBC_MetalHarbor_ItemBox_3] = ItemBoxCheckData(0x01DEEDC6, 0x02, LevelIDs_MetalHarbor, { 6415,	 887,	-10429 });
    outItemBoxChecks[ItemBoxCheck::IBC_MetalHarbor_ItemBox_4] = ItemBoxCheckData(0x01DEEDC6, 0x03, LevelIDs_MetalHarbor, { 6699,	 593,	-10307 });
    outItemBoxChecks[ItemBoxCheck::IBC_MetalHarbor_ItemBox_5] = ItemBoxCheckData(0x01DEEDC6, 0x04, LevelIDs_MetalHarbor, { 7254,	  42,	-10401 });

    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_LifeBox_1]  = ItemBoxCheckData(0x01DEEDC7, 0x00, LevelIDs_IronGate, { 2829,	 -433,	 -740 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_LifeBox_2]  = ItemBoxCheckData(0x01DEEDC7, 0x01, LevelIDs_IronGate, { 2889,	 -433,	 -740 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_LifeBox_3]  = ItemBoxCheckData(0x01DEEDC7, 0x02, LevelIDs_IronGate, { 3360,	 -803,	  -95 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_LifeBox_4]  = ItemBoxCheckData(0x01DEEDC7, 0x03, LevelIDs_IronGate, { 4702,	-1366,	 -756 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_1]  = ItemBoxCheckData(0x01DEEDCC, 0x00, LevelIDs_IronGate, { 1085,	 -270,	 -719 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_2]  = ItemBoxCheckData(0x01DEEDCC, 0x01, LevelIDs_IronGate, { 1121,	 -270,	 -719 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_3]  = ItemBoxCheckData(0x01DEEDCC, 0x02, LevelIDs_IronGate, { 2373,	 -663,	-1042 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_4]  = ItemBoxCheckData(0x01DEEDCC, 0x03, LevelIDs_IronGate, { 2403,	 -663,	-1042 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_5]  = ItemBoxCheckData(0x01DEEDCC, 0x04, LevelIDs_IronGate, { 2403,	 -663,	-1012 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_6]  = ItemBoxCheckData(0x01DEEDCC, 0x05, LevelIDs_IronGate, { 2373,	 -663,	-1012 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_7]  = ItemBoxCheckData(0x01DEEDCC, 0x06, LevelIDs_IronGate, { 2929,	 -601,	 -570 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_8]  = ItemBoxCheckData(0x01DEEDCC, 0x07, LevelIDs_IronGate, { 2857,	 -433,	 -210 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_9]  = ItemBoxCheckData(0x01DEEDCD, 0x00, LevelIDs_IronGate, { 3310,	 -803,	  -95 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_10] = ItemBoxCheckData(0x01DEEDCD, 0x01, LevelIDs_IronGate, { 3310,	 -803,	  -45 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_11] = ItemBoxCheckData(0x01DEEDCD, 0x02, LevelIDs_IronGate, { 3360,	 -803,	  -45 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_12] = ItemBoxCheckData(0x01DEEDCD, 0x03, LevelIDs_IronGate, { 3144,	 -853,	 -575 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_13] = ItemBoxCheckData(0x01DEEDCD, 0x04, LevelIDs_IronGate, { 3164,	 -853,	 -575 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_14] = ItemBoxCheckData(0x01DEEDCD, 0x05, LevelIDs_IronGate, { 3843,	 -903,	 -752 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_15] = ItemBoxCheckData(0x01DEEDCD, 0x06, LevelIDs_IronGate, { 4728,	-1366,	 -756 });
    outItemBoxChecks[ItemBoxCheck::IBC_IronGate_ItemBox_16] = ItemBoxCheckData(0x01DEEDCD, 0x07, LevelIDs_IronGate, { 4969,	-1435,	-1145 });

    outItemBoxChecks[ItemBoxCheck::IBC_WeaponsBed_LifeBox_1] = ItemBoxCheckData(0x01DEEDCE, 0x00, LevelIDs_WeaponsBed, { 1915,	-293,	-5771 });
    outItemBoxChecks[ItemBoxCheck::IBC_WeaponsBed_ItemBox_1] = ItemBoxCheckData(0x01DEEDCF, 0x00, LevelIDs_WeaponsBed, {  941,	-112,	-3273 });
    outItemBoxChecks[ItemBoxCheck::IBC_WeaponsBed_ItemBox_2] = ItemBoxCheckData(0x01DEEDCF, 0x01, LevelIDs_WeaponsBed, {  863,	-220,	-3321 });
    outItemBoxChecks[ItemBoxCheck::IBC_WeaponsBed_ItemBox_3] = ItemBoxCheckData(0x01DEEDCF, 0x02, LevelIDs_WeaponsBed, {  863,	-220,	-3233 });
    outItemBoxChecks[ItemBoxCheck::IBC_WeaponsBed_ItemBox_4] = ItemBoxCheckData(0x01DEEDCF, 0x03, LevelIDs_WeaponsBed, { 1924,	-246,	-5889 });
    outItemBoxChecks[ItemBoxCheck::IBC_WeaponsBed_ItemBox_5] = ItemBoxCheckData(0x01DEEDCF, 0x04, LevelIDs_WeaponsBed, { 1866,	-220,	-7220 });
    outItemBoxChecks[ItemBoxCheck::IBC_WeaponsBed_ItemBox_6] = ItemBoxCheckData(0x01DEEDCF, 0x05, LevelIDs_WeaponsBed, { 1866,	-220,	-7260 });
    outItemBoxChecks[ItemBoxCheck::IBC_WeaponsBed_ItemBox_7] = ItemBoxCheckData(0x01DEEDCF, 0x06, LevelIDs_WeaponsBed, { 1866,	-220,	-7300 });

    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_LifeBox_1] = ItemBoxCheckData(0x01DEEDD0, 0x00, LevelIDs_CityEscape, { -1760,	 -4502,	6139 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_LifeBox_2] = ItemBoxCheckData(0x01DEEDD0, 0x01, LevelIDs_CityEscape, {  4024,	 -8873,	6413 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_ItemBox_1] = ItemBoxCheckData(0x01DEEDD1, 0x00, LevelIDs_CityEscape, { -1760,	 -4532,	6139 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_ItemBox_2] = ItemBoxCheckData(0x01DEEDD1, 0x01, LevelIDs_CityEscape, { -1540,	 -6020,	8838 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_ItemBox_3] = ItemBoxCheckData(0x01DEEDD1, 0x02, LevelIDs_CityEscape, {  -647,	 -6238,	9814 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_ItemBox_4] = ItemBoxCheckData(0x01DEEDD1, 0x03, LevelIDs_CityEscape, {   345,	 -6466,	9842 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_ItemBox_5] = ItemBoxCheckData(0x01DEEDD1, 0x04, LevelIDs_CityEscape, {   827,	 -8079,	6325 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_ItemBox_6] = ItemBoxCheckData(0x01DEEDD1, 0x05, LevelIDs_CityEscape, {  4024,	 -8901,	6413 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_ItemBox_7] = ItemBoxCheckData(0x01DEEDD1, 0x06, LevelIDs_CityEscape, {  5986,	-10718,	4812 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_ItemBox_8] = ItemBoxCheckData(0x01DEEDD1, 0x07, LevelIDs_CityEscape, {  7302,	-11302,	4729 });
    outItemBoxChecks[ItemBoxCheck::IBC_CityEscape_ItemBox_9] = ItemBoxCheckData(0x01DEEDD2, 0x00, LevelIDs_CityEscape, {  7658,	-14296,	6253 });

    outItemBoxChecks[ItemBoxCheck::IBC_RadicalHighway_LifeBox_1] = ItemBoxCheckData(0x01DEEDD3, 0x00, LevelIDs_RadicalHighway, { -4432,	-2632,	 -4767 });
    outItemBoxChecks[ItemBoxCheck::IBC_RadicalHighway_LifeBox_2] = ItemBoxCheckData(0x01DEEDD3, 0x01, LevelIDs_RadicalHighway, { -6228,	-5006,	-11144 });
    outItemBoxChecks[ItemBoxCheck::IBC_RadicalHighway_ItemBox_1] = ItemBoxCheckData(0x01DEEDD8, 0x00, LevelIDs_RadicalHighway, { -4338,	-2885,	 -4647 });
    outItemBoxChecks[ItemBoxCheck::IBC_RadicalHighway_ItemBox_2] = ItemBoxCheckData(0x01DEEDD8, 0x01, LevelIDs_RadicalHighway, { -4432,	-2632,	 -4517 });
    outItemBoxChecks[ItemBoxCheck::IBC_RadicalHighway_ItemBox_3] = ItemBoxCheckData(0x01DEEDD8, 0x02, LevelIDs_RadicalHighway, { -5000,	-2712,	 -4343 });
    outItemBoxChecks[ItemBoxCheck::IBC_RadicalHighway_ItemBox_4] = ItemBoxCheckData(0x01DEEDD8, 0x03, LevelIDs_RadicalHighway, { -6679,	-2727,	 -6065 });
    outItemBoxChecks[ItemBoxCheck::IBC_RadicalHighway_ItemBox_5] = ItemBoxCheckData(0x01DEEDD8, 0x04, LevelIDs_RadicalHighway, { -6224,	-5081,	 -7667 });
    outItemBoxChecks[ItemBoxCheck::IBC_RadicalHighway_ItemBox_6] = ItemBoxCheckData(0x01DEEDD8, 0x05, LevelIDs_RadicalHighway, { -8177,	-6525,	-15476 });
    outItemBoxChecks[ItemBoxCheck::IBC_RadicalHighway_ItemBox_7] = ItemBoxCheckData(0x01DEEDD8, 0x06, LevelIDs_RadicalHighway, { -8152,	-6525,	-15476 });

    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_LifeBox_1] = ItemBoxCheckData(0x01DEEDD9, 0x00, LevelIDs_WildCanyon, {  110,	 235,	-150 });
    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_LifeBox_2] = ItemBoxCheckData(0x01DEEDD9, 0x01, LevelIDs_WildCanyon, {  574,	 950,	  45 });
    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_ItemBox_1] = ItemBoxCheckData(0x01DEEDDA, 0x00, LevelIDs_WildCanyon, {  288,	 235,	-150 });
    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_ItemBox_2] = ItemBoxCheckData(0x01DEEDDA, 0x01, LevelIDs_WildCanyon, {  110,	 235,	 150 });
    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_ItemBox_3] = ItemBoxCheckData(0x01DEEDDA, 0x02, LevelIDs_WildCanyon, {  470,	 457,	-330 });
    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_ItemBox_4] = ItemBoxCheckData(0x01DEEDDA, 0x03, LevelIDs_WildCanyon, {  350,	 650,	  51 });
    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_ItemBox_5] = ItemBoxCheckData(0x01DEEDDA, 0x04, LevelIDs_WildCanyon, {  175,	1070,	 216 });
    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_ItemBox_6] = ItemBoxCheckData(0x01DEEDDA, 0x05, LevelIDs_WildCanyon, {  224,	1070,	 216 });
    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_ItemBox_7] = ItemBoxCheckData(0x01DEEDDA, 0x06, LevelIDs_WildCanyon, { 1650,	   0,	 704 });
    outItemBoxChecks[ItemBoxCheck::IBC_WildCanyon_ItemBox_8] = ItemBoxCheckData(0x01DEEDDA, 0x07, LevelIDs_WildCanyon, { 1650,	   0,	 774 });

    outItemBoxChecks[ItemBoxCheck::IBC_MissionStreet_LifeBox_1] = ItemBoxCheckData(0x01DEEDDB, 0x00, LevelIDs_MissionStreet, {  -485,	 375,	-2601 });
    outItemBoxChecks[ItemBoxCheck::IBC_MissionStreet_LifeBox_2] = ItemBoxCheckData(0x01DEEDDB, 0x01, LevelIDs_MissionStreet, {  2430,	 159,	-3391 });
    outItemBoxChecks[ItemBoxCheck::IBC_MissionStreet_ItemBox_1] = ItemBoxCheckData(0x01DEEDDC, 0x00, LevelIDs_MissionStreet, {  -280,	  -7,	-1949 });
    outItemBoxChecks[ItemBoxCheck::IBC_MissionStreet_ItemBox_2] = ItemBoxCheckData(0x01DEEDDC, 0x01, LevelIDs_MissionStreet, { -1050,	-165,	-1990 });
    outItemBoxChecks[ItemBoxCheck::IBC_MissionStreet_ItemBox_3] = ItemBoxCheckData(0x01DEEDDC, 0x02, LevelIDs_MissionStreet, { -1284,	 248,	-2960 });
    outItemBoxChecks[ItemBoxCheck::IBC_MissionStreet_ItemBox_4] = ItemBoxCheckData(0x01DEEDDC, 0x03, LevelIDs_MissionStreet, {   464,	 199,	-3309 });
    outItemBoxChecks[ItemBoxCheck::IBC_MissionStreet_ItemBox_5] = ItemBoxCheckData(0x01DEEDDC, 0x04, LevelIDs_MissionStreet, {  1922,	 304,	-3392 });
    outItemBoxChecks[ItemBoxCheck::IBC_MissionStreet_ItemBox_6] = ItemBoxCheckData(0x01DEEDDC, 0x05, LevelIDs_MissionStreet, {  3361,	 388,	-3944 });

    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_LifeBox_1] = ItemBoxCheckData(0x01DEEDDD, 0x00, LevelIDs_DryLagoon, { 1803,	  0,	-1590 });
    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_LifeBox_2] = ItemBoxCheckData(0x01DEEDDD, 0x01, LevelIDs_DryLagoon, {   69,	240,	 1556 });
    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_LifeBox_3] = ItemBoxCheckData(0x01DEEDDD, 0x02, LevelIDs_DryLagoon, {  190,	479,	 1265 });
    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_LifeBox_4] = ItemBoxCheckData(0x01DEEDDD, 0x03, LevelIDs_DryLagoon, {  943,	360,	 1516 });
    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_ItemBox_1] = ItemBoxCheckData(0x01DEEDDE, 0x00, LevelIDs_DryLagoon, {  517,	191,	 -105 });
    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_ItemBox_2] = ItemBoxCheckData(0x01DEEDDE, 0x01, LevelIDs_DryLagoon, {  280,	163,	  152 });
    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_ItemBox_3] = ItemBoxCheckData(0x01DEEDDE, 0x02, LevelIDs_DryLagoon, {  125,	 40,	  428 });
    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_ItemBox_4] = ItemBoxCheckData(0x01DEEDDE, 0x03, LevelIDs_DryLagoon, {   90,	218,	 -286 });
    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_ItemBox_5] = ItemBoxCheckData(0x01DEEDDE, 0x04, LevelIDs_DryLagoon, {  252,	380,	 -268 });
    outItemBoxChecks[ItemBoxCheck::IBC_DryLagoon_ItemBox_6] = ItemBoxCheckData(0x01DEEDDE, 0x05, LevelIDs_DryLagoon, {  316,	429,	   54 });

    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_LifeBox_1]  = ItemBoxCheckData(0x01DEEDDF, 0x00, LevelIDs_SandOcean, {  -36,	 30,	 -110 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_LifeBox_2]  = ItemBoxCheckData(0x01DEEDDF, 0x01, LevelIDs_SandOcean, {  391,	169,	-1999 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_LifeBox_3]  = ItemBoxCheckData(0x01DEEDDF, 0x02, LevelIDs_SandOcean, {  559,	 30,	-4688 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_1]  = ItemBoxCheckData(0x01DEEDE4, 0x00, LevelIDs_SandOcean, {   37,	 30,	 -110 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_2]  = ItemBoxCheckData(0x01DEEDE4, 0x01, LevelIDs_SandOcean, {  866,	 54,	 -538 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_3]  = ItemBoxCheckData(0x01DEEDE4, 0x02, LevelIDs_SandOcean, {   34,	 80,	-1416 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_4]  = ItemBoxCheckData(0x01DEEDE4, 0x03, LevelIDs_SandOcean, {  -35,	 80,	-1416 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_5]  = ItemBoxCheckData(0x01DEEDE4, 0x04, LevelIDs_SandOcean, {    0,	144,	-2180 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_6]  = ItemBoxCheckData(0x01DEEDE4, 0x05, LevelIDs_SandOcean, {   61,	 30,	-1941 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_7]  = ItemBoxCheckData(0x01DEEDE4, 0x06, LevelIDs_SandOcean, {  616,	-44,	-2100 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_8]  = ItemBoxCheckData(0x01DEEDE4, 0x07, LevelIDs_SandOcean, { 2750,	  0,	-3703 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_9]  = ItemBoxCheckData(0x01DEEDE5, 0x00, LevelIDs_SandOcean, { 2720,	  0,	-3675 });
    outItemBoxChecks[ItemBoxCheck::IBC_SandOcean_ItemBox_10] = ItemBoxCheckData(0x01DEEDE5, 0x01, LevelIDs_SandOcean, { 3478,	-37,	-6157 });

    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_LifeBox_1]  = ItemBoxCheckData(0x01DEEDE6, 0x00, LevelIDs_CrazyGadget, {  -2660,	  348,	 -549 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_LifeBox_2]  = ItemBoxCheckData(0x01DEEDE6, 0x01, LevelIDs_CrazyGadget, {  -4411,	 -815,	-2385 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_LifeBox_3]  = ItemBoxCheckData(0x01DEEDE6, 0x02, LevelIDs_CrazyGadget, {  -9587,	 -817,	-3334 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_LifeBox_4]  = ItemBoxCheckData(0x01DEEDE6, 0x03, LevelIDs_CrazyGadget, {  -9587,	 -817,	-3314 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_1]  = ItemBoxCheckData(0x01DEEDE7, 0x00, LevelIDs_CrazyGadget, {      0,	  -30,	 -399 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_2]  = ItemBoxCheckData(0x01DEEDE7, 0x01, LevelIDs_CrazyGadget, {   -799,	 -179,	 -420 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_3]  = ItemBoxCheckData(0x01DEEDE7, 0x02, LevelIDs_CrazyGadget, {   -800,	   20,	 -380 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_4]  = ItemBoxCheckData(0x01DEEDE7, 0x03, LevelIDs_CrazyGadget, {  -3133,	  302,	 -550 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_5]  = ItemBoxCheckData(0x01DEEDE7, 0x04, LevelIDs_CrazyGadget, {  -3569,	  152,	 -650 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_6]  = ItemBoxCheckData(0x01DEEDE7, 0x05, LevelIDs_CrazyGadget, {  -3829,	  170,	 -730 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_7]  = ItemBoxCheckData(0x01DEEDE7, 0x06, LevelIDs_CrazyGadget, {  -3956,	    0,	-1355 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_8]  = ItemBoxCheckData(0x01DEEDE7, 0x07, LevelIDs_CrazyGadget, {  -4404,	 -528,	-1355 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_9]  = ItemBoxCheckData(0x01DEEDE8, 0x00, LevelIDs_CrazyGadget, { -10934,	-1067,	-3375 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_10] = ItemBoxCheckData(0x01DEEDE8, 0x01, LevelIDs_CrazyGadget, { -10949,	-1067,	-3375 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_11] = ItemBoxCheckData(0x01DEEDE8, 0x02, LevelIDs_CrazyGadget, { -10964,	-1067,	-3375 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_12] = ItemBoxCheckData(0x01DEEDE8, 0x03, LevelIDs_CrazyGadget, { -10949,	-1227,	-3375 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_13] = ItemBoxCheckData(0x01DEEDE8, 0x04, LevelIDs_CrazyGadget, {  -9580,	-1097,	-2455 });
    outItemBoxChecks[ItemBoxCheck::IBC_CrazyGadget_ItemBox_14] = ItemBoxCheckData(0x01DEEDE8, 0x05, LevelIDs_CrazyGadget, {  -9580,	 -816,	-2537 });

    outItemBoxChecks[ItemBoxCheck::IBC_HiddenBase_LifeBox_1] = ItemBoxCheckData(0x01DEEDE9, 0x00, LevelIDs_HiddenBase, { -3955,	610,	-4537 });
    outItemBoxChecks[ItemBoxCheck::IBC_HiddenBase_ItemBox_1] = ItemBoxCheckData(0x01DEEDEA, 0x00, LevelIDs_HiddenBase, {   -74,	 40,	 -361 });
    outItemBoxChecks[ItemBoxCheck::IBC_HiddenBase_ItemBox_2] = ItemBoxCheckData(0x01DEEDEA, 0x01, LevelIDs_HiddenBase, { -4066,	560,	-3708 });
    outItemBoxChecks[ItemBoxCheck::IBC_HiddenBase_ItemBox_3] = ItemBoxCheckData(0x01DEEDEA, 0x02, LevelIDs_HiddenBase, { -4106,	560,	-3708 });
    outItemBoxChecks[ItemBoxCheck::IBC_HiddenBase_ItemBox_4] = ItemBoxCheckData(0x01DEEDEA, 0x03, LevelIDs_HiddenBase, { -3930,	610,	-4517 });
    outItemBoxChecks[ItemBoxCheck::IBC_HiddenBase_ItemBox_5] = ItemBoxCheckData(0x01DEEDEA, 0x04, LevelIDs_HiddenBase, { -3930,	610,	-4557 });

    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_LifeBox_1]  = ItemBoxCheckData(0x01DEEDEB, 0x00, LevelIDs_EternalEngine, { -2795,	 836,	-5130 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_LifeBox_2]  = ItemBoxCheckData(0x01DEEDEB, 0x01, LevelIDs_EternalEngine, { -2054,	 736,	-7070 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_1]  = ItemBoxCheckData(0x01DEEDF0, 0x00, LevelIDs_EternalEngine, {   249,	 578,	-2200 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_2]  = ItemBoxCheckData(0x01DEEDF0, 0x01, LevelIDs_EternalEngine, {  -653,	 578,	-3707 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_3]  = ItemBoxCheckData(0x01DEEDF0, 0x02, LevelIDs_EternalEngine, {  -609,	 323,	-4789 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_4]  = ItemBoxCheckData(0x01DEEDF0, 0x03, LevelIDs_EternalEngine, { -2005,	 941,	-5200 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_5]  = ItemBoxCheckData(0x01DEEDF0, 0x04, LevelIDs_EternalEngine, { -2119,	 835,	-5300 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_6]  = ItemBoxCheckData(0x01DEEDF0, 0x05, LevelIDs_EternalEngine, { -2795,	 836,	-5270 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_7]  = ItemBoxCheckData(0x01DEEDF0, 0x06, LevelIDs_EternalEngine, { -2055,	1036,	-7164 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_8]  = ItemBoxCheckData(0x01DEEDF0, 0x07, LevelIDs_EternalEngine, { -2039,	 736,	-7070 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_9]  = ItemBoxCheckData(0x01DEEDF1, 0x00, LevelIDs_EternalEngine, { -2069,	 736,	-7070 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_10] = ItemBoxCheckData(0x01DEEDF1, 0x01, LevelIDs_EternalEngine, { -2054,	 604,	-7744 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_11] = ItemBoxCheckData(0x01DEEDF1, 0x02, LevelIDs_EternalEngine, { -2174,	 336,	-7664 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_12] = ItemBoxCheckData(0x01DEEDF1, 0x03, LevelIDs_EternalEngine, { -1934,	 336,	-7664 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_13] = ItemBoxCheckData(0x01DEEDF1, 0x04, LevelIDs_EternalEngine, { -2055,	 985,	-9150 });
    outItemBoxChecks[ItemBoxCheck::IBC_EternalEngine_ItemBox_14] = ItemBoxCheckData(0x01DEEDF1, 0x05, LevelIDs_EternalEngine, {  -106,	-530,	-9150 });

    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_LifeBox_1]  = ItemBoxCheckData(0x01DEEDF2, 0x00, LevelIDs_DeathChamber, { -684,	 -84,	-952 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_1]  = ItemBoxCheckData(0x01DEEDF3, 0x00, LevelIDs_DeathChamber, {    0,	   0,	-351 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_2]  = ItemBoxCheckData(0x01DEEDF3, 0x01, LevelIDs_DeathChamber, { -467,	  20,	 540 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_3]  = ItemBoxCheckData(0x01DEEDF3, 0x02, LevelIDs_DeathChamber, {  980,	  80,	-390 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_4]  = ItemBoxCheckData(0x01DEEDF3, 0x03, LevelIDs_DeathChamber, {  600,	   0,	1770 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_5]  = ItemBoxCheckData(0x01DEEDF3, 0x04, LevelIDs_DeathChamber, { 1342,	 -19,	-330 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_6]  = ItemBoxCheckData(0x01DEEDF3, 0x05, LevelIDs_DeathChamber, { -905,	-268,	-905 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_7]  = ItemBoxCheckData(0x01DEEDF3, 0x06, LevelIDs_DeathChamber, { 1330,	  25,	1770 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_8]  = ItemBoxCheckData(0x01DEEDF3, 0x07, LevelIDs_DeathChamber, { 1330,	  25,	1710 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_9]  = ItemBoxCheckData(0x01DEEDF4, 0x00, LevelIDs_DeathChamber, { 1270,	  25,	1710 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_10] = ItemBoxCheckData(0x01DEEDF4, 0x01, LevelIDs_DeathChamber, { 1270,	  25,	1770 });
    outItemBoxChecks[ItemBoxCheck::IBC_DeathChamber_ItemBox_11] = ItemBoxCheckData(0x01DEEDF4, 0x02, LevelIDs_DeathChamber, {  577,	  20,	-513 });

    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_LifeBox_1]  = ItemBoxCheckData(0x01DEEDF5, 0x00, LevelIDs_EggQuarters, {   -80,	 48,	 475 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_LifeBox_2]  = ItemBoxCheckData(0x01DEEDF5, 0x01, LevelIDs_EggQuarters, {  -820,	 40,	2680 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_1]  = ItemBoxCheckData(0x01DEEDF6, 0x00, LevelIDs_EggQuarters, {   732,	 19,	 614 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_2]  = ItemBoxCheckData(0x01DEEDF6, 0x01, LevelIDs_EggQuarters, {    80,	 48,	 475 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_3]  = ItemBoxCheckData(0x01DEEDF6, 0x02, LevelIDs_EggQuarters, {   -80,	 48,	 435 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_4]  = ItemBoxCheckData(0x01DEEDF6, 0x03, LevelIDs_EggQuarters, {  -567,	 49,	 496 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_5]  = ItemBoxCheckData(0x01DEEDF6, 0x04, LevelIDs_EggQuarters, {  -186,	  0,	1145 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_6]  = ItemBoxCheckData(0x01DEEDF6, 0x05, LevelIDs_EggQuarters, {  -700,	-20,	2760 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_7]  = ItemBoxCheckData(0x01DEEDF6, 0x06, LevelIDs_EggQuarters, {  -580,	-20,	2720 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_8]  = ItemBoxCheckData(0x01DEEDF6, 0x07, LevelIDs_EggQuarters, {  -580,	-20,	2600 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_9]  = ItemBoxCheckData(0x01DEEDF7, 0x00, LevelIDs_EggQuarters, {  -700,	-20,	2600 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_10] = ItemBoxCheckData(0x01DEEDF7, 0x01, LevelIDs_EggQuarters, {  -659,	 40,	2840 });
    outItemBoxChecks[ItemBoxCheck::IBC_EggQuarters_ItemBox_11] = ItemBoxCheckData(0x01DEEDF7, 0x02, LevelIDs_EggQuarters, { -1640,	-20,	2760 });

    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_LifeBox_1] = ItemBoxCheckData(0x01DEEDFC, 0x00, LevelIDs_LostColony, { -1400,	-633,	-1265 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_ItemBox_1] = ItemBoxCheckData(0x01DEEDFD, 0x00, LevelIDs_LostColony, {  -420,	-642,	 -650 });
    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_ItemBox_2] = ItemBoxCheckData(0x01DEEDFD, 0x01, LevelIDs_LostColony, { -1415,	-633,	-1265 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_ItemBox_3] = ItemBoxCheckData(0x01DEEDFD, 0x02, LevelIDs_LostColony, { -1385,	-633,	-1265 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_ItemBox_4] = ItemBoxCheckData(0x01DEEDFD, 0x03, LevelIDs_LostColony, { -1400,	-578,	-2040 });
    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_ItemBox_5] = ItemBoxCheckData(0x01DEEDFD, 0x04, LevelIDs_LostColony, { -1570,	-613,	-2109 });
    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_ItemBox_6] = ItemBoxCheckData(0x01DEEDFD, 0x05, LevelIDs_LostColony, { -1540,	-528,	-2330 });
    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_ItemBox_7] = ItemBoxCheckData(0x01DEEDFD, 0x06, LevelIDs_LostColony, {  -893,	-421,	-1988 });
    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_ItemBox_8] = ItemBoxCheckData(0x01DEEDFD, 0x07, LevelIDs_LostColony, {  1269,	-518,	-2400 });
    outItemBoxChecks[ItemBoxCheck::IBC_LostColony_ItemBox_9] = ItemBoxCheckData(0x01DEEDFE, 0x00, LevelIDs_LostColony, {  3549,	1552,	-2398 });

    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_LifeBox_1]  = ItemBoxCheckData(0x01DEEDFF, 0x00, LevelIDs_PyramidCave, {  -286,	-1417,	 -4118 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_LifeBox_2]  = ItemBoxCheckData(0x01DEEDFF, 0x01, LevelIDs_PyramidCave, {     0,	-1942,	 -5049 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_LifeBox_3]  = ItemBoxCheckData(0x01DEEDFF, 0x02, LevelIDs_PyramidCave, { -2547,	-2187,	-10101 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_LifeBox_4]  = ItemBoxCheckData(0x01DEEDFF, 0x03, LevelIDs_PyramidCave, { -2820,	-3682,	-16159 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_LifeBox_5]  = ItemBoxCheckData(0x01DEEDFF, 0x04, LevelIDs_PyramidCave, { -2749,	-4100,	-18682 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_LifeBox_6]  = ItemBoxCheckData(0x01DEEDFF, 0x05, LevelIDs_PyramidCave, {  -686,	-4146,	-19517 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_LifeBox_7]  = ItemBoxCheckData(0x01DEEDFF, 0x06, LevelIDs_PyramidCave, {  -804,	-4160,	-20654 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_1]  = ItemBoxCheckData(0x01DEEE00, 0x00, LevelIDs_PyramidCave, {   180,	 -790,	 -2279 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_2]  = ItemBoxCheckData(0x01DEEE00, 0x01, LevelIDs_PyramidCave, {  -324,	-1405,	 -4071 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_3]  = ItemBoxCheckData(0x01DEEE00, 0x02, LevelIDs_PyramidCave, { -1091,	-2010,	 -6436 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_4]  = ItemBoxCheckData(0x01DEEE00, 0x03, LevelIDs_PyramidCave, { -1091,	-2010,	 -6501 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_5]  = ItemBoxCheckData(0x01DEEE00, 0x04, LevelIDs_PyramidCave, { -2560,	-1780,	 -8387 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_6]  = ItemBoxCheckData(0x01DEEE00, 0x05, LevelIDs_PyramidCave, { -2617,	-1730,	 -8519 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_7]  = ItemBoxCheckData(0x01DEEE00, 0x06, LevelIDs_PyramidCave, { -2617,	-1710,	 -8559 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_8]  = ItemBoxCheckData(0x01DEEE00, 0x07, LevelIDs_PyramidCave, { -2571,	-2187,	-10101 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_9]  = ItemBoxCheckData(0x01DEEE01, 0x00, LevelIDs_PyramidCave, { -2560,	-2189,	-10203 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_10] = ItemBoxCheckData(0x01DEEE01, 0x01, LevelIDs_PyramidCave, { -2540,	-2240,	-11012 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_11] = ItemBoxCheckData(0x01DEEE01, 0x02, LevelIDs_PyramidCave, { -2641,	-2235,	-11001 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_12] = ItemBoxCheckData(0x01DEEE01, 0x03, LevelIDs_PyramidCave, { -2580,	-2257,	-12664 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_13] = ItemBoxCheckData(0x01DEEE01, 0x04, LevelIDs_PyramidCave, { -2794,	-2479,	-13226 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_14] = ItemBoxCheckData(0x01DEEE01, 0x05, LevelIDs_PyramidCave, {  -804,	-4160,	-20622 });
    outItemBoxChecks[ItemBoxCheck::IBC_PyramidCave_ItemBox_15] = ItemBoxCheckData(0x01DEEE01, 0x06, LevelIDs_PyramidCave, {  -804,	-4160,	-20687 });

    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_1]  = ItemBoxCheckData(0x01DEEE02, 0x00, LevelIDs_FinalRush, { 3078,	  -868,	 -596 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_2]  = ItemBoxCheckData(0x01DEEE02, 0x01, LevelIDs_FinalRush, { 3020,	  -988,	  825 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_3]  = ItemBoxCheckData(0x01DEEE02, 0x02, LevelIDs_FinalRush, { 4604,	 -3669,	 3607 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_4]  = ItemBoxCheckData(0x01DEEE02, 0x03, LevelIDs_FinalRush, { 4546,	 -5328,	 5336 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_5]  = ItemBoxCheckData(0x01DEEE02, 0x04, LevelIDs_FinalRush, { 3692,	 -7249,	 4511 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_6]  = ItemBoxCheckData(0x01DEEE02, 0x05, LevelIDs_FinalRush, { 8269,	-12632,	 9131 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_7]  = ItemBoxCheckData(0x01DEEE02, 0x06, LevelIDs_FinalRush, { 6550,	-13874,	 9199 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_8]  = ItemBoxCheckData(0x01DEEE02, 0x07, LevelIDs_FinalRush, { 6726,	-14550,	13918 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_9]  = ItemBoxCheckData(0x01DEEE03, 0x00, LevelIDs_FinalRush, { 5736,	-15922,	19571 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_10] = ItemBoxCheckData(0x01DEEE03, 0x01, LevelIDs_FinalRush, { 5776,	-16199,	21457 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_11] = ItemBoxCheckData(0x01DEEE03, 0x02, LevelIDs_FinalRush, { 4142,	-16652,	24499 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_12] = ItemBoxCheckData(0x01DEEE03, 0x03, LevelIDs_FinalRush, { 2881,	-17741,	20353 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_LifeBox_13] = ItemBoxCheckData(0x01DEEE03, 0x04, LevelIDs_FinalRush, { 2475,	-17442,	19503 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_1]  = ItemBoxCheckData(0x01DEEE08, 0x00, LevelIDs_FinalRush, { 3406,	  -921,	  -40 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_2]  = ItemBoxCheckData(0x01DEEE08, 0x01, LevelIDs_FinalRush, { 4569,	 -1627,	  744 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_3]  = ItemBoxCheckData(0x01DEEE08, 0x02, LevelIDs_FinalRush, { 3906,	 -1617,	 1160 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_4]  = ItemBoxCheckData(0x01DEEE08, 0x03, LevelIDs_FinalRush, { 4582,	 -3669,	 3607 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_5]  = ItemBoxCheckData(0x01DEEE08, 0x04, LevelIDs_FinalRush, { 4125,	 -3341,	 3787 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_6]  = ItemBoxCheckData(0x01DEEE08, 0x05, LevelIDs_FinalRush, { 4474,	 -5264,	 5367 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_7]  = ItemBoxCheckData(0x01DEEE08, 0x06, LevelIDs_FinalRush, { 3720,	 -7105,	 4386 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_8]  = ItemBoxCheckData(0x01DEEE08, 0x07, LevelIDs_FinalRush, { 6260,	 -9551,	 5416 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_9]  = ItemBoxCheckData(0x01DEEE09, 0x00, LevelIDs_FinalRush, { 7810,	-11431,	 7934 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_10] = ItemBoxCheckData(0x01DEEE09, 0x01, LevelIDs_FinalRush, { 8052,	-11945,	 8330 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_11] = ItemBoxCheckData(0x01DEEE09, 0x02, LevelIDs_FinalRush, { 8329,	-12190,	 8662 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_12] = ItemBoxCheckData(0x01DEEE09, 0x03, LevelIDs_FinalRush, { 8263,	-12548,	 8996 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_13] = ItemBoxCheckData(0x01DEEE09, 0x04, LevelIDs_FinalRush, { 8325,	-12708,	 9260 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_14] = ItemBoxCheckData(0x01DEEE09, 0x05, LevelIDs_FinalRush, { 8329,	-12796,	 9376 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_15] = ItemBoxCheckData(0x01DEEE09, 0x06, LevelIDs_FinalRush, { 6900,	-14259,	 8649 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_16] = ItemBoxCheckData(0x01DEEE09, 0x07, LevelIDs_FinalRush, { 6687,	-14270,	 8649 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_17] = ItemBoxCheckData(0x01DEEE0A, 0x00, LevelIDs_FinalRush, { 6695,	-14015,	 8909 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_18] = ItemBoxCheckData(0x01DEEE0A, 0x01, LevelIDs_FinalRush, { 6740,	-14046,	 9966 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_19] = ItemBoxCheckData(0x01DEEE0A, 0x02, LevelIDs_FinalRush, { 6764,	-14700,	12358 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_20] = ItemBoxCheckData(0x01DEEE0A, 0x03, LevelIDs_FinalRush, { 6574,	-14876,	13785 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_21] = ItemBoxCheckData(0x01DEEE0A, 0x04, LevelIDs_FinalRush, { 6731,	-14794,	13703 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_22] = ItemBoxCheckData(0x01DEEE0A, 0x05, LevelIDs_FinalRush, { 6341,	-14293,	13748 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_23] = ItemBoxCheckData(0x01DEEE0A, 0x06, LevelIDs_FinalRush, { 6262,	-14194,	13836 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_24] = ItemBoxCheckData(0x01DEEE0A, 0x07, LevelIDs_FinalRush, { 5861,	-14150,	14025 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_25] = ItemBoxCheckData(0x01DEEE0B, 0x00, LevelIDs_FinalRush, { 5779,	-14150,	14158 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_26] = ItemBoxCheckData(0x01DEEE0B, 0x01, LevelIDs_FinalRush, { 5786,	-13941,	14325 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_27] = ItemBoxCheckData(0x01DEEE0B, 0x02, LevelIDs_FinalRush, { 5732,	-13455,	14386 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_28] = ItemBoxCheckData(0x01DEEE0B, 0x03, LevelIDs_FinalRush, { 5633,	-13170,	14422 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_29] = ItemBoxCheckData(0x01DEEE0B, 0x04, LevelIDs_FinalRush, { 5650,	-13155,	14473 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_30] = ItemBoxCheckData(0x01DEEE0B, 0x05, LevelIDs_FinalRush, { 5604,	-13156,	14538 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_31] = ItemBoxCheckData(0x01DEEE0B, 0x06, LevelIDs_FinalRush, { 5638,	-13150,	14630 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_32] = ItemBoxCheckData(0x01DEEE0B, 0x07, LevelIDs_FinalRush, { 5570,	-13132,	14684 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_33] = ItemBoxCheckData(0x01DEEE0C, 0x00, LevelIDs_FinalRush, { 5632,	-12722,	15537 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_34] = ItemBoxCheckData(0x01DEEE0C, 0x01, LevelIDs_FinalRush, { 5701,	-12716,	15521 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_35] = ItemBoxCheckData(0x01DEEE0C, 0x02, LevelIDs_FinalRush, { 5733,	-12729,	15587 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_36] = ItemBoxCheckData(0x01DEEE0C, 0x03, LevelIDs_FinalRush, { 4272,	-16652,	24499 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_37] = ItemBoxCheckData(0x01DEEE0C, 0x04, LevelIDs_FinalRush, { 2457,	-19090,	17674 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_38] = ItemBoxCheckData(0x01DEEE0C, 0x05, LevelIDs_FinalRush, { 2421,	-19090,	17645 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_39] = ItemBoxCheckData(0x01DEEE0C, 0x06, LevelIDs_FinalRush, { 2530,	-21145,	12253 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalRush_ItemBox_40] = ItemBoxCheckData(0x01DEEE0C, 0x07, LevelIDs_FinalRush, { 2530,	-21095,	12064 });

    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_LifeBox_1]  = ItemBoxCheckData(0x01DEEE0D, 0x00, LevelIDs_MeteorHerd, {  -100,	-542,	1057 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_LifeBox_2]  = ItemBoxCheckData(0x01DEEE0D, 0x01, LevelIDs_MeteorHerd, {  -189,	-433,	  60 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_LifeBox_3]  = ItemBoxCheckData(0x01DEEE0D, 0x02, LevelIDs_MeteorHerd, {    23,	-916,	  25 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_LifeBox_4]  = ItemBoxCheckData(0x01DEEE0D, 0x03, LevelIDs_MeteorHerd, {   131,	 173,	 133 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_LifeBox_5]  = ItemBoxCheckData(0x01DEEE0D, 0x04, LevelIDs_MeteorHerd, {  -205,	 491,	 520 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_1]  = ItemBoxCheckData(0x01DEEE0E, 0x00, LevelIDs_MeteorHerd, {  -809,	-517,	-809 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_2]  = ItemBoxCheckData(0x01DEEE0E, 0x01, LevelIDs_MeteorHerd, { -1094,	-550,	 212 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_3]  = ItemBoxCheckData(0x01DEEE0E, 0x02, LevelIDs_MeteorHerd, {  1076,	-550,	 323 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_4]  = ItemBoxCheckData(0x01DEEE0E, 0x03, LevelIDs_MeteorHerd, {   194,	-440,	  60 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_5]  = ItemBoxCheckData(0x01DEEE0E, 0x04, LevelIDs_MeteorHerd, {   514,	-428,	 -85 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_6]  = ItemBoxCheckData(0x01DEEE0E, 0x05, LevelIDs_MeteorHerd, {   -26,	-916,	  25 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_7]  = ItemBoxCheckData(0x01DEEE0E, 0x06, LevelIDs_MeteorHerd, {   128,	-616,	  36 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_8]  = ItemBoxCheckData(0x01DEEE0E, 0x07, LevelIDs_MeteorHerd, {  -305,	 310,	-242 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_9]  = ItemBoxCheckData(0x01DEEE0F, 0x00, LevelIDs_MeteorHerd, {  -376,	 375,	  53 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_10] = ItemBoxCheckData(0x01DEEE0F, 0x01, LevelIDs_MeteorHerd, {   201,	 550,	 422 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_11] = ItemBoxCheckData(0x01DEEE0F, 0x02, LevelIDs_MeteorHerd, {  -559,	 862,	  96 });
    outItemBoxChecks[ItemBoxCheck::IBC_MeteorHerd_ItemBox_12] = ItemBoxCheckData(0x01DEEE0F, 0x03, LevelIDs_MeteorHerd, {  -559,	 862,	  35 });

    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_LifeBox_1]  = ItemBoxCheckData(0x01DEEE10, 0x00, LevelIDs_CannonsCoreK, {    0,	   30,	    0 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_1]  = ItemBoxCheckData(0x01DEEE11, 0x00, LevelIDs_CannonsCoreE, { -500,	  608,	-1010 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_2]  = ItemBoxCheckData(0x01DEEE11, 0x01, LevelIDs_CannonsCoreE, {  570,	  130,	-2693 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_3]  = ItemBoxCheckData(0x01DEEE11, 0x02, LevelIDs_CannonsCoreE, {  569,	-2749,	-2769 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_4]  = ItemBoxCheckData(0x01DEEE11, 0x03, LevelIDs_CannonsCoreR, { -460,	   48,	    0 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_5]  = ItemBoxCheckData(0x01DEEE11, 0x04, LevelIDs_CannonsCoreR, {   79,	 -130,	 -989 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_6]  = ItemBoxCheckData(0x01DEEE11, 0x05, LevelIDs_CannonsCoreK, {    0,	  810,	 -130 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_7]  = ItemBoxCheckData(0x01DEEE11, 0x06, LevelIDs_CannonsCoreK, {   69,	 -130,	 -980 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_8]  = ItemBoxCheckData(0x01DEEE11, 0x07, LevelIDs_CannonsCoreK, {  -70,	 -130,	 -980 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_9]  = ItemBoxCheckData(0x01DEEE12, 0x00, LevelIDs_CannonsCoreK, {  -70,	  274,	 -880 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_10] = ItemBoxCheckData(0x01DEEE12, 0x01, LevelIDs_CannonsCoreK, {   69,	  274,	 -880 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_11] = ItemBoxCheckData(0x01DEEE12, 0x02, LevelIDs_CannonsCoreK, {    0,	  139,	-1440 });
    outItemBoxChecks[ItemBoxCheck::IBC_CannonCore_ItemBox_12] = ItemBoxCheckData(0x01DEEE12, 0x03, LevelIDs_CannonsCoreK, {  -74,	 -140,	-1325 });

    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_LifeBox_1]  = ItemBoxCheckData(0x01DEEE13, 0x00, LevelIDs_FinalChase, { 3712,	 -4575,	 3432 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_LifeBox_2]  = ItemBoxCheckData(0x01DEEE13, 0x01, LevelIDs_FinalChase, { 4238,	 -4329,	 7096 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_LifeBox_3]  = ItemBoxCheckData(0x01DEEE13, 0x02, LevelIDs_FinalChase, { 4431,	 -5331,	 8904 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_LifeBox_4]  = ItemBoxCheckData(0x01DEEE13, 0x03, LevelIDs_FinalChase, { 3591,	 -4236,	13341 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_LifeBox_5]  = ItemBoxCheckData(0x01DEEE13, 0x04, LevelIDs_FinalChase, { 3532,	 -6739,	17450 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_LifeBox_6]  = ItemBoxCheckData(0x01DEEE13, 0x05, LevelIDs_FinalChase, { 2213,	 -6765,	18283 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_LifeBox_7]  = ItemBoxCheckData(0x01DEEE13, 0x06, LevelIDs_FinalChase, { 2154,	 -7204,	18230 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_LifeBox_8]  = ItemBoxCheckData(0x01DEEE13, 0x07, LevelIDs_FinalChase, {  230,	 -9009,	11943 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_LifeBox_9]  = ItemBoxCheckData(0x01DEEE14, 0x00, LevelIDs_FinalChase, { -144,	 -8920,	10493 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_1]  = ItemBoxCheckData(0x01DEEE15, 0x00, LevelIDs_FinalChase, { 3173,	 -4045,	 2303 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_2]  = ItemBoxCheckData(0x01DEEE15, 0x01, LevelIDs_FinalChase, { 3210,	 -4045,	 2303 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_3]  = ItemBoxCheckData(0x01DEEE15, 0x02, LevelIDs_FinalChase, { 3195,	 -4398,	 2910 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_4]  = ItemBoxCheckData(0x01DEEE15, 0x03, LevelIDs_FinalChase, { 3244,	 -4537,	 3606 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_5]  = ItemBoxCheckData(0x01DEEE15, 0x04, LevelIDs_FinalChase, { 3712,	 -4575,	 3492 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_6]  = ItemBoxCheckData(0x01DEEE15, 0x05, LevelIDs_FinalChase, { 3622,	 -4529,	 4210 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_7]  = ItemBoxCheckData(0x01DEEE15, 0x06, LevelIDs_FinalChase, { 3720,	 -4516,	 4413 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_8]  = ItemBoxCheckData(0x01DEEE15, 0x07, LevelIDs_FinalChase, { 3593,	 -4580,	 4847 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_9]  = ItemBoxCheckData(0x01DEEE16, 0x00, LevelIDs_FinalChase, { 4327,	 -4309,	 6874 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_10] = ItemBoxCheckData(0x01DEEE16, 0x01, LevelIDs_FinalChase, { 4350,	 -4412,	 7333 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_11] = ItemBoxCheckData(0x01DEEE16, 0x02, LevelIDs_FinalChase, { 4346,	 -5144,	 6972 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_12] = ItemBoxCheckData(0x01DEEE16, 0x03, LevelIDs_FinalChase, { 4384,	 -5144,	 7090 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_13] = ItemBoxCheckData(0x01DEEE16, 0x04, LevelIDs_FinalChase, { 4365,	 -5165,	 8700 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_14] = ItemBoxCheckData(0x01DEEE16, 0x05, LevelIDs_FinalChase, { 4301,	 -5331,	 8904 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_15] = ItemBoxCheckData(0x01DEEE16, 0x06, LevelIDs_FinalChase, { 4291,	 -5216,	10499 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_16] = ItemBoxCheckData(0x01DEEE16, 0x07, LevelIDs_FinalChase, { 4200,	 -4765,	10609 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_17] = ItemBoxCheckData(0x01DEEE17, 0x00, LevelIDs_FinalChase, { 3987,	 -4229,	10534 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_18] = ItemBoxCheckData(0x01DEEE17, 0x01, LevelIDs_FinalChase, { 4087,	 -4456,	10532 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_19] = ItemBoxCheckData(0x01DEEE17, 0x02, LevelIDs_FinalChase, { 4122,	 -4420,	10672 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_20] = ItemBoxCheckData(0x01DEEE17, 0x03, LevelIDs_FinalChase, { 4286,	 -3861,	11010 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_21] = ItemBoxCheckData(0x01DEEE17, 0x04, LevelIDs_FinalChase, { 3554,	 -4111,	13253 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_22] = ItemBoxCheckData(0x01DEEE17, 0x05, LevelIDs_FinalChase, { 3263,	 -5827,	15476 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_23] = ItemBoxCheckData(0x01DEEE17, 0x06, LevelIDs_FinalChase, { 3372,	 -5947,	15596 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_24] = ItemBoxCheckData(0x01DEEE17, 0x07, LevelIDs_FinalChase, { 3569,	 -6739,	17185 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_25] = ItemBoxCheckData(0x01DEEE18, 0x00, LevelIDs_FinalChase, { 3343,	 -6739,	17320 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_26] = ItemBoxCheckData(0x01DEEE18, 0x01, LevelIDs_FinalChase, { 1933,	 -7129,	18258 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_27] = ItemBoxCheckData(0x01DEEE18, 0x02, LevelIDs_FinalChase, {  144,	 -8596,	17218 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_28] = ItemBoxCheckData(0x01DEEE18, 0x03, LevelIDs_FinalChase, {  189,	-10086,	13993 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_29] = ItemBoxCheckData(0x01DEEE18, 0x04, LevelIDs_FinalChase, {   46,	 -9524,	13697 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_30] = ItemBoxCheckData(0x01DEEE18, 0x05, LevelIDs_FinalChase, {  230,	 -9009,	11897 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_31] = ItemBoxCheckData(0x01DEEE18, 0x06, LevelIDs_FinalChase, {  230,	 -9009,	11920 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_32] = ItemBoxCheckData(0x01DEEE18, 0x07, LevelIDs_FinalChase, {  371,	 -9003,	10621 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_33] = ItemBoxCheckData(0x01DEEE19, 0x00, LevelIDs_FinalChase, { -610,	 -8373,	10156 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_34] = ItemBoxCheckData(0x01DEEE19, 0x01, LevelIDs_FinalChase, { -665,	 -7796,	10135 });
    outItemBoxChecks[ItemBoxCheck::IBC_FinalChase_ItemBox_35] = ItemBoxCheckData(0x01DEEE19, 0x02, LevelIDs_FinalChase, { -672,	 -7439,	10154 });

    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_1]  = ItemBoxCheckData(0x01DEEE1A, 0x00, LevelIDs_CosmicWall, {  109,	   0,	  -22 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_2]  = ItemBoxCheckData(0x01DEEE1A, 0x01, LevelIDs_CosmicWall, {  109,	   0,	   22 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_3]  = ItemBoxCheckData(0x01DEEE1A, 0x02, LevelIDs_CosmicWall, { 2132,	1032,	 -522 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_4]  = ItemBoxCheckData(0x01DEEE1A, 0x03, LevelIDs_CosmicWall, { 3638,	2552,	-1059 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_5]  = ItemBoxCheckData(0x01DEEE1A, 0x04, LevelIDs_CosmicWall, { 3780,	2540,	 -983 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_6]  = ItemBoxCheckData(0x01DEEE1A, 0x05, LevelIDs_CosmicWall, { 3685,	3020,	-1014 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_7]  = ItemBoxCheckData(0x01DEEE1A, 0x06, LevelIDs_CosmicWall, { 3679,	3505,	-1000 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_8]  = ItemBoxCheckData(0x01DEEE1A, 0x07, LevelIDs_CosmicWall, { 4032,	3870,	 -941 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_9]  = ItemBoxCheckData(0x01DEEE1B, 0x00, LevelIDs_CosmicWall, { 4299,	3167,	-1084 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_10] = ItemBoxCheckData(0x01DEEE1B, 0x01, LevelIDs_CosmicWall, { 5566,	2215,	 -975 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_11] = ItemBoxCheckData(0x01DEEE1B, 0x02, LevelIDs_CosmicWall, { 5695,	2213,	 -206 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_12] = ItemBoxCheckData(0x01DEEE1B, 0x03, LevelIDs_CosmicWall, { 5477,	3167,	 3752 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_13] = ItemBoxCheckData(0x01DEEE1B, 0x04, LevelIDs_CosmicWall, { 5712,	3167,	 3752 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_14] = ItemBoxCheckData(0x01DEEE1B, 0x05, LevelIDs_CosmicWall, { 5522,	3062,	 4102 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_15] = ItemBoxCheckData(0x01DEEE1B, 0x06, LevelIDs_CosmicWall, { 5522,	3062,	 4057 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_16] = ItemBoxCheckData(0x01DEEE1B, 0x07, LevelIDs_CosmicWall, { 5477,	3062,	 4057 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_17] = ItemBoxCheckData(0x01DEEE1C, 0x00, LevelIDs_CosmicWall, { 5477,	3062,	 4102 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_18] = ItemBoxCheckData(0x01DEEE1C, 0x01, LevelIDs_CosmicWall, { 5598,	2050,	 4306 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_19] = ItemBoxCheckData(0x01DEEE1C, 0x02, LevelIDs_CosmicWall, { 6552,	3408,	 8501 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_20] = ItemBoxCheckData(0x01DEEE1C, 0x03, LevelIDs_CosmicWall, { 6725,	3572,	 9122 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_21] = ItemBoxCheckData(0x01DEEE1C, 0x04, LevelIDs_CosmicWall, { 6641,	3711,	 9188 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_22] = ItemBoxCheckData(0x01DEEE1C, 0x05, LevelIDs_CosmicWall, { 6767,	4102,	 9207 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_23] = ItemBoxCheckData(0x01DEEE1C, 0x06, LevelIDs_CosmicWall, { 6624,	4492,	 9207 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_24] = ItemBoxCheckData(0x01DEEE1C, 0x07, LevelIDs_CosmicWall, { 6624,	4812,	 9207 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_25] = ItemBoxCheckData(0x01DEEE1D, 0x00, LevelIDs_CosmicWall, { 6707,	4317,	 9533 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_26] = ItemBoxCheckData(0x01DEEE1D, 0x01, LevelIDs_CosmicWall, { 6587,	4317,	 9533 });
    outItemBoxChecks[ItemBoxCheck::IBC_CosmicWall_ItemBox_27] = ItemBoxCheckData(0x01DEEE1D, 0x02, LevelIDs_CosmicWall, { 6474,	3513,	12428 });

    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_LifeBox_1]  = ItemBoxCheckData(0x01DEEE1E, 0x00, LevelIDs_MadSpace, {     0,	 470,	  91 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_LifeBox_2]  = ItemBoxCheckData(0x01DEEE1E, 0x01, LevelIDs_MadSpace, {  -752,	 197,	-793 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_LifeBox_3]  = ItemBoxCheckData(0x01DEEE1E, 0x02, LevelIDs_MadSpace, {  1163,	 187,	-388 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_LifeBox_4]  = ItemBoxCheckData(0x01DEEE1E, 0x03, LevelIDs_MadSpace, {   500,	1706,	1081 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_1]  = ItemBoxCheckData(0x01DEEE1F, 0x00, LevelIDs_MadSpace, {   -93,	 470,	  13 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_2]  = ItemBoxCheckData(0x01DEEE1F, 0x01, LevelIDs_MadSpace, {     0,	 470,	 -90 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_3]  = ItemBoxCheckData(0x01DEEE1F, 0x02, LevelIDs_MadSpace, {  -762,	 197,	 759 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_4]  = ItemBoxCheckData(0x01DEEE1F, 0x03, LevelIDs_MadSpace, { -1022,	 198,	 339 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_5]  = ItemBoxCheckData(0x01DEEE1F, 0x04, LevelIDs_MadSpace, { -1045,	 198,	 269 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_6]  = ItemBoxCheckData(0x01DEEE1F, 0x05, LevelIDs_MadSpace, {  -259,	 620,	 195 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_7]  = ItemBoxCheckData(0x01DEEE1F, 0x06, LevelIDs_MadSpace, {     0,	 600,	-400 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_8]  = ItemBoxCheckData(0x01DEEE1F, 0x07, LevelIDs_MadSpace, {    52,	2107,	 491 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_9]  = ItemBoxCheckData(0x01DEEE24, 0x00, LevelIDs_MadSpace, {   628,	1726,	 666 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_10] = ItemBoxCheckData(0x01DEEE24, 0x01, LevelIDs_MadSpace, {   448,	1804,	 500 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_11] = ItemBoxCheckData(0x01DEEE24, 0x02, LevelIDs_MadSpace, {   134,	1792,	1068 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_12] = ItemBoxCheckData(0x01DEEE24, 0x03, LevelIDs_MadSpace, {   674,	2710,	-299 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_13] = ItemBoxCheckData(0x01DEEE24, 0x04, LevelIDs_MadSpace, {   728,	2710,	-299 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_14] = ItemBoxCheckData(0x01DEEE24, 0x05, LevelIDs_MadSpace, {   789,	3523,	-456 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_15] = ItemBoxCheckData(0x01DEEE24, 0x06, LevelIDs_MadSpace, {   828,	3483,	-617 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_16] = ItemBoxCheckData(0x01DEEE24, 0x07, LevelIDs_MadSpace, {   527,	3864,	 524 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_17] = ItemBoxCheckData(0x01DEEE25, 0x00, LevelIDs_MadSpace, {   857,	3916,	 454 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_18] = ItemBoxCheckData(0x01DEEE25, 0x01, LevelIDs_MadSpace, {   213,	3999,	 358 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_19] = ItemBoxCheckData(0x01DEEE25, 0x02, LevelIDs_MadSpace, {  1066,	4125,	 199 });
    outItemBoxChecks[ItemBoxCheck::IBC_MadSpace_ItemBox_20] = ItemBoxCheckData(0x01DEEE25, 0x03, LevelIDs_MadSpace, {   834,	4183,	-356 });

    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_1]  = ItemBoxCheckData(0x01DEEE26, 0x00, LevelIDs_GreenHill, {   -61,	  70,	 -430 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_2]  = ItemBoxCheckData(0x01DEEE26, 0x01, LevelIDs_GreenHill, {  -203,	 147,	-1100 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_3]  = ItemBoxCheckData(0x01DEEE26, 0x02, LevelIDs_GreenHill, {  -970,	 130,	-3000 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_4]  = ItemBoxCheckData(0x01DEEE26, 0x03, LevelIDs_GreenHill, {  -689,	-140,	-3157 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_5]  = ItemBoxCheckData(0x01DEEE26, 0x04, LevelIDs_GreenHill, {  -689,	-140,	-3172 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_6]  = ItemBoxCheckData(0x01DEEE26, 0x05, LevelIDs_GreenHill, {  -689,	-140,	-3187 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_7]  = ItemBoxCheckData(0x01DEEE26, 0x06, LevelIDs_GreenHill, {  -689,	-140,	-3202 }, 10.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_8]  = ItemBoxCheckData(0x01DEEE26, 0x07, LevelIDs_GreenHill, {  -934,	 125,	-3656 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_9]  = ItemBoxCheckData(0x01DEEE27, 0x00, LevelIDs_GreenHill, { -1395,	-348,	-5109 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_10] = ItemBoxCheckData(0x01DEEE27, 0x01, LevelIDs_GreenHill, { -2129,	-810,	-5819 });
    outItemBoxChecks[ItemBoxCheck::IBC_GreenHill_ItemBox_11] = ItemBoxCheckData(0x01DEEE27, 0x02, LevelIDs_GreenHill, { -2159,	-768,	-6019 });

    outItemBoxChecks[ItemBoxCheck::IBC_Route101_ItemBox_1] = ItemBoxCheckData(0x01DEEE28, 0x00, LevelIDs_Route101280, {  9629,	 -794,	-21740 }, 60.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_Route101_ItemBox_2] = ItemBoxCheckData(0x01DEEE28, 0x01, LevelIDs_Route101280, { 17252,	-1044,	-19647 }, 60.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_Route101_ItemBox_3] = ItemBoxCheckData(0x01DEEE28, 0x02, LevelIDs_Route101280, { 18486,	-1155,	-14206 }, 70.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_Route101_ItemBox_4] = ItemBoxCheckData(0x01DEEE28, 0x03, LevelIDs_Route101280, { 19700,	-1394,	-5995  }, 60.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_Route101_ItemBox_5] = ItemBoxCheckData(0x01DEEE28, 0x04, LevelIDs_Route101280, { 15242,	-2744,	19542  }, 60.0f);

    outItemBoxChecks[ItemBoxCheck::IBC_Route280_ItemBox_1] = ItemBoxCheckData(0x01DEEE29, 0x00, LevelIDs_Route101280, {  9227,	 -394,	-21762 }, 60.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_Route280_ItemBox_2] = ItemBoxCheckData(0x01DEEE29, 0x01, LevelIDs_Route101280, { 23113,	-1844,	-20898 }, 60.0f);
    outItemBoxChecks[ItemBoxCheck::IBC_Route280_ItemBox_3] = ItemBoxCheckData(0x01DEEE29, 0x02, LevelIDs_Route101280, { 12966,	-2344,	-17686 }, 60.0f);
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

    outChaoGardenChecks[ChaoGardenCheck::CGC_Beginner_Karate_1]     = ChaoGardenCheckData(0x01DEF831, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Beginner_Karate_2]     = ChaoGardenCheckData(0x01DEF831, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Beginner_Karate_3]     = ChaoGardenCheckData(0x01DEF831, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Beginner_Karate_4]     = ChaoGardenCheckData(0x01DEF831, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Beginner_Karate_5]     = ChaoGardenCheckData(0x01DEF831, 4);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Intermediate_Karate_1] = ChaoGardenCheckData(0x01DEF832, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Intermediate_Karate_2] = ChaoGardenCheckData(0x01DEF832, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Intermediate_Karate_3] = ChaoGardenCheckData(0x01DEF832, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Intermediate_Karate_4] = ChaoGardenCheckData(0x01DEF832, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Intermediate_Karate_5] = ChaoGardenCheckData(0x01DEF832, 4);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Expert_Karate_1]       = ChaoGardenCheckData(0x01DEF833, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Expert_Karate_2]       = ChaoGardenCheckData(0x01DEF833, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Expert_Karate_3]       = ChaoGardenCheckData(0x01DEF833, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Expert_Karate_4]       = ChaoGardenCheckData(0x01DEF833, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Expert_Karate_5]       = ChaoGardenCheckData(0x01DEF833, 4);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Super_Karate_1]        = ChaoGardenCheckData(0x01DEF834, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Super_Karate_2]        = ChaoGardenCheckData(0x01DEF834, 1);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Super_Karate_3]        = ChaoGardenCheckData(0x01DEF834, 2);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Super_Karate_4]        = ChaoGardenCheckData(0x01DEF834, 3);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Super_Karate_5]        = ChaoGardenCheckData(0x01DEF834, 4);
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

    outChaoRacePacks[ChaoGardenCheck::CGC_Beginner_Karate_5]     = std::vector<int>{ CGC_Beginner_Karate_1, CGC_Beginner_Karate_2, CGC_Beginner_Karate_3, CGC_Beginner_Karate_4 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Intermediate_Karate_5] = std::vector<int>{ CGC_Intermediate_Karate_1, CGC_Intermediate_Karate_2, CGC_Intermediate_Karate_3, CGC_Intermediate_Karate_4 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Expert_Karate_5]       = std::vector<int>{ CGC_Expert_Karate_1, CGC_Expert_Karate_2, CGC_Expert_Karate_3, CGC_Expert_Karate_4 };
    outChaoRacePacks[ChaoGardenCheck::CGC_Super_Karate_5]        = std::vector<int>{ CGC_Super_Karate_1, CGC_Super_Karate_2, CGC_Super_Karate_3, CGC_Super_Karate_4 };
}

void InitializeChaoStatChecks(std::map<int, ChaoStatCheckData>& outChaoStatChecks)
{
    outChaoStatChecks.clear();

    for (int i = 1; i <= 99; i++)
    {
        outChaoStatChecks[ChaoStatCheck::CSC_Swim_BEGIN         + i] = ChaoStatCheckData(0x01DEC7CE, ChaoStatCheckType::CSCT_Swim, i);
        outChaoStatChecks[ChaoStatCheck::CSC_Fly_BEGIN          + i] = ChaoStatCheckData(0x01DEC7CF, ChaoStatCheckType::CSCT_Fly, i);
        outChaoStatChecks[ChaoStatCheck::CSC_Run_BEGIN          + i] = ChaoStatCheckData(0x01DEC7D0, ChaoStatCheckType::CSCT_Run, i);
        outChaoStatChecks[ChaoStatCheck::CSC_Power_BEGIN        + i] = ChaoStatCheckData(0x01DEC7D1, ChaoStatCheckType::CSCT_Power, i);
        outChaoStatChecks[ChaoStatCheck::CSC_Stamina_BEGIN      + i] = ChaoStatCheckData(0x01DEC7D2, ChaoStatCheckType::CSCT_Stamina, i);
        outChaoStatChecks[ChaoStatCheck::CSC_Luck_BEGIN         + i] = ChaoStatCheckData(0x01DEC7D3, ChaoStatCheckType::CSCT_Luck, i);
        outChaoStatChecks[ChaoStatCheck::CSC_Intelligence_BEGIN + i] = ChaoStatCheckData(0x01DEC7D4, ChaoStatCheckType::CSCT_Intelligence, i);
    }
}

void InitializeChaoBodyPartChecks(std::map<int, ChaoBodyPartCheckData>& outChaoBodyPartChecks)
{
    outChaoBodyPartChecks.clear();

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PenguinArms]     = ChaoBodyPartCheckData(0x01DEC7D5, SA2BAnimal_Penguin, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PenguinForehead] = ChaoBodyPartCheckData(0x01DEC7D5, SA2BAnimal_Penguin, ChaoBodyPart::CBP_Forehead);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PenguinLegs]     = ChaoBodyPartCheckData(0x01DEC7D5, SA2BAnimal_Penguin, ChaoBodyPart::CBP_Legs);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SealArms] = ChaoBodyPartCheckData(0x01DEC7D6, SA2BAnimal_Seal, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SealTail] = ChaoBodyPartCheckData(0x01DEC7D6, SA2BAnimal_Seal, ChaoBodyPart::CBP_Tail);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_OtterArms] = ChaoBodyPartCheckData(0x01DEC7D7, SA2BAnimal_Otter, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_OtterEars] = ChaoBodyPartCheckData(0x01DEC7D7, SA2BAnimal_Otter, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_OtterFace] = ChaoBodyPartCheckData(0x01DEC7D7, SA2BAnimal_Otter, ChaoBodyPart::CBP_Face);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_OtterLegs] = ChaoBodyPartCheckData(0x01DEC7D7, SA2BAnimal_Otter, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_OtterTail] = ChaoBodyPartCheckData(0x01DEC7D7, SA2BAnimal_Otter, ChaoBodyPart::CBP_Tail);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_RabbitArms] = ChaoBodyPartCheckData(0x01DEC7DC, SA2BAnimal_Rabbit, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_RabbitEars] = ChaoBodyPartCheckData(0x01DEC7DC, SA2BAnimal_Rabbit, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_RabbitLegs] = ChaoBodyPartCheckData(0x01DEC7DC, SA2BAnimal_Rabbit, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_RabbitTail] = ChaoBodyPartCheckData(0x01DEC7DC, SA2BAnimal_Rabbit, ChaoBodyPart::CBP_Tail);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_CheetahArms] = ChaoBodyPartCheckData(0x01DEC7DD, SA2BAnimal_Cheetah, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_CheetahEars] = ChaoBodyPartCheckData(0x01DEC7DD, SA2BAnimal_Cheetah, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_CheetahLegs] = ChaoBodyPartCheckData(0x01DEC7DD, SA2BAnimal_Cheetah, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_CheetahTail] = ChaoBodyPartCheckData(0x01DEC7DD, SA2BAnimal_Cheetah, ChaoBodyPart::CBP_Tail);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_WarthogArms] = ChaoBodyPartCheckData(0x01DEC7DE, SA2BAnimal_Warthog, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_WarthogEars] = ChaoBodyPartCheckData(0x01DEC7DE, SA2BAnimal_Warthog, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_WarthogFace] = ChaoBodyPartCheckData(0x01DEC7DE, SA2BAnimal_Warthog, ChaoBodyPart::CBP_Face);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_WarthogLegs] = ChaoBodyPartCheckData(0x01DEC7DE, SA2BAnimal_Warthog, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_WarthogTail] = ChaoBodyPartCheckData(0x01DEC7DE, SA2BAnimal_Warthog, ChaoBodyPart::CBP_Tail);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_BearArms] = ChaoBodyPartCheckData(0x01DEC7DF, SA2BAnimal_Bear, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_BearEars] = ChaoBodyPartCheckData(0x01DEC7DF, SA2BAnimal_Bear, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_BearLegs] = ChaoBodyPartCheckData(0x01DEC7DF, SA2BAnimal_Bear, ChaoBodyPart::CBP_Legs);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_TigerArms] = ChaoBodyPartCheckData(0x01DEC7E0, SA2BAnimal_Tiger, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_TigerEars] = ChaoBodyPartCheckData(0x01DEC7E0, SA2BAnimal_Tiger, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_TigerLegs] = ChaoBodyPartCheckData(0x01DEC7E0, SA2BAnimal_Tiger, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_TigerTail] = ChaoBodyPartCheckData(0x01DEC7E0, SA2BAnimal_Tiger, ChaoBodyPart::CBP_Tail);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_GorillaArms]     = ChaoBodyPartCheckData(0x01DEC7E1, SA2BAnimal_Gorilla, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_GorillaEars]     = ChaoBodyPartCheckData(0x01DEC7E1, SA2BAnimal_Gorilla, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_GorillaForehead] = ChaoBodyPartCheckData(0x01DEC7E1, SA2BAnimal_Gorilla, ChaoBodyPart::CBP_Forehead);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_GorillaLegs]     = ChaoBodyPartCheckData(0x01DEC7E1, SA2BAnimal_Gorilla, ChaoBodyPart::CBP_Legs);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PeacockForehead] = ChaoBodyPartCheckData(0x01DEC7E2, SA2BAnimal_Peacock, ChaoBodyPart::CBP_Forehead);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PeacockLegs]     = ChaoBodyPartCheckData(0x01DEC7E2, SA2BAnimal_Peacock, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PeacockTail]     = ChaoBodyPartCheckData(0x01DEC7E2, SA2BAnimal_Peacock, ChaoBodyPart::CBP_Tail);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PeacockWings]    = ChaoBodyPartCheckData(0x01DEC7E2, SA2BAnimal_Peacock, ChaoBodyPart::CBP_Wings);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_ParrotForehead] = ChaoBodyPartCheckData(0x01DEC7E3, SA2BAnimal_Parrot, ChaoBodyPart::CBP_Forehead);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_ParrotLegs]     = ChaoBodyPartCheckData(0x01DEC7E3, SA2BAnimal_Parrot, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_ParrotTail]     = ChaoBodyPartCheckData(0x01DEC7E3, SA2BAnimal_Parrot, ChaoBodyPart::CBP_Tail);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_ParrotWings]    = ChaoBodyPartCheckData(0x01DEC7E3, SA2BAnimal_Parrot, ChaoBodyPart::CBP_Wings);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_CondorEars]  = ChaoBodyPartCheckData(0x01DEC7E8, SA2BAnimal_Condor, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_CondorLegs]  = ChaoBodyPartCheckData(0x01DEC7E8, SA2BAnimal_Condor, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_CondorTail]  = ChaoBodyPartCheckData(0x01DEC7E8, SA2BAnimal_Condor, ChaoBodyPart::CBP_Tail);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_CondorWings] = ChaoBodyPartCheckData(0x01DEC7E8, SA2BAnimal_Condor, ChaoBodyPart::CBP_Wings);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SkunkArms]     = ChaoBodyPartCheckData(0x01DEC7E9, SA2BAnimal_Skunk, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SkunkForehead] = ChaoBodyPartCheckData(0x01DEC7E9, SA2BAnimal_Skunk, ChaoBodyPart::CBP_Forehead);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SkunkLegs]     = ChaoBodyPartCheckData(0x01DEC7E9, SA2BAnimal_Skunk, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SkunkTail]     = ChaoBodyPartCheckData(0x01DEC7E9, SA2BAnimal_Skunk, ChaoBodyPart::CBP_Tail);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SheepArms] = ChaoBodyPartCheckData(0x01DEC7EA, SA2BAnimal_Sheep, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SheepEars] = ChaoBodyPartCheckData(0x01DEC7EA, SA2BAnimal_Sheep, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SheepLegs] = ChaoBodyPartCheckData(0x01DEC7EA, SA2BAnimal_Sheep, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SheepHorn] = ChaoBodyPartCheckData(0x01DEC7EA, SA2BAnimal_Sheep, ChaoBodyPart::CBP_Horn);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_SheepTail] = ChaoBodyPartCheckData(0x01DEC7EA, SA2BAnimal_Sheep, ChaoBodyPart::CBP_Tail);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_RaccoonArms] = ChaoBodyPartCheckData(0x01DEC7EB, SA2BAnimal_Raccoon, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_RaccoonEars] = ChaoBodyPartCheckData(0x01DEC7EB, SA2BAnimal_Raccoon, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_RaccoonLegs] = ChaoBodyPartCheckData(0x01DEC7EB, SA2BAnimal_Raccoon, ChaoBodyPart::CBP_Legs);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_DragonArms]  = ChaoBodyPartCheckData(0x01DEC7ED, SA2BAnimal_Dragon, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_DragonEars]  = ChaoBodyPartCheckData(0x01DEC7ED, SA2BAnimal_Dragon, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_DragonLegs]  = ChaoBodyPartCheckData(0x01DEC7ED, SA2BAnimal_Dragon, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_DragonHorn]  = ChaoBodyPartCheckData(0x01DEC7ED, SA2BAnimal_Dragon, ChaoBodyPart::CBP_Horn);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_DragonTail]  = ChaoBodyPartCheckData(0x01DEC7ED, SA2BAnimal_Dragon, ChaoBodyPart::CBP_Tail);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_DragonWings] = ChaoBodyPartCheckData(0x01DEC7ED, SA2BAnimal_Dragon, ChaoBodyPart::CBP_Wings);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_UnicornArms]     = ChaoBodyPartCheckData(0x01DEC7EE, SA2BAnimal_Unicorn, ChaoBodyPart::CBP_Arms);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_UnicornEars]     = ChaoBodyPartCheckData(0x01DEC7EE, SA2BAnimal_Unicorn, ChaoBodyPart::CBP_Ears);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_UnicornForehead] = ChaoBodyPartCheckData(0x01DEC7EE, SA2BAnimal_Unicorn, ChaoBodyPart::CBP_Forehead);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_UnicornLegs]     = ChaoBodyPartCheckData(0x01DEC7EE, SA2BAnimal_Unicorn, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_UnicornTail]     = ChaoBodyPartCheckData(0x01DEC7EE, SA2BAnimal_Unicorn, ChaoBodyPart::CBP_Tail);

    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PhoenixForehead] = ChaoBodyPartCheckData(0x01DEC7EF, SA2BAnimal_Phoenix, ChaoBodyPart::CBP_Forehead);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PhoenixLegs]     = ChaoBodyPartCheckData(0x01DEC7EF, SA2BAnimal_Phoenix, ChaoBodyPart::CBP_Legs);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PhoenixTail]     = ChaoBodyPartCheckData(0x01DEC7EF, SA2BAnimal_Phoenix, ChaoBodyPart::CBP_Tail);
    outChaoBodyPartChecks[ChaoBodyPartCheck::CBPC_PhoenixWings]    = ChaoBodyPartCheckData(0x01DEC7EF, SA2BAnimal_Phoenix, ChaoBodyPart::CBP_Wings);
}

void InitializeChaoKindergartenChecks(std::map<int, ChaoKindergartenCheckData>& outChaoKindergartenChecks)
{
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Drawing_1] = ChaoKindergartenCheckData(0x01DEC7F4, 0x00);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Drawing_2] = ChaoKindergartenCheckData(0x01DEC7F4, 0x01);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Drawing_3] = ChaoKindergartenCheckData(0x01DEC7F4, 0x02);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Drawing_4] = ChaoKindergartenCheckData(0x01DEC7F4, 0x03);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Drawing_5] = ChaoKindergartenCheckData(0x01DEC7F4, 0x04);

    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Shake_Dance] = ChaoKindergartenCheckData(0x01DEC7F4, 0x08);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Spin_Dance]  = ChaoKindergartenCheckData(0x01DEC7F4, 0x09);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Step_Dance]  = ChaoKindergartenCheckData(0x01DEC7F4, 0x0A);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_GoGo_Dance]  = ChaoKindergartenCheckData(0x01DEC7F4, 0x0B);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Exercise]    = ChaoKindergartenCheckData(0x01DEC7F4, 0x0C);

    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Song_1] = ChaoKindergartenCheckData(0x01DEC7F4, 0x10);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Song_2] = ChaoKindergartenCheckData(0x01DEC7F4, 0x11);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Song_3] = ChaoKindergartenCheckData(0x01DEC7F4, 0x12);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Song_4] = ChaoKindergartenCheckData(0x01DEC7F4, 0x13);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Song_5] = ChaoKindergartenCheckData(0x01DEC7F4, 0x14);

    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Bell]       = ChaoKindergartenCheckData(0x01DEC7F4, 0x18);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Castanets]  = ChaoKindergartenCheckData(0x01DEC7F4, 0x19);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Cymbals]    = ChaoKindergartenCheckData(0x01DEC7F4, 0x1A);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Drum]       = ChaoKindergartenCheckData(0x01DEC7F4, 0x1B);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Flute]      = ChaoKindergartenCheckData(0x01DEC7F4, 0x1C);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Maracas]    = ChaoKindergartenCheckData(0x01DEC7F4, 0x1D);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Trumpet]    = ChaoKindergartenCheckData(0x01DEC7F4, 0x1E);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_Tambourine] = ChaoKindergartenCheckData(0x01DEC7F4, 0x1F);

    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_AnyDrawing]    = ChaoKindergartenCheckData(0x01DEC7F8, 0x20);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_AnyDance]      = ChaoKindergartenCheckData(0x01DEC7F8, 0x21);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_AnySong]       = ChaoKindergartenCheckData(0x01DEC7F8, 0x22);
    outChaoKindergartenChecks[ChaoKindergartenCheck::CKgC_AnyInstrument] = ChaoKindergartenCheckData(0x01DEC7F8, 0x23);
}

void InitializeBlackMarketChecks(std::map<int, BlackMarketCheckData>& outBlackMarketChecks)
{
    outBlackMarketChecks.clear();

    for (int i = 1; i <= 64; i++)
    {
        outBlackMarketChecks[BlackMarketCheck::BMC_BEGIN + i] = BlackMarketCheckData(0x01DEC800, i);
    }
}

void InitializeKartRaceChecks(std::map<int, KartRaceCheckData>& outKartRaceChecks)
{
    outKartRaceChecks.clear();

    outKartRaceChecks[KartRaceCheck::KRC_Beginner_Sonic]    = KartRaceCheckData(0x01DEF5BC);
    outKartRaceChecks[KartRaceCheck::KRC_Standard_Sonic]    = KartRaceCheckData(0x01DEF5C9);
    outKartRaceChecks[KartRaceCheck::KRC_Expert_Sonic]      = KartRaceCheckData(0x01DEF5D6);

    outKartRaceChecks[KartRaceCheck::KRC_Beginner_Tails]    = KartRaceCheckData(0x01DEF5E3);
    outKartRaceChecks[KartRaceCheck::KRC_Standard_Tails]    = KartRaceCheckData(0x01DEF5F0);
    outKartRaceChecks[KartRaceCheck::KRC_Expert_Tails]      = KartRaceCheckData(0x01DEF5FD);

    outKartRaceChecks[KartRaceCheck::KRC_Beginner_Knuckles] = KartRaceCheckData(0x01DEF60A);
    outKartRaceChecks[KartRaceCheck::KRC_Standard_Knuckles] = KartRaceCheckData(0x01DEF617);
    outKartRaceChecks[KartRaceCheck::KRC_Expert_Knuckles]   = KartRaceCheckData(0x01DEF624);

    outKartRaceChecks[KartRaceCheck::KRC_Beginner_Shadow]   = KartRaceCheckData(0x01DEF631);
    outKartRaceChecks[KartRaceCheck::KRC_Standard_Shadow]   = KartRaceCheckData(0x01DEF63E);
    outKartRaceChecks[KartRaceCheck::KRC_Expert_Shadow]     = KartRaceCheckData(0x01DEF64B);

    outKartRaceChecks[KartRaceCheck::KRC_Beginner_Eggman]   = KartRaceCheckData(0x01DEF658);
    outKartRaceChecks[KartRaceCheck::KRC_Standard_Eggman]   = KartRaceCheckData(0x01DEF665);
    outKartRaceChecks[KartRaceCheck::KRC_Expert_Eggman]     = KartRaceCheckData(0x01DEF672);

    outKartRaceChecks[KartRaceCheck::KRC_Beginner_Rouge]    = KartRaceCheckData(0x01DEF67F);
    outKartRaceChecks[KartRaceCheck::KRC_Standard_Rouge]    = KartRaceCheckData(0x01DEF68C);
    outKartRaceChecks[KartRaceCheck::KRC_Expert_Rouge]      = KartRaceCheckData(0x01DEF699);

    outKartRaceChecks[KartRaceCheck::KRC_Beginner_General] = KartRaceCheckData(0x01DEF5BC);
    outKartRaceChecks[KartRaceCheck::KRC_Standard_General] = KartRaceCheckData(0x01DEF5C9);
    outKartRaceChecks[KartRaceCheck::KRC_Expert_General]   = KartRaceCheckData(0x01DEF5D6);
}

void InitializeBigChecks(std::map<int, BigCheckData>& outBigChecks)
{
    outBigChecks.clear();

    outBigChecks[BigCheck::BC_GreenForest_Big_1]    = BigCheckData(0x01DEEECD, 0x00, LevelIDs_GreenForest,      true,   {  6453,  -1678,   7488 },  false,  { 6369,  -1595,  7201 });
    outBigChecks[BigCheck::BC_WhiteJungle_Big_1]    = BigCheckData(0x01DEEECD, 0x01, LevelIDs_WhiteJungle,      false,  {  9833,  -3080,  -7339 }, 40.0f, true, { 10225, -3500, -7460 });
    outBigChecks[BigCheck::BC_WhiteJungle_Big_2]    = BigCheckData(0x01DEEECD, 0x02, LevelIDs_WhiteJungle,      true,   { 13275,  -3571,  -5391 });
    outBigChecks[BigCheck::BC_PumpkinHill_Big_1]    = BigCheckData(0x01DEEECD, 0x03, LevelIDs_PumpkinHill,      false,  {   957,  -1000,   -959 });
    outBigChecks[BigCheck::BC_SkyRail_Big_1]        = BigCheckData(0x01DEEECD, 0x04, LevelIDs_SkyRail,          false,  {    45,    405,   -532 }, 40.0f, true, {    -5, -1125,  1500 });
    outBigChecks[BigCheck::BC_AquaticMine_Big_1]    = BigCheckData(0x01DEEECD, 0x05, LevelIDs_AquaticMine,      false,  {   134,   -250,    176 });
    outBigChecks[BigCheck::BC_SecurityHall_Big_1]   = BigCheckData(0x01DEEECD, 0x06, LevelIDs_SecurityHall,     true,   {   301,   -933,    173 },  false,  {  165,   -986,   161 });
    outBigChecks[BigCheck::BC_PrisonLane_Big_1]     = BigCheckData(0x01DEEECD, 0x07, LevelIDs_PrisonLane,       false,  { -1838,    236,   -596 });
    outBigChecks[BigCheck::BC_MetalHarbor_Big_1]    = BigCheckData(0x01DEEECE, 0x00, LevelIDs_MetalHarbor,      true,   {  4821,   -270,  -9224 },  false,  { 4862,   -197, -9128 });
    outBigChecks[BigCheck::BC_IronGate_Big_1]       = BigCheckData(0x01DEEECE, 0x01, LevelIDs_IronGate,         true,   {  1994,   -665,  -1047 }, 25.0f);
    outBigChecks[BigCheck::BC_WeaponsBed_Big_1]     = BigCheckData(0x01DEEECE, 0x02, LevelIDs_WeaponsBed,       true,   {  -203,   -170,  -1530 },  false,  { -201,    -87, -1550 });
    outBigChecks[BigCheck::BC_CityEscape_Big_1]     = BigCheckData(0x01DEEECE, 0x03, LevelIDs_CityEscape,       false,  {  7832, -20608,  16083 }, 50.0f);
    outBigChecks[BigCheck::BC_RadicalHighway_Big_1] = BigCheckData(0x01DEEECE, 0x04, LevelIDs_RadicalHighway,   false,  { -6760,  -2546,  -6134 }, 50.0f);
    outBigChecks[BigCheck::BC_MissionStreet_Big_1]  = BigCheckData(0x01DEEECE, 0x06, LevelIDs_MissionStreet,    true,   {  2796,    200,  -3443 });
    outBigChecks[BigCheck::BC_DryLagoon_Big_1]      = BigCheckData(0x01DEEECE, 0x07, LevelIDs_DryLagoon,        false,  {   193,      2,    969 }, 30.0f);
    outBigChecks[BigCheck::BC_SandOcean_Big_1]      = BigCheckData(0x01DEEECF, 0x00, LevelIDs_SandOcean,        true,   {  2845,    150,  -6928 });
    outBigChecks[BigCheck::BC_CrazyGadget_Big_1]    = BigCheckData(0x01DEEECF, 0x01, LevelIDs_CrazyGadget,      false,  { -9650,  -1255,  -2548 });
    outBigChecks[BigCheck::BC_HiddenBase_Big_1]     = BigCheckData(0x01DEEECF, 0x02, LevelIDs_HiddenBase,       true,   {    60,    160,  -1719 }, 40.0f);
    outBigChecks[BigCheck::BC_EternalEngine_Big_1]  = BigCheckData(0x01DEEECF, 0x03, LevelIDs_EternalEngine,    false,  { -2166,    335,  -8342 });
    outBigChecks[BigCheck::BC_DeathChamber_Big_1]   = BigCheckData(0x01DEEECF, 0x04, LevelIDs_DeathChamber,     false,  {    48,    217,     97 });
    outBigChecks[BigCheck::BC_EggQuarters_Big_1]    = BigCheckData(0x01DEEECF, 0x05, LevelIDs_EggQuarters,      false,  {     0,    114,   1455 });
    outBigChecks[BigCheck::BC_LostColony_Big_1]     = BigCheckData(0x01DEEECF, 0x06, LevelIDs_LostColony,       false,  {  2891,   1241,  -2469 }, 50.0f);
    outBigChecks[BigCheck::BC_PyramidCave_Big_1]    = BigCheckData(0x01DEEECF, 0x07, LevelIDs_PyramidCave,      false,  { -2580,  -1969, -10431 });
    outBigChecks[BigCheck::BC_FinalRush_Big_1]      = BigCheckData(0x01DEEED0, 0x00, LevelIDs_FinalRush,        true,   {  5937, -15487,  21804 },  false,  { 5713, -15222, 21799 });
    outBigChecks[BigCheck::BC_MeteorHerd_Big_1]     = BigCheckData(0x01DEEED0, 0x01, LevelIDs_MeteorHerd,       true,   {   584,   -600,    -46 });
    outBigChecks[BigCheck::BC_CannonCore_Big_1]     = BigCheckData(0x01DEEED0, 0x02, LevelIDs_CannonsCoreT,     true,   {  -674,   -638,  -1031 });
    outBigChecks[BigCheck::BC_CannonCore_Big_2]     = BigCheckData(0x01DEEED0, 0x03, LevelIDs_CannonsCoreE,     false,  {   430,  -2475,  -2402 });
    outBigChecks[BigCheck::BC_CannonCore_Big_3]     = BigCheckData(0x01DEEED0, 0x04, LevelIDs_CannonsCoreR,     false,  {    11,    528,     -4 });
    outBigChecks[BigCheck::BC_CannonCore_Big_4]     = BigCheckData(0x01DEEED0, 0x05, LevelIDs_CannonsCoreK,     false,  {    94,   -125,  -1346 });
    outBigChecks[BigCheck::BC_CannonCore_Big_5]     = BigCheckData(0x01DEEED0, 0x06, LevelIDs_CannonsCoreS,     true,   {  -614,  -1090,  -3347 });
    outBigChecks[BigCheck::BC_FinalChase_Big_1]     = BigCheckData(0x01DEEED0, 0x07, LevelIDs_FinalChase,       false,  {   144,  -9030,  11145 }, 45.0f);
    outBigChecks[BigCheck::BC_MadSpace_Big_1]       = BigCheckData(0x01DEEED1, 0x01, LevelIDs_MadSpace,         true,   {  1090,   4099,    -33 }, 25.0f);
}
