#pragma once
#include "CollisionManager.h"
#include "../../../../Utilities/SpriteUtilities.h"
#include <vector>

class PolygonCollider : public Collider
{
public:
	bool IsColliding(Collider& otherCollider) override;
	BoundingBox GetBoundingBox() override;

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
			if (_rotation > 0.0f)
			{
				PrintDebug(std::to_string(points[i].x).c_str());
				PrintDebug(std::to_string(points[i].y).c_str());
			}
		}
	}

private:
	bool IsCollidingPolygon(PolygonCollider& other);
	bool HasSeparatingLine(PolygonCollider& a, PolygonCollider& b);

	std::vector<NJS_POINT3> adjustedPoints;
};
