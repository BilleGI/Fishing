#pragma once
#include <exception>

class BootCaught : public std::exception
{
public:
    const char* what() const noexcept override;
};
