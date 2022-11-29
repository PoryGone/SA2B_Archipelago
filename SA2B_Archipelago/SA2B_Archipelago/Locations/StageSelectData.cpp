#include "../pch.h"
#include "StageSelectData.h"

void InitializeStageSelectData(std::map<int, StageSelectStageData>& outStageSelectData)
{
	outStageSelectData.clear();

	outStageSelectData[StageSelectStage::SSS_CityEscape]    = StageSelectStageData(0x01DED031, 0x00C751E8, 0x01DEC63A, Characters::Characters_Sonic);
	outStageSelectData[StageSelectStage::SSS_WildCanyon]    = StageSelectStageData(0x01DED27D, 0x00C750F8, 0x01DEC646, Characters::Characters_Knuckles);
	outStageSelectData[StageSelectStage::SSS_PrisonLane]    = StageSelectStageData(0x01DECD21, 0x00C750E8, 0x01DEC640, Characters::Characters_MechTails);
	outStageSelectData[StageSelectStage::SSS_MetalHarbor]   = StageSelectStageData(0x01DECDE5, 0x00C75128, 0x01DEC638, Characters::Characters_Sonic);
	outStageSelectData[StageSelectStage::SSS_GreenForest]   = StageSelectStageData(0x01DEC889, 0x00C75158, 0x01DEC639, Characters::Characters_Sonic);
	outStageSelectData[StageSelectStage::SSS_PumpkinHill]   = StageSelectStageData(0x01DECA11, 0x00C75168, 0x01DEC642, Characters::Characters_Knuckles);
	outStageSelectData[StageSelectStage::SSS_MissionStreet] = StageSelectStageData(0x01DED341, 0x00C751C8, 0x01DEC63E, Characters::Characters_MechTails);
	outStageSelectData[StageSelectStage::SSS_AquaticMine]   = StageSelectStageData(0x01DECB99, 0x00C75178, 0x01DEC645, Characters::Characters_Knuckles);
	outStageSelectData[StageSelectStage::SSS_Route101]      = StageSelectStageData(0x01DEF42D, 0x00C751B8, 0x00, Characters::Characters_MechTails);
	outStageSelectData[StageSelectStage::SSS_HiddenBase]    = StageSelectStageData(0x01DED7D9, 0x00C75078, 0x01DEC641, Characters::Characters_MechTails);
	outStageSelectData[StageSelectStage::SSS_PyramidCave]   = StageSelectStageData(0x01DEDBAD, 0x00C75088, 0x01DEC63C, Characters::Characters_Sonic);
	outStageSelectData[StageSelectStage::SSS_DeathChamber]  = StageSelectStageData(0x01DED961, 0x00C75098, 0x01DEC644, Characters::Characters_Knuckles);
	outStageSelectData[StageSelectStage::SSS_EternalEngine] = StageSelectStageData(0x01DED89D, 0x00C75208, 0x01DEC63F, Characters::Characters_MechTails);
	outStageSelectData[StageSelectStage::SSS_MeteorHerd]    = StageSelectStageData(0x01DEDEBD, 0x00C75228, 0x01DEC643, Characters::Characters_Knuckles);
	outStageSelectData[StageSelectStage::SSS_CrazyGadget]   = StageSelectStageData(0x01DED715, 0x00C751F8, 0x01DEC63B, Characters::Characters_Sonic);
	outStageSelectData[StageSelectStage::SSS_FinalRush]     = StageSelectStageData(0x01DEDD35, 0x00C75268, 0x01DEC63D, Characters::Characters_Sonic);

	outStageSelectData[StageSelectStage::SSS_IronGate]       = StageSelectStageData(0x01DECEA9, 0x00C75108, 0x01DEC64E, Characters::Characters_MechEggman);
	outStageSelectData[StageSelectStage::SSS_DryLagoon]      = StageSelectStageData(0x01DED405, 0x00C750C8, 0x01DEC654, Characters::Characters_Rouge);
	outStageSelectData[StageSelectStage::SSS_SandOcean]      = StageSelectStageData(0x01DED651, 0x00C750B8, 0x01DEC650, Characters::Characters_MechEggman);
	outStageSelectData[StageSelectStage::SSS_RadicalHighway] = StageSelectStageData(0x01DED0F5, 0x00C751A8, 0x01DEC64A, Characters::Characters_Shadow);
	outStageSelectData[StageSelectStage::SSS_EggQuarters]    = StageSelectStageData(0x01DEDA25, 0x00C750A8, 0x01DEC651, Characters::Characters_Rouge);
	outStageSelectData[StageSelectStage::SSS_LostColony]     = StageSelectStageData(0x01DEDAE9, 0x00C75238, 0x01DEC64C, Characters::Characters_MechEggman);
	outStageSelectData[StageSelectStage::SSS_WeaponsBed]     = StageSelectStageData(0x01DECF6D, 0x00C750D8, 0x01DEC64D, Characters::Characters_MechEggman);
	outStageSelectData[StageSelectStage::SSS_SecurityHall]   = StageSelectStageData(0x01DECC5D, 0x00C75118, 0x01DEC652, Characters::Characters_Rouge);
	outStageSelectData[StageSelectStage::SSS_WhiteJungle]    = StageSelectStageData(0x01DEC94D, 0x00C75148, 0x01DEC648, Characters::Characters_Shadow);
	outStageSelectData[StageSelectStage::SSS_Route280]       = StageSelectStageData(0x01DEF4F1, 0x00C75198, 0x00, Characters::Characters_Rouge);
	outStageSelectData[StageSelectStage::SSS_SkyRail]        = StageSelectStageData(0x01DECAD5, 0x00C75138, 0x01DEC649, Characters::Characters_Shadow);
	outStageSelectData[StageSelectStage::SSS_MadSpace]       = StageSelectStageData(0x01DEE7ED, 0x00C75278, 0x01DEC653, Characters::Characters_Rouge);
	outStageSelectData[StageSelectStage::SSS_CosmicWall]     = StageSelectStageData(0x01DEE729, 0x00C75218, 0x01DEC64F, Characters::Characters_MechEggman);
	outStageSelectData[StageSelectStage::SSS_FinalChase]     = StageSelectStageData(0x01DEE4DD, 0x00C75258, 0x01DEC64B, Characters::Characters_Shadow);
	outStageSelectData[StageSelectStage::SSS_CannonCore]     = StageSelectStageData(0x01DEE045, 0x00C75248, 0x00, Characters::Characters_Sonic);

	outStageSelectData[StageSelectStage::SSS_GreenHill]  = StageSelectStageData(0x01DEDDF9, 0x00C75188, 0x00, Characters::Characters_B);
	outStageSelectData[StageSelectStage::SSS_ChaoGarden] = StageSelectStageData(0x01DEEECC, 0x00C751D8, 0x00, Characters::Characters_ChaoWalker);
	outStageSelectData[StageSelectStage::SSS_Biolizard]  = StageSelectStageData(0x01DEF801, 0x00000000, 0x00, Characters::Characters_Shadow);
}

