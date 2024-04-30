#include "../../../pch.h"
#include "AssignColorToChildren.h"

void AssignColorToChildren::OnFrame(SpriteNode& node)
{
	for (int i = 0; i < node.children.size(); i++)
	{
		if (includeFullHierarchy)
		{
			NJS_ARGB c = node.color;
			std::function<void(SpriteNode&)> func = [c](SpriteNode& child) {child.color = c; };
			node.RunMethodOnHeirarchy(func);
		}
		else
		{
			node.children[i]->color = node.color;
		}
	}
}