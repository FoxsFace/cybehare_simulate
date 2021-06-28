#include "Item.h"

std::string Item::GetName()
{
    if (this == nullptr)
    {
        return "default";
    }
    else
        return this->name;
}
