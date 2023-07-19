#include "../pch.h"
#include "ArchipelagoManager.h"
#include "../Locations/LocationData.h"
#include "../Items/ItemManager.h"
#include "../Items/Minigames/MinigameManager.h"
#include "../Locations/ChaoGardenManager.h"
#include "../Locations/LocationManager.h"
#include "../Aesthetics/MusicManager.h"

#include "../Utilities/MessageQueue.h"
#include "../../lib/APCpp/Archipelago.h"
#include "../../lib/APCpp/json/reader.h"
#include "../../lib/APCpp/json/writer.h"

#include <chrono>
#include <functional>
#include "../Locations/StageSelectManager.h"
#include "../Aesthetics/StatsManager.h"


DataPointer(unsigned int, SeedHash, 0x1DEC6FC);
DataPointer(unsigned int, PlayerNameHash, 0x1DEC700);
DataPointer(char, LastStoryComplete, 0x1DEFA95);


unsigned int CalcHash(std::string str)
{
    // DJB2 Hash Algorithm
    unsigned long hash = 5381;
    unsigned int str_len = str.length();

    for (int c = 0; c < str_len; c++)
    {
        hash = ((hash << 5) + hash) + (int)str[c]; /* hash * 33 + c */
    }

    return hash;
}

static void __cdecl HandleRingLoss()
{
    __asm
    {
        movzx edx, word ptr[eax * 2 + 174B028h]
        cmp edx, 14h
        ja greater
        ret
    greater:
        mov edx, 20
    }
}

static void __cdecl HandleOHKO()
{
    __asm
    {
        push eax
    }

    if (CurrentLevel == LevelIDs::LevelIDs_SonicVsShadow1 ||
        CurrentLevel == LevelIDs::LevelIDs_SonicVsShadow2 ||
        CurrentLevel == LevelIDs::LevelIDs_TailsVsEggman1 ||
        CurrentLevel == LevelIDs::LevelIDs_TailsVsEggman2 ||
        CurrentLevel == LevelIDs::LevelIDs_KnucklesVsRouge)
    {
        // Hitting them kills you lol
    }
    else
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
     }

    __asm
    {
        pop eax
        movzx edx, word ptr[eax * 2 + 174B028h]
    }
}

void ArchipelagoManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

    this->_settingsINI = new IniFile(std::string(path) + "\\config.ini");

    MessageQueue::GetInstance().SetFontSize(this->_settingsINI->getInt("General", "MessageFontSize"));
    MessageQueue::GetInstance().SetDisplayCount(this->_settingsINI->getInt("General", "MessageDisplayCount"));
    MessageQueue::GetInstance().SetDisplayDuration(this->_settingsINI->getFloat("General", "MessageDisplayDuration"));

    int textRed   = this->_settingsINI->getInt("General", "MessageColorR");
    int textGreen = this->_settingsINI->getInt("General", "MessageColorG");
    int textBlue  = this->_settingsINI->getInt("General", "MessageColorB");

    int textColor = 0xFF000000 + (textRed * 0x10000) + (textGreen * 0x100) + (textBlue * 0x1);
    MessageQueue::GetInstance().SetDisplayColor(textColor);

    std::chrono::time_point<std::chrono::system_clock> timestamp = std::chrono::system_clock::now();
    this->_instanceID = std::chrono::duration_cast<std::chrono::seconds>(timestamp.time_since_epoch()).count();
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

                this->ap_player_name = playerName;
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

            unsigned int seedHash = CalcHash(this->_seedName);

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

                unsigned int playerNameHash = CalcHash(playerName);

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
    this->OnFrameRingLink();

    this->OnFrameMessageQueue();
    this->OnFrameDebug();
}


void noop() {}

