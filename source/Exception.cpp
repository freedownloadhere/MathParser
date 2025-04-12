// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Exception.hpp"

Exception::Exception() : m_reason("Unspecififed") { }
Exception::Exception(std::string_view reason) : m_reason(reason) { }

const char* Exception::what() const throw() {
    return m_reason.data();
}
