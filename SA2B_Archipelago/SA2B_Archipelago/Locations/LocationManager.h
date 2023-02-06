#include "../pch.h"
#pragma once

#include <map>
#include <vector>
#include "LocationData.h"
#include "../Archipelago/ArchipelagoManager.h"
#include "../ModLoaderCommon/Trampoline.h"

constexpr unsigned int MEMORY_CHECK_TIME = 120;
constexpr unsigned int CHAO_MEMORY_CHECK_TIME = 240;
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
	void OnFrameFunction();
	void OnFrameLevelClears();
	void OnFrameChaoKeys();
	void OnFrameWhistle();
	void OnFramePipes();
	void OnFrameHidden();
	void OnFrameGoldBeetles();
	void OnFrameOmochao();
	void OnFrameChaoGarden();
	void CheckLocation(int location_id);
	void SetRequiredRank(int requiredRank);
	void SetChaoKeysEnabled(bool chaoKeysEnabled);
	void SetPipesEnabled(bool pipesEnabled);
	void SetHiddensEnabled(bool hiddenEnabled);
	void SetGoldBeetlesEnabled(bool goldBeetlesEnabled);
	void SetOmochaoEnabled(bool omochaoEnabled);
	void SetRacesPacked(bool racesPacked);
	void SetChaoEnabled(bool chaoEnabled);
	void SetRequiredCannonsCoreMissions(bool requireAllCannonsCoreMissions);
	void ResetLocations();

	void SendChaoKeyLocationCheck();
	void SendPipeLocationCheck();
	void SendHiddenLocationCheck();
	void SendGoldBeetleLocationCheck();
	void SendOmochaoLocationCheck();

	std::vector<int> GetChaoKeyLocationsForLevel(int levelID);
	std::vector<int> GetPipeLocationsForLevel(int levelID);
	std::vector<int> GetHiddenLocationsForLevel(int levelID);
	std::vector<int> GetGoldBeetleLocationsForLevel(int levelID);
	std::vector<int> GetOmochaoLocationsForLevel(int levelID);

private:
	const HelperFunctions* _helperFunctions;
	ArchipelagoManager* _archipelagoManager;

	unsigned int _timer = 0;
	unsigned int _chaoTimer = 0;
	unsigned int _whistleTimer = 0;
	int _requiredRank = 0;
	bool _requireAllCannonsCoreMissions = false;
	bool _chaoKeysEnabled = false;
	bool _pipesEnabled = false;
	bool _hiddensEnabled = false;
	bool _goldBeetlesEnabled = false;
	bool _omochaoEnabled = false;
	bool _racesPacked = false;
	bool _chaoEnabled = false;

	std::map<int, LevelClearCheckData> _LevelClearData;
	std::map<int, ChaoGardenCheckData> _ChaoGardenData;
	std::map<int, ChaoKeyCheckData> _ChaoKeyData;
	std::map<int, PipeCheckData> _PipeData;
	std::map<int, HiddenCheckData> _HiddenData;
	std::map<int, GoldBeetleCheckData> _GoldBeetleData;
	std::map<int, OmochaoCheckData> _OmochaoData;

	std::map<int, std::vector<int>> _ChaoRacePacks;
};