void SA2_HandleBouncedPacket(AP_Bounce bouncePacket)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    Json::Value bounceData;
    Json::Reader reader;
    reader.parse(bouncePacket.data, bounceData);

    if (bouncePacket.tags == nullptr)
    {
        return;
    }

    for (unsigned int i = 0; i < bouncePacket.tags->size(); i++)
    {
        if ((*bouncePacket.tags)[i].length() == 0)
        {
            return;
        }

        if (!strcmp((*bouncePacket.tags)[i].c_str(), "DeathLink"))
        {
            if (!apm->_deathLinkActive)
            {
                return;
            }

            if (!strcmp(bounceData["source"].asCString(), apm->ap_player_name.c_str()) &&
                (bounceData["time"].asInt64() == apm->lastDeathLinkTime))
            {
                // This is the packet we just sent
                apm->lastDeathLinkTime = 0;
                break;
            }

            if (!bounceData["cause"].isNull())
            {
                apm->receivedDeathCause = std::string(bounceData["cause"].asCString());
            }
            else
            {
                apm->receivedDeathCause = std::string("You were killed by ") + bounceData["source"].asCString();
            }
            apm->_deathLinkPending = true;
            break;
        }
        else if (!strcmp((*bouncePacket.tags)[i].c_str(), "RingLink"))
        {
            if (!apm->_ringLinkActive)
            {
                return;
            }

            if (GameState != GameStates::GameStates_Ingame)
            {
                // We cannot deal with this currently
                return;
            }

            if (CurrentLevel == LevelIDs_FinalHazard)
            {
                return;
            }

            if (bounceData["source"].asInt() != apm->_instanceID)
            {
                // We didn't send this one
                __int16 amount = bounceData["amount"].asInt();

                if (amount == 0)
                {
                    return;
                }
                else if (amount < 0 && RingCount[0] > 0)
                {
                    PlaySoundProbably(RING_LOSS_SOUND, 0, 0, 0);
                }
                else if (amount > 0 && RingCount[0] < 999)
                {
                    PlaySoundProbably(RING_GAIN_SOUND, 0, 0, 0);
                }

                __int16 newAmount = max(min(RingCount[0] + amount, 999), 0);
                __int16 realDiff = newAmount - RingCount[0];

                RingCount[0] = newAmount;
                //AddRings(0, realDiff); // Maybe have to use this function

                // Make sure you don't re-link out your received link
                apm->_lastSentRingCount += realDiff;
            }
        }
    }
}

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

void SA2_SetVoiceMap(std::map<int, int> map)
{
    MusicManager* musicManager = &MusicManager::getInstance();

    musicManager->SetVoiceMap(map);
}

void SA2_SetDeathLink(int deathLinkActive)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->SetDeathLink(deathLinkActive != 0);

    StatsManager* stats = &StatsManager::GetInstance();

    stats->DeathLinkActive(deathLinkActive != 0);
}

void SA2_SetRingLink(int ringLinkActive)
{
    ArchipelagoManager* apm = &ArchipelagoManager::getInstance();

    apm->SetRingLink(ringLinkActive != 0);
}

void SA2_SetGoal(int goal)
{
    // Best place to detect we've connected
    MessageQueue* messageQueue = &MessageQueue::GetInstance();
    messageQueue->AddMessage("Connected to Archipelago");

    LocationManager* locationManager = &LocationManager::getInstance();

    locationManager->SetGoal(goal);

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

void SA2_SetRingLoss(int ringLoss)
{
    if (ringLoss == 1)
    {
        WriteCall(static_cast<void*>((void*)0x6C1B0D), &HandleRingLoss);
        WriteData<3>((void*)0x6C1B12, 0x90);
    }
    else if (ringLoss == 2)
    {
        WriteCall(static_cast<void*>((void*)0x6C1B0D), &HandleOHKO);
        WriteData<3>((void*)0x6C1B12, 0x90);
    }
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

void SA2_SetChaoRaceDifficulty(int chaoDifficulty)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (chaoDifficulty > 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetChaoRaceEnabled(true);

        ChaoGardenManager* chaoGardenManager = &ChaoGardenManager::GetInstance();

        chaoGardenManager->SetChaoRaceEnabled(chaoDifficulty);
    }
}

void SA2_SetChaoKarateDifficulty(int chaoDifficulty)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (chaoDifficulty > 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetChaoKarateEnabled(true);

        ChaoGardenManager* chaoGardenManager = &ChaoGardenManager::GetInstance();

        chaoGardenManager->SetChaoKarateEnabled(chaoDifficulty);
    }
}

