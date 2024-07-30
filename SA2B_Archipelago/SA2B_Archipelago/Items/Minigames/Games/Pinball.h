#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"

class Pinball : public MinigameBase
{

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);

};