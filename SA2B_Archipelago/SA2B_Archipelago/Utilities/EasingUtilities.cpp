#include "../pch.h"
#include "EasingUtilities.h"
#include <cmath>

float ApplyEasing(float x, EasingType type)
{
	switch (type)
	{
	case EasingType::ET_Linear:
		return x;
	case EasingType::ET_SineIn:
		return 1.0f - cos((x * NJD_PI) / 2.0f);
	case EasingType::ET_SineOut:
		return 1.0f - sin((x * NJD_PI) / 2.0f);
	case EasingType::ET_SineInOut:
		return -(cos(x * NJD_PI) - 1.0f) / 2.0f;
	case EasingType::ET_QuadIn:
		return x * x;
	case EasingType::ET_QuadOut:
		return 1.0f - (1.0f - x) * (1.0f - x);
	case EasingType::ET_QuadInOut:
		return x < 0.5f ? 2.0f * x * x : 1.0f - pow(-2.0f * x + 2.0f, 2.0f) / 2.0f;
	case EasingType::ET_CubicIn:
		return x * x * x;
	case EasingType::ET_CubicOut:
		return 1.0f - pow(1.0f - x, 3.0f);
	case EasingType::ET_CubicInOut:
		return x < 0.5f ? 4.0f * x * x * x : 1.0f - pow(-2.0f * x + 2.0f, 3.0f) / 2.0f;
	case EasingType::ET_ExpoIn:
		return x == 0.0f ? 0.0f : pow(2.0f, 10.0f * x - 10.0f);
	case EasingType::ET_ExpoOut:
		return x == 1.0f ? 1.0f : 1.0f - pow(2.0f, -10.0f * x);
	case EasingType::ET_ExpoInOut:
		return x == 0.0f
			? 0.0f
			: x == 1.0f
			? 1.0f
			: x < 0.5f ? pow(2.0f, 20.0f * x - 10.0f) / 2.0f
			: (2.0f - pow(2.0f, -20.0f * x + 10.0f)) / 2.0f;
	default:
		return x;
		break;
	}
}

float Lerp(float a, float b, float t)
{
	return (1.0f - t) * a + t * b;
}

float EaseInterpolate(float a, float b, float t, EasingType type)
{
	return Lerp(a, b, ApplyEasing(t, type));
}

NJS_POINT3 EaseInterpolate(NJS_POINT3 a, NJS_POINT3 b, float t, EasingType type)
{
	return {
		Lerp(a.x, b.x, ApplyEasing(t, type)),
		Lerp(a.y, b.y, ApplyEasing(t, type)),
		Lerp(a.z, b.z, ApplyEasing(t, type)),
	};
}

NJS_ARGB EaseInterpolate(NJS_ARGB a, NJS_ARGB b, float t, EasingType type)
{
	return {
		Lerp(a.a, b.a, ApplyEasing(t, type)),
		Lerp(a.r, b.r, ApplyEasing(t, type)),
		Lerp(a.g, b.g, ApplyEasing(t, type)),
		Lerp(a.b, b.b, ApplyEasing(t, type)),
	};
}