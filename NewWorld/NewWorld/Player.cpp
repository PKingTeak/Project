#include "Player.h"

Player::Player()
{
	NewWeapon.SetName("SteelSword");
	NewWeapon.SetAtt(10);
}

int Player::RandomAtt() 
{
	CurDamage = FightUnit::GetAtt() + (NewWeapon.GetAtt()* NewWeapon.GetWeaponLevel());
	// PlayerAtt = PlayerAtt + WeaPonAtt

	return CurDamage;
}
//using Weapon
