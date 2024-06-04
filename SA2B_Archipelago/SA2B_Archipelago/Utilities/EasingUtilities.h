#pragma once

enum EasingType
{
	ET_Linear,
	ET_SineIn,
	ET_SineOut,
	ET_SineInOut,
	ET_QuadIn,
	ET_QuadOut,
	ET_QuadInOut,
	ET_CubicIn,
	ET_CubicOut,
	ET_CubicInOut,
	ET_ExpoIn,
	ET_ExpoOut,
	ET_ExpoInOut,
};

float ApplyEasing(float x, EasingType type);
float Lerp(float a, float b, float t);

float EaseInterpolate(float a, float b, float t, EasingType type);
NJS_POINT3 EaseInterpolate(NJS_POINT3 a, NJS_POINT3 b, float t, EasingType type);
NJS_ARGB EaseInterpolate(NJS_ARGB a, NJS_ARGB b, float t, EasingType type);