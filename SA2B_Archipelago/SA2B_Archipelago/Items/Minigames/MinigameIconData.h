#pragma once

#define POKE_START 76

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
	MGI_Earth					= 26,
	MGI_Stars_BG				= 27,
	MGI_Artificial_Chaos_Round	= 28,
	MGI_Artificial_Chaos_Tall	= 29,
	MGI_Beetle					= 30,
	MGI_Beetle_Gun				= 31,
	MGI_Barrel					= 32,
	MGI_F_Rank					= 33,
	MGI_Chopper					= 34,
	MGI_Snake_Head				= 35,
	MGI_Snake_Tail				= 36,
	MGI_Snake_Straight			= 37,
	MGI_Snake_Turn				= 38,
	MGI_Snake_Turn_Mirrored		= 39,
	MGI_Bobber					= 40,
	MGI_Bobber_Splash			= 41,
	MGI_Big_0					= 42,
	MGI_Big_1					= 43,
	MGI_Caught_Banner			= 44,
	MGI_Miss_Banner				= 45,
	MGI_Sonic_Head				= 46,
	MGI_Bomb					= 47,
	MGI_Green_Check				= 48,
	MGI_Green_Circle			= 49,
	MGI_Red_X					= 50,
	MGI_Bobber_Circle			= 51,
	MGI_Life_Box				= 52,
	MGI_Safe_Handle				= 53,
	MGI_Caught_Big_Banner		= 54,
	MGI_Miss_Big_Banner			= 55,
	MGI_Tile_Unlit				= 56,
	MGI_Tile_Lit				= 57,
	MGI_Tile_Disabled			= 58,
	MGI_Bumper					= 59,
	MGI_Star					= 60,
	MGI_Tri_Bumper_Right		= 61,
	MGI_Tri_Bumper_Left			= 62,
	MGI_Bee_Taters				= 63,
	MGI_Bee_Pory				= 64,
	MGI_Bee_Ras					= 65,
	MGI_Bee_Unknown				= 66,
	MGI_Fishing_BG				= 67,
	MGI_Fishing_Bar_Outline		= 68,
	MGI_Fishing_Bar_Cap			= 69,
	MGI_Flipper					= 70,
	MGI_Block_Green				= 71,
	MGI_Block_Purple			= 72,
	MGI_Block_Deep_Purple		= 73, //Smoke on the Breakout Block
	MGI_Fishing_Catch_Bar		= 74,
	MGI_Tile_Arrow				= 75,

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

