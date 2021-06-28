#pragma once
#ifndef _SHOTGUN_H_
#define _SHOTGUN_H_

#include "Weapon.h"
#include "Hare.h"
class Shotgun : public Weapon
{
public: 
	Shotgun();
	void equip(Hare* hare) override;
	void use() override;
};

#endif // !_SHOTGUN_H_