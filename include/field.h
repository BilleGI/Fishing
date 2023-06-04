#pragma once

class Field
{
public:
    Field(const int& _number);
    virtual ~Field();
    virtual int getNumber()const = 0;
protected:
    int number;
};
