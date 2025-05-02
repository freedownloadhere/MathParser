// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "MathEnv.hpp"

#include "Allocator.hpp"
#include "Lexer.hpp"
#include "NativeFunctions.hpp"
#include "Parser.hpp"
#include "Expression.hpp"

std::int64_t MathEnv::evaluate(const std::string& toEvaluate) {
	m_allocator.reset();
	Lexer lexer = Lexer(toEvaluate, m_allocator);
	Parser parser = Parser(lexer, m_mempool, m_allocator);
	Expression* expr = parser.getExpression();
	Value* result = expr->evaluate(m_mempool, m_functable);
	return result->read();
}
