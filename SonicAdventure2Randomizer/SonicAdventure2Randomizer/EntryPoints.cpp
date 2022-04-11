#include "pch.h"
#include "Items/Emblems.h"
#include "Items/ItemManager.h"
#include "Locations/LocationManager.h"
#include "Locations/StageSelectManager.h"
#include "Archipelago/ArchipelagoManager.h"
#include "Aesthetics/MusicManager.h"


EmblemManager* _emblemManager;
ItemManager* _itemManager;
LocationManager* _locationManager;
StageSelectManager* _stageSelectManager;
MusicManager* _musicManager;
ArchipelagoManager* _archipelagoManager;
MessageQueue& _messageQueue = MessageQueue::GetInstance();

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.
		_messageQueue.OnInitFunction(path, helperFunctions);

		_emblemManager = new EmblemManager();
		_emblemManager->OnInitFunction(path, helperFunctions);

		_itemManager = &ItemManager::getInstance();
		_itemManager->OnInitFunction(path, helperFunctions);

		_musicManager = &MusicManager::getInstance();
		_musicManager->OnInitFunction(path, helperFunctions);

		_stageSelectManager = new StageSelectManager();
		_stageSelectManager->OnInitFunction(path, helperFunctions);

		_archipelagoManager = &ArchipelagoManager::getInstance();
		_archipelagoManager->OnInitFunction(path, helperFunctions);

		_locationManager = new LocationManager();
		_locationManager->OnInitFunction(path, helperFunctions);
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SA2
		if (_emblemManager)
		{
			_emblemManager->OnFrameFunction();
		}

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

		if (_stageSelectManager)
		{
			_stageSelectManager->OnFrameFunction();
		}

		_messageQueue.OnFrameFunction();
	}

	__declspec(dllexport) void __cdecl OnInput()
	{
		// Executed before the game processes input
		if (_emblemManager)
		{
			_emblemManager->OnInputFunction();
		}
	}

	__declspec(dllexport) void __cdecl OnControl()
	{
		// Executed when the game processes input
		if (_emblemManager)
		{
			_emblemManager->OnControlFunction();
		}
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}