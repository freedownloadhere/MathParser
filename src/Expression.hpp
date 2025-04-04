#ifndef H_MATH_EVALUATOR_EXPRESSION_HEADER_EXPRESSION_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_EXPRESSION_HEADER_EXPRESSION_GUARD_HEADER_DEFINE_HEADER_PLEASE

#include <cassert>
#include <cmath>
#include <iostream>

#include "LogicException.hpp"
#include "Token.hpp"

class Expression {
public:
    Expression() : m_token(Token(Token::Type::Base)) { }
    Expression(const Token token) : m_token(token) { }

    int evaluate() const {
        auto type = m_token.getType();

        switch(type) {
            case Token::Type::Base:
            case Token::Type::BracketLeft:
            case Token::Type::BracketRight:
                return m_left->evaluate();
            case Token::Type::Number:
                return m_token.getNumber();
            default: ;
        }

        int left = m_left->evaluate();
        int right = m_right->evaluate();

        switch(type) {
            case Token::Type::Add:
                return left + right;
            case Token::Type::Subtract:
                return left - right;
            case Token::Type::Multiply:
                return left * right;
            case Token::Type::Divide:
                return left / right;
            case Token::Type::Power:
                return std::pow(left, right);
            default:
                throw LogicException("Token could not be evaluated");
        }
    }

    int getPrecedence() const {
        return Token::precedence[m_token.getType()];
    }

    Token::Type getType() const {
        return m_token.getType();
    }

    void setType(Token::Type type) {
        m_token.setType(type);
    }

    Token getToken() const {
        return m_token;
    }

    Expression* getUnary() const {
        return m_left;
    }

    Expression* getBinaryLeft() const {
        return m_left;
    }

    Expression* getBinaryRight() const {
        return m_right;
    }

    void setNext(Expression* e) {
        if(m_left == nullptr)
            setLeft(e);
        else if(m_right == nullptr)
            setRight(e);
        else
            throw LogicException("SetNext was called on an already filled expression");
    }

    void setLeft(Expression* e) {
        m_left = e;
        m_left->m_parent = this;
    }

    void setRight(Expression* e) {
        m_right = e;
        m_right->m_parent = this;
    }

    void removeChild(Expression* e) {
        if(m_left == e) {
            m_left->m_parent = nullptr;
            m_left = nullptr;
        }
        else if(m_right == e) {
            m_right->m_parent = nullptr;
            m_right = nullptr;
        }
        else
            throw LogicException("Trying to remove a non-existing child from an expression");
    }

    Expression* getParent() {
        return m_parent;
    }

    void print(int tabcount = 0) const {
        static auto m_print_tabs = [](int tc) {
            for(int i = 1; i <= tc; i++)
                std::cout << "  ";
        };

        auto type = m_token.getType();

        m_print_tabs(tabcount);
        std::cout << Token::tokenToString[type] << " {\n";

        tabcount++;

        if(type == Token::Type::Number) {
            m_print_tabs(tabcount);
            std::cout << "Value: " << m_token.getNumber() << '\n';
        }

        if(m_left != nullptr) {
            m_left->print(tabcount);
        }

        if(m_right != nullptr) {
            m_right->print(tabcount);
        }

        tabcount--;

        m_print_tabs(tabcount);
        std::cout << "}\n";
    }

    ~Expression() {
        if(m_left)
            delete m_left;
        if(m_right)
            delete m_right;
    }

private:
    Expression* m_parent = nullptr;
    Token m_token;
    Expression* m_left = nullptr;
    Expression* m_right = nullptr;
};

#endif
