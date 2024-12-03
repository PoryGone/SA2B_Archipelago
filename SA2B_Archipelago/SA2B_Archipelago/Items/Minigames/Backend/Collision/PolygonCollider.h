#pragma once
#include "Collider.h"
#include "../../../../Utilities/SpriteUtilities.h"
#include <vector>

/// <summary>
/// Any number of points that define a convex shape.
/// MUST be convex to properly detect collisions.
/// </summary>
class PolygonCollider : public Collider
{
public:
	bool IsColliding(Collider& otherCollider) override;
	BoundingBox GetBoundingBox() override;

	bool ContainsPoint(NJS_POINT3 point);
	NJS_POINT3 GetCentroid();
	std::vector<NJS_POINT3> GetAdjustedPoints();

	std::vector<NJS_POINT3> points;

	PolygonCollider() : Collider(), points({ { 0.0f, 0.0f, 0.0f } }) {}
	PolygonCollider(std::vector<NJS_POINT3> _points) : Collider(), points(_points) {}
	PolygonCollider(NJS_POINT3 _size) : Collider(), points({ {-_size.x * 0.5f, _size.y * 0.5f, 0.0f}, {_size.x * 0.5f, _size.y * 0.5f, 0.0f}, {_size.x * 0.5f, -_size.y * 0.5f, 0.0f}, {-_size.x * 0.5f, -_size.y * 0.5f, 0.0f} }) {}
	PolygonCollider(NJS_POINT3 _size, float _rotation) : Collider(), points({ {-_size.x * 0.5f, _size.y * 0.5f, 0.0f}, {_size.x * 0.5f, _size.y * 0.5f, 0.0f}, {_size.x * 0.5f, -_size.y * 0.5f, 0.0f}, {-_size.x * 0.5f, -_size.y * 0.5f, 0.0f} }) 
	{
		for (int i = 0; i < points.size(); i++)
		{
			points[i] = Point3RotateAround(points[i], { 0.0f, 0.0f, 0.0f }, _rotation);
		}
	}
	PolygonCollider(NJS_POINT3 _size, float _rotation, NJS_POINT3 _offset) : Collider(_offset), points({ {-_size.x * 0.5f, _size.y * 0.5f, 0.0f}, {_size.x * 0.5f, _size.y * 0.5f, 0.0f}, {_size.x * 0.5f, -_size.y * 0.5f, 0.0f}, {-_size.x * 0.5f, -_size.y * 0.5f, 0.0f} })
	{
		for (int i = 0; i < points.size(); i++)
		{
			points[i] = Point3RotateAround(points[i], { 0.0f, 0.0f, 0.0f }, _rotation);
		}
	}

private:
	bool IsCollidingPolygon(PolygonCollider& other);
	bool HasSeparatingLine(PolygonCollider& a, PolygonCollider& b);

	std::vector<NJS_POINT3> adjustedPoints;
};
