#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

#include "Value.hpp"

class VariableMap {
public:
	void addVariable(const std::string& name, std::int64_t value = 0);

	std::int64_t readVariable(const std::string& name) const;

	void writeVariable(const std::string& name, std::int64_t value);

	LValue* getVariablePtr(const std::string& name);

private:
	std::unordered_map<std::string, LValue> m_map;
};