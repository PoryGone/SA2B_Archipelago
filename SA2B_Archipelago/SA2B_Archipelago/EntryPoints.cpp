#include "pch.h"
#include "Utilities/MessageQueue.h"
#include "Items/ItemManager.h"
#include "Locations/LocationManager.h"
#include "Locations/StageSelectManager.h"
#include "Archipelago/ArchipelagoManager.h"
#include "Aesthetics/MusicManager.h"
#include "Aesthetics/CreditsManager.h"
#include "Aesthetics/StatsManager.h"


ItemManager* _itemManager;
LocationManager* _locationManager;
MusicManager* _musicManager;
ArchipelagoManager* _archipelagoManager;
CreditsManager& _creditsManager = CreditsManager::GetInstance();
StageSelectManager& _stageSelectManager = StageSelectManager::GetInstance();
MessageQueue& _messageQueue = MessageQueue::GetInstance();
StatsManager& _statsManager = StatsManager::GetInstance();

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.
		_messageQueue.OnInitFunction(path, helperFunctions);

		_stageSelectManager.OnInitFunction(path, helperFunctions);

		_itemManager = &ItemManager::getInstance();
		_itemManager->OnInitFunction(path, helperFunctions);

		_musicManager = &MusicManager::getInstance();
		_musicManager->OnInitFunction(path, helperFunctions);

		_creditsManager.OnInitFunction(path, helperFunctions);

		_archipelagoManager = &ArchipelagoManager::getInstance();
		_archipelagoManager->OnInitFunction(path, helperFunctions);

		_locationManager = &LocationManager::getInstance();
		_locationManager->OnInitFunction(path, helperFunctions);

		_statsManager.OnInitFunction(path, helperFunctions);

	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SA2
		if (_itemManager)
		{
			_itemManager->OnFrameFunction();
		}

		if (_archipelagoManager)
		{
			_archipelagoManager->OnFrameFunction();
		}

		if (_locationManager)
		{
			_locationManager->OnFrameFunction();
		}

		_stageSelectManager.OnFrameFunction();

		_messageQueue.OnFrameFunction();

		_statsManager.OnFrameFunction();
	}

	__declspec(dllexport) void __cdecl OnInput()
	{
		// Executed before the game processes input
	}

	__declspec(dllexport) void __cdecl OnControl()
	{
		// Executed when the game processes input
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}