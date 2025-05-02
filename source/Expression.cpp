// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Expression.hpp"

#include "Exception.hpp"
#include "NativeFunctions.hpp"
#include "MemoryPool.hpp"

Expression::Expression(const Token& token) 
	: m_token(token) { }

Value* Expression::evaluate(MemoryPool& mempool, FuncTable& functable) const {
	const Token::Type* type = m_token.getType();

	if(type == &Token::Type::Number)
		return m_token.getRValue();

	if(type == &Token::Type::Label)
		return mempool.getVariablePtr(*m_token.getLabel());

	assert(m_params.size() >= 1);
	Value* op1 = m_params.at(0)->evaluate(mempool, functable);

	auto unaryFunc = functable.getUnary(type->getID());
	if (unaryFunc != nullptr)
		return unaryFunc(mempool, op1);

	assert(m_params.size() >= 2);
	Value* op2 = m_params.at(1)->evaluate(mempool, functable);

	auto binaryFunc = functable.getBinary(type->getID());
	if (binaryFunc != nullptr)
		return binaryFunc(mempool, op1, op2);

	throw Exception("Expression could not be evaluated; not mapped to any function");
}

int Expression::getPrecedence() const {
	return m_token.getType()->getPrecedence();
}

const Token::Type* Expression::getType() const {
	return m_token.getType();
}

void Expression::setType(const Token::Type* type) {
	m_token.setType(type);
}

Token Expression::getToken() const {
	return m_token;
}

Expression* Expression::getUnary() const {
	assert(m_params.size() == 1);
	return m_params.at(0);
}

Expression* Expression::getBinaryLeft() const {
	assert(m_params.size() == 2);
	return m_params.at(0);
}

Expression* Expression::getBinaryRight() const {
	assert(m_params.size() == 2);
	return m_params.at(1);
}

void Expression::setNext(Expression* e) {
	m_params.push_back(e);
	e->m_parent = this;
}

void Expression::removeChild(Expression* e) {
	auto it = m_params.begin();
	while (it != m_params.end() && *it != e)
		++it;
	if (it != m_params.end())
		m_params.erase(it);
	else
		throw Exception("Tried to erase a child that does not exist");
}

Expression* Expression::getParent() {
	return m_parent;
}

void Expression::print(int tabcount) const {
	static auto m_print_tabs = [](int tc) {
		for(int i = 1; i <= tc; i++)
			std::cout << "  ";
	};

	const Token::Type* type = m_token.getType();

	m_print_tabs(tabcount);
	std::cout << type->getName() << " {\n";

	tabcount++;

	if(type == &Token::Type::Number) {
		m_print_tabs(tabcount);
		std::cout << "Value: " << m_token.getRValue() << '\n';
	}

	for (const auto param : m_params)
		param->print(tabcount);

	tabcount--;

	m_print_tabs(tabcount);
	std::cout << "}\n";
}
