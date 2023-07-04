#include "../../../pch.h"
#include "SpriteHierarchy.h"
#include <functional>

void SpriteHierarchy::AddNode(SpriteNode* node, SpriteNode* parent) 
{
	if ((*node).parent != nullptr) 
	{
		(*(*node).parent).RemoveFromChildren(node);
	}
	(*node).parent = (parent == nullptr) ? &rootNode : parent;
}

void SpriteHierarchy::Render() 
{
	NJS_SPRITE sprite{};
	std::function<void(SpriteNode&)> func = [&](SpriteNode& node) {node.Render(sprite); };
	rootNode.RunMethodOnHeirarchy(func);
}

void SpriteHierarchy::OnFrame()
{
	std::function<void(SpriteNode&)> func = [](SpriteNode& node) {node.OnFrame(); };
	rootNode.RunMethodOnHeirarchy(func);
}

void SpriteHierarchy::ClearHierarchy() {

}