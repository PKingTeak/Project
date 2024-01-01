#pragma once
#include"NameUnit.h"
class Weapon : public NameUnit 
{
public:
	
	inline int SetAtt(int _Att)// return int because Plus DamageLogic
	{
		Att = _Att;
		return Att;
	}

	inline int GetAtt() 
	{ // Set Att input WaeponDamage
		return Att;
	}
	inline void WeaponLevelUP(int _Level)
	{
		WeaponLevel += _Level;
	}
	inline void WeaponlevelDown(int _Level)
	{
		WeaponLevel -= _Level;
	}
	inline int SetWeaponLevel(int _Level)
	{
		WeaponLevel += _Level;
	}
	inline int GetWeaponLevel()
	{
		return WeaponLevel;
	}

private:
	int Att = 0;
	int WeaponLevel = 1;
};

