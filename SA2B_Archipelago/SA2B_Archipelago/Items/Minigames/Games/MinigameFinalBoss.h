#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include "../Components/Wiggle.h"
#include "../Components/AssignColorToChildren.h"
#include "../Components//ParticleEmitter.h"
#include <array>

enum BossAimType
{
	BAT_DownRelative,
	BAT_CharacterStart,
	BAT_CharacterContinuous,
};

enum BeamSequenceType
{
	BST_Hold,
	BST_RotateToAngle,
};

enum BossPatternNames
{
	BPN_AimC_3_Slow = 0,
	BPN_AimC_5_Slow,
	BPN_AimC_5_Quick,
	BPN_AimC_Burst_4,
	BPN_Burst_6,
	BPN_Burst_8,
	BPN_Burst_9,
	BPN_Burst_10,
	BPN_Burst_16,
	BPN_Burst_17,
	BPN_Spiral_12,
	BPN_Spiral_12_R,
	BPN_Spiral_24_PP,
	BPN_Spiral_24_PP_R,
	BPN_Spiral_47_PP,
	BPN_Spiral_47_PP_R,
};

enum BossBeamNames
{
	BBN_AimC,
	BBN_InOut_L,
	BBN_InOut_R,
};

struct MinigameBulletData
{
public:
	SpriteNode* node;
	NJS_POINT3 velocity;
};

struct BossBulletPattern
{
public:
	int bulletCount;
	bool pingPong;
	BossAimType aimType;
	float timeBetween;
	float angleBetween;
	float startAngle;
	bool startIncrementing;
	float minAngle;
	float maxAngle;

	BossBulletPattern(int _bulletCount, bool _pingPong, BossAimType _aimType, float _timeBetween, float _angleBetween, float _startAngle, bool _startIncrementing, float _minAngle, float _maxAngle) :
		bulletCount(_bulletCount), pingPong(_pingPong), aimType(_aimType), timeBetween(_timeBetween), angleBetween(_angleBetween), startAngle(_startAngle), startIncrementing(_startIncrementing), minAngle(_minAngle), maxAngle(_maxAngle) {}
};

struct BossPatternData
{
public:
	int dataIndex;
	int spawnPoint;
	float initialDelay;

	BossPatternData(int _dataIndex, int _spawnPoint, float _initialDelay) : dataIndex(_dataIndex), spawnPoint(_spawnPoint), initialDelay(_initialDelay) {}
};

struct BossBeamSequenceEntry
{
public:
	BeamSequenceType type;
	float speed;
	float time;
	float angle;
	bool active;

	BossBeamSequenceEntry(BeamSequenceType _type, float _speed, float _time, float _angle, bool _active) :
		type(_type), speed(_speed), time(_time), angle(_angle), active(_active) {}
};

struct BossBeamSequence
{
public:
	bool startAimAtPlayer;
	float startAngle;
	std::vector<BossBeamSequenceEntry> sequence;

	BossBeamSequence(bool _startAimAtPlayer, float _startAngle, std::vector<BossBeamSequenceEntry> _sequence) :
		startAimAtPlayer(_startAimAtPlayer), startAngle(_startAngle), sequence(_sequence) {}
};

struct BossBeamData
{
public:
	int dataIndex;
	float initialDelay;

	BossBeamData(int _dataIndex, float _initialDelay) : dataIndex(_dataIndex), initialDelay(_initialDelay) {}
};

struct BossPatternSequence
{
public:
	std::vector<BossPatternData> patterns;
	std::vector<BossBeamData> beams;

	BossPatternSequence(std::vector<BossPatternData> _patterns, std::vector<BossBeamData> _beams) : patterns(_patterns), beams(_beams) {}
};

struct BossPatternRuntimeData
{
public:
	bool active;
	Timer timer;
	int count;
	NJS_POINT3 characterStart;
	bool increasing;
	float rotation;

	BossPatternRuntimeData() : active(false), timer(Timer()), count(0), characterStart({0.0f, 0.0f}), increasing(false), rotation(0.0f) {}
};

struct BossBeamRuntimeData
{
public:
	bool active;
	Timer timer;
	SpriteNode* node;
	int progress;
	float currentRotation;
	float toRotation;
	bool collisionActive;

