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
	if (CurrentLevel != LevelIDs_FinalHazard)
	{
		int rings = (int)RingCount[0];
		if (rings > _lastRingCount)
		{
			apStats.RingsCollected += rings - _lastRingCount;
		}
		_lastRingCount = rings;
	}
	if (EmeraldManagerObj2)
	{
		if (EmeraldManagerObj2->HintCount > _lastHintCount)
		{
			apStats.HintMonitorsUsed += EmeraldManagerObj2->HintCount - _lastHintCount;
		}
		_lastHintCount = EmeraldManagerObj2->HintCount;
	}
}

void StatsManager::DeathLinkSent()
{
	apStats.SentDeaths++;
}

void StatsManager::DeathLinkReceived()
{
	apStats.ReceivedDeaths++;
}

void StatsManager::RingLinkSent(int amount)
{
	if (amount < 0)
	{
		apStats.NegativeRingsSent += abs(amount);
	}
	else
	{
		apStats.PositiveRingsSent += abs(amount);
	}
}

void StatsManager::RingLinkReceived(int amount)
{
	if (amount < 0)
	{
		apStats.NegativeRingsReceived += abs(amount);
	}
	else
	{
		apStats.PositiveRingsReceived += abs(amount);
	}
}

void StatsManager::TrapLinkSent()
{
	apStats.SentTrapLinks++;
}

void StatsManager::TrapLinkReceived()
{
	apStats.ReceivedTrapLinks++;
}

void StatsManager::MinigameWon()
{
	apStats.MinigamesWon++;
}

void StatsManager::MinigameLost()
{
	apStats.MinigamesLost++;
}

void StatsManager::DeathLinkActive(bool isActive)
{
	_deathLinkActive = isActive;
}

void StatsManager::RingLinkActive(bool isActive)
{
	_ringLinkActive = isActive;
}

void StatsManager::TrapLinkActive(bool isActive)
{
	_trapLinkActive = isActive;
}

void StatsManager::HintMonitorUsed()
{
	apStats.HintMonitorsUsed++;
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
	std::string statLine = std::string();
	statLine.append(title);
	int blanks = 30 - title.length() - stat.length();
	if (blanks > 0)
	{
		statLine.append(blanks, ' ');
	}
	statLine.append(stat);
	char* statLine_c = new char[31];
	strncpy(statLine_c, statLine.c_str(), 31);
	statLine_c[30] = '\0';
	return SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, statLine_c);
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
	creditsEntries.emplace_back();
	creditsEntries.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Title, SA2B_AP_Color, "Stats"));
	creditsEntries.emplace_back(CreateStatsEntry("RINGS COLLECTED", std::to_string(apStats.RingsCollected)));
	if (_deathLinkActive)
	{
		creditsEntries.emplace_back(CreateStatsEntry("DEATHS SENT", std::to_string(apStats.SentDeaths)));
		creditsEntries.emplace_back(CreateStatsEntry("DEATHS RECEIVED", std::to_string(apStats.ReceivedDeaths)));
	}
	else
	{
		creditsEntries.emplace_back(CreateStatsEntry("DEATHS", std::to_string(apStats.SentDeaths)));
	}
	if (_trapLinkActive)
	{
		creditsEntries.emplace_back(CreateStatsEntry("TRAPS SENT", std::to_string(apStats.SentTrapLinks)));
		creditsEntries.emplace_back(CreateStatsEntry("TRAPS RECEIVED", std::to_string(apStats.ReceivedTrapLinks)));
	}
	if (_ringLinkActive)
	{
		std::string ringSend = "+";
		ringSend.append(std::to_string(apStats.PositiveRingsSent));
		ringSend.append(" / -");
		ringSend.append(std::to_string(apStats.NegativeRingsSent));
		creditsEntries.emplace_back(CreateStatsEntry("RINGS SENT", ringSend));

		std::string ringReceive = "+";
		ringReceive.append(std::to_string(apStats.PositiveRingsReceived));
		ringReceive.append(" / -");
		ringReceive.append(std::to_string(apStats.NegativeRingsReceived));
		creditsEntries.emplace_back(CreateStatsEntry("RINGS RECEIVED", ringReceive));
	}
	if ((apStats.MinigamesWon + apStats.MinigamesLost) > 0)
	{
		std::string minigameStats = "";
		minigameStats.append(std::to_string(apStats.MinigamesWon));
		minigameStats.append("/");
		minigameStats.append(std::to_string((apStats.MinigamesWon + apStats.MinigamesLost)));
		creditsEntries.emplace_back(CreateStatsEntry("MINIGAMES WON", minigameStats));
	}
	/*if (apStats.HintMonitorsUsed > 0)
	{
		creditsEntries.emplace_back(CreateStatsEntry("HINT MONITORS USED", std::to_string(apStats.HintMonitorsUsed)));
	}*/
	if (apStats.CCUnlockFrames > 0)
	{
		creditsEntries.emplace_back(CreateStatsEntry("CANNONS CORE UNLOCK TIME", FormatGameTime(apStats.CCUnlockFrames)));
	}
	for (int i = 0; i < 5; i++)
	{
		if (apStats.GateUnlockFrames[i] > 0)
		{
			std::string gateTitle = "GATE ";
			gateTitle.append(std::to_string(i + 1));
			gateTitle.append(" UNLOCK TIME");
			creditsEntries.emplace_back(CreateStatsEntry(gateTitle, FormatGameTime(apStats.GateUnlockFrames[i])));
		}
	}
	creditsEntries.emplace_back(CreateStatsEntry("TOTAL TIME", FormatGameTime(TimeTotal)));

	// TODO: RAS: Add new fields to credits

	CreditsManager::GetInstance().UpdateCredits(creditsEntries);
}