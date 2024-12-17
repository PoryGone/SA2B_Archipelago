#include "../../../pch.h"
#include "Snake.h"

void Snake::OnGameStart(MinigameManagerData data)
{
	this->currentState = MGS_InProgress;

	this->playerCells.clear();
	this->playerCells.push_back(std::pair<int, int>(10, 10));
	this->playerCells.push_back(std::pair<int, int>(9, 10));
	this->playerCells.push_back(std::pair<int, int>(8, 10));

	this->activeSpeed = this->speeds[data.difficulty];
	this->goalLength = this->goalLengths[data.difficulty];
	this->playerDirection = SnakeTileDirection::STD_Right;

	CreateHierarchy(data);
	this->GenerateFood();

	FillGrid();
}

void Snake::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MGS_InProgress)
	{
		return;
	}
	if (data.inputPress & RIF_Up)
	{
		playerDirection = SnakeTileDirection::STD_Up;
	}
	if (data.inputPress & RIF_Down)
	{
		playerDirection = SnakeTileDirection::STD_Down;
	}
	if (data.inputPress & RIF_Left)
	{
		playerDirection = SnakeTileDirection::STD_Left;
	}
	if (data.inputPress & RIF_Right)
	{
		playerDirection = SnakeTileDirection::STD_Right;
	}

	this->frameCount++;

	if (this->frameCount >= this->activeSpeed)
	{
		this->frameCount = 0;

		this->Tick();
		this->FillGrid();
	}
}

void Snake::OnCleanup(MinigameManagerData data)
{
	for (int x = 0; x < grid.size(); x++)
	{
		grid[x].clear();
	}
	this->grid.clear();
	this->playerCells.clear();
}

void Snake::FillGrid()
{
	for (int i = 0; i < this->playerCells.size(); i++)
	{
		std::pair<int, int> pos = this->playerCells[i];

		if (i == 0)
		{
			this->grid[pos.first][pos.second].type = SnakeTileType::STT_Head;
		}
		else if (i == this->playerCells.size() - 1)
		{
			this->grid[pos.first][pos.second].type = SnakeTileType::STT_Tail;
		}
		else
		{
			this->grid[pos.first][pos.second].type = SnakeTileType::STT_Body;
		}
	}

	for (int x = 0; x < grid.size(); x++)
	{
		for (int y = 0; y < grid[x].size(); y++)
		{
			this->grid[x][y].cellParent->color = this->colors[this->grid[x][y].type];
		}
	}
}

void Snake::Tick()
{
	std::pair<int, int> nextHead = this->playerCells[0];

	switch (this->playerDirection)
	{
	case SnakeTileDirection::STD_Up:
		if (this->playerCells[0].second == 0)
		{
			this->currentState = MinigameState::MGS_Loss;
		}
		else
		{
			nextHead.second--;
		}
		break;
	case SnakeTileDirection::STD_Down:
		if (this->playerCells[0].second == this->sizeY - 1)
		{
			this->currentState = MinigameState::MGS_Loss;
		}
		else
		{
			nextHead.second++;
		}
		break;
	case SnakeTileDirection::STD_Left:
		if (this->playerCells[0].first == 0)
		{
			this->currentState = MinigameState::MGS_Loss;
		}
		else
		{
			nextHead.first--;
		}
		break;
	case SnakeTileDirection::STD_Right:
		if (this->playerCells[0].first == this->sizeX - 1)
		{
			this->currentState = MinigameState::MGS_Loss;
		}
		else
		{
			nextHead.first++;
		}
		break;
	}

	if (this->grid[nextHead.first][nextHead.second].type == SnakeTileType::STT_Food)
	{
		this->playerCells.insert(this->playerCells.begin(), nextHead);

		if (this->playerCells.size() >= this->goalLength)
		{
			this->currentState = MinigameState::MGS_Victory;
		}
		else
		{
			this->GenerateFood();
		}

		return;
	}
	else if (this->grid[nextHead.first][nextHead.second].type != SnakeTileType::STT_None)
	{
		this->currentState = MinigameState::MGS_Loss;
		return;
	}

	this->grid[this->playerCells[this->playerCells.size() - 1].first][this->playerCells[this->playerCells.size() - 1].second].type = SnakeTileType::STT_None;

	for (int i = this->playerCells.size() - 1; i > 0; i--)
	{
		this->playerCells[i].first = this->playerCells[i - 1].first;
		this->playerCells[i].second = this->playerCells[i - 1].second;
	}

	this->playerCells[0].first = nextHead.first;
	this->playerCells[0].second = nextHead.second;
}

