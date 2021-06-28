#pragma once
#ifndef _SNIPEROPRICS_H_
#define _SNIPEROPRICS_H_

#include "Optics.h"
#include "Hare.h"

class SniperOptics : public Optics
{
private:
	float reflexes;
public:
	float GetReflexes() { return this->reflexes; }
	SniperOptics();
	void use() override;
	void equip(Hare* hare) override;
};

#endif // !_SNIPEROPRICS_H_