#ifndef H_MATH_EVALUATOR_MATHPARSER_HEADER_MATHPARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE
#define H_MATH_EVALUATOR_MATHPARSER_HEADER_MATHPARSER_GUARD_HEADER_DEFINE_HEADER_PLEASE

#include <string>

#include "Lexer.hpp"
#include "Parser.hpp"

namespace MathParser {
    int evaluate(const std::string& s) {
        auto lexer = Lexer(s);
        auto parser = Parser(lexer);
        auto expr = parser.getExpression();
        return expr->evaluate();
    }
}

#endif
