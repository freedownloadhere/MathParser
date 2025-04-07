#include "MathEnv.hpp"

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Expression.hpp"

int MathEnv::evaluate(const std::string& toEvaluate) {
	auto lexer = Lexer(toEvaluate);
	auto parser = Parser(lexer);
	auto expr = parser.getExpression();
	auto result = expr->evaluate();
	delete expr;
	return result;
}