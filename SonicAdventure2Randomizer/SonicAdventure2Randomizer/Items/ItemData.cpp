#include "../pch.h"
#pragma once
#include "ItemData.h"
#include <map>


void InitializeItemData(std::map<int, ItemData> &outItemData)
{
    outItemData.clear();

    outItemData[ItemValue::IV_Emblem] = ItemData(0x01DEC60E);

    outItemData[ItemValue::IV_SonicGloves]         = ItemData(0x01DEB302);
    outItemData[ItemValue::IV_SonicLightShoes]     = ItemData(0x01DEB300);
    outItemData[ItemValue::IV_SonicAncientLight]   = ItemData(0x01DEB301);
    outItemData[ItemValue::IV_SonicBounceBracelet] = ItemData(0x01DEB304);
    outItemData[ItemValue::IV_SonicFlameRing]      = ItemData(0x01DEB303);
    outItemData[ItemValue::IV_SonicMysticMelody]   = ItemData(0x01DEB305);

    outItemData[ItemValue::IV_TailsLaserBlaster] = ItemData(0x01DEB308);
    outItemData[ItemValue::IV_TailsBooster]      = ItemData(0x01DEB306);
    outItemData[ItemValue::IV_TailsMysticMelody] = ItemData(0x01DEB309);
    outItemData[ItemValue::IV_TailsBazooka]      = ItemData(0x01DEB307);

    outItemData[ItemValue::IV_KnucklesMysticMelody] = ItemData(0x01DEB30E);
    outItemData[ItemValue::IV_KnucklesShovelClaw]   = ItemData(0x01DEB30A);
    outItemData[ItemValue::IV_KnucklesAirNecklace]  = ItemData(0x01DEB30D);
    outItemData[ItemValue::IV_KnucklesHammerGloves] = ItemData(0x01DEB30C);
    outItemData[ItemValue::IV_KnucklesSunglasses]   = ItemData(0x01DEB30B);

    outItemData[ItemValue::IV_ShadowFlameRing]     = ItemData(0x01DEB312);
    outItemData[ItemValue::IV_ShadowAirShoes]      = ItemData(0x01DEB310);
    outItemData[ItemValue::IV_ShadowAincientLight] = ItemData(0x01DEB311);
    outItemData[ItemValue::IV_ShadowMysticMelody]  = ItemData(0x01DEB313);

    outItemData[ItemValue::IV_EggmanLaserBlaster]    = ItemData(0x1DEB316);
    outItemData[ItemValue::IV_EggmanMysticMelody]    = ItemData(0x1DEB318);
    outItemData[ItemValue::IV_EggmanJetEngine]       = ItemData(0x1DEB314);
    outItemData[ItemValue::IV_EggmanLargeCannon]     = ItemData(0x1DEB315);
    outItemData[ItemValue::IV_EggmanProtectiveArmor] = ItemData(0x01DEB317);

    outItemData[ItemValue::IV_RougeMysticMelody]  = ItemData(0x01DEB31C);
    outItemData[ItemValue::IV_RougePickNails]     = ItemData(0x01DEB319);
    outItemData[ItemValue::IV_RougeTreasureScope] = ItemData(0x01DEB31A);
    outItemData[ItemValue::IV_RougeIronBoots]     = ItemData(0x01DEB31B);
}
