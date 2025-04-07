#ifndef H_MATH_EVALUATOR_PARSER_HEADER_PARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_PARSER_HEADER_PARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE

#include "Expression.hpp"
#include "Lexer.hpp"

class Parser {
public:
    Parser(Lexer& lex);
    Expression* getExpression() const;

private:
    Expression* m_expr;
};

#endif
