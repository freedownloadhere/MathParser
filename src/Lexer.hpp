#ifndef H_MATH_EVALUATOR_LEXER_HEADER_LEXER_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_LEXER_HEADER_LEXER_GUARD_HEADER_DEFINE_HEADER_PLEASE

#include <vector>

#include "Token.hpp"

class Lexer {
public:
    Lexer(const std::string& expr);

    void print() const;

    Token nextToken();

    bool reachedEnd();

private:
    int m_parseNumber(const std::string& expr, int& p);

    std::string m_parseLabel(const std::string& expr, int& p);

    bool m_isLabelChar(const char c) const;

    bool m_isAlpha(const char c) const;

    bool m_isNumber(const char c) const;

    bool m_isWhitespace(const char c) const;

    int m_toNumber(const char c) const;

    std::vector<Token> m_vec;
    std::vector<Token>::iterator it;
};

#endif
