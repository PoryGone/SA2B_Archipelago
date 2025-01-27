#include "../pch.h"
#pragma once

struct APStats
{
public:
	int GateUnlockFrames[5];
	int RingsCollected;
	int dword_1DED1CC;
	int ReceivedDeaths;
	int SentDeaths;
	int dword_1DED1D8;
	int HintMonitorsUsed;
	int CCUnlockFrames;
	int dword_1DED1E4;
	int MinigamesWon;
	int MinigamesLost;
	int dword_1DED1F0;
	int PositiveRingsSent;
	int PositiveRingsReceived;
	int dword_1DED1FC;
	int NegativeRingsSent;
	int NegativeRingsReceived;
	int dword_1DED208;
	int SentTrapLinks;
	int ReceivedTrapLinks;
	int dword_1DED214;
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
	void RingLinkSent(int amount);
	void RingLinkReceived(int amount);
	void TrapLinkSent();
	void TrapLinkReceived();
	void MinigameWon();
	void MinigameLost();
	void DeathLinkActive(bool isActive);
	void RingLinkActive(bool isActive);
	void TrapLinkActive(bool isActive);
	void HintMonitorUsed();
	void CanonsCoreUnlocked();
	void GateUnlocked(int index);
	void Victory();

private:
	const HelperFunctions* _helperFunctions;
	int _lastRingCount;
	int _lastHintCount;
	bool _deathLinkActive;
	bool _ringLinkActive;
	bool _trapLinkActive;
};