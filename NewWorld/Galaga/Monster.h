#pragma once
#include <ConsoleEngine/ConsoleObject.h>
#include <ConsoleEngine/ConsoleScreen.h>
class Monster : public ConsoleObject
{
protected:
	void Update() override;

	int count = 10;
	int2 Dir = Right;
};

