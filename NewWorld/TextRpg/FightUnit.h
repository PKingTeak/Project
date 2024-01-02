#pragma once
#include "StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();

	// Get
	inline bool IsDeath() const
	{
		return Hp <= 0;
	}

	inline int GetMinAtt() const
	{
		return MinAtt;
	}


	int GetRandomSpeed() const;

	// Fight¿ë ÇÔ¼ö
	void DamageLogic(FightUnit& _Unit);

	void DamageRender();

	virtual int GetRandomAtt();
	virtual void FightStart(FightUnit& _Other) {}
	virtual void FightEnd(FightUnit& _Other) {}

protected:
	int CurDamage = 0;

private:
};
