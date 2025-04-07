#pragma once

#include "Expression.hpp"
#include "Lexer.hpp"

class Parser {
public:
    Parser(Lexer& lex);
    Expression* getExpression() const;

private:
    Expression* m_expr;
};