void SA2_SetChaoStats(int chaoStats)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (chaoStats > 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetChaoStatsEnabled(chaoStats);

        ChaoGardenManager* chaoGardenManager = &ChaoGardenManager::GetInstance();

        chaoGardenManager->SetChaoStatsEnabled(chaoStats);
    }
}

void SA2_SetChaoBodyParts(int chaoBodyParts)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (chaoBodyParts > 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetChaoBodyPartsEnabled(true);

        ChaoGardenManager* chaoGardenManager = &ChaoGardenManager::GetInstance();

        chaoGardenManager->SetChaoBodyPartsEnabled(true);
    }
}

void SA2_SetChaoKindergarten(int chaoKindergarten)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (chaoKindergarten > 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetChaoKindergartenEnabled(true);

        ChaoGardenManager* chaoGardenManager = &ChaoGardenManager::GetInstance();

        chaoGardenManager->SetChaoKindergartenEnabled(true);
    }
}

void SA2_SetDefaultEggMap(std::map<int, int> map)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    ChaoGardenManager* chaoGardenManager = &ChaoGardenManager::GetInstance();

    chaoGardenManager->SetDefaultEggMap(map);
}

void SA2_SetDefaultChaoNameMap(std::map<int, int> map)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    ChaoGardenManager* chaoGardenManager = &ChaoGardenManager::GetInstance();

    chaoGardenManager->SetDefaultChaoNameMap(map);
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

void SA2_SetOmochaoChecks(int omochaoChecks)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (omochaoChecks > 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetOmochaoEnabled(true);
    }
}

void SA2_SetAnimalChecks(int animalChecks)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    if (animalChecks > 0)
    {
        LocationManager* locationManager = &LocationManager::getInstance();

        locationManager->SetAnimalsEnabled(true);
    }
}

void SA2_SetKartRaceChecks(int kartRaceChecks)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    LocationManager* locationManager = &LocationManager::getInstance();

    locationManager->SetKartRacesEnabled(kartRaceChecks);

    StageSelectManager* stageSelectManager = &StageSelectManager::GetInstance();

    stageSelectManager->SetKartRacesEnabled(kartRaceChecks);
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

void SA2_SetChosenBossRushMap(std::map<int, int> map)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    StageSelectManager* ssm = &StageSelectManager::GetInstance();

    ssm->SetChosenBossRushMap(map);
}

void SA2_SetMinigameDifficulty(int minigameDifficulty)
{
    if (!ArchipelagoManager::getInstance().IsInit())
    {
        return;
    }

    MinigameManager* minigameManager = &MinigameManager::GetInstance();

    minigameManager->SetDifficulty(minigameDifficulty);
}

