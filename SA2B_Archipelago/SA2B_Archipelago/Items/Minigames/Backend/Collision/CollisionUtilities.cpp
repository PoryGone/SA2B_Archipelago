#include "../../../../pch.h"
#include "CollisionUtilities.h"
#include <tuple>

std::tuple<LineSegment, LineSegment> GetCapsuleSegments(CapsuleCollider& col)
{
	NJS_POINT3 aColPoint1 = col.GetPoint1();
	NJS_POINT3 aColPoint2 = col.GetPoint2();
	NJS_POINT3 aColForward = Point3Normalize(Point3Substract(aColPoint2, aColPoint1));
	NJS_POINT3 aColRight = Point3RotateAround(aColForward, { 0.0f, 0.0f }, 90.0f);
	NJS_POINT3 aColLeft = Point3Scale(aColRight, -1.0f);
	//NJS_POINT3 p1 = Point3Add(aColPoint1, Point3Scale(aColForward, -col.radius));
	//NJS_POINT3 p2 = Point3Add(aColPoint2, Point3Scale(aColForward, col.radius));
	//LineSegment aColCenter = LineSegment(p1, p2);
	NJS_POINT3 p1 = Point3Add(aColPoint1, Point3Scale(aColRight, col.radius));
	NJS_POINT3 p2 = Point3Add(aColPoint2, Point3Scale(aColRight, col.radius));
	LineSegment aColSide1 = LineSegment(p1, p2);
	p1 = Point3Add(aColPoint1, Point3Scale(aColLeft, col.radius));
	p2 = Point3Add(aColPoint2, Point3Scale(aColLeft, col.radius));
	LineSegment aColSide2 = LineSegment(p1, p2);
	return std::make_tuple(aColSide1, aColSide2);
}

std::tuple<int, NJS_POINT3, NJS_POINT3> GetIntersectionsOfLineSegAndCircle(LineSegment seg, NJS_POINT3 center, float radius)
{
	int intersections = -1;
	NJS_POINT3 intersection1 = {};
	NJS_POINT3 intersection2 = {};

	NJS_POINT3 segVector = Point3Substract(seg.b, seg.a);
	NJS_POINT3 p1Vector = Point3Substract(seg.a, center);
	float a = Point3SqrMagnitude(segVector);
	float b = 2.0f * (segVector.x * p1Vector.x + segVector.y * p1Vector.y);
	float c = Point3SqrMagnitude(p1Vector) - radius * radius;
	float t1 = 0.0f;
	float t2 = 0.0f;
	float det = b * b - 4 * a * c;

	if (a < 0.00000001f || det < 0.0f)
	{
		intersections = 0;
	}
	else if (det == 0.0f)
	{
		t1 = -b / (2 * a);
		if (t1 >= 0.0f && t1 <= 1.0f)
		{
			intersections = 1;
			intersection1 = { seg.a.x + t1 * segVector.x, seg.a.y + t1 * segVector.y };
		} 
	}
	else
	{
		t1 = (-b + sqrt(det)) / (2 * a);
		t2 = (-b - sqrt(det)) / (2 * a);
		bool valid1 = t1 >= 0.0f && t1 <= 1.0f;
		bool valid2 = t2 >= 0.0f && t2 <= 1.0f;
		if (valid1 && valid2)
		{
			intersections = 2;
			intersection1 = { seg.a.x + t1 * segVector.x, seg.a.y + t1 * segVector.y };
			intersection2 = { seg.a.x + t2 * segVector.x, seg.a.y + t2 * segVector.y };
		}
		else if (valid1 || valid2)
		{
			t1 = valid1 ? t1 : t2;
			intersections = 1;
			intersection1 = { seg.a.x + t1 * segVector.x, seg.a.y + t1 * segVector.y };
		}
	}

	return std::make_tuple(intersections, intersection1, intersection2);
}

NJS_POINT3 GetNormalDirectionOfPointFromSeg(LineSegment seg, NJS_POINT3 pt)
{
	float d = (pt.x - seg.a.x) * (seg.b.y - seg.a.y) - (pt.y - seg.a.y) * (seg.b.x - seg.a.x);
	NJS_POINT3 n = Point3Normalize({ seg.b.y - seg.a.y, -(seg.b.x - seg.a.x) });
	if (d < 0.0f)
	{
		n = Point3Scale(n, -1.0f);
	}
	return n;
}

