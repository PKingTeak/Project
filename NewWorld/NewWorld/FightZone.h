#pragma once
#include"FightUnit.h"
#include"Monster.h"
#include"ZoneBase.h"

class FightZone :public ZoneBase
{
public :
	FightZone();

	void In(class Player& _Player);
private:
	Monster NewMonster = Monster();

	bool FightLogic(FightUnit& _Frist, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot);
};

