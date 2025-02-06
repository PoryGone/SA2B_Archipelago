#include "../../../pch.h"
#include "Snake.h"

void Snake::OnGameStart(MinigameManagerData data)
{
	this->currentState = MGS_InProgress;
	this->localState = SnakeState::SS_Game;
	this->endingTimer = 120;

	PlayUnshuffledVoice(2, 671);

	this->playerCells.clear();
	this->playerCells.push_back(std::pair<int, int>(7, 4));
	this->playerCells.push_back(std::pair<int, int>(6, 4));
	this->playerCells.push_back(std::pair<int, int>(5, 4));

	this->activeSpeed = this->speeds[data.difficulty];
	this->goalLength = this->goalLengths[data.difficulty];
	this->playerDirection = SnakeTileDirection::STD_Right;

	CreateHierarchy(data);
	this->GenerateFood();

	FillGrid(data);
}

void Snake::OnFrame(MinigameManagerData data)
{
	if (data.managerState != MGS_InProgress)
	{
		return;
	}

	if (this->localState == SnakeState::SS_EndingWin)
	{
		if (this->resultNode->color.a < 1.0f)
		{
			this->resultNode->SetEnabled(true);
			this->resultNode->anim = data.icons->GetAnim(MGI_Green_Check);
			this->resultNode->color.a += 1.0f / 30.0f;
			this->resultNode->displaySize = Point3MoveTowards(this->resultNode->displaySize, { 128.0f, 128.0f }, 72.0f / 30.0f);
		}
		else
		{
			if (this->endingTimer == 120)
			{
				PlaySoundProbably((int)MinigameSounds::RankReveal, 0, 0, 0);
			}

			this->endingTimer--;

			if (this->endingTimer <= 0)
			{
				this->currentState = MinigameState::MGS_Victory;
			}
		}
		return;
	}
	else if (this->localState == SnakeState::SS_EndingLose)
	{
		if (this->resultNode->color.a < 1.0f)
		{
			this->resultNode->SetEnabled(true);
			this->resultNode->anim = data.icons->GetAnim(MGI_F_Rank);
			this->resultNode->color.a += 1.0f / 30.0f;
			this->resultNode->displaySize = Point3MoveTowards(this->resultNode->displaySize, { 128.0f, 128.0f }, 72.0f / 30.0f);
		}
		else
		{
			if (this->endingTimer == 120)
			{
				PlaySoundProbably((int)MinigameSounds::RankReveal, 0, 0, 0);
			}

			this->endingTimer--;

			if (this->endingTimer <= 0)
			{
				this->currentState = MinigameState::MGS_Loss;
			}
		}
		return;
	}

	if (this->playerCells.size() >= 2)
	{
		if ((data.inputPress & RIF_Up) && (this->playerCells[0].second - 1 != this->playerCells[1].second))
		{
			playerDirection = SnakeTileDirection::STD_Up;
		}
		if ((data.inputPress & RIF_Down) && (this->playerCells[0].second + 1 != this->playerCells[1].second))
		{
			playerDirection = SnakeTileDirection::STD_Down;
		}
		if ((data.inputPress & RIF_Left) && (this->playerCells[0].first - 1 != this->playerCells[1].first))
		{
			playerDirection = SnakeTileDirection::STD_Left;
		}
		if ((data.inputPress & RIF_Right) && (this->playerCells[0].first + 1 != this->playerCells[1].first))
		{
			playerDirection = SnakeTileDirection::STD_Right;
		}
	}

	this->frameCount++;

	if (this->frameCount >= this->activeSpeed)
	{
		this->frameCount = 0;

		this->Tick();
		this->FillGrid(data);
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

void Snake::FillGrid(MinigameManagerData data)
{
	for (int i = 0; i < this->playerCells.size(); i++)
	{
		std::pair<int, int> pos = this->playerCells[i];
		this->grid[pos.first][pos.second].mirror = false;

		if (i == 0)
		{
			std::pair<int, int> nextPos = this->playerCells[i + 1];
			this->grid[pos.first][pos.second].type = SnakeTileType::STT_Head;

			if (nextPos.first > pos.first)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Left;
			}
			else if (nextPos.first < pos.first)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Right;
			}
			else if(nextPos.second > pos.second)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Up;
			}
			else if(nextPos.second > pos.second)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Down;
			}
		}
		else if (i == this->playerCells.size() - 1)
		{
			std::pair<int, int> prevPos = this->playerCells[i - 1];
			this->grid[pos.first][pos.second].type = SnakeTileType::STT_Tail;
			if (prevPos.first < pos.first)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Left;
			}
			else if (prevPos.first > pos.first)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Right;
			}
			else if (prevPos.second < pos.second)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Up;
			}
			else if (prevPos.second > pos.second)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Down;
			}
		}
		else
		{
			std::pair<int, int> prevPos = this->playerCells[i - 1];
			std::pair<int, int> nextPos = this->playerCells[i + 1];

			if (prevPos.first == nextPos.first || prevPos.second == nextPos.second)
			{
				this->grid[pos.first][pos.second].type = SnakeTileType::STT_BodyStraight;
			}
			else
			{
				this->grid[pos.first][pos.second].type = SnakeTileType::STT_BodyTurn;
			}

			if (prevPos.first < pos.first)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Left;

				if (nextPos.second < pos.second)
				{
					this->grid[pos.first][pos.second].mirror = true;
				}
			}
			else if (prevPos.first > pos.first)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Right;

				if (nextPos.second > pos.second)
				{
					this->grid[pos.first][pos.second].mirror = true;
				}
			}
			else if (prevPos.second < pos.second)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Up;

				if (nextPos.first > pos.first)
				{
					this->grid[pos.first][pos.second].mirror = true;
				}
			}
			else if (prevPos.second > pos.second)
			{
				this->grid[pos.first][pos.second].direction = SnakeTileDirection::STD_Down;

				if (nextPos.first < pos.first)
				{
					this->grid[pos.first][pos.second].mirror = true;
				}
			}
		}
	}

	for (int x = 0; x < grid.size(); x++)
	{
		for (int y = 0; y < grid[x].size(); y++)
		{
			this->grid[x][y].cellParent->color.a = 1.0f;
			if (this->grid[x][y].type != SnakeTileType::STT_None)
			{
				MinigameIcon icon = this->snakeIcons[this->grid[x][y].type - 1];
				this->grid[x][y].cellParent->anim = data.icons->GetAnim(icon);
				if (this->grid[x][y].mirror)
				{
					icon = (MinigameIcon)((int)icon + 1);
					this->grid[x][y].cellParent->anim = data.icons->GetAnim(icon);
				}
				if (this->grid[x][y].direction != SnakeTileDirection::STD_None)
				{
					this->grid[x][y].cellParent->SetRotation((this->grid[x][y].direction - 1) * 90.0f);
				}
				else
				{
					this->grid[x][y].cellParent->SetRotation(0.0f);
				}
			}
			else
			{
				this->grid[x][y].cellParent->color.a = 0.0f;
			}
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
			PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
			this->localState = SnakeState::SS_EndingLose;
		}
		else
		{
			nextHead.second--;
		}
		break;
	case SnakeTileDirection::STD_Down:
		if (this->playerCells[0].second == this->sizeY - 1)
		{
			PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
			this->localState = SnakeState::SS_EndingLose;
		}
		else
		{
			nextHead.second++;
		}
		break;
	case SnakeTileDirection::STD_Left:
		if (this->playerCells[0].first == 0)
		{
			PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
			this->localState = SnakeState::SS_EndingLose;
		}
		else
		{
			nextHead.first--;
		}
		break;
	case SnakeTileDirection::STD_Right:
		if (this->playerCells[0].first == this->sizeX - 1)
		{
			PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
			this->localState = SnakeState::SS_EndingLose;
		}
		else
		{
			nextHead.first++;
		}
		break;
	}

	if (this->grid[nextHead.first][nextHead.second].type >= SnakeTileType::STT_Food)
	{
		this->playerCells.insert(this->playerCells.begin(), nextHead);

		if (this->playerCells.size() >= this->goalLength)
		{
			PlaySoundProbably((int)MinigameSounds::CollectEmblem, 0, 0, 0);
			this->localState = SnakeState::SS_EndingWin;
		}
		else
		{
			PlaySoundProbably((int)MinigameSounds::CollectAnimal, 0, 0, 0);
			this->GenerateFood();
		}

		return;
	}
	else if (this->grid[nextHead.first][nextHead.second].type != SnakeTileType::STT_None)
	{
		PlaySoundProbably((int)MinigameSounds::Explosion, 0, 0, 0);
		this->localState = SnakeState::SS_EndingLose;
		return;
	}

	this->grid[this->playerCells[this->playerCells.size() - 1].first][this->playerCells[this->playerCells.size() - 1].second].type = SnakeTileType::STT_None;
	this->grid[this->playerCells[this->playerCells.size() - 1].first][this->playerCells[this->playerCells.size() - 1].second].direction = SnakeTileDirection::STD_None;

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
			if (RandomInt(0, 2) == 0)
			{
				this->grid[chosenCell.first][chosenCell.second].type = SnakeTileType::STT_Food2;
			}
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

	this->resultNode = data.hierarchy->CreateNode("Result", data.icons->GetAnim(MGI_Green_Check), { 200, 200 },
													{ data.icons->xCenter, data.icons->yCenter });
	this->resultNode->color.a = 0.0f;
	this->resultNode->SetEnabled(false);
}