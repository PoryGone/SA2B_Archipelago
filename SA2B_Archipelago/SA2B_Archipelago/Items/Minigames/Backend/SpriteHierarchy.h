#pragma once
#include "SpriteNode.h"
#include "../MinigameIconData.h"

class SpriteHierarchy
{
public:
	MinigameIconData* iconData;

	SpriteNode rootNode = SpriteNode("ROOT_NODE");

	void AddNode(SpriteNode* node, SpriteNode* parent = nullptr);
	SpriteNode* CreateNode(std::string name, SpriteNode* parent = nullptr);
	SpriteNode* CreateNode(std::string name, NJS_TEXANIM* anim, NJS_POINT3 displaySize, NJS_POINT3 globalPosition, SpriteNode* parent = nullptr);
	
	void Render();
	void OnFrame();
	void ClearHierarchy();
};