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

    outChaoKeyChecks[ChaoKeyCheck::CKC_CityEscape_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8CA, LevelIDs_CityEscape, { 2850, -8555, 6418 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CityEscape_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8CB, LevelIDs_CityEscape, { 6040, -10690, 4395 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CityEscape_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8CC, LevelIDs_CityEscape, { 7728, -14355, 6278 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_RadicalHighway_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8CD, LevelIDs_RadicalHighway, { -1500, -1020, -4310 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_RadicalHighway_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8CE, LevelIDs_RadicalHighway, { -5070, -2763, -4360 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_RadicalHighway_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8CF, LevelIDs_RadicalHighway, { -6360, -5116, -11245 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_WildCanyon_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8D0, LevelIDs_WildCanyon, { 300, 235, 150 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_WildCanyon_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8D1, LevelIDs_WildCanyon, { 1070, 812, 20 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_WildCanyon_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8D2, LevelIDs_WildCanyon, { -405, 927, -120 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_MissionStreet_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8D3, LevelIDs_MissionStreet, { -1250, -58, -2265 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MissionStreet_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8D4, LevelIDs_MissionStreet, { -1260, 35, 3025 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MissionStreet_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8D5, LevelIDs_MissionStreet, { 2385, 200, -3460 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_DryLagoon_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8D6, LevelIDs_DryLagoon, { -160, 55, 135 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_DryLagoon_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8D7, LevelIDs_DryLagoon, { -140, 457, 255 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_DryLagoon_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8D8, LevelIDs_DryLagoon, { -70, 429, 1410 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_SandOcean_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8D9, LevelIDs_SandOcean, { 320, 30, -1980 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_SandOcean_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8DA, LevelIDs_SandOcean, { 990, 90, -3420 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_SandOcean_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8DB, LevelIDs_SandOcean, { 2625, 20, -4065 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_CrazyGadget_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8DC, LevelIDs_CrazyGadget, { -5755, -1238, -3205 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CrazyGadget_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8DD, LevelIDs_CrazyGadget, { -8300, -1065, -3805 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CrazyGadget_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8DE, LevelIDs_CrazyGadget, { -10950, -1027, -2737 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_HiddenBase_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8DF, LevelIDs_HiddenBase, { 150, 110, -2875 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_HiddenBase_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8E0, LevelIDs_HiddenBase, { -3850, 110, -3080 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_EternalEngine_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8E1, LevelIDs_EternalEngine, { -920, 578, -2200 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_EternalEngine_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8E2, LevelIDs_EternalEngine, { -1600, 786, -5310 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_EternalEngine_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8E3, LevelIDs_EternalEngine, { -2745, 836, -5200 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_DeathChamber_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8E4, LevelIDs_DeathChamber, { 215, 0, 215 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_DeathChamber_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8E5, LevelIDs_DeathChamber, { 600, 59, 1805 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_DeathChamber_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8E6, LevelIDs_DeathChamber, { -980, -130, 290 });

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
    outChaoKeyChecks[ChaoKeyCheck::CKC_CannonCore_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8F8, LevelIDs_CannonsCoreS, { -50, -480, -990 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_FinalChase_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8F9, LevelIDs_FinalChase, { 3715, -4575, 3375 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_FinalChase_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8FA, LevelIDs_FinalChase, { 4275, -5170, 8645 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_FinalChase_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8FB, LevelIDs_FinalChase, { 1490, -7614, 18210 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_CosmicWall_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8FC, LevelIDs_CosmicWall, { 3090, 1750, -725 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CosmicWall_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8FD, LevelIDs_CosmicWall, { 5678, 3167, 3530 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CosmicWall_Chao_Key_3] = ChaoKeyCheckData(0x01DEE8FE, LevelIDs_CosmicWall, { 6648, 4317, 9268 });

    outChaoKeyChecks[ChaoKeyCheck::CKC_MadSpace_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8FF, LevelIDs_MadSpace, { 140, 327, -80 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MadSpace_Chao_Key_2] = ChaoKeyCheckData(0x01DEE900, LevelIDs_MadSpace, { -620, 1699, 185 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_MadSpace_Chao_Key_3] = ChaoKeyCheckData(0x01DEE901, LevelIDs_MadSpace, { 100, 4099, -60 });
}

void InitializePipeChecks(std::map<int, PipeCheckData>& outPipeChecks)
{
    outPipeChecks.clear();

    outPipeChecks[PipeCheck::PC_GreenForest_Pipe_1] = PipeCheckData(0x01DEE970, LevelIDs_GreenForest, { 222, -951, 3956 });
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
    outPipeChecks[PipeCheck::PC_PrisonLane_Pipe_2] = PipeCheckData(0x01DEE982, LevelIDs_PrisonLane, { -1483, 227, -78 });
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
    outGoldBeetleChecks[GoldBeetleCheck::GBC_MadSpace_Gold_Beetle_1] = GoldBeetleCheckData(0x01DEEA4A, LevelIDs_MadSpace);
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

    outChaoGardenChecks[ChaoGardenCheck::CGC_Beginner_Karate]     = ChaoGardenCheckData(0x01DEF831, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Intermediate_Karate] = ChaoGardenCheckData(0x01DEF832, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Expert_Karate]       = ChaoGardenCheckData(0x01DEF833, 0);
    outChaoGardenChecks[ChaoGardenCheck::CGC_Super_Karate]        = ChaoGardenCheckData(0x01DEF834, 0);
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
