#pragma once
#include "../MinigameBase.h"
#include "../MinigameUtilities.h"
#include "../Components/Wiggle.h"


class LightUpPath : public MinigameBase
{
	enum LightUpPathTileType
	{
		LTT_None, //Grid position does not exist
		LTT_Open,
		LTT_Closed,
		LTT_Start,
	};

	struct PathGridCell
	{
		bool active;
		bool used;
		SpriteNode* cellParent;
		SpriteNode* upArrow;
		SpriteNode* downArrow;
		SpriteNode* leftArrow;
		SpriteNode* rightArrow;
	};

public:
	void OnGameStart(MinigameManagerData data) override;
	void OnFrame(MinigameManagerData data) override;
	void OnCleanup(MinigameManagerData data) override;

private:
	void CreateHierarchy(MinigameManagerData data);
	void UpdateTimerFill();

	void FillGrid(MinigameDifficulty difficulty, MinigameManagerData data);
	void Move(int x, int y, MinigameManagerData data);
	void Set(int x, int y, MinigameManagerData data);
	LightUpPathTileType GetCellType(int index, int x, int y, MinigameDifficulty difficulty);
	PathGridCell* GetCell(int x, int y);

	SpriteNode* timerBarBG;
	SpriteNode* timerBar;
	SpriteNode* timerBomb;
	SpriteNode* timerSonic;

	Timer timer;
	float guessTime = 25.0f;

	//0,0 is top left
	int cursorX;
	int cursorY;

	int sizeX = 5;
	int sizeY = 5;

	//NJS_ARGB closedColor = { 1.0f, 1.0f, 0.0f, 0.0f };
	//NJS_ARGB openColor = { 1.0f, 1.0f, 1.0f, 1.0f };
	//NJS_ARGB usedColor = { 1.0f, 1.0f, 1.0f, 0.0f };

	float cellSize = 50.0f;

	SpriteNode* gridParent;
	
	std::vector<std::vector<PathGridCell>> grid;

	std::vector<std::vector<std::vector<LightUpPathTileType>>> layoutsEasy {
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Start, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//S-000
		},
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Closed, LTT_Start, LTT_Open, LTT_Open},			//0-S00
		},
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Start, LTT_Open},			//000S0
		},
		{ //Probably easy
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Open, LTT_Closed},		//---0-
			{LTT_Closed, LTT_Start, LTT_Open, LTT_Open, LTT_Open},			//-S000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//--000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},		//--00-
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed},	//-----
		},
		{ //Probably medium
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Open},			//000-0
			{LTT_Open, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},			//0-00-
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Start, LTT_Open},			//-00S0
		},
		{ //Probably medium
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Start, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//S-000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},		//--00-
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed},	//-----
		},
		{ //Probably medium
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Start, LTT_Closed},		//00-S-
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//0-000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},		//--00-
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed},	//-----
		},
		{ //Probably hard
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//-0000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Open},			//000-0
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Start, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//S0000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Closed},			//000--
		},
		{ //Probably hard
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//-0000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Open, LTT_Open, LTT_Start, LTT_Open},			//000S0
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
		},
		{ //Probably hard
			{LTT_Start, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//S0000
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//-0000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Open},			//000-0
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
		},
		/*
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
		},
		*/
	};

	std::vector<std::vector<std::vector<LightUpPathTileType>>> layoutsMedium {
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Start, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//S-000
		},
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Closed, LTT_Start, LTT_Open, LTT_Open},			//0-S00
		},
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Start, LTT_Open},			//000S0
		},
		{ //Probably easy
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Open, LTT_Closed},		//---0-
			{LTT_Closed, LTT_Start, LTT_Open, LTT_Open, LTT_Open},			//-S000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//--000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},		//--00-
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed},	//-----
		},
		{ //Probably medium
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Open},			//000-0
			{LTT_Open, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},			//0-00-
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Start, LTT_Open},			//-00S0
		},
		{ //Probably medium
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Start, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//S-000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},		//--00-
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed},	//-----
		},
		{ //Probably medium
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Start, LTT_Closed},		//00-S-
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//0-000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},		//--00-
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed},	//-----
		},
		{ //Probably hard
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//-0000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Open},			//000-0
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Start, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//S0000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Closed},			//000--
		},
		{ //Probably hard
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//-0000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Open, LTT_Open, LTT_Start, LTT_Open},			//000S0
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
		},
		{ //Probably hard
			{LTT_Start, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//S0000
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//-0000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Open},			//000-0
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
		},
	};

	std::vector<std::vector<std::vector<LightUpPathTileType>>> layoutsHard {
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Start, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//S-000
		},
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Closed, LTT_Start, LTT_Open, LTT_Open},			//0-S00
		},
		{ //Probably easy
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Start, LTT_Open},			//000S0
		},
		{ //Probably easy
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Open, LTT_Closed},		//---0-
			{LTT_Closed, LTT_Start, LTT_Open, LTT_Open, LTT_Open},			//-S000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//--000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},		//--00-
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed},	//-----
		},
		{ //Probably medium
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Open},			//000-0
			{LTT_Open, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},			//0-00-
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Start, LTT_Open},			//-00S0
		},
		{ //Probably medium
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Closed},			//00-0-
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Start, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//S-000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},		//--00-
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed},	//-----
		},
		{ //Probably medium
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Start, LTT_Closed},		//00-S-
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Open, LTT_Closed, LTT_Open, LTT_Open, LTT_Open},			//0-000
			{LTT_Closed, LTT_Closed, LTT_Open, LTT_Open, LTT_Closed},		//--00-
			{LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed, LTT_Closed},	//-----
		},
		{ //Probably hard
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//-0000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Open},			//000-0
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Start, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//S0000
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Closed},			//000--
		},
		{ //Probably hard
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//-0000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Open, LTT_Open, LTT_Start, LTT_Open},			//000S0
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
		},
		{ //Probably hard
			{LTT_Start, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//S0000
			{LTT_Closed, LTT_Open, LTT_Open, LTT_Open, LTT_Open},			//-0000
			{LTT_Open, LTT_Open, LTT_Closed, LTT_Open, LTT_Open},			//00-00
			{LTT_Open, LTT_Open, LTT_Open, LTT_Closed, LTT_Open},			//000-0
			{LTT_Open, LTT_Open, LTT_Open, LTT_Open, LTT_Open},				//00000
		},
	};

};