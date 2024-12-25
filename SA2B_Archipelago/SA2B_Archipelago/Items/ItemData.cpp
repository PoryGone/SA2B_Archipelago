#include "../pch.h"
#pragma once
#include "ItemData.h"
#include <map>


void InitializeItemData(std::map<int, ItemData> &outItemData)
{
    outItemData.clear();

    outItemData[ItemValue::IV_Emblem] = ItemData(0x01DEE418, std::string("Emblem"), std::string("Emblem"), 0);

    outItemData[ItemValue::IV_BlackMarketToken] = ItemData(0x01DEE41C, std::string("Chao Coin"), std::string("Chao Coin"), 0);

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

    outItemData[ItemValue::IV_OmochaoTrap]         = ItemData(0x0000000, std::string("OmoTrap"), std::string(), 0);
    outItemData[ItemValue::IV_TimeStopTrap]        = ItemData(0x0000000, std::string("Chaos Control Trap"), std::string(), 0);
    outItemData[ItemValue::IV_ConfuseTrap]         = ItemData(0x0000000, std::string("Confusion Trap"), std::string(), 0);
    outItemData[ItemValue::IV_TinyTrap]            = ItemData(0x0000000, std::string("Tiny Trap"), std::string(), 0);
    outItemData[ItemValue::IV_GravityTrap]         = ItemData(0x0000000, std::string("Gravity Trap"), std::string(), 0);
    outItemData[ItemValue::IV_ExpositionTrap]      = ItemData(0x0000000, std::string("Exposition Trap"), std::string(), 0);
    outItemData[ItemValue::IV_DarknessTrap]        = ItemData(0x0000000, std::string("Darkness Trap"), std::string(), 0);
    outItemData[ItemValue::IV_IceTrap]             = ItemData(0x0000000, std::string("Ice Trap"), std::string(), 0);
    outItemData[ItemValue::IV_SlowTrap]            = ItemData(0x0000000, std::string("Slow Trap"), std::string(), 0);
    outItemData[ItemValue::IV_CutsceneTrap]        = ItemData(0x0000000, std::string("Cutscene Trap"), std::string(), 0);
    outItemData[ItemValue::IV_ReverseTrap]         = ItemData(0x0000000, std::string("Reverse Trap"), std::string(), 0);
    outItemData[ItemValue::IV_LiteratureTrap]      = ItemData(0x0000000, std::string("Literature Trap"), std::string(), 0);
    outItemData[ItemValue::IV_ControllerDriftTrap] = ItemData(0x0000000, std::string("Controller Drift Trap"), std::string(), 0);
    outItemData[ItemValue::IV_PoisonTrap]          = ItemData(0x0000000, std::string("Poison Trap"), std::string(), 0);

    outItemData[ItemValue::IV_WhiteChaosEmerald]  = ItemData(0x01DEEAF8, std::string("White Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_RedChaosEmerald]    = ItemData(0x01DEEAF9, std::string("Red Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_CyanChaosEmerald]   = ItemData(0x01DEEAFA, std::string("Cyan Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_PurpleChaosEmerald] = ItemData(0x01DEEAFB, std::string("Purple Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_GreenChaosEmerald]  = ItemData(0x01DEEAFC, std::string("Green Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_YellowChaosEmerald] = ItemData(0x01DEEAFD, std::string("Yellow Chaos Emerald"), std::string(), 0);
    outItemData[ItemValue::IV_BlueChaosEmerald]   = ItemData(0x01DEEAFE, std::string("Blue Chaos Emerald"), std::string(), 0);

    outItemData[ItemValue::IV_PongTrap]           = ItemData(0x01DEEAFF, std::string("Pong Trap"), std::string(), 0);
    outItemData[ItemValue::IV_PlatformerTrap]     = ItemData(0x01DEEB00, std::string("Platformer Trap"), std::string(), 0);
    outItemData[ItemValue::IV_FishingTrap]        = ItemData(0x01DEEB01, std::string("Fishing Trap"), std::string(), 0);
    outItemData[ItemValue::IV_TriviaTrap]         = ItemData(0x01DEEB02, std::string("Trivia Trap"), std::string(), 0);
    outItemData[ItemValue::IV_PokemonTriviaTrap]  = ItemData(0x01DEEB03, std::string("Pokemon Trivia Trap"), std::string(), 0);
    outItemData[ItemValue::IV_PokemonCountTrap]   = ItemData(0x01DEEB04, std::string("Pokemon Count Trap"), std::string(), 0);
    outItemData[ItemValue::IV_NumberSequenceTrap] = ItemData(0x01DEEB05, std::string("Number Sequence Trap"), std::string(), 0);
    outItemData[ItemValue::IV_LightUpPathTrap]    = ItemData(0x01DEEB06, std::string("Light Up Path Trap"), std::string(), 0);
    outItemData[ItemValue::IV_PinballTrap]        = ItemData(0x01DEEB07, std::string("Pinball Trap"), std::string(), 0);
    outItemData[ItemValue::IV_MathQuizTrap]       = ItemData(0x01DEEB08, std::string("Math Quiz Trap"), std::string(), 0);
    outItemData[ItemValue::IV_SnakeTrap]          = ItemData(0x01DEEB09, std::string("Snake Trap"), std::string(), 0);
    outItemData[ItemValue::IV_InputSequenceTrap]  = ItemData(0x01DEEB0A, std::string("Input Sequence Trap"), std::string(), 0);

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

    outItemData[ItemValue::IV_ChaoGardenFruit] = ItemData(0x0000000, std::string("Chao Garden Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_HeroGardenFruit] = ItemData(0x0000000, std::string("Hero Garden Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_DarkGardenFruit] = ItemData(0x0000000, std::string("Dark Garden Fruit"), std::string(), 3);

    outItemData[ItemValue::IV_StrongFruit]   = ItemData(0x0000000, std::string("Strong Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_TastyFruit]    = ItemData(0x0000000, std::string("Tasty Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_HeroFruit]     = ItemData(0x0000000, std::string("Hero Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_DarkFruit]     = ItemData(0x0000000, std::string("Dark Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_RoundFruit]    = ItemData(0x0000000, std::string("Round Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_TriangleFruit] = ItemData(0x0000000, std::string("Triangle Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_SquareFruit]   = ItemData(0x0000000, std::string("Square Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_HeartFruit]    = ItemData(0x0000000, std::string("Heart Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_ChaoFruit]     = ItemData(0x0000000, std::string("Chao Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_SmartFruit]    = ItemData(0x0000000, std::string("Smart Fruit"), std::string(), 3);

    outItemData[ItemValue::IV_OrangeFruit] = ItemData(0x0000000, std::string("Orange Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_BlueFruit]   = ItemData(0x0000000, std::string("Blue Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_PinkFruit]   = ItemData(0x0000000, std::string("Pink Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_GreenFruit]  = ItemData(0x0000000, std::string("Green Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_PurpleFruit] = ItemData(0x0000000, std::string("Purple Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_YellowFruit] = ItemData(0x0000000, std::string("Yellow Fruit"), std::string(), 3);
    outItemData[ItemValue::IV_RedFruit]    = ItemData(0x0000000, std::string("Red Fruit"), std::string(), 3);

    outItemData[ItemValue::IV_Mushroom]      = ItemData(0x0000000, std::string("Mushroom"), std::string(), 3);
    outItemData[ItemValue::IV_SuperMushroom] = ItemData(0x0000000, std::string("Super Mushroom"), std::string(), 3);
    outItemData[ItemValue::IV_MintCandy]     = ItemData(0x0000000, std::string("Mint Candy"), std::string(), 3);
    outItemData[ItemValue::IV_Grapes]        = ItemData(0x0000000, std::string("Grapes"), std::string(), 3);

    outItemData[ItemValue::IV_StrongSeed]   = ItemData(0x0000000, std::string("Strong Seed"), std::string(), 7);
    outItemData[ItemValue::IV_TastySeed]    = ItemData(0x0000000, std::string("Tasty Seed"), std::string(), 7);
    outItemData[ItemValue::IV_HeroSeed]     = ItemData(0x0000000, std::string("Hero Seed"), std::string(), 7);
    outItemData[ItemValue::IV_DarkSeed]     = ItemData(0x0000000, std::string("Dark Seed"), std::string(), 7);
    outItemData[ItemValue::IV_RoundSeed]    = ItemData(0x0000000, std::string("Round Seed"), std::string(), 7);
    outItemData[ItemValue::IV_TriangleSeed] = ItemData(0x0000000, std::string("Triangle Seed"), std::string(), 7);
    outItemData[ItemValue::IV_SquareSeed]   = ItemData(0x0000000, std::string("Square Seed"), std::string(), 7);

    outItemData[ItemValue::IV_Pumpkin]      = ItemData(0x0000000, std::string("Pumpkin"), std::string(), 9);
    outItemData[ItemValue::IV_Skull]        = ItemData(0x0000000, std::string("Skull"), std::string(), 9);
    outItemData[ItemValue::IV_Apple]        = ItemData(0x0000000, std::string("Apple"), std::string(), 9);
    outItemData[ItemValue::IV_Bucket]       = ItemData(0x0000000, std::string("Bucket"), std::string(), 9);
    outItemData[ItemValue::IV_EmptyCan]     = ItemData(0x0000000, std::string("Empty Can"), std::string(), 9);
    outItemData[ItemValue::IV_CardboardBox] = ItemData(0x0000000, std::string("Cardboard Box"), std::string(), 9);
    outItemData[ItemValue::IV_FlowerPot]    = ItemData(0x0000000, std::string("Flower Pot"), std::string(), 9);
    outItemData[ItemValue::IV_PaperBag]     = ItemData(0x0000000, std::string("Paper Bag"), std::string(), 9);
    outItemData[ItemValue::IV_Pan]          = ItemData(0x0000000, std::string("Pan"), std::string(), 9);
    outItemData[ItemValue::IV_Stump]        = ItemData(0x0000000, std::string("Stump"), std::string(), 9);
    outItemData[ItemValue::IV_Watermelon]   = ItemData(0x0000000, std::string("Watermelon"), std::string(), 9);

    outItemData[ItemValue::IV_RedWoolBeanie]   = ItemData(0x0000000, std::string("Red Wool Beanie"), std::string(), 9);
    outItemData[ItemValue::IV_BlueWoolBeanie]  = ItemData(0x0000000, std::string("Blue Wool Beanie"), std::string(), 9);
    outItemData[ItemValue::IV_BlackWoolBeanie] = ItemData(0x0000000, std::string("Black Wool Beanie"), std::string(), 9);
    outItemData[ItemValue::IV_Pacifier]        = ItemData(0x0000000, std::string("Pacifier"), std::string(), 9);

    outItemData[ItemValue::IV_Penguin]     = ItemData(0x0000000, std::string("Penguin"), std::string(), 13);
    outItemData[ItemValue::IV_Seal]        = ItemData(0x0000000, std::string("Seal"), std::string(), 13);
    outItemData[ItemValue::IV_Otter]       = ItemData(0x0000000, std::string("Otter"), std::string(), 13);
    outItemData[ItemValue::IV_Rabbit]      = ItemData(0x0000000, std::string("Rabbit"), std::string(), 13);
    outItemData[ItemValue::IV_Cheetah]     = ItemData(0x0000000, std::string("Cheetah"), std::string(), 13);
    outItemData[ItemValue::IV_Warthog]     = ItemData(0x0000000, std::string("Warthog"), std::string(), 13);
    outItemData[ItemValue::IV_Bear]        = ItemData(0x0000000, std::string("Bear"), std::string(), 13);
    outItemData[ItemValue::IV_Tiger]       = ItemData(0x0000000, std::string("Tiger"), std::string(), 13);
    outItemData[ItemValue::IV_Gorilla]     = ItemData(0x0000000, std::string("Gorilla"), std::string(), 13);
    outItemData[ItemValue::IV_Peacock]     = ItemData(0x0000000, std::string("Peacock"), std::string(), 13);
    outItemData[ItemValue::IV_Parrot]      = ItemData(0x0000000, std::string("Parrot"), std::string(), 13);
    outItemData[ItemValue::IV_Condor]      = ItemData(0x0000000, std::string("Condor"), std::string(), 13);
    outItemData[ItemValue::IV_Skunk]       = ItemData(0x0000000, std::string("Skunk"), std::string(), 13);
    outItemData[ItemValue::IV_Sheep]       = ItemData(0x0000000, std::string("Sheep"), std::string(), 13);
    outItemData[ItemValue::IV_Raccoon]     = ItemData(0x0000000, std::string("Raccoon"), std::string(), 13);
    outItemData[ItemValue::IV_HalfFish]    = ItemData(0x0000000, std::string("HalfFish"), std::string(), 13);
    outItemData[ItemValue::IV_SkeletonDog] = ItemData(0x0000000, std::string("Skeleton Dog"), std::string(), 13);
    outItemData[ItemValue::IV_Bat]         = ItemData(0x0000000, std::string("Bat"), std::string(), 13);
    outItemData[ItemValue::IV_Dragon]      = ItemData(0x0000000, std::string("Dragon"), std::string(), 13);
    outItemData[ItemValue::IV_Unicorn]     = ItemData(0x0000000, std::string("Unicorn"), std::string(), 13);
    outItemData[ItemValue::IV_Phoenix]     = ItemData(0x0000000, std::string("Phoenix"), std::string(), 13);

    outItemData[ItemValue::IV_YellowChaosDrive] = ItemData(0x0000000, std::string("Yellow Chaos Drive"), std::string(), 13);
    outItemData[ItemValue::IV_GreenChaosDrive]  = ItemData(0x0000000, std::string("Green Chaos Drive"), std::string(), 13);
    outItemData[ItemValue::IV_RedChaosDrive]    = ItemData(0x0000000, std::string("Red Chaos Drive"), std::string(), 13);
    outItemData[ItemValue::IV_PurpleChaosDrive] = ItemData(0x0000000, std::string("Purple Chaos Drive"), std::string(), 13);
}

std::map<ItemValue, std::string> item_value_to_name = {
    {ItemValue::IV_OmochaoTrap,         "OmoTrap"},
    {ItemValue::IV_TimeStopTrap,        "Chaos Control Trap"},
    {ItemValue::IV_ConfuseTrap,         "Confuse Trap"},
    {ItemValue::IV_TinyTrap,            "Tiny Trap"},
    {ItemValue::IV_GravityTrap,         "Gravity Trap"},
    {ItemValue::IV_ExpositionTrap,      "Exposition Trap"},
    {ItemValue::IV_IceTrap,             "Ice Trap"},
    {ItemValue::IV_SlowTrap,            "Slow Trap"},
    {ItemValue::IV_CutsceneTrap,        "Cutscene Trap"},
    {ItemValue::IV_ReverseTrap,         "Reverse Trap"},
    {ItemValue::IV_LiteratureTrap,      "Literature Trap"},
    {ItemValue::IV_ControllerDriftTrap, "Controller Drift Trap"},
    {ItemValue::IV_PoisonTrap,          "Poison Trap"},
    {ItemValue::IV_PongTrap,            "Pong Trap"},
    {ItemValue::IV_PlatformerTrap,      "Platformer Trap"},
    {ItemValue::IV_FishingTrap,         "Fishing Trap"},
    {ItemValue::IV_TriviaTrap,          "Trivia Trap"},
    {ItemValue::IV_PokemonTriviaTrap,   "Pokemon Trivia Trap"},
    {ItemValue::IV_PokemonCountTrap,    "Pokemon Count Trap"},
    {ItemValue::IV_NumberSequenceTrap,  "Number Sequence Trap"},
    {ItemValue::IV_LightUpPathTrap,     "Light Up Path Trap"},
    {ItemValue::IV_PinballTrap,         "Pinball Trap"},
    {ItemValue::IV_MathQuizTrap,        "Math Quiz Trap"},
    {ItemValue::IV_SnakeTrap,           "Snake Trap"},
    {ItemValue::IV_InputSequenceTrap,   "Input Sequence Trap"},
};

std::map<std::string, ItemValue> item_name_to_value = {
    // Our native Traps
    {"OmoTrap",                 ItemValue::IV_OmochaoTrap},
    {"Chaos Control Trap",      ItemValue::IV_TimeStopTrap},
    {"Confuse Trap",            ItemValue::IV_ConfuseTrap},
    {"Tiny Trap",               ItemValue::IV_TinyTrap},
    {"Gravity Trap",            ItemValue::IV_GravityTrap},
    {"Exposition Trap",         ItemValue::IV_ExpositionTrap},
    {"Ice Trap",                ItemValue::IV_IceTrap},
    {"Slow Trap",               ItemValue::IV_SlowTrap},
    {"Cutscene Trap",           ItemValue::IV_CutsceneTrap},
    {"Reverse Trap",            ItemValue::IV_ReverseTrap},
    {"Literature Trap",         ItemValue::IV_LiteratureTrap},
    {"Controller Drift Trap",   ItemValue::IV_ControllerDriftTrap},
    {"Poison Trap",             ItemValue::IV_PoisonTrap},
    {"Pong Trap",               ItemValue::IV_PongTrap},
    {"Platformer Trap",         ItemValue::IV_PlatformerTrap},
    {"Fishing Trap",            ItemValue::IV_FishingTrap},
    {"Trivia Trap",             ItemValue::IV_TriviaTrap},
    {"Pokemon Trivia Trap",     ItemValue::IV_PokemonTriviaTrap},
    {"Pokemon Count Trap",      ItemValue::IV_PokemonCountTrap},
    {"Number Sequence Trap",    ItemValue::IV_NumberSequenceTrap},
    {"Light Up Path Trap",      ItemValue::IV_LightUpPathTrap},
    {"Pinball Trap",            ItemValue::IV_PinballTrap},
    {"Math Quiz Trap",          ItemValue::IV_MathQuizTrap},
    {"Snake Trap",              ItemValue::IV_SnakeTrap},
    {"Input Sequence Trap",     ItemValue::IV_InputSequenceTrap},

    // Common other trap names
    {"Stun Trap",               ItemValue::IV_TimeStopTrap},
};
