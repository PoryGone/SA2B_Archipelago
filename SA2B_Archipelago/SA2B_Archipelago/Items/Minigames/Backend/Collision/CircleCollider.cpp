#include "../../../../pch.h"
#include "CircleCollider.h"
#include "PolygonCollider.h"
#include "../../../../Utilities/SpriteUtilities.h"

bool CircleCollider::IsColliding(Collider& otherCollider)
{
	if (auto circle = dynamic_cast<CircleCollider*>(&otherCollider))
	{
		float distance = Point3Distance(GetCenter(), circle->GetCenter());
		return distance < (radius + circle->radius);
	}
	if (auto polygon = dynamic_cast<PolygonCollider*>(&otherCollider))
	{
		return polygon->ContainsPoint(GetClosestPoint(polygon->GetCentroid()));
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
		return Point3Add(nodePos, Point3RotateAround(offset, nodePos, node->GetRotationGlobal()));
	}
	return offset;
}

NJS_POINT3 CircleCollider::GetClosestPoint(NJS_POINT3 point)
{
	auto center = GetCenter();
	if (Point3Distance(point, center) < radius)
	{
		return point;
	}
	NJS_POINT3 toPoint = Point3Scale(Point3Normalize(Point3Substract(point, center)),radius);
	return Point3Add(center, toPoint);
}
