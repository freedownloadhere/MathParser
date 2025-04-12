// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "Value.hpp"

Value::Value(std::int64_t value) 
	: m_value(value) { }

LValue::LValue(std::int64_t value) 
	: Value(value) { }

std::int64_t LValue::read() const {
	return m_value;
}

void LValue::write(std::int64_t value) {
	m_value = value;
}

RValue::RValue(std::int64_t value) 
	: Value(value) { }

std::int64_t RValue::read() const {
	return m_value;
}
