#include "../pch.h"
#include <string>
#include <queue>
#include <ctime>
#pragma once

constexpr unsigned int MAX_MESSAGE_QUEUE_DISPLAY_COUNT = 15;
constexpr double MESSAGE_QUEUE_DISPLAY_TIME = 10.0;

struct TimeStampedMessage
{
public:
	TimeStampedMessage()
		: message(""), color(0xFFF542C8), start(0)
	{}
	TimeStampedMessage(std::string _message, int _color)
		: message(_message), color(_color), start(0)
	{}
	std::string message;
	int color;
	std::clock_t start;
};

class MessageQueue
{
public:
	static MessageQueue& GetInstance()
	{
		static MessageQueue instance;
		return instance;
	}
	void OnInitFunction(const char* path, const HelperFunctions& helperFunctions);
	void OnFrameFunction();
	void AddMessage(std::string message, int color = 0xFFF542C8);

	void SetFontSize(int newFontSize);
	void SetDisplayCount(int newDisplayCount);

	int GetFontSize() { return this->_debugFontSize; }

private:

	int _startLine = 35;
	int _displayCount = 5;
	int _debugFontSize = 12;

	const HelperFunctions* _helperFunctions;
	std::queue<TimeStampedMessage> messages;
	std::vector<TimeStampedMessage> currentMessages;
};