#pragma once
#include "../Backend/SpriteNode.h"

class Rotator : public SpriteComponent
{
public:
	void OnFrame(SpriteNode& node) override;
	void UpdateDelta(float d);

	Rotator() : rotationDelta(1.0f) {}
	Rotator(float _rotationDelta) : rotationDelta(_rotationDelta) {}
	
private:
	float rotationDelta = 1.0f;
};

