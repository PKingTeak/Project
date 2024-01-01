#pragma once
#include "ZoneBase.h"
class Town:public ZoneBase
{
public:
	void In(Player& _Player) override;

	void WeaponUP(Player& _Player);
	


};

