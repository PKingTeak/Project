#include "Town.h"
#include<iostream>
#include<conio.h>
#include"Player.h"





void Town::In(Player& _Player)
{
	system("cls");
	_Player.StatusRender();
	printf("마을에 입장하였습니다.\n");
	printf("1.강화하기\n");
	printf("2.치료하기.\n");
	printf("3.나가기\n");


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