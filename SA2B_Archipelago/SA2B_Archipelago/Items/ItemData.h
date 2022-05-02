#include "../pch.h"
#pragma once
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

    IV_NUM_ITEMS
};

struct ItemData
{
    ItemData() : Address(0x00), DisplayName(std::string("Unknown")) {}
    ItemData(int address, std::string displayName) : Address(address), DisplayName(displayName) {}

    int Address;
    int AmountObtained = 0;
    std::string DisplayName;
};


void InitializeItemData(std::map<int, ItemData>& outItemData);