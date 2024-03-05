#pragma once
#include "../Backend/SpriteNode.h"

class Wiggle : public SpriteComponent
{
public:
	void OnFrame(SpriteNode& node) override;

	void UpdateDelta(float d);
	void UpdateRange(float _min, float _max);

	Wiggle() : delta(1.0f), minRotation(0.0f), maxRotation(180.0f), isIncreasing(true), currentRotation(0.0f), isInitialized(false) {}
	Wiggle(float _delta, float _min, float _max) : delta(_delta), minRotation(_min), maxRotation(_max), isIncreasing(true), currentRotation(0.0f), isInitialized(false) {}
	Wiggle(float _delta, float _min, float _max, bool startWithIncreasing) : delta(_delta), minRotation(_min), maxRotation(_max), isIncreasing(startWithIncreasing), currentRotation(0.0f), isInitialized(false) {}

private:
	float delta;
	float minRotation;
	float maxRotation;
	bool isIncreasing;
	float currentRotation;
	bool isInitialized;
};

