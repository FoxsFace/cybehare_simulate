#include "Shotgun.h"

Shotgun:: Shotgun()
{
	this->name = "Shotgun";
	this->cost = 300;
	this->ammo = 8;
	this->damage = 27;
	this->reload = 5;
}

void Shotgun::equip(Hare* hare)
{
	if (hare->GetCash() >= this->GetCost())
	{
		hare->SetCash(hare->GetCash() - this->GetCost());
		hare->SetWeapon(this);
	}
}

void Shotgun::use()
{
	
}