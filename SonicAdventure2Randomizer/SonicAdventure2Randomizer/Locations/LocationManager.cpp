#include "../pch.h"
#include "LocationManager.h"
#include "LocationData.h"

void LocationManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
}

void LocationManager::OnFrameFunction()
{
	this->_helperFunctions->SetDebugFontColor(0xFFF542C8);
	this->_helperFunctions->DisplayDebugString(NJM_LOCATION(100, 0), "On Frame Locations");

	this->_timer++;

	if (this->_timer > this->MEMORY_CHECK_TIME)
	{
		this->_timer = 0;


	}
}

void LocationManager::OnInputFunction()
{

}

void LocationManager::OnControlFunction()
{

}