#include "fish.h"
#include <cmath>

enum NAMEFISH
{
    TUNA = 1,
    CARP = 2,
    TROUT = 4,
    STURGEON = 8,
    PIKE = 16,
};


Fish::Fish(const int& number) : Field(number)
{
    int num = rand() % 5;
    if(TUNA == pow(2,num)) type = "Tuna";
    else if(CARP == pow(2, num)) type = "Carp";
    else if(TROUT == pow(2, num)) type = "Trout";
    else if(STURGEON == pow(2, num)) type = "Sturgeon";
    else if(PIKE == pow(2, num)) type = "Pike";
}

int Fish::getNumber() const
{
    return number;
}

std::string Fish::getType() const
{
    return type;
}
