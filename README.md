# Sonic Adventure 2 Archipelago

## What is this game?

**Sonic Adventure 2 Archipelgao** is a  Randomizer for the Steam release of Sonic Adventure 2. 

## What does randomization do to this game?

The randomizer shuffles emblems and upgrade items into the AP item pool. The story mode is disabled, but stage select is available from the start. Levels can be locked behind gates requiring a certain number of emblems and a boss fight to unlock. Cannon's Core will be locked behind a percentage of all available emblems, and completing Cannon's Core will unlock the Biolizard boss if Biolizard is the goal. If the emerald hunt goal is selected, collecting all seven Chaos Emeralds will unlock Green Hill Zone. Progress towards unlocking Cannon's Core and the next stage gate will be displayed on the Stage Select screen.

## What items get shuffled?

The main collectable item in this game is emblems, which you collect to unlock new stages. Some goals may also have Chaos Emeralds as collectables to unlock Green Hill Zone. Additionally all character upgrades will be shuffled and optionally any included junk items, trap items, and chao garden items.

## What locations get shuffled?

Any stage apart from Cannon's Core and Green Hill Zone can be shuffled in up to 5 different areas gated by emblem count. Any of the boss fights apart from Biolizard and Finalhazard can be shuffled and must be fought to access new levels once the required number of emblems are collected.

## Is there a location guide?

Check out our [SA2B Archipelago Wiki](https://sa2archipelago.miraheze.org/wiki/Main_Page)!

## How can I get started?

### Required Software
- Sonic Adventure 2: Battle from: [Sonic Adventure 2: Battle Steam Store Page](https://store.steampowered.com/app/213610/Sonic_Adventure_2/)
	- The Battle DLC is required if you choose to add Chao Karate locations to the randomizer
- SA Mod Manager from: [SA Mod Manager GitHub Releases Page](https://github.com/X-Hax/SA-Mod-Manager/releases)
- .NET Desktop Runtime 8.0 from: [.NET Desktop Runtime 8.0 Download Page](https://dotnet.microsoft.com/en-us/download/dotnet/thank-you/runtime-desktop-8.0.12-windows-x64-installer)
- Archipelago Mod for Sonic Adventure 2: Battle
  from: [Sonic Adventure 2: Battle Archipelago Randomizer Mod Releases Page](https://github.com/PoryGone/SA2B_Archipelago/releases/)

### Installation Procedures (Windows)

1. Install Sonic Adventure 2: Battle from Steam.

2. Launch the game at least once without mods.

3. Install SA Mod Manager as per [its instructions](https://github.com/X-Hax/SA-Mod-Manager/tree/master?tab=readme-ov-file).

4. Unpack the Archipelago Mod into the `/mods` directory in the folder into which you installed Sonic Adventure 2: Battle, so that `/mods/SA2B_Archipelago` is a valid path.

5. Launch the `SAModManager.exe` and make sure the SA2B_Archipelago mod is listed and enabled.

### Installation Procedures (Linux and Steam Deck)

1. Install Sonic Adventure 2: Battle from Steam.

2. Launch the game at least once without mods.

3. Create both a `/mods` directory and a `/SAManager` directory in the folder into which you installed Sonic Adventure 2: Battle.

4. Unpack the Archipelago Mod into this folder, so that `/mods/SA2B_Archipelago` is a valid path.

5. Install SA Mod Manager as per [its instructions](https://github.com/X-Hax/SA-Mod-Manager/tree/master?tab=readme-ov-file). Specifically, extract SAModManager.exe file to the folder that Sonic Adventure 2: Battle is installed to. To launch it, add ``SAModManager.exe`` as a non-Steam game. In the properties on Steam for SA Mod Manager, set it to use Proton as the compatibility tool.

6. Run SAModManager.exe from Steam once. It should produce an error popup saying you need .NET Desktop Runtime and ask you if you'd like to download it. Say yes and it will download through your browser.

7. Install protontricks, on the Steam Deck this can be done via the Discover store, on other distros instructions vary, [see its github page](https://github.com/Matoking/protontricks).

8. Right click the .NET Desktop Runtime exe that was downloaded in step 6, and assuming protontricks was installed correctly, the option to "Open with Protontricks Launcher" should be available. Click that, and in the popup window that opens, select SAModManager.exe. Follow the prompts after this to install the .NET Desktop Runtime for SAModManager. Once it is done, you should be able to successfully launch SAModManager to steam.

9. Launch `SAModManager.exe` from Steam and make sure the SA2B_Archipelago mod is listed and enabled.

Note: Ensure that you launch Sonic Adventure 2 from Steam directly on Linux, rather than launching using the `Save & Play` button in SA Mod Manager.

### Joining a MultiWorld Game

1. Before launching the game, run the `SAModManager.exe`, select the SA2B_Archipelago mod, and hit the `Configure Mod` button.

2. For the `Server IP` field under `AP Settings`, enter the address of the server, such as archipelago.gg:38281, your server host should be able to tell you this.

3. For the `PlayerName` field under `AP Settings`, enter your "name" field from the yaml, or website config.

4. For the `Password` field under `AP Settings`, enter the server password if one exists, otherwise leave blank.

5. Click The `Save` button then hit `Save & Play` to launch the game. On Linux, launch Sonic Adventure 2 from Steam directly rather than using `Save & Play`.

6. Create a new save to connect to the MultiWorld game. A "Connected to Archipelago" message will appear if you sucessfully connect. If you close the game during play, you can reconnect to the MultiWorld game by selecting the same save file slot.