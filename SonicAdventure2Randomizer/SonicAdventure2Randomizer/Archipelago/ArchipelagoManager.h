#include "../pch.h"
#pragma once

#include "../ModloaderCommon/IniFile.hpp"

#include <map>

constexpr unsigned int AP_ID_OFFSET = 0xFF0000;

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

private:
	const HelperFunctions* _helperFunctions;
	const IniFile* _settingsINI;

	int _deathLinkTimer = 0;
	std::string _seedName;

	bool _authFailed = false;
	bool _connectionRejected = false;

	bool _completionSent = false;

	void Init(const char* ip, const char* playerName, const char* password);
	void OnFrameMessageQueue();

	// DeathLink functions
	void OnFrameDeathLink();
	void DeathLinkSend();
	bool DeathLinkPending();
	void DeathLinkClear();
};