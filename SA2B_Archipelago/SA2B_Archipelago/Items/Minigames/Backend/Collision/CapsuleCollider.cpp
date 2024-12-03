#include "../../../../pch.h"
#include "CapsuleCollider.h"
#include "PolygonCollider.h"
#include "CollisionUtilities.h"
#include "../../../../Utilities/EasingUtilities.h"
#include "../../../../Utilities/SpriteUtilities.h"

bool CapsuleCollider::IsColliding(Collider& otherCollider)
{
	if (auto circle = dynamic_cast<CircleCollider*>(&otherCollider))
	{
		NJS_POINT3 center = circle->GetCenter();
		return Point3Distance(center, GetClosestPoint(center)) < circle->radius;
	}
	if (auto polygon = dynamic_cast<PolygonCollider*>(&otherCollider))
	{
		return IsCollidingPolygon(*polygon);
	}
	if (auto capsule = dynamic_cast<CapsuleCollider*>(&otherCollider))
	{
		return IsCollidingCapsule(*capsule);
	}
	return false;
}

BoundingBox CapsuleCollider::GetBoundingBox()
{
	NJS_POINT3 totalOffset = Point3Add(node == nullptr ? NJS_POINT3({}) : node->GetPositionGlobal(), offset);
	NJS_POINT3 p1 = Point3Add(totalOffset, p1_offset);
	NJS_POINT3 p2 = Point3Add(totalOffset, p2_offset);
	float d = radius * 2.0f;
	BoundingBox b1 = BoundingBox(p1, { d, d, 0.0f });
	BoundingBox b2 = BoundingBox(p2, { d, d, 0.0f });
	b1.Add(b2);
	return b1;
}

NJS_POINT3 CapsuleCollider::GetCenter()
{
	if (node)
	{
		NJS_POINT3 totalOffset = Point3Add(node->GetPositionGlobal(), offset);
		return Lerp(Point3Add(p1_offset, totalOffset), Point3Add(p2_offset, totalOffset), 0.5f);
	}
	else
	{
		return Lerp(Point3Add(p1_offset, offset), Point3Add(p2_offset, offset), 0.5f);
	}
}

NJS_POINT3 CapsuleCollider::GetClosestPoint(NJS_POINT3 point)
{
	NJS_POINT3 totalOffset = Point3Add(node == nullptr ? NJS_POINT3({}) : node->GetPositionGlobal(), offset);
	NJS_POINT3 p1 = Point3Add(totalOffset, p1_offset);
	NJS_POINT3 p2 = Point3Add(totalOffset, p2_offset);
	NJS_POINT3 toP2 = Point3Substract(p2, p1);
	NJS_POINT3 toPoint = Point3Substract(point, p1);
	float length = Point3DotProduct(toP2, toP2);
	if (length != 0.0f)
	{
		float t = Point3DotProduct(toP2, toPoint) / length;
		t = t < 0.0f ? 0.0f : t;
		t = t > 1.0f ? 1.0f : t;
		p1 = Lerp(p1, p2, t);
	}

	if (Point3Distance(point, p1) < radius)
	{
		return point;
	}
	toPoint = Point3Scale(Point3Normalize(Point3Substract(point, p1)), radius);
	return Point3Add(p1, toPoint);
}

NJS_POINT3 CapsuleCollider::GetPoint1()
{
	NJS_POINT3 aTotalOffset = Point3Add(node == nullptr ? NJS_POINT3({}) : node->GetPositionGlobal(), offset);
	return Point3Add(aTotalOffset, p1_offset);
}

NJS_POINT3 CapsuleCollider::GetPoint2()
{
	NJS_POINT3 aTotalOffset = Point3Add(node == nullptr ? NJS_POINT3({}) : node->GetPositionGlobal(), offset);
	return Point3Add(aTotalOffset, p2_offset);
}

