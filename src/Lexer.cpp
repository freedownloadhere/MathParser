#include "Lexer.hpp"

#include <iostream>
#include <string>

#include "Exception.hpp"

Lexer::Lexer(const std::string& expr) {
    const size_t sz = expr.size();

    for(size_t p = 0; p < sz; ++p) {
        const char c = expr[p];

        if(m_isWhitespace(c))
            continue;

        auto type = Token::singleCharToToken[c];

        if(type != Token::Type::Base) {
            m_vec.push_back(Token(type));
            continue;
        }

        if(m_isNumber(c)) {
            int number = m_parseNumber(expr, p);
            m_vec.push_back(Token(number));
            --p;
            continue;
        }

        if(m_isLabelChar(c)) {
            std::string label = m_parseLabel(expr, p);
            m_vec.push_back(Token(label));
            --p;
            continue;
        }

        throw Exception("Invalid character in sequence");
    }

    it = m_vec.begin();
}

void Lexer::print() const {
    std::cout << "{ ";

    for(const auto& token : m_vec) {
        auto type = token.getType();

        std::cout << Token::tokenToString[type];

        if(type == Token::Type::Number)
            std::cout << " " << token.getNumber();

        if(type == Token::Type::Label)
            std::cout << " \"" << token.getLabel() << "\"";

        std::cout << "; ";
    }

    std::cout << "}\n";
}


Token Lexer::nextToken() {
    if(it == m_vec.end())
        throw Exception("Reached end of tokens");

    auto& token = *it;
    ++it;
    return token;
}

bool Lexer::reachedEnd() {
    return it == m_vec.end();
}

int Lexer::m_parseNumber(const std::string& expr, size_t& p) {
    const size_t sz = expr.size();
    int number = 0;

    while(p < sz && m_isNumber(expr[p])) {
        int digit = m_toNumber(expr[p]);
        number = number * 10 + digit;
        ++p;
    }

    return number;
}

std::string Lexer::m_parseLabel(const std::string& expr, size_t& p) {
    const size_t sz = expr.size();

    const size_t start = p;

    while(p < sz && m_isLabelChar(expr[p])) {
        ++p;
    }

    const size_t end = p;

    std::string label = expr.substr(start, end - start);

    return label;
}

bool Lexer::m_isLabelChar(const char c) const {
    return c == '_' || m_isNumber(c) || m_isAlpha(c);
}

bool Lexer::m_isAlpha(const char c) const {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool Lexer::m_isNumber(const char c) const {
    return '0' <= c && c <= '9';
}

bool Lexer::m_isWhitespace(const char c) const {
    return c <= 32;
}

int Lexer::m_toNumber(const char c) const {
    return c - '0';
}
