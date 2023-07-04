#include "../pch.h"
#include "SpriteUtilities.h"

__declspec(noinline) void DrawSprite2D(NJS_SPRITE* _sp, Int n, Float pri, char attr)
{
	njDrawSprite2D(_sp, n, pri, attr);
}

NJS_POINT3 Point3Add(NJS_POINT3 a, NJS_POINT3 b)
{
	NJS_POINT3 v{0,0,0};
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return v;
}

void Point3AddEQ(NJS_POINT3& a, NJS_POINT3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
}

NJS_POINT3 Point3Substract(NJS_POINT3 a, NJS_POINT3 b)
{
	NJS_POINT3 v{ 0,0,0 };
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return v;
}

void Point3SubtractEQ(NJS_POINT3& a, NJS_POINT3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
}

NJS_POINT3 Point3Multiply(NJS_POINT3 a, float b)
{
	NJS_POINT3 v{ 0,0,0 };
	v.x = a.x * b;
	v.y = a.y * b;
	v.z = a.z * b;
	return v;
}

void Point3MultiplyEQ(NJS_POINT3& a, float b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
}