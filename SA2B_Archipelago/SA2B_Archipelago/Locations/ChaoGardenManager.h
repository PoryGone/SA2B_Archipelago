#include "../pch.h"
#pragma once

#include <map>
#include <array>
#include "../Archipelago/ArchipelagoManager.h"
#include "../ModLoaderCommon/Trampoline.h"

constexpr unsigned int CGM_MEMORY_CHECK_TIME = 600;

enum ChaoExit
{
	CE_LobbyNeutral = 0x00,
	CE_LobbyHero,
	CE_LobbyDark,
	CE_LobbyKindergarten,
	CE_NeutralLobby,
	CE_NeutralCave,
	CE_NeutralTransporter,
	CE_HeroLobby,
	CE_HeroTransporter,
	CE_DarkLobby,
	CE_DarkTransporter,
	CE_CaveNeutral,
	CE_CaveRace,
	CE_CaveKarate,
	CE_RaceCave,
	CE_KarateCave,
	CE_TransporterOut,
	CE_KindergartenLobby = 0x13,
};


class ChaoGardenManager
{
public:
	static ChaoGardenManager& GetInstance()
	{
		static ChaoGardenManager instance;
		return instance;
	}

	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();
	void OnInputFunction();

	void SetChaoEnabled(bool chaoEnabled);
	void SetChaoRaceEnabled(bool chaoRaceEnabled);
	void SetChaoKarateEnabled(bool chaoKarateEnabled);
	void SetChaoStatsEnabled(int chaoStatsEnabled);
	void SetChaoBodyPartsEnabled(bool chaoBodyPartsEnabled);
	void SetChaoKindergartenEnabled(bool chaoKindergartenEnabled);
	void SetBlackMarketSlots(int blackMarketSlots);

	void SetBlackMarketData(std::map<int, int> map);

	void SetDefaultEggMap(std::map<int, int> map);
	void SetDefaultChaoNameMap(std::map<int, int> map);

	void SetChaoERData(std::map<int, int> map);

	int GetTimescale();

	void LoadAPTextures();
	void ReleaseAPTextures();

	ObjectMaster* apIconObjPtr;
	ModelIndex* apModelIndex;

private:
	void HandleBlackMarket();
	void HandleStartingEggs();
	void HandleSubsequentEggs();
	void HandleChaoER();

	const HelperFunctions* _helperFunctions;
	ArchipelagoManager* _archipelagoManager;

	unsigned int _timer = 0;

	unsigned int _timescale = 1;

	uint8_t _namesUsed = 4;

	bool _chaoEnabled = false;
	bool _chaoRaceEnabled = false;
	bool _chaoKarateEnabled = false;
	int _chaoStatsEnabled = 0;
	bool _chaoBodyPartsEnabled = false;
	bool _chaoKindergartenEnabled = false;
	int _blackMarketSlots = 0;
	
	std::map<int, int> _blackMarketData;

	std::map<int, int> _defaultEggMap;
	std::map<int, int> _defaultChaoNameMap;

	std::map<int, int> _chaoERData;

	//std::array<int, 10> _NameStringOffsets = { 0x227, 0x235, 0x244, 0x255, 0x265, 0x275, 0x285, 0x296, 0x2A7, 0x2BA };
	std::array<int, 10> _NameStringOffsets = { 0x195, 0x1B1, 0x1CF, 0x201, 0x21D, 0x255, 0x275, 0x296, 0x2BA, 0x2DE };
	std::array<int, 10> _NameStringIndeces = {   0x2,   0x5,   0x8,   0xC,   0xF,  0x13,  0x15,  0x17,  0x19,  0x1B };

	std::array<int, 10> _DescStringOffsets = { 0x619, 0x63B, 0x659, 0x68A, 0x6AD, 0x6C4, 0x6EB, 0x707, 0x73C, 0x757 };
	std::array<int, 10> _DescStringIndeces = {  0x50,  0x52,  0x54,  0x56,  0x58,  0x59,  0x5B,  0x5D,  0x5F,  0x60 };
};
