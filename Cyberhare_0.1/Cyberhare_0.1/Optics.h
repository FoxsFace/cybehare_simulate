#pragma once
#ifndef _OPTICS_H_
#define _OPTICS_H_

#include "Item.h"
#include "Hare.h"

class Optics : public Item
{
protected:
    int armor;
    float accuraty;
public:
    void Damage(float damage) { this->armor -= damage; }
    int GetArmor() { return this->armor; }
    float GetAccuraty() { return this->accuraty; }
};
#endif // !_OPTICS_H_