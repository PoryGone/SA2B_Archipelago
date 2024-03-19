#pragma once
#include <vector>

#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/TextBox.h"
#include "../Components/Wiggle.h"

#include "PokemonData.h"


// Sound Data
#define POKEMON_COUNT_SOUND_BEGIN    0x8019


class PokemonCount : public MinigameBase
{
public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;

	void CreateHierarchy(MinigameManagerData data);

	void OnFramePlayer(MinigameManagerData data);
	void OnFrameSimulate(MinigameManagerData data);

private:
	int correctAnswer = 0;

	RawInputFlags anyDPad = RIF_Up | RIF_Down | RIF_Left | RIF_Right;

	SpriteNode* questionNode = nullptr;
	TextBox* questionBox = nullptr;
	std::vector<SpriteNode*> pokemonSpawnNodes;
};