void InitializeStageSelectBossData(std::map<int, StageSelectBossData>& outStageBossData)
{
	outStageBossData.clear();

	outStageBossData[StageSelectBoss::SSB_Speed_1]			= StageSelectBossData(BossStageData(Characters::Characters_Sonic, 0x13, 0x01DED4C9), BossStageData(Characters::Characters_Shadow, 0x13, 0x01DED4C9));
	outStageBossData[StageSelectBoss::SSB_Speed_2]			= StageSelectBossData(BossStageData(Characters::Characters_Sonic, 0x2A, 0x01DEE665), BossStageData(Characters::Characters_Shadow, 0x2A, 0x01DEE665));
	outStageBossData[StageSelectBoss::SSB_Mech_1]			= StageSelectBossData(BossStageData(Characters::Characters_MechTails, 0x14, 0x01DED58D), BossStageData(Characters::Characters_MechEggman, 0x14, 0x01DED58D));
	outStageBossData[StageSelectBoss::SSB_Mech_2]			= StageSelectBossData(BossStageData(Characters::Characters_MechTails, 0x1D, 0x01DEDC71), BossStageData(Characters::Characters_MechEggman, 0x1D, 0x01DEDC71));
	outStageBossData[StageSelectBoss::SSB_Hunt_1]			= StageSelectBossData(BossStageData(Characters::Characters_Knuckles, 0x21, 0x01DEDF81), BossStageData(Characters::Characters_Rouge, 0x21, 0x01DEDF81));
	outStageBossData[StageSelectBoss::SSB_BigFoot]			= StageSelectBossData(BossStageData(Characters::Characters_Sonic, 0x3C, 0x01DEF42D), BossStageData());
	outStageBossData[StageSelectBoss::SSB_HotShot]			= StageSelectBossData(BossStageData(Characters::Characters_Shadow, 0x3D, 0x01DEF4F1), BossStageData());
	outStageBossData[StageSelectBoss::SSB_FlyingDog]		= StageSelectBossData(BossStageData(Characters::Characters_Rouge, 0x3E, 0x01DEF5B5), BossStageData());
	outStageBossData[StageSelectBoss::SSB_EggGolem_Sonic]	= StageSelectBossData(BossStageData(Characters::Characters_Sonic, 0x40, 0x01DEF73D), BossStageData());
	outStageBossData[StageSelectBoss::SSB_EggGolem_Eggman]	= StageSelectBossData(BossStageData(Characters::Characters_MechEggman, 0x43, 0x01DEF989), BossStageData());
	outStageBossData[StageSelectBoss::SSB_KingBoomBoo]		= StageSelectBossData(BossStageData(Characters::Characters_Knuckles, 0x3F, 0x01DEF679), BossStageData());
}

