#include "../pch.h"
#include "Emblems.h"

void* endLevelSave_ptr = (void*)0x4457df;
void* updateSettingsSave_ptr = (void*)0x44390C;
const char nullop = '\x90';

void EmblemManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	WriteData<5>(endLevelSave_ptr, nullop);
	WriteData<5>(updateSettingsSave_ptr, nullop);
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