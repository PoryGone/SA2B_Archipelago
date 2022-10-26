#include "../pch.h"
#pragma once

#include <map>
#include <queue>
#include "ItemData.h"
#include "../ModLoaderCommon/Trampoline.h"

FunctionPointer(double, sa2b_ceil, (double a1), 0x007A7B50);

constexpr unsigned int AP_ITEM_ID_OFFSET = 0xFF0000;
constexpr unsigned int TRAP_DURATION = 600;
constexpr unsigned int TRAP_COOLDOWN = 60;
constexpr unsigned int JUNK_COOLDOWN = 210;

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

	int _TimeStopTimer;

private:
	void HandleEquipment(int EquipmentItem);
	void HandleJunk(int item_id);
	void HandleTrap(int item_id);
	void OnFrameJunkQueue();
	void OnFrameTrapQueue();
	const HelperFunctions* _helperFunctions;

	std::map<int, ItemData> _ItemData;
	int _thisSessionChecksReceived = 0;
	unsigned __int8 _EmblemsReceived = 0;

	std::queue<int> _JunkQueue;
	std::queue<int> _TrapQueue;

	int _ActiveTrap = 0;
	int _ActiveTrapTimer = 0;
	int _TrapCooldownTimer = TRAP_COOLDOWN;
	int _JunkCooldownTimer = 0;

	NJS_VECTOR _TimeStopPos;

	CharObj2Base* _p2Obj;
};