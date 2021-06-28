#pragma once
#ifndef _PAWS_H_
#define _PAWS_H_

#include "Item.h"
#include "Hare.h"

class Paws :
    public Item
{
protected:
    float flexibility;
    float durability;
public:
    float GetFlexibility() { return this->flexibility; }
    float GetDurability() { return this->durability; }
};

#endif // !_PAWS_H_