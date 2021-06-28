#pragma once
#ifndef _HARE_H_
#define _HARE_H_

#include <stdlib.h>
#include <string>
#include "Item.h"
#include "Optics.h"
#include "Weapon.h"
#include "Bodies.h"
#include "Paws.h"
#include <chrono>
#include <thread>

class Optics;
class Weapon;
class Bodies;
class Paws;

class Hare
{
private:
	std::string name;
	float reflexes;
	float accuraty;
	float flexibility;
	float durability;
	int money = 0;
	Optics* head;
	Weapon* r_hand;
	Weapon* l_hand;
	Bodies* armor;
	Paws* legs;
	int Shot(Hare* enemy);
	int random(int max) { return 1 + rand() % max; }
	int status;
	float max_durability;

public:
	std::string GetName() { return name; }
	float GetReflexes() { return reflexes; }
	float GetAccuraty() { return accuraty; }
	float GetDurability() { return durability; }
	float GetFlexibility() { return flexibility; }
	int GetCash() { return this->money; }
	void SetReflexes(float reflexes) { this->reflexes += reflexes; }
	void SetAccuraty(float accuraty) { this->accuraty += accuraty; }
	void SetDurability(float durability) { this->durability += durability; }
	void SetFlexibility(float flexibility) { this->flexibility += flexibility; }
	void SetOptics(Optics* head) { this->head = head; }
	void SetWeapon(Weapon* hand);
	void SetArmor(Bodies* armor) { this->armor = armor; }
	void SetLegs(Paws* legs) { this->legs = legs; }
	void SetCash(int cash) { this->money = cash; }
	void equip(Item* equippment) { equippment->equip(this); }
	int GetStatus() { return this->status; }
	Hare(std::string name);
	Hare();
	void info();
	void Figth(Hare* me, Hare* enemy);
	void recover(){	this->durability = this->max_durability;}

};
#endif // !_HARE_H_