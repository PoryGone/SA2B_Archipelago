#include "../../../../pch.h"
#include "Stopwatch.h"

void Stopwatch::Start()
{
	start = std::clock();
	pauseElapsed = 0.0f;
	isPaused = false;
}

void Stopwatch::Stop()
{
	Pause();
}

void Stopwatch::Pause()
{
	if (!isPaused)
	{
		pauseElapsed += ElapsedTime();
		isPaused = true;
	}
}

void Stopwatch::Resume()
{
	if (isPaused)
	{
		start = std::clock();
		isPaused = false;
	}
}

float Stopwatch::TimeElapsed()
{
	if (isPaused)
	{
		return pauseElapsed;
	}
	else
	{
		return pauseElapsed + ElapsedTime();
	}
}

bool Stopwatch::IsPaused()
{
	return isPaused;
}

float Stopwatch::ElapsedTime()
{
	return (std::clock() - start) / (double)CLOCKS_PER_SEC;
}