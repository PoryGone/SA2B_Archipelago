#include "../pch.h"
#pragma once

#include <map>
#include "LocationData.h"
#include "../Archipelago/ArchipelagoManager.h"

constexpr unsigned int MEMORY_CHECK_TIME = 120;
constexpr unsigned int CHAO_MEMORY_CHECK_TIME = 240;

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
	void OnFrameChaoGarden();
	void CheckLocation(int location_id);
	void SetRequiredRank(int requiredRank);
	void SetChaoKeysEnabled(bool chaoKeysEnabled);
	void SetRacesPacked(bool racesPacked);
	void SetChaoEnabled(bool chaoEnabled);
	void ResetLocations();

private:
	const HelperFunctions* _helperFunctions;
	ArchipelagoManager* _archipelagoManager;

	unsigned int _timer = 0;
	unsigned int _chaoTimer = 0;
	int _requiredRank = 0;
	bool _chaoKeysEnabled = false;
	bool _racesPacked = false;
	bool _chaoEnabled = false;

	std::map<int, LevelClearCheckData> _LevelClearData;
	std::map<int, ChaoGardenCheckData> _ChaoGardenData;
	std::map<int, ChaoKeyCheckData> _ChaoKeyData;

	std::map<int, std::vector<int>> _ChaoRacePacks;
};
