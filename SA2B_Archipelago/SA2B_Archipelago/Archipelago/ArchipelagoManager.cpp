#include "../pch.h"
#include "ArchipelagoManager.h"
#include "../Locations/LocationData.h"
#include "../Items/ItemManager.h"
#include "../Locations/LocationManager.h"
#include "../Aesthetics/MusicManager.h"

#include "../Utilities/MessageQueue.h"
#include "../../lib/APCpp/Archipelago.h"

#include <functional>
#include "../Locations/StageSelectManager.h"
#include "../Aesthetics/StatsManager.h"


DataPointer(unsigned int, SeedHash, 0x1DEC6FC);
DataPointer(char, LastStoryComplete, 0x1DEFA95);

void ArchipelagoManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

    this->_settingsINI = new IniFile(std::string(path) + "\\config.ini");

    MessageQueue::GetInstance().SetFontSize(this->_settingsINI->getInt("General", "MessageFontSize"));
    MessageQueue::GetInstance().SetDisplayCount(this->_settingsINI->getInt("General", "MessageDisplayCount"));
    MessageQueue::GetInstance().SetDisplayDuration(this->_settingsINI->getFloat("General", "MessageDisplayDuration"));
}

void ArchipelagoManager::OnFrameFunction()
{
    if (this->_badSaveFile)
    {
        std::string msg1 = "Incorrect Save File Loaded.";
        std::string msg2 = "Relaunch game and load the correct save.";
        _helperFunctions->SetDebugFontColor(0xFFF542C8);
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 0), msg1.c_str());
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 1), msg2.c_str());

        return;
    }

    if (this->_badModVersion)
    {
        std::string msg1 = "Incorrect Mod Version.";
        std::string msg2 = "Local Version: ";
        msg2.append(std::to_string(MOD_VERSION / 100));
        msg2.append(".");
        msg2.append(std::to_string(MOD_VERSION % 100));
        msg2.append(" | Server Version: ");
        msg2.append(std::to_string(this->_serverModVersion / 100));
        msg2.append(".");
        msg2.append(std::to_string(this->_serverModVersion % 100));
        _helperFunctions->SetDebugFontColor(0xFFF542C8);
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 0), msg1.c_str());
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 1), msg2.c_str());

        return;
    }

    if (!this->IsInit())
    {
        std::string msg = "Load a Save File to Connect";
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
    else if (AP_GetConnectionStatus() != AP_ConnectionStatus::Authenticated)
    {
        std::string msg1 = "Connection to Archipelago lost.";
        std::string msg2 = "Reconnecting...";
        _helperFunctions->SetDebugFontColor(0xFFF542C8);
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 0), msg1.c_str());
        _helperFunctions->DisplayDebugString(NJM_LOCATION(0, 1), msg2.c_str());

        this->_authFailed = true;

        return;
    }

    this->_authFailed = false;

    this->_keepAliveTimer++;

    if (this->_keepAliveTimer >= KEEP_ALIVE)
    {
        this->_keepAliveTimer = 0;

        AP_KeepAlive();
    }

    AP_RoomInfo RoomInfo;
    AP_GetRoomInfo(&RoomInfo);

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
                        this->_badSaveFile = true;

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

void SA2_SetDeathLink(int deathLinkActive)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->SetDeathLink(deathLinkActive != 0);

    StatsManager* stats = &StatsManager::GetInstance();

    stats->DeathLinkActive(deathLinkActive != 0);
}

void SA2_CompareModVersion(int modVersion)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->VerfyModVersion(modVersion);
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

void SA2_SetMissionCount(int missionCount)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetMissionCount(missionCount);
}

void SA2_SetRequiredRank(int requiredRank)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    LocationManager* locationManager = &LocationManager::getInstance();

    locationManager->SetRequiredRank(requiredRank);

    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetRequiredRank(requiredRank);
}

void SA2_SetChaoPacks(int chaoRaceChecks)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (chaoRaceChecks == 1)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetRacesPacked(true);
    }
}

void SA2_SetChaoDifficulty(int chaoDifficulty)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (chaoDifficulty > 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetChaoEnabled(true);
    }
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

void SA2_SetGateBosses(std::map<int, int> map)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetBossGates(map);
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
    AP_RegisterSlotDataIntCallback("DeathLink", &SA2_SetDeathLink);
    AP_RegisterSlotDataIntCallback("ModVersion", &SA2_CompareModVersion);
    AP_RegisterSlotDataMapIntIntCallback("MusicMap", &SA2_SetMusicMap);
    AP_RegisterSlotDataIntCallback("MusicShuffle", &SA2_SetMusicShuffle);
    AP_RegisterSlotDataIntCallback("EmblemsForCannonsCore", &SA2_SetEmblemsForCannonsCore);
    AP_RegisterSlotDataIntCallback("IncludeMissions", &SA2_SetMissionCount);
    AP_RegisterSlotDataIntCallback("RequiredRank", &SA2_SetRequiredRank);
    AP_RegisterSlotDataIntCallback("ChaoRaceChecks", &SA2_SetChaoPacks);
    AP_RegisterSlotDataIntCallback("ChaoGardenDifficulty", &SA2_SetChaoDifficulty);
    AP_RegisterSlotDataMapIntIntCallback("RegionEmblemMap", &SA2_SetRegionEmblemMap);
    AP_RegisterSlotDataMapIntIntCallback("GateBosses", &SA2_SetGateBosses);
    AP_Start();
}

