#pragma once

#include "Expression.hpp"
#include "Lexer.hpp"
#include "MemoryPool.hpp"

class Parser {
public:
    Parser(Lexer& lex, MemoryPool& variableMap);
    Expression* getExpression() const;

private:
    Expression* m_expr;
};
