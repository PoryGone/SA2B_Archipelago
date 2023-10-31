#include "../pch.h"
#include "SpriteUtilities.h"
#include <cmath>

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

NJS_POINT3 Point3Scale(NJS_POINT3 a, float b)
{
	NJS_POINT3 v{ 0,0,0 };
	v.x = a.x * b;
	v.y = a.y * b;
	v.z = a.z * b;
	return v;
}

void Point3ScaleEQ(NJS_POINT3& a, float b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
}

float Point3Distance(NJS_POINT3 a, NJS_POINT3 b)
{
	return sqrt(pow(b.x - a.x, 2.0f) + pow(b.y - a.y, 2.0f) + pow(b.z - a.z, 2.0f));
}

NJS_POINT3 Point3RotateAround(NJS_POINT3 point, NJS_POINT3 center, float angleDeg)
{
	float angle = NJM_DEG_RAD(angleDeg);
	NJS_POINT3 v{ point.x, point.y, point.z };
	Point3SubtractEQ(v, center);
	float sAngle = sin(angle);
	float cAngle = cos(angle);
	float x = v.x * cAngle - v.y * sAngle;
	float y = v.x * sAngle + v.y * cAngle;
	v.x = x;
	v.y = y;
	Point3AddEQ(v, center);
	return v;
}

void Point3RotateAroundEQ(NJS_POINT3& point, NJS_POINT3 center, float angleDeg)
{
	float angle = NJM_DEG_RAD(angleDeg);
	NJS_POINT3 v{ point.x, point.y, point.z };
	Point3SubtractEQ(v, center);
	float sAngle = sin(angle);
	float cAngle = cos(angle);
	float x = v.x * cAngle - v.y * sAngle;
	float y = v.x * sAngle + v.y * cAngle;
	v.x = x;
	v.y = y;
	Point3AddEQ(v, center);
	point.x = v.x;
	point.y = v.y;
}

float Point3DotProduct(NJS_POINT3 a, NJS_POINT3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float Point3Magnitude(NJS_POINT3 a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

NJS_POINT3 Point3Normalize(NJS_POINT3 a)
{
	float mag = Point3Magnitude(a);
	if (mag > 0.0f)
	{
		return { a.x / mag, a.y / mag, a.z / mag };
	}
	return { 0.0f,0.0f,0.0f };
}

void Point3NormalizeEQ(NJS_POINT3& a)
{
	float mag = Point3Magnitude(a);
	if (mag > 0.0f)
	{
		a.x /= mag;
		a.y /= mag;
		a.z /= mag;
	}
}
