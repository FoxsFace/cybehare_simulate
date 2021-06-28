#pragma once
#ifndef _PAWS_DEFAULT_H_
#define _PAWS_DEFAULT_H_

#include "Paws.h"
class Paws_Default :
    public Paws
{
public:
    Paws_Default();
    void use() override;
    void equip(Hare* hare) override;
private:
    //
};

#endif // !_PAWS_DEFAULT_H_