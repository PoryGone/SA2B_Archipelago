#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include "../Components/Wiggle.h"

class MinigameFinalBoss : public MinigameBase
{

	enum FinalBossState
	{
		FBS_Intro,
		FBS_InGame,
		FBS_Swap,
		FBS_Loss,
		FBS_Win,
	};

	enum FinalBossIntroState
	{
		FBIS_FadeIn,
		FBIS_CharacterEntrance,
		FBIS_BossEntrance,
		FBIS_CharacterToStart,
	};

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

private:

	void RunIntro(MinigameManagerData data);
	void RunInGame(MinigameManagerData data);
	void RunSwap(MinigameManagerData data);
	void UpdateCharacterPosition(MinigameManagerData data);

	FinalBossState state;
	FinalBossIntroState introState;

	float bossHealth;
	bool sonicIsActive;

	float characterSpeed = 2.0f;
	float enemyBulletSpeed = 2.0f;
	float playerBulletSpeed = 4.0f;

	NJS_POINT3 sonicOffScreenPos = { 230.0f, 512.0f };
	NJS_POINT3 shadowOffScreenPos = { 410.0f, 512.0f };

	SpriteNode* background;
	SpriteNode* rightBar;
	SpriteNode* leftBar;

	SpriteNode* characterParent;
	SpriteNode* sonic;
	SpriteNode* shadow;

	SpriteNode* sonicRings;
	SpriteNode* shadowRings;
	TextBox* sonicRingsText;
	TextBox* shadowRingsText;
	
	SpriteNode* FHParent;
	SpriteNode* FHLArmBase;
	SpriteNode* FHLArm;
	SpriteNode* FHRArmBase;
	SpriteNode* FHRArm;
	SpriteNode* FHBody;
	SpriteNode* FHHead;
	Wiggle* FHLWiggle;
	Wiggle* FHRWiggle;

};
