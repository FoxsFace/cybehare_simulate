#include "Paws_Default.h"

Paws_Default::Paws_Default()
{
	this->cost = 200;
	this->durability = 2;
	this->flexibility = 4;
	this->name = "Default Paws";
}

void Paws_Default::use()
{
	//
}

void Paws_Default::equip(Hare* hare)
{
	if (hare->GetCash() >= this->GetCost())
	{
		hare->SetCash(hare->GetCash() - this->GetCost());
		hare->SetFlexibility(this->flexibility);
		hare->SetDurability(this->durability);
		hare->SetLegs(this);
	}
}