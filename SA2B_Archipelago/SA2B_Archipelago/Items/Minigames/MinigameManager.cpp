#include "../../pch.h"
#include "MinigameManager.h"
#include "../../Archipelago/ArchipelagoManager.h"
#include "../ItemManager.h"
#include "../../Locations/LocationManager.h"

/*void DeleteUpgradeIcon_MG(ObjectMaster* obj)
{
	MinigameManager::GetInstance().EndMinigame();
	//MinigameManager::GetInstance().iconData.ReleaseIcons();
	//MinigameManager::GetInstance().textData.ReleaseIcons();
	MinigameManager::GetInstance().IconObjPtr = nullptr;
}

void DrawUpgradeIcon_MG(ObjectMaster* obj)
{
	if (GameState == GameStates_Ingame)
	{
		MinigameManager::GetInstance().Resume();
		MinigameManager::GetInstance().UpdateCurrentMinigame();
	}
	else if (MinigameManager::GetInstance().IsInFinalBoss() && GameState == GameStates_NormalRestart)
	{
		MinigameManager::GetInstance().EndMinigame();
	}
	else
	{
		MinigameManager::GetInstance().Pause();
	}
}

void DrawUpgradeIconMain_MG(ObjectMaster* obj)
{
	if (GameState != GameStates_LoadFinished && GameState != GameStates_LoadLevel)
	{
		return;
	}

	if (obj->Data1.Entity->Action == 0) {
		obj->DeleteSub = DeleteUpgradeIcon_MG;
		obj->DisplaySub_Delayed3 = DrawUpgradeIcon_MG;
		obj->Data1.Entity->Action = 1;
	}
}*/

void OnHierarchyCreation()
{
	return;
	auto manager = MinigameManager::GetInstance();
	manager.InitManagerData();
	if (GameState == GameStates_Ingame)
	{
		manager.Resume();
		//manager.UpdateCurrentMinigame();
	}
	else if (manager.IsInFinalBoss() && GameState == GameStates_NormalRestart)
	{
		manager.EndMinigame();
	}
	else
	{
		manager.Pause();
	}
}

void OnHierarchyDelete()
{
	return;
	MinigameManager::GetInstance().EndMinigame();
}

void MinigameManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	SpriteHierarchyManager& hierarchyManager = SpriteHierarchyManager::GetInstance();
	hierarchyItemPtr = hierarchyManager.GetHierarchyItem(HPT_Minigames);
	hierarchyItemPtr->callbacks = this;
	//hierarchyItemPtr->onSceneObjectCreation = OnHierarchyCreation;
	//hierarchyItemPtr->onSceneObjectDelete = OnHierarchyDelete;
	//hierarchyItemPtr->onBeforeFrameUpdate = [&](SpriteHierarchy& hierarchy) {this->UpdateCurrentMinigame(hierarchy);};
	//hierarchyItemPtr->onAfterFrameRender = this->PostRenderHierarchy; //[&](SpriteHierarchy& hierarchy) {this->PostRenderHierarchy(hierarchy);};
}

void MinigameManager::OnFrameFunction()
{
	/*if (!this->IconObjPtr && GameState == GameStates_Ingame)
	{
		this->iconData.LoadIcons();
		this->_data.icons = &this->iconData;
		this->textData.LoadIcons();
		this->_data.text = &this->textData;
		this->_data.hierarchy = &this->spriteHierarchy;
		this->_data.collision = &this->collisionManager;
		this->_data.hierarchy->iconData = &this->iconData;
		this->_data.timers = &this->timers;
		this->_data.stopwatches = &this->stopwatches;
		this->IconObjPtr = LoadObject(0, "MinigameIcons", DrawUpgradeIconMain_MG, LoadObj_Data1 | LoadObj_Data2);
		this->IconObjPtr->DeleteSub = DeleteUpgradeIcon_MG;
		this->IconObjPtr->MainSub = DrawUpgradeIconMain_MG;
		this->IconObjPtr->DisplaySub_Delayed3 = DrawUpgradeIcon_MG;
		this->IconObjPtr->Data1.Entity->Action = 1;
	}*/
}

