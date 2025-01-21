#pragma once
#include "../Backend/SpriteNode.h"
#include "../MinigameIconData.h"
#include <vector>


class Flipbook : public SpriteComponent
{
public:
	void OnFrame(SpriteNode& node) override;

	Flipbook(std::vector<NJS_TEXANIM*> _icons, int _framesPerImage) : framesPerImage(_framesPerImage), frameCount(0), index(0), icons(_icons) {}

private:
	int framesPerImage;
	int frameCount;
	int index;
	std::vector<NJS_TEXANIM*> icons;

};