#pragma once
#include"FightUnit.h"
#include"Weapon.h"

class Player : public FightUnit
{
public:
	Player();
	

	Weapon NewWeapon;

private:
	int RandomAtt() override; 
	//override in FightUnit VirtualFuntion

	
	


};

