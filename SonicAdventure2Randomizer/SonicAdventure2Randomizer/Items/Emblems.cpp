#include "../pch.h"
#include "Emblems.h"

void EmblemManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	//WriteJump()
}

void OverrideEmblemGet()
{
	
}

void EmblemManager::OnFrameFunction()
{
	_helperFunctions->SetDebugFontColor(0xFFF542C8);
	_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 0), "On Frame Emblems");
	if (ScoreP1 < 1000)
	{
		ScoreP1 += 1;
	}
	if (ScoreP1 > 1000)
	{
		GravityDirection = GravityDirectionType::UpwardY;
		//LoadEmblemgetModule();
	}
}

void EmblemManager::OnInputFunction()
{

}

void EmblemManager::OnControlFunction()
{

}