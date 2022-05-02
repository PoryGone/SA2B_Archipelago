#include "../pch.h"
#pragma once

#include <map>
#include "LocationData.h"
#include "../Archipelago/ArchipelagoManager.h"

constexpr unsigned int MEMORY_CHECK_TIME = 120;

class LocationManager
{
public:
	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();
	void OnInputFunction();
	void OnControlFunction();

private:
	const HelperFunctions* _helperFunctions;
	ArchipelagoManager* _archipelagoManager;

	unsigned int _timer = 0;

	std::map<int, LevelClearCheckData> _LevelClearData;
};