#include "../pch.h"
#include "CreditsManager.h"
#include "../Utilities/MessageQueue.h"

DataArray(SA2BCreditsEntry, Credits, 0x966400, 549);
// 3 minimum with 2 blanks to steal leaves 30 free credits lines
const int MinimumBlanksToStealFrom = 3;
const int BlanksToSteal = 2;
const SA2BCreditsColor SA2B_AP_Color = SA2BCreditsColor(1.0, 0.96078, 0.25882, 0.78431);

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
	std::vector<SA2BCreditsEntry> updatedCredits = std::vector<SA2BCreditsEntry>();

	int consecutiveBlanks = 0;

	for (int i = 0; i < 549; i++)
	{
		if (Credits[i].Type != CreditsEntryType::CET_Blank)
		{
			if (Credits[i].Type > 2)
			{
				std::string typeMessage = "Unknown Type: ";
				typeMessage.append(std::to_string(Credits[i].Type));
				MessageQueue::GetInstance().AddMessage(typeMessage.c_str());
			}
			if (consecutiveBlanks > MinimumBlanksToStealFrom)
			{
				consecutiveBlanks -= BlanksToSteal;
			}
			while (consecutiveBlanks > 0)
			{
				updatedCredits.emplace_back();
				consecutiveBlanks--;
			}
			updatedCredits.emplace_back(Credits[i]);
			consecutiveBlanks = 0;
		}
		else
		{
			consecutiveBlanks++;
		}
	}

	updatedCredits.emplace_back();
	updatedCredits.emplace_back();
	updatedCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Title, SA2B_AP_Color, "SA2B Archipelago Randomizer"));
	updatedCredits.emplace_back();
	updatedCredits.emplace_back();
	updatedCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "PORYGONE"));
	updatedCredits.emplace_back();
	updatedCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "RASPBERRYSPACEJAM"));
	updatedCredits.emplace_back();
	updatedCredits.emplace_back();
	updatedCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Title, SA2B_AP_Color, "AP Randomizer Special Thanks"));
	updatedCredits.emplace_back();
	updatedCredits.emplace_back();
	updatedCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "MAINMEMORY"));
	updatedCredits.emplace_back();
	updatedCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "N00BYKING"));
	updatedCredits.emplace_back();
	updatedCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "THEBULBLAXEMPIRE"));
	updatedCredits.emplace_back();
	updatedCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "X-HAX COMMUNITY"));
	updatedCredits.emplace_back();
	updatedCredits.push_back(SA2BCreditsEntry(CreditsEntryType::CET_Name, SA2B_AP_Color, "ARCHIPELAGO COMMUNITY"));


	OverwriteCredits(updatedCredits);
	/*
	std::string logMessage = "Blank Credits Spots: ";
	logMessage.append(std::to_string(549 - updatedCredits.size()));
	MessageQueue::GetInstance().AddMessage(logMessage.c_str());
	*/
}