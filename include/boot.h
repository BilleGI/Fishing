#pragma once
#include "field.h"

class Boot: public Field
{
public:
    Boot(const int& number);
    int getNumber() const override;
};

