#pragma once
#include <ctime>

class Timer
{
public:
	void Start(float time);
	void Stop();
	void Pause();
	void Resume();
	float TimeRemaining();
	bool IsElapsed();
	bool IsPaused();

	Timer() : start(std::clock()), totalTime(0.0f), isPaused(false) {}
	Timer(float _time) : start(std::clock()), totalTime(_time), isPaused(false) {}

private:
	float ElapsedTime();

	clock_t start;
	float totalTime;
	bool isPaused;
};