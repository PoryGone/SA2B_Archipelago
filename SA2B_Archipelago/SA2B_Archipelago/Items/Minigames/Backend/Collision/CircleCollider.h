#pragma once
#include "CollisionManager.h"

class CircleCollider : public Collider
{
public:
	bool IsColliding(Collider& otherCollider) override;
	BoundingBox GetBoundingBox() override;

	NJS_POINT3 GetCenter();
	NJS_POINT3 GetClosestPoint(NJS_POINT3 point);

	float radius;

	CircleCollider() : Collider(), radius(0.0f) {}
	CircleCollider(float _radius) : Collider(), radius(_radius) {}
	CircleCollider(float _radius, NJS_POINT3 _offset) : Collider(_offset), radius(_radius) {}
	CircleCollider(float _radius, NJS_POINT3 _offset, SpriteNode* _node) : Collider(_offset, _node), radius(_radius) {}
	CircleCollider(float _radius, SpriteNode* _node) : Collider(_node), radius(_radius) {}
};