bool CapsuleCollider::IsCollidingPolygon(PolygonCollider& other)
{
	bool colFound = false;
	NJS_POINT3 totalOffset = Point3Add(node == nullptr ? NJS_POINT3({}) : node->GetPositionGlobal(), offset);
	NJS_POINT3 p1 = Point3Add(totalOffset, p1_offset);
	NJS_POINT3 p2 = Point3Add(totalOffset, p2_offset);
	NJS_POINT3 capDir = Point3Normalize(Point3Substract(p2, p1));
	NJS_POINT3 p1Tip = Point3Add(p1, Point3Scale(capDir, -radius));
	NJS_POINT3 p2Tip = Point3Add(p2, Point3Scale(capDir, radius));

	NJS_POINT3 t0 = other.GetCentroid();
	auto points = other.GetAdjustedPoints();

	for (int i = 0; i < points.size() && !colFound; i++)
	{
		//Find best point along capsule
		int i2 = (i + 1 == points.size()) ? 0 : i + 1;
		NJS_POINT3 t1 = points[i];
		NJS_POINT3 t2 = points[i2];
		NJS_POINT3 tNorm = Point3Normalize(Point3CrossProduct(Point3Substract(t1, t0), Point3Substract(t2, t0)));
		float dot = abs(Point3DotProduct(tNorm, capDir));
		NJS_POINT3 triPlaneIntersection = {};
		if (dot == 0.0f)
		{
			triPlaneIntersection = t0;
		}
		else
		{
			float t = Point3DotProduct(tNorm, Point3Substract(t0, p1Tip)) / dot;
			triPlaneIntersection = Point3Add(p1Tip, Point3Scale(capDir, t));
		}
		NJS_POINT3 bestTriPoint = triPlaneIntersection;
		NJS_POINT3 c0 = Point3CrossProduct(Point3Substract(triPlaneIntersection, t0), Point3Substract(t1, t0));
		NJS_POINT3 c1 = Point3CrossProduct(Point3Substract(triPlaneIntersection, t1), Point3Substract(t2, t1));
		NJS_POINT3 c2 = Point3CrossProduct(Point3Substract(triPlaneIntersection, t2), Point3Substract(t0, t2));
		bool inTri = Point3DotProduct(c0, tNorm) <= 0.0f && Point3DotProduct(c1, tNorm) <= 0.0f && Point3DotProduct(c2, tNorm) <= 0.0f;
		if (!inTri)
		{
			NJS_POINT3 pointOnLine = GetClosestPointOnSegmentToPoint(t0, t1, triPlaneIntersection).point;
			NJS_POINT3 toPoint = Point3Substract(triPlaneIntersection, pointOnLine);
			float dist = Point3DotProduct(toPoint, toPoint);
			float bestFitDist = dist;
			bestTriPoint = pointOnLine;

			pointOnLine = GetClosestPointOnSegmentToPoint(t1, t2, triPlaneIntersection).point;
			toPoint = Point3Substract(triPlaneIntersection, pointOnLine);
			dist = Point3DotProduct(toPoint, toPoint);
			if (dist < bestFitDist)
			{
				bestFitDist = dist;
				bestTriPoint = pointOnLine;
			}

			pointOnLine = GetClosestPointOnSegmentToPoint(t2, t0, triPlaneIntersection).point;
			toPoint = Point3Substract(triPlaneIntersection, pointOnLine);
			dist = Point3DotProduct(toPoint, toPoint);
			if (dist < bestFitDist)
			{
				bestFitDist = dist;
				bestTriPoint = pointOnLine;
			}
		}
		//Check sphere collision around best point
		NJS_POINT3 center = GetClosestPointOnSegmentToPoint(p1, p2, bestTriPoint).point;
		//PrintDebug(Point3String(center).c_str());
		float centerDist = Point3DotProduct(Point3Substract(center, t0), tNorm);
		if (centerDist < -radius || centerDist > radius)
		{
			continue;
		}
		NJS_POINT3 triPlaneProjection = Point3Substract(center, Point3Scale(tNorm, centerDist));
		c0 = Point3CrossProduct(Point3Substract(triPlaneProjection, t0), Point3Substract(t1, t0));
		c1 = Point3CrossProduct(Point3Substract(triPlaneProjection, t1), Point3Substract(t2, t1));
		c2 = Point3CrossProduct(Point3Substract(triPlaneProjection, t2), Point3Substract(t0, t2));
		inTri = Point3DotProduct(c0, tNorm) <= 0.0f && Point3DotProduct(c1, tNorm) <= 0.0f && Point3DotProduct(c2, tNorm) <= 0.0f;
		if (inTri)
		{
			colFound = true;
			continue;
		}
		float radiusSq = radius * radius;
		NJS_POINT3 closest = GetClosestPointOnSegmentToPoint(t0, t1, triPlaneProjection).point;
		NJS_POINT3 toClosest = Point3Substract(triPlaneProjection, closest);
		float cDist = Point3DotProduct(toClosest, toClosest);
		if (cDist < radiusSq)
		{
			colFound = true;
			continue;
		}
		closest = GetClosestPointOnSegmentToPoint(t1, t2, triPlaneProjection).point;
		toClosest = Point3Substract(triPlaneProjection, closest);
		cDist = Point3DotProduct(toClosest, toClosest);
		if (cDist < radiusSq)
		{
			colFound = true;
			continue;
		}
		closest = GetClosestPointOnSegmentToPoint(t2, t0, triPlaneProjection).point;
		toClosest = Point3Substract(triPlaneProjection, closest);
		cDist = Point3DotProduct(toClosest, toClosest);
		if (cDist < radiusSq)
		{
			colFound = true;
		}
	}
	return colFound;
}

bool CapsuleCollider::IsCollidingCapsule(CapsuleCollider& other)
{
	NJS_POINT3 aTotalOffset = Point3Add(node == nullptr ? NJS_POINT3({}) : node->GetPositionGlobal(), offset);
	NJS_POINT3 aP1 = Point3Add(aTotalOffset, p1_offset);
	NJS_POINT3 aP2 = Point3Add(aTotalOffset, p2_offset);

	NJS_POINT3 bTotalOffset = Point3Add(other.node == nullptr ? NJS_POINT3({}) : other.node->GetPositionGlobal(), other.offset);
	NJS_POINT3 bP1 = Point3Add(bTotalOffset, other.p1_offset);
	NJS_POINT3 bP2 = Point3Add(bTotalOffset, other.p2_offset);

	NJS_POINT3 v0 = Point3Substract(bP1, aP1);
	NJS_POINT3 v1 = Point3Substract(bP2, aP1);
	NJS_POINT3 v2 = Point3Substract(bP1, aP2);
	NJS_POINT3 v3 = Point3Substract(bP2, aP2);

	float d0 = Point3DotProduct(v0, v0);
	float d1 = Point3DotProduct(v1, v1);
	float d2 = Point3DotProduct(v2, v2);
	float d3 = Point3DotProduct(v3, v3);

	NJS_POINT3 aCandidate = (d2 < d0 || d2 < d1 || d3 < d0 || d3 < d1) ? aP2 : aP1;
	NJS_POINT3 bCandidate = GetClosestPointOnSegmentToPoint(bP1, bP2, aCandidate).point;
	aCandidate = GetClosestPointOnSegmentToPoint(aP1, aP2, bCandidate).point;;
	return Point3Distance(aCandidate, bCandidate) < (radius + other.radius);
}