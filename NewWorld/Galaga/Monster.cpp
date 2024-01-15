#include "Monster.h"
#include "ContentsEnum.h"
#include <ConsoleEngine/EngineCore.h>

void Monster::Update()
{


	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{//총알
		Destroy();
		CollisionObject->Destroy();
	}
	int2 MonsterPos = GetPos();
	EngineCore* Core = GetCore();
	int changeX = Core->Screen.GetScreenX();
	int changeY = Core->Screen.GetScreenY();


	AddPos(Dir);


	if (MonsterPos.X >= changeX && Dir == Right)
	{
		Dir = Left;
		AddPos(Down);
	}
	else if (MonsterPos.X <= 0 && Dir == Left)
	{
		Dir = Right;
		AddPos(Down);

	}
	count = 10;

	if (MonsterPos.Y >= changeY)
	{
		//게임종료
	}



	//--count;
	//if (count <= 0)
	//{
	//	AddPos(Down);
	//	if (Dir == Right)
	//	{
	//		Dir = Left;
	//	}
	//	else if (Dir == Left)
	//	{
	//		Dir = Right;
	//
	//	}
	//	count = 10;
	//}
		//if (MonsterPos.Y >= changer)
		//{
		//	
		//}

		/*
		AddPos(Dir);
		--count;

		*/
}