#pragma once
#include "Pch.hpp"

#include "Allocator.hpp"
#include "Expression.hpp"
#include "Lexer.hpp"
#include "MemoryPool.hpp"

class Parser {
public:
    Parser(Lexer& lex, MemoryPool& variableMap, Allocator& allocator);
    Expression* getExpression() const;

private:
    Expression* m_expr;
};
