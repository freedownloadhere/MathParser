// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "MathEnv.hpp"

#include "Lexer.hpp"
#include "NativeFunctions.hpp"
#include "Parser.hpp"
#include "Expression.hpp"

std::int64_t MathEnv::evaluate(const std::string& toEvaluate) {
	auto lexer = Lexer(toEvaluate);
	auto parser = Parser(lexer, m_mempool);
	auto expr = std::unique_ptr<Expression>(parser.getExpression());
	auto result = expr->evaluate(m_mempool, m_functable);
	return result->read();
}
