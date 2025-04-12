#pragma once
#include "Pch.hpp"

#include "Token.hpp"
#include "Value.hpp"
#include "MemoryPool.hpp"
#include "FuncTable.hpp"

class Expression {
public:
    Expression(const Token& token = Token(&Token::Type::Base));

    Value* evaluate(MemoryPool& mempool, FuncTable& functable) const;

    int getPrecedence() const;

    const Token::Type* getType() const;

    void setType(const Token::Type* type);

    Token getToken() const;

    Expression* getUnary() const;

    Expression* getBinaryLeft() const;

    Expression* getBinaryRight() const;

    void setNext(Expression* e);

    void removeChild(Expression* e);

    Expression* getParent();

    void print(int tabcount = 0) const;

    ~Expression();

private:
    Token m_token;
    std::vector<Expression*> m_params;
    Expression* m_parent = nullptr;
};
