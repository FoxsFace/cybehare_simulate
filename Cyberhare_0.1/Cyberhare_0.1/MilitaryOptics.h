#pragma once
#ifndef _MILITARYOPTICS_H_
#define _MILITARYOPTICS_H_

#include "Optics.h"
#include "Hare.h"

class MilitaryOptics : public Optics
{
private:
	float durability;
public:
	float GetDurability() { return this->durability; }
	MilitaryOptics();
	void use() override;
	void equip(Hare* hare) override;
};

#endif // !_MILITARYOPTICS_H_