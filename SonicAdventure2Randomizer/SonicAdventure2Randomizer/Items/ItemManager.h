#include "../pch.h"
#pragma once

#include <map>
#include "ItemData.h"

constexpr unsigned int AP_ITEM_ID_OFFSET = 0xFF0000;

class ItemManager
{
public:
	static ItemManager& getInstance()
	{
		static ItemManager instance;
		return instance;
	}

	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();

	// Item Functions
	void ResetItems();
	void ReceiveItem(int item_id, bool notify);

private:
	const HelperFunctions* _helperFunctions;

	std::map<int, ItemData> _ItemData;
};