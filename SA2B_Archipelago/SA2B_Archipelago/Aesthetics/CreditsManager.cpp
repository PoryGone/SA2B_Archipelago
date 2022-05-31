#include "../pch.h"
#include "CreditsManager.h"
#include "../Utilities/MessageQueue.h"

DataArray(SA2BCreditsEntry, Credits, 0x966400, 549);
// 3 minimum with 2 blanks to steal leaves 30 free credits lines
const int MinimumBlanksToStealFrom = 3;
const int BlanksToSteal = 2;

void GenerateAPCredits(std::vector<SA2BCreditsEntry>& apCredits)
{
	apCredits = std::vector<SA2BCreditsEntry>();

	int consecutiveBlanks = 0;

	for (int i = 0; i < 549; i++)
	{
		if (Credits[i].Type != CreditsEntryType::CET_Blank)
		{
			if (consecutiveBlanks > MinimumBlanksToStealFrom)
			{
				consecutiveBlanks -= BlanksToSteal;
			}
			while (consecutiveBlanks > 0)
			{
				apCredits.emplace_back();
				consecutiveBlanks--;
			}
			apCredits.emplace_back(Credits[i]);
			consecutiveBlanks = 0;
		}
		else
		{
			consecutiveBlanks++;
		}
	}

	apCredits.emplace_back();
	apCredits.emplace_back();
	apCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Logo_4, SA2B_AP_Color, ""));
	apCredits.emplace_back();
	apCredits.emplace_back();
	apCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "PORYGONE"));
	apCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "RASPBERRYSPACEJAM"));
	apCredits.emplace_back();
	apCredits.emplace_back();
	apCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Title, SA2B_AP_Color, "AP Randomizer Special Thanks"));
	apCredits.emplace_back();
	apCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "MAINMEMORY"));
	apCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "N00BYKING"));
	apCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "THEBULBLAXEMPIRE"));
	apCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "X-HAX COMMUNITY"));
	apCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "ARCHIPELAGO COMMUNITY"));
}

void OverwriteCredits(std::vector<SA2BCreditsEntry>& newCredits)
{
	for (int i = 0; i < 549; i++)
	{
		if (newCredits.size() > i)
		{
			Credits[i] = newCredits[i];
		}
		else
		{
			Credits[i] = SA2BCreditsEntry();
		}
	}
}

void CreditsManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	GenerateAPCredits(apCredits);
	std::vector<SA2BCreditsEntry> empty = std::vector<SA2BCreditsEntry>();
	UpdateCredits(empty);
}

void CreditsManager::UpdateCredits(std::vector<SA2BCreditsEntry>& statsEntries)
{
	std::vector<SA2BCreditsEntry> updatedCredits = std::vector<SA2BCreditsEntry>();

	for (int i = 0; i < apCredits.size(); i++)
	{
		updatedCredits.push_back(apCredits[i]);
	}

	for (int i = 0; i < statsEntries.size(); i++)
	{
		updatedCredits.push_back(statsEntries[i]);
	}

	//14 entries for stats

	OverwriteCredits(updatedCredits);
	/*
	std::string logMessage = "Blank Credits Spots: ";
	logMessage.append(std::to_string(549 - updatedCredits.size()));
	MessageQueue::GetInstance().AddMessage(logMessage.c_str());
	*/
}