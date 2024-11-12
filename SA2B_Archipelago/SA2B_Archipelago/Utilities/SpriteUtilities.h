#pragma once
#include <string>

__declspec(noinline) void DrawSprite2D(NJS_SPRITE* _sp, Int n = 1, Float pri = 1, char attr = NJD_SPRITE_ALPHA);

NJS_POINT3 Point3Add(NJS_POINT3 a, NJS_POINT3 b);
void Point3AddEQ(NJS_POINT3& a, NJS_POINT3 b);

NJS_POINT3 Point3Substract(NJS_POINT3 a, NJS_POINT3 b);
void Point3SubtractEQ(NJS_POINT3& a, NJS_POINT3 b);

NJS_POINT3 Point3Scale(NJS_POINT3 a, float b);
void Point3ScaleEQ(NJS_POINT3& a, float b);

float Point3Distance(NJS_POINT3 a, NJS_POINT3 b);

NJS_POINT3 Point3RotateAround(NJS_POINT3 point, NJS_POINT3 center, float angleDeg);
void Point3RotateAroundEQ(NJS_POINT3& point, NJS_POINT3 center, float angleDeg);

NJS_POINT3 Point3MoveTowards(NJS_POINT3 a, NJS_POINT3 b, float delta);

bool Point3Approximatly(NJS_POINT3 a, NJS_POINT3 b);

float Point3DotProduct(NJS_POINT3 a, NJS_POINT3 b);

float Point3Magnitude(NJS_POINT3 a);
float Point3SqrMagnitude(NJS_POINT3 a);

NJS_POINT3 Point3Normalize(NJS_POINT3 a);
void Point3NormalizeEQ(NJS_POINT3& a);

float Point3AngleDegrees(NJS_POINT3 a, NJS_POINT3 b);
float Point3SignedAngleDegrees(NJS_POINT3 a, NJS_POINT3 b);
float Point3AngleRadians(NJS_POINT3 a, NJS_POINT3 b);

std::string Point3String(NJS_POINT3 a);
