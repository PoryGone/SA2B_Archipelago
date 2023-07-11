#pragma once
#include "../Backend/SpriteNode.h"

class RotateSpriteNode : public SpriteComponent
{
public:
	void OnFrame(SpriteNode& node) override;

	RotateSpriteNode() : currentRotation(0.0f), rotationDelta(1.0f) {}
	RotateSpriteNode(float _startingAngle, float _rotationDelta) : currentRotation(_startingAngle), rotationDelta(_rotationDelta) {}
	
private:
	float currentRotation = 0.0f; 
	float rotationDelta = 2.0f;
};

