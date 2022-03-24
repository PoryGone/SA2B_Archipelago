#include "../pch.h"
#include <string>
#include <queue>
#include <ctime>
#pragma once

constexpr unsigned int MESSAGE_QUEUE_DISPLAY_COUNT = 5;
constexpr unsigned int MESSAGE_QUEUE_START_LINE = 30;
constexpr double MESSAGE_QUEUE_DISPLAY_TIME = 5.0;

struct TimeStampedMessage
{
public:
	TimeStampedMessage()
		: message(""), color(0xFF000000), start(0)
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
	void AddMessage(std::string message, int color = 0xFF000000);

private:
	const HelperFunctions* _helperFunctions;
	std::queue<TimeStampedMessage> messages;
	TimeStampedMessage currentMessages[MESSAGE_QUEUE_DISPLAY_COUNT];
};