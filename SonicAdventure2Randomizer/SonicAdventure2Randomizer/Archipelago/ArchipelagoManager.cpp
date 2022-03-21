#include "../pch.h"
#include "ArchipelagoManager.h"
#include "../Locations/LocationData.h"

#include "../../lib/APCpp/Archipelago.h"

#include <map>
#include <fstream>


void ArchipelagoManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

    std::ifstream modFile;
    std::string ppath = path;
    modFile.open((ppath + "\\mod.ini").c_str());
}

void ArchipelagoManager::OnFrameFunction()
{
    if (this->DeathLinkPending() && GameState == GameStates::GameStates_Ingame) // They died
    {
        KillPlayer(0);

        this->DeathLinkClear();
    }
    else if (!this->DeathLinkPending() && MainCharObj1[0] != NULL && MainCharObj1[0]->Action == Action_Death) // We Died
    {
        this->DeathLinkSend();
    }
}

void ArchipelagoManager::OnInputFunction()
{

}

void ArchipelagoManager::OnControlFunction()
{

}


void ArchipelagoManager::DeathLinkSend() 
{
    AP_DeathLinkSend();
}

bool ArchipelagoManager::DeathLinkPending() 
{
    return AP_DeathLinkPending();
}

void ArchipelagoManager::DeathLinkClear() 
{
    AP_DeathLinkClear();
}