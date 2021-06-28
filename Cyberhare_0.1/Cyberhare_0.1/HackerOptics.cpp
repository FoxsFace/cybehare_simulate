#include "HackerOptics.h"

HackerOptics::HackerOptics()
{
	this->name = "Hacker optics";
	this->cost = 200;
	this->accuraty = 3;
	this->armor = 4;
	this->flexibility = 2;
}

void HackerOptics::use()
{
	//shut down enemies vision
}

void HackerOptics::equip(Hare* hare)
{
	if (hare->GetCash() >= this->GetCost())
	{
		hare->SetCash(hare->GetCash() - this->GetCost());
		hare->SetAccuraty(this->accuraty);
		hare->SetFlexibility(this->flexibility);
		hare->SetOptics(this);
	}
}