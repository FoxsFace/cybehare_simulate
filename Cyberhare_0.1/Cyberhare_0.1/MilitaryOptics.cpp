#include "MilitaryOptics.h"
#include <iostream>

MilitaryOptics::MilitaryOptics()
{
	this->name = "Military optics";
	this->cost = 200;
	this->durability = 2;
	this->accuraty = 2;
	this->armor = 9;
}

void MilitaryOptics::use()
{
	//raket launch
}

void MilitaryOptics::equip(Hare* hare)
{
	if (hare->GetCash() >= this->GetCost())
	{
		hare->SetCash(hare->GetCash() - this->GetCost());
		hare->SetAccuraty(this->accuraty);
		hare->SetDurability(this->durability);
		hare->SetOptics(this);
	}
}