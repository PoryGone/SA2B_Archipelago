#pragma once
#include <string>
#include "Timer.h"
#include "Stopwatch.h"

/// <summary>
/// Formats time to {Minutes}:{Seconds}. This will always display at least 1 digit for minutes and always display exactly 2 digits for seconds with no trailing decimal.
/// </summary>
std::string FormatTime_MSS(float seconds);
