#pragma once
#include"NameUnit.h"

class StatusUnit :public NameUnit
{
public:
	void StatusRender();

protected:
	int Hp = 200;
	int MaxHp = 500;
	int MaxAtt = 20;
	int MinAtt = 10;
	int Gold = 0;
	int Luck = 0;
	int Level = 0;

};

