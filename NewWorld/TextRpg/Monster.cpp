#include "Monster.h"

void Monster::FightStart(FightUnit& _Player)
{
	int MonsterExp = GetRandomExp(100, 1000);
	SetExp(MonsterExp);
	HpReset();
	RandomGold(1000, 10000);
	

}

void Monster::FightEnd(/*Monster* const this,*/ FightUnit& _Player)
{


	// �����ϰ� ����ġ�� ���ؾ� �Ѵ�.

	/*NewMonster.*/
	/*this->*/
}