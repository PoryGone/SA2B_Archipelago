#include "../../../../pch.h"
#include "Timer.h"

void Timer::Start(float time)
{
	isPaused = false;
	totalTime = time;
	start = std::clock();
}

void Timer::Stop()
{
	totalTime = 0.0f;
	start = std::clock();
}

void Timer::Pause()
{
	if (!isPaused)
	{
		totalTime = TimeRemaining();
		isPaused = true;
	}
}

void Timer::Resume()
{
	if (isPaused)
	{
		start = std::clock();
		isPaused = false;
	}
}

float Timer::TimeRemaining()
{
	if (isPaused)
	{
		return totalTime;
	}
	else
	{
		float remaining = totalTime - ElapsedTime();
		return remaining < 0.0f ? 0.0f : remaining;
	}
}

bool Timer::IsElapsed()
{
	return TimeRemaining() <= 0.0f;
}

bool Timer::IsPaused()
{
	return isPaused;
}

float  Timer::ElapsedTime()
{
	return (std::clock() - start) / (double)CLOCKS_PER_SEC;
}