void MinigameManager::OnInputFunction()
{
	// Debug Sound Test
	if (ArchipelagoManager::getInstance().IsDebug() && false)
	{
		static int DEBUG_SOUND_BANK{ 0 };
		static int DEBUG_SOUND_ID{ 0 };

		int res_ID = (int)((((DEBUG_SOUND_BANK) << 12) & 0xF000) + (DEBUG_SOUND_ID));

		std::string message = "Bank: " + std::to_string(DEBUG_SOUND_BANK) + " | ID: " + std::to_string(DEBUG_SOUND_ID);
		this->_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 1), message.c_str());

		if ((ControllersRaw->press & RawInputFlags::RIF_Down) != 0)
		{
			if (DEBUG_SOUND_ID > 0)
			{
				DEBUG_SOUND_ID -= 1;
			}
		}
		else if ((ControllersRaw->press & RawInputFlags::RIF_Up) != 0)
		{
			DEBUG_SOUND_ID += 1;
		}
		else if ((ControllersRaw->press & RawInputFlags::RIF_Left) != 0)
		{
			if (DEBUG_SOUND_BANK > 0)
			{
				DEBUG_SOUND_BANK -= 1;
			}
		}
		else if ((ControllersRaw->press & RawInputFlags::RIF_Right) != 0)
		{
			if (DEBUG_SOUND_BANK < 8)
			{
				DEBUG_SOUND_BANK += 1;
			}
		}
		else if ((ControllersRaw->press & RawInputFlags::RIF_Y) != 0)
		{
			PlaySoundProbably(res_ID, 0, 1, 1);
		}
	}
	// End Debug Sound Test

	this->_data.input = (RawInputFlags)ControllersRaw->on;
	this->_data.inputPress = (RawInputFlags)ControllersRaw->press;
	this->_data.inputRelease = (RawInputFlags)ControllersRaw->release;

	if (this->currentMinigame && !this->isPaused)
	{
		ControllersRaw->on &= ~RawInputFlags::RIF_ANY_D_PAD;
		ControllersRaw->press &= ~RawInputFlags::RIF_ANY_D_PAD;
		ControllersRaw->release &= ~RawInputFlags::RIF_ANY_D_PAD;
	}
}

void MinigameManager::InitManagerData()
{
	if (hierarchyItemPtr->hierarchy == nullptr)
	{
		PrintDebug("Hierarchy is null on data init");
	}
	SpriteHierarchyManager& hierarachyManager = SpriteHierarchyManager::GetInstance();
	this->_data.icons = &hierarachyManager.iconData;
	this->_data.text = &hierarachyManager.textData;
	this->_data.hierarchy = hierarchyItemPtr->hierarchy;
	this->_data.collision = &this->collisionManager;
	this->_data.timers = &this->timers;
	this->_data.stopwatches = &this->stopwatches;
}

void MinigameManager::OnSceneObjectCreation()
{
	PrintDebug("Scene Object Create");
	InitManagerData();
	if (GameState == GameStates_Ingame)
	{
		Resume();
		//manager.UpdateCurrentMinigame();
	}
	else if (IsInFinalBoss() && GameState == GameStates_NormalRestart)
	{
		PrintDebug("End Minigame: Boss Restart");
		EndMinigame();
	}
	else
	{
		Pause();
	}
}

void MinigameManager::OnSceneObjectDelete()
{
	PrintDebug("End Minigame: Delete");
	EndMinigame();
}

