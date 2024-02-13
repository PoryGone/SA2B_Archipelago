#include "../../../pch.h"
#include "../../../Utilities/SpriteUtilities.h"
#include "TextBox.h"

void TextBox::OnRender(SpriteNode& node)
{
	NJS_SPRITE sprite = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, textData->FontTex, textData->FontAnims };
	NJS_TEXANIM* tempAnim = textData->GetAnim(character);
	character++;
	if (character > '~') character = ' ';
	sprite.tanim = tempAnim;
	tempAnim++;
	sprite.p = node.GetPositionGlobal();
	sprite.ang = NJM_DEG_ANG(0.0f);
	sprite.sx = fontSize / (float)tempAnim->sx;
	sprite.sy = fontSize / (float)tempAnim->sy;
	DrawSprite2D(&sprite, 1, 1.0f, NJD_SPRITE_ALPHA);
}