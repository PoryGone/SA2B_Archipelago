#include "../pch.h"
#pragma once

#include <array>
#include <map>


enum MusicShuffleType
{
	MST_None = 0,
	MST_Levels = 1,
	MST_Full = 2
};

class MusicManager
{
public:
	static MusicManager& getInstance()
	{
		static MusicManager instance;
		return instance;
	}

	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);

	void SetMusicMap(std::map<int, int> map);
	void SetMusicShuffle(int shuffleType);

//private:
	const HelperFunctions* _helperFunctions;

	MusicShuffleType _ShuffleType = MusicShuffleType::MST_None;

	std::map<int, int> _MusicMap;

	std::array<const char*, 78> _AllMusicNames = {
		"A_MINE.ADX", // Aquatic Mine
		"boss_01.adx", // Big Foot
		"boss_02a.adx", // Egg Golem Sonic
		"boss_02b.adx", // Egg Golem Eggman
		"boss_03.adx", // Vs Knuckles/Rouge
		"boss_04.adx", // Sonic vs Shadow 1
		"boss_05.adx", // Sonic vs Shadow 2
		"boss_06.adx", // Vs Biolizard
		"boss_07.adx", // Vs FinalHazard
		"btl_ce.adx", // Battle City Escape (Good)
		"btl_pc.adx", // Battle Pyramid Cave (Unique)
		"c_core_1.adx", // Cannon's Core 1 (Tails/Eggman)
		"c_core_2.adx", // Cannon's Core 2 (Rouge/Knuckles)
		"c_core_5.adx", // Cannon's Core 3 (Sonic)
		"c_core_6.adx", // Cannon's Core 4 (SA1 Drums)
		"c_escap1.adx", // City Escape 1
		"c_escap2.adx", // City Escape 2 (GUN Truck)
		"c_escap3.adx", // City Escape 3 (Better version of 1)
		"c_gadget.adx", // Crazy Gadget
		"c_wall.adx", // Cosmic Wall
		"d_chambr.adx", // Death Chamber
		"d_lagoon.adx", // Dry Lagoon
		"e_engine.adx", // Eternal Engine
		"e_quart.adx", // Egg Quarters
		"f_chase.adx", // Final Chase
		"f_rush.adx", // Final Rush
		"g_fores.adx", // Green Forest
		"g_hill.adx", // Green Hill
		"h_base.adx", // Hidden Base
		"i_gate.adx", // Iron Gate
		"kart.adx", // Kart Race
		"l_colony.adx", // Lost Colony
		"m_harb1.adx", // Metal Harbor Main
		"m_harb2.adx", // Metal Harbor Boarding
		"m_herd.adx", // Meteor Herd
		"m_space.adx", // Mad Space
		"m_street.adx", // Mission Street
		"p_cave.adx", // Pyramid Cave
		"p_hill.adx", // Pumpkin Hill
		"p_lane.adx", // Prison Lane
		"r_hwy.adx", // Radical Highway
		"s_hall.adx", // Security Hall
		"S_OCEAN.ADX", // Sand Ocean
		"s_rail.adx", // Sky Rail
		"W_BED.ADX", // Weapons Bed
		"w_canyon.adx", // Wild Canyon
		"w_jungl.adx", // White Jungle

		"advsng_1.adx", // Main Menu
		"advsng_2.adx", // Story Recap
		"advsng_3.adx", // Options
		"advsng_4.adx", // Stage Select
		"advsng_5.adx", // Tutorial
		"btl_sel.adx", // Battle Menu
		"chao_g_bgm_d.adx", // Dark Chao Garden
		"chao_g_bgm_h.adx", // Hero Chao Garden
		"chao_g_bgm_n.adx", // Neutral Chao Garden
		"chao_g_iede.adx", // Chao dying??? (Good)
		"chao_hall.adx", // Chao Lobby
		"chao_k_m.adx", // Chao Kindergarten
		"chao_l_m.adx", // Chao Race/Karate Entrance
		"chao_r_b.adx", // Chao Race 1
		"chao_r_c.adx", // Chao Race 2
		"chao_r_d.adx", // Chao Race 3 (Dark)
		"chao_r_e.adx", // Chao Teleporter
		"chao_r_h.adx", // Chao Race 4 (Hero)
		"chao_r_j.adx", // Chao Race 5
		"c_btl_cv.adx", // Chao Race Lobby
		"c_btl_gm.adx", // Chao Karate 1
		"c_btl_sl.adx", // Chao Karate Lobby
		"e006_sng.adx", // Jail Cell Cutscene (Good)
		"e021_sng.adx", // Mission Prep Cutscene Dark (Good)
		"T3_KNUCK.ADX", // Theme of Knuckles (Vocal)
		"t9_amy.adx", // Theme of Amy
		"T9_EGGMA.ADX", // Theme of Eggman (Vocal)
		"T9_MILES.ADX", // Theme of Tails (Vocal)
		"T9_ROUGE.ADX", // Theme of Rouge (Vocal)
		"T9_SHADO.ADX", // Theme of Shadow (Vocal)
		"T9_SONIC.ADX", // Theme of Sonic
	};

	std::array<const char*, 78> _AllSADXMusicNames = {
		"./bgm/wma/twnklpk1.adx", // Twinkle Park 1 (Race Section)
		"./bgm/wma/bosstrgt.adx", // Robot Bosses
		"./bgm/wma/chaos_p2.adx", // Perfect Chaos Boss (Second Part)
		"./bgm/wma/bossall.adx", // Generic Boss (Eggman?)
		"./bgm/wma/bossevnt.adx", // Character Fights
		"./bgm/wma/chaos.adx", // Chaos 0/2/4 Boss
		"./bgm/wma/chaos_6.adx", // Chaos 6 Boss
		"./bgm/wma/eggmbl23.adx", // Eggman Final Bosses (Get a Load of This)
		"./bgm/wma/chaos_p1.adx", // Perfect Chaos Boss (Open Your Heart)
		"./bgm/wma/themiles.adx", // Tails Theme (Instrumental)
		"./bgm/wma/thesonic.adx", // Sonic Theme (Instrumental)
		"./bgm/wma/bosse101.adx", // Crazy Robo (E101)
		"./bgm/wma/shelter1.adx", // Hot Shelter 1
		"./bgm/wma/shelter2.adx", // Hot Shelter 2
		"./bgm/wma/lstwrld2.adx", // Lost World 2
		"./bgm/wma/advbig.adx", // Big Theme (Short)
		"./bgm/wma/wndyvly2.adx", // Windy Valley 2 (Tornado)
		"./bgm/wma/thebig.adx", // Big Theme (Instrumental)
		"./bgm/wma/finaleg2.adx", // Final Egg 2
		"./bgm/wma/scramble.adx", // Egg Carrier Chase
		"./bgm/wma/egcarer1.adx", // Egg Carrier 1
		"./bgm/wma/wndyvly1.adx", // Windy Valley 1 (Main)
		"./bgm/wma/finaleg1.adx", // Final Egg 1
		"./bgm/wma/ecoast3.adx", // Emerald Coast 3 (Fishing)
		"./bgm/wma/skydeck2.adx", // Sky Deck 2
		"./bgm/wma/skydeck1.adx", // Sky Deck 1
		"./bgm/wma/ecoast2.adx", // Emerald Coast 2
		"./bgm/wma/wndyvly3.adx", // Windy Valley 3 (Sky)
		"./bgm/wma/sandhill.adx", // Sand Hill Minigame
		"./bgm/wma/casino2.adx", // Casinopolis Sewer
		"./bgm/wma/circuit.adx", // Kart Race Mode
		"./bgm/wma/twnklpk3.adx", // Twinkle Park 3 (Interior)
		"./bgm/wma/twnklpk2.adx", // Twinkle Park 2 (Main Section)
		"./bgm/wma/icecap3.adx", // Ice Cap 3 (Snowboarding)
		"./bgm/wma/icecap1.adx", // Ice Cap 1 (Calm Mountain)
		"./bgm/wma/icecap2.ADX", // Ice Cap 2 (Ice Cave)
		"./bgm/wma/highway3.adx", // Speed Highway 3 (Dawn)
		"./bgm/wma/lstwrld1.adx", // Lost World 1
		"./bgm/wma/redmntn2.adx", // Red Mountain 2 (Interior)
		"./bgm/wma/casino3.adx", // Casinopolis Pinball
		"./bgm/wma/highway1.adx", // Speed Highway 1 (Up & Down & All Around)
		"./bgm/wma/casino1.adx", // Casinopolis Main
		"./bgm/wma/lstwrld3.adx", // Lost World 3 (Emerald Area)
		"./bgm/wma/redmntn1.adx", // Red Mountain 1 (Exterior)
		"./bgm/wma/egcarer2.adx", // Egg Carrier 2 (Crashed)
		"./bgm/wma/mstcln.adx", // Mystic Ruins Overworld
		"./bgm/wma/ecoast1.adx", // Emerald Coast 1

		"./bgm/wma/sprsonic.adx", // Open Your Heart (Instrumental)
		"./bgm/wma/jingle_3.ADX", // Menu?
		"./bgm/wma/option.adx", // Options Menu?
		"./bgm/wma/charactr.adx", // Character Select
		"./bgm/wma/jingle_5.ADX", // Tutorial?
		"./bgm/wma/jingle_2.ADX", // Menu?
		"./bgm/wma/eggrobo.adx", // Amy Robot Chase Cutscenes
		"./bgm/wma/s_square.adx", // Station Square Overworld
		"./bgm/wma/chao.adx", // Chao Garden
		"./bgm/wma/chao_g_iede.adx", // Sad Chao Music
		"./bgm/wma/chaohall.adx", // Chao Lobby?
		"./bgm/wma/CHAO_K_M.ADX", // Chao Kindergarten
		"./bgm/wma/evtbgm00.adx", // Sad Cutscene
		"./bgm/wma/chaorace.adx", // Chao Race
		"./bgm/wma/fishing.adx", // Fish on the Line
		"./bgm/wma/evtbgm01.adx", // Tense/Chaos Cutscene
		"./bgm/wma/CHAO_R_E.adx", // Chao Teleporter
		"./bgm/wma/casino4.adx", // Casinopolis NIGHTS Pinball
		"./bgm/wma/hammer.adx", // Hammer Minigame?
		"./bgm/wma/c_btl_cv.adx", // Chao Race Lobby
		"./bgm/wma/theknkls.adx", // Knuckles Theme (Instrumental)
		"./bgm/wma/trial.adx", // Character Select Again?
		"./bgm/wma/evtbgm02.adx", // E102 Ending Cutscene
		"./bgm/wma/hurryup.adx", // Hurry Up? (looping)
		"./bgm/wma/advknkls.adx", // Knuckles Theme (Short)
		"./bgm/wma/advamy.adx", // Amy Theme (Short)
		"./bgm/wma/eggman.adx", // Eggman Theme (Long)
		"./bgm/wma/advmiles.adx", // Tails Theme (Short)
		"./bgm/wma/tical.adx", // Tikal Theme
		"./bgm/wma/thee102.adx", // E102 Theme (Instrumental)
		"./bgm/wma/advsonic.ADX", // Sonic Theme (Short)
	};
};
