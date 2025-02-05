#include "../../../pch.h"
#include "LightUpPath.h"

// TODO: Handle results feedback
// TODO: SFX

void LightUpPath::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_InProgress;
	cursorX = 0;
	cursorY = 0;
	CreateHierarchy(data);
	FillGrid(data.difficulty, data);
	data.timers->push_back(&this->timer);
	this->timer.Start(this->guessTime);
}

void LightUpPath::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MGS_InProgress)
	{
		return;
	}
	if (data.inputPress & RIF_Up)
	{
		Move(0, -1, data);
	}
	if (data.inputPress & RIF_Down)
	{
		Move(0, 1, data);
	}
	if (data.inputPress & RIF_Left)
	{
		Move(-1, 0, data);
	}
	if (data.inputPress & RIF_Right)
	{
		Move(1, 0, data);
	}

	this->UpdateTimerFill();
	if (timer.IsElapsed())
	{
		PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
		this->currentState = MinigameState::MGS_Loss;
	}
}

void LightUpPath::OnCleanup(MinigameManagerData data)
{
	for (int x = 0; x < grid.size(); x++)
	{
		grid[x].clear();
	}
	grid.clear();
}

void LightUpPath::FillGrid(MinigameDifficulty difficulty, MinigameManagerData data)
{
	int startX = 0;
	int startY = 0;
	int xMax = sizeX - 1;
	int yMax = sizeY - 1;
	int layoutsSize = 0;
	switch (difficulty)
	{
	case MGD_Easy:
		layoutsSize = layoutsEasy.size();
		break;
	case MGD_Medium:
		layoutsSize = layoutsMedium.size();
		break;
	case MGD_Hard:
		layoutsSize = layoutsHard.size();
		break;
	}
	int index = RandomInt(0, layoutsSize);
	bool flipXY = RandomFloat(0.0f, 1.0f) < 0.5f;
	bool invX = RandomFloat(0.0f, 1.0f) < 0.5f;
	bool invY = RandomFloat(0.0f, 1.0f) < 0.5f;
	for (int x = 0; x < grid.size(); x++)
	{
		for (int y = 0; y < grid[x].size(); y++)
		{
			int cellX = invX ? xMax - x : x;
			int cellY = invY ? yMax - y : y;
			auto type = GetCellType(index, flipXY ? cellX : cellY, flipXY ? cellY : cellX, difficulty);
			switch (type)
			{
			case LightUpPath::LTT_None:
				grid[x][y].cellParent->SetEnabled(false);
				grid[x][y].active = false;
				grid[x][y].used = false;
				break;
			case LightUpPath::LTT_Open:
				grid[x][y].cellParent->SetEnabled(true);
				grid[x][y].active = true;
				grid[x][y].used = false;
				grid[x][y].cellParent->anim = data.icons->GetAnim(MGI_Tile_Unlit);
				//grid[x][y].cellParent->color = openColor;
				break;
			case LightUpPath::LTT_Closed:
				grid[x][y].cellParent->SetEnabled(true);
				grid[x][y].active = false;
				grid[x][y].used = false;
				grid[x][y].cellParent->anim = data.icons->GetAnim(MGI_Tile_Disabled);
				//grid[x][y].cellParent->color = closedColor;
				break;
			case LightUpPath::LTT_Start:
				grid[x][y].cellParent->SetEnabled(true);
				grid[x][y].active = true;
				grid[x][y].used = true;
				grid[x][y].cellParent->anim = data.icons->GetAnim(MGI_Tile_Lit);
				//grid[x][y].cellParent->color = usedColor;
				startX = x;
				startY = y;
				break;
			}
		}
	}
	Set(startX, startY, data);
}

void LightUpPath::Move(int x, int y, MinigameManagerData data)
{
	auto cell = GetCell(cursorX + x, cursorY + y);
	if (cell && cell->active && !cell->used)
	{
		Set(cursorX + x, cursorY + y, data);
	}
}

