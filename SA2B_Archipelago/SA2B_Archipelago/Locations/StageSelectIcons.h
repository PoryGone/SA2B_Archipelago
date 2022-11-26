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

struct NumberDisplayData 
{
	NumberDisplayData() : index(0), width(0.0f), xOffset(0.0f), yOffset(0.0f) {}
	NumberDisplayData(int _index, float _width, float _xOffset, float _yOffset) : index(_index), width(_width), xOffset(_xOffset), yOffset(_yOffset) {}

	int index;
	float width;
	float xOffset;
	float yOffset;
};

enum StageSelectIcon {
	SSI_ChaoKey					= 0,
	SSI_ChaoKeyDisabled			= 1,
	SSI_Pipe					= 2,
	SSI_PipeDisabled			= 3,
	SSI_GoldBeetle				= 4,
	SSI_GoldBeetleDisabled		= 5,
	SSI_Hidden					= 6,
	SSI_HiddenDisabled			= 7,
	SSI_Upgrade					= 8,
	SSI_UpgradeDisabled			= 9,
	SSI_Gate1					= 10,
	SSI_Gate2					= 11,
	SSI_Gate3					= 12,
	SSI_Gate4					= 13,
	SSI_Gate5					= 14,
	SSI_Emerald_None			= 15,
	SSI_Emerald_White			= 16,
	SSI_Emerald_Red				= 17,
	SSI_Emerald_Cyan			= 18,
	SSI_Emerald_Purple			= 19,
	SSI_Emerald_Green			= 20,
	SSI_Emerald_Yellow			= 21,
	SSI_Emerald_Blue			= 22,
	SSI_CannonsCore				= 23,
};