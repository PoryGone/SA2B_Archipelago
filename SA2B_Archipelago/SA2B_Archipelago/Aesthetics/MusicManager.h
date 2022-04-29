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
		"advsng_1.adx", // Main Menu
		"advsng_2.adx", // Story Recap
		"advsng_3.adx", // Options
		"advsng_4.adx", // Stage Select
		"advsng_5.adx", // Tutorial
		"a_mine.adx", // Aquatic Mine
		"boss_01.adx", // Big Foot
		"BOSS_02A.ADX", // Egg Golem Sonic
		"BOSS_02B.ADX", // Egg Golem Eggman
		"boss_03.adx", // Vs Knuckles/Rouge
		"boss_04.adx", // Sonic vs Shadow 1
		"boss_05.adx", // Sonic vs Shadow 2
		"boss_06.adx", // Vs Biolizard
		"BOSS_07.ADX", // Vs FinalHazard
		"btl_ce.adx", // Battle City Escape (Good)
		"btl_pc.adx", // Battle Pyramid Cave (Unique)
		"btl_sel.adx", // Battle Menu
		"chao_g_bgm_d.adx", // Dark Chao Garden
		"chao_g_bgm_h.adx", // Hero Chao Garden
		"chao_g_bgm_n.adx", // Neutral Chao Garden
		"chao_g_iede.adx", // Chao dying??? (Good)
		"chao_hall.adx", // Chao Lobby
		"CHAO_K_M.ADX", // Chao Kindergarten
		"chao_l_m.adx", // Chao Race/Karate Entrance
		"chao_r_b.adx", // Chao Race 1
		"chao_r_c.adx", // Chao Race 2
		"chao_r_d.adx", // Chao Race 3 (Dark)
		"CHAO_R_E.ADX", // Chao Teleporter
		"chao_r_h.adx", // Chao Race 4 (Hero)
		"chao_r_j.adx", // Chao Race 5
		"c_btl_cv.adx", // Chao Race Lobby
		"c_btl_gm.adx", // Chao Karate 1
		"c_btl_sl.adx", // Chao Karate Lobby
		"c_core_1.adx", // Cannon's Core 1 (Tails/Eggman)
		"c_core_2.adx", // Cannon's Core 2 (Rouge/Knuckles)
		"c_core_5.adx", // Cannon's Core 3 (Sonic)
		"C_CORE_6.ADX", // Cannon's Core 4 (SA1 Drums)
		"c_escap1.adx", // City Escape 1
		"c_escap2.adx", // City Escape 2 (GUN Truck)
		"c_escap3.adx", // City Escape 3 (Better version of 1)
		"c_gadget.adx", // Crazy Gadget
		"c_wall.adx", // Cosmic Wall
		"d_chambr.adx", // Death Chamber
		"d_lagoon.adx", // Dry Lagoon
		"E006_SNG.ADX", // Jail Cell Cutscene (Good)
		"e021_sng.adx", // Mission Prep Cutscene Dark (Good)
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
		"s_ocean.adx", // Sand Ocean
		"s_rail.adx", // Sky Rail
		"T3_KNUCK.ADX", // Theme of Knuckles (Vocal)
		"t9_amy.adx", // Theme of Amy
		"T9_EGGMA.ADX", // Theme of Eggman (Vocal)
		"T9_MILES.ADX", // Theme of Tails (Vocal)
		"T9_ROUGE.ADX", // Theme of Rouge (Vocal)
		"T9_SHADO.ADX", // Theme of Shadow (Vocal)
		"T9_SONIC.ADX", // Theme of Sonic
		"w_bed.adx", // Weapons Bed
		"w_canyon.adx", // Wild Canyon
		"w_jungl.adx"  // White Jungle
	};

	std::array<const char*, 47> _LevelMusicNames = {
		"a_mine.adx", "boss_01.adx", "BOSS_02A.ADX", "BOSS_02B.ADX", "boss_03.adx", "boss_04.adx",
		"boss_05.adx", "boss_06.adx", "BOSS_07.ADX", "btl_ce.adx", "btl_pc.adx", "c_core_1.adx",
		"c_core_2.adx", "c_core_5.adx", "C_CORE_6.ADX", "c_escap1.adx", "c_escap2.adx", "c_escap3.adx",
		"c_gadget.adx", "c_wall.adx", "d_chambr.adx", "d_lagoon.adx", "e_engine.adx", "e_quart.adx",
		"f_chase.adx", "f_rush.adx", "g_fores.adx", "g_hill.adx", "h_base.adx", "i_gate.adx",
		"kart.adx", "l_colony.adx", "m_harb1.adx", "m_harb2.adx", "m_herd.adx", "m_space.adx",
		"m_street.adx", "p_cave.adx", "p_hill.adx", "p_lane.adx", "r_hwy.adx", "s_hall.adx",
		"s_ocean.adx", "s_rail.adx", "w_bed.adx", "w_canyon.adx", "w_jungl.adx"
	};
};