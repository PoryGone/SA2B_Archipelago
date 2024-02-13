#include "../../../pch.h"
#include "SpriteNode.h"
#include "../../../Utilities/SpriteUtilities.h"
#include <functional>

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
	globalPosition = pos;
	NJS_POINT3 local = globalPosition;
	SpriteNode* ptr = this;
	while (ptr->parent != nullptr)
	{
		ptr = ptr->parent;
		Point3SubtractEQ(local, (*ptr).localPosition);
	}
	localPosition = local;
	SetBranchDirty();
}

void SpriteNode::SetPosition(NJS_POINT3 pos)
{
	localPosition = pos;
	SetBranchDirty();
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

void SpriteNode::Translate(NJS_POINT3 delta)
{
	NJS_POINT3 pos = GetPositionGlobal();
	Point3AddEQ(pos, delta);
	SetPositionGlobal(pos);
}

void SpriteNode::SetEnabled(bool enabled)
{
	if (enabled != enabledSelf)
	{
		enabledSelf = enabled;
		std::function<void(SpriteNode&)> func = [](SpriteNode& node) {node.SetEnabledDirty(); };
		RunMethodOnHeirarchy(func);
	}
}

bool SpriteNode::IsEnabledSelf()
{
	return enabledSelf;
}

bool SpriteNode::IsEnabled()
{
	if (isEnabledDirty)
	{
		enabledInHierarchy = true;
		SpriteNode* ptr = this;
		while (ptr->parent != nullptr)
		{
			ptr = ptr->parent;
			if (!ptr->IsEnabled())
			{
				enabledInHierarchy = false;
				break;
			}
		}
		isEnabledDirty = false;
	}
	return enabledInHierarchy && enabledSelf;
}

void SpriteNode::Render(NJS_SPRITE& sprite)
{
	if (anim != nullptr && IsEnabled())
	{
		NJS_TEXANIM* tempAnim = anim;
		tempAnim--;
		sprite.tanim = tempAnim;
		sprite.p = GetPositionGlobal();
		sprite.ang = NJM_DEG_ANG(rotation);
		sprite.sx = displaySize.x / (float)anim->sx;
		sprite.sy = displaySize.y / (float)anim->sy;
		ConstantMaterial = color;
		if (rotation != 0.0f) 
		{
			DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE | NJD_SPRITE_COLOR);
		}
		else
		{
			DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
		}
		ResetMaterial();
	}

	if (IsEnabled())
	{
		for (auto& component : this->renderComponents)
		{
			component->OnRender(*this);
		}
	}
}

void SpriteNode::OnFrame()
{
	for (auto& component : this->components)
	{
		component->OnFrame(*this);
	}
}

void SpriteNode::RunMethodOnHeirarchy(std::function<void(SpriteNode&)> func, bool depthFirst)
{
	if (!depthFirst) 
	{
		func(*this);
	}
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->RunMethodOnHeirarchy(func, depthFirst);
	}
	if (depthFirst)
	{
		func(*this);
	}
}

void SpriteNode::SetPositionDirty()
{
	isGlobalPositionDirty = true;
}

void  SpriteNode::SetEnabledDirty()
{
	isEnabledDirty = true;
}

void SpriteNode::SetBranchDirty()
{
	std::function<void(SpriteNode&)> func = [](SpriteNode& node) {node.SetPositionDirty(); };
	RunMethodOnHeirarchy(func);
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
