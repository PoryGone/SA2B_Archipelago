#include "../pch.h"
#pragma once
#include <map>
#include <vector>
#include <array>
#include "../Items/ItemData.h"

class StageSelectIcons
{
public:
	void OnFrame();
	void OnInit(std::map<int, StageSelectStageData>* stageSelectDataMap);
	ObjectMaster* DrawIconObj;
	std::map<int, ItemData> ItemData;
	std::vector<CharacterItemRange> CharacterItemRanges;
};