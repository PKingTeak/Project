#pragma once
#include "FightUnit.h"
#include "Weapon.h"

class Player : public FightUnit
{
public:
	Player();

	// �̷� ��쿡 public���� �Ѵ�.
	// ������ ��� �ִ� ��쿡��.
	// ���� �̷���.
	// �����ͷ� �ؾ� �մϴ�.

	// ���� ������� �������� ����
	// �̰� ������ �ؾ�����
	// �����ͷ� �ؾ�����.

	// ���� �����ϰų� �������� ���� ���ɼ��� �ִٸ� => ������
	// ����� ������� �ʾƾ� �ϸ� => ����
	// ������ �����Ҵ��� ����� �ʾұ� ������ 
	Weapon Weapon;

	void FightEnd(FightUnit& _Ohter) override;

	void StatusRenderStart() override;

	inline void SetLevel(int _Exp)
	{
		CurExp += _Exp;
	}
	inline int GetLevel() //������ ����ġ 
	{
		return LevelUpExp;
	}
	void LevelUp(int _Exp);
	int SkillAtt();
	
protected:
	int GetRandomAtt() override;

private:
	int Level = 1;
	int CurExp = 0;
	int Mp = 100;
	
	// �̰� ���⿡ �����ϸ� ���� �������Ѵ�.
	int LevelUpExp = 1000;
};

