#include "../pch.h"
#include "StageSelectData.h"

void InitializeStageSelectData(std::map<int, StageSelectStageData>& outStageSelectData)
{
	outStageSelectData.clear();

	outStageSelectData[StageSelectStage::SSS_CityEscape]    = StageSelectStageData(0x01DED031, 0x00C751E8, 0x01DEC63A);
	outStageSelectData[StageSelectStage::SSS_WildCanyon]    = StageSelectStageData(0x01DED27D, 0x00C750F8, 0x01DEC646);
	outStageSelectData[StageSelectStage::SSS_PrisonLane]    = StageSelectStageData(0x01DECD21, 0x00C750E8, 0x01DEC640);
	outStageSelectData[StageSelectStage::SSS_MetalHarbor]   = StageSelectStageData(0x01DECDE5, 0x00C75128, 0x01DEC638);
	outStageSelectData[StageSelectStage::SSS_GreenForest]   = StageSelectStageData(0x01DEC889, 0x00C75158, 0x01DEC639);
	outStageSelectData[StageSelectStage::SSS_PumpkinHill]   = StageSelectStageData(0x01DECA11, 0x00C75168, 0x01DEC642);
	outStageSelectData[StageSelectStage::SSS_MissionStreet] = StageSelectStageData(0x01DED341, 0x00C751C8, 0x01DEC63E);
	outStageSelectData[StageSelectStage::SSS_AquaticMine]   = StageSelectStageData(0x01DECB99, 0x00C75178, 0x01DEC645);
	outStageSelectData[StageSelectStage::SSS_Route101]      = StageSelectStageData(0x01DEF42D, 0x00C751B8, 0x00);
	outStageSelectData[StageSelectStage::SSS_HiddenBase]    = StageSelectStageData(0x01DED7D9, 0x00C75078, 0x01DEC641);
	outStageSelectData[StageSelectStage::SSS_PyramidCave]   = StageSelectStageData(0x01DEDBAD, 0x00C75088, 0x01DEC63C);
	outStageSelectData[StageSelectStage::SSS_DeathChamber]  = StageSelectStageData(0x01DED961, 0x00C75098, 0x01DEC644);
	outStageSelectData[StageSelectStage::SSS_EternalEngine] = StageSelectStageData(0x01DED89D, 0x00C75208, 0x01DEC63F);
	outStageSelectData[StageSelectStage::SSS_MeteorHerd]    = StageSelectStageData(0x01DEDEBD, 0x00C75228, 0x01DEC643);
	outStageSelectData[StageSelectStage::SSS_CrazyGadget]   = StageSelectStageData(0x01DED715, 0x00C751F8, 0x01DEC63B);
	outStageSelectData[StageSelectStage::SSS_FinalRush]     = StageSelectStageData(0x01DEDD35, 0x00C75268, 0x01DEC63D);

	outStageSelectData[StageSelectStage::SSS_IronGate]       = StageSelectStageData(0x01DECEA9, 0x00C75108, 0x01DEC64E);
	outStageSelectData[StageSelectStage::SSS_DryLagoon]      = StageSelectStageData(0x01DED405, 0x00C750C8, 0x01DEC654);
	outStageSelectData[StageSelectStage::SSS_SandOcean]      = StageSelectStageData(0x01DED651, 0x00C750B8, 0x01DEC650);
	outStageSelectData[StageSelectStage::SSS_RadicalHighway] = StageSelectStageData(0x01DED0F5, 0x00C751A8, 0x01DEC64A);
	outStageSelectData[StageSelectStage::SSS_EggQuarters]    = StageSelectStageData(0x01DEDA25, 0x00C750A8, 0x01DEC651);
	outStageSelectData[StageSelectStage::SSS_LostColony]     = StageSelectStageData(0x01DEDAE9, 0x00C75238, 0x01DEC64C);
	outStageSelectData[StageSelectStage::SSS_WeaponsBed]     = StageSelectStageData(0x01DECF6D, 0x00C750D8, 0x01DEC64D);
	outStageSelectData[StageSelectStage::SSS_SecurityHall]   = StageSelectStageData(0x01DECC5D, 0x00C75118, 0x01DEC652);
	outStageSelectData[StageSelectStage::SSS_WhiteJungle]    = StageSelectStageData(0x01DEC94D, 0x00C75148, 0x01DEC648);
	outStageSelectData[StageSelectStage::SSS_Route280]       = StageSelectStageData(0x01DEF4F1, 0x00C75198, 0x00);
	outStageSelectData[StageSelectStage::SSS_SkyRail]        = StageSelectStageData(0x01DECAD5, 0x00C75138, 0x01DEC649);
	outStageSelectData[StageSelectStage::SSS_MadSpace]       = StageSelectStageData(0x01DEE7ED, 0x00C75278, 0x01DEC653);
	outStageSelectData[StageSelectStage::SSS_CosmicWall]     = StageSelectStageData(0x01DEE729, 0x00C75218, 0x01DEC64F);
	outStageSelectData[StageSelectStage::SSS_FinalChase]     = StageSelectStageData(0x01DEE4DD, 0x00C75258, 0x01DEC64B);
	outStageSelectData[StageSelectStage::SSS_CannonCore]     = StageSelectStageData(0x01DEE045, 0x00C75248, 0x00);

	outStageSelectData[StageSelectStage::SSS_GreenHill]  = StageSelectStageData(0x01DEDDF9, 0x00C75188, 0x00);
	outStageSelectData[StageSelectStage::SSS_ChaoGarden] = StageSelectStageData(0x01DEEECC, 0x00C751D8, 0x00);
	outStageSelectData[StageSelectStage::SSS_Biolizard]  = StageSelectStageData(0x01DEF801, 0x00000000, 0x00);
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