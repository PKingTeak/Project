#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Player : public ConsoleObject
{
public:
	void KeyInput();
	void KeyInput2();
	bool GetIsFire() 
	{
		return IsFire;
	}

private:
	bool IsFire = false;
};

