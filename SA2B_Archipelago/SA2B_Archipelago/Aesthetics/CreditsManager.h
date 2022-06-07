#include "../pch.h"
#include <vector>
#include <string>
#pragma once

enum CreditsEntryType
{
	CET_Blank = 0,
	CET_Name = 1,
	CET_Title = 2,
	CET_Logo_0 = 3,
	CET_Logo_1 = 4,
	CET_Logo_2 = 5,
	CET_Logo_3 = 6,
	CET_Logo_4 = 7,
	CET_Logo_5 = 8,
	CET_Logo_6 = 9,
};

struct SA2BCreditsColor
{
	SA2BCreditsColor() : Alpha(1.0), Red(1.0), Green(1.0), Blue(0.0) {}
	SA2BCreditsColor(float a, float r, float g, float b) : Alpha(a), Red(r), Green(g), Blue(b) {}

	float Alpha;
	float Red;
	float Green;
	float Blue;
};

struct SA2BCreditsEntry
{
	SA2BCreditsEntry() : Type(CreditsEntryType::CET_Blank), Color(), Text() {}
	SA2BCreditsEntry(CreditsEntryType type, SA2BCreditsColor color, const char* text) : Type(type), Color(color), Text(text) {}

	CreditsEntryType Type;
	SA2BCreditsColor Color;
	const char* Text;
};

const SA2BCreditsColor SA2B_AP_Color = SA2BCreditsColor(1.0f, 0.96078f, 0.25882f, 0.78431f);

class CreditsManager
{
public:
	static CreditsManager& GetInstance()
	{
		static CreditsManager instance;
		return instance;
	}
	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void UpdateCredits(std::vector<SA2BCreditsEntry> statsEntries);

private:
	std::vector<SA2BCreditsEntry> apCredits = std::vector<SA2BCreditsEntry>();
};