bool ArchipelagoManager::IsInit()
{
    return (AP_IsInit() && !this->_badSaveFile && !this->_badModVersion);
}

bool ArchipelagoManager::IsAuth()
{
    return !this->_authFailed;
}

void ArchipelagoManager::SendStoryComplete()
{
    StatsManager::GetInstance().Victory();
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
        if ((TimerStopped == 0 || GameState != GameStates::GameStates_Ingame) && GameState != GameStates::GameStates_Pause)
        {
            this->_deathLinkTimer--;
        }

        return;
    }

    if (this->DeathLinkPending() && GameState == GameStates::GameStates_Ingame) // They died
    {
        if (CurrentLevel == LevelIDs::LevelIDs_Route101280)
        {
            if (!TimerStopped)
            {
                GameState = GameStates::GameStates_RestartLevel_1;
            }
        }
        else
        {
            KillPlayer(0);
            if (CurrentCharacter == Characters_MechTails || CurrentCharacter == Characters_MechEggman)
            {
                if (MainCharObj2[0] != NULL && MainCharObj1[0] != NULL)
                {
                    MainCharObj2[0]->Powerups = (MainCharObj2[0]->Powerups & ~(1 << PowerupBits::PowerupBits_Barrier));
                    MainCharObj2[0]->Powerups = (MainCharObj2[0]->Powerups & ~(1 << PowerupBits::PowerupBits_MagneticBarrier));
                    MainCharObj2[0]->Powerups = (MainCharObj2[0]->Powerups & ~(1 << PowerupBits::PowerupBits_Invincibility));
                    MainCharObj2[0]->MechHP = 0;
                    MainCharObj1[0]->field_6 = 0; // Invulvnerability Frames
                    MainCharObj1[0]->Status |= Status_Hurt;
                }
            }
        }

        this->_deathLinkTimer = 420;

        this->DeathLinkClear();
    }
    else if (!this->DeathLinkPending() &&
             CurrentLevel == LevelIDs::LevelIDs_Route101280 &&
             GameState == GameStates::GameStates_RestartLevel_1) // We Died, Car Flavored
    {
        this->DeathLinkSend();

        this->_deathLinkTimer = 420;
    }
    else if (!this->DeathLinkPending() && 
             MainCharObj1[0] != NULL && 
             MainCharObj2[0] != NULL)
    {
        if (MainCharObj1[0]->Action == Action_Death ||
            MainCharObj1[0]->Action == Action_Drown ||
            (MainCharObj1[0]->Action == Action_Quicksand && CurrentLevel != LevelIDs_EggGolemS) ||
            (MainCharObj2[0]->Powerups & (1 << PowerupBits::PowerupBits_Dead))) // We Died
        {
            this->DeathLinkSend();

            this->_deathLinkTimer = 420;
        }
    }
}

void ArchipelagoManager::DeathLinkSend() 
{
    StatsManager::GetInstance().DeathLinkSent();
    if (!this->_deathLinkActive)
    {
        return;
    }
    AP_DeathLinkSend();
    MessageQueue::GetInstance().AddMessage(std::string("Death Sent"));
}

bool ArchipelagoManager::DeathLinkPending() 
{
    return AP_DeathLinkPending();
}

void ArchipelagoManager::DeathLinkClear() 
{
    StatsManager::GetInstance().DeathLinkReceived();
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
    if (!this->IsInit())
    {
        return;
    }

    ItemManager* itemManager = &ItemManager::getInstance();

    itemManager->ResetItems();

    LocationManager* locationManager = &LocationManager::getInstance();

    locationManager->ResetLocations();
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
    if (!this->IsInit())
    {
        return;
    }

    LocationManager* locationManager = &LocationManager::getInstance();

    locationManager->CheckLocation(loc_id - AP_ID_OFFSET);
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

void ArchipelagoManager::SetDeathLink(bool deathLinkActive)
{
    this->_deathLinkActive = deathLinkActive;
}

void ArchipelagoManager::VerfyModVersion(int modVersion)
{
    if (modVersion != MOD_VERSION)
    {
        this->_badModVersion = true;
        this->_serverModVersion = modVersion;
    }
}
