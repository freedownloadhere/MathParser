#pragma once

#include "Expression.hpp"
#include "Lexer.hpp"
#include "VariableMap.hpp"

class Parser {
public:
    Parser(Lexer& lex, VariableMap& variableMap);
    Expression* getExpression() const;

private:
    Expression* m_expr;
};
