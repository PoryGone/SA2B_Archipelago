#include "../../../../pch.h"
#include "PolygonCollider.h"

bool PolygonCollider::IsColliding(Collider& otherCollider)
{
	if (auto polygon = dynamic_cast<PolygonCollider*>(&otherCollider))
	{
		return IsCollidingPolygon(*polygon);
	}
	return false;
}

BoundingBox PolygonCollider::GetBoundingBox()
{
	BoundingBox box = BoundingBox(GetCentroid(), { 0.0f,0.0f,0.0f });
	for (int i = 1; i < points.size(); i++)
	{
		box.Add(points[i]);
	}
	return box;
}

NJS_POINT3 PolygonCollider::GetCentroid()
{
	if (points.size() == 1)
	{
		NJS_POINT3 center = Point3Add(offset, points[0]);
		if (node)
		{
			NJS_POINT3 nodePos = node->GetPositionGlobal();
			return Point3Add(nodePos, Point3RotateAround(center, nodePos, node->rotation));
		}
		return center;
	}
	else if (points.size() > 1)
	{
		GetAdjustedPoints();
		NJS_POINT3 centroid = { 0.0f,0.0f,0.0f };
		float area = 0.0f;
		NJS_POINT3 current;
		NJS_POINT3 next;
		float segArea;
		for (int i = 0; i < adjustedPoints.size(); i++)
		{
			int i2 = i + 1;
			current = adjustedPoints[i];
			next = adjustedPoints[i2 == adjustedPoints.size() ? 0 : i2];
			segArea = (current.x * next.y) - (next.x * current.y);
			area += segArea;
			centroid.x += (current.x + next.x) * segArea;
			centroid.y += (current.y + next.y) * segArea;
		}
		area *= 0.5f;
		area *= 6.0f;
		if (area != 0.0f)
		{
			centroid.x /= area;
			centroid.y /= area;
		}
		return centroid;
	}
	return offset;
}

std::vector<NJS_POINT3> PolygonCollider::GetAdjustedPoints()
{
	if (adjustedPoints.size() != points.size())
	{
		adjustedPoints.clear();
		for (int i = 0; i < points.size(); i++)
		{
			adjustedPoints.push_back({ points[i].x,points[i].y,points[i].z });
		}
	}
	if (node)
	{
		NJS_POINT3 nodePos = node->GetPositionGlobal();
		for (int i = 0; i < adjustedPoints.size(); i++)
		{
			adjustedPoints[i] = Point3Add(points[i], offset);
			adjustedPoints[i] = Point3Add(nodePos, Point3RotateAround(adjustedPoints[i], nodePos, node->rotation));
		}
	}
	else
	{
		for (int i = 0; i < adjustedPoints.size(); i++)
		{
			adjustedPoints[i] = Point3Add(points[i], offset);
		}
	}
	return adjustedPoints;
}

bool PolygonCollider::IsCollidingPolygon(PolygonCollider& other)
{
	return !HasSeparatingLine(*this, other) && !HasSeparatingLine(other, *this);
}

bool PolygonCollider::HasSeparatingLine(PolygonCollider& a, PolygonCollider& b)
{
	auto aPts = a.GetAdjustedPoints();
	auto bPts = b.GetAdjustedPoints();
	for (int i = 0; i < aPts.size(); i++)
	{
		int i2 = i + 1;
		NJS_POINT3 p1 = aPts[i];
		NJS_POINT3 p2 = aPts[i2 == aPts.size() ? 0 : i2];
		NJS_POINT3 normal = { p2.y - p1.y, p1.x - p2.x, 0.0f };
		float minA = 0.0f;
		float maxA = 0.0f;
		float minB = 0.0f;
		float maxB = 0.0f;

		for (int iA = 0; iA < aPts.size(); iA++)
		{
			NJS_POINT3 pA = aPts[iA];
			float projection = Point3DotProduct(pA, normal);
			if (iA == 0)
			{
				minA = projection;
				maxA = projection;
			}
			else
			{
				minA = projection < minA ? projection : minA;
				maxA = projection > maxA ? projection : maxA;
			}
		}

		for (int iB = 0; iB < bPts.size(); iB++)
		{
			NJS_POINT3 pB = bPts[iB];
			float projection = Point3DotProduct(pB, normal);
			if (iB == 0)
			{
				minB = projection;
				maxB = projection;
			}
			else
			{
				minB = projection < minB ? projection : minB;
				maxB = projection > maxB ? projection : maxB;
			}
		}

		if (maxA < minB || maxB < minA)
		{
			return true;
		}
	}
	return false;
}