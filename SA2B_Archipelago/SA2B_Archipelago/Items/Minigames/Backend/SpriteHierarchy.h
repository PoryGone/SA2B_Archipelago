#pragma once
#include "SpriteNode.h"

class SpriteHierarchy
{
public:
	SpriteNode rootNode = SpriteNode("ROOT_NODE");

	void AddNode(SpriteNode* node, SpriteNode* parent = nullptr);
	void Render();
	void OnFrame();
	void ClearHierarchy();
};