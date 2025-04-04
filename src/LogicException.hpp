#ifndef H_MATH_EVALUATOR_LOGICEXCEPTION_HEADER_MATHPARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_LOGICEXCEPTION_HEADER_MATHPARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE

#include <exception>
#include <string>

class LogicException : std::exception {
public:
    LogicException() : m_reason("Unspecififed") { }
    LogicException(const std::string& reason) : m_reason(reason) { }

    virtual const char* what() const throw() {
        return m_reason.c_str();
    }

private:
    std::string m_reason;
};

#endif