void LightUpPath::Set(int x, int y, MinigameManagerData data)
{
	bool nActive = false;
	bool anyActive = false;
	auto cell = &grid[cursorX][cursorY];
	cell->upArrow->SetEnabled(false);
	cell->downArrow->SetEnabled(false);
	cell->leftArrow->SetEnabled(false);
	cell->rightArrow->SetEnabled(false);
	cell = &grid[x][y];
	cell->cellParent->anim = data.icons->GetAnim(MGI_Tile_Lit);
	//cell->cellParent->color = usedColor;
	cell->used = true;
	cursorX = x;
	cursorY = y;
	auto nCell = GetCell(x, y - 1);
	nActive = nCell && nCell->active && !nCell->used;
	anyActive = anyActive || nActive;
	cell->upArrow->SetEnabled(nActive);
	nCell = GetCell(x, y + 1);
	nActive = nCell && nCell->active && !nCell->used;
	anyActive = anyActive || nActive;
	cell->downArrow->SetEnabled(nActive);
	nCell = GetCell(x - 1, y);
	nActive = nCell && nCell->active && !nCell->used;
	anyActive = anyActive || nActive;
	cell->leftArrow->SetEnabled(nActive);
	nCell = GetCell(x + 1, y);
	nActive = nCell && nCell->active && !nCell->used;
	anyActive = anyActive || nActive;
	cell->rightArrow->SetEnabled(nActive);

	int inactiveCount = sizeX * sizeY;
	for (int gX = 0; gX < grid.size(); gX++)
	{
		for (int gY = 0; gY < grid[gX].size(); gY++)
		{
			if (!grid[gX][gY].active || grid[gX][gY].used)
			{
				inactiveCount--;
			}
		}
	}
	if (inactiveCount <= 0)
	{
		currentState = MGS_Victory;
	}
	else if (!anyActive)
	{
		currentState = MGS_Loss;
	}
}

LightUpPath::LightUpPathTileType LightUpPath::GetCellType(int index, int x, int y, MinigameDifficulty difficulty)
{
	switch (difficulty)
	{
	case MGD_Easy:
		if (index < layoutsEasy.size() && x < layoutsEasy[index].size() && y < layoutsEasy[index][x].size())
		{
			return layoutsEasy[index][x][y];
		}
		break;
	case MGD_Medium:
		if (index < layoutsMedium.size() && x < layoutsMedium[index].size() && y < layoutsMedium[index][x].size())
		{
			return layoutsMedium[index][x][y];
		}
		break;
	case MGD_Hard:
		if (index < layoutsHard.size() && x < layoutsHard[index].size() && y < layoutsHard[index][x].size())
		{
			return layoutsHard[index][x][y];
		}
		break;
	}
	
	return LTT_None;
}

LightUpPath::PathGridCell* LightUpPath::GetCell(int x, int y)
{
	if (x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size())
	{
		return &grid[x][y];
	}
	return nullptr;
}

void LightUpPath::UpdateTimerFill()
{
	float amount = this->timer.TimeRemaining() / this->guessTime;
	amount = amount < 0.0f ? 0.0f : amount;
	amount = amount > 1.0f ? 1.0f : amount;
	float width = this->timerBarBG->displaySize.x * amount;
	float bgX = -(this->timerBarBG->displaySize.x * 0.5f);
	NJS_POINT3 pos = { bgX + width * 0.5f, 0.0f };
	this->timerBar->displaySize.x = width;
	this->timerBar->SetPosition(pos);

	NJS_POINT3 bombPos = this->timerBomb->GetPosition();
	bombPos.x = bgX + width;
	this->timerBomb->SetPosition(bombPos);
}

