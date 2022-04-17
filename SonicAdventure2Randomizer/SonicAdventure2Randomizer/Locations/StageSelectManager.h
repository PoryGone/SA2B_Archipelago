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

private:
	const HelperFunctions* _helperFunctions;
	std::map<int, StageSelectStageData> _stageSelectDataMap;

	void UnlockAllLevels();
	void HideMenuButtons();
	void HandleBiolizard();
};