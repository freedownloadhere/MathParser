#include "MathEnv.hpp"

#include <memory>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Expression.hpp"

std::int64_t MathEnv::evaluate(const std::string& toEvaluate) {
	auto lexer = Lexer(toEvaluate);
	auto parser = Parser(lexer);
	auto expr = std::unique_ptr<Expression>(parser.getExpression());
	auto result = expr->evaluate();
	return result;
}
