#include "../../../pch.h"
#include "SpriteNode.h"
#include "../../../Utilities/SpriteUtilities.h"

void SpriteNode::RemoveFromChildren(SpriteNode* child) 
{
	for (int i = 0; i < children.size(); i++) 
	{
		if (children[i] == child) 
		{
			children.erase(children.begin() + i);
			i--;
		}
	}
}

void SpriteNode::SetPositionGlobal(NJS_POINT3 pos) 
{

}

void SpriteNode::SetPosition(NJS_POINT3 pos)
{

}

NJS_POINT3 SpriteNode::GetPosition()
{
	return localPosition;
}

NJS_POINT3 SpriteNode::GetPositionGlobal()
{
	UpdateGlobalPosition();
	return globalPosition;
}

void SpriteNode::Render(NJS_SPRITE& sprite)
{
	if (anim == nullptr) return;
	sprite.tanim = anim;
	sprite.p = globalPosition;
	sprite.ang = NJM_DEG_ANG(rotation);
	sprite.sx = displaySize.x / anim->sx;
	sprite.sy = displaySize.y / anim->sy;
	DrawSprite2D(&sprite);
}

void SpriteNode::OnFrame()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i].OnFrame(*this);
	}
}

void SpriteNode::RunMethodOnHeirarchy(std::function<void(SpriteNode&)> func, bool depthFirst)
{
	func(*this);
}

void SpriteNode::SetPositionDirty()
{
	isGlobalPositionDirty = true;
}

void SpriteNode::UpdateGlobalPosition()
{
	if (!isGlobalPositionDirty)
	{
		return;
	}
	NJS_POINT3 pos = localPosition;
	SpriteNode* ptr = this;
	while (ptr->parent != nullptr)
	{
		ptr = ptr->parent;
		Point3AddEQ(pos, (*ptr).localPosition);
	}
	globalPosition = pos;
}