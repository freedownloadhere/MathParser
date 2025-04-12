// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "MemoryPool.hpp"
#include "Exception.hpp"

void MemoryPool::storeVariable(const std::string& name, std::int64_t value) {
	if (m_varmap.count(name) == 0)
		m_varmap.try_emplace(name, value);
}

void MemoryPool::storeConstant(std::int64_t value) {
	if (m_constpool.count(value) == 0)
		m_constpool.try_emplace(value, value);
}

std::int64_t MemoryPool::readVariable(const std::string& name) const {
	if (m_varmap.count(name) == 0)
		throw Exception("Variable does not exist; cannot read " + name);

	return m_varmap.at(name).read();
}

std::int64_t MemoryPool::readConstant(std::int64_t value) const {
	if (m_constpool.count(value) == 0)
		throw Exception("Constant was not found in the memory pool; cannot read " + value);

	return m_constpool.at(value).read();
}

void MemoryPool::writeVariable(const std::string& name, std::int64_t value) {
	if (m_varmap.count(name) == 0)
		throw Exception("Variable does not exist, cannot write");

	m_varmap.at(name).write(value);
}

LValue* MemoryPool::getVariablePtr(const std::string& name) {
	if (m_varmap.count(name) == 0)
		throw Exception("Variable " + name + " does not exist, cannot get reference");

	return &m_varmap.at(name);
}

RValue* MemoryPool::getConstantPtr(std::int64_t value) {
	if (m_constpool.count(value) == 0)
		throw Exception("Constant " + std::to_string(value) + " was not found in the memory pool, cannot get reference");

	return &m_constpool.at(value);
}
