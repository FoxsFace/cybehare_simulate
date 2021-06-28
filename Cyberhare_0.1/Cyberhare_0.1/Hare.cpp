#include "Hare.h"
#include <iostream>

using namespace std;

void Hare::SetWeapon(Weapon* hand)
{
	if (this->l_hand == nullptr)	this->l_hand = hand;
	else
	{
		if (this->r_hand == nullptr)	this->r_hand = hand;
		else
		{
			//chose worser weapon to swap
		}
	}
}

Hare::Hare(string name)
{
	this->name = name;
	this->reflexes = rand() % 11;
	this->accuraty = rand() % 11;
	this->durability = rand() % 11;
	this->max_durability = this->durability;
	this->flexibility = rand() % 11;
	this->money = 500;
	this->r_hand = this->l_hand = nullptr;
	this->head = NULL;
	this->status = 2;
}

Hare::Hare()
{
	this->reflexes = 0;
	this->accuraty = 0;
	this->durability = 0;
	this->flexibility = 0;
	this->money = 0;
	this->r_hand = l_hand = nullptr;
	this->head = nullptr;
	this->armor = nullptr;
	this->legs = nullptr;
	this->name = "";
	this->status = 0;
}

void Hare::info()
{
	
	cout << "\n" << this->name << ":"
		<< "\treflexes: " << this->reflexes << endl
		<< "\taccuraty: " << this->accuraty << endl
		<< "\tdurability: " << this->durability << endl
		<< "\tflexibility: " << this->flexibility << endl
		<< "\tcash: " << this->money
		<< endl;
	if (this->head!=0 || this->r_hand!=0 || this->l_hand != 0 || this->armor != 0 || this->legs != 0)
	{
		cout << "Equip:";
		if (this->head != nullptr) { cout << "\t" << this->head->GetName() << " (head)"; }
		if (this->armor != nullptr) { cout << "\t" << armor->GetName() << " (armor)"; }
		if (this->legs != nullptr) { cout << "\t" << legs->GetName() << " (legs)"; }
		if (this->r_hand != nullptr) { cout << "\t" << r_hand->GetName() << " (right hand)"; }
		if (this->l_hand != nullptr) { cout << "\t" << l_hand->GetName() << " (left hand)"; }
	}
	cout << endl;
}

void Hare::Figth(Hare* me, Hare* enemy)
{
	this_thread::sleep_for(chrono::seconds((int)(3/this->reflexes)));
	while (me->status != 0 && enemy->status != 0)
	{
		if (me->status==2)
		{
			cout << this->GetName() << " shooting!" << endl;
			enemy->status = me->Shot(enemy);
			if (enemy->status == 1 || enemy->status == 2)
			{
				if (this->l_hand != nullptr)
				{
					cout << this->GetName() << " reloading" << endl;
					this_thread::sleep_for(chrono::seconds((int)(this->l_hand->GetReload() / this->reflexes)));
				}
				else
				{
					cout << this->GetName() << " reloading" << endl;
					this_thread::sleep_for(chrono::seconds((int)(this->l_hand->GetReload() / this->reflexes)));
				}
			}
		}
		else
		{
			if (me->status == 1)
			{
				cout << this->GetName() << " hurt!" << endl;
				me->status = 2;
				this_thread::sleep_for(chrono::seconds((int)(3 / this->reflexes)));
			}
			else
			{
				cout << this->GetName() << " is dead!";
			}
		}
	}
}

int Hare::Shot(Hare* enemy)
{
	float probability = (((enemy->GetFlexibility() + enemy->GetReflexes())/2) / (this->random(11) + this->GetAccuraty())) * 100;
	float Shoot = this->random(101);
	float damage = 0;
	if (Shoot < probability)
	{
		cout << this->GetName() << " missed!" << endl;
		return 2; 
	}
	else
	{
		if (this->l_hand != nullptr)
			damage = this->l_hand->GetDamage() / (float)this->random(this->l_hand->GetDamage()/2);
		else
		{
			if (this->r_hand != nullptr)
				damage = this->r_hand->GetDamage() / (float)this->random(this->r_hand->GetDamage()/2);
			else
			{
				return 2;
			}
		}
		cout << this->GetName() << "'s hit: " << damage << " damage to ";
		int limb = random(101);
		if (limb > 0 && limb <= 15)
		{
			cout << "head!" << " (" <<  enemy->GetName() << ")" << endl;
			if (enemy->head == nullptr)
			{
				cout << enemy->GetName() << " is dead!" << endl;
				return 0;
			}
			else
			{
				if (damage>enemy->head->GetArmor())
				{
					cout << enemy->GetName() << " is dead!" << endl;

					return 0;
				}
				else
				{
					enemy->head->Damage(damage);
					return 1;
				}
			}
		}
		else
			if (limb > 15 && limb <= 35)
			{
				cout << "r_hand!" << " (" << enemy->GetName() << ")" << endl;
				if (damage > enemy->GetDurability())
				{
					cout << enemy->GetName() << " is dead!" << endl;
					return 0;
				}
				else
				{
					enemy->SetDurability(- damage);
					return 1;
				}
			}
			else
				if (limb > 35 && limb <= 75)
				{
					cout << "body!" << " (" << enemy->GetName() << ")" << endl;
					if (enemy->armor == nullptr)
					{
						if (damage > enemy->GetDurability())
						{
							cout << enemy->GetName() << " is dead!" << endl;
							return 0;
						}
						else
						{
							enemy->SetDurability(- damage);
							return 1;
						}
					}
					else
					{
						enemy->armor->Damage(damage);
						return 1;
					}
				}
				else
					if (limb > 75 && limb <= 95)
					{
						cout << "l_hand!" << " (" << enemy->GetName() << ")" << endl;
						if (damage > enemy->GetDurability())
						{
							cout << enemy->GetName() << " is dead!" << endl;
							return 0;
						}
						else
						{
							enemy->SetDurability( - damage);
							return 1;
						}
					}
					else
						if (limb > 95 && limb <= 100)
						{
							cout << "legs!" << " (" << enemy->GetName() << ")" << endl;
							if (damage > enemy->GetDurability())
							{
								cout << enemy->GetName() << " is dead!" << endl;
								return 0;
							}
							else
							{
								enemy->SetDurability(- damage);
								return 1;
							}
						}
	}
}
