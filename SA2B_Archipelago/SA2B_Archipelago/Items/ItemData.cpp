#include "../pch.h"
#pragma once
#include "ItemData.h"
#include <map>


void InitializeItemData(std::map<int, ItemData> &outItemData)
{
    outItemData.clear();

    outItemData[ItemValue::IV_Emblem] = ItemData(0x01DEE418, std::string("Emblem"), std::string("Emblem"), 0);

    outItemData[ItemValue::IV_SonicGloves]         = ItemData(0x01DEB302, std::string("Sonic - Magic Gloves"), std::string("Magic Gloves"), 22);
    outItemData[ItemValue::IV_SonicLightShoes]     = ItemData(0x01DEB300, std::string("Sonic - Light Shoes"), std::string("Light Shoes"), 21);
    outItemData[ItemValue::IV_SonicAncientLight]   = ItemData(0x01DEB301, std::string("Sonic - Ancient Light"), std::string("Ancient Light"), 18);
    outItemData[ItemValue::IV_SonicBounceBracelet] = ItemData(0x01DEB304, std::string("Sonic - Bounce Bracelet"), std::string("Bounce Bracelet"), 19);
    outItemData[ItemValue::IV_SonicFlameRing]      = ItemData(0x01DEB303, std::string("Sonic - Flame Ring"), std::string("Flame Ring"), 20);
    outItemData[ItemValue::IV_SonicMysticMelody]   = ItemData(0x01DEB305, std::string("Sonic - Mystic Melody"), std::string("Mystic Melody"), 23);

    outItemData[ItemValue::IV_TailsLaserBlaster] = ItemData(0x01DEB308, std::string("Tails - Laser Blaster"), std::string("Laser Blaster"), 26);
    outItemData[ItemValue::IV_TailsBooster]      = ItemData(0x01DEB306, std::string("Tails - Booster"), std::string("Booster"), 25);
    outItemData[ItemValue::IV_TailsMysticMelody] = ItemData(0x01DEB309, std::string("Tails - Mystic Melody"), std::string("Mystic Melody"), 27);
    outItemData[ItemValue::IV_TailsBazooka]      = ItemData(0x01DEB307, std::string("Tails - Bazooka"), std::string("Bazooka"), 24);

    outItemData[ItemValue::IV_KnucklesMysticMelody] = ItemData(0x01DEB30E, std::string("Knuckles - Mystic Melody"), std::string("Mystic Melody"), 7);
    outItemData[ItemValue::IV_KnucklesShovelClaw]   = ItemData(0x01DEB30A, std::string("Knuckles - Shovel Claws"), std::string("Shovel Claws"), 8);
    outItemData[ItemValue::IV_KnucklesAirNecklace]  = ItemData(0x01DEB30D, std::string("Knuckles - Air Necklace"), std::string("Air Necklace"), 5);
    outItemData[ItemValue::IV_KnucklesHammerGloves] = ItemData(0x01DEB30C, std::string("Knuckles - Hammer Gloves"), std::string("Hammer Gloves"), 6);
    outItemData[ItemValue::IV_KnucklesSunglasses]   = ItemData(0x01DEB30B, std::string("Knuckles - Sunglasses"), std::string("Sunglasses"), 9);

    outItemData[ItemValue::IV_ShadowFlameRing]     = ItemData(0x01DEB312, std::string("Shadow - Flame Ring"), std::string("Flame Ring"), 16);
    outItemData[ItemValue::IV_ShadowAirShoes]      = ItemData(0x01DEB310, std::string("Shadow - Air Shoes"), std::string("Air Shoes"), 14);
    outItemData[ItemValue::IV_ShadowAncientLight]  = ItemData(0x01DEB311, std::string("Shadow - Ancient Light"), std::string("Ancient Light"), 15);
    outItemData[ItemValue::IV_ShadowMysticMelody]  = ItemData(0x01DEB313, std::string("Shadow - Mystic Melody"), std::string("Mystic Melody"), 17);

    outItemData[ItemValue::IV_EggmanLaserBlaster]    = ItemData(0x1DEB316, std::string("Eggman - Laser Blaster"), std::string("Laser Blaster"), 2);
    outItemData[ItemValue::IV_EggmanMysticMelody]    = ItemData(0x1DEB318, std::string("Eggman - Mystic Melody"), std::string("Mystic Melody"), 3);
    outItemData[ItemValue::IV_EggmanJetEngine]       = ItemData(0x1DEB314, std::string("Eggman - Jet Engine"), std::string("Jet Engine"), 0);
    outItemData[ItemValue::IV_EggmanLargeCannon]     = ItemData(0x1DEB315, std::string("Eggman - Large Cannon"), std::string("Large Cannon"), 1);
    outItemData[ItemValue::IV_EggmanProtectiveArmor] = ItemData(0x1DEB317, std::string("Eggman - Protective Armor"), std::string("Protective Armor"), 4);

    outItemData[ItemValue::IV_RougeMysticMelody]  = ItemData(0x1DEB31C, std::string("Rouge - Mystic Melody"), std::string("Mystic Melody"), 11);
    outItemData[ItemValue::IV_RougePickNails]     = ItemData(0x1DEB319, std::string("Rouge - Pick Nails"), std::string("Pick Nails"), 12);
    outItemData[ItemValue::IV_RougeTreasureScope] = ItemData(0x1DEB31A, std::string("Rouge - Treasure Scope"), std::string("Treasure Scope"), 13);
    outItemData[ItemValue::IV_RougeIronBoots]     = ItemData(0x1DEB31B, std::string("Rouge - Iron Boots"), std::string("Iron Boots"), 10);
    
    outItemData[ItemValue::IV_FiveRings]      = ItemData(0x0000001, std::string("5 Rings"), std::string(), 0);
    outItemData[ItemValue::IV_TenRings]       = ItemData(0x0000003, std::string("10 Rings"), std::string(), 0);
    outItemData[ItemValue::IV_TwentyRings]    = ItemData(0x0000004, std::string("20 Rings"), std::string(), 0);
    outItemData[ItemValue::IV_ExtraLife]      = ItemData(0x0000002, std::string("Extra Life"), std::string(), 0);
    outItemData[ItemValue::IV_Shield]         = ItemData(0x0000005, std::string("Shield"), std::string(), 0);
    outItemData[ItemValue::IV_MagneticShield] = ItemData(0x0000008, std::string("Magnetic Shield"), std::string(), 0);
    outItemData[ItemValue::IV_Invincibility]  = ItemData(0x000000A, std::string("Invincibility"), std::string(), 0);

    outItemData[ItemValue::IV_OmochaoTrap]    = ItemData(0x0000000, std::string("OmoTrap"), std::string(), 0);
    outItemData[ItemValue::IV_TimeStopTrap]   = ItemData(0x0000000, std::string("Chaos Control Trap"), std::string(), 0);
    outItemData[ItemValue::IV_ConfuseTrap]    = ItemData(0x0000000, std::string("Confusion Trap"), std::string(), 0);
    outItemData[ItemValue::IV_TinyTrap]       = ItemData(0x0000000, std::string("Tiny Trap"), std::string(), 0);
    outItemData[ItemValue::IV_GravityTrap]    = ItemData(0x0000000, std::string("Gravity Trap"), std::string(), 0);
    outItemData[ItemValue::IV_ExpositionTrap] = ItemData(0x0000000, std::string("Exposition Trap"), std::string(), 0);
    outItemData[ItemValue::IV_DarknessTrap]   = ItemData(0x0000000, std::string("Darkness Trap"), std::string(), 0);
    outItemData[ItemValue::IV_IceTrap]        = ItemData(0x0000000, std::string("Ice Trap"), std::string(), 0);
    outItemData[ItemValue::IV_SlowTrap]       = ItemData(0x0000000, std::string("Slow Trap"), std::string(), 0);
    outItemData[ItemValue::IV_CutsceneTrap]   = ItemData(0x0000000, std::string("Cutscene Trap"), std::string(), 0);

    outItemData[ItemValue::IV_WhiteChaosEmerald]  = ItemData(0x01DEEAF8, std::string("White Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_RedChaosEmerald]    = ItemData(0x01DEEAF9, std::string("Red Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_CyanChaosEmerald]   = ItemData(0x01DEEAFA, std::string("Cyan Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_PurpleChaosEmerald] = ItemData(0x01DEEAFB, std::string("Purple Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_GreenChaosEmerald]  = ItemData(0x01DEEAFC, std::string("Green Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_YellowChaosEmerald] = ItemData(0x01DEEAFD, std::string("Yellow Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_BlueChaosEmerald]   = ItemData(0x01DEEAFE, std::string("Blue Chaos Emerald"), std::string(), 0);

    outItemData[ItemValue::IV_PongTrap] = ItemData(0x0000000, std::string("Pong Trap"), std::string(), 0);

    outItemData[ItemValue::IV_NormalEgg]            = ItemData(0x0000000, std::string("Normal Egg"), std::string(), 1);
    outItemData[ItemValue::IV_YellowMonoToneEgg]    = ItemData(0x0000000, std::string("Yellow Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_WhiteMonoToneEgg]     = ItemData(0x0000000, std::string("White Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_BrownMonoToneEgg]     = ItemData(0x0000000, std::string("Brown Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_SkyBlueMonoToneEgg]   = ItemData(0x0000000, std::string("Sky Blue Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_PinkMonoToneEgg]      = ItemData(0x0000000, std::string("Pink Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_BlueMonoToneEgg]      = ItemData(0x0000000, std::string("Blue Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_GreyMonoToneEgg]      = ItemData(0x0000000, std::string("Grey Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_GreenMonoToneEgg]     = ItemData(0x0000000, std::string("Green Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_RedMonoToneEgg]       = ItemData(0x0000000, std::string("Red Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_LimeGreenMonoToneEgg] = ItemData(0x0000000, std::string("Lime Green Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_PurpleMonoToneEgg]    = ItemData(0x0000000, std::string("Purple Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_OrangeMonoToneEgg]    = ItemData(0x0000000, std::string("Orange Mono-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_BlackMonoToneEgg]     = ItemData(0x0000000, std::string("Black Mono-Tone Egg"), std::string(), 1);

    outItemData[ItemValue::IV_YellowTwoToneEgg]    = ItemData(0x0000000, std::string("Yellow Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_WhiteTwoToneEgg]     = ItemData(0x0000000, std::string("White Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_BrownTwoToneEgg]     = ItemData(0x0000000, std::string("Brown Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_SkyBlueTwoToneEgg]   = ItemData(0x0000000, std::string("Sky Blue Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_PinkTwoToneEgg]      = ItemData(0x0000000, std::string("Pink Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_BlueTwoToneEgg]      = ItemData(0x0000000, std::string("Blue Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_GreyTwoToneEgg]      = ItemData(0x0000000, std::string("Grey Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_GreenTwoToneEgg]     = ItemData(0x0000000, std::string("Green Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_RedTwoToneEgg]       = ItemData(0x0000000, std::string("Red Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_LimeGreenTwoToneEgg] = ItemData(0x0000000, std::string("Lime Green Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_PurpleTwoToneEgg]    = ItemData(0x0000000, std::string("Purple Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_OrangeTwoToneEgg]    = ItemData(0x0000000, std::string("Orange Two-Tone Egg"), std::string(), 1);
    outItemData[ItemValue::IV_BlackTwoToneEgg]     = ItemData(0x0000000, std::string("Black Two-Tone Egg"), std::string(), 1);

    outItemData[ItemValue::IV_NormalShinyEgg]    = ItemData(0x0000000, std::string("Normal Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_YellowShinyEgg]    = ItemData(0x0000000, std::string("Yellow Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_WhiteShinyEgg]     = ItemData(0x0000000, std::string("White Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_BrownShinyEgg]     = ItemData(0x0000000, std::string("Brown Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_SkyBlueShinyEgg]   = ItemData(0x0000000, std::string("Sky Blue Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_PinkShinyEgg]      = ItemData(0x0000000, std::string("Pink Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_BlueShinyEgg]      = ItemData(0x0000000, std::string("Blue Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_GreyShinyEgg]      = ItemData(0x0000000, std::string("Grey Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_GreenShinyEgg]     = ItemData(0x0000000, std::string("Green Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_RedShinyEgg]       = ItemData(0x0000000, std::string("Red Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_LimeGreenShinyEgg] = ItemData(0x0000000, std::string("Lime Green Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_PurpleShinyEgg]    = ItemData(0x0000000, std::string("Purple Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_OrangeShinyEgg]    = ItemData(0x0000000, std::string("Orange Shiny Egg"), std::string(), 1);
    outItemData[ItemValue::IV_BlackShinyEgg]     = ItemData(0x0000000, std::string("Black Shiny Egg"), std::string(), 1);
}
