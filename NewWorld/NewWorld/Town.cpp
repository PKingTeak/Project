#include "Town.h"
#include<iostream>
#include<conio.h>
#include"Player.h"





void Town::In(Player& _Player)
{
	system("cls");
	_Player.StatusRender();
	printf("������ �����Ͽ����ϴ�.\n");
	printf("1.��ȭ�ϱ�\n");
	printf("2.ġ���ϱ�.\n");
	printf("3.������\n");


	while (true)
	{
	int input = _getch();

		switch (input)
		{
		case '1':

			break;
		case '2':
			break;
		case'3':
			return;
		}

	}

	
}