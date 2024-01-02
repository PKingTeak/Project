#include "Player.h"
#include <iostream>

Player::Player()
{
	// 지금 테스트 코드
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

void Player::StatusRenderStart()
{
	LevelUpExp = 1000 * Level; //경험치 통
	printf_s("레벨 %d 경험치량(%d / %d)\n", Level, CurExp ,LevelUpExp);
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp() + Level;
	return CurDamage;
}
void Player::LevelUp(int _Exp)
{//만약에 값이 바뀌면 1000*level로 놓자
	LevelUpExp = 1000 * Level; //경험치 통
	CurExp += _Exp;

	if (CurExp >= LevelUpExp)
	{
		Level++;
		CurExp = CurExp - LevelUpExp;
		
	}
	// 레벨업 구현 
	
}

void Player::FightEnd(FightUnit& _Ohter)
{
	int Gold = _Ohter.GetGold();
	printf_s("플레이어가 %d 골드를 벌었습니다.\n", Gold);
	AddGold(Gold);

	int ExpNum = _Ohter.GetExp();
	printf_s("플레이어가 %d 경험치를 얻었습니다.\n", ExpNum);
	LevelUp(ExpNum);

}
int Player::SkillAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp() + (Level*Mp) +Level;
	Mp -= 20;
	return CurDamage;

}