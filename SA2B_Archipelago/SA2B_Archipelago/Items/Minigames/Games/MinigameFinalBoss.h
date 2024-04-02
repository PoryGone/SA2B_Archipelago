#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include "../Components/Wiggle.h"

struct MinigameBulletData
{
public:
	SpriteNode* node;
	NJS_POINT3 velocity;
};

struct MinigameBulletPattern
{
public:
	int bulletCount;
	bool pingPong;
	bool aimAtCharacter;
	float timeBetween;
	float angleBetween;
	float startAngle;
	float endAngle;
};

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
	void CharacterShoot(MinigameManagerData data);
	void UpdateBullets(MinigameManagerData data);
	void UpdateCharacterPosition(MinigameManagerData data);
	void UpdateCharacterRingGrowthDecay(MinigameManagerData data);
	void UpdateWeakPoint();
	void UpdateHealthBarFill();
	bool IsSpriteOutsidePlayArea(SpriteNode* node);

	FinalBossState state;
	FinalBossIntroState introState;

	float bossMaxHealth = 100.0f;
	float bossHealth;
	int sonicRingCount;
	int shadowRingCount;
	bool sonicIsActive;

	float characterSpeed = 4.0f;
	float enemyBulletSpeed = 3.0f;
	float characterBulletSpeed = 5.0f;
	float characterBulletCooldown = 0.25f;
	float ringDecayCooldown = 2.0f;
	float ringGrowthCooldown = 1.0f;

	NJS_POINT3 characterBulletSize = { 32.0f, 32.0f };
	NJS_POINT3 bossBulletSize = { 32.0f, 32.0f };

	NJS_POINT3 sonicOffScreenPos = { 230.0f, 512.0f };
	NJS_POINT3 shadowOffScreenPos = { 410.0f, 512.0f };
	
	float weakPointCooldown = 10.0f;
	int weakSpotIndex = 0;
	std::vector<NJS_POINT3> weakPointPositions = { { -120.0f, 17.0f }, { -81.0f, 11.0f }, { -51.0f, 38.0f }, { -14.0f, 25.0f }, { 31.0f, 17.0f }, { 51.0f, 30.0f }, { 80.0f, 38.0f }, { 124.0f, 11.0f } };

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
	SpriteNode* FHWeakPoint;
	Wiggle* FHLWiggle;
	Wiggle* FHRWiggle;

	SpriteNode* FHHealthBar;
	SpriteNode* FHHealthBarBG;

	Timer characterShootTimer;
	Timer ringGrowthTimer;
	Timer ringDecayTimer;
	Timer weakPointTimer;
	std::vector<Timer> patternTimers = { Timer(), Timer(), Timer(), Timer() };

	SpriteNode* characterBulletParent;
	std::vector<MinigameBulletData> characterBullets;
	SpriteNode* bossBulletParent;
	std::vector<MinigameBulletData> bossBullets;

};
