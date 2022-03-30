#include "../pch.h"
#include "ArchipelagoManager.h"
#include "../Locations/LocationData.h"
#include "../Items/ItemManager.h"

#include "../Utilities/MessageQueue.h"
#include "../../lib/APCpp/Archipelago.h"

#include <map>
#include "../ModloaderCommon/IniFile.hpp"


void ArchipelagoManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

    const IniFile* settings = new IniFile(std::string(path) + "\\config.ini");

    if (settings)
    {
        std::string serverIP        = settings->getString("AP", "IP");
        std::string playerName      = settings->getString("AP", "PlayerName");
        std::string serverPassword  = settings->getString("AP", "Password");

        this->Init(serverIP.c_str(), playerName.c_str(), serverPassword.c_str());
    }
}

void ArchipelagoManager::OnFrameFunction()
{
    if (!this->IsInit())
    {
        return;
    }

    this->OnFrameDeathLink();

    this->OnFrameMessageQueue();
}


void noop() {}

void SA2_ResetItems()
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->ResetItems();
}

void SA2_RecvItem(int item_id, bool notify)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->ReceiveItem(item_id, notify);
}

void SA2_CheckLocation(int loc_id)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->CheckLocation(loc_id);
}

void ArchipelagoManager::Init(const char* ip, const char* playerName, const char* password)
{
    AP_Init(ip, "Sonic Adventure 2 Battle", playerName, password);

    AP_SetDeathLinkSupported(true);
    AP_EnableQueueItemRecvMsgs(false);
    AP_SetItemClearCallback(&SA2_ResetItems);
    AP_SetItemRecvCallback(&SA2_RecvItem);
    AP_SetLocationCheckedCallback(&SA2_CheckLocation);
    AP_SetDeathLinkRecvCallback(&noop);
    AP_Start();
}

bool ArchipelagoManager::IsInit()
{
    return AP_IsInit();
}

void ArchipelagoManager::OnFrameMessageQueue()
{
    if (!AP_IsMessagePending())
    {
        return;
    }

    MessageQueue* messageQueue = &MessageQueue::GetInstance();
    std::vector<std::string> msg = AP_GetLatestMessage();
    for (unsigned int i = 0; i < msg.size(); i++)
    {
        messageQueue->AddMessage(msg.at(i));
    }
    AP_ClearLatestMessage();
}

// DeathLink Functions
void ArchipelagoManager::OnFrameDeathLink()
{
    if (this->_deathLinkTimer > 0)
    {
        this->_deathLinkTimer--;

        return;
    }

    if (this->DeathLinkPending() && GameState == GameStates::GameStates_Ingame) // They died
    {
        KillPlayer(0);
        if (CurrentCharacter == Characters_MechTails || CurrentCharacter == Characters_MechEggman)
        {
            if (MainCharObj2[0] != NULL && MainCharObj1[0] != NULL)
            {
                MainCharObj2[0]->MechHP = 0;
                MainCharObj1[0]->Status |= Status_Hurt;
            }
        }

        this->_deathLinkTimer = 200;

        this->DeathLinkClear();
    }
    else if (!this->DeathLinkPending() && 
             MainCharObj1[0] != NULL && 
             MainCharObj2[0] != NULL)
    {
        if (MainCharObj1[0]->Action == Action_Death ||
            MainCharObj1[0]->Action == Action_Drown ||
            MainCharObj1[0]->Action == Action_Quicksand ||
            (MainCharObj2[0]->Powerups & (1 << PowerupBits::PowerupBits_Dead))) // We Died
        {
            this->DeathLinkSend();

            this->_deathLinkTimer = 200;
        }
    }
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

// Item Functions
void ArchipelagoManager::SendItem(int index)
{
    if (!this->IsInit())
    {
        return;
    }

    int ap_index = index + AP_ID_OFFSET;
    AP_SendItem(ap_index);
}

void ArchipelagoManager::ResetItems()
{

}

void ArchipelagoManager::ReceiveItem(int item_id, bool notify)
{
    ItemManager* itemManager = &ItemManager::getInstance();

    itemManager->ReceiveItem(item_id, notify);
}

void ArchipelagoManager::CheckLocation(int loc_id)
{

}
