#pragma once
#ifndef _BODIES_H_
#define _BODIES_H_

#include "Item.h"
#include "Hare.h"

class Bodies : public Item
{
protected:
	int armor;
	float durability;
public:
	void Damage(float damage) { this->armor -= damage; }
	int GetArmor() { return this->armor; }
	float GetDurability() { return this->durability; }
};

#endif // !_BODIES_H_