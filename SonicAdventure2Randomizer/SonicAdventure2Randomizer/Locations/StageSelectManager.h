#include "../pch.h"
#include "StageSelectData.h"
#include <map>
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

	void LayoutLevels();
	void SetLevelsLockState();
	void UnlockAllLevels();
	void HideMenuButtons();
	void HandleBiolizard();
};

struct GateLevelCollection
{
public:
	GateLevelCollection() : EmblemCount(0), Levels() {}
	GateLevelCollection(int _emblemCount) : EmblemCount(_emblemCount), Levels() {}

	int EmblemCount;
	std::vector<int> Levels;
};