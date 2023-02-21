#pragma once
#include "MinigameBase.h"

class Pong : public MinigameBase
{
public:
	void OnGameStart() override;
	void OnFrame(MinigameManagerData data) override;
};
