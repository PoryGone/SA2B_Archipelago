#include "../../../pch.h"
#include "Rotator.h"

void Rotator::OnFrame(SpriteNode& node)
{
	node.Rotate(rotationDelta);
}

void Rotator::UpdateDelta(float d)
{
	rotationDelta = d;
}