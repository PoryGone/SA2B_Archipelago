#pragma once
#include "MinigameIconData.h"
#include "TextDisplayData.h"
#include "../../Utilities/SpriteUtilities.h"
#include "../../Utilities/EasingUtilities.h"
#include "Backend/MinigameBackend.h"
#include "Backend/Time/TimeUtilities.h"
#include <vector>

/*
Use this for upper nibble of Sound ID

0:  STG_SE,    |   stage sound effects        |   [bank 5]
1:  GM,        |   game sounds                |   [bank 1]
2:  CH,        |   character sounds           |   [bank 2]
3:  VC,        |   voice clip                 |   [bank 3]
4:  EM,        |   enemy                      |   [bank 4]
5:  NA,        |   nothing                    |
6:  STG_ENV,   |   stage environment sounds   |   [bank 6]
7:  WT,        |   unknown                    |   [bank 7]
8:  SY,        |   system sounds              |   [bank 0]

*/
enum class MinigameSounds
{
	Spring		= 0x1000,
	Checkpoint,
	MedBeep,
	DashPanel,
	LowExplode,
	RocketPrep,
	BalloonPop,
	RailContact,
	ExtraLife,
	RadarBeep,
	AnimalSpawn,
	MysticSpawn,
	Crusher,
	LostChao,
	LostChaoLaugh,
	None,
	WoodBoxBreak,
	MetalBoxBreak,
	GoalRingLoop,
	GoalRingTouch,
	BackRingTouch,
	HighPitchLoop,
	BlockDragLoop,
	Teleport_1,
	Teleport_2,
	RocketLaunch,
	SpinningBallLoop,
	RailLoop_1,
	RailLoop_2,
	PulleyLoop,
	MysticMelody,
	LowZap,
	ElevatorStart,
	LowClang,
	CageBreak,
	Nyoom,
	Bink,

	Whistle_1 =  0x2005,
	Whistle_2 =  0x2006,

	GunShoot_1 = 0x4000,
	LaserCharge,
	LaserShoot,
	GunShoot_2,
	BombFall,
	GhostJumpscare = 0x4014,
	GhostDie,
	RobotDie = 0x4019,
	RobotDie_2,
	RobotDie_3 = 0x401E,
	ArtificialChaosBounce,
	Boing = 0x4023,

	Splort = 0x7002,

	MenuNav = 0x8000,
	MenuSelect,
	Pause,
	HighBeep,
	SpendRings,
	CollectRing,
	CollectEmblem,
	Punch,
	MenuLoad,
	MenuBack,
	MenuError,
	OmochaoActivate,
	OmochaoDie,
	ItemBox,
	SwitchPress,
	CollectAnimal,
	AnimalSpawn_2,
	CollectChaosDrive,
	GoToChaoGarden,
	HintMonitor,
	LoseRings,
	Explosion,
	Flute,
	OmochaoLoop,
	LowExplosion,
	LevelStart,
	Shield,
	TwoBloops,
	StageClearBink,
	RankReveal,
	TypeLetter,
	LowBeep,
	CommunicatorBeep,
	ComputerNoise,
};

enum RawInputFlags
{
	RIF_None = 0,
	RIF_B = 2,
	RIF_A = 4,
	RIF_Start = 8,
	RIF_Up = 16,
	RIF_Down = 32,
	RIF_Left = 64,
	RIF_Right = 128,
	RIF_Y = 512,
	RIF_X = 1024,
	RIF_RightTrigger = 65536,
	RIF_LeftTrigger = 131072,
	//C-C-C-Combo Inputs!
	RIF_ANY_D_PAD = 0b11110000,
};
DEFINE_ENUM_FLAG_OPERATORS(RawInputFlags);

enum MinigameState
{
	MGS_None,
	MGS_PreGame,
	MGS_InProgress,
	MGS_Victory,
	MGS_Draw,
	MGS_Loss,
};

enum MinigameDifficulty
{
	MGD_Easy,
	MGD_Medium,
	MGD_Hard,
	MGD_Chaos,
};

struct MinigameManagerData
{
public:
	RawInputFlags input;
	RawInputFlags inputPress;
	RawInputFlags inputRelease;
	MinigameState managerState;
	MinigameIconData* icons;
	TextDisplayData* text;
	MinigameDifficulty difficulty;
	SpriteHierarchy* hierarchy;
	CollisionManager* collision;

	std::vector<Timer*>* timers;
	std::vector<Stopwatch*>* stopwatches;

	bool isLocationCheck;
	bool isLinkedTrap;
};

class MinigameBase
{
public:
	virtual void OnGameStart(MinigameManagerData data) = 0;
	virtual void OnFrame(MinigameManagerData data) = 0;
	virtual void OnCleanup(MinigameManagerData data) {};
	MinigameState currentState;
	float pregameTime = 1.0f;
};