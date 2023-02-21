#include "../../pch.h"
#include "Pong.h"


void Pong::OnGameStart()
{
	this->currentState = MGS_InProgress;
}

void Pong::OnFrame(MinigameManagerData data)
{
	NJS_SPRITE sprite = { { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0, data.icons->MinigameTex, data.icons->MinigameAnims };

	//ballAngle += rotationDelta;
	sprite.p.x = data.icons->xCenter;
	sprite.p.y = data.icons->yCenter;
	sprite.tanim = data.icons->GetAnim(MGI_Spinball);
	DrawSprite2D(&sprite);

	sprite.sx = 0.5f;
	sprite.sy = 0.5f;
	sprite.ang = 0;

	sprite.p.x = data.icons->xCenter - 100.0f;
	sprite.p.y = data.icons->yCenter;
	sprite.tanim = data.icons->GetAnim(MGI_RoundedBar);
	DrawSprite2D(&sprite);

	sprite.p.x = data.icons->xCenter + 100.0f;
	sprite.p.y = data.icons->yCenter;
	sprite.tanim = data.icons->GetAnim(MGI_RoundedBar_Mid);
	DrawSprite2D(&sprite);

	sprite.p.x = data.icons->xCenter + 100.0f;
	sprite.p.y = data.icons->yCenter + 128.0f;
	sprite.tanim = data.icons->GetAnim(MGI_RoundedBar_Bottom);
	DrawSprite2D(&sprite);

	sprite.p.x = data.icons->xCenter + 100.0f;
	sprite.p.y = data.icons->yCenter - 128.0f;
	sprite.tanim = data.icons->GetAnim(MGI_RoundedBar_Top);
	DrawSprite2D(&sprite);

	if (data.managerState & MGS_InProgress && data.input & RIF_Up)
	{
		currentState = MGS_Victory;
	}
}
