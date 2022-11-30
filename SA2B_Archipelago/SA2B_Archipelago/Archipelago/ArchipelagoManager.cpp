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
DataPointer(unsigned int, PlayerNameHash, 0x1DEC700);
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
    if (this->_badSaveFile || this->_badSaveName)
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

        if (*(int*)0x1DEC600 != 0)
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

            if (this->_settingsINI)
            {
                std::string playerName = this->_settingsINI->getString("AP", "PlayerName");
                std::size_t playerNameHash = std::hash<std::string>{}(playerName);

                if (PlayerNameHash == 0)
                {
                    PlayerNameHash = playerNameHash;

                    ProbablySavesSaveFile();
                }
                else
                {
                    if (PlayerNameHash != playerNameHash)
                    {
                        if (!this->_settingsINI->getBool("AP", "IgnoreFileSafety", false))
                        {
                            this->_badSaveName = true;

                            return;
                        }
                    }
                }
            }
        }
    }

    this->OnFrameDeathLink();

    this->OnFrameMessageQueue();
    this->OnFrameDebug();
}


void noop() {}

void SA2_ResetItems()
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->ResetItems();
}

void SA2_RecvItem(int64_t item_id, bool notify)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->ReceiveItem(item_id, notify);
}

void SA2_CheckLocation(int64_t loc_id)
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

void SA2_SetGoal(int goal)
{
    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetGoal(goal);
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

void SA2_SetNarrator(int narrator)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->SetNarrator(narrator);
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

void SA2_SetRequiredCannonsCoreMissions(int requirement)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetRequiredCannonsCoreMissions(requirement != 0);

    LocationManager* locationManager = &LocationManager::getInstance();

    locationManager->SetRequiredCannonsCoreMissions(requirement != 0);
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

void SA2_SetChaoKeys(int chaoKeys)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (chaoKeys != 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetChaoKeysEnabled(true);
    }
}

void SA2_SetPipes(int pipes)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    LocationManager* locationManager = &LocationManager::getInstance();
    if (pipes == 1)
    {
        locationManager->SetPipesEnabled(true);
    }
    else if (pipes == 2)
    {
        locationManager->SetHiddensEnabled(true);
    }
    else if (pipes == 3)
    {
        locationManager->SetPipesEnabled(true);
        locationManager->SetHiddensEnabled(true);
    }
}

void SA2_SetGoldBeetles(int goldBeetles)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (goldBeetles > 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetGoldBeetlesEnabled(true);
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

void SA2_SetChosenMissionsMap(std::map<int, int> map)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetChosenMissionsMap(map);
}

void SA2_SetMissionCountMap(std::map<int, int> map)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetMissionCountMap(map);
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
    AP_RegisterSlotDataIntCallback("Goal", &SA2_SetGoal);
    AP_RegisterSlotDataIntCallback("ModVersion", &SA2_CompareModVersion);
    AP_RegisterSlotDataMapIntIntCallback("MusicMap", &SA2_SetMusicMap);
    AP_RegisterSlotDataIntCallback("MusicShuffle", &SA2_SetMusicShuffle);
    AP_RegisterSlotDataIntCallback("Narrator", &SA2_SetNarrator);
    AP_RegisterSlotDataIntCallback("EmblemsForCannonsCore", &SA2_SetEmblemsForCannonsCore);
    AP_RegisterSlotDataIntCallback("RequiredCannonsCoreMissions", &SA2_SetRequiredCannonsCoreMissions);
    AP_RegisterSlotDataIntCallback("RequiredRank", &SA2_SetRequiredRank);
    AP_RegisterSlotDataIntCallback("ChaoKeys", &SA2_SetChaoKeys);
    AP_RegisterSlotDataIntCallback("Whistlesanity", &SA2_SetPipes);
    AP_RegisterSlotDataIntCallback("GoldBeetles", &SA2_SetGoldBeetles);
    AP_RegisterSlotDataIntCallback("ChaoRaceChecks", &SA2_SetChaoPacks);
    AP_RegisterSlotDataIntCallback("ChaoGardenDifficulty", &SA2_SetChaoDifficulty);
    AP_RegisterSlotDataMapIntIntCallback("RegionEmblemMap", &SA2_SetRegionEmblemMap);
    AP_RegisterSlotDataMapIntIntCallback("MissionMap", &SA2_SetChosenMissionsMap);
    AP_RegisterSlotDataMapIntIntCallback("MissionCountMap", &SA2_SetMissionCountMap);
    AP_RegisterSlotDataMapIntIntCallback("GateBosses", &SA2_SetGateBosses);
    AP_Start();
}

bool ArchipelagoManager::IsInit()
{
    return (AP_IsInit() && !this->_badSaveFile && !this->_badSaveName && !this->_badModVersion);
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

    AP_Message* msg = AP_GetLatestMessage();
    std::vector<std::string> outMsgs;
    if (msg)
    {
        switch (msg->type)
        {
        case (AP_MessageType::ItemSend):
        {
            AP_ItemSendMessage* sendMsg = static_cast<AP_ItemSendMessage*>(msg);

            if (sendMsg)
            {
                std::string outMsg = "Sent " + sendMsg->item + " to " + sendMsg->recvPlayer;
                outMsgs.push_back(outMsg);
            }
            break;
        }
        case (AP_MessageType::ItemRecv):
        {
            AP_ItemRecvMessage* recvMsg = static_cast<AP_ItemRecvMessage*>(msg);

            if (recvMsg)
            {
                std::string outMsg = "Received " + recvMsg->item + " from " + recvMsg->sendPlayer;
                outMsgs.push_back(outMsg);
            }
            break;
        }
        case (AP_MessageType::Hint):
        {
            AP_HintMessage* hintMsg = static_cast<AP_HintMessage*>(msg);

            if (hintMsg)
            {
                std::string foundText = hintMsg->checked ? " (found)" : " (not found)";
                std::string outMsg1 = hintMsg->recvPlayer + "'s " + hintMsg->item + " can be found at";
                std::string outMsg2 = "  " + hintMsg->location + " in " + hintMsg->sendPlayer + "'s world." + foundText;
                outMsgs.push_back(outMsg1);
                outMsgs.push_back(outMsg2);
            }
            break;
        }
        default:
        {
            std::string outMsg = msg->text;
        }
        }

        for (unsigned int i = 0; i < outMsgs.size(); i++)
        {
            messageQueue->AddMessage(outMsgs.at(i).c_str());
        }
    }
    AP_ClearLatestMessage();
}

void ArchipelagoManager::OnFrameDebug()
{
    if (!this->_settingsINI || !this->_settingsINI->getBool("AP", "DebugDisplayPositionXYZ", false))
    {
        return;
    }

    if (MainCharObj1[0])
    {
        std::string message = "X: ";
        message.append(std::to_string((int)floor(MainCharObj1[0]->Position.x)));
        message.append(" | Y: ");
        message.append(std::to_string((int)floor(MainCharObj1[0]->Position.y)));
        message.append(" | Z: ");
        message.append(std::to_string((int)floor(MainCharObj1[0]->Position.z)));
        int missionCountMessageXPos = ((HorizontalResolution / MessageQueue::GetInstance().GetFontSize()) - message.length());
        _helperFunctions->DisplayDebugString(NJM_LOCATION(missionCountMessageXPos, 1), message.c_str());
    }
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

void ArchipelagoManager::SetNarrator(int narrator)
{
    if (!this->IsInit())
    {
        return;
    }

    MusicManager* musicManager = &MusicManager::getInstance();

    musicManager->SetNarrator(narrator);
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
