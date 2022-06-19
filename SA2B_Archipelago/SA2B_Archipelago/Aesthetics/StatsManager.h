#include "../pch.h"
#pragma once

struct APStats
{
public:
	int GateUnlockFrames[5];
	int RingsCollected;
	int dword_1DEC714;
	int ReceivedDeaths;
	int SentDeaths;
	int dword_1DEC720;
	int HintMonitorsUsed;
	int CCUnlockFrames;
	int dword_1DEC72C;
};

DataPointer(APStats, apStats, 0x01DED1B4);

class StatsManager
{
public:
	static StatsManager& GetInstance()
	{
		static StatsManager instance;
		return instance;
	}
	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();
	void DeathLinkSent();
	void DeathLinkReceived();
	void DeathLinkActive(bool isActive);
	void HintMonitorUsed();
	void CanonsCoreUnlocked();
	void GateUnlocked(int index);
	void Victory();

private:
	const HelperFunctions* _helperFunctions;
	int _lastRingCount;
	int _lastHintCount;
	bool _deathLinkActive;
};