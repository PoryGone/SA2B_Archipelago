#include "../pch.h"
#pragma once
#include <map>
#include <vector>
#include <array>
#include "../Items/ItemData.h"

class StageSelectIcons
{
public:
	static StageSelectIcons& GetInstance()
	{
		static StageSelectIcons instance;
		return instance;
	}
	void OnFrame();
	void OnInit(std::map<int, StageSelectStageData>* stageSelectDataMap);
	std::map<int, ItemData> ItemData;
	std::vector<CharacterItemRange> CharacterItemRanges;
	ObjectMaster* DrawIconObj;
};