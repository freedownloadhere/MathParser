#ifndef H_MATH_EVALUATOR_EXCEPTION_HEADER_MATHPARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_EXCEPTION_HEADER_MATHPARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE

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

#endif
