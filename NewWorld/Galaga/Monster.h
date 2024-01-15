#pragma once
#include <ConsoleEngine/ConsoleObject.h>
#include <ConsoleEngine/ConsoleScreen.h>
class Monster : public ConsoleObject
{
protected:
	void Update() override;

	int DownValue = 10;
	bool Right = false;
};

