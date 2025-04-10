#include "Expression.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

#include "Exception.hpp"

Expression::Expression() : m_token(Token(Token::Type::Base)) { }
Expression::Expression(const Token token) : m_token(token) { }

std::int64_t Expression::evaluate() const {
	Token::Type type = m_token.getType();

	switch(type) {
		case Token::Type::Base:
		case Token::Type::BracketLeft:
		case Token::Type::BracketRight:
			return m_left->evaluate();
		case Token::Type::Number:
			return m_token.getNumber();
		default: ;
	}

	std::int64_t left = m_left->evaluate();
	std::int64_t right = m_right->evaluate();

	switch(type) {
		case Token::Type::Add:
			return left + right;
		case Token::Type::Subtract:
			return left - right;
		case Token::Type::Multiply:
			return left * right;
		case Token::Type::Divide:
			if (right == 0) 
				throw Exception("Division by zero");
			return left / right;
		case Token::Type::Power:
			return static_cast<std::int64_t>(std::pow(left, right));
		default:
			throw Exception("Token could not be evaluated");
	}
}

int Expression::getPrecedence() const {
	return Token::precedence[m_token.getType()];
}

Token::Type Expression::getType() const {
	return m_token.getType();
}

void Expression::setType(Token::Type type) {
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

	Token::Type type = m_token.getType();

	m_print_tabs(tabcount);
	std::cout << Token::tokenToString[type] << " {\n";

	tabcount++;

	if(type == Token::Type::Number) {
		m_print_tabs(tabcount);
		std::cout << "Value: " << m_token.getNumber() << '\n';
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
	if(m_left)
		delete m_left;
	if(m_right)
		delete m_right;
}
