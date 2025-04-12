// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "FuncTable.hpp"

#include "NativeFunctions.hpp"
#include "Token.hpp"

FuncTable::FuncTable() {
	m_unaryFuncTable = {
		{ Token::Type::Base.getID(), NativeFunc::ident },
		{ Token::Type::BracketLeft.getID(), NativeFunc::ident },
		{ Token::Type::BracketRight.getID(), NativeFunc::ident },
	};

	m_binaryFuncTable = {
		{ Token::Type::Add.getID(), NativeFunc::add },
		{ Token::Type::Subtract.getID(), NativeFunc::sub },
		{ Token::Type::Multiply.getID(), NativeFunc::mul },
		{ Token::Type::Divide.getID(), NativeFunc::div },
		{ Token::Type::Power.getID(), NativeFunc::pow },
		{ Token::Type::Equals.getID(), NativeFunc::assign },
	};
}

FuncTable::UnaryFunc FuncTable::getUnary(std::int32_t id) {
	if (m_unaryFuncTable.count(id) == 0)
		return nullptr;
	return m_unaryFuncTable.at(id);
}

FuncTable::BinaryFunc FuncTable::getBinary(std::int32_t id) {
	if (m_binaryFuncTable.count(id) == 0)
		return nullptr;
	return m_binaryFuncTable.at(id);
}
