#pragma once
#include "Pch.hpp"

#include "Token.hpp"

class Lexer {
public:
    Lexer(const std::string& expr);

    void print() const;

    Token nextToken();

    bool reachedEnd();

private:
    std::int64_t m_parseNumber(const std::string& expr, size_t& p);

    std::string m_parseLabel(const std::string& expr, size_t& p);

    bool m_isLabelChar(const char c) const;

    bool m_isAlpha(const char c) const;

    bool m_isNumber(const char c) const;

    bool m_isWhitespace(const char c) const;

    int m_toNumber(const char c) const;

    std::vector<Token> m_vec;
    std::vector<Token>::iterator it;
};
