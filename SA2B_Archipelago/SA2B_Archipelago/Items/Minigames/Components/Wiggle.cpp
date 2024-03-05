#include "../../../pch.h"
#include "Wiggle.h"
#include <string>

void Wiggle::OnFrame(SpriteNode& node)
{
	if(!isInitialized) 
	{
		currentRotation = node.GetRotation();
		isInitialized = true;
	}
	
	currentRotation = isIncreasing ? currentRotation + delta : currentRotation - delta;
	if (currentRotation < minRotation)
	{
		currentRotation += minRotation - currentRotation;
		isIncreasing = !isIncreasing;
	}
	if (currentRotation > maxRotation)
	{
		currentRotation -= currentRotation - maxRotation;
		isIncreasing = !isIncreasing;
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