void InitializeCharacterItemRanges(std::vector<CharacterItemRange>& outCharacterItemRanges)
{
	outCharacterItemRanges.clear();

	outCharacterItemRanges.emplace_back(CharacterItemRange(Characters_Sonic, IV_SonicGloves, IV_SonicMysticMelody));
	outCharacterItemRanges.emplace_back(CharacterItemRange(Characters_Shadow, IV_ShadowFlameRing, IV_ShadowMysticMelody));
	outCharacterItemRanges.emplace_back(CharacterItemRange(Characters_MechTails, IV_TailsLaserBlaster, IV_TailsBazooka));
	outCharacterItemRanges.emplace_back(CharacterItemRange(Characters_MechEggman, IV_EggmanLaserBlaster, IV_EggmanProtectiveArmor));
	outCharacterItemRanges.emplace_back(CharacterItemRange(Characters_Knuckles, IV_KnucklesMysticMelody, IV_KnucklesSunglasses));
	outCharacterItemRanges.emplace_back(CharacterItemRange(Characters_Rouge, IV_RougeMysticMelody, IV_RougeIronBoots));
}

LevelIDs StageSelectStageToLevelID(StageSelectStage stage)
{
	switch (stage)
	{
	case SSS_CityEscape:
		return LevelIDs_CityEscape;
	case SSS_WildCanyon:
		return LevelIDs_WildCanyon;
	case SSS_PrisonLane:
		return LevelIDs_PrisonLane;
	case SSS_MetalHarbor:
		return LevelIDs_MetalHarbor;
	case SSS_GreenForest:
		return LevelIDs_GreenForest;
	case SSS_PumpkinHill:
		return LevelIDs_PumpkinHill;
	case SSS_MissionStreet:
		return LevelIDs_MissionStreet;
	case SSS_AquaticMine:
		return LevelIDs_AquaticMine;
	case SSS_Route101:
		return LevelIDs_Route101280;
	case SSS_HiddenBase:
		return LevelIDs_HiddenBase;
	case SSS_PyramidCave:
		return LevelIDs_PyramidCave;
	case SSS_DeathChamber:
		return LevelIDs_DeathChamber;
	case SSS_EternalEngine:
		return LevelIDs_EternalEngine;
	case SSS_MeteorHerd:
		return LevelIDs_MeteorHerd;
	case SSS_CrazyGadget:
		return LevelIDs_CrazyGadget;
	case SSS_FinalRush:
		return LevelIDs_FinalRush;
	case SSS_IronGate:
		return LevelIDs_IronGate;
	case SSS_DryLagoon:
		return LevelIDs_DryLagoon;
	case SSS_SandOcean:
		return LevelIDs_SandOcean;
	case SSS_RadicalHighway:
		return LevelIDs_RadicalHighway;
	case SSS_EggQuarters:
		return LevelIDs_EggQuarters;
	case SSS_LostColony:
		return LevelIDs_LostColony;
	case SSS_WeaponsBed:
		return LevelIDs_WeaponsBed;
	case SSS_SecurityHall:
		return LevelIDs_SecurityHall;
	case SSS_WhiteJungle:
		return LevelIDs_WhiteJungle;
	case SSS_Route280:
		return LevelIDs_Route101280;
	case SSS_SkyRail:
		return LevelIDs_SkyRail;
	case SSS_MadSpace:
		return LevelIDs_MadSpace;
	case SSS_CosmicWall:
		return LevelIDs_CosmicWall;
	case SSS_FinalChase:
		return LevelIDs_FinalChase;
	case SSS_CannonCore:
		return LevelIDs_CannonsCoreS;
	case SSS_GreenHill:
		return LevelIDs_GreenHill;
	case SSS_ChaoGarden:
		return LevelIDs_ChaoWorld;
	case SSS_Biolizard:
		return LevelIDs_Biolizard;
	case SSS_COUNT:
		return LevelIDs_BasicTest;
	default:
		return LevelIDs_BasicTest;
	}
}