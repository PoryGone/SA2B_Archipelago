#include "../pch.h"
#include "StatsManager.h"
#include "CreditsManager.h"
#include "../Utilities/MessageQueue.h"
#include <string>
#include <vector>

void StatsManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
}

void StatsManager::OnFrameFunction()
{
	std::string msg = "";
	int rings = (int)RingCount[0];
	msg.append(std::to_string(rings));
	if (rings > _lastRingCount)
	{
		apStats.RingsCollected += rings - _lastRingCount;
	}
	_lastRingCount = rings;
	msg.append(", ");
	msg.append(std::to_string(apStats.RingsCollected));
	_helperFunctions->SetDebugFontColor(0xFFF542C8);
	_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 6), msg.c_str());
}

void StatsManager::DeathLinkSent()
{
	apStats.SentDeaths++;
}

void StatsManager::DeathLinkReceived()
{
	apStats.ReceivedDeaths++;
}

void StatsManager::DeathLinkAvtive(bool isActive)
{
	_deathLinkActive = isActive;
}

void StatsManager::CanonsCoreUnlocked()
{
	if (apStats.CCUnlockFrames == 0)
	{
		apStats.CCUnlockFrames = TimeTotal;
	}
}

void StatsManager::GateUnlocked(int index)
{
	if (apStats.GateUnlockFrames[index] == 0)
	{
		apStats.GateUnlockFrames[index] = TimeTotal;
	}
}

SA2BCreditsEntry CreateStatsEntry(std::string title, std::string stat)
{
	std::string statLine;
	statLine.append(title);
	int blanks = 20 - title.length() - stat.length();
	if (blanks > 0)
	{
		statLine.append(blanks, ' ');
	}
	statLine.append(stat);
	MessageQueue::GetInstance().AddMessage(statLine.c_str());
	return SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, statLine.c_str());
}

std::string FormatGameTime(int frames)
{
	int seconds = frames / 60;
	int minutes = seconds / 60;
	int hours = minutes / 60;
	std::string time;
	if (hours < 10)
	{
		time.append("0");
	}
	time.append(std::to_string(hours));
	time.append(":");
	minutes %= 60;
	if (minutes < 10)
	{
		time.append("0");
	}
	time.append(std::to_string(minutes));
	time.append(":");
	seconds %= 60;
	if (seconds < 10)
	{
		time.append("0");
	}
	time.append(std::to_string(seconds));
	return time;
}

void StatsManager::Victory()
{
	std::vector<SA2BCreditsEntry> creditsEntries = std::vector<SA2BCreditsEntry>();
	creditsEntries.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Title, SA2B_AP_Color, "Stats"));
	creditsEntries.emplace_back();
	creditsEntries.push_back(CreateStatsEntry("RINGS COLLECTED", std::to_string(apStats.RingsCollected)));
	if (_deathLinkActive)
	{
		creditsEntries.push_back(CreateStatsEntry("DEATHS SENT", std::to_string(apStats.SentDeaths)));
		creditsEntries.push_back(CreateStatsEntry("DEATHS RECEIVED", std::to_string(apStats.ReceivedDeaths)));
	}
	else
	{
		creditsEntries.push_back(CreateStatsEntry("DEATHS", std::to_string(apStats.SentDeaths)));
	}
	if (apStats.CCUnlockFrames > 0)
	{
		creditsEntries.push_back(CreateStatsEntry("CANNONS CORE UNLOCK TIME", FormatGameTime(apStats.CCUnlockFrames)));
	}
	for (int i = 0; i < 5; i++)
	{
		if (apStats.GateUnlockFrames[i] > 0)
		{
			std::string gateTitle = "GATE ";
			gateTitle.append(std::to_string(i + 1));
			gateTitle.append(" UNLOCK TIME");
			creditsEntries.push_back(CreateStatsEntry(gateTitle, FormatGameTime(apStats.GateUnlockFrames[i])));
		}
	}
	creditsEntries.push_back(CreateStatsEntry("TOTAL TIME", FormatGameTime(TimeTotal)));


	CreditsManager::GetInstance().UpdateCredits(creditsEntries);
}