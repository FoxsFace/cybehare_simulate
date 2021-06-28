#include "Body_Default.h"

Body_Default::Body_Default()
{
	this->name = "Default Body";
	this->armor = 18;
	this->durability = 5;
	this->cost = 200;
}

void Body_Default::use()
{
	//
}

void Body_Default::equip(Hare* hare)
{
	if (hare->GetCash() >= this->GetCost())
	{
		hare->SetCash(hare->GetCash() - this->GetCost());
		hare->SetDurability(this->durability);
		hare->SetArmor(this);
	}
}
