#include "../../../pch.h"
#include "LightUpPath.h"

void LightUpPath::OnGameStart(MinigameManagerData data)
{
	currentState = MGS_InProgress;
	cursorX = 0;
	cursorY = 0;
	CreateHierarchy(data);
	FillGrid();
}

void LightUpPath::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MGS_InProgress)
	{
		return;
	}
	if (data.inputPress & RIF_Up)
	{
		Move(0, -1);
	}
	if (data.inputPress & RIF_Down)
	{
		Move(0, 1);
	}
	if (data.inputPress & RIF_Left)
	{
		Move(-1, 0);
	}
	if (data.inputPress & RIF_Right)
	{
		Move(1, 0);
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

void LightUpPath::FillGrid()
{
	int startX = 0;
	int startY = 0;
	int index = RandomInt(0, layouts.size());
	bool rotate = RandomFloat(0.0f, 1.0f) < 0.5f;
	for (int x = 0; x < grid.size(); x++)
	{
		for (int y = 0; y < grid[x].size(); y++)
		{
			auto type = GetCellType(index, rotate ? x : y, rotate ? y : x);
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
				grid[x][y].cellParent->color = openColor;
				break;
			case LightUpPath::LTT_Closed:
				grid[x][y].cellParent->SetEnabled(true);
				grid[x][y].active = false;
				grid[x][y].used = false;
				grid[x][y].cellParent->color = closedColor;
				break;
			case LightUpPath::LTT_Start:
				grid[x][y].cellParent->SetEnabled(true);
				grid[x][y].active = true;
				grid[x][y].used = true;
				grid[x][y].cellParent->color = usedColor;
				startX = x;
				startY = y;
				break;
			}
		}
	}
	Set(startX, startY);
}

void LightUpPath::Move(int x, int y)
{
	auto cell = GetCell(cursorX + x, cursorY + y);
	if (cell && cell->active && !cell->used)
	{
		Set(cursorX + x, cursorY + y);
	}
}

void LightUpPath::Set(int x, int y)
{
	bool nActive = false;
	bool anyActive = false;
	auto cell = &grid[cursorX][cursorY];
	cell->upArrow->SetEnabled(false);
	cell->downArrow->SetEnabled(false);
	cell->leftArrow->SetEnabled(false);
	cell->rightArrow->SetEnabled(false);
	cell = &grid[x][y];
	cell->cellParent->color = usedColor;
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

LightUpPath::LightUpPathTileType LightUpPath::GetCellType(int index, int x, int y)
{
	if (index < layouts.size() && x < layouts[index].size() && y < layouts[index][x].size())
	{
		return layouts[index][x][y];
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

void LightUpPath::CreateHierarchy(MinigameManagerData data)
{
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
			grid[x][y].cellParent = data.hierarchy->CreateNode("Grid_Cell", data.icons->GetAnim(MGI_Square), { cellSize * 0.8f, cellSize * 0.8f },
				{gridStart.x + (x * cellSize) + halfCellSize, gridStart.y + (y * cellSize) + halfCellSize }, gridParent);
			grid[x][y].upArrow = data.hierarchy->CreateNode("Cell_Up", data.icons->GetAnim(MGI_Triangle), { cellSize * 0.4f, cellSize * 0.1f }, {}, grid[x][y].cellParent);
			grid[x][y].upArrow->SetPosition({ 0.0f, cellSize * -0.5f });
			grid[x][y].upArrow->SetEnabled(false);
			grid[x][y].downArrow = data.hierarchy->CreateNode("Cell_Down", data.icons->GetAnim(MGI_Triangle), { cellSize * 0.4f, cellSize * 0.1f }, {}, grid[x][y].cellParent);
			grid[x][y].downArrow->SetPosition({ 0.0f, cellSize * 0.5f });
			grid[x][y].downArrow->SetEnabled(false);
			grid[x][y].downArrow->SetRotation(180.0f);
			grid[x][y].leftArrow = data.hierarchy->CreateNode("Cell_Left", data.icons->GetAnim(MGI_Triangle), { cellSize * 0.4f, cellSize * 0.1f }, {}, grid[x][y].cellParent);
			grid[x][y].leftArrow->SetPosition({ cellSize * -0.5f, 0.0f });
			grid[x][y].leftArrow->SetEnabled(false);
			grid[x][y].leftArrow->SetRotation(270.0f);
			grid[x][y].rightArrow = data.hierarchy->CreateNode("Cell_Right", data.icons->GetAnim(MGI_Triangle), { cellSize * 0.4f, cellSize * 0.1f }, {}, grid[x][y].cellParent);
			grid[x][y].rightArrow->SetPosition({ cellSize * 0.5f, 0.0f });
			grid[x][y].rightArrow->SetEnabled(false);
			grid[x][y].rightArrow->SetRotation(90.0f);
		}
	}
}