#pragma once

#include <exception>
#include <string>

class Exception : public std::exception {
public:
    Exception();
    Exception(const std::string& reason);

    virtual const char* what() const throw() override;

private:
    std::string m_reason;
};
