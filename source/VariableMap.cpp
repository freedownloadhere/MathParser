#include "VariableMap.hpp"
#include "Exception.hpp"

void VariableMap::addVariable(const std::string& name, std::int64_t value) {
	if(m_map.count(name) == 0)
		m_map.emplace(name, value);
}

std::int64_t VariableMap::readVariable(const std::string& name) const {
	if (m_map.count(name) == 0)
		throw Exception("Variable does not exist, cannot read");

	return m_map.at(name).read();
}

void VariableMap::writeVariable(const std::string& name, std::int64_t value) {
	if (m_map.count(name) == 0)
		throw Exception("Variable does not exist, cannot write");

	m_map.at(name).write(value);
}

LValue* VariableMap::getVariablePtr(const std::string& name) {
	if (m_map.count(name) == 0)
		throw Exception("Variable does not exist, cannot get reference");

	return &m_map.at(name);
}
