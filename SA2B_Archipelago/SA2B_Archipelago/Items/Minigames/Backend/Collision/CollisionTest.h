#pragma once
#include <string>
#include "BoundingBox.h"

class CollisionTest 
{
public:
	void RunTests();
private:
	void AssertTrue(bool value, std::string testName);
	void AssertFalse(bool value, std::string testName);
	bool hasRun = false;
};
