#include "../pch.h"
#include "../Items/ItemData.h"
#include "../Locations/LocationData.h"
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
	void SetGoal(int goal);
	void SetKartRacesEnabled(int kartRacesEnabled);
	void SetEmblemsForCannonsCore(int emblemsRequired);
	void SetRequiredCannonsCoreMissions(bool requireAllCannonsCoreMissions);
    void SetRequiredRank(int requiredRank);
	void SetRegionEmblemMap(std::map<int, int> map);
	void SetChosenMissionsMap(std::map<int, int> map);
	void SetMissionCountMap(std::map<int, int> map);
    void SetBossGates(std::map<int, int> map);
    void SetChosenBossRushMap(std::map<int, int> map);
    int GetGoal();
    int GetCannonsCoreEmblemCount();
    std::vector<int> GetGateRequirements();

private:
	const HelperFunctions* _helperFunctions;
	std::map<int, StageSelectStageData> _stageSelectDataMap;
    std::map<int, StageSelectBossData> _stageSelectBossDataMap;
	int _emblemsForCannonsCore = 2000;
	bool _requireAllCannonsCoreMissions = false;
	int _goal = 0;
	int _kartRacesEnabled = 0;
	int _requiredRank = 0;
	std::map<int, int> _regionEmblemMap;
    std::map<int, int> _bossGates;
    std::vector<int> _gateRequirements;
    std::map<int, int> _chosenMissionsMap;
    std::map<int, int> _missionCountMap;
    std::map<int, int> _chosenBossRushMap;
    std::map<int, ItemData> _itemData;
    std::vector<CharacterItemRange> _characterItemRanges;
    std::vector<GateBossLayout> _gateBossLayoutData;

    std::map<int, BossRushCheckData> _BossRushData;

    __int8 _firstStageIndex = 0x17;
    __int8 _previousMainMenuSelection = 0x02;
    __int8 _previousSettingsSelection = 0x02;
    bool _needsSave = false;

    bool _victorySent = false;

    void UpdateTitleHeaderArrays();
	void LayoutLevels();
	void SetLevelsLockState();
    void LayoutBossGates();
	void UnlockAllLevels();
	bool IsCannonsCoreComplete();
	void HideMenuButtons();
	void HandleGoal();
	void HandleBiolizard();
	void HandleGreenHill();
	void HandleGrandPrix();
	void HandleBossRush();
	void HandleChaosChao();
	void HandleMinigameMadness();
    void HandleBossStage();
	void HandleStageSelectCamera();
	void HandleMissionOrder();
    void DrawDebugTextOnScreenRight(std::string text, int row);
    void DrawCurrentLevelUpgrade();
    void DrawCurrentCharacterUpgrades();
    CharacterItemRange GetItemRangeForCharacter(char character);
    bool HaveAllChaosEmeralds();
    bool HaveAllMinigames();
    bool IsCurrentLevelChaoWorld();

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

    std::array<std::array<int, 5>, 96> _potentialMissionOrders = { {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 5, 4},
        {1, 2, 4, 3, 5},
        {1, 2, 4, 5, 3},
        {1, 2, 5, 3, 4},
        {1, 2, 5, 4, 3},

        {1, 3, 2, 4, 5},
        {1, 3, 2, 5, 4},
        {1, 3, 4, 2, 5},
        {1, 3, 4, 5, 2},
        {1, 3, 5, 2, 4},
        {1, 3, 5, 4, 2},

        {1, 4, 2, 3, 5},
        {1, 4, 2, 5, 3},
        {1, 4, 3, 2, 5},
        {1, 4, 3, 5, 2},
        {1, 4, 5, 2, 3},
        {1, 4, 5, 3, 2},

        {1, 5, 2, 3, 4},
        {1, 5, 2, 4, 3},
        {1, 5, 3, 2, 4},
        {1, 5, 3, 4, 2},
        {1, 5, 4, 2, 3},
        {1, 5, 4, 3, 2},

        {2, 1, 3, 4, 5},
        {2, 1, 3, 5, 4},
        {2, 1, 4, 3, 5},
        {2, 1, 4, 5, 3},
        {2, 1, 5, 3, 4},
        {2, 1, 5, 4, 3},

        {2, 3, 1, 4, 5},
        {2, 3, 1, 5, 4},
        {2, 3, 4, 1, 5},
        {2, 3, 4, 5, 1},
        {2, 3, 5, 1, 4},
        {2, 3, 5, 4, 1},

        {2, 4, 1, 3, 5},
        {2, 4, 1, 5, 3},
        {2, 4, 3, 1, 5},
        {2, 4, 3, 5, 1},
        {2, 4, 5, 1, 3},
        {2, 4, 5, 3, 1},

        {2, 5, 1, 3, 4},
        {2, 5, 1, 4, 3},
        {2, 5, 3, 1, 4},
        {2, 5, 3, 4, 1},
        {2, 5, 4, 1, 3},
        {2, 5, 4, 3, 1},

        {3, 1, 2, 4, 5},
        {3, 1, 2, 5, 4},
        {3, 1, 4, 2, 5},
        {3, 1, 4, 5, 2},
        {3, 1, 5, 4, 2},
        {3, 1, 5, 2, 4},

        {3, 2, 1, 4, 5},
        {3, 2, 1, 5, 4},
        {3, 2, 4, 1, 5},
        {3, 2, 4, 5, 1},
        {3, 2, 5, 1, 4},
        {3, 2, 5, 4, 1},

        {3, 4, 1, 2, 5},
        {3, 4, 1, 5, 2},
        {3, 4, 2, 1, 5},
        {3, 4, 2, 5, 1},
        {3, 4, 5, 1, 2},
        {3, 4, 5, 2, 1},

        {3, 5, 1, 4, 2},
        {3, 5, 1, 2, 4},
        {3, 5, 2, 1, 4},
        {3, 5, 2, 4, 1},
        {3, 5, 4, 1, 2},
        {3, 5, 4, 2, 1},

        {4, 1, 2, 3, 5},
        {4, 1, 2, 5, 3},
        {4, 1, 3, 2, 5},
        {4, 1, 3, 5, 2},
        {4, 1, 5, 3, 2},
        {4, 1, 5, 2, 3},

        {4, 2, 1, 3, 5},
        {4, 2, 1, 5, 3},
        {4, 2, 3, 1, 5},
        {4, 2, 3, 5, 1},
        {4, 2, 5, 1, 3},
        {4, 2, 5, 3, 1},

        {4, 3, 1, 2, 5},
        {4, 3, 1, 5, 2},
        {4, 3, 2, 1, 5},
        {4, 3, 2, 5, 1},
        {4, 3, 5, 1, 2},
        {4, 3, 5, 2, 1},

        {4, 5, 1, 3, 2},
        {4, 5, 1, 2, 3},
        {4, 5, 2, 1, 3},
        {4, 5, 2, 3, 1},
        {4, 5, 3, 1, 2},
        {4, 5, 3, 2, 1},
    } };

};
