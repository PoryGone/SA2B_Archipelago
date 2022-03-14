#include "../pch.h"
#pragma once

class LocationManager
{
public:
	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();
	void OnInputFunction();
	void OnControlFunction();

private:
	const HelperFunctions* _helperFunctions;

	unsigned int _timer = 0;

	const unsigned int MEMORY_CHECK_TIME = 600;
};