#include "../../../../pch.h"
#include "TimeUtilities.h"

std::string FormatTime_MSS(float seconds)
{
	int s = (int)truncf(seconds) % 60;
	int m = (int)truncf(seconds / 60.0f);
	std::string timeString = std::to_string(m);
	timeString.append(s < 10 ? ":0" : ":");
	timeString.append(std::to_string(s));
}