void MinigameManager::OnBeforeFrameUpdate(SpriteHierarchy& hierarchy)
{
	if (GameState == GameStates_Ingame)
	{
		this->Resume();
	}
	else if (IsInFinalBoss() && GameState == GameStates_NormalRestart)
	{
		PrintDebug("End Minigame: Boss Restart 2");
		this->EndMinigame();
	}
	else
	{
		this->Pause();
	}
	if (this->currentMinigame && !this->isPaused)
	{
		if (this->state == MinigameState::MGS_None)
		{
			this->_data.timers->clear();
			this->_data.stopwatches->clear();
			this->currentMinigame->OnGameStart(this->_data);
			this->minigameStart = std::clock();
			this->state = MinigameState::MGS_PreGame;
		}
		if (this->state == MinigameState::MGS_PreGame)
		{
			if (((std::clock() - minigameStart) / (double)CLOCKS_PER_SEC) > this->currentMinigame->pregameTime)
			{
				this->state = MinigameState::MGS_InProgress;
			}
		}
		if (this->state == MinigameState::MGS_InProgress || this->state == MinigameState::MGS_PreGame)
		{
			this->_data.managerState = this->state;
			this->currentMinigame->OnFrame(this->_data);
			//this->_data.hierarchy->OnFrame();
			//this->_data.hierarchy->Render();
			
		}
		if (this->currentMinigame->currentState == MinigameState::MGS_Victory ||
			this->currentMinigame->currentState == MinigameState::MGS_Draw ||
			this->currentMinigame->currentState == MinigameState::MGS_Loss)
		{
			this->state = this->currentMinigame->currentState;
			if (state == MinigameState::MGS_Victory)
			{
				this->HandleVictory();
			}
			else if (state == MinigameState::MGS_Loss)
			{
				this->HandleLoss();
			}
			PrintDebug("End Minigame: Normal Path");
			this->EndMinigame();
		}
	}
	//Debug Test Minigame
	else
	{
		/*if (_data.inputPress & RIF_Down)
		{
			//this->_data.isLocationCheck = true;
			this->SetDifficulty(MGD_Medium);
			this->currentMinigame = &this->pinball;
			this->currentMinigameItem = ItemValue::IV_PongTrap;
		}*/
	}
}

void MinigameManager::OnAfterFrameRender(SpriteHierarchy& hierarchy)
{
	if (this->currentMinigame && !this->isPaused && ArchipelagoManager::getInstance().IsDebug())
	{
		this->_data.collision->DebugDrawCollision(this->_data.icons);
	}
}

void MinigameManager::EndMinigame()
{
	if (this->_data.hierarchy == nullptr)
	{
		PrintDebug("Hierarchy ptr is null");
		return;
	}
	if (this->currentMinigame)
	{
		this->currentMinigame->OnCleanup(this->_data);
	}
	this->_data.collision->Reset();
	this->_data.hierarchy->ClearHierarchy();
	this->_data.isLocationCheck = false;
	this->currentMinigame = nullptr;
	this->state = MinigameState::MGS_None;
	this->currentMinigameItem = ItemValue::IV_Apple;
}

void MinigameManager::StartMinigame(ItemValue item, bool locationGame, bool linkedTrap)
{
	if (this->state != MinigameState::MGS_None)
	{
		return;
	}

	switch (item)
	{
	case ItemValue::IV_LiteratureTrap:
		this->currentMinigame = &this->literature;
		break;
	case ItemValue::IV_BeeTrap:
		this->currentMinigame = &this->bee;
		break;
	case ItemValue::IV_PongTrap:
		this->currentMinigame = &this->pong;
		break;
	case ItemValue::IV_BreakoutTrap:
		this->currentMinigame = &this->breakout;
		break;
	case ItemValue::IV_FishingTrap:
		this->currentMinigame = &this->fishing;
		break;
	case ItemValue::IV_TriviaTrap:
		this->currentMinigame = &this->trivia;
		break;
	case ItemValue::IV_PokemonTriviaTrap:
		this->currentMinigame = &this->pokemonTrivia;
		break;
	case ItemValue::IV_PokemonCountTrap:
		this->currentMinigame = &this->pokemonCount;
		break;
	case ItemValue::IV_NumberSequenceTrap:
		this->currentMinigame = &this->numberSequence;
		break;
	case ItemValue::IV_LightUpPathTrap:
		this->currentMinigame = &this->lightUpPath;
		break;
	case ItemValue::IV_PinballTrap:
		this->currentMinigame = &this->pinball;
		break;
	case ItemValue::IV_MathQuizTrap:
		this->currentMinigame = &this->mathQuiz;
		break;
	case ItemValue::IV_SnakeTrap:
		this->currentMinigame = &this->snake;
		break;
	case ItemValue::IV_InputSequenceTrap:
		this->currentMinigame = &this->inputSequence;
		break;
	case ItemValue::IV_Maria:
		this->currentMinigame = &this->finalBoss;
		break;
	}

	if (locationGame)
	{
		if (this->_bigDifficulty == MinigameDifficulty::MGD_Chaos)
		{
			this->_data.difficulty = (MinigameDifficulty)RandomInt(0, 3);
		}
		else
		{
			this->_data.difficulty = this->_bigDifficulty;
		}
	}
	else if (this->_baseDifficulty == MinigameDifficulty::MGD_Chaos)
	{
		this->_data.difficulty = (MinigameDifficulty)RandomInt(0, 3);
	}
	else
	{
		this->_data.difficulty = this->_baseDifficulty;
	}

	this->_data.isLocationCheck = locationGame;
	this->_data.isLinkedTrap = linkedTrap;
	this->currentMinigameItem = item;
}

