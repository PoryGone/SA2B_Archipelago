#include "../pch.h"
#pragma once

#include "../ModloaderCommon/IniFile.hpp"

#include <map>

constexpr unsigned int AP_ID_OFFSET = 0xFF0000;
constexpr int MOD_VERSION = 101;

constexpr int KEEP_ALIVE = 3600;

class ArchipelagoManager
{
public:
	static ArchipelagoManager& getInstance()
	{
		static ArchipelagoManager instance;
		return instance;
	}

	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();

	bool IsInit();
	bool IsAuth();

	void SendStoryComplete();

	// Item Functions
	void SendItem(int index);
	void ResetItems();
	void ReceiveItem(int item_id, bool notify);
	void CheckLocation(int loc_id);

	void SetMusicMap(std::map<int, int> map);
	void SetMusicShuffle(int shuffleType);
	void SetDeathLink(bool deathLinkActive);
	void VerfyModVersion(int modVersion);

	std::string GetSeedName() { return this->_seedName; };

private:
	const HelperFunctions* _helperFunctions;
	const IniFile* _settingsINI;

	int _keepAliveTimer = 0;

	int _deathLinkTimer = 0;
	bool _deathLinkActive = false;

	std::string _seedName;

	bool _authFailed = false;
	bool _badSaveFile = false;
	bool _badSaveName = false;
	bool _badModVersion = false;

	int _serverModVersion = 0;

	bool _completionSent = false;

	void Init(const char* ip, const char* playerName, const char* password);
	void OnFrameMessageQueue();
	void OnFrameDebug();

	// DeathLink functions
	void OnFrameDeathLink();
	void DeathLinkSend();
	bool DeathLinkPending();
	void DeathLinkClear();
};