#pragma once
#include "MinigameBase.h"
#include "MinigameIconData.h"
#include "../../Utilities/SpriteUtilities.h"
#include "Backend/SpriteHierarchy.h"

void DrawDPad(RawInputFlags activeButtons, NJS_POINT3 position, float displaySize, MinigameIconData& iconData);

void AddDPadToHierarchy(RawInputFlags activeButtons, NJS_POINT3 position, float displaySize, MinigameIconData& iconData, SpriteHierarchy& hierarchy);
