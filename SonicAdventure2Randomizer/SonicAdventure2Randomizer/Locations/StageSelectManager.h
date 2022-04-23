#include "../pch.h"
#include "StageSelectData.h"
#include <map>
#include <array>
#include <vector>
#pragma once

class StageSelectManager
{
public:
	static StageSelectManager& GetInstance()
	{
		static StageSelectManager instance;
		return instance;
	}
	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();
	void SetEmblemsForCannonsCore(int emblemsRequired);
	void SetRegionEmblemMap(std::map<int, int> map);

private:
	const HelperFunctions* _helperFunctions;
	std::map<int, StageSelectStageData> _stageSelectDataMap;
	int _emblemsForCannonsCore;
	std::map<int, int> _regionEmblemMap;
    std::vector<int> _gateRequirements;

	void LayoutLevels();
	void SetLevelsLockState();
	void UnlockAllLevels();
	void HideMenuButtons();
	void HandleBiolizard();
	void HandleStageSelectCamera();


    std::array<int, 33> TileIDtoStageIndex = {
        SSS_HiddenBase,
        SSS_PyramidCave,
        SSS_DeathChamber,
        SSS_EggQuarters,
        SSS_SandOcean,
        SSS_DryLagoon,
        SSS_WeaponsBed,
        SSS_PrisonLane,
        SSS_WildCanyon,
        SSS_IronGate,
        SSS_SecurityHall,
        SSS_MetalHarbor,
        SSS_SkyRail,
        SSS_WhiteJungle,
        SSS_GreenForest,
        SSS_PumpkinHill,
        SSS_AquaticMine,
        SSS_GreenHill,
        SSS_Route280,
        SSS_RadicalHighway,
        SSS_Route101,
        SSS_MissionStreet,
        SSS_ChaoGarden,
        SSS_CityEscape,
        SSS_CrazyGadget,
        SSS_EternalEngine,
        SSS_CosmicWall,
        SSS_MeteorHerd,
        SSS_LostColony,
        SSS_CannonCore,
        SSS_FinalChase,
        SSS_FinalRush,
        SSS_MadSpace
    };
};

struct GateLevelCollection
{
public:
	GateLevelCollection() : EmblemCount(0), Levels() {}
	GateLevelCollection(int _emblemCount) : EmblemCount(_emblemCount), Levels() {}

	int EmblemCount;
	std::vector<int> Levels;
};
