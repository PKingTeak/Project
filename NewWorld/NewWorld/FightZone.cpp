#include "FightZone.h"
#include<iostream>
#include<conio.h>
#include"Player.h"
FightZone::FightZone()
{
	//MadeMonster
	NewMonster.SetName("���");
}





bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{

	int input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	if (true == _Second.IsDeath())
	{
		printf_s("���� ����."); // Name
		return true;
	}

	{
	int input =  _getch();

	}
	
	system("cls");
	_First.DamageLogic(_Second);
	_Top.StatusRender();
	_Bot.StatusRender();
	_Second.DamageRender();
	if (true == _First.IsDeath())
	{
		printf_s("���� ����."); 
		return true;
	}

	{
		int input = _getch();

	}

	system("cls");

	return false; // �̰� �־�� ��� �������ΰ� ǥ�����ټ� �ִ�.



}

void FightZone::In(Player& _Player)
{
	system("cls");
	while (true)
	{
		int PDice = _Player.Dice();
		int MDice = NewMonster.Dice();
		bool IsEnd = false;
		_Player.StatusRender();
		NewMonster.StatusRender();
		printf_s("�÷��̾� �ֻ��� ���� = %d\n", PDice);
		printf_s("���� �ֻ��� ���� = %d\n", MDice);
	

		if (PDice >= MDice)
		{
			printf_s("�÷��̾� ����!");
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
			
		}

		else if (PDice < MDice)
		{
			printf_s("���� ����!");
			FightLogic(NewMonster, _Player ,_Player, NewMonster);
		}
		
		if (true == IsEnd)
		{
			return;
		}
	}
		return;//�Լ������� �Ѵٴ� ���� �ᱹ ���� �Լ����� �Լ��� �����Ų�ٴ� �ǹ�
}
