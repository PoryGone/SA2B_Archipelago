#pragma once
#include "Collider.h"
#include "CircleCollider.h"

class CapsuleCollider : public Collider
{
public:
	bool IsColliding(Collider& otherCollider) override;
	BoundingBox GetBoundingBox() override;

	NJS_POINT3 GetCenter();
	NJS_POINT3 GetClosestPoint(NJS_POINT3 point);
	NJS_POINT3 GetPoint1();
	NJS_POINT3 GetPoint2();

	float radius;
	NJS_POINT3 p1_offset;
	NJS_POINT3 p2_offset;

	CapsuleCollider() : Collider(), radius(0.0f), p1_offset({}), p2_offset({}) {}
	CapsuleCollider(CircleCollider _collider, NJS_POINT3 _castVector) : Collider(_collider.offset, _collider.node), radius(_collider.radius), p1_offset({}), p2_offset(_castVector) {}
	CapsuleCollider(float _radius, SpriteNode* _node, NJS_POINT3 _p1_offset, NJS_POINT3 _p2_offset) : Collider(_node), radius(_radius), p1_offset(_p1_offset), p2_offset(_p2_offset) {}

private:
	bool IsCollidingCapsule(CapsuleCollider& other);
};