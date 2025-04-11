#pragma once

#include <string>
#include <unordered_map>

class VariableMap {
public:
	void addVariable(const std::string& name, std::int64_t value = 0);

	std::int64_t readVariable(const std::string& name) const;

	void writeVariable(const std::string& name, std::int64_t value);

private:
	std::unordered_map<std::string, std::int64_t> m_map;
};