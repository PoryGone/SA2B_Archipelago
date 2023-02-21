#pragma once
#include "MinigameBase.h"

class Pong : public MinigameBase
{
public:
	void OnGameStart() override;
	void OnFrame(MinigameManagerData data) override;

private:
	Angle ballAngle = 0;
	int rotationDelta = 1;
};