float NonSquaredDistance(NJS_POINT3 a, NJS_POINT3 b)
{
	return pow(b.x - a.x, 2.0f) + pow(b.y - a.y, 2.0f);
}

IntersectionResults TestCapsulePolygonIntersection(CapsuleCollider& aCol, PolygonCollider& bCol)
{
	IntersectionResults currentResults = IntersectionResults(false, {}, {});
	float currentDist = 1000000.0f;
	NJS_POINT3 aColStart = aCol.GetPoint1();
	NJS_POINT3 aColEnd = aCol.GetPoint2();
	float aRadius = aCol.radius;
	auto capLines = GetCapsuleSegments(aCol);
	auto bColPoints = bCol.GetAdjustedPoints();

	for (int i = 0; i < bColPoints.size(); i++)
	{
		int i2 = (i + 1 == bColPoints.size()) ? 0 : i + 1;
		LineSegment seg = LineSegment(bColPoints[i], bColPoints[i2]);
		IntersectionResults results = TestLineSegmentIntersection(std::get<0>(capLines), seg);
		if (results.isIntersecting)
		{
			float dist = NonSquaredDistance(aColStart, results.point);
			if (dist < currentDist || !currentResults.isIntersecting)
			{
				currentResults = results;
				currentDist = dist;
			}
		}
		results = TestLineSegmentIntersection(std::get<1>(capLines), seg);
		if (results.isIntersecting)
		{
			float dist = NonSquaredDistance(aColStart, results.point);
			if (dist < currentDist || !currentResults.isIntersecting)
			{
				currentResults = results;
				currentDist = dist;
			}
		}
		auto intersections = GetIntersectionsOfLineSegAndCircle(seg, aColEnd, aRadius);
		if (std::get<0>(intersections) > 0)
		{
			NJS_POINT3 intersection = std::get<1>(intersections);
			float dist = NonSquaredDistance(aColStart, intersection);
			if (dist < currentDist || !currentResults.isIntersecting)
			{
				currentResults = IntersectionResults(true, intersection, Point3Scale(Point3Normalize(Point3Substract(intersection, aColEnd)), -1.0f));
				currentDist = dist;
			}
		}
		if (std::get<0>(intersections) > 1)
		{
			NJS_POINT3 intersection = Lerp(std::get<1>(intersections), std::get<2>(intersections), 0.5f);
			float dist = NonSquaredDistance(aColStart, intersection);
			if (dist < currentDist || !currentResults.isIntersecting)
			{
				NJS_POINT3 n = GetNormalDirectionOfPointFromSeg(seg, aColStart);
				currentResults = IntersectionResults(true, intersection, n);
				currentDist = dist;
			}
		}
	}
	return currentResults;
}

IntersectionResults TestCapsuleCircleIntersection(CapsuleCollider& aCol, CircleCollider& bCol)
{
	return TestCapsuleCircleIntersection(aCol, { bCol.GetCenter(), bCol.radius });
}