void ArchipelagoManager::Init(const char* ip, const char* playerName, const char* password)
{
    AP_Init(ip, "Sonic Adventure 2 Battle", playerName, password);

    AP_NetworkVersion net_ver;
    net_ver.major = 0;
    net_ver.minor = 3;
    net_ver.build = 7;

    AP_SetDeathLinkSupported(true);
    AP_SetClientVersion(&net_ver);
    AP_EnableQueueItemRecvMsgs(false);
    AP_SetItemClearCallback(&SA2_ResetItems);
    AP_SetItemRecvCallback(&SA2_RecvItem);
    AP_SetLocationCheckedCallback(&SA2_CheckLocation);
    AP_SetDeathLinkRecvCallback(&noop);
    AP_RegisterBouncedCallback(&SA2_HandleBouncedPacket);
    AP_RegisterSlotDataIntCallback("DeathLink", &SA2_SetDeathLink);
    AP_RegisterSlotDataIntCallback("RingLink", &SA2_SetRingLink);
    AP_RegisterSlotDataIntCallback("Goal", &SA2_SetGoal);
    AP_RegisterSlotDataIntCallback("ModVersion", &SA2_CompareModVersion);
    AP_RegisterSlotDataMapIntIntCallback("MusicMap", &SA2_SetMusicMap);
    AP_RegisterSlotDataMapIntIntCallback("VoiceMap", &SA2_SetVoiceMap);
    AP_RegisterSlotDataIntCallback("MusicShuffle", &SA2_SetMusicShuffle);
    AP_RegisterSlotDataIntCallback("Narrator", &SA2_SetNarrator);
    AP_RegisterSlotDataIntCallback("RingLoss", &SA2_SetRingLoss);
    AP_RegisterSlotDataIntCallback("EmblemsForCannonsCore", &SA2_SetEmblemsForCannonsCore);
    AP_RegisterSlotDataIntCallback("RequiredCannonsCoreMissions", &SA2_SetRequiredCannonsCoreMissions);
    AP_RegisterSlotDataIntCallback("RequiredRank", &SA2_SetRequiredRank);
    AP_RegisterSlotDataIntCallback("ChaoKeys", &SA2_SetChaoKeys);
    AP_RegisterSlotDataIntCallback("Whistlesanity", &SA2_SetPipes);
    AP_RegisterSlotDataIntCallback("GoldBeetles", &SA2_SetGoldBeetles);
    AP_RegisterSlotDataIntCallback("OmochaoChecks", &SA2_SetOmochaoChecks);
    AP_RegisterSlotDataIntCallback("AnimalChecks", &SA2_SetAnimalChecks);
    AP_RegisterSlotDataIntCallback("KartRaceChecks", &SA2_SetKartRaceChecks);
    AP_RegisterSlotDataIntCallback("ChaoStadiumChecks", &SA2_SetChaoPacks);
    AP_RegisterSlotDataIntCallback("ChaoRaceDifficulty", &SA2_SetChaoRaceDifficulty);
    AP_RegisterSlotDataIntCallback("ChaoKarateDifficulty", &SA2_SetChaoKarateDifficulty);
    AP_RegisterSlotDataIntCallback("ChaoStats", &SA2_SetChaoStats);
    AP_RegisterSlotDataIntCallback("ChaoAnimalParts", &SA2_SetChaoBodyParts);
    AP_RegisterSlotDataIntCallback("ChaoKindergarten", &SA2_SetChaoKindergarten);
    AP_RegisterSlotDataMapIntIntCallback("DefaultEggMap", &SA2_SetDefaultEggMap);
    AP_RegisterSlotDataMapIntIntCallback("DefaultChaoNameMap", &SA2_SetDefaultChaoNameMap);
    AP_RegisterSlotDataIntCallback("MinigameTrapDifficulty", &SA2_SetMinigameDifficulty);
    AP_RegisterSlotDataMapIntIntCallback("RegionEmblemMap", &SA2_SetRegionEmblemMap);
    AP_RegisterSlotDataMapIntIntCallback("MissionMap", &SA2_SetChosenMissionsMap);
    AP_RegisterSlotDataMapIntIntCallback("MissionCountMap", &SA2_SetMissionCountMap);
    AP_RegisterSlotDataMapIntIntCallback("GateBosses", &SA2_SetGateBosses);
    AP_RegisterSlotDataMapIntIntCallback("BossRushMap", &SA2_SetChosenBossRushMap);
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

bool ArchipelagoManager::IsDebug()
{
    return (this->_settingsINI && this->_settingsINI->getBool("AP", "DebugDisplayPositionXYZ", false));
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
            // Currently too much spam, maybe more types in future
            //std::string outMsg = msg->text;
            //outMsgs.push_back(outMsg);
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
    if (!this->IsDebug())
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
        this->AP_KillPlayer();

        this->_deathLinkTimer = 420;

        MessageQueue::GetInstance().AddMessage(this->receivedDeathCause);
        this->receivedDeathCause.clear();

        this->DeathLinkClear();
    }
    else if (!this->DeathLinkPending() &&
             CurrentLevel == LevelIDs::LevelIDs_Route101280 &&
             GameState == GameStates::GameStates_RestartLevel_1) // We Died, Car Flavored
    {
        DeathCause cause = DeathCause::DC_Kart;
        this->DeathLinkSend(cause);

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
            DeathCause cause = DeathCause::DC_Damage;

            if (this->deathCauseOverride != DeathCause::DC_None)
            {
                cause = this->deathCauseOverride;
                this->deathCauseOverride = DeathCause::DC_None;
            }
            else if (MainCharObj1[0]->Action == Action_Drown)
            {
                cause = DeathCause::DC_Drown;
            }
            else if (MainCharObj1[0]->Action == Action_Quicksand)
            {
                cause = DeathCause::DC_Quicksand;
            }
            else if (MainCharObj1[0]->Action == Action_Death)
            {
                cause = DeathCause::DC_Damage;
            }
            else if (MainCharObj2[0]->Powerups & (1 << PowerupBits::PowerupBits_Dead))
            {
                cause = DeathCause::DC_Fall;
            }

            this->DeathLinkSend(cause);

            this->_deathLinkTimer = 420;
        }
    }
}

