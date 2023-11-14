#pragma once
#include <ctime>

class Stopwatch
{
public:
	void Start();
	void Stop();
	void Pause();
	void Resume();
	float TimeElapsed();
	bool IsPaused();

	Stopwatch() : start(std::clock()), pauseElapsed(0.0f), isPaused(false) {}

private:
	float ElapsedTime();

	clock_t start;
	float pauseElapsed;
	bool isPaused;
};