IntersectionResults TestCapsuleCircleIntersection(CapsuleCollider& aCol, Circle bCol)
{
	IntersectionResults currentResults = IntersectionResults(false, {}, {});
	float currentDist = 1000000.0f;
	NJS_POINT3 aColStart = aCol.GetPoint1();
	NJS_POINT3 aColEnd = aCol.GetPoint2();
	float aRadius = aCol.radius;
	auto capLines = GetCapsuleSegments(aCol);
	NJS_POINT3 bCenter = bCol.center;
	float bRadius = bCol.radius;

	auto intersections = GetIntersectionsOfLineSegAndCircle(std::get<0>(capLines), bCenter, bRadius);
	if (std::get<0>(intersections) > 0)
	{
		NJS_POINT3 intersection = std::get<1>(intersections);
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = IntersectionResults(true, intersection, Point3Normalize(Point3Substract(intersection, bCenter)));
			currentDist = dist;
		}
	}
	if (std::get<0>(intersections) > 1)
	{
		NJS_POINT3 intersection = std::get<2>(intersections);
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = IntersectionResults(true, intersection, Point3Normalize(Point3Substract(intersection, bCenter)));
			currentDist = dist;
		}
	}
	intersections = GetIntersectionsOfLineSegAndCircle(std::get<1>(capLines), bCenter, bRadius);
	if (std::get<0>(intersections) > 0)
	{
		NJS_POINT3 intersection = std::get<1>(intersections);
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = IntersectionResults(true, intersection, Point3Normalize(Point3Substract(intersection, bCenter)));
			currentDist = dist;
		}
	}
	if (std::get<0>(intersections) > 1)
	{
		NJS_POINT3 intersection = std::get<2>(intersections);
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = IntersectionResults(true, intersection, Point3Normalize(Point3Substract(intersection, bCenter)));
			currentDist = dist;
		}
	}
	if (Point3Distance(aColStart, bCenter) < (aRadius + bRadius))
	{
		NJS_POINT3 intersection = Point3Normalize(Point3Substract(aColStart, bCenter));
		NJS_POINT3 n = intersection;
		intersection = Point3Add(bCenter, Point3Scale(intersection, bRadius));
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = IntersectionResults(true, intersection, n);
			currentDist = dist;
		}
	}
	if (Point3Distance(aColEnd, bCenter) < (aRadius + bRadius))
	{
		NJS_POINT3 intersection = Point3Normalize(Point3Substract(aColEnd, bCenter));
		NJS_POINT3 n = intersection;
		intersection = Point3Add(bCenter, Point3Scale(intersection, bRadius));
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = IntersectionResults(true, intersection, n);
			currentDist = dist;
		}
	}

	return currentResults;
}


IntersectionResults TestCapsuleCapsuleIntersection(CapsuleCollider& aCol, CapsuleCollider& bCol)
{
	IntersectionResults currentResults = IntersectionResults(false, {}, {});
	float currentDist = 1000000.0f;
	NJS_POINT3 aColStart = aCol.GetPoint1();
	NJS_POINT3 aColEnd = aCol.GetPoint2();
	NJS_POINT3 bColStart = bCol.GetPoint1();
	NJS_POINT3 bColEnd = bCol.GetPoint2();
	float aRadius = aCol.radius;
	float bRadius = bCol.radius;
	auto aCapLines = GetCapsuleSegments(aCol);
	auto bCapLines = GetCapsuleSegments(bCol);
	IntersectionResults results = TestLineSegmentIntersection(std::get<0>(aCapLines), std::get<0>(bCapLines));
	if (results.isIntersecting)
	{
		float dist = NonSquaredDistance(aColStart, results.point);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = results;
			currentDist = dist;
		}
	}
	results = TestLineSegmentIntersection(std::get<0>(aCapLines), std::get<1>(bCapLines));
	if (results.isIntersecting)
	{
		float dist = NonSquaredDistance(aColStart, results.point);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = results;
			currentDist = dist;
		}
	}
	results = TestLineSegmentIntersection(std::get<1>(aCapLines), std::get<0>(bCapLines));
	if (results.isIntersecting)
	{
		float dist = NonSquaredDistance(aColStart, results.point);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = results;
			currentDist = dist;
		}
	}
	results = TestLineSegmentIntersection(std::get<1>(aCapLines), std::get<1>(bCapLines));
	if (results.isIntersecting)
	{
		float dist = NonSquaredDistance(aColStart, results.point);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = results;
			currentDist = dist;
		}
	}
	auto intersections = GetIntersectionsOfLineSegAndCircle(std::get<0>(bCapLines), aColEnd, aRadius);
	if (std::get<0>(intersections) > 0)
	{
		NJS_POINT3 intersection = std::get<1>(intersections);
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = IntersectionResults(true, intersection, Point3Scale(Point3Normalize(Point3Substract(intersection, aColEnd)), -1.0f));
			currentDist = dist;
		}
	}
	if (std::get<0>(intersections) > 1)
	{
		NJS_POINT3 intersection = Lerp(std::get<1>(intersections), std::get<2>(intersections), 0.5f);
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			NJS_POINT3 n = GetNormalDirectionOfPointFromSeg(std::get<0>(bCapLines), aColStart);
			currentResults = IntersectionResults(true, intersection, n);
			currentDist = dist;
		}
	}
	intersections = GetIntersectionsOfLineSegAndCircle(std::get<1>(bCapLines), aColEnd, aRadius);
	if (std::get<0>(intersections) > 0)
	{
		NJS_POINT3 intersection = std::get<1>(intersections);
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = IntersectionResults(true, intersection, Point3Scale(Point3Normalize(Point3Substract(intersection, aColEnd)), -1.0f));
			currentDist = dist;
		}
	}
	if (std::get<0>(intersections) > 1)
	{
		NJS_POINT3 intersection = Lerp(std::get<1>(intersections), std::get<2>(intersections), 0.5f);
		float dist = NonSquaredDistance(aColStart, intersection);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			NJS_POINT3 n = GetNormalDirectionOfPointFromSeg(std::get<1>(bCapLines), aColStart);
			currentResults = IntersectionResults(true, intersection, n);
			currentDist = dist;
		}
	}
	results = TestCapsuleCircleIntersection(aCol, { bColStart, bRadius });
	if (results.isIntersecting)
	{
		float dist = NonSquaredDistance(aColStart, results.point);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = results;
			currentDist = dist;
		}
	}
	results = TestCapsuleCircleIntersection(aCol, { bColEnd, bRadius });
	if (results.isIntersecting)
	{
		float dist = NonSquaredDistance(aColStart, results.point);
		if (dist < currentDist || !currentResults.isIntersecting)
		{
			currentResults = results;
			currentDist = dist;
		}
	}
	return currentResults;
}

