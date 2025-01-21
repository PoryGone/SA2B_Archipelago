#include "../../../pch.h"
#include "Flipbook.h"

void Flipbook::OnFrame(SpriteNode& node)
{
	frameCount++;
	if (frameCount >= framesPerImage)
	{
		index = index < icons.size() - 1 ? index + 1 : 0;
		frameCount = 0;
	}
	node.anim = icons[index];
}