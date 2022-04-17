#include "../pch.h"
#include "StageSelectData.h"
#include <map>
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

	void UnlockAllLevels();
	void HideMenuButtons();
	void HandleBiolizard();
};