#include "../pch.h"
#include "../Items/ItemData.h"
#include "StageSelectData.h"
#include "StageSelectIcons.h"
#include <map>
#include <array>
#include <vector>
#pragma once

struct GateLevelCollection
{
public:
    GateLevelCollection() : EmblemCount(0), Levels() {}
    GateLevelCollection(int _emblemCount) : EmblemCount(_emblemCount), Levels() {}

    int EmblemCount;
    std::vector<int> Levels;
};

struct StageIconLocation
{
    StageIconLocation() : X(0), Y(0) {}
    StageIconLocation(int _x, int _y) : X(_x), Y(_y) {}

    int X;
    int Y;
};

struct GateBossLayout
{
    GateBossLayout() : BossLocation(), StageLocation(), FirstGateStage() {}
    GateBossLayout(StageIconLocation bossLocation, StageIconLocation stageLocation, StageSelectStage firstGateStage) : 
        BossLocation(bossLocation),
        StageLocation(stageLocation),
        FirstGateStage(firstGateStage) {}

    StageIconLocation BossLocation;
    StageIconLocation StageLocation;
    StageSelectStage FirstGateStage;
};

class StageSelectManager
{
public:
	static StageSelectManager& GetInstance()
	{
		static StageSelectManager instance;
		return instance;
	}
    static void DrawDebugText(int location, const char* message);
	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();
	void SetEmblemsForCannonsCore(int emblemsRequired);
	void SetRequiredCannonsCoreMissions(bool requireAllCannonsCoreMissions);
    void SetMissionCount(int missionCount);
    void SetRequiredRank(int requiredRank);
	void SetRegionEmblemMap(std::map<int, int> map);
    void SetBossGates(std::map<int, int> map);

private:
	const HelperFunctions* _helperFunctions;
	std::map<int, StageSelectStageData> _stageSelectDataMap;
    std::map<int, StageSelectBossData> _stageSelectBossDataMap;
	int _emblemsForCannonsCore = 200;
	bool _requireAllCannonsCoreMissions = false;
	int _missionCount = 1;
	int _requiredRank = 0;
	std::map<int, int> _regionEmblemMap;
    std::map<int, int> _bossGates;
    std::vector<int> _gateRequirements;
    std::map<int, ItemData> _itemData;
    std::vector<CharacterItemRange> _characterItemRanges;
    std::vector<GateBossLayout> _gateBossLayoutData;

    __int8 _firstStageIndex = 0x17;
    __int8 _previousSettingsSelection = 0x02;
    bool _needsSave = false;

    void UpdateTitleHeaderArrays();
	void LayoutLevels();
	void SetLevelsLockState();
    void LayoutBossGates();
	void UnlockAllLevels();
	void HideMenuButtons();
	void HandleBiolizard();
    void HandleBossStage();
	void HandleStageSelectCamera();
    void DrawStageSelectText();
    void DrawDebugTextOnScreenRight(std::string text, int row);
    void DrawCurrentLevelUpgrade();
    void DrawCurrentCharacterUpgrades();
    CharacterItemRange GetItemRangeForCharacter(char character);

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