void MinigameManager::HandleVictory()
{
	ItemValue itemToSend = ItemValue::IV_FiveRings;

	if (this->_data.difficulty == 1)
	{
		itemToSend = ItemValue::IV_TenRings;
	}
	else if (this->_data.difficulty == 2)
	{
		itemToSend = ItemValue::IV_TwentyRings;
	}

	if (this->currentMinigameItem == ItemValue::IV_Maria)
	{
		// TODO: RAS: Figure out how to keep the minigame rendering until the stage transitions to the ending

		AwardWin(0);

		return;
	}

	if (CurrentLevel == LevelIDs::LevelIDs_ChaoWorld && this->_data.isLinkedTrap)
	{
		// Don't send ring rewards for Chao Garden traps
	}
	else if (this->_data.isLinkedTrap)
	{
		// Don't count linked trap wins for goal completion
		ItemManager::getInstance().HandleJunk(itemToSend);
	}
	else if (CurrentLevel == LevelIDs::LevelIDs_ChaoWorld)
	{
		// Don't send ring rewards for Chao Garden traps
		ItemManager::getInstance().HandleMinigameCompletion(this->currentMinigameItem);
	}
	else if (this->_data.isLocationCheck)
	{
		// TODO: Generalize?

		LocationManager::getInstance().SendBigLocationCheck();
	}
	else
	{
		ItemManager::getInstance().HandleJunk(itemToSend);
		ItemManager::getInstance().HandleMinigameCompletion(this->currentMinigameItem);
	}

	StatsManager::GetInstance().MinigameWon();
}

void MinigameManager::HandleLoss()
{
	if (this->_data.isLocationCheck)
	{
		// Don't kill from failing location check
	}
	else
	{
		ArchipelagoManager::getInstance().SetDeathCause((DeathCause)this->currentMinigameItem);
		ArchipelagoManager::getInstance().AP_KillPlayer();
	}

	StatsManager::GetInstance().MinigameLost();
}

void MinigameManager::SetDifficulty(int difficulty)
{
	this->_baseDifficulty = (MinigameDifficulty)difficulty;
	this->_data.difficulty = this->_baseDifficulty;
}

void MinigameManager::SetBigDifficulty(int difficulty)
{
	this->_bigDifficulty = (MinigameDifficulty)difficulty;
}

bool MinigameManager::IsInFinalBoss()
{
	return this->currentMinigameItem == IV_Maria;
}

void MinigameManager::Pause()
{
	if (!this->isPaused)
	{
		this->isPaused = true;
		for (int i = 0; i < this->timers.size(); i++)
		{
			timers[i]->Pause();
		}
		for (int i = 0; i < this->stopwatches.size(); i++)
		{
			stopwatches[i]->Pause();
		}
		this->hierarchyItemPtr->isFrameUpdateActive = false;
		this->hierarchyItemPtr->isRenderActive = false;
	}

	if (this->currentMinigameItem == ItemValue::IV_Maria)
	{
		this->hierarchyItemPtr->isRenderActive = true;
		//this->_data.hierarchy->Render();
	}
}

void MinigameManager::Resume()
{
	if (this->isPaused)
	{
		this->isPaused = false;
		for (int i = 0; i < this->timers.size(); i++)
		{
			timers[i]->Resume();
		}
		for (int i = 0; i < this->stopwatches.size(); i++)
		{
			stopwatches[i]->Resume();
		}
		this->hierarchyItemPtr->isFrameUpdateActive = true;
		this->hierarchyItemPtr->isRenderActive = true;
	}
}
