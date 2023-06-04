#include "boot.h"

Boot::Boot(const int& number) : Field(number){};

int Boot::getNumber() const
{
    return number;
}
