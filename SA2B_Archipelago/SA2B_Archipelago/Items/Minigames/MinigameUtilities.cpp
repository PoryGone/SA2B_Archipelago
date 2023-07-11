#include "../../pch.h"
#include "MinigameUtilities.h"

void DrawDPad(RawInputFlags activeButtons, NJS_POINT3 position, float displaySize, MinigameIconData& iconData)
{
	float offset = displaySize / 4.0f;
	float iconSize = displaySize / 2.0f;
	iconSize *= 0.9f;
	NJS_SPRITE sprite = { position, iconSize / 64.0f, iconSize / 64.0f, 0, iconData.MinigameTex, iconData.MinigameAnims };

	sprite.tanim = activeButtons & RIF_Down ? iconData.GetAnim(MGI_DPad_Active) : iconData.GetAnim(MGI_DPad_Inactive);
	sprite.p.y += offset;
	sprite.ang = NJM_DEG_ANG(0.0f);
	DrawSprite2D(&sprite, 1, 1, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE);

	sprite.tanim = activeButtons & RIF_Up ? iconData.GetAnim(MGI_DPad_Active) : iconData.GetAnim(MGI_DPad_Inactive);
	sprite.p = position;
	sprite.p.y -= offset;
	sprite.ang = NJM_DEG_ANG(180.0f);
	DrawSprite2D(&sprite, 1, 1, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE);

	sprite.tanim = activeButtons & RIF_Left ? iconData.GetAnim(MGI_DPad_Active) : iconData.GetAnim(MGI_DPad_Inactive);
	sprite.p = position;
	sprite.p.x -= offset;
	sprite.ang = NJM_DEG_ANG(90.0f);
	DrawSprite2D(&sprite, 1, 1, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE);

	sprite.tanim = activeButtons & RIF_Right ? iconData.GetAnim(MGI_DPad_Active) : iconData.GetAnim(MGI_DPad_Inactive);
	sprite.p = position;
	sprite.p.x += offset;
	sprite.ang = NJM_DEG_ANG(270.0f);
	DrawSprite2D(&sprite, 1, 1, NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE);
}

void AddDPadToHierarchy(RawInputFlags activeButtons, NJS_POINT3 position, float displaySize, MinigameIconData& iconData, SpriteHierarchy& hierarchy)
{
	float offset = displaySize / 4.0f;
	float iconSize = displaySize / 2.0f;
	iconSize *= 0.9f;

	SpriteNode* dpadRoot = hierarchy.CreateNode("DPad");

	SpriteNode* dpadDown = hierarchy.CreateNode("DPad_Down", activeButtons & RIF_Down ? iconData.GetAnim(MGI_DPad_Active) : iconData.GetAnim(MGI_DPad_Inactive), { displaySize, displaySize, 0 }, { 0,0,0 }, dpadRoot);
	dpadDown->SetPosition({ 0.0f, offset, 0.0f });
	dpadDown->rotation = 0.0f;
	SpriteNode* dpadUp = hierarchy.CreateNode("DPad_Up", activeButtons & RIF_Up ? iconData.GetAnim(MGI_DPad_Active) : iconData.GetAnim(MGI_DPad_Inactive), { displaySize, displaySize, 0 }, { 0,0,0 }, dpadRoot);
	dpadUp->SetPosition({ 0.0f, -offset, 0.0f });
	dpadUp->rotation = 180.0f;
	SpriteNode* dpadLeft = hierarchy.CreateNode("DPad_Left", activeButtons & RIF_Left ? iconData.GetAnim(MGI_DPad_Active) : iconData.GetAnim(MGI_DPad_Inactive), { displaySize, displaySize, 0 }, { 0,0,0 }, dpadRoot);
	dpadLeft->SetPosition({ -offset, 0.0f, 0.0f });
	dpadLeft->rotation = 90.0f;
	SpriteNode* dpadRight = hierarchy.CreateNode("DPad_Right", activeButtons & RIF_Right ? iconData.GetAnim(MGI_DPad_Active) : iconData.GetAnim(MGI_DPad_Inactive), { displaySize, displaySize, 0 }, { 0,0,0 }, dpadRoot);
	dpadRight->SetPosition({ -offset, 0.0f, 0.0f });
	dpadRight->rotation = 270.0f;
}