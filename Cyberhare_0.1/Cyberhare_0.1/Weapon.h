#pragma once
#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Item.h"
class Weapon : public Item
{
protected:
	int ammo;
	int damage;
	float reload;
//	float firerate;
public:
	int GetAmmo() { return this->ammo; }
	int GetDamage() { return this->damage; }
	float GetReload() { return this->reload; }
};

#endif // !_WEAPON_H_