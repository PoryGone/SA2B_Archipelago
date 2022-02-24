#include "../pch.h"
#pragma once

class EmblemManager
{
public:
	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();
	void OnInputFunction();
	void OnControlFunction();

private:
	const HelperFunctions* _helperFunctions;
};