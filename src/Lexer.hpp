#ifndef H_MATH_EVALUATOR_LEXER_HEADER_LEXER_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_LEXER_HEADER_LEXER_GUARD_HEADER_DEFINE_HEADER_PLEASE

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

#include "Token.hpp"

class Lexer {
public:
    Lexer(const std::string& expr) {
        const int sz = expr.size();

        for(int p = 0; p < sz; ++p) {
            const char c = expr[p];

            if(m_isWhitespace(c))
                continue;

            auto type = Token::singleCharToToken[c];

            if(type != Token::Type::Base) {
                m_vec.push_back(Token(type));
                continue;
            }

            if('0' <= c && c <= '9') {
                int number = m_parseNumber(expr, p);
                m_vec.push_back(Token(number));
                --p;
                continue;
            }

            else {
                m_vec.push_back(Token(Token::Type::Invalid));
            }
        }

        it = m_vec.begin();
    }

    void print() const {
        std::cout << "{ ";

        for(const auto& token : m_vec) {
            auto type = token.getType();

            std::cout << Token::tokenToString[type];

            if(type == Token::Type::Number)
                std::cout << " (" << token.getValue() << ")";

            std::cout << "; ";
        }

        std::cout << "}\n";
    }

    Token nextToken() {
        assert(it != m_vec.end());

        auto token = *it;
        ++it;
        return token;
    }

    bool reachedEnd() {
        return it == m_vec.end();
    }

private:
    int m_parseNumber(const std::string& expr, int& p) {
        const int sz = expr.size();
        int number = 0;

        while(p < sz && m_isNumber(expr[p])) {
            int digit = m_toNumber(expr[p]);
            number = number * 10 + digit;
            ++p;
        }

        return number;
    }

    bool m_isNumber(const char c) const {
        return '0' <= c && c <= '9';
    }

    bool m_isWhitespace(const char c) const {
        return c == ' ' || c == '\n';
    }

    int m_toNumber(const char c) const {
        return c - '0';
    }

    std::vector<Token> m_vec;
    std::vector<Token>::iterator it;
};

#endif
