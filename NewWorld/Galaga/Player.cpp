#include "Player.h"

#include <conio.h>

void Player::KeyInput()
{
	IsFire = false;

	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	switch (Select)
	{
	case 'A':
	case 'a':
		AddPos(Left);
		break;
	case 'S':
	case 's':
		AddPos(Down);
		break;
	case 'W':
	case 'w':
		AddPos(Up);
		break;
	case 'D':
	case 'd':
		AddPos(Right);
		break;
	case 'Q':
	case 'q':
		IsFire = true;
		break;
	default:
		break;
	}
}

void Player::KeyInput2()
{
	IsFire = false;

	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	switch (Select)
	{
	case '4':
	case 'j':
		AddPos(Left);
		break;
	case '5':
	case 'k':
		AddPos(Down);
		break;
	case '8':
	case 'i':
		AddPos(Up);
		break;
	case '6':
	case 'l':
		AddPos(Right);
		break;
	case 'P':
	case 'p':
		IsFire = true;
		break;
	default:
		break;
	}
}