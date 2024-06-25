#include "../pch.h"
#pragma once

#include <map>
#include <vector>
#include "LocationData.h"
#include "../Archipelago/ArchipelagoManager.h"
#include "../ModLoaderCommon/Trampoline.h"

constexpr unsigned int MEMORY_CHECK_TIME = 120;
constexpr unsigned int CHAO_MEMORY_CHECK_TIME = 60;
constexpr unsigned int CHAO_MEMORY_CHECK_ENTRY_TIME = 240;
constexpr unsigned int WHISTLE_CHECK_TIME = 20;

class LocationManager
{
public:
	static LocationManager& getInstance()
	{
		static LocationManager instance;
		return instance;
	}

	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnInputFunction();
	void OnFrameFunction();
	void OnFrameLevelClears();
	void OnFrameBossRush();
	void OnFrameChaoKeys();
	void OnFrameWhistle();
	void OnFramePipes();
	void OnFrameHidden();
	void OnFrameGoldBeetles();
	void OnFrameOmochao();
	void OnFrameAnimals();
	void OnFrameItemBoxes();
	void OnFrameBig();
	void OnFrameKartRace();
	void OnFrameChaoGarden();

	void CheckLocation(int location_id);
	void ResetLocations();

	void SetGoal(int goal);
	void SetRequiredRank(int requiredRank);
	void SetRequiredCannonsCoreMissions(bool requireAllCannonsCoreMissions);

	void SetChaoKeysEnabled(bool chaoKeysEnabled);
	void SetPipesEnabled(bool pipesEnabled);
	void SetHiddensEnabled(bool hiddenEnabled);
	void SetGoldBeetlesEnabled(bool goldBeetlesEnabled);
	void SetOmochaoEnabled(bool omochaoEnabled);
	void SetAnimalsEnabled(bool animalsEnabled);
	void SetItemBoxesEnabled(bool itemboxesEnabled);
	void SetBigEnabled(bool bigEnabled);
	void SetKartRacesEnabled(int kartRacesEnabled);

	void SetRacesPacked(bool racesPacked);
	void SetChaoEnabled(bool chaoEnabled);
	void SetChaoRaceEnabled(int chaoRaceEnabled);
	void SetChaoKarateEnabled(int chaoKarateEnabled);
	void SetChaoStatsEnabled(int chaoStatsEnabled);
	void SetChaoStatsFrequency(int chaoStatsFrequency);
	void SetChaoStatsStaminaEnabled(bool chaoStatsStaminaEnabled);
	void SetChaoStatsHiddenEnabled(bool chaoStatsHiddenEnabled);
	void SetChaoBodyPartsEnabled(bool chaoBodyPartsEnabled);
	void SetChaoKindergartenEnabled(int chaoKindergartenEnabled);
	void SetBlackMarketSlots(int blackMarketSlots);
	void SetBlackMarketUnlockCosts(std::map<int, int> map);

	void SendChaoKeyLocationCheck();
	void SendPipeLocationCheck();
	void SendHiddenLocationCheck();
	void SendGoldBeetleLocationCheck();
	void SendOmochaoLocationCheck();
	void SendAnimalLocationCheck();
	void SendItemBoxLocationCheck(ObjectMaster* itemBox);
	void SendBigLocationCheck();
	void SendBlackMarketLocationCheck(int menuSelection);

	std::vector<int> GetChaoKeyLocationsForLevel(int levelID);
	std::vector<int> GetPipeLocationsForLevel(int levelID);
	std::vector<int> GetHiddenLocationsForLevel(int levelID);
	std::vector<int> GetGoldBeetleLocationsForLevel(int levelID);
	std::vector<int> GetOmochaoLocationsForLevel(int levelID);
	int GetCompletedAnimalLocationsForLevel(int levelID);
	int GetTotalAnimalLocationsForLevel(int levelID);
	std::vector<int> GetLifeBoxLocationsForLevel(int levelID);
	std::vector<int> GetItemBoxLocationsForLevel(int levelID);
	std::vector<int> GetBigLocationsForLevel(int levelID);
	int GetMaxMarketTokens();

	std::vector<int> GetChaoBeginnerRaceLocations();
	std::vector<int> GetChaoChallengeRaceLocations();
	std::vector<int> GetChaoHeroRaceLocations();
	std::vector<int> GetChaoDarkRaceLocations();
	std::vector<int> GetChaoJewelRaceLocations(JewelRaceCategory jewel);
	std::vector<int> GetChaoKarateLocations();

	std::vector<int> GetChaoStatLocations(ChaoStatCheckType stat);

	std::vector<int> GetChaoAnimalPartLocations(ChaoBodyPartAnimal animal);

	std::vector<int> GetChaoLessonLocations(ChaoLessonType lesson);

	std::vector<int> GetCompletedBlackMarketLocations();
	std::vector<int> GetAvailableBlackMarketLocations();

	bool AreAllRacesComplete();

private:
	const HelperFunctions* _helperFunctions;
	ArchipelagoManager* _archipelagoManager;

	unsigned int _timer = 0;
	unsigned int _chaoTimer = 0;
	unsigned int _chaoEntryTimer = 0;
	unsigned int _whistleTimer = 0;

	bool _inBigFishing = false;
	NJS_VECTOR _FreezePos;

	int _goal = 0;
	int _requiredRank = 0;
	bool _requireAllCannonsCoreMissions = false;

	bool _chaoKeysEnabled = false;
	bool _pipesEnabled = false;
	bool _hiddensEnabled = false;
	bool _goldBeetlesEnabled = false;
	bool _omochaoEnabled = false;
	bool _animalsEnabled = false;
	bool _itemBoxesEnabled = false;
	bool _bigEnabled = false;
	int _kartRacesEnabled = 0;

	bool _racesPacked = false;
	bool _chaoEnabled = false;
	int _chaoRaceEnabled = 0;
	int _chaoKarateEnabled = 0;
	int _chaoStatsEnabled = 0;
	int _chaoStatsFrequency = 1;
	bool _chaoStatsStaminaEnabled = false;
	bool _chaoStatsHiddenEnabled = false;
	bool _chaoBodyPartsEnabled = false;
	int _chaoKindergartenEnabled = 0;
	int _blackMarketSlots = 0;

	std::map<int, int> _blackMarketUnlockCosts;

	std::map<int, LevelClearCheckData> _LevelClearData;
	std::map<int, BossRushCheckData> _BossRushData;
	std::map<int, ChaoGardenCheckData> _ChaoGardenData;
	std::map<int, ChaoStatCheckData> _ChaoStatData;
	std::map<int, ChaoBodyPartCheckData> _ChaoBodyPartData;
	std::map<int, ChaoKindergartenCheckData> _ChaoKindergartenData;
	std::map<int, BlackMarketCheckData> _BlackMarketLocationData;

	std::map<int, std::vector<int> > _CollectedChaoStats;

	std::map<int, ChaoKeyCheckData> _ChaoKeyData;
	std::map<int, PipeCheckData> _PipeData;
	std::map<int, HiddenCheckData> _HiddenData;
	std::map<int, GoldBeetleCheckData> _GoldBeetleData;
	std::map<int, OmochaoCheckData> _OmochaoData;
	std::map<int, AnimalCheckData> _AnimalData;
	std::map<int, ItemBoxCheckData> _ItemBoxData;
	std::map<int, BigCheckData> _BigData;
	std::map<int, KartRaceCheckData> _KartRaceData;

	std::map<int, std::vector<int>> _ChaoRacePacks;
};
