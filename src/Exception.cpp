#include "Exception.hpp"

Exception::Exception() : m_reason("Unspecififed") { }
Exception::Exception(const std::string& reason) : m_reason(reason) { }

const char* Exception::what() const throw() {
    return m_reason.c_str();
}
