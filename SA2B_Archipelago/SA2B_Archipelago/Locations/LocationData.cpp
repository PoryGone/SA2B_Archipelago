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

    outChaoKeyChecks[ChaoKeyCheck::CKC_CannonCore_Chao_Key_1] = ChaoKeyCheckData(0x01DEE8F6, LevelIDs_CannonsCoreS, { 570, 120, -2590 });
    outChaoKeyChecks[ChaoKeyCheck::CKC_CannonCore_Chao_Key_2] = ChaoKeyCheckData(0x01DEE8F7, LevelIDs_CannonsCoreS, { -80, -131, -990 });
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
