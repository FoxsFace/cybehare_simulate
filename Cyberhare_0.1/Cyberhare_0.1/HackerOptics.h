#pragma once
#ifndef _HACKEROPTICS_H_
#define _HACKEROPTICS_H_

#include "Optics.h"
#include "Hare.h"

class HackerOptics : public Optics
{
private:
	float flexibility;
public:
	float GetFlexibity() { return this->flexibility; }
	HackerOptics();
	void use() override;
	void equip(Hare* hare) override;
};
#endif // !_HACKEROPTICS_H_