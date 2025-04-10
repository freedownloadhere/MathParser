#include "Exception.hpp"

Exception::Exception() : m_reason("Unspecififed") { }
Exception::Exception(std::string_view reason) : m_reason(reason) { }

const char* Exception::what() const throw() {
    return m_reason.data();
}
