#pragma once
#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>

class Hare;

class Item
{
protected:
	std::string name;
	int cost;
public:
	std::string GetName();
	int GetCost() { return this->cost; }
	virtual void use() = 0;
	virtual void equip(Hare* hare) = 0;
};
#endif // !_ITEM_H_