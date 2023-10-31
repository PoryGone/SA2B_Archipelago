#pragma once
#include "BoundingBox.h"
#include "../SpriteNode.h"

class Collider
{
public:
	virtual bool IsColliding(Collider& otherCollider) = 0;
	virtual BoundingBox GetBoundingBox() = 0;
	NJS_POINT3 offset;
	SpriteNode* node;

	Collider() : offset({ 0.0f,0.0f,0.0f }), node(nullptr) {}
	Collider(NJS_POINT3 _offset) : offset(_offset), node(nullptr) {}
	Collider(SpriteNode* _node) : offset({ 0.0f,0.0f,0.0f }), node(_node) {}
	Collider(NJS_POINT3 _offset, SpriteNode* _node) : offset(_offset), node(_node) {}
};