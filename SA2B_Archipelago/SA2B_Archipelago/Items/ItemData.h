#include "../pch.h"
#pragma once
#include <array>
#include <map>
#include <string>

enum ItemValue
{
    IV_Emblem = 0x00,

    IV_SonicGloves,
    IV_SonicLightShoes,
    IV_SonicAncientLight,
    IV_SonicBounceBracelet,
    IV_SonicFlameRing,
    IV_SonicMysticMelody,

    IV_TailsLaserBlaster,
    IV_TailsBooster,
    IV_TailsMysticMelody,
    IV_TailsBazooka,

    IV_KnucklesMysticMelody,
    IV_KnucklesShovelClaw,
    IV_KnucklesAirNecklace,
    IV_KnucklesHammerGloves,
    IV_KnucklesSunglasses,

    IV_ShadowFlameRing,
    IV_ShadowAirShoes,
    IV_ShadowAncientLight,
    IV_ShadowMysticMelody,

    IV_EggmanLaserBlaster,
    IV_EggmanMysticMelody,
    IV_EggmanJetEngine,
    IV_EggmanLargeCannon,
    IV_EggmanProtectiveArmor,

    IV_RougeMysticMelody,
    IV_RougePickNails,
    IV_RougeTreasureScope,
    IV_RougeIronBoots,
    IV_END_UPGRADES = IV_RougeIronBoots,

    IV_Maria,

    IV_FiveRings = 0x20,
    IV_TenRings,
    IV_TwentyRings,
    IV_ExtraLife,
    IV_Shield,
    IV_MagneticShield,
    IV_Invincibility,
    IV_END_JUNK = IV_Invincibility,

    IV_OmochaoTrap = 0x30,
    IV_TimeStopTrap,
    IV_ConfuseTrap,
    IV_TinyTrap,
    IV_GravityTrap,
    IV_ExpositionTrap,
    IV_DarknessTrap,
    IV_IceTrap,
    IV_SlowTrap,
    IV_END_TRAPS = IV_SlowTrap,

    IV_WhiteChaosEmerald = 0x40,
    IV_RedChaosEmerald,
    IV_CyanChaosEmerald,
    IV_PurpleChaosEmerald,
    IV_GreenChaosEmerald,
    IV_YellowChaosEmerald,
    IV_BlueChaosEmerald,
    IV_END_CHAOS_EMERALDS = IV_BlueChaosEmerald,

    IV_PongTrap = 0x50,
    IV_END_MINIGAMES = IV_PongTrap,

    IV_NUM_ITEMS
};

struct ItemData
{
    ItemData() : Address(0x00), DisplayName(std::string("Unknown")) {}
    ItemData(int address, std::string displayName, std::string displayNameShort, int iconIndex) : Address(address), DisplayName(displayName), DisplayNameShort(displayNameShort), IconIndex(iconIndex) {}

    int Address;
    int AmountObtained = 0;
    std::string DisplayName;
    std::string DisplayNameShort;
    //For character upgrades
    int IconIndex = 0;
};


void InitializeItemData(std::map<int, ItemData>& outItemData);


struct DialogueData
{
    DialogueData() : VoiceID(0), Duration(0) {}
    DialogueData(int voiceID, int duration) : VoiceID(voiceID), Duration(duration) {}

    int VoiceID = 0;
    int Duration = 0;
};
