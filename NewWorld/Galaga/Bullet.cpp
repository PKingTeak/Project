#include "Bullet.h"

Bullet::Bullet()
{
	SetRenderChar('-');
}

void Bullet::Move()
{
	if (false == IsFire)
	{
		return;
	}

	AddPos(Right);
}

void Bullet::Move2()
{
	if (false == IsFire)
	{
		return;
	}
	AddPos(Left);
}
