//#pragma once
#ifndef _BODY_DEFAULT_H_
#define _BODY_DEFAULT_H_

#include "Bodies.h"
class Body_Default :
    public Bodies
{
private:
    //
public:
    Body_Default();
    void use() override;
    void equip(Hare* hare) override;
};

#endif // !_BODY_DEFAULT_H_