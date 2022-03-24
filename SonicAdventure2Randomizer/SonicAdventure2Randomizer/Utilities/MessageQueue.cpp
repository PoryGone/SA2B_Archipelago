#include "../pch.h"
#include "MessageQueue.h"

void MessageQueue::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;
}

double GetTimeSinceMessage(TimeStampedMessage message)
{
	return (std::clock() - message.start) / (double)CLOCKS_PER_SEC;
}

void MessageQueue::OnFrameFunction()
{
	//Remove Old Messages
	for (int i = 0; i < MESSAGE_QUEUE_DISPLAY_COUNT; i++)
	{
		if (currentMessages[i].message != "" && GetTimeSinceMessage(currentMessages[i]) > MESSAGE_QUEUE_DISPLAY_TIME)
		{
			currentMessages[i] = TimeStampedMessage();
		}
	}
	//Move Messages Down
	for (int i = 1; i < MESSAGE_QUEUE_DISPLAY_COUNT; i++)
	{
		if (currentMessages[i-1].message == "" && currentMessages[i].message != "")
		{
			currentMessages[i - 1] = currentMessages[i];
			currentMessages[i] = TimeStampedMessage();
		}
	}
	//Add New Messages
	for (int i = 0; i < MESSAGE_QUEUE_DISPLAY_COUNT; i++)
	{
		if (currentMessages[i].message == "" && !messages.empty())
		{
			currentMessages[i] = messages.front();
			messages.pop();
			currentMessages[i].start = std::clock();
		}
	}
	//Display Messages
	for (int i = 0; i < MESSAGE_QUEUE_DISPLAY_COUNT; i++)
	{
		if (currentMessages[i].message != "")
		{
			_helperFunctions->SetDebugFontColor(currentMessages[i].color);
			_helperFunctions->DisplayDebugString(NJM_LOCATION(0, MESSAGE_QUEUE_START_LINE - 0), currentMessages[i].message.c_str());
		}
	}
}

void MessageQueue::AddMessage(std::string message, int color)
{
	messages.push(TimeStampedMessage(message, color));
}