void ArchipelagoManager::DeathLinkSend(DeathCause cause)
{
    StatsManager::GetInstance().DeathLinkSent();
    if (!this->_deathLinkActive)
    {
        return;
    }

    std::string causeText;
    std::string characterText;

    switch (CurrentCharacter)
    {
    case Characters::Characters_Sonic:
        characterText = std::string("Sonic");
        break;
    case Characters::Characters_SuperSonic:
        characterText = std::string("Super Sonic");
        break;
    case Characters::Characters_Shadow:
        characterText = std::string("Shadow");
        break;
    case Characters::Characters_SuperShadow:
        characterText = std::string("Super Shadow");
        break;
    case Characters::Characters_Tails:
        characterText = std::string("Tails");
        break;
    case Characters::Characters_MechTails:
        characterText = std::string("Tails");
        break;
    case Characters::Characters_Eggman:
        characterText = std::string("Eggman");
        break;
    case Characters::Characters_MechEggman:
        characterText = std::string("Eggman");
        break;
    case Characters::Characters_Knuckles:
        characterText = std::string("Knuckles");
        break;
    case Characters::Characters_Rouge:
        characterText = std::string("Rouge");
        break;
    default:
        characterText = std::string("Sonic");
        break;
    }

    switch (cause)
    {
    case DeathCause::DC_Damage:
        causeText = characterText + " ran out of rings. (" + this->ap_player_name + ")";
        break;
    case DeathCause::DC_Quicksand:
        causeText = characterText + " fell into quicksand. (" + this->ap_player_name + ")";
        break;
    case DeathCause::DC_Fall:
        causeText = characterText + " didn't make the jump. (" + this->ap_player_name + ")";
        break;
    case DeathCause::DC_Kart:
        causeText = characterText + " crashed their kart. (" + this->ap_player_name + ")";
        break;
    case DeathCause::DC_Drown:
        causeText = characterText + " drowned. (" + this->ap_player_name + ")";
        break;
    case DeathCause::DC_Pong:
        causeText = this->ap_player_name + " could not win at Pong.";
        break;
    default:
        causeText = characterText + " died. (" + this->ap_player_name + ")";
        break;
    }

    Json::FastWriter writer;
    std::chrono::time_point<std::chrono::system_clock> timestamp = std::chrono::system_clock::now();
    AP_Bounce b;
    Json::Value v;
    v["time"] = std::chrono::duration_cast<std::chrono::seconds>(timestamp.time_since_epoch()).count();
    v["source"] = this->ap_player_name;
    v["cause"] = causeText;
    b.data = writer.write(v);
    b.games = nullptr;
    b.slots = nullptr;
    std::vector<std::string> tags = { std::string("DeathLink") };
    b.tags = &tags;
    AP_SendBounce(b);

    MessageQueue::GetInstance().AddMessage(std::string("Death Sent"));

    this->lastDeathLinkTime = std::chrono::duration_cast<std::chrono::seconds>(timestamp.time_since_epoch()).count();
}

