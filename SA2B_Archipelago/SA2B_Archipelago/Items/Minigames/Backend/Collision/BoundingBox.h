#pragma once
#include <string>

struct BoundingBox
{
public:
	NJS_POINT3 center;
	NJS_POINT3 size;

	bool IsOverlapping(BoundingBox& other);
	bool IsOverlapping(NJS_POINT3 point);
	void Add(BoundingBox& other);
	void Add(NJS_POINT3 point);
	bool IsEqual(BoundingBox& other);
	float Left();
	float Right();
	float Top();
	float Bottom();
	std::string ToDebugString();

	BoundingBox() : center({ 0.0f, 0.0f, 0.0f}), size({ 0.0f, 0.0f, 0.0f }) {}
	BoundingBox(NJS_POINT3 _center, NJS_POINT3 _size) : center(_center), size(_size) {}

private:
	float Min(float f1, float f2);
	float Max(float f1, float f2);
};
