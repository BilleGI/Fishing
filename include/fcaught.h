#pragma once
#include <exception>

class FishCaught : public std::exception
{
public:
    const char* what() const noexcept override;
};
