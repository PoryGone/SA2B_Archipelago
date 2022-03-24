#include "../pch.h"
#include "Emblems.h"

std::string EmblemManager::DebugString = "";

void OverrideEmblemGet()
{
	EmblemManager::DebugString = "Emblem Got!";
}

//getEmblemExec seems to do vital things which the app does not like to skip
void* getEmblemExecReturn_ptr = (void*)0x4340CC;
void* getEmblemExecStart_ptr = (void*)0x798601;
void* getEmblemExecEnd_ptr = (void*)0x798680;
__declspec(naked) void GetEmblemCall()
{
	__asm
	{
		//push eax
		call OverrideEmblemGet
		jmp getEmblemExecReturn_ptr
		//pop eax
		//ret
	}
}

void EmblemManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
	DebugString = "On Frame Emblems";
	//WriteJump(getEmblemExecStart_ptr, getEmblemExecEnd_ptr);
}

void EmblemManager::OnFrameFunction()
{
	_helperFunctions->SetDebugFontColor(0xFFF542C8);
	_helperFunctions->DisplayDebugString(NJM_LOCATION(0, 1), DebugString.c_str());
}

void EmblemManager::OnInputFunction()
{

}

void EmblemManager::OnControlFunction()
{

}