#pragma once

enum MinigameIcon
{
	MGI_RoundedBar				= 0,
	MGI_RoundedBar_Top			= 1,
	MGI_RoundedBar_Bottom		= 2,
	MGI_RoundedBar_Mid			= 3,
	MGI_RoundedBarDark			= 4,
	MGI_RoundedBarDark_Top		= 5,
	MGI_RoundedBarDark_Bottom	= 6,
	MGI_RoundedBarDark_Mid		= 7,
	MGI_DPad_Inactive			= 8,
	MGI_DPad_Active				= 9,
	MGI_Spinball				= 10,
	MGI_Circle					= 11,
	MGI_Circle_Outline			= 12,
	MGI_Square					= 13,
	MGI_Square_Outline			= 14,
	MGI_Triangle				= 15,
	MGI_Triangle_Outline		= 16,
	MGI_White_Box				= 17,
	MGI_Bio_Beam				= 18,
	MGI_Bio_Bullet				= 19,
	MGI_Super_Bullet			= 20,
	MGI_Super_Shadow			= 21,
	MGI_Super_Sonic				= 22,
};

class MinigameIconData
{
public:
	void LoadIcons();
	void ReleaseIcons();
	NJS_TEXANIM* GetAnim(MinigameIcon icon);
	NJS_TEXANIM* MinigameAnims;
	NJS_TEXLIST* MinigameTex;
	int AnimLength;

	//600 x 480 of usuable space, but using 600 x 380 for standard minigames removing 100 at the top
	float xMin;
	float xMax;
	float xCenter;
	float yMin = 0.0f;
	float yMax = 480.0f;
	float yCenter = 240.0f;
};