void LightUpPath::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(RIF_ANY_D_PAD, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);

	gridParent = data.hierarchy->CreateNode("Grid_Parent");

	NJS_POINT3 gridStart = { data.icons->xCenter, data.icons->yCenter };
	gridStart.x -= (cellSize * sizeX) * 0.5f;
	gridStart.y -= (cellSize * sizeY) * 0.5f;
	float halfCellSize = cellSize * 0.5f;

	grid.resize(sizeX);
	for (int x = 0; x < grid.size(); x++)
	{
		grid[x].resize(sizeY);
		for (int y = 0; y < grid[x].size(); y++)
		{
			grid[x][y].cellParent = data.hierarchy->CreateNode("Grid_Cell", data.icons->GetAnim(MGI_Tile_Unlit), { cellSize * 0.8f, cellSize * 0.8f },
				{gridStart.x + (x * cellSize) + halfCellSize, gridStart.y + (y * cellSize) + halfCellSize }, gridParent);
			grid[x][y].upArrow = data.hierarchy->CreateNode("Cell_Up", data.icons->GetAnim(MGI_Tile_Arrow), { cellSize * 0.1f, cellSize * 0.4f }, {}, grid[x][y].cellParent);
			grid[x][y].upArrow->SetPosition({ 0.0f, cellSize * -0.5f });
			grid[x][y].upArrow->SetEnabled(false);
			grid[x][y].upArrow->SetRotation(270.0f);
			grid[x][y].downArrow = data.hierarchy->CreateNode("Cell_Down", data.icons->GetAnim(MGI_Tile_Arrow), { cellSize * 0.1f, cellSize * 0.4f }, {}, grid[x][y].cellParent);
			grid[x][y].downArrow->SetPosition({ 0.0f, cellSize * 0.5f });
			grid[x][y].downArrow->SetEnabled(false);
			grid[x][y].downArrow->SetRotation(90.0f);
			grid[x][y].leftArrow = data.hierarchy->CreateNode("Cell_Left", data.icons->GetAnim(MGI_Tile_Arrow), { cellSize * 0.1f, cellSize * 0.4f }, {}, grid[x][y].cellParent);
			grid[x][y].leftArrow->SetPosition({ cellSize * -0.5f, 0.0f });
			grid[x][y].leftArrow->SetEnabled(false);
			grid[x][y].leftArrow->SetRotation(180.0f);
			grid[x][y].rightArrow = data.hierarchy->CreateNode("Cell_Right", data.icons->GetAnim(MGI_Tile_Arrow), { cellSize * 0.1f, cellSize * 0.4f }, {}, grid[x][y].cellParent);
			grid[x][y].rightArrow->SetPosition({ cellSize * 0.5f, 0.0f });
			grid[x][y].rightArrow->SetEnabled(false);
			grid[x][y].rightArrow->SetRotation(0.0f);
		}
	}

	// Timer
	this->timerBarBG = data.hierarchy->CreateNode("Timer_Background", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 72.0f });
	this->timerBarBG->color = { 1.0f, 0.0f, 0.0f, 0.0f };
	this->timerBar = data.hierarchy->CreateNode("Timer_Fill", data.icons->GetAnim(MGI_White_Box), { 200.0f, 10.0f }, { 320.0f, 72.0f }, this->timerBarBG);
	this->timerBar->color = { 1.0f, 0.0f, 1.0f, 0.0f };
	this->timerBarBG->SetEnabled(true);
	this->timerBomb = data.hierarchy->CreateNode("Timer_Sonic", data.icons->GetAnim(MGI_Sonic_Head), { 32.0f, 32.0f }, { 220.0f, 46.0f }, this->timerBarBG);
	this->timerBomb = data.hierarchy->CreateNode("Timer_Bomb", data.icons->GetAnim(MGI_Bomb), { 32.0f, 32.0f }, { 420.0f, 46.0f }, this->timerBarBG);
	Wiggle* bombWiggle = new Wiggle(RandomFloat(0.45f, 0.65f), -25.0f, 25.0f, true);
	timerBomb->components.push_back(bombWiggle);

}