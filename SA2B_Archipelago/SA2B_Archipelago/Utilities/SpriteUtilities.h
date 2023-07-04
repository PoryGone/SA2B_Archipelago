#pragma once

__declspec(noinline) void DrawSprite2D(NJS_SPRITE* _sp, Int n = 1, Float pri = 1, char attr = NJD_SPRITE_ALPHA);

NJS_POINT3 Point3Add(NJS_POINT3 a, NJS_POINT3 b);
void Point3AddEQ(NJS_POINT3& a, NJS_POINT3 b);

NJS_POINT3 Point3Substract(NJS_POINT3 a, NJS_POINT3 b);
void Point3SubtractEQ(NJS_POINT3& a, NJS_POINT3 b);

NJS_POINT3 Point3Multiply(NJS_POINT3 a, float b);
void Point3MultiplyEQ(NJS_POINT3& a, float b);