bool ArchipelagoManager::DeathLinkPending() 
{
    return this->_deathLinkPending;
}

void ArchipelagoManager::DeathLinkClear() 
{
    StatsManager::GetInstance().DeathLinkReceived();

    this->_deathLinkPending = false;
    AP_DeathLinkClear();
}

// RingLink Functions
void ArchipelagoManager::OnFrameRingLink()
{
    if (!this->_ringLinkActive)
    {
        return;
    }

    if (CurrentLevel == LevelIDs_FinalHazard)
    {
        return;
    }

    if (GameState != GameStates::GameStates_Ingame &&
        GameState != GameStates::GameStates_Pause &&
        RingCount[0] == 0)
    {
        this->_lastSentRingCount = 0;
        this->_ringLinkTimer = RINGLINK_RATE;

        return;
    }

    if (RingCount[0] != this->_lastSentRingCount)
    {
        this->_ringLinkTimer--;

        if (this->_ringLinkTimer <= 0)
        {
            // Send RingLink
            int ringLinkAmount = (RingCount[0] - this->_lastSentRingCount);

            this->_ringLinkTimer = RINGLINK_RATE;
            this->_lastSentRingCount = RingCount[0];

            Json::FastWriter writer;
            std::chrono::time_point<std::chrono::system_clock> timestamp = std::chrono::system_clock::now();
            AP_Bounce b;
            Json::Value v;
            v["time"] = std::chrono::duration_cast<std::chrono::seconds>(timestamp.time_since_epoch()).count();
            v["source"] = this->_instanceID;
            v["amount"] = ringLinkAmount;
            b.data = writer.write(v);
            b.slots = nullptr;
            b.games = nullptr;
            std::vector<std::string> tags = { std::string("RingLink") };
            b.tags = &tags;
            AP_SendBounce(b);
        }
    }
    else
    {
        this->_ringLinkTimer = RINGLINK_RATE;
    }
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

    std::vector<std::string> tags;
    if (this->_deathLinkActive)
    {
        tags.push_back(std::string("DeathLink"));
    }
    if (this->_ringLinkActive)
    {
        tags.push_back(std::string("RingLink"));
    }
    AP_SetTags(tags);
}

void ArchipelagoManager::SetRingLink(bool ringLinkActive)
{
    this->_ringLinkActive = ringLinkActive;

    std::vector<std::string> tags;
    if (this->_deathLinkActive)
    {
        tags.push_back(std::string("DeathLink"));
    }
    if (this->_ringLinkActive)
    {
        tags.push_back(std::string("RingLink"));
    }
    AP_SetTags(tags);
}

void ArchipelagoManager::VerfyModVersion(int modVersion)
{
    if (modVersion != MOD_VERSION)
    {
        this->_badModVersion = true;
        this->_serverModVersion = modVersion;
    }
}

void ArchipelagoManager::AP_KillPlayer()
{
    if (CurrentLevel == LevelIDs::LevelIDs_Route101280 || CurrentLevel == LevelIDs::LevelIDs_KartRace)
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
}

void ArchipelagoManager::SetDeathCause(DeathCause cause)
{
    this->deathCauseOverride = cause;
}
