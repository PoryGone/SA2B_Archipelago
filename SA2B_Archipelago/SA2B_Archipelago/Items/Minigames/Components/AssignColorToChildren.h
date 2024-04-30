#pragma once
#include "../Backend/SpriteNode.h"

class AssignColorToChildren : public SpriteComponent
{
public:
	void OnFrame(SpriteNode& node) override;

	AssignColorToChildren() : includeFullHierarchy(false) {}
	AssignColorToChildren(bool _includeFullHierarchy) : includeFullHierarchy(_includeFullHierarchy) {}

private:
	bool includeFullHierarchy;
};