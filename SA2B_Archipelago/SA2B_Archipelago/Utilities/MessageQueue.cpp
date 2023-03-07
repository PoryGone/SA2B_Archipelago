#include "../pch.h"
#include "MessageQueue.h"

void MessageQueue::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

	for (int i = 0; i < MAX_MESSAGE_QUEUE_DISPLAY_COUNT; i++)
	{
		this->currentMessages.push_back(TimeStampedMessage());
	}
}

double GetTimeSinceMessage(TimeStampedMessage message)
{
	return (std::clock() - message.start) / (double)CLOCKS_PER_SEC;
}

void MessageQueue::OnFrameFunction()
{
	//Remove Old Messages
	for (int i = 0; i < this->_displayCount; i++)
	{
		if (!currentMessages[i].message.empty() && GetTimeSinceMessage(currentMessages[i]) > this->_displayDuration)
		{
			currentMessages[i] = TimeStampedMessage();
		}
	}
	//Move Messages Down
	for (int i = 1; i < this->_displayCount; i++)
	{
		if (!currentMessages[i].message.empty())
		{
			int b = 1;
			while (i - b > 1 && currentMessages[i - b - 1].message.empty())
			{
				b++;
			}
			if (currentMessages[i - b].message.empty())
			{
				currentMessages[i - b] = currentMessages[i];
				currentMessages[i] = TimeStampedMessage();
			}
		}
	}
	//Add New Messages
	for (int i = 0; i < this->_displayCount; i++)
	{
		if (currentMessages[i].message.empty() && !messages.empty())
		{
			currentMessages[i] = messages.front();
			messages.pop();
			currentMessages[i].start = std::clock();
		}
	}
	//Display Messages
	for (int i = 0; i < this->_displayCount; i++)
	{
		if (!currentMessages[i].message.empty())
		{
			_helperFunctions->SetDebugFontSize(this->_debugFontSize);
			_helperFunctions->SetDebugFontColor(currentMessages[i].color);
			_helperFunctions->DisplayDebugString(NJM_LOCATION(0, this->_startLine + i), currentMessages[i].message.c_str());
		}
	}
}

void MessageQueue::SetFontSize(int newFontSize)
{
	if (newFontSize == 0)
	{
		return;
	}

	this->_debugFontSize = newFontSize;

	_helperFunctions->SetDebugFontSize(this->_debugFontSize);
}

void MessageQueue::SetDisplayCount(int newDisplayCount)
{
	if (newDisplayCount == 0)
	{
		return;
	}

	this->_displayCount = max(1, min(newDisplayCount, MAX_MESSAGE_QUEUE_DISPLAY_COUNT));

	this->_startLine = ((VerticalResolution / this->_debugFontSize) - this->_displayCount);
}

void MessageQueue::SetDisplayColor(int newDisplayColor)
{
	if (newDisplayColor == 0xFF000000)
	{
		return;
	}

	this->_displayColor = newDisplayColor;
}

void MessageQueue::SetDisplayDuration(float newDisplayDuration)
{
	if (newDisplayDuration == 0)
	{
		return;
	}

	this->_displayDuration = newDisplayDuration;
}

void MessageQueue::AddMessage(std::string message, int color)
{
	if (color == 0)
	{
		color = this->_displayColor;
	}

	messages.push(TimeStampedMessage(message, color));
}