IntersectionResults TestLineSegmentIntersection(LineSegment a, LineSegment b)
{ 
	return TestLineSegmentIntersection(a.a, a.b, b.a, b.b);
}

IntersectionResults TestLineSegmentIntersection(NJS_POINT3 a1, NJS_POINT3 a2, NJS_POINT3 b1, NJS_POINT3 b2)
{
	float cA1 = a1.y - a2.y;
	float cB1 = a2.x - a1.x;
	float cC1 = -(a1.x * a2.y - a2.x * a1.y);
	float cA2 = b1.y - b2.y;
	float cB2 = b2.x - b1.x;
	float cC2 = -(b1.x * b2.y - b2.x * b1.y);
	float det = cA1 * cB2 - cB1 * cA2;
	float detX = cC1 * cB2 - cB1 * cC2;
	float detY = cA1 * cC2 - cC1 * cA2;

	if (det != 0.0)
	{
		float x = detX / det;
		float y = detY / det;
		auto results1 = GetClosestPointOnSegmentToPoint(a1, a2, { x, y });
		auto results2 = GetClosestPointOnSegmentToPoint(b1, b2, { x, y });
		if (results1.t >= 0.0f && results1.t <= 1.0f && results2.t >= 0.0f && results2.t <= 1.0f)
		{
			NJS_POINT3 n = GetNormalDirectionOfPointFromSeg({ b1, b2 }, a1);
			return IntersectionResults(true, { x, y }, n);
		}
	}

	return IntersectionResults(false, {}, {});
}

LineSegmentClosestPointResults GetClosestPointOnSegmentToPoint(NJS_POINT3 a1, NJS_POINT3 a2, NJS_POINT3 p)
{
	NJS_POINT3 toP2 = Point3Substract(a2, a1);
	NJS_POINT3 toPoint = Point3Substract(p, a1);
	float length = Point3DotProduct(toP2, toP2);
	if (length != 0.0f)
	{
		float t = Point3DotProduct(toP2, toPoint) / length;
		float nT = t;
		nT = nT < 0.0f ? 0.0f : nT;
		nT = nT > 1.0f ? 1.0f : nT;
		return LineSegmentClosestPointResults(Lerp(a1, a2, nT), nT, t);
	}
	return LineSegmentClosestPointResults(a1, 0.0f, 0.0f);
}