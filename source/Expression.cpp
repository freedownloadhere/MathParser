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

	Value* op1 = m_left->evaluate(mempool, functable);

	auto unaryFunc = functable.getUnary(type->getID());
	if (unaryFunc != nullptr)
		return unaryFunc(mempool, op1);

	Value* op2 = m_right->evaluate(mempool, functable);

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
	return m_left;
}

Expression* Expression::getBinaryLeft() const {
	return m_left;
}

Expression* Expression::getBinaryRight() const {
	return m_right;
}

void Expression::setNext(Expression* e) {
	if(m_left == nullptr)
		setLeft(e);
	else if(m_right == nullptr)
		setRight(e);
	else
		throw Exception("SetNext was called on an already filled expression");
}

void Expression::setLeft(Expression* e) {
	m_left = e;
	m_left->m_parent = this;
}

void Expression::setRight(Expression* e) {
	m_right = e;
	m_right->m_parent = this;
}

void Expression::removeChild(Expression* e) {
	if(m_left == e) {
		m_left->m_parent = nullptr;
		m_left = nullptr;
	}
	else if(m_right == e) {
		m_right->m_parent = nullptr;
		m_right = nullptr;
	}
	else
	throw Exception("Trying to remove a non-existing child from an expression");
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

	if(m_left != nullptr) {
		m_left->print(tabcount);
	}

	if(m_right != nullptr) {
		m_right->print(tabcount);
	}

	tabcount--;

	m_print_tabs(tabcount);
	std::cout << "}\n";
}

Expression::~Expression() {
	delete m_left;
	delete m_right;
}
