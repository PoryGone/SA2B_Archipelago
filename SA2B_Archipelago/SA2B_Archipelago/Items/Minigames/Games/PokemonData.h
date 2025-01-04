#pragma once

#include <array>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "../MinigameIconData.h"


enum class PokemonType
{
	No_Type		= 0x00,
	Normal		= 0x01,
	Fire		= 0x02,
	Water		= 0x03,
	Grass		= 0x04,
	Electric	= 0x05,
	Ice			= 0x06,
	Fighting	= 0x07,
	Poison		= 0x08,
	Ground		= 0x09,
	Flying		= 0x0A,
	Psychic		= 0x0B,
	Bug			= 0x0C,
	Rock		= 0x0D,
	Ghost		= 0x0E,
	Dragon		= 0x0F,
	Dark		= 0x10,
	Steel		= 0x11,
	Fairy		= 0x12,
};

enum class PokemonTypeMatchup
{
	NoEffect = 0,
	NotVeryEffective = 1,
	NeutralEffective = 2,
	SuperEffective = 3,
};

extern std::map<PokemonType, std::string> typeNames;

extern std::map<PokemonTypeMatchup, std::string> typeEffectivenessNames;

extern std::map<std::pair<PokemonType, PokemonType>, PokemonTypeMatchup> typeMatchupData;

struct PokemonData
{
	MinigameIcon icon;

	std::string name;

	int originGen;

	PokemonType type1;
	PokemonType type2;

	PokemonData() {};
	PokemonData(MinigameIcon icon, std::string name, int originGen, PokemonType type1, PokemonType type2)
	{
		this->icon = icon;
		this->name = name;
		this->originGen = originGen;
		this->type1 = type1;
		this->type2 = type2;
	};
};

extern std::array<PokemonData, 32> allPokemon;
