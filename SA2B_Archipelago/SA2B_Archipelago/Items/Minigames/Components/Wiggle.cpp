#include "../../../pch.h"
#include "Wiggle.h"

void Wiggle::OnFrame(SpriteNode& node)
{
	if(!isInitialized) 
	{
		currentRotation = node.GetRotation();
	}
	
	currentRotation = isIncreasing ? currentRotation + delta : currentRotation - delta;
	if (currentRotation < minRotation)
	{
		currentRotation += minRotation - currentRotation;
		isIncreasing = true;
	}
	if (currentRotation > maxRotation)
	{
		currentRotation -= currentRotation - maxRotation;
		isIncreasing = false;
	}
	node.SetRotation(currentRotation);
}

void Wiggle::UpdateDelta(float d)
{
	delta = d;
}

void Wiggle::UpdateRange(float _min, float _max)
{
	minRotation = _min;
	maxRotation = _max;
}