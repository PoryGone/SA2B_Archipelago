#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"


class Bee
{
public:
	SpriteNode* sprite;

	NJS_POINT3 position;
	float targetAngle;
	float speed;

	bool hasBeenOn = false;
	bool hasPassed = false;
};

class BeeTrap : public MinigameBase
{
public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

	void OnFrameSimulate(MinigameManagerData data);

private:
	Timer timer;
	std::vector<Bee> bees;
	int beeCount = 400;
};
