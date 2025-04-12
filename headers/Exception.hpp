#pragma once
#include "Pch.hpp"

class Exception : public std::exception {
public:
    Exception();
    Exception(std::string_view reason);

    virtual const char* what() const throw() override;

private:
    std::string_view m_reason;
};
