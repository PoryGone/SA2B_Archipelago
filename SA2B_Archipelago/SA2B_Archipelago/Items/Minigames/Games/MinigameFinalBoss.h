#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"

class MinigameFinalBoss : public MinigameBase
{
public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

private:
	float bossHealth;
};
