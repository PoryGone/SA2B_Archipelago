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
		FBS_Loss,
		FBS_Win,
	};

	enum FinalBossIntroState
	{
		FBIS_CharacterEntrance,
		FBIS_BossEntrance,
	};

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

private:

	FinalBossState state;
	FinalBossIntroState introState;

	float bossHealth;

	SpriteNode* background;

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