void Snake::GenerateFood()
{
	while (true)
	{
		std::pair<int, int> chosenCell = std::pair<int, int>(RandomInt(0, this->sizeX), RandomInt(0, this->sizeY));

		if (this->grid[chosenCell.first][chosenCell.second].type == SnakeTileType::STT_None)
		{
			this->grid[chosenCell.first][chosenCell.second].type = SnakeTileType::STT_Food;
			this->foodCell = chosenCell;

			break;
		}
	}
}

void Snake::CreateHierarchy(MinigameManagerData data)
{
	AddDPadToHierarchy(RIF_ANY_D_PAD, { 65.0f, 130.0f, 0.0f }, 45.0f, *data.icons, *data.hierarchy);

	this->gridParent = data.hierarchy->CreateNode("Grid_Parent");

	float gridTotalX = (this->cellSize * this->sizeX);
	float gridTotalY = (this->cellSize * this->sizeY);

	NJS_POINT3 gridStart = { data.icons->xCenter, data.icons->yCenter };
	gridStart.x -= gridTotalX * 0.5f;
	gridStart.y -= gridTotalY * 0.5f;
	gridStart.y += 16.0f;
	float halfCellSize = this->cellSize * 0.5f;

	float gridCenterX = data.icons->xCenter;
	float gridCenterY = data.icons->yCenter + 16.0f;

	grid.resize(this->sizeX);
	for (int x = 0; x < grid.size(); x++)
	{
		grid[x].resize(this->sizeY);
		for (int y = 0; y < grid[x].size(); y++)
		{
			grid[x][y].cellParent = data.hierarchy->CreateNode("Grid_Cell", data.icons->GetAnim(MGI_Square), { this->cellSize * 1.0f, this->cellSize * 1.0f },
				{gridStart.x + (x * this->cellSize) + halfCellSize, gridStart.y + (y * this->cellSize) + halfCellSize }, this->gridParent);
		}
	}

	data.hierarchy->CreateNode("Grid_Wall", data.icons->GetAnim(MGI_Square), { this->cellSize / 2, gridTotalY + this->cellSize },
		{ gridStart.x + (-1 * this->cellSize) + halfCellSize * 1.5f, gridCenterY }, this->gridParent); // Left
	data.hierarchy->CreateNode("Grid_Wall", data.icons->GetAnim(MGI_Square), { this->cellSize / 2, gridTotalY + this->cellSize },
		{ gridStart.x + (this->sizeX * this->cellSize) + halfCellSize / 2, gridCenterY }, this->gridParent); // Right

	data.hierarchy->CreateNode("Grid_Wall", data.icons->GetAnim(MGI_Square), { gridTotalX + this->cellSize, this->cellSize / 2 },
		{ gridCenterX, gridStart.y + (-1 * this->cellSize) + halfCellSize * 1.5f }, this->gridParent); // Top
	data.hierarchy->CreateNode("Grid_Wall", data.icons->GetAnim(MGI_Square), { gridTotalX + this->cellSize, this->cellSize / 2 },
		{ gridCenterX, gridStart.y + (this->sizeY * this->cellSize) + halfCellSize / 2 }, this->gridParent); // Bottom
}