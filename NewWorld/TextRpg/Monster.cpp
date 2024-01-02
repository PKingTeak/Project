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


	// 랜덤하게 경험치를 정해야 한다.

	/*NewMonster.*/
	/*this->*/
}