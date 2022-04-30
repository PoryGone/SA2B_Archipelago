#include "../pch.h"
#include "ArchipelagoManager.h"
#include "../Locations/LocationData.h"
#include "../Items/ItemManager.h"
#include "../Aesthetics/MusicManager.h"

#include "../Utilities/MessageQueue.h"
#include "../../lib/APCpp/Archipelago.h"

#include <functional>
#include "../Locations/StageSelectManager.h"


DataPointer(unsigned int, SeedHash, 0x1DEC6FC);
DataPointer(char, LastStoryComplete, 0x1DEFA95);

DataPointer(char, SavedChecksSent, 0x1DEF5DA);

void ArchipelagoManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

    this->_settingsINI = new IniFile(std::string(path) + "\\config.ini");

    this->_thisSessionChecksSent = 0;
}

void ArchipelagoManager::OnFrameFunction()
{
    if (this->_connectionRejected)
    {
        std::string msg1 = "Incorrect Save File Loaded.";
        std::string msg2 = "Relaunch game and load the correct save.";
        _helperFunctions->SetDebugFontColor(0xFFF542C8);
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 0), msg1.c_str());
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 1), msg2.c_str());

        return;
    }

    if (!this->IsInit())
    {
        std::string msg = "Not Connected";
        _helperFunctions->SetDebugFontColor(0xFFF542C8);
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 0), msg.c_str());

        if (*(char*)0x1DEC600 != 0)
        {
            if (this->_settingsINI)
            {
                std::string serverIP = this->_settingsINI->getString("AP", "IP");
                std::string playerName = this->_settingsINI->getString("AP", "PlayerName");
                std::string serverPassword = this->_settingsINI->getString("AP", "Password");

                this->Init(serverIP.c_str(), playerName.c_str(), serverPassword.c_str());

            }
            else
            {
                std::string msg2 = "Invalid Settings INI";
                _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 1), msg2.c_str());

                return;
            }
        }
        else
        {
            return;
        }
    }

    AP_RoomInfo RoomInfo;
    this->_authFailed = (AP_GetRoomInfo(&RoomInfo) == 1);

    if (this->_authFailed)
    {
        std::string msg = "Connection Failed";
        std::string msg2 = "Verify server connection and try again.";
        _helperFunctions->SetDebugFontColor(0xFFF542C8);
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 0), msg.c_str());
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 1), msg2.c_str());

        return;
    }

    if (this->_seedName.length() == 0)
    {
        if (RoomInfo.seed_name.length() != 0)
        {
            this->_seedName = RoomInfo.seed_name;

            std::size_t seedHash = std::hash<std::string>{}(this->_seedName);

            if (SeedHash == 0)
            {
                SeedHash = seedHash;

                ProbablySavesSaveFile();
            }
            else
            {
                if (SeedHash != seedHash)
                {
                    if (!this->_settingsINI || !this->_settingsINI->getBool("AP", "IgnoreFileSafety", false))
                    {
                        this->_connectionRejected = true;

                        return;
                    }
                }
            }
        }
    }

    if (CurrentLevel == LevelIDs_FinalHazard)
    {
        if (GameState == GameStates_GoToNextLevel)
        {
            MessageQueue* messageQueue = &MessageQueue::GetInstance();
            std::string msg = "Victory!";
            messageQueue->AddMessage(msg);

            this->SendStoryComplete();
        }
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

void SA2_SetMusicMap(std::map<int, int> map) 
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->SetMusicMap(map);
}

void SA2_SetMusicShuffle(int shuffleType)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->SetMusicShuffle(shuffleType);
}

void SA2_SetEmblemsForCannonsCore(int emblemsRequired)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetEmblemsForCannonsCore(emblemsRequired);
}

void SA2_SetRegionEmblemMap(std::map<int, int> map)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetRegionEmblemMap(map);
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
    AP_RegisterSlotDataMapIntIntCallback("MusicMap", &SA2_SetMusicMap);
    AP_RegisterSlotDataIntCallback("MusicShuffle", &SA2_SetMusicShuffle);
    AP_RegisterSlotDataIntCallback("EmblemsForCannonsCore", &SA2_SetEmblemsForCannonsCore);
    AP_RegisterSlotDataMapIntIntCallback("RegionEmblemMap", &SA2_SetRegionEmblemMap);
    AP_Start();
}

bool ArchipelagoManager::IsInit()
{
    return (AP_IsInit() && !this->_connectionRejected);
}

bool ArchipelagoManager::IsAuth()
{
    return !this->_authFailed;
}

void ArchipelagoManager::SendStoryComplete()
{
    AP_StoryComplete();
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

        this->_deathLinkTimer = 420;

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

            this->_deathLinkTimer = 420;
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

    this->_thisSessionChecksSent++;
    if (this->_thisSessionChecksSent > SavedChecksSent)
    {
        SavedChecksSent = this->_thisSessionChecksSent;
        // Send Message
    }

    int ap_index = index + AP_ID_OFFSET;
    AP_SendItem(ap_index);
}

void ArchipelagoManager::ResetItems()
{
    if (!this->IsInit())
    {
        return;
    }

    ItemManager* itemManager = &ItemManager::getInstance();

    itemManager->ResetItems();
}

void ArchipelagoManager::ReceiveItem(int item_id, bool notify)
{
    if (!this->IsInit())
    {
        return;
    }

    ItemManager* itemManager = &ItemManager::getInstance();

    itemManager->ReceiveItem(item_id, notify);
}

void ArchipelagoManager::CheckLocation(int loc_id)
{

}

void ArchipelagoManager::SetMusicMap(std::map<int, int> map)
{
    if (!this->IsInit())
    {
        return;
    }

    MusicManager* musicManager = &MusicManager::getInstance();

    musicManager->SetMusicMap(map);
}

void ArchipelagoManager::SetMusicShuffle(int shuffleType)
{
    if (!this->IsInit())
    {
        return;
    }

    MusicManager* musicManager = &MusicManager::getInstance();

    musicManager->SetMusicShuffle(shuffleType);
}
