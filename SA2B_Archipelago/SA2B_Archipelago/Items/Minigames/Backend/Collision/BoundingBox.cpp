#include "../../../../pch.h"
#include "BoundingBox.h"

bool BoundingBox::IsOverlapping(BoundingBox& other)
{
	return this->Left() < other.Right() &&
		this->Right() > other.Left() &&
		this->Bottom() < other.Top() &&
		this->Top() > other.Bottom();
}

bool BoundingBox::IsOverlapping(NJS_POINT3 point)
{
	return point.x < this->Right() &&
		point.x > this->Left() &&
		point.y < this->Top() &&
		point.y > this->Bottom();
}

void BoundingBox::Add(BoundingBox& other)
{
	float left = Min(this->Left(), other.Left());
	float right = Max(this->Right(), other.Right());
	float top = Max(this->Top(), other.Top());
	float bottom = Min(this->Bottom(), other.Bottom());
	float xSize = right - left;
	float x = left + (xSize * 0.5f);
	float ySize = top - bottom;
	float y = bottom + (ySize * 0.5f);
	this->center = { x, y, 0.0f };
	this->size = { xSize, ySize, 0.0f };
}

void BoundingBox::Add(NJS_POINT3 point)
{
	float left = Min(this->Left(), point.x);
	float right = Max(this->Right(), point.x);
	float top = Max(this->Top(), point.y);
	float bottom = Min(this->Bottom(), point.y);
	float xSize = right - left;
	float x = left + (xSize * 0.5f);
	float ySize = top - bottom;
	float y = bottom + (ySize * 0.5f);
	this->center = { x, y, 0.0f };
	this->size = { xSize, ySize, 0.0f };
}

bool BoundingBox::IsEqual(BoundingBox& other)
{
	return Left() == other.Left() &&
		Right() == other.Right() &&
		Top() == other.Top() &&
		Bottom() == other.Bottom();
}

float BoundingBox::Left()
{
	return this->center.x - (this->size.x * 0.5f);
}

float BoundingBox::Right()
{
	return this->center.x + (this->size.x * 0.5f);
}

float BoundingBox::Top()
{
	return this->center.y + (this->size.y * 0.5f);
}

float BoundingBox::Bottom()
{
	return this->center.y - (this->size.y * 0.5f);
}

float BoundingBox::Min(float f1, float f2)
{
	return f1 < f2 ? f1 : f2;
}

float BoundingBox::Max(float f1, float f2)
{
	return f1 > f2 ? f1 : f2;
}