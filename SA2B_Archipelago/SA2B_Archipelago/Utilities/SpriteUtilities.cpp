#include "../pch.h"
#include "SpriteUtilities.h"

__declspec(noinline) void DrawSprite2D(NJS_SPRITE* _sp, Int n, Float pri, char attr)
{
	njDrawSprite2D(_sp, n, pri, attr);
}