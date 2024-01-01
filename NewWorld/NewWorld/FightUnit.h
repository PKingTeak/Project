#pragma once
#include"StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();

	inline bool IsDeath() const
	{
		return Hp <= 0;
	}
	inline int GetAtt() const
	{
		return MinAtt;
	}
	
	virtual int RandomAtt();
	 // int MonsterAtt();
	int Dice();
	void DamageLogic(FightUnit& _Unit);
	void DamageRender();
	
protected:
	int CurDamage = 0;
};

