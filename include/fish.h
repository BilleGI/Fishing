#pragma once
#include "field.h"
#include <string>

class Fish: public Field
{
public:
    Fish(const int& number);
    int getNumber()const override;
    std::string getType() const;
private:
    std::string type;
};
