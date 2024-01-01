#include "FightZone.h"
#include<iostream>
#include<conio.h>
#include"Player.h"
FightZone::FightZone()
{
	//MadeMonster
	NewMonster.SetName("고블린");
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
		printf_s("게임 종료."); // Name
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
		printf_s("게임 종료."); 
		return true;
	}

	{
		int input = _getch();

	}

	system("cls");

	return false; // 이게 있어야 계속 전투중인걸 표시해줄수 있다.



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
		printf_s("플레이어 주사위 숫자 = %d\n", PDice);
		printf_s("몬스터 주사위 숫자 = %d\n", MDice);
	

		if (PDice >= MDice)
		{
			printf_s("플레이어 선공!");
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
			
		}

		else if (PDice < MDice)
		{
			printf_s("몬스터 선공!");
			FightLogic(NewMonster, _Player ,_Player, NewMonster);
		}
		
		if (true == IsEnd)
		{
			return;
		}
	}
		return;//함수리턴을 한다는 것은 결국 메인 함수에서 함수를 종료시킨다는 의미
}
