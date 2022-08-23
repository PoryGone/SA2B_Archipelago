#include "../pch.h"
#include "StageSelectIcons.h"
#include "StageSelectManager.h"
#include "../Utilities/MessageQueue.h"

FunctionPointer(void, ReleaseTextureList, (NJS_TEXLIST* a1), 0x77F9F0);

static NJS_TEXNAME UpgradeIconsTexName[56];

static NJS_TEXANIM	UpgradeIconsAnim[]{
	{ 0x80, 0x80, 0, 0, 0, 0, 0x100, 0x100, 0, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x100, 0x100, 1, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x100, 0x100, 2, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 3, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 4, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 5, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 6, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 7, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 8, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 9, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x100, 0x100, 10, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 11, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 12, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 13, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 14, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 15, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 16, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 17, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 18, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 19, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 20, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 21, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 22, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 23, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 24, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 25, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 26, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 27, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 28, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 29, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 30, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 31, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 32, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 33, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 34, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 35, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 36, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 37, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 38, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 39, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 40, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 41, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 42, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 43, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 44, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 45, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 46, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 47, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 48, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 49, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 50, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 51, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 52, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 53, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 54, NJD_SPRITE_ALPHA },
	{ 0x80, 0x80, 0x40, 0x40, 0, 0, 0x80, 0x80, 55, NJD_SPRITE_ALPHA },
};

static NJS_TEXLIST UpgradeIconsTex = { arrayptrandlength(UpgradeIconsTexName, Uint32) };
static TexPackInfo TexPack = { "AP_UPGRADEICONS", &UpgradeIconsTex };
static NJS_SPRITE Sprite = { { -32.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, &UpgradeIconsTex, UpgradeIconsAnim };

void DeleteUpgradeIcon(ObjectMaster* obj)
{
	ReleaseTextureList(&UpgradeIconsTex);
	MessageQueue::GetInstance().AddMessage(std::to_string((int)StageSelectManager::GetInstance().DrawIconObj).c_str());
	StageSelectManager::GetInstance().DrawIconObj = nullptr;
	MessageQueue::GetInstance().AddMessage(std::to_string((int)StageSelectManager::GetInstance().DrawIconObj).c_str());
	MessageQueue::GetInstance().AddMessage("Delete Upgrade Icon");
}

void DrawUpgradeIcon(ObjectMaster* obj)
{

	float ratio = 480.0f / VerticalResolution;
	float adjustedHorizontal = HorizontalResolution * ratio;
	float adjustedMin = (adjustedHorizontal - 640.0f) / 2.0f;
	float adjustedMax = adjustedHorizontal - adjustedMin;
	adjustedMin = -adjustedMin;

	Sprite.tanim = &UpgradeIconsAnim[0];
	//Sprite Position is based on 640x480 resolution which gets scaled up for higher resolutions
	//The Screen height resolution remains consistent (0 and 480 will always be top and bottom)
	//The Screen width is not consistent and will change based on the aspect ratio with 0-640 being the center portion (although parts of that could be off screen with dumb resolutions)
	Sprite.p = { Sprite.p.x + 0.5f, 32.0f, 0.0f };
	if (Sprite.p.x > (adjustedMax + 32.0f)) {
		Sprite.p.x = adjustedMin - 32.0f;
	}
	Sprite.sx = 0.5f;
	Sprite.sy = 0.5f;

	njDrawSprite2D(&Sprite, 1, 1, NJD_SPRITE_ALPHA);

	std::string debugStr = "Update Icon: ";
	debugStr.append(std::to_string(Sprite.p.x));
	debugStr.append(", ");
	debugStr.append(std::to_string(Sprite.p.y));
	debugStr.append(" : ");
	debugStr.append(std::to_string(UpgradeIconsTex.textures[0].attr));
	debugStr.append(", ");
	debugStr.append(std::to_string(NJD_SPRITE_ALPHA));

	StageSelectManager::DrawDebugText(NJM_LOCATION(0, 6), debugStr.c_str());
}

void DrawUpgradeIconMain(ObjectMaster* obj)
{
	std::string str = "Update Icon Main ";
	str.append(std::to_string(GameState));
	StageSelectManager::DrawDebugText(NJM_LOCATION(0, 5), str.c_str());

	if (GameState != GameStates_LoadFinished)
		return;

	if (obj->Data1.Entity->Action == 0) {
		obj->DeleteSub = DeleteUpgradeIcon;
		obj->DisplaySub_Delayed3 = DrawUpgradeIcon;
		obj->Data1.Entity->Action = 1;
		MessageQueue::GetInstance().AddMessage("Draw OBJ Setup");
	}
}

void StageSelectIcons::OnFrame() 
{
	if (!DrawIconObj && CurrentMenu == Menus::Menus_StageSelect && GameMode == GameMode::GameMode_Advertise) //GameState == GameStates_LoadItems)
	{
		LoadTextures(&TexPack);
		MessageQueue::GetInstance().AddMessage(std::to_string(UpgradeIconsTex.textures[0].texaddr));
		DrawIconObj = LoadObject(0, "UpgradeIcon", DrawUpgradeIconMain, LoadObj_Data1 | LoadObj_Data2);
		DrawIconObj->DeleteSub = DeleteUpgradeIcon;
		DrawIconObj->MainSub = DrawUpgradeIconMain;
		DrawIconObj->DisplaySub_Delayed3 = DrawUpgradeIcon;
	}
}