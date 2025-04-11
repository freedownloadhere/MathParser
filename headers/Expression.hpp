#pragma once

#include "Token.hpp"
#include "Value.hpp"
#include "VariableMap.hpp"

class Expression {
public:
    Expression();
    Expression(const Token token);

    Value* evaluate(VariableMap& variableMap) const;

    int getPrecedence() const;

    Token::Type getType() const;

    void setType(Token::Type type);

    Token getToken() const;

    Expression* getUnary() const;

    Expression* getBinaryLeft() const;

    Expression* getBinaryRight() const;

    void setNext(Expression* e);

    void setLeft(Expression* e);

    void setRight(Expression* e);

    void removeChild(Expression* e);

    Expression* getParent();

    void print(int tabcount = 0) const;

    ~Expression();

private:
    Token m_token;
    Expression* m_parent = nullptr;
    Expression* m_left = nullptr;
    Expression* m_right = nullptr;
};
