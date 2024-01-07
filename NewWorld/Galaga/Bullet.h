#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Bullet : public ConsoleObject
{
public:
	Bullet();
	void Move();
	void Move2();

	void Fire()
	{
		IsFire = true;
	}

	bool GetIsFire() 
	{
		return IsFire;
	}

private:
	bool IsFire = false;
};

