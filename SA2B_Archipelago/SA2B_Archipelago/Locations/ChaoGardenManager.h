#include "../pch.h"
#pragma once

#include <map>
#include <vector>
#include "../Archipelago/ArchipelagoManager.h"
#include "../ModLoaderCommon/Trampoline.h"

constexpr unsigned int CGM_MEMORY_CHECK_TIME = 600;

class ChaoGardenManager
{
public:
	static ChaoGardenManager& GetInstance()
	{
		static ChaoGardenManager instance;
		return instance;
	}

	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();

	void SetChaoEnabled(bool chaoEnabled);
	void SetChaoRaceEnabled(bool chaoRaceEnabled);
	void SetChaoStatsEnabled(int chaoStatsEnabled);
	void SetChaoBodyPartsEnabled(bool chaoBodyPartsEnabled);
	void SetChaoKindergartenEnabled(bool chaoKindergartenEnabled);

	void SetDefaultEggMap(std::map<int, int> map);
	void SetDefaultChaoNameMap(std::map<int, int> map);

private:
	void HandleStartingEggs();
	void HandleSubsequentEggs();

	const HelperFunctions* _helperFunctions;
	ArchipelagoManager* _archipelagoManager;

	unsigned int _timer = 0;

	uint8_t _namesUsed = 4;

	bool _chaoEnabled = false;
	bool _chaoRaceEnabled = false;
	int _chaoStatsEnabled = 0;
	bool _chaoBodyPartsEnabled = false;
	bool _chaoKindergartenEnabled = false;
	
	std::map<int, int> _defaultEggMap;
	std::map<int, int> _defaultChaoNameMap;
};
