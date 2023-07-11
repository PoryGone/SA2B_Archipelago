#include "../../../pch.h"
#include "RotateSpriteNode.h"

void RotateSpriteNode::OnFrame(SpriteNode& node)
{
	currentRotation += rotationDelta;
	currentRotation = currentRotation > 360.0f ? currentRotation - 360.0f : currentRotation;
	node.rotation = currentRotation;
}