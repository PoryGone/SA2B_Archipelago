#include "../pch.h"
#pragma once
#include "ItemData.h"
#include <map>


void InitializeItemData(std::map<int, ItemData> &outItemData)
{
    outItemData.clear();

    outItemData[ItemValue::IV_Emblem] = ItemData(0x01DEC60E, std::string("Emblem"), std::string("Emblem"));

    outItemData[ItemValue::IV_SonicGloves]         = ItemData(0x01DEB302, std::string("Sonic - Magic Gloves"), std::string("Magic Gloves"));
    outItemData[ItemValue::IV_SonicLightShoes]     = ItemData(0x01DEB300, std::string("Sonic - Light Shoes"), std::string("Light Shoes"));
    outItemData[ItemValue::IV_SonicAncientLight]   = ItemData(0x01DEB301, std::string("Sonic - Ancient Light"), std::string("Ancient Light"));
    outItemData[ItemValue::IV_SonicBounceBracelet] = ItemData(0x01DEB304, std::string("Sonic - Bounce Bracelet"), std::string("Bounce Bracelet"));
    outItemData[ItemValue::IV_SonicFlameRing]      = ItemData(0x01DEB303, std::string("Sonic - Flame Ring"), std::string("Flame Ring"));
    outItemData[ItemValue::IV_SonicMysticMelody]   = ItemData(0x01DEB305, std::string("Sonic - Mystic Melody"), std::string("Mystic Melody"));

    outItemData[ItemValue::IV_TailsLaserBlaster] = ItemData(0x01DEB308, std::string("Tails - Laser Blaster"), std::string("Laser Blaster"));
    outItemData[ItemValue::IV_TailsBooster]      = ItemData(0x01DEB306, std::string("Tails - Booster"), std::string("Booster"));
    outItemData[ItemValue::IV_TailsMysticMelody] = ItemData(0x01DEB309, std::string("Tails - Mystic Melody"), std::string("Mystic Melody"));
    outItemData[ItemValue::IV_TailsBazooka]      = ItemData(0x01DEB307, std::string("Tails - Bazooka"), std::string("Bazooka"));

    outItemData[ItemValue::IV_KnucklesMysticMelody] = ItemData(0x01DEB30E, std::string("Knuckles - Mystic Melody"), std::string("Mystic Melody"));
    outItemData[ItemValue::IV_KnucklesShovelClaw]   = ItemData(0x01DEB30A, std::string("Knuckles - Shovel Claw"), std::string("Shovel Claw"));
    outItemData[ItemValue::IV_KnucklesAirNecklace]  = ItemData(0x01DEB30D, std::string("Knuckles - Air Necklace"), std::string("Air Necklace"));
    outItemData[ItemValue::IV_KnucklesHammerGloves] = ItemData(0x01DEB30C, std::string("Knuckles - Hammer Gloves"), std::string("Hammer Gloves"));
    outItemData[ItemValue::IV_KnucklesSunglasses]   = ItemData(0x01DEB30B, std::string("Knuckles - Sunglasses"), std::string("Sunglasses"));

    outItemData[ItemValue::IV_ShadowFlameRing]     = ItemData(0x01DEB312, std::string("Shadow - Flame Ring"), std::string("Flame Ring"));
    outItemData[ItemValue::IV_ShadowAirShoes]      = ItemData(0x01DEB310, std::string("Shadow - Air Shoes"), std::string("Air Shoes"));
    outItemData[ItemValue::IV_ShadowAncientLight]  = ItemData(0x01DEB311, std::string("Shadow - Ancient Light"), std::string("Ancient Light"));
    outItemData[ItemValue::IV_ShadowMysticMelody]  = ItemData(0x01DEB313, std::string("Shadow - Mystic Melody"), std::string("Mystic Melody"));

    outItemData[ItemValue::IV_EggmanLaserBlaster]    = ItemData(0x1DEB316, std::string("Eggman - Laser Blaster"), std::string("Laser Blaster"));
    outItemData[ItemValue::IV_EggmanMysticMelody]    = ItemData(0x1DEB318, std::string("Eggman - Mystic Melody"), std::string("Mystic Melody"));
    outItemData[ItemValue::IV_EggmanJetEngine]       = ItemData(0x1DEB314, std::string("Eggman - Jet Engine"), std::string("Jet Engine"));
    outItemData[ItemValue::IV_EggmanLargeCannon]     = ItemData(0x1DEB315, std::string("Eggman - Large Cannon"), std::string("Large Cannon"));
    outItemData[ItemValue::IV_EggmanProtectiveArmor] = ItemData(0x1DEB317, std::string("Eggman - Protective Armor"), std::string("Protective Armor"));

    outItemData[ItemValue::IV_RougeMysticMelody]  = ItemData(0x1DEB31C, std::string("Rouge - Mystic Melody"), std::string("Mystic Melody"));
    outItemData[ItemValue::IV_RougePickNails]     = ItemData(0x1DEB319, std::string("Rouge - Pick Nails"), std::string("Pick Nails"));
    outItemData[ItemValue::IV_RougeTreasureScope] = ItemData(0x1DEB31A, std::string("Rouge - Treasure Scope"), std::string("Treasure Scope"));
    outItemData[ItemValue::IV_RougeIronBoots]     = ItemData(0x1DEB31B, std::string("Rouge - Iron Boots"), std::string("Iron Boots"));
    
    outItemData[ItemValue::IV_FiveRings]      = ItemData(0x0000000, std::string("5 Rings"), std::string());
    outItemData[ItemValue::IV_TenRings]       = ItemData(0x0000000, std::string("10 Rings"), std::string());
    outItemData[ItemValue::IV_TwentyRings]    = ItemData(0x0000000, std::string("20 Rings"), std::string());
    outItemData[ItemValue::IV_Shield]         = ItemData(0x0000000, std::string("Shield"), std::string());
    outItemData[ItemValue::IV_MagneticShield] = ItemData(0x0000000, std::string("Magnetic Shield"), std::string());
    outItemData[ItemValue::IV_Invincibility]  = ItemData(0x0000000, std::string("Invincibility"), std::string());

    outItemData[ItemValue::IV_OmochaoTrap]  = ItemData(0x0000000, std::string("OmoTrap"), std::string());
    outItemData[ItemValue::IV_TimeStopTrap] = ItemData(0x0000000, std::string("Chaos Control Trap"), std::string());
    outItemData[ItemValue::IV_ConfuseTrap]  = ItemData(0x0000000, std::string("Confusion Trap"), std::string());
    outItemData[ItemValue::IV_TinyTrap]     = ItemData(0x0000000, std::string("Tiny Trap"), std::string());
}
