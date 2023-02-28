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
	MGI_Spinball				= 8,
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

	float xMin;
	float xMax;
	float xCenter;
	float yMin = 0.0f;
	float yMax = 480.0f;
	float yCenter = 240.0f;
};

