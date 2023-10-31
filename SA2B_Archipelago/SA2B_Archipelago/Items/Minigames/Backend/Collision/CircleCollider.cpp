#include "../../../../pch.h"
#include "CircleCollider.h"
#include "../../../../Utilities/SpriteUtilities.h"

bool CircleCollider::IsColliding(Collider& otherCollider)
{
	if (auto circle = dynamic_cast<CircleCollider*>(&otherCollider))
	{
		float distance = Point3Distance(GetCenter(), circle->GetCenter());
		return distance < (radius + circle->radius);
	}
	return false;
}

BoundingBox CircleCollider::GetBoundingBox()
{
	float d = radius * 2.0f;
	return BoundingBox(GetCenter(), { d, d, 0.0f });
}

NJS_POINT3 CircleCollider::GetCenter()
{
	if (node)
	{
		NJS_POINT3 nodePos = node->GetPositionGlobal();
		return Point3Add(nodePos, Point3RotateAround(offset, nodePos, node->rotation));
	}
	return offset;
}