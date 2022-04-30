#include "../pch.h"
#include "StageSelectData.h"

void InitializeStageSelectData(std::map<int, StageSelectStageData>& outStageSelectData)
{
	outStageSelectData.clear();

	outStageSelectData[StageSelectStage::SSS_CityEscape]    = StageSelectStageData(0x01DED031, 0x00C751E8);
	outStageSelectData[StageSelectStage::SSS_WildCanyon]    = StageSelectStageData(0x01DED27D, 0x00C750F8);
	outStageSelectData[StageSelectStage::SSS_PrisonLane]    = StageSelectStageData(0x01DECD21, 0x00C750E8);
	outStageSelectData[StageSelectStage::SSS_MetalHarbor]   = StageSelectStageData(0x01DECDE5, 0x00C75128);
	outStageSelectData[StageSelectStage::SSS_GreenForest]   = StageSelectStageData(0x01DEC889, 0x00C75158);
	outStageSelectData[StageSelectStage::SSS_PumpkinHill]   = StageSelectStageData(0x01DECA11, 0x00C75168);
	outStageSelectData[StageSelectStage::SSS_MissionStreet] = StageSelectStageData(0x01DED341, 0x00C751C8);
	outStageSelectData[StageSelectStage::SSS_AquaticMine]   = StageSelectStageData(0x01DECB99, 0x00C75178);
	outStageSelectData[StageSelectStage::SSS_Route101]      = StageSelectStageData(0x01DEF42D, 0x00C751B8);
	outStageSelectData[StageSelectStage::SSS_HiddenBase]    = StageSelectStageData(0x01DED7D9, 0x00C75078);
	outStageSelectData[StageSelectStage::SSS_PyramidCave]   = StageSelectStageData(0x01DEDBAD, 0x00C75088);
	outStageSelectData[StageSelectStage::SSS_DeathChamber]  = StageSelectStageData(0x01DED961, 0x00C75098);
	outStageSelectData[StageSelectStage::SSS_EternalEngine] = StageSelectStageData(0x01DED89D, 0x00C75208);
	outStageSelectData[StageSelectStage::SSS_MeteorHerd]    = StageSelectStageData(0x01DEDEBD, 0x00C75228);
	outStageSelectData[StageSelectStage::SSS_CrazyGadget]   = StageSelectStageData(0x01DED715, 0x00C751F8);
	outStageSelectData[StageSelectStage::SSS_FinalRush]     = StageSelectStageData(0x01DEDD35, 0x00C75268);

	outStageSelectData[StageSelectStage::SSS_IronGate]       = StageSelectStageData(0x01DECEA9, 0x00C75108);
	outStageSelectData[StageSelectStage::SSS_DryLagoon]      = StageSelectStageData(0x01DED405, 0x00C750C8);
	outStageSelectData[StageSelectStage::SSS_SandOcean]      = StageSelectStageData(0x01DED651, 0x00C750B8);
	outStageSelectData[StageSelectStage::SSS_RadicalHighway] = StageSelectStageData(0x01DED0F5, 0x00C751A8);
	outStageSelectData[StageSelectStage::SSS_EggQuarters]    = StageSelectStageData(0x01DEDA25, 0x00C750A8);
	outStageSelectData[StageSelectStage::SSS_LostColony]     = StageSelectStageData(0x01DEDAE9, 0x00C75238);
	outStageSelectData[StageSelectStage::SSS_WeaponsBed]     = StageSelectStageData(0x01DECF6D, 0x00C750D8);
	outStageSelectData[StageSelectStage::SSS_SecurityHall]   = StageSelectStageData(0x01DECC5D, 0x00C75118);
	outStageSelectData[StageSelectStage::SSS_WhiteJungle]    = StageSelectStageData(0x01DEC94D, 0x00C75148);
	outStageSelectData[StageSelectStage::SSS_Route280]       = StageSelectStageData(0x01DEF4F1, 0x00C75198);
	outStageSelectData[StageSelectStage::SSS_SkyRail]        = StageSelectStageData(0x01DECAD5, 0x00C75138);
	outStageSelectData[StageSelectStage::SSS_MadSpace]       = StageSelectStageData(0x01DEE7ED, 0x00C75278);
	outStageSelectData[StageSelectStage::SSS_CosmicWall]     = StageSelectStageData(0x01DEE729, 0x00C75218);
	outStageSelectData[StageSelectStage::SSS_FinalChase]     = StageSelectStageData(0x01DEE4DD, 0x00C75258);
	outStageSelectData[StageSelectStage::SSS_CannonCore]     = StageSelectStageData(0x01DEE045, 0x00C75248);

	outStageSelectData[StageSelectStage::SSS_GreenHill]  = StageSelectStageData(0x01DEDDF9, 0x00C75188);
	outStageSelectData[StageSelectStage::SSS_ChaoGarden] = StageSelectStageData(0x01DEEECC, 0x00C751D8);
	outStageSelectData[StageSelectStage::SSS_Biolizard]  = StageSelectStageData(0x01DEF801, 0x00000000);
}