	BossBeamRuntimeData() : active(false), timer(Timer()), node(nullptr), progress(-1), currentRotation(0.0f), toRotation(0.0f), collisionActive(false) {}
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
	void OnCleanup(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

private:

	void RunIntro(MinigameManagerData data);
	void RunInGame(MinigameManagerData data);
	void RunSwap(MinigameManagerData data);
	void RunWin(MinigameManagerData data);
	void RunLose(MinigameManagerData data);
	void Victory(MinigameManagerData data);
	void Defeat(MinigameManagerData data);
	void CharacterShoot(MinigameManagerData data);
	void UpdateBullets(MinigameManagerData data);
	void UpdateCharacterPosition(MinigameManagerData data);
	void UpdateCharacterRingGrowthDecay(MinigameManagerData data);
	void UpdateWeakPoint();
	void UpdateHealthBarFill();
	void UpdateSequence();
	void UpdatePattern(int index);
	void UpdateBeam(int index);
	void CheckCharacterCollision(MinigameManagerData data);
	void OnCharacterHit();

	FinalBossState state;
	FinalBossIntroState introState;

	float bossMaxHealth = 150.0f;
	float bossHealth;
	int sonicRingCount;
	int shadowRingCount;
	bool sonicIsActive;
	int remainingIFrames = 0;
	int onHitIFrames = 15;
	int onHitRingDamage = 5;
	int ringEmitterIndex = 0;

	float characterSpeed = 4.0f;
	float enemyBulletSpeed = 3.0f;
	float characterBulletSpeed = 5.0f;
	float characterBulletCooldown = 0.25f;
	float beamWidth = 32.0f;
	float ringDecayCooldown = 2.0f;
	float ringGrowthCooldown = 1.0f;

	NJS_POINT3 characterBulletSize = { 14.0f, 32.0f };
	NJS_POINT3 bossBulletSize = { 20.0f, 20.0f };

	NJS_POINT3 sonicOffScreenPos = { 230.0f, 512.0f };
	NJS_POINT3 shadowOffScreenPos = { 410.0f, 512.0f };
	
	float weakPointCooldown = 10.0f;
	int weakSpotIndex = 0;
	std::array<NJS_POINT3, 8> weakPointPositions = { { { -120.0f, 17.0f }, { -81.0f, 11.0f }, { -51.0f, 38.0f }, { -14.0f, 25.0f }, { 31.0f, 17.0f }, { 51.0f, 30.0f }, { 80.0f, 38.0f }, { 124.0f, 11.0f } } };
	std::array<NJS_POINT3, 3> bulletSpawns = { { {320.0f, 30.0f}, {180.0f, 0.0f}, {460.0f, 0.0f} } };

	SpriteNode* background;
	SpriteNode* rightBar;
	SpriteNode* leftBar;

	SpriteNode* characterParent;
	SpriteNode* sonic;
	SpriteNode* shadow;
	std::array<ParticleEmitter*, 5> ringEmitters = { nullptr ,nullptr ,nullptr ,nullptr ,nullptr };

	SpriteNode* sonicRings;
	SpriteNode* shadowRings;
	TextBox* sonicRingsText;
	TextBox* shadowRingsText;

	SpriteNode* endTextNode;
	TextBox* endText;
	
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
	SpriteNode* FHExplostion;
	ParticleEmitter* FHExplosionEmitter;

	SpriteNode* FHHealthBar;
	SpriteNode* FHHealthBarBG;

	Timer characterShootTimer;
	Timer ringGrowthTimer;
	Timer ringDecayTimer;
	Timer weakPointTimer;
	Timer sequenceTimer;
	std::array<BossPatternRuntimeData, 10> patternProgress;
	std::array<BossBeamRuntimeData, 8> beamProgress;

	int sequenceIndex = 0;
	BossPatternSequence* currentSequence = nullptr;

	SpriteNode* characterBulletParent;
	std::vector<MinigameBulletData> characterBullets;
	SpriteNode* bossBulletParent;
	std::vector<MinigameBulletData> bossBullets;
	SpriteNode* bossBeamParent;

#pragma region PatternData

	std::vector<BossBulletPattern> patterns = {
		BossBulletPattern(3, false, BAT_CharacterContinuous, 1.0f, 0.0f, 0.0f, false, 0.0f, 0.0f), //BPN_AimC_3_Slow
		BossBulletPattern(5, false, BAT_CharacterContinuous, 1.0f, 0.0f, 0.0f, false, 0.0f, 0.0f), //BPN_AimC_5_Slow
		BossBulletPattern(5, false, BAT_CharacterContinuous, 0.25f, 0.0f, 0.0f, false, 0.0f, 0.0f), //BPN_AimC_5_Quick
		BossBulletPattern(4, false, BAT_CharacterStart, 0.0f, 20.0f, -30.0f, true, -90.0f, 90.0f), //BPN_AimC_Burst_4
		BossBulletPattern(6, false, BAT_DownRelative, 0.0f, 30.0f, -75.0f, true, -90.0f, 90.0f), //BPN_Burst_6
		BossBulletPattern(8, false, BAT_DownRelative, 0.0f, 22.5f, -78.75f, true, -90.0f, 90.0f), //BPN_Burst_8
		BossBulletPattern(9, false, BAT_DownRelative, 0.0f, 22.5f, -90.0f, true, -90.0f, 90.0f), //BPN_Burst_9
		BossBulletPattern(10, false, BAT_DownRelative, 0.0f, 18.0f, -81.0f, true, -90.0f, 90.0f), //BPN_Burst_10
		BossBulletPattern(16, false, BAT_DownRelative, 0.0f, 11.25f, -84.375f, true, -90.0f, 90.0f), //BPN_Burst_16
		BossBulletPattern(17, false, BAT_DownRelative, 0.0f, 11.25f, -90.0f, true, -90.0f, 90.0f), //BPN_Burst_17
		BossBulletPattern(12, false, BAT_DownRelative, 0.15f, 15.0f, -90.0f, true, -90.0f, 90.0f), //BPN_Spiral_12
		BossBulletPattern(12, false, BAT_DownRelative, 0.15f, 15.0f, 90.0f, false, -90.0f, 90.0f), //BPN_Spiral_12_R
		BossBulletPattern(24, true, BAT_DownRelative, 0.15f, 15.0f, -90.0f, true, -90.0f, 90.0f), //BPN_Spiral_24_PP
		BossBulletPattern(24, true, BAT_DownRelative, 0.15f, 15.0f, 90.0f, false, -90.0f, 90.0f), //BPN_Spiral_24_PP_R
		BossBulletPattern(47, true, BAT_DownRelative, 0.1f, 15.0f, -90.0f, true, -90.0f, 90.0f), //BPN_Spiral_47_PP
		BossBulletPattern(47, true, BAT_DownRelative, 0.1f, 15.0f, 90.0f, false, -90.0f, 90.0f), //BPN_Spiral_47_PP_R
	};

	std::vector<BossBeamSequence> beamSequences = {
		BossBeamSequence(true, 0.0f, { //BBN_AimC
			BossBeamSequenceEntry(BST_Hold, 0.0f, 1.0f, 0.0f, false),
			BossBeamSequenceEntry(BST_Hold, 0.0f, 1.0f, 0.0f, true),
			}),
		BossBeamSequence(false, -90.0f, { //BBN_InOut_L
			BossBeamSequenceEntry(BST_Hold, 0.0f, 1.0f, 0.0f, false),
			BossBeamSequenceEntry(BST_RotateToAngle, 20.0f, 0.0f, -30.0f, true),
			BossBeamSequenceEntry(BST_Hold, 0.0f, 1.0f, 0.0f, true),
			BossBeamSequenceEntry(BST_RotateToAngle, 20.0f, 0.0f, -90.0f, true),
			BossBeamSequenceEntry(BST_Hold, 0.0f, 0.5f, 0.0f, true),
			}),
		BossBeamSequence(false, 90.0f, { //BBN_InOut_R
			BossBeamSequenceEntry(BST_Hold, 0.0f, 1.0f, 0.0f, false),
			BossBeamSequenceEntry(BST_RotateToAngle, 20.0f, 0.0f, 30.0f, true),
			BossBeamSequenceEntry(BST_Hold, 0.0f, 1.0f, 0.0f, true),
			BossBeamSequenceEntry(BST_RotateToAngle, 20.0f, 0.0f, 90.0f, true),
			BossBeamSequenceEntry(BST_Hold, 0.0f, 0.5f, 0.0f, true),
			}),
	};

	std::vector<BossPatternSequence> earlySequences = {
		BossPatternSequence({
			BossPatternData(BPN_AimC_5_Slow, 0, 0.0f),
			BossPatternData(BPN_Spiral_12, 1, 0.0f),
			BossPatternData(BPN_Spiral_12_R, 2, 0.0f),
			BossPatternData(BPN_Spiral_12, 1, 3.0f),
			BossPatternData(BPN_Spiral_12_R, 2, 3.0f),
			}, {}),
		BossPatternSequence({
			BossPatternData(BPN_Burst_6, 1, 0.0f),
			BossPatternData(BPN_Burst_6, 2, 1.0f),
			BossPatternData(BPN_Burst_8, 1, 2.0f),
			BossPatternData(BPN_Burst_8, 2, 3.0f),
			BossPatternData(BPN_Burst_10, 1, 4.0f),
			BossPatternData(BPN_Burst_10, 2, 5.0f),
			}, {}),
		BossPatternSequence({
			BossPatternData(BPN_AimC_5_Quick, 0, 0.0f),
			BossPatternData(BPN_Spiral_24_PP, 1, 1.0f),
			BossPatternData(BPN_Spiral_24_PP_R, 2, 1.0f),
			}, {}),
		BossPatternSequence({
			BossPatternData(BPN_AimC_5_Slow, 1, 0.0f),
			BossPatternData(BPN_AimC_5_Slow, 2, 0.0f),
			BossPatternData(BPN_Burst_8, 0, 0.0f),
			BossPatternData(BPN_Burst_9, 0, 1.25f),
			BossPatternData(BPN_Burst_8, 0, 2.5f),
			BossPatternData(BPN_Burst_9, 0, 3.75f),
			BossPatternData(BPN_Burst_8, 0, 5.0f),
			}, {}),
		BossPatternSequence({
			BossPatternData(BPN_Burst_9, 1, 1.0f),
			BossPatternData(BPN_Burst_9, 2, 3.0f),
			}, {
			BossBeamData(BBN_AimC, 0.0f),
			BossBeamData(BBN_AimC, 1.0f),
			BossBeamData(BBN_AimC, 2.0f),
			BossBeamData(BBN_AimC, 3.0f),
			}),
		BossPatternSequence({
			BossPatternData(BPN_AimC_Burst_4, 1, 1.0f),
			BossPatternData(BPN_AimC_Burst_4, 2, 1.0f),
			BossPatternData(BPN_AimC_Burst_4, 1, 3.0f),
			BossPatternData(BPN_AimC_Burst_4, 2, 3.0f),
			BossPatternData(BPN_AimC_Burst_4, 1, 5.0f),
			BossPatternData(BPN_AimC_Burst_4, 2, 5.0f),
			BossPatternData(BPN_AimC_Burst_4, 1, 7.0f),
			BossPatternData(BPN_AimC_Burst_4, 2, 7.0f),
			}, {
			BossBeamData(BBN_InOut_L, 0.0f),
			BossBeamData(BBN_InOut_R, 0.0f),
			}),
	};

	std::vector<BossPatternSequence> lateSequences = {
		BossPatternSequence({
			BossPatternData(BPN_AimC_5_Slow, 1, 0.0f),
			BossPatternData(BPN_AimC_5_Slow, 2, 0.0f),
			BossPatternData(BPN_Burst_16, 0, 0.0f),
			BossPatternData(BPN_Burst_17, 0, 1.0f),
			BossPatternData(BPN_Burst_16, 0, 2.0f),
			BossPatternData(BPN_Burst_17, 0, 3.0f),
			BossPatternData(BPN_Burst_16, 0, 4.0f),
			}, {}),
		BossPatternSequence({
			BossPatternData(BPN_Burst_8, 1, 0.0f),
			BossPatternData(BPN_Burst_8, 2, 0.5f),
			BossPatternData(BPN_Burst_10, 1, 1.0f),
			BossPatternData(BPN_Burst_10, 2, 1.5f),
			BossPatternData(BPN_Burst_16, 1, 2.0f),
			BossPatternData(BPN_Burst_16, 2, 2.5f),
			}, {}),
		BossPatternSequence({
			BossPatternData(BPN_AimC_5_Quick, 0, 0.0f),
			BossPatternData(BPN_Spiral_47_PP, 1, 1.0f),
			BossPatternData(BPN_Spiral_47_PP_R, 2, 1.0f),
			}, {}),
	};

#pragma endregion
};
