#pragma once

#define POKE_START 31

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
	MGI_Boss_Body				= 23,
	MGI_Boss_Arm				= 24,
	MGI_Boss_Head				= 25,
	MGI_Artificial_Chaos_Round	= 26,
	MGI_Artificial_Chaos_Tall	= 27,
	MGI_Beetle					= 28,
	MGI_Beetle_Gun				= 29,
	MGI_Barrel					= 30,

	//Pokemon
	MGI_Aron					= POKE_START + 0,
	MGI_Bulbasaur				= POKE_START + 1,
	MGI_Charjabug				= POKE_START + 2,
	MGI_Charmander				= POKE_START + 3,
	MGI_Ditto					= POKE_START + 4,
	MGI_Dratini					= POKE_START + 5,
	MGI_Flamigo					= POKE_START + 6,
	MGI_Goomy					= POKE_START + 7,
	MGI_Grimer					= POKE_START + 8,
	MGI_Haunter					= POKE_START + 9,
	MGI_Litwick					= POKE_START + 10,
	MGI_Phantump				= POKE_START + 11,
	MGI_Piplup					= POKE_START + 12,
	MGI_Pooper					= POKE_START + 13,
	MGI_Porygon					= POKE_START + 14,
	MGI_Roggenrola				= POKE_START + 15,
	MGI_Shuckle					= POKE_START + 16,
	MGI_Sinistea				= POKE_START + 17,
	MGI_Snom					= POKE_START + 18,
	MGI_Spiritomb				= POKE_START + 19,
	MGI_Sudowoodo				= POKE_START + 20,
	MGI_Surskit					= POKE_START + 21,
	MGI_Tatsugiri				= POKE_START + 22,
	MGI_Togepi					= POKE_START + 23,
	MGI_Chansey					= POKE_START + 24,
	MGI_UnownQue				= POKE_START + 25,
	MGI_UnownX					= POKE_START + 26,
	MGI_Wailmer					= POKE_START + 27,
	MGI_Wooper					= POKE_START + 28,
	MGI_Wugtrio					= POKE_START + 29,
	MGI_Shroomish				= POKE_START + 30,
	MGI_Suicune					= POKE_START + 31,
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

	//600 x 480 of usuable space, but using 600 x 380 for standard minigames removing 100 at the top
	//5:4 is the narrowest ratio, henct 600x480 instead of 640x480
	float xMinSafe = 20.0f;
	float xMaxSafe = 620.0f;
	float xCenterSafe = 320.0f;
	float yMinSafe = 100.0f;
	float yMaxSafe = 480.0f;
	float yCenterSafe = 290.0f;
};

