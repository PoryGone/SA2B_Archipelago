#include "../pch.h"
#include "StageSelectData.h"

void InitializeStageSelectData(std::map<int, StageSelectStageData>& outStageSelectData)
{
	outStageSelectData.clear();

	outStageSelectData[StageSelectStage::SSS_CityEscape] = StageSelectStageData(0x01DED031);
	outStageSelectData[StageSelectStage::SSS_WildCanyon] = StageSelectStageData(0x01DED27D);
	outStageSelectData[StageSelectStage::SSS_PrisonLane] = StageSelectStageData(0x01DECD21);
	outStageSelectData[StageSelectStage::SSS_MetalHarbor] = StageSelectStageData(0x01DECDE5);
	outStageSelectData[StageSelectStage::SSS_GreenForest] = StageSelectStageData(0x01DEC889);
	outStageSelectData[StageSelectStage::SSS_PumpkinHill] = StageSelectStageData(0x01DECA11);
	outStageSelectData[StageSelectStage::SSS_MissionStreet] = StageSelectStageData(0x01DED341);
	outStageSelectData[StageSelectStage::SSS_AquaticMine] = StageSelectStageData(0x01DECB99);
	outStageSelectData[StageSelectStage::SSS_Route101] = StageSelectStageData(0x01DEF42D);
	outStageSelectData[StageSelectStage::SSS_HiddenBase] = StageSelectStageData(0x01DED7D9);
	outStageSelectData[StageSelectStage::SSS_PyramidCave] = StageSelectStageData(0x01DEDBAD);
	outStageSelectData[StageSelectStage::SSS_DeathChamber] = StageSelectStageData(0x01DED961);
	outStageSelectData[StageSelectStage::SSS_EternalEngine] = StageSelectStageData(0x01DED89D);
	outStageSelectData[StageSelectStage::SSS_MeteorHerd] = StageSelectStageData(0x01DEDEBD);
	outStageSelectData[StageSelectStage::SSS_CrazyGadget] = StageSelectStageData(0x01DED715);
	outStageSelectData[StageSelectStage::SSS_FinalRush] = StageSelectStageData(0x01DEDD35);
	outStageSelectData[StageSelectStage::SSS_IronGate] = StageSelectStageData(0x01DECEA9);
	outStageSelectData[StageSelectStage::SSS_DryLagoon] = StageSelectStageData(0x01DED405);
	outStageSelectData[StageSelectStage::SSS_SandOcean] = StageSelectStageData(0x01DED651);
	outStageSelectData[StageSelectStage::SSS_RadicalHighway] = StageSelectStageData(0x01DED0F5);
	outStageSelectData[StageSelectStage::SSS_EggQuarters] = StageSelectStageData(0x01DEDA25);
	outStageSelectData[StageSelectStage::SSS_LostColony] = StageSelectStageData(0x01DEDAE9);
	outStageSelectData[StageSelectStage::SSS_WeaponsBed] = StageSelectStageData(0x01DECF6D);
	outStageSelectData[StageSelectStage::SSS_SecurityHall] = StageSelectStageData(0x01DECC5D);
	outStageSelectData[StageSelectStage::SSS_WhiteJungle] = StageSelectStageData(0x01DEC94D);
	outStageSelectData[StageSelectStage::SSS_Route280] = StageSelectStageData(0x01DEF4F1);
	outStageSelectData[StageSelectStage::SSS_SkyRail] = StageSelectStageData(0x01DECAD5);
	outStageSelectData[StageSelectStage::SSS_MadSpace] = StageSelectStageData(0x01DEE7ED);
	outStageSelectData[StageSelectStage::SSS_CosmicWall] = StageSelectStageData(0x01DEE729);
	outStageSelectData[StageSelectStage::SSS_FinalChase] = StageSelectStageData(0x01DEE4DD);
	outStageSelectData[StageSelectStage::SSS_CannonCore] = StageSelectStageData(0x01DEE045);
	outStageSelectData[StageSelectStage::SSS_GreenHill] = StageSelectStageData(0x01DEDDF9);
	outStageSelectData[StageSelectStage::SSS_Biolizard] = StageSelectStageData(0x1DEF801);
}