#include "FightUnit.h"
#include<iostream>
FightUnit::FightUnit()
{

}

int FightUnit::RandomAtt()
{
	int Damage = rand() % (MaxAtt - MinAtt) + MinAtt;
	CurDamage = Damage;
	return CurDamage;
	//Player Att
}
/*
int FightUnit::MonsterAtt()
{
	int Damage = MinAtt;
	CurDamage = Damage * Level;
	return CurDamage;
	//MonsterDamage
}
*/

int FightUnit::Dice()
{
	Luck = rand() % 6;
	return Luck;
	//turn choice
}


void FightUnit::DamageLogic(FightUnit& _Unit)
{
	//not -
	Hp -= _Unit.RandomAtt();
	if (Hp < 0)
	{
		Hp = 0;
	}

}
void FightUnit::DamageRender()
{
	printf("%s가 %d로 공격했습니다.", Name,CurDamage);
}
