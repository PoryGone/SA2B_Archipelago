#pragma once
#include "MinigameBase.h"

class Pong : public MinigameBase
{
public:
	void OnGameStart() override;
	void OnFrame(MinigameManagerData data) override;

private:
	float ballAngle = 0;
	float rotationDelta = 2.0f;
};
