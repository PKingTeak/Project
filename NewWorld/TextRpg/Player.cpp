#include "Player.h"
#include <iostream>

Player::Player()
{
	// ���� �׽�Ʈ �ڵ�
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

void Player::StatusRenderStart()
{
	LevelUpExp = 1000 * Level; //����ġ ��
	printf_s("���� %d ����ġ��(%d / %d)\n", Level, CurExp ,LevelUpExp);
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp() + Level;
	return CurDamage;
}
void Player::LevelUp(int _Exp)
{//���࿡ ���� �ٲ�� 1000*level�� ����
	LevelUpExp = 1000 * Level; //����ġ ��
	CurExp += _Exp;

	if (CurExp >= LevelUpExp)
	{
		Level++;
		CurExp = CurExp - LevelUpExp;
		
	}
	// ������ ���� 
	
}

void Player::FightEnd(FightUnit& _Ohter)
{
	int Gold = _Ohter.GetGold();
	printf_s("�÷��̾ %d ��带 �������ϴ�.\n", Gold);
	AddGold(Gold);

	int ExpNum = _Ohter.GetExp();
	printf_s("�÷��̾ %d ����ġ�� ������ϴ�.\n", ExpNum);
	LevelUp(ExpNum);

}
int Player::SkillAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp() + (Level*Mp) +Level;
	Mp -= 20;
	return CurDamage;

}