#include "../pch.h"
#include "Emblems.h"

void* endLevelSave_ptr = (void*)0x4457df;
void* updateSettingsSave_ptr = (void*)0x44390C;
void* exitChaoGardenSave_ptr = (void*)0x4448E1;
void* winChaoKarateSave_ptr = (void*)0x542C0C;
//void* winChaoRaceSave_ptr = (void*)0x46F8E4; // This seems like a generic helper function that gets called all the time
const char nullop = '\x90';

void EmblemManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	WriteData<5>(endLevelSave_ptr, nullop);
	WriteData<5>(updateSettingsSave_ptr, nullop);
	WriteData<5>(exitChaoGardenSave_ptr, nullop);
	WriteData<5>(winChaoKarateSave_ptr, nullop);
	//WriteData<2>(winChaoRaceSave_ptr, nullop);
}

void EmblemManager::OnFrameFunction()
{

}

void EmblemManager::OnInputFunction()
{

}

void EmblemManager::OnControlFunction()
{

}