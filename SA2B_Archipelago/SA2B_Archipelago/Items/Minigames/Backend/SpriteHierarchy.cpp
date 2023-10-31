#include "../../../pch.h"
#include "SpriteHierarchy.h"
#include <functional>

void SpriteHierarchy::AddNode(SpriteNode* node, SpriteNode* parent) 
{
	NJS_POINT3 gPos = node->GetPositionGlobal();
	if ((*node).parent != nullptr) 
	{
		(*(*node).parent).RemoveFromChildren(node);
	}
	node->parent = (parent == nullptr) ? &rootNode : parent;
	node->parent->children.push_back(node);
	node->SetPositionGlobal(gPos);
}

SpriteNode* SpriteHierarchy::CreateNode(std::string name, SpriteNode* parent) 
{
	return CreateNode(name, nullptr, { 1, 1, 0 }, { 0, 0, 0 }, parent);
}

SpriteNode* SpriteHierarchy::CreateNode(std::string name, NJS_TEXANIM* anim, NJS_POINT3 displaySize, NJS_POINT3 globalPosition, SpriteNode* parent) 
{
	SpriteNode* node = new SpriteNode(name, anim, displaySize, globalPosition);
	AddNode(node, parent);
	return node;
}

void SpriteHierarchy::Render() 
{
	NJS_SPRITE sprite = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, iconData->MinigameTex, iconData->MinigameAnims };
	std::function<void(SpriteNode&)> func = [&](SpriteNode& node) {node.Render(sprite); };
	rootNode.RunMethodOnHeirarchy(func);
}

void SpriteHierarchy::OnFrame()
{
	std::function<void(SpriteNode&)> func = [](SpriteNode& node) {node.OnFrame(); };
	rootNode.RunMethodOnHeirarchy(func);
}

void SpriteHierarchy::ClearHierarchy() 
{
	std::function<void(SpriteNode&)> func = [](SpriteNode& node) 
	{
		if (node.name != "ROOT_NODE")
		{
			for(int i = 0; i < node.components.size(); i++)
			delete node.components[i];
			delete& node;
		}
	};
	rootNode.RunMethodOnHeirarchy(func, true);
	rootNode.children.clear();
}
