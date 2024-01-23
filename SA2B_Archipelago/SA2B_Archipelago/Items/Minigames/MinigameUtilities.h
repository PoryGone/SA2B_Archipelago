#pragma once
#include "MinigameBase.h"
#include "MinigameIconData.h"
#include "../../Utilities/SpriteUtilities.h"
#include "Backend/SpriteHierarchy.h"
#include <random>

void DrawDPad(RawInputFlags activeButtons, NJS_POINT3 position, float displaySize, MinigameIconData& iconData);

void AddDPadToHierarchy(RawInputFlags activeButtons, NJS_POINT3 position, float displaySize, MinigameIconData& iconData, SpriteHierarchy& hierarchy);

std::default_random_engine& RNG();

float RandomFloat(float min, float max);

int RandomInt(int minInc, int maxExcl);
