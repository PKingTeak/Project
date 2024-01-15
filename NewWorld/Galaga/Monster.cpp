#include "Monster.h"
#include "ContentsEnum.h"
#include <ConsoleEngine/EngineCore.h>

void Monster::Update()
{
	

	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{//ÃÑ¾Ë
		Destroy();
		CollisionObject->Destroy();
	}

	//AddPos(Right);
	int2 monsterPos = GetPos();
	EngineCore* Core = GetCore();

	

	if(monsterPos.X >= 0 && monsterPos.X<=20)
	{
		AddPos(Dir);
		--DownValue;
		if (DownValue < 0)
		{
		AddPos(Down);
		DownValue = 10;
		int a = 0;
		}
		if (monsterPos.X == 20)
		{
			AddPos(Left);
		}

		 
	}
	//else if(monsterPos.X <)

	
	
	
	//--RightValue;
	//--LeftValue;
	
	//if (0 >= RightValue)
	//{
	//	AddPos(Right);
	//	RightValue = 5;
	//}
//	if (0 >= DownValue)
//	{
//		AddPos(Down);
//		DownValue = 10;
//		RightValue = 10;
//		LeftValue = 1;
//	}
//	if (0 >= LeftValue)
//	{
//		AddPos(Left);
//
//	}

	
}