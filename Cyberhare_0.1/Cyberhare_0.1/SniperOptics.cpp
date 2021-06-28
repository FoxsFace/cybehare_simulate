#include "SniperOptics.h"

SniperOptics::SniperOptics()
{
	this->name = "Sniper optics";
	this->cost = 200;
	this->accuraty = 4;
	this->armor = 0;
	this->reflexes = 2;
}

void SniperOptics::use()
{
	//aimed shot
	//this.*_hand.use()
}

void SniperOptics::equip(Hare* hare)
{
	if (hare->GetCash() >= this->GetCost())
	{
		hare->SetCash(hare->GetCash() - this->GetCost());
		hare->SetAccuraty(this->accuraty);
		hare->SetReflexes(this->reflexes);
		hare->SetOptics(this);
	}
}