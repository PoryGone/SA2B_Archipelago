#pragma once
#include "../../../../Utilities/SpriteUtilities.h"
#include "../../../../Utilities/EasingUtilities.h"
#include "CapsuleCollider.h"
#include "PolygonCollider.h"
#include "CircleCollider.h"

struct LineSegment
{
public:
	NJS_POINT3 a;
	NJS_POINT3 b;

	LineSegment() : a({0.0f, 0.0f, 0.0f }), b({ 0.0f, 0.0f, 0.0f }) {}
	LineSegment(NJS_POINT3 _a, NJS_POINT3 _b) : a({ _a.x, _a.y, _a.z }), b({ _b.x, _b.y, _b.z }) {}
};

struct Circle
{
public:
	NJS_POINT3 center;
	float radius;

	Circle(NJS_POINT3 _center, float _radius) : center({ _center.x, _center.y, _center.z }), radius(_radius) {}
};

struct IntersectionResults
{
public:
	bool isIntersecting;
	NJS_POINT3 point;
	NJS_POINT3 surfaceNormal;

	IntersectionResults(bool _isIntersecting, NJS_POINT3 _point, NJS_POINT3 _surfaceNormal) : isIntersecting(_isIntersecting), point(_point), surfaceNormal(_surfaceNormal) {}
};

struct LineSegmentClosestPointResults
{
public:
	NJS_POINT3 point;
	float normT;
	float t;

	LineSegmentClosestPointResults(NJS_POINT3 _point, float _normT, float _t) : point(_point), normT(_normT), t(_t) {}
};

IntersectionResults TestCapsulePolygonIntersection(CapsuleCollider& aCol, PolygonCollider& bCol);
IntersectionResults TestCapsuleCircleIntersection(CapsuleCollider& aCol, CircleCollider& bCol);
IntersectionResults TestCapsuleCircleIntersection(CapsuleCollider& aCol, Circle bCol);
IntersectionResults TestCapsuleCapsuleIntersection(CapsuleCollider& aCol, CapsuleCollider& bCol);
IntersectionResults TestLineSegmentIntersection(LineSegment a, LineSegment b);
IntersectionResults TestLineSegmentIntersection(NJS_POINT3 a1, NJS_POINT3 a2, NJS_POINT3 b1, NJS_POINT3 b2);
LineSegmentClosestPointResults GetClosestPointOnSegmentToPoint(NJS_POINT3 a1, NJS_POINT3 a2, NJS